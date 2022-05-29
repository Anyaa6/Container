/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariane <ariane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 11:08:39 by                   #+#    #+#             */
/*   Updated: 2022/05/25 14:46:44 by ariane           ###   ########.fr       */
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
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include "tester_class.hpp"
#define NUMBER_OF_RANDOM 100

int main()
{
	std::cout << TESTING << std::endl;
	//--------------------------------------
	//tester les retours de insert avec et sans balancing pour voir si current modifié
	//utiliser random pour add randomnumbers 

	srand (time(NULL));
	ft::map<int, int>		balance_test;

	for (int i = 0; i < 150; i += 2)
		balance_test.insert(ft::make_pair(i, i));

	balance_test.insert(ft::make_pair(99,99));
	balance_test.print_tree();

	balance_test.erase(130);
	balance_test.print_tree();
	
	/*
	//delete _begin to see what happens
	balance_test.insert(ft::make_pair(-2, -2+2));
	balance_test.insert(ft::make_pair(1, 2+2));
	balance_test.insert(ft::make_pair(2, 2+2));
	balance_test.erase(-2);

	// for (ft::map<int, int>::iterator it = balance_test.begin(); it != balance_test.end(); it++)
	// 	std::cout << it->first << " " << it->second << std::endl;
	*/
	
	/*
	for (int i = 0; i < 2; i++)
		balance_test.insert(ft::make_pair(i, i+2));

	balance_test.insert(ft::make_pair(-2, -2+2));
	balance_test.insert(ft::make_pair(2, 2+2));
	balance_test.insert(ft::make_pair(7, 3+2));
	balance_test.insert(ft::make_pair(4, 3+2));
	balance_test.insert(ft::make_pair(5, 3+2));
	balance_test.insert(ft::make_pair(7, 3+2));
	balance_test.insert(ft::make_pair(4, 4+2));
	balance_test.insert(ft::make_pair(5, 4+2));
	balance_test.insert(ft::make_pair(6, 4+2));
	balance_test.insert(ft::make_pair(7, 4+2));
	balance_test.insert(ft::make_pair(-3, 4+2));
	balance_test.insert(ft::make_pair(-4, 4+2));
	balance_test.insert(ft::make_pair(-8, 4+2));

	// balance_test.print_tree();
	balance_test.erase(1);
	balance_test.print_tree();
	balance_test.erase(-3);
	balance_test.print_tree();
	// balance_test.erase(-2);
	// balance_test.print_tree();
	*/
	
	/*
	std::cout << "\nAdding : " << std::endl;
	for (int i = 0; i < NUMBER_OF_RANDOM; i++) {
		int random = rand() % NUMBER_OF_RANDOM;
		std::cout << random << " ";
		balance_test.insert(ft::make_pair(random, random + 2));
	}
	std::cout << std::endl;
	
	balance_test.print_tree();
	// for (ft::map<int, int>::iterator it = balance_test.begin(); it != balance_test.end(); it++)
	// 	std::cout << it->first << " " << it->second << std::endl;
	
	std::cout << "\nErasing : " << std::endl;
	int erased_nodes = 0;
	for (int i = 0; i < NUMBER_OF_RANDOM; i++) {
		int random = rand() % NUMBER_OF_RANDOM;
		std::cout << random << " ";
		// std::cout << "ERASE " << random << std::endl;
		if (balance_test.erase(random) == 1)
			erased_nodes++;
	}
	std::cout << std::endl;

	balance_test.print_tree();
	// for (ft::map<int, int>::iterator it = balance_test.begin(); it != balance_test.end(); it++)
	// 	std::cout << it->first << " " << it->second << std::endl;
	std::cout << "\nNumber of erased nodes = " << erased_nodes << std::endl;

	for (int i = 0; i < 10; i++) {
		int random = rand() % NUMBER_OF_RANDOM;
		balance_test.insert(ft::make_pair(random, random + 2));
	}
	
	balance_test.print_tree();
	// for (ft::map<int, int>::iterator it = balance_test.begin(); it != balance_test.end(); it++)
	// 	std::cout << it->first << " " << it->second << std::endl;

	std::cout << "Nodes added" << std::endl;
	*/

	std::cout << "Exiting main" << std::endl;

	return 0;
}