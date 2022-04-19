/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonnel <abonnel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 12:35:23 by abonnel           #+#    #+#             */
/*   Updated: 2022/04/19 13:45:32 by abonnel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NODE_HPP
#define NODE_HPP

namespace ft {
	
template <typename Pair>
struct node {
	Pair		*value;
	node 		*left;
	node 		*right;
	node 		*parent;
	bool		color;

	//CONSTRUCTOR
	// node(Pair &data) : value(data) {
		// left = right = parent = NULL;
		// std::cout << "LOOOOL" << std::endl;
		// color = RED;	//create enum for RED and BLACK
	// };

	node(){
		value = NULL;
		left = right = parent = NULL;
		std::cout << "HAAAAA" << std::endl;
	};

	~node(){};//a definir
};

}

#endif //NODE_HPP
