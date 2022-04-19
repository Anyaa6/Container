/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonnel <abonnel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 11:08:39 by                   #+#    #+#             */
/*   Updated: 2022/04/19 15:39:56 by abonnel          ###   ########.fr       */
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