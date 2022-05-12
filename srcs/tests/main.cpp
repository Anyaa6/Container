/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonnel <abonnel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 11:08:39 by                   #+#    #+#             */
/*   Updated: 2022/05/12 13:44:13 by abonnel          ###   ########.fr       */
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
#include <string>
#include "tester_class.hpp"

int main()
{
	std::cout << TESTING << std::endl;
	//--------------------------------------
	//TEST ON MQAP WITH A SINGLE NODE
	ft::map<int, int> 	map_erase_test;

	// for (int i = 0; i < 5; i++)
		// map_erase_test.insert(ft::make_pair(i, i+2));
// 
	// for (int i = -5; i < 0; i++)
		// map_erase_test.insert(ft::make_pair(i, i+2));
		// 
	// for (int i = -6; i > -10; i--)
		// map_erase_test.insert(ft::make_pair(i, i+2));

	std::cout << map_erase_test.max_size() << std::endl;
	return 0;
}