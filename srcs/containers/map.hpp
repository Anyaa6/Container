/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonnel <abonnel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 14:57:21 by abonnel           #+#    #+#             */
/*   Updated: 2022/04/26 16:24:14 by abonnel          ###   ########.fr       */
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
		typedef Key 								key_type;
		typedef T 									mapped_type;
		typedef pair<const key_type, mapped_type> 	value_type;
		typedef Compare 							key_compare;
		typedef Alloc 								allocator_type;
		typedef typename allocator_type::reference 			reference;
		typedef typename allocator_type::const_reference	const_reference;
		typedef typename allocator_type::pointer			pointer;
		typedef typename allocator_type::const_pointer		const_pointer;
		
	private :
		typedef	node<value_type>	_node;
		typedef typename Alloc::template rebind<_node>::other _node_alloc_type;
	
	public:
		typedef typename ft::bidirectional_iterator<_node>		iterator;
		// typedef ft::bidirectional_iterator<const value_type>				const_iterator;
		// typedef reverse_iterator<iterator>			reverse_iterator
		// typedef const reverse_iterator<iterator>			const_reverse_iterator
		// typedef ft::iterator_traits<iterator>::difference_type	difference_type;
		typedef size_t	size_type;
		
		//key_compare compares keys directly, value_compare also compares keys but from the pairs level
		class value_compare {
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

		//CONSTRUCTOR
		map(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) : _root(NULL), _size(0), _alloc(alloc), _comp(comp) 
		{
			//Creating end node
			_end = _node_alloc.allocate(1);
			_node_alloc.construct(_end, _node());//!! HERE we do not want parent / right and left set to NULL, we want them to have random values so that when incrementing on end() then it will segfault
			_end->value = _alloc.allocate(1);
			//Value is allocated but not constructed
			_begin = _end;
		};
		
		~map(){
			//destroy_tree;
		};

		//begin & end
		// iterator begin();
		// const_iterator begin() const;
		
		//INSERT
		//!!! When going before begin() shoudl segfault so ROOT should have a random value for parent
		// pair<iterator,bool> insert (const value_type& val) {};
		
		// iterator insert (iterator position, const value_type& val);
		
		// template <class InputIterator>
		// void insert (InputIterator first, InputIterator last);

		
	private:
		_node 			*_root;
		_node			*_end;
		_node			*_begin;
		size_type 		_size;
		allocator_type	_alloc;
		_node_alloc_type	_node_alloc;
		key_compare		_comp;
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