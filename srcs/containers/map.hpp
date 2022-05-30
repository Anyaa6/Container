/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonnel <abonnel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 14:57:21 by abonnel           #+#    #+#             */
/*   Updated: 2022/05/30 15:46:05 by abonnel          ###   ########.fr       */
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

enum e_erase { DELETE = 1, KEEP_NODE = 0 };
enum e_node_alignement {LINE_LEFT, LINE_RIGHT, LINE, TRIANGLE, TRIANGLE_LEFT, TRIANGLE_RIGHT};

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
				value_compare (Compare c) : comp(c) {}
				
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
			_node *to_delete = _convert_iterator_to_node(_root, position);

			if (to_delete == _end)
				return;
				
			if (to_delete->right && to_delete->left)
			{
				_node *predecessor = _get_predecessor(to_delete);
				_swap_values(predecessor, to_delete);
				_erase_1_or_no_child(predecessor);
			}
			else
				_erase_1_or_no_child(to_delete);
		};

		size_type erase (const key_type& k) {
			iterator from_key = find(k);

			if (from_key == end())
				return 0;
			this->erase(from_key);
			return 1;
		};

		void erase (iterator first, iterator last) {
			for (; first != last; first++)
				this->erase(first);
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
			while (_comp(it->first, k) == false && _comp(k, it->first) == false)
				return (++it);
			return (it);
		};
		
		const_iterator upper_bound (const key_type& k) const {
			iterator it = begin();
			
			while (_comp(it->first, k) && it != _end)
				it++;
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
			_root->parent = _root;
		};
		
		//-------------------------------------------------------------------------------------
		//INSERT

		bool _get_uncle_color(_node *parent, _node *grandparent) {
			_node *uncle;

			if (grandparent->left == parent)
				uncle = grandparent->right;
			else
				uncle = grandparent->left;
				
			if (uncle == NULL)
				return BLACK;
			return uncle->color;
		};

		void	_switch_color(_node *node1, _node *node2, _node *node3) {
			if (node1)
				node1->color = !node1->color;
			if (node2)
				node2->color = !node2->color;
			if (node3)
				node3->color = !node3->color;
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

		void _left_rotate(_node *down) {
			_node* up = down->right;
			_node* switch_parent = up->left;
			
			if (down == _root) {
				_root = up;
				up->parent = _root;
			}
			else {
				if (_is_on_right(down)) 
					down->parent->right = up;
				else
					down->parent->left = up;
				up->parent = down->parent;
			}
			
			down->right = switch_parent;
			if (switch_parent)
				switch_parent->parent = down;
			
			down->parent = up;
			up->left = down;
		};

		void _right_rotate(_node *down) {
			_node* up = down->left;
			_node* switch_parent = up->right;
			
			if (down == _root) {
				_root = up;
				up->parent = _root;
			}
			else {
				if (_is_on_right(down)) 
					down->parent->right = up;
				else
					down->parent->left = up;
				up->parent = down->parent;
			}
			
			down->left = switch_parent;
			if (switch_parent)
				switch_parent->parent = down;
			
			down->parent = up;
			up->right = down;
		};
		

		void _black_uncle_violation(_node *current, _node *parent, _node *grandparent) {
			int node_alignement = _nodes_alignement(current, parent, grandparent);
			
			if (node_alignement <= LINE) {
				if (node_alignement == LINE_RIGHT)
					_left_rotate(grandparent);
				if (node_alignement == LINE_LEFT)
					_right_rotate(grandparent);
				_switch_color(grandparent, parent, NULL);
			}
			else if (node_alignement >= TRIANGLE) {
				if (node_alignement == TRIANGLE_RIGHT)
					_right_rotate(parent);
				if (node_alignement == TRIANGLE_LEFT)
					_left_rotate(parent);
				_balance_insertion(parent, parent->parent, parent->parent->parent);
			}
		};
		
		void _balance_insertion(_node *current, _node *parent, _node *grandparent) {
			if (_root == current)
				current->color = BLACK;
 			else if (parent->color == RED)
			{
				bool uncle_color = _get_uncle_color(parent, grandparent);
				if (uncle_color == RED){
					_switch_color(grandparent, grandparent->left, grandparent->right);
					_balance_insertion(grandparent, grandparent->parent, grandparent->parent->parent);
				}
				else if (uncle_color == BLACK)
					_black_uncle_violation(current, parent, grandparent);
			}
		};
		
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
			if (is_root) {
				_root = current;
				current->parent = _root;
			}
			if (is_begin)
				_begin = current;
		};
		
		pair<iterator,bool>	_insert_from_root(const value_type& val, _node *&current, _node *&parent) {
			if (current == _end || current == NULL) {
				_insert_do_end_root_begin(current, _node(val, parent));
				_balance_insertion(current, current->parent, current->parent->parent);
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
			return (&parent->right);
		};
		
		_node *_get_child_ptr(_node const *to_delete) {
			if (to_delete->left)
				return (to_delete->left);
			return (to_delete->right);
		};

		_node *_get_predecessor(_node const *to_delete) {
			_node *next_smaller = to_delete->left;

			while (next_smaller && next_smaller->right)
				next_smaller = next_smaller->right;
			return (next_smaller);
		};
		
		//if node has 1 or no child
		void _delete_node_from_tree(_node *to_remove) {
			_node **bridge_from = _get_parent_ptr(to_remove);
			_node *bridge_to = _get_child_ptr(to_remove);

			*bridge_from = bridge_to;
			if (bridge_to != NULL)
				bridge_to->parent = to_remove->parent;
			_delete_node(to_remove);
		};		

		_node *_get_sibling(_node *current, _node *parent) {
			if (parent->left == current)
				return (parent->right);
			return (parent->left);
		};

		bool _is_on_right(_node *child) {
			if (child->parent->right == child)
				return true;
			return false;
		};

		bool _is_on_left(_node *child) {
			if (child->parent->left == child)
				return true;
			return false;
		};

		bool _childs_are_black(_node *sibling) {
			if ((sibling->left == NULL || sibling->left->color == BLACK)
			&& (sibling->right == NULL || sibling->right->color == BLACK))
				return true;
			return false;
		};
		
		_node *_inner_child(_node *sibling) {
			if (_is_on_left(sibling))
				return (sibling->right);
			return (sibling->left);
		};

		_node *_outer_child(_node *sibling) {
			if (_is_on_left(sibling))
				return (sibling->left);
			return (sibling->right);
		};

		bool _outer_child_is_black(_node *sibling) {
			if (_is_on_right(sibling) && (sibling->right == NULL || sibling->right->color == BLACK))
				return true;
			if (_is_on_left(sibling) && (sibling->left == NULL || sibling->left->color == BLACK))
				return true;
			return false;			
		};

		bool _outer_child_is_red(_node *sibling) {
			if (_is_on_right(sibling) && sibling->right && sibling->right->color == RED)
				return true;
			if (_is_on_left(sibling) && sibling->left && sibling->left->color == RED)
				return true;
			return false;
		};

		void _balance_erase(_node *current, _node *parent) {
			if (current == _root) {
				current->color = BLACK;
				return;
			}
			
			_node *sibling = _get_sibling(current, parent);
			
			if (sibling == NULL)
				_balance_erase(parent, parent->parent);
			else if (sibling->color == RED)
			{
				sibling->color = BLACK;
				parent->color = RED;
				if (_is_on_right(sibling))
					_left_rotate(parent);
				else
					_right_rotate(parent);
				_balance_erase(current, parent);
			}
			else //sibling is black
			{
				if (_childs_are_black(sibling)) {
					sibling->color = RED;
					if (parent->color == BLACK)
						_balance_erase(parent, parent->parent);
					else
						parent->color = BLACK;
				}
				else if (_outer_child_is_black(sibling)) 
				{
					_switch_color(sibling, _inner_child(sibling), NULL);
					if (_is_on_right(sibling))
						_right_rotate(sibling);
					else
						_left_rotate(sibling);
					_balance_erase(current, parent);
					
				}
				else if (_outer_child_is_red(sibling))
				{
					sibling->color = parent->color;
					parent->color = _outer_child(sibling)->color = BLACK;
					if (_is_on_right(sibling))
						_left_rotate(parent);
					else
						_right_rotate(parent);
				}
			}
		};
		
		void _swap_values(_node *predecessor, _node *to_delete) {
			value_type		*tmp = predecessor->val_ptr;

			predecessor->val_ptr = to_delete->val_ptr;
			to_delete->val_ptr = tmp;			
		};

		void _erase_1_or_no_child(_node *to_delete) {
			_node *parent = to_delete->parent;
			_node *replacing_node = (to_delete->left ? to_delete->left : to_delete->right);
			bool double_black = (to_delete->color == BLACK && (replacing_node == NULL || replacing_node->color == BLACK));

			if (to_delete == _root)
			{
				_root = replacing_node;
				replacing_node->parent = _root;
				replacing_node->color = BLACK;
				return;
			}
			if (to_delete == _begin)
				((_begin->right) ? (_begin = _begin->right) : (_begin = _begin->parent));
			
			_delete_node_from_tree(to_delete);
			
			if (double_black)
				_balance_erase(replacing_node, parent);
			else if (replacing_node)
				replacing_node->color = BLACK;
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
#endif //MAP_HPP