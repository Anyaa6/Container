/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonnel <abonnel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 11:08:39 by                   #+#    #+#             */
/*   Updated: 2022/05/16 16:57:40 by abonnel          ###   ########.fr       */
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

int main()
{
	std::cout << TESTING << std::endl;
	//--------------------------------------
	//tester les retours de insert avec et sans balancing pour voir si current modifié
	//utiliser random pour add randomnumbers 

	srand (time(NULL));
	ft::map<int, int>		balance_test;

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
	
	//left side
	balance_test.insert(ft::make_pair(-3, 4+2));
	balance_test.insert(ft::make_pair(-4, 4+2));
	balance_test.insert(ft::make_pair(-8, 4+2));
	*/

	for (int i = 0; i < 4000; i++) {
		int random = rand() % 4000;
		balance_test.insert(ft::make_pair(random, random + 2));
	}
	// balance_test.print_tree();

	for (ft::map<int, int>::iterator it = balance_test.begin(); it != balance_test.end(); it++)
		std::cout << it->first << " " << it->second << std::endl;
	
	return 0;
}