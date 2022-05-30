/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonnel <abonnel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 12:35:23 by abonnel           #+#    #+#             */
/*   Updated: 2022/05/30 15:41:53 by abonnel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NODE_HPP
#define NODE_HPP

enum RBtree_color { RED = 0, BLACK = 1};
enum node_constructor_flag { END_NODE };

namespace ft {
	
template <typename Pair >
struct node {
	
	typedef	Pair					value_type;
	typedef std::allocator< Pair >	allocator_type;
	typedef typename Pair::first_type		key_type;
	
	allocator_type	val_alloc;
	value_type		*val_ptr;
	node 			*parent;
	node 			*left;
	node 			*right;
	bool			color;

	//CONSTRUCTOR
	//New node constructor - new nodes are always red
	node(const value_type &data, node *parent) 
	: parent(parent), color(RED) {
		val_ptr = val_alloc.allocate(1);
		val_alloc.construct(val_ptr, data);
		left = right = NULL;
	};

	node(bool flag) {
		if (flag == END_NODE) {
			val_ptr = val_alloc.allocate(1);
			color = BLACK;
			left = NULL;
			right = NULL;
		}
	};

	node(){};

	~node(){};
};

}

#endif //NODE_HPP