/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_tests.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariane <ariane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 12:29:39 by abonnel           #+#    #+#             */
/*   Updated: 2022/05/25 14:11:57 by ariane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <limits>
#include <iterator>
#include <vector>
#include <stack>
#include <map>
#include <utility>
// namespace ft = std;
#include "../utils/metafunctions.hpp"
#include "../iterators/iterator.hpp"
#include "../containers/vector.hpp"
#include "../containers/stack.hpp"
#include "../containers/map.hpp"
#include "../utils/pair.hpp"
#include <string>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#define NUMBER_OF_RANDOM 150

int main()
{
	srand (time(NULL));
	ft::map<int, int>		balance_test;
	
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

	std::cout << "Exiting main" << std::endl;

	return 0;
}