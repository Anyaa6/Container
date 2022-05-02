/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonnel <abonnel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 12:35:23 by abonnel           #+#    #+#             */
/*   Updated: 2022/05/02 14:45:49 by abonnel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NODE_HPP
#define NODE_HPP

enum RBtree { RED, BLACK };
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
		std::cout << sizeof(value_type) << std::endl;
	};

	node(int flag) {
		if (flag == END_NODE) {
			//VALUE IS NOT EVEN ALLOCATED IN END NODE OF STD NOR CONSTRUCTED
			// val_ptr = val_alloc.allocate(1); 
			color = BLACK;
			left = NULL;
			right = NULL;
		}
	};

	//Random parent/child node constructor
	node(){
		//color = XX; BLACK ? only for node
	};

	~node(){
		// std::cout << "destroy " <<  val_ptr->first << " and " << val_ptr->second << std::endl;
		// val_alloc.destroy(val_ptr);
		// val_alloc.deallocate(val_ptr, 1);
		std::cout << "Destroy node" << std::endl;
	};//a definir

	key_type get_key() {
		return (val_ptr->first);
	};
};

}

#endif //NODE_HPP

/*

	// node(const node &to_copy) {
	// 	val_ptr = val_alloc.allocate(1);
	// 	val_alloc.construct(val_ptr, *(to_copy.val_ptr));
	// 	left = to_copy.left;
	// 	right = to_copy.right;
	// 	parent = to_copy.parent;
	// 	color = to_copy.color;
	// };
	
	// node &operator=(const node &to_copy) {
	// 	val_ptr = val_alloc.allocate(1);
	// 	val_alloc.construct(val_ptr, *(to_copy.val_ptr));
	// 	left = to_copy.left;
	// 	right = to_copy.right;
	// 	parent = to_copy.parent;
	// 	color = to_copy.color;
	// };
*/
