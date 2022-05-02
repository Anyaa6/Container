/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_tests.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonnel <abonnel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 12:29:39 by abonnel           #+#    #+#             */
/*   Updated: 2022/05/02 15:39:57 by abonnel          ###   ########.fr       */
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
	

	std::cout << simple_map.end()->first << std::endl;
	

	return 0;
}