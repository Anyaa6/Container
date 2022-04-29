/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariane <ariane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 14:57:21 by abonnel           #+#    #+#             */
/*   Updated: 2022/04/29 11:58:33 by ariane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
#define MAP_HPP

#include <memory>
#include <functional>
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

		value_compare value_comp() const {
			return (_val_comp);
		};

		key_compare key_comp() const {
			return (_comp);
		};

		//CONSTRUCTOR
		map(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) : _root(NULL), _size(0), _alloc(alloc), _comp(comp), _val_comp(value_comp()) 
		{
			//_node() gives random values to parent/right/left so that it will segfault when going after end()
			_construct_node(_end, _node(END_NODE));
			_end->parent = _root;
			_root = _end;
			_begin = NULL; //do begin == end and change begin == NULL condition in insert_node_at
		};
		
		~map(){
			//destroy_tree;
		};

		bool empty() const {
			//or return (_size == 0);
			return (_root == _end);
		};

		size_type size() const {
			return (_size);
		};
		
		//begin & end
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
		
		//INSERT
		//link is not made between root and next ones
		//seems like begin has not parent
		pair<iterator,bool> insert (const value_type& val) {
			return (_insert(val, _root, _root));
		};
		
		// iterator insert (iterator position, const value_type& val);
		
		// template <class InputIterator>
		// void insert (InputIterator first, InputIterator last);

		
	//private:
		_node 			*_root;
		_node			*_end;
		_node			*_begin; //smallest key
		size_type 		_size;
		allocator_type		_alloc;
		_node_alloc_type	_node_alloc;
		key_compare		_comp;
		value_compare	_val_comp;

		void _construct_node(_node *&position, const _node &new_node) {
			
			position = _node_alloc.allocate(1);
			_node_alloc.construct(position, new_node);
			if (position != _end)
				_size++;
		};

		void	_insert_do_end_root_begin(_node *&current, const _node &new_node) {
			int is_end = (current == _end);
			int is_root = (current == _root);
			int is_begin = (is_root || _val_comp(*new_node.val_ptr, *_begin->val_ptr));
			
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

		
		pair<iterator,bool>	_insert(const value_type& val, _node *&current, _node *&parent) {
			if (current == _end || current == NULL) {
				_insert_do_end_root_begin(current, _node(val, parent));
				//balance
				return (make_pair(iterator(current), true));
			}
			if (_val_comp(val, *current->val_ptr))
				return (_insert(val, current->left, current));
			else if (_val_comp(*current->val_ptr, val))
				return (_insert(val, current->right, current));
			return (make_pair(iterator(current), false)); //keys are same
		};

		/*

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
		

		//-------------------------------------------------------------------------------------
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

/* Random infos

	rend() segfault quand on essaye de l'imprimer 

	
	Ex de ce qu'il faut pour creer reellement un node
	_node		*tmp
	1) D'abord alloc et construct NODE
	tmp = _node_alloc.allocate(1);
	_node_alloc.construct(tmp, _node());
	
	2) Puis alloc et construct VALUE
	tmp->value = _alloc.allocate(1);
	_alloc.construct(tmp->value, value_type(key_type(), mapped_type()));
*/

#endif //MAP_HPP