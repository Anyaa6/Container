/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonnel <abonnel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 11:08:39 by                   #+#    #+#             */
/*   Updated: 2022/03/25 14:08:14 by abonnel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#if 0//CREATE A REAL STL EXAMPLE
	#define TESTING "Testing with std library"
	#include <limits>
	#include <iterator>
	#include <vector>
	#include <stack>
	namespace ft = std;
#else
	#define TESTING "Testing with ft library"
	#include "metafunctions.hpp"
	#include "iterator.hpp"
	#include "vector.hpp"
	#include "stack.hpp"
#endif
#include "tester_class.hpp"

int main()
{
	std::cout << TESTING << std::endl;
	//--------------------------------------

	/* TESTING TOP AND BACK BC ISSUE
	ft::vector<A> 	empty_vec_const;

	std::cout << "empty vec size = " << empty_vec_const.size() << " empty_vec_const.capacity() = " << empty_vec_const.capacity() << std::endl;

	std::cout << "empty_vec_const[2] = " << empty_vec_const[2] << std::endl;

	std::cout << "empty_vec_const.back() = " << empty_vec_const.back() << std::endl;

	ft::vector<A>		vec_for_stack(4, A(12, 5));
	ft::vector<A>	empty_vec;
	ft::stack<A, ft::vector<A> >   empty_stack(empty_vec);
	ft::stack<A, ft::vector<A> >   stack_from_vec(vec_for_stack);

	std::cout << std::boolalpha;
	std::cout << "empty stack is empty = " << empty_stack.empty() << std::endl;
	std::cout << "stack_from_vec stack is empty " << stack_from_vec.empty() << std::endl;
	std::cout << std::endl;

	std::cout << "empty stack size = " << empty_stack.size() << std::endl;
	std::cout << "stack_from_vec stack size " << stack_from_vec.size() << std::endl;
	std::cout << std::endl;

	std::cout << "stack_from_vec stack top " << stack_from_vec.top() << std::endl;
	std::cout << "vec_for_stack stack back " << vec_for_stack.back() << std::endl;
	std::cout << std::endl;
	
	std::cout << "Testing stack top" << std::endl;
	std::cout << "empty stack top = " << empty_stack.top() << std::endl;
	std::cout << "empty_vec back = " << empty_vec.back() << std::endl;
	std::cout << std::endl;

	*/
	return 0;
}