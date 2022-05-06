/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonnel <abonnel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 11:08:39 by                   #+#    #+#             */
/*   Updated: 2022/05/06 16:35:38 by abonnel          ###   ########.fr       */
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
	
	ft::map<int, int> 	map_erase_test;

	for (int i = 0; i < 5; i++)
		map_erase_test.insert(ft::make_pair(i, i+2));

	for (int i = -5; i < 0; i++)
		map_erase_test.insert(ft::make_pair(i, i+2));
		
	for (int i = -6; i > -10; i--)
		map_erase_test.insert(ft::make_pair(i, i+2));


	ft::map<int, int>::iterator it = map_erase_test.begin();
	for (int i = 0; i < 6; i++)
		it++;
			
	// ft::map<int, int> 	other_map;
	// for (int i = -12; i < 0; i++)
	// 	other_map.insert(ft::make_pair(i, i+2));
	// ft::map<int, int>::iterator it_other_map = ++(++(++(++(other_map.begin()))));
	
	// std::cout << "key to delete is : " << it->first << std::endl;
	// std::cout << "\nUsing iterator from other map\nkey to delete is : " << it_other_map->first << std::endl;
	// map_erase_test.erase(it_other_map);
	
	std::cout << "\nPrinting map_erase" <<std::endl;
	map_erase_test.print_tree();
	// map_erase_test.erase(it);
	// for (ft::map<int, int>::iterator it_map_erase = map_erase_test.begin(); it_map_erase != map_erase_test.end(); it_map_erase++)
		// std::cout << "it->first = " << it_map_erase->first << std::endl;
	std::cout << "\n\n" << std::endl;
	// std::cout << "\nPrinting other map" <<std::endl;
	// other_map.print_tree();
	// for (; it_other_map != other_map.end(); it_other_map++)
		// std::cout << "it->first = " << it_other_map->first << std::endl;

	it = --(map_erase_test.end());
	std::cout << "key to delete is : " << it->first << std::endl;
	map_erase_test.erase(it); //erase last node with no child
	map_erase_test.print_tree();

	// for (ft::map<int, int>::iterator it_map_erase = map_erase_test.begin(); it_map_erase != map_erase_test.end(); it_map_erase++)
		// std::cout << "it->first = " << it_map_erase->first << std::endl;

	std::cout << "\nBEFORE END" << std::endl;
	return 0;
}