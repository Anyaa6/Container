/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariane <ariane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 11:08:39 by                   #+#    #+#             */
/*   Updated: 2022/03/11 10:17:07 by ariane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#if 0 //CREATE A REAL STL EXAMPLE
	#define TESTING "Testing with std library"
	#include <limits>
	#include <iterator>
	#include <vector>
	namespace ft = std;
#else
	#define TESTING "Testing with ft library"
	#include "metafunctions.hpp"
	#include "iterator.hpp"
	#include "vector.hpp"
#endif
#include "tester_class.hpp"

int main()
{
	std::cout << TESTING << std::endl;
	//--------------------------------------


	return 0;
}