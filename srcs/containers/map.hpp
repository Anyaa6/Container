/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonnel <abonnel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 14:57:21 by abonnel           #+#    #+#             */
/*   Updated: 2022/05/06 16:40:20 by abonnel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
#define MAP_HPP

#include <memory>
#include <functional>
#include <limits>
#include "../utils/pair.hpp"
#include "../utils/node.hpp"
#include "../iterators/bidirectional_iterator.hpp"
#define RESET 		  "\033[0m"
#define BLACK_COLOR   "\033[30m"      /* Black */
#define RED_COLOR     "\033[31m"      /* Red */

namespace ft 
{
	template < class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator< pair<const Key,T> > >
	class map 
	{
	
		
	public:
		typedef Key 										key_type;
		typedef T 											mapped_type;
		typedef pair<const key_type, mapped_type> 			value_type;
		typedef Compare 									key_compare;
		typedef Alloc 										allocator_type;
		typedef typename allocator_type::reference 			reference;
		typedef typename allocator_type::const_reference	const_reference;
		typedef typename allocator_type::pointer			pointer;
		typedef typename allocator_type::const_pointer		const_pointer;
		typedef size_t										size_type;
		
	private :
		typedef	node<value_type>								_node;
		typedef typename Alloc::template rebind<_node>::other 	_node_alloc_type;
	
	public:
		typedef typename ft::bidirectional_iterator<_node>					iterator;
		typedef typename ft::bidirectional_iterator<const _node>			const_iterator;
		typedef typename ft::reverse_iterator<iterator>						reverse_iterator;
		typedef typename ft::reverse_iterator<const_iterator>				const_reverse_iterator;
		typedef typename ft::iterator_traits<iterator>::difference_type		difference_type;
		
		//key_compare compares keys directly, value_compare also compares keys but from the pairs level
		class value_compare : public std::binary_function<value_type,value_type,bool>
		{
			friend class map;
			protected:
				Compare comp;
				value_compare (Compare c) : comp(c) {}  // constructed with map's comparison object
				
			public:
				typedef bool result_type;
				typedef value_type first_argument_type;
				typedef value_type second_argument_type;
				bool operator() (const value_type& x, const value_type& y) const {
					return comp(x.first, y.first);
				}
		};

		//-------------------------------------------------------------------------------------
		//CONSTRUCTOR && DESTRUCTORS

		map(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) : _size(0), _alloc(alloc), _comp(comp), _val_comp(value_comp()) 
		{
			_construct_link_end_node();
		};
			
		template <class InputIterator>
		map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) : _size(0), _alloc(alloc), _comp(comp), _val_comp(value_comp()) 
		{
			_construct_link_end_node();
			this->insert(first, last);
		};
		
		map (const map& x) : _size(0), _alloc(x._alloc), _comp(x._comp), _val_comp(x._val_comp) {
			_construct_link_end_node();
			_map_by_copy(x._root, x._end, this->_root, this->_root);
		};
		
		map& operator= (const map& x) {
			_size = 0;
			_alloc = x._alloc;
			_comp = x._comp;
			_val_comp = x._val_comp;
			_construct_link_end_node();
			_map_by_copy(x._root, x._end, this->_root, this->_root);
			return (*this);
		};
		
		~map(){
			clear();
			_node_alloc.destroy(_end);
			_node_alloc.deallocate(_end, 1);
		};

		void clear() {
			_clear_tree(_root);
			_root = _begin = _end;
		};

		//-------------------------------------------------------------------------------------
		//GETTERS && INFOS && RANDOM

		value_compare value_comp() const {
			return (_val_comp);
		};

		key_compare key_comp() const {
			return (_comp);
		};

		allocator_type get_allocator() const {
			return (_alloc);
		};
		size_type size() const {
			return (_size);
		};

		bool empty() const {
			return (_size == 0);
		};

		// size_type max_size() const {
			// return (_node_alloc.max_size());
		// };

		void swap (map& x) {
			map		tmp(x);
			map		*tmp_ptr = &tmp;

			x = *this;
			*this = *tmp_ptr;
		}
		
		//-------------------------------------------------------------------------------------
		//ITERATORS
		iterator begin() {
			return (iterator(_begin));
		};
		const_iterator begin() const {
			return (const_iterator(_begin));
		};
		iterator end() {
			return (iterator(_end));
		};
		const_iterator end() const {
			return (const_iterator(_end));
		};
		reverse_iterator rbegin() {
			return (reverse_iterator(_end));
		};
		const_reverse_iterator rbegin() const {
			return (const_reverse_iterator(_end));
		};
		reverse_iterator rend() {
			return (reverse_iterator(_begin));
		};
		const_reverse_iterator rend() const {
			return (const_reverse_iterator(_begin));
		};
		
		//-------------------------------------------------------------------------------------
		//FIND
		mapped_type& operator[] (const key_type& k) {
			return ((*((this->insert(make_pair(k,mapped_type()))).first)).second);
		};
		
		//-------------------------------------------------------------------------------------
		//INSERT
		pair<iterator,bool> insert (const value_type& val) {
			return (_insert_from_root(val, _root, _root));
		};
		
		iterator insert (iterator position, const value_type& val) {
			//friend not authorised 
			//eventhough real map uses it to access node pointer inside of iterator 
			(void)position;
			return (this->insert(val).first);
		};
		
		template <class InputIterator>
		void insert (InputIterator first, InputIterator last) {
			for (; first != last; first++)
				this->insert(*first);
		};

		//-------------------------------------------------------------------------------------
		//ERASE
		
		_node *_convert_iterator_to_node(_node *current, const iterator &position) {
			if (current == _end || current == NULL)
				return (_end);
			if (_val_comp(*current->val_ptr, *position))
				return (_convert_iterator_to_node(current->right, position));
			if (_val_comp(*position, *current->val_ptr))
				return (_convert_iterator_to_node(current->left, position));
			return (current);
		};
		
		/*
		//links are not well made in the new route and deleted node gets deleted twice
		void _erase_node_1_or_no_childs(_node *to_delete) {
			_node *tmp = to_delete;
			bool is_end = 0;

			if ((to_delete)->left) {
				to_delete = (to_delete)->left;
			}
			else {
				std::cout << "(to_delete)->right == _end ? " << ((to_delete)->right == _end) << std::endl;
				is_end = ((to_delete)->right == _end);
				to_delete = (to_delete)->right;
				std::cout << "to_delete = " << to_delete->val_ptr->first << std::endl;
				// tmp = (to_delete)->right;
			}
			_delete_node(tmp);
			// to_delete = tmp;
			if (is_end)
				_end = to_delete;
			// std::cout << "printing tree in function " << std::endl;
			// this->print_tree();
		};
		*/

		void erase (iterator position) {
			if (_root == _end)
				return;
			//function to convert position to node
			_node *to_delete = _convert_iterator_to_node(_root, position);
			if (to_delete == _end)
				return;
			//if node has 2 childs, choose biggest of left side or smallest of right side instead of him
				//get back memory for him and set pointers previously pointing to switch element to null
			if (to_delete->right && to_delete->left) {
				std::cout << "node has 2 childs" << std::endl;
				// return;
			}
			//if node has no child, set parent's pointer to null and get back memory
			//if node had 1 child, bridge between its parent and its child and get back memory
			else {
				
				std::cout << "erase node with 1 or no child" << std::endl;
				// _erase_node_1_or_no_childs(to_delete);
			}
			//balance tree from position?
		};
	
		/*
		//in std even if you use the iterator of another map, as long as it finds a corresponding key, then
		//it will delete this node which will mess up the entire map structure
		//but it is because it has access directly to the underlying pointer that the iterator holds
		//map.erase(iterator_of_other_map)
		//so here even if you call erase on "map" then it will actually destroy the node from "other_map"
		//bc that is the map that the iterator belongs to
		//since we do not have access to underlying pointer, behaviour will be different */
		
		// size_type erase (const key_type& k);
		// void erase (iterator first, iterator last);
		
		//-------------------------------------------------------------------------------------
		//OPERATIONS

		iterator find (const key_type& k) {
			return (_find_from_root(_root, k));
		};
		
		const_iterator find (const key_type& k) const {
			return (_find_from_root(_root, k));
		};

		size_type count (const key_type& k) const {
			if (_find_from_root(_root, k) == _end)
				return (0);
			return (1);
		};
		
		iterator lower_bound (const key_type& k) {
			iterator it = begin();
			
			while (_comp(it->first, k) && it != _end)
				it++;
			return (it);
		};
		
		const_iterator lower_bound (const key_type& k) const {
			iterator it = begin();
			
			while (_comp(it->first, k) && it != _end)
				it++;
			return (it);
		};

		iterator upper_bound (const key_type& k) {
			iterator it = begin();
			
			while (_comp(it->first, k) && it != _end)
				it++;
			//if it key is == to k then we need to go to next one
			while (_comp(it->first, k) == false && _comp(k, it->first) == false)
				return (++it);
			return (it);
		};
		
		const_iterator upper_bound (const key_type& k) const {
			iterator it = begin();
			
			while (_comp(it->first, k) && it != _end)
				it++;
			//if it key is == to k then we need to go to next one
			while (_comp(it->first, k) == false && _comp(k, it->first) == false)
				return (++it);
			return (it);
		};

		pair<iterator,iterator> equal_range (const key_type& k) {
			return (ft::make_pair(lower_bound(k), upper_bound(k)));
		};
		pair<const_iterator,const_iterator> equal_range (const key_type& k) const {
			return (ft::make_pair(lower_bound(k), upper_bound(k)));
		};

		//TO DELEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEETE
		void print_tree() {
			_print_tree(_root, NULL, false, _end);}
			
	private:
		_node 			*_root;
		_node			*_end;
		_node			*_begin; //smallest key
		size_type 		_size;
		allocator_type		_alloc;
		_node_alloc_type	_node_alloc;
		key_compare		_comp;
		value_compare	_val_comp;

		
		void	_construct_link_end_node() {
			_construct_node(_end, _node(END_NODE));
			_end->parent = _root;
			_root = _begin = _end;
		};
		
		//-------------------------------------------------------------------------------------
		//INSERT
		
		void _construct_node(_node *&position, const _node &new_node) {
			
			position = _node_alloc.allocate(1);
			_node_alloc.construct(position, new_node);
			if (position != _end)
				_size++;
		};

		void	_insert_do_end_root_begin(_node *&current, const _node &new_node) {
			bool is_end = (current == _end);
			bool is_root = (current == _root);
			bool is_begin = (is_root || _val_comp(*new_node.val_ptr, *_begin->val_ptr));
			
			_construct_node(current, new_node);
			if (is_end)
			{
				current->right = _end;
				_end->parent = current;
			}
			if (is_root)
				_root = current;
			if (is_begin)
				_begin = current;
		};

		pair<iterator,bool>	_insert_from_root(const value_type& val, _node *&current, _node *&parent) {
			if (current == _end || current == NULL) {
				_insert_do_end_root_begin(current, _node(val, parent));
				//balance - beware to not change current for return value
				return (make_pair(iterator(current), true));
			}
			if (_val_comp(val, *current->val_ptr))
				return (_insert_from_root(val, current->left, current));
			else if (_val_comp(*current->val_ptr, val))
				return (_insert_from_root(val, current->right, current));
			return (make_pair(iterator(current), false)); //keys are same
		};

		//-------------------------------------------------------------------------------------
		//CLEAR DELETE COPY
		void	_clear_tree(_node *current) {
			if (current == NULL || current == _end)
				return;
			_clear_tree(current->left);
			_clear_tree(current->right);
			_delete_node(current);
		}
		
		void _delete_node(_node *&node_to_destroy) {
			std::cout << "deleting " << node_to_destroy->val_ptr->first << std::endl;
			_alloc.destroy((node_to_destroy)->val_ptr);
			_alloc.deallocate((node_to_destroy)->val_ptr, 1);
			_node_alloc.destroy(node_to_destroy);
			_node_alloc.deallocate(node_to_destroy, 1);
			_size--;
		};

		void	_map_by_copy(_node *x_current, _node *x_end, _node *&this_current, _node *&this_parent) {
			if (x_current == NULL || x_current == x_end)
				return;
			_insert_do_end_root_begin(this_current, _node(*x_current->val_ptr, this_parent));
			_map_by_copy(x_current->left, x_end, this_current->left, this_current);
			_map_by_copy(x_current->right, x_end, this_current->right, this_current);
		};

		//-------------------------------------------------------------------------------------
		//OPERATIONS
		
		iterator	_lower_bound_from_root(_node *current, const key_type& key) const {
			if (current == NULL || current == _end)
				return (iterator(_end));
			if (_comp(key, current->val_ptr->first) && current->left && _comp(key, current->left->val_ptr->first))
				return (_lower_bound_from_root(current->left, key));
			else if (_comp(current->val_ptr->first, key))
				return (_lower_bound_from_root(current->right, key));
			return (iterator(current));
		};

		iterator	_find_from_root(_node *current, const key_type& key) const {
			if (current == NULL || current == _end)
				return (iterator(_end));
			if (_comp(key, current->val_ptr->first))
				return (_find_from_root(current->left, key));
			else if (_comp(current->val_ptr->first, key))
				return (_find_from_root(current->right, key));
			return (iterator(current));
		};
		
		//-------------------------------------------------------------------------------------
		//print tree
		struct Trunk
		{
			Trunk 		*prev;
			std::string str;
		
			Trunk(Trunk *prev, std::string str)
			{
				this->prev = prev;
				this->str = str;
			}
		};
		
		// Helper function to print branches of the binary tree
		void _show_trunks(Trunk *p)
		{
			if (p == NULL) {
				return;
			}
			_show_trunks(p->prev);
			std::cout << p->str;
		}
		
		void _print_tree(_node *root, Trunk *prev, bool is_left, _node *end)
		{
			// std::cout << "Printing tree" << std::endl;
			if (root == NULL || root == end) {
				return;
			}
		
			std::string prev_str = "    ";
			Trunk *trunk = new Trunk(prev, prev_str);
		
			_print_tree(root->right, trunk, true, end);
		
			if (!prev) {
				trunk->str = "———";
			}
			else if (is_left)
			{
				trunk->str = ".———";
				prev_str = "   |";
			}
			else {
				trunk->str = "`———";
				prev->str = prev_str;
			}
		
			_show_trunks(trunk);
			if (root->color == 0)
				std::cout << " " << RED_COLOR << root->get_key() << RESET << std::endl;
			else
				std::cout << " " << root->get_key() << std::endl;
			if (prev) {
				prev->str = prev_str;
			}
			trunk->str = "   |";
		
			_print_tree(root->left, trunk, false, end);
			delete	trunk;
		}


};

}

/* BROUILLON INSERT

	// if (_root == _end){ //at beginning
		// _construct_node(current, _node(val, parent));
		// current->right = _end;
		// _end->parent = current;
		// _root = current;
		// return (make_pair(iterator(current), true));
	// }
	// if (current == NULL) {
		// _construct_node(current, _node(val, parent));
		// return (make_pair(iterator(current), true));
	// }
	// if (current == _end) {//beginning or when leaf at outmost right
		// _construct_node(current, _node(val, parent));
		// current->right = _end;
		// _end->parent = current;
		// return (make_pair(iterator(current), true));
	// }

	
//!!! When going before begin() shoudl segfault so ROOT should have a random value for parent OR should just go to NULL
void _insert_node_at(_node **position, _node *parent, const value_type &val){
	_construct_node(position, _node(val, parent));
	//Handle _end : if position was end, then added node and end have same parent
	if (parent == _end->parent) {
		std::cout << "parent = end" << std::endl;
		(*position)->right = _end;
		// (*position)->parent = _root; //??
		_end->parent = *position;
	}
	//Handle _begin
	if (_begin == NULL || _val_comp(*(*position)->val_ptr, *_begin->val_ptr))
		_begin = *position;
	// std::cout << "Value when just inserting : " << (*position)->val_ptr->first << std::endl;
};

//ISSUE WITH LINKING NODES TO ONE ANOTHER
pair<iterator,bool>	_insert(const value_type& val, _node *current, _node *parent) {
	if (current == _end || current == NULL) {
		_insert_node_at(&current, parent, val);
		// std::cout << "Value when out of function : " << current->val_ptr->first << std::endl;
		//balance
		return (make_pair(iterator(current), true));
	}
	std::cout << "LOOKS FOR LEAF" << std::endl;
	if (_val_comp(val, *current->val_ptr)) //insert to the left
		return (_insert(val, current->left, current));
	else if (_val_comp(*current->val_ptr, val)) //insert to the right
		return (_insert(val, current->right, current));
	else //keys are same
		return (make_pair(iterator(current), false));
};
*/
#endif //MAP_HPP