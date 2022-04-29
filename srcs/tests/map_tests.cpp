/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_tests.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariane <ariane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 12:29:39 by abonnel           #+#    #+#             */
/*   Updated: 2022/04/29 15:38:08 by ariane           ###   ########.fr       */
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
	
	std::cout << "begin key = " << it_start->first << " value =  "<< it_start->second << std::endl;
	std::cout << "adreses = " << &it_start << std::endl;
	
	for (int i = 0; i < 3; i++)
		simple_map.insert(std::make_pair(i, i + 2));

	simple_map.clear();

	it_start = simple_map.begin();
	std::cout << "after clear\nbegin key = " << it_start->first << " value =  "<< it_start->second << std::endl;
	std::cout << "adreses = " << &it_start << std::endl;

	return 0;
}