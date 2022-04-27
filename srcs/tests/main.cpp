/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonnel <abonnel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 11:08:39 by                   #+#    #+#             */
/*   Updated: 2022/04/27 17:31:40 by abonnel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#if std_lib//CREATE A REAL STL EXAMPLE
	#define TESTING "Testing with std library"
	#include <limits>
	#include <iterator>
	#include <vector>
	#include <stack>
	#include <map>
	#include <utility>
	namespace ft = std;
#else
	#define TESTING "Testing with ft library"
	#include "../utils/metafunctions.hpp"
	#include "../iterators/iterator.hpp"
	#include "../containers/vector.hpp"
	#include "../containers/stack.hpp"
	#include "../containers/map.hpp"
	#include "../utils/pair.hpp"
#endif
#include "tester_class.hpp"

int main()
{
	std::cout << TESTING << std::endl;
	//--------------------------------------
	
	ft::map<int, int>	empty_map;
	
	// for (int i = 12; i >= 0; i--) 
		// empty_map.insert(ft::make_pair(i, i + 2));

	for (int i = 0; i < 12; i++) 
		empty_map.insert(ft::make_pair(i, i + 2));

	ft::map<int, int>::iterator		it_em = empty_map.begin();
	std::cout << "C" << std::endl;
	
	// for (; it_em != empty_map.end(); it_em++)
		std::cout << "begin key = " << it_em->first << " value =  "<< it_em->second << std::endl;
	// std::map<int, int>::iterator it = empty_map.end();
	// std::cout << "second : "<<std::endl;
	// std::cout << "end = " << (empty_map.end())->second << std::endl;
	// std::cout << "begin = " << (empty_map.begin())->second << std::endl;
	// 
	// std::cout << "\nfirst : "<< std::endl;
	// std::cout << "end = " << (empty_map.end())->first << std::endl;
	// std::cout << "begin = " << (empty_map.begin())->first << std::endl;

	return 0;
}