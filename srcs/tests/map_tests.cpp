/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_tests.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonnel <abonnel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 12:29:39 by abonnel           #+#    #+#             */
/*   Updated: 2022/04/27 17:01:12 by abonnel          ###   ########.fr       */
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

	std::map<int, int>::iterator		it_start = simple_map.begin();
	
	
	for (int i = 0; i < 22; i++)
		simple_map.insert(std::make_pair(i, i + 2));

	std::map<int, int>::iterator		it_simple_map = simple_map.end();
	
	for (; it_simple_map != simple_map.begin(); it_simple_map--)
		std::cout << "begin key = " << it_simple_map->first << " value =  "<< it_simple_map->second << std::endl;

	std::cout << "Incrementing before begin" << std::endl;
	// it_simple_map--;
	// std::cout << "begin key = " << it_simple_map->first << " value =  "<< it_simple_map->second << std::endl;
	// it_simple_map->
	// std::map<int, int>::iterator::pointer 	lol;
	// std::map<int, int>::iterator::value_type 	lol;
	// lol = *it_simple_map;

	return 0;
}