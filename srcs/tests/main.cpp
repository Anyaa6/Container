/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariane <ariane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 11:08:39 by                   #+#    #+#             */
/*   Updated: 2022/04/29 12:48:49 by ariane           ###   ########.fr       */
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
	
	ft::map<int, int>	simple_inserts;
	
	for (int i = 12; i >= 0; i--)
		simple_inserts.insert(ft::make_pair(i, i + 2));
	for (int i = 0; i < 5; i++)
		simple_inserts.insert(ft::make_pair(i, i + 2));

	simple_inserts.insert(ft::make_pair(-5, 2));

	ft::map<int, int>::iterator		it_em = simple_inserts.begin();

	for (; it_em != simple_inserts.end(); it_em++)
		std::cout << "begin key = " << it_em->first << " value =  "<< it_em->second << std::endl;

	std::cout << "\n REVERSE" << std::endl;
	ft::map<int, int>::reverse_iterator		rit_em = simple_inserts.rbegin();
		// 
	for (; rit_em != simple_inserts.rend(); rit_em++)
		std::cout << "begin key = " << rit_em->first << " value =  "<< rit_em->second << std::endl;

	std::cout << simple_inserts.size() << std::endl;
		
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