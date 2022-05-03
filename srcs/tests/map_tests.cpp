/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_tests.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonnel <abonnel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 12:29:39 by abonnel           #+#    #+#             */
/*   Updated: 2022/05/03 10:57:10 by abonnel          ###   ########.fr       */
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
#include "tester_class.hpp"


int main()
{
	std::map<int, int>		simple_map;

	// std::map<int, int>::iterator		it_start = simple_map.begin();
	
	for (int i = 0; i < 12; i++)
		simple_map.insert( std::make_pair(i, i-2));
	// std::cout << simple_map.end()->first << std::endl;
	
	
	std::map<int, int>::iterator		it_simple_map = begin();
	for (int i = 0; i < 4; i++)
		it_simple_map++;

	simple_map.insert(it_simple_map, std::make_pair(12, 12));

	return 0;
}