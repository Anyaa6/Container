/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonnel <abonnel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 14:57:21 by abonnel           #+#    #+#             */
/*   Updated: 2022/05/16 16:37:07 by abonnel          ###   ########.fr       */
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

enum erase { DELETE = 1, KEEP_NODE = 0 };
enum node_alignement {LINE_LEFT, LINE_RIGHT, LINE, TRIANGLE, TRIANGLE_LEFT, TRIANGLE_RIGHT};

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
			if (_end) {
				_alloc.deallocate(_end->val_ptr, 1);
				_node_alloc.destroy(_end);
				_node_alloc.deallocate(_end, 1);
			}
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

		//depends on map implementation so cannot be same as std since _node_size will be different
		size_type max_size() const {
			return std::numeric_limits<difference_type>::max();
		};
			
		void swap (map& x) {
			map tmp;

			_alloc.deallocate(tmp._end->val_ptr, 1);
			_node_alloc.destroy(tmp._end);
			_node_alloc.deallocate(tmp._end, 1);
			
			_swap_between(tmp, *this);
			_swap_between(*this, x);
			_swap_between(x, tmp);
			_set_to_zero(&tmp);
		};
		
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

		void erase (iterator position) {
			if (_root == _end)
				return;
			_node *to_delete = _convert_iterator_to_node(_root, position);
			if (to_delete == _end)
				return;
			if (to_delete->right && to_delete->left)
				_erase_node_2_childs(to_delete);
			else
				_erase_node_1_or_no_childs(to_delete, DELETE);
			//BALANCE TREE (from position?)
		};
		
		size_type erase (const key_type& k) {
			iterator from_key = find(k);

			if (from_key == end())
				return 0;
			this->erase(from_key);
			//BALANCE TREE (from position?)
			return 1;
		};

		void erase (iterator first, iterator last) {
			for (; first != last; first++)
				this->erase(first);
			//BALANCE TREE (from position?)
		};
		
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

	
	//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++		
	//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++		
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

		bool _get_uncle_color(_node *parent, _node *grandparent) {
			_node *uncle;

			if (grandparent->left == parent)
				uncle = grandparent->right;
			else
				uncle = grandparent->left;
			
			/*
			std::cout << "parent = " << parent->val_ptr->first << std::endl;
			std::cout << "grandparent = " << grandparent->val_ptr->first << std::endl;
			std::cout << "grandparent->right->first = " << grandparent->right->val_ptr->first << std::endl;
			std::cout << "grandparent->right->second = " << grandparent->right->val_ptr->second << std::endl;
			std::cout << "_end->first = " << _end->val_ptr->first << std::endl;
			std::cout << "_end->second = " << _end->val_ptr->second << std::endl;
			*/
			if (uncle == NULL)
				std::cout << "UNCLE is NULL" << std::endl;
			else
				std::cout << "uncle = " << uncle->val_ptr->first << std::endl;
			
			if (uncle == NULL)
				return BLACK;
			return uncle->color;
		};

		void	_switch_color(_node *grandparent, _node *left_child, _node *right_child) {
			if (grandparent)
				grandparent->color = !grandparent->color;
			if (left_child)
				left_child->color = !left_child->color;
			if (right_child)
				right_child->color = !right_child->color;
		};

		int _nodes_alignement(_node const *current, _node const *parent, _node const *grandparent) {
			if (grandparent->left == parent && parent->left == current) 
				return LINE_LEFT;
			else if (grandparent->right == parent && parent->right == current)
				return LINE_RIGHT;
			else if (grandparent->right == parent && parent->left == current)
				return TRIANGLE_RIGHT;
			return TRIANGLE_LEFT;
		}

		void _left_rotate(_node *down, _node *up, _node* switch_parent) {
			std::cout << "down = " << down->val_ptr->first << std::endl;
			std::cout << "up = " << up->val_ptr->first << std::endl;
			
			if (down == _root)
				_root = up;
			else if (down->parent->right == down) 
				down->parent->right = up;
			else
				down->parent->left = up;
			up->parent = down->parent;
			
			down->right = switch_parent;
			if (switch_parent)
				switch_parent->parent = down;
			
			down->parent = up;
			up->left = down;
		};

		void _right_rotate(_node *down, _node *up, _node* switch_parent) {
			std::cout << "down = " << down->val_ptr->first << std::endl;
			std::cout << "up = " << up->val_ptr->first << std::endl;
			
			if (down == _root)
				_root = up;
			else if (down->parent->right == down) 
				down->parent->right = up;
			else
				down->parent->left = up;
			up->parent = down->parent;
			
			down->left = switch_parent;
			if (switch_parent)
				switch_parent->parent = down;
			
			down->parent = up;
			up->right = down;
		};
		
		//granparent always exist bc even if one node then it does a loop : node -> root -> node -> root
		void _balance_insertion(_node *current, _node *parent, _node *grandparent) {
			//if added node is root then color it in black
			if (_root == current)
				current->color = BLACK;
			//if parent is RED -> violation
 			else if (parent->color == RED)
			{
				bool uncle_color = _get_uncle_color(parent, grandparent);
				std::cout << "For current = " << current->val_ptr->first << " with color = " << (current->color == RED ? "RED" : "BLACK") << "\nuncle_color = " << (uncle_color == RED ? "RED\n" : "BLACK\n") << std::endl;
				
				//if uncle is also red do recoloring and then set GRANDPARENT
				//as the node to be checked for violations recursively
				if (uncle_color == RED){
					_switch_color(grandparent, grandparent->left, grandparent->right);
					_balance_insertion(grandparent, grandparent->parent, grandparent->parent->parent);
				}
				//if uncle is black
				else if (uncle_color == BLACK) {
					int node_alignement = _nodes_alignement(current, parent, grandparent);
					//if line shape then rotate GRANDPARENT to the opposite side of node so that parent becomes top 
					//and recolor PARENT and GRANDPARENT
					if (node_alignement <= LINE) {
						std::cout << "LINE" << std::endl;
						if (node_alignement == LINE_RIGHT)
							_left_rotate(grandparent, parent, parent->left);
						if (node_alignement == LINE_LEFT)
							_right_rotate(grandparent, parent, parent->right);
						_switch_color(grandparent, parent, NULL);
					}
					//if triangle formation then rotate PARENT to the opposite side of node so that becomes line shape, with PARENT
					//being now the VIOLATING node, so call balancing recursively on HIM/PARENT
					else if (node_alignement >= TRIANGLE) {
						std::cout << "TRIANGLE" << std::endl;
						if (node_alignement == TRIANGLE_RIGHT)
							_right_rotate(parent, current, current->right);
						if (node_alignement == TRIANGLE_LEFT)
							_left_rotate(parent, current, current->left);
						_balance_insertion(parent, parent->parent, parent->parent->parent);
					}
				}				
			}
		};

		pair<iterator,bool>	_insert_from_root(const value_type& val, _node *&current, _node *&parent) {
			if (current == _end || current == NULL) {
				_insert_do_end_root_begin(current, _node(val, parent));
				//BALANCE TREE - beware to not change current for return value
				// std::cout << "before " << current->val_ptr->first << std::endl;
				print_tree();
				_balance_insertion(current, current->parent, current->parent->parent);
				print_tree();
				std::cout << "\n\n" << std::endl;
				// std::cout << "after " << current->val_ptr->first << std::endl;
				return (make_pair(iterator(current), true));
			}
			if (_val_comp(val, *current->val_ptr))
				return (_insert_from_root(val, current->left, current));
			else if (_val_comp(*current->val_ptr, val))
				return (_insert_from_root(val, current->right, current));
			return (make_pair(iterator(current), false)); //keys are same
		};

		//-------------------------------------------------------------------------------------
		//ERASE
		/* in std even if you use the iterator of another map, as long as it finds a corresponding 
		key, then it will delete this node which will mess up the entire map structure
		but it is because it has access directly to the underlying pointer that the iterator holds
		map.erase(iterator_of_other_map)
		so here even if you call erase on "map" then it will actually destroy the node from "other_map"
		bc that is the map that the iterator belongs to
		since we do not have access to underlying pointer, behaviour will be different */
		
		_node *_convert_iterator_to_node(_node *current, const iterator &position) {
			if (current == _end || current == NULL)
				return (_end);
			if (_val_comp(*current->val_ptr, *position))
				return (_convert_iterator_to_node(current->right, position));
			if (_val_comp(*position, *current->val_ptr))
				return (_convert_iterator_to_node(current->left, position));
			return (current);
		};

		_node **_get_parent_ptr(_node const *to_delete) {
			if (to_delete == _root)
				return (&_root);
				
			_node *parent = to_delete->parent;
			
			if (parent->left == to_delete)
				return (&parent->left);
			//is right child - also takes _end
			return (&parent->right);
		};
		
		_node *_get_child_ptr(_node const *to_delete) {
			if (to_delete->left)
				return (to_delete->left);
			return (to_delete->right);
		};

		_node *_get_next_smaller(_node const *to_delete) {
			_node *next_smaller = to_delete->left;

			while (next_smaller->right)
				next_smaller = next_smaller->right;
			return (next_smaller);
		};
		
		//bridge from = adress of parent pointer to child to_delete
		//bridge to = pointer to to_delete's child
		//if node has 1 or no child, bridge between parent and child of deleted node
		void	_erase_node_1_or_no_childs(_node *to_delete, bool erased_node) {
			_node **bridge_from = _get_parent_ptr(to_delete);
			_node *bridge_to = _get_child_ptr(to_delete); //no double pointer cause value changed is derived from ptr ->parent

			if (to_delete == _begin && erased_node == DELETE)
				((bridge_to == NULL) ? (_begin = to_delete->parent) : (_begin = bridge_to));
			*bridge_from = bridge_to;
			if (bridge_to != NULL)
				bridge_to->parent = to_delete->parent;
			if (erased_node == DELETE)
				_delete_node(to_delete);
		};		
		
		void	_replace_node(_node const *former_node, _node *replacing_node, _node **at) {
			*at = replacing_node;
			
			replacing_node->parent = former_node->parent;
			replacing_node->right = former_node->right;
			replacing_node->left = former_node->left;
			if (replacing_node->right)
				replacing_node->right->parent = replacing_node;
			if (replacing_node->left)
				replacing_node->left->parent = replacing_node;
		};
		
		//if node has 2 childs, choose biggest of left side to replace it
			//(not smallest of right side bc it could be _end)
		void	_erase_node_2_childs(_node *to_delete) {
			_node **bridge_from = _get_parent_ptr(to_delete);
			_node *replaces_deleted = _get_next_smaller(to_delete);

			_erase_node_1_or_no_childs(replaces_deleted, KEEP_NODE);
			_replace_node(to_delete, replaces_deleted, bridge_from);
			_delete_node(to_delete);
		};
		
		//-------------------------------------------------------------------------------------
		//CLEAR DELETE COPY SWAP
		void	_clear_tree(_node *current) {
			if (current == NULL || current == _end)
				return;
			_clear_tree(current->left);
			_clear_tree(current->right);
			_delete_node(current);
		}
		
		void _delete_node(_node *&node_to_destroy) {
			// std::cout << "deleting " << node_to_destroy->val_ptr->first << std::endl;
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

		void	_swap_between(map &x, map &y) {
			x._root = y._root;
			x._end = y._end;
			x._begin = y._begin;
			x._size = y._size;
			x._alloc = y._alloc;
			x._node_alloc = y._node_alloc;
			x._comp = y._comp;
			x._val_comp = y._val_comp;
		};

		void _set_to_zero(map *tmp) {
			tmp->_root = NULL;
			tmp->_end = NULL;
			tmp->_begin = NULL;
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