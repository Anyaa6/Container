/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariane <ariane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 11:08:39 by                   #+#    #+#             */
/*   Updated: 2022/01/26 09:05:49 by ariane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"
#include <iostream>


#include <vector> //A ENLEVER
#include <iterator> //A ENLEVER

int main()
{
	ft::vector<int>	haha(5, 12);

	for (int i = 0; i < 5; i++)
		std::cout << haha[0] << std::endl;

	std::vector<int> real_stuff(52,12);

	std::cout << "first" << std::endl;
	std::cout << real_stuff.size() << std::endl;
	std::cout << real_stuff.capacity() << std::endl;

	std::cout << "Push backs" << std::endl;
	for (int i = 0; i < 13 ; i++)
	{
		real_stuff.push_back(42);
		std::cout << "size : " << real_stuff.size() << std::endl;
		std::cout << "capacity : " << real_stuff.capacity() << std::endl;
	}
	return 0;
}