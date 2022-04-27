/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonnel <abonnel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 14:57:21 by abonnel           #+#    #+#             */
/*   Updated: 2022/04/27 17:32:05 by abonnel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
#define MAP_HPP

#include <memory>
#include <functional>
#include "../utils/pair.hpp"
#include "../utils/node.hpp"
#include "../iterators/bidirectional_iterator.hpp"

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
			_construct_node(&_end, _node());
			_end->val_ptr = _alloc.allocate(1);
			_end->color = BLACK;
			_end->parent = _root;
			//Value is allocated but not constructed
			_root = _end;
			_begin = NULL;
		};
		
		~map(){
			//destroy_tree;
		};

		bool empty() const {
			//or return (_size == 0);
			return (_root == _end);
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
			return (_insert(val, _root, NULL));
		};
		
		// iterator insert (iterator position, const value_type& val);
		
		// template <class InputIterator>
		// void insert (InputIterator first, InputIterator last);

		
	private:
		_node 			*_root;
		_node			*_end;
		_node			*_begin; //smallest key
		size_type 		_size;
		allocator_type		_alloc;
		_node_alloc_type	_node_alloc;
		key_compare		_comp;
		value_compare	_val_comp;

		void _construct_node(_node **position, const _node &node) {
			*position = _node_alloc.allocate(1);
			_node_alloc.construct(*position, node);
		};
		
		//!!! When going before begin() shoudl segfault so ROOT should have a random value for parent OR should just go to NULL
		void _insert_node_at(_node *position, _node *parent, const value_type &val){
			//create fun for 2 next lines, can be used with _end as well if sending _node(XXX)
			//alloc et construct NODE + pair 
			//handles parent, childs and color
			_construct_node(&position, _node(val, parent));

			//Handle _end : if position was end, then added node and end have same parent
			if (parent == _end->parent) {
				position->right = _end;
				_end->parent = position;
			}
			//Handle _begin
			if (_begin == NULL || _val_comp(*position->val_ptr, *_begin->val_ptr))
				_begin = position;
		};

		pair<iterator,bool>	_insert(const value_type& val, _node *current, _node *parent) {
			if (current == _end || current == NULL) {
				_insert_node_at(current, parent, val);
				//balance
				return (make_pair(iterator(current), true));
			}
			if (_val_comp(val, *current->val_ptr)) //insert to the left
				return (_insert(val, current->left, current));
			else if (_val_comp(*current->val_ptr, val)) //insert to the right
				return (_insert(val, current->right, current));
			else //keys are same
				return (make_pair(iterator(current), false));
		};
		

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