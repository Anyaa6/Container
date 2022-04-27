/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonnel <abonnel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 12:35:23 by abonnel           #+#    #+#             */
/*   Updated: 2022/04/27 17:17:52 by abonnel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NODE_HPP
#define NODE_HPP

enum RBtree { RED, BLACK };

namespace ft {
	
template <typename Pair >
struct node {
	
	typedef	Pair					value_type;
	typedef std::allocator< Pair >	allocator_type;
	
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

	//Random parent/child node constructor
	node(){
		//color = XX; BLACK ? only for node
	};

	~node(){};//a definir
};

}

#endif //NODE_HPP
