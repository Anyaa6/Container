/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Namespace.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 11:11:45 by                   #+#    #+#             */
/*   Updated: 2022/01/19 11:11:45 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTAINER_NAMESPACE_HPP
#define CONTAINER_NAMESPACE_HPP

#include <iostream>

namespace ft
{
	class vector;
	class map;
	class stack;
}

// Defining class outside, in another file
class ft::vector
{
public:
	void display()
	{
		std::cout << "lol" << std::endl;
	}
};

#endif //CONTAINER_NAMESPACE_HPP
