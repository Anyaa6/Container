/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonnel <abonnel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 11:08:39 by                   #+#    #+#             */
/*   Updated: 2022/05/31 10:47:23 by abonnel          ###   ########.fr       */
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
#define NUMBER_OF_RANDOM 200

int main()
{
	std::cout << TESTING << std::endl;
	//--------------------------------------
	//WRITE TESTS WITH FT here 

	ft::vector<int>		vec(5, 2);
	ft::vector<int>::iterator it = vec.begin();
	ft::vector<int>::const_iterator it_const = vec.begin();

	for (; it_const != vec.end(); it_const++)
		std::cout << *it << std::endl;
	it_const = vec.begin();
	if (it == it_const)
		std::cout << "iterator are same" << std::endl;



	
	return 0;
}