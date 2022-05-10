/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariane <ariane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 11:08:39 by                   #+#    #+#             */
/*   Updated: 2022/05/10 13:39:35 by ariane           ###   ########.fr       */
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
	//TEST ON MQAP WITH A SINGLE NODE
	ft::map<int, int> 	map_erase_test;

	for (int i = 0; i < 5; i++)
		map_erase_test.insert(ft::make_pair(i, i+2));

	for (int i = -5; i < 0; i++)
		map_erase_test.insert(ft::make_pair(i, i+2));
		
	for (int i = -6; i > -10; i--)
		map_erase_test.insert(ft::make_pair(i, i+2));

	ft::map<int, int>::iterator it = map_erase_test.begin();
	for (int i = 0; i < 7; i++)
		it++;

	
	std::cout << "\nPrinting map_erase" <<std::endl;
	// map_erase_test.print_tree();
	std::cout << "key to delete is : " << it->first << std::endl;
	map_erase_test.erase(it);
	// map_erase_test.print_tree();
	

	std::cout << "\nPrinting map_erase" <<std::endl;
	// map_erase_test.print_tree();
	std::cout << "key to delete is : " << (map_erase_test.begin())->first << std::endl;
	map_erase_test.erase(map_erase_test.begin());
	// map_erase_test.print_tree();

	std::cout << "\nPrinting map_erase" <<std::endl;
	// map_erase_test.print_tree();
	std::cout << "key to delete is : " << (--map_erase_test.end())->first << std::endl;
	map_erase_test.erase(--map_erase_test.end());
	// map_erase_test.print_tree();

	std::cout << "\nPrinting map_erase" <<std::endl;
	// map_erase_test.print_tree();
	std::cout << "key to delete is : " << (--map_erase_test.end())->first << std::endl;
	map_erase_test.erase(--map_erase_test.end());
	// map_erase_test.print_tree();

	ft::map<int, int>::iterator it_erase;
	it_erase = ++map_erase_test.begin();
	std::cout << "key to delete is : " << it_erase->first << std::endl;
	map_erase_test.erase(it_erase); //erase last node with no child

	std::cout << "\nPrinting map_erase" <<std::endl;
	it_erase = ------map_erase_test.end();
	// map_erase_test.print_tree();
	std::cout << "key to delete is : " << it_erase->first << std::endl;
	map_erase_test.erase(it_erase); //erase last node with no child
	// map_erase_test.print_tree();


		
	std::cout << "\nPrinting map_erase" <<std::endl;
	// map_erase_test.print_tree();
	it_erase = ++++map_erase_test.begin();
	std::cout << "key to delete is : " << it_erase->first << std::endl;
	map_erase_test.erase(it_erase); //erase last node with no child
	// map_erase_test.print_tree();

	std::cout << "\nPrinting map_erase" <<std::endl;
	// map_erase_test.print_tree();
	it_erase = ++++map_erase_test.begin();
	std::cout << "key to delete is : " << it_erase->first << std::endl;
	map_erase_test.erase(it_erase); //erase last node with no child
	// map_erase_test.print_tree();

	std::cout << "\nPrinting map_erase" <<std::endl;
	// map_erase_test.print_tree();
	it_erase = ++++map_erase_test.begin();
	std::cout << "key to delete is : " << it_erase->first << std::endl;
	map_erase_test.erase(it_erase); //erase last node with no child
	// map_erase_test.print_tree();
	
	map_erase_test.insert(ft::make_pair(-2, -2+2));
	// map_erase_test.insert(ft::make_pair(3, 3+2));

	std::cout << "\nPrinting map_erase" <<std::endl;
	// map_erase_test.print_tree();
	std::cout << "key to delete is : " << (----(map_erase_test.end()))->first << std::endl;
	map_erase_test.erase((----(map_erase_test.end())));
	// map_erase_test.print_tree();

	std::cout << "\nPrinting map_erase" <<std::endl;
	// map_erase_test.print_tree();
	it_erase = --map_erase_test.end();
	std::cout << "key to delete is : " << it_erase->first << std::endl;
	map_erase_test.erase(it_erase); //erase last node with no child
	// map_erase_test.print_tree();
	
	for (ft::map<int, int>::iterator it_map_erase = map_erase_test.begin(); it_map_erase != map_erase_test.end(); it_map_erase++)
		std::cout << "it->first = " << it_map_erase->first << std::endl;
		
	std::cout << "\nPrinting map_erase" <<std::endl;
	// map_erase_test.print_tree();
	std::cout << "key to delete is -6 " << std::endl;
	map_erase_test.erase(-6); //erase last node with no child
	// map_erase_test.print_tree();
	
	for (ft::map<int, int>::iterator it_map_erase = map_erase_test.begin(); it_map_erase != map_erase_test.end(); it_map_erase++)
		std::cout << "it->first = " << it_map_erase->first << std::endl;

	std::cout << "\nBEFORE END" << std::endl;
	return 0;
}