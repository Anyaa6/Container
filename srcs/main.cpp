/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariane <ariane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 11:08:39 by                   #+#    #+#             */
/*   Updated: 2022/03/11 09:34:08 by ariane           ###   ########.fr       */
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

	//Const and dest in different order
	// ft::vector<A> swap_overload_class(2, A(3, 2));
	ft::vector<A> swap2_overload_class;
	
	// swap2_overload_class.reserve(10);
	
	for (int i = 0; i < 3; i++){
		swap2_overload_class.push_back(A(2, i));
		print_any_vector(swap2_overload_class, "swap2_overload_class");
		std::cout << std::endl;	
	}
	print_any_vector(swap2_overload_class, "swap2_overload_class");
	// print_any_vector(swap_overload_class, "swap_overload_class");

	// swap(swap_overload_class, swap2_overload_class);
	// print_any_vector(swap2_overload_class, "swap2_overload_class");
	// print_any_vector(swap_overload_class, "swap_overload_class");

	//Check ok : triggers same warning as std when using swap on vectors of different types
	//and allocators
	// swap(swap_overload_int, swap2_overload_class);
	// print_any_vector(swap2_overload_class, "swap2_overload_class");
	// print_any_vector(swap_overload_class, "swap_overload_class");
	return 0;
}