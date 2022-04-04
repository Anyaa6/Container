/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonnel <abonnel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 14:57:21 by abonnel           #+#    #+#             */
/*   Updated: 2022/04/01 15:17:50 by abonnel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
#define MAP_H

#include <memory>
#include <functional>
#include "pair.hpp"


namespace ft 
{
	
	template < class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<pair<const Key,T> > >
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
		// typedef bidir_iterator						iterator;
		// typedef const bidir_iterator						const_iterator;
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
		map(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) : root(NULL), _size(0), _alloc(alloc), _comp(comp) {};
		
		~map(){
			//destroy_tree;
		};

		
		
	private:
		node 			*root;
		size_type 		_size;
		allocator_type	_alloc;
		key_compare		_comp;

		struct _node {
			value_type	value;
			node 		*left;
			node 		*right;
			node 		*parent;
			bool		color;

			// _node(data) : value(data) {
				// left = right = parent = NULL;
				// color = RED;	//create enum for RED and BLACK
			// };
		};
};

}

#endif