/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonnel <abonnel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 11:08:39 by                   #+#    #+#             */
/*   Updated: 2022/01/25 17:56:01 by abonnel          ###   ########.fr       */
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

	// std::vector<int> real_stuff;
// 
	// std::cout << real_stuff.max_size() << std::endl;


	return 0;
}