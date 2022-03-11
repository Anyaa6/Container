/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariane <ariane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 11:08:39 by                   #+#    #+#             */
/*   Updated: 2022/03/11 12:07:36 by ariane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#if 1//CREATE A REAL STL EXAMPLE
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
	ft::stack<A, ft::vector<A> >  lhs(ft::vector<A>(12, A(12, 5)));
	ft::stack<A, ft::vector<A> >  rhs(ft::vector<A>(12, A(3, 5)));
	ft::stack<A, ft::vector<A> >  rhs_other(lhs);

	ft::stack<int, ft::vector<int> >  lhs_int(ft::vector<int>(12, 7));
	// for (size_t i = 0; i < lhs_int.size(); i++)
		// lhs_int[i] = i + 2;
	ft::stack<int, ft::vector<int> >  lhs_copy(ft::vector<int>(12, 7));
	// lhs_int[2] = 16;
	ft::stack<int, ft::vector<int> >  rhs_int(ft::vector<int>(12, 4));
	ft::stack<int, ft::vector<int> >  rhs_other_int(ft::vector<int>(12, 7));
	
	std::cout << std::boolalpha << "\n\nlhs_int == rhs_int = " << (lhs_int == rhs_int) << "\nlhs_int == rhs_other_int = " << (lhs_int == rhs_other_int) << " lhs_int == lhs_copy = " << (lhs_int == lhs_copy) << "\n\n" << std::endl;

	std::cout << "lhsint < rhs_int" << (lhs_int < rhs_int) << std::endl;
	std::cout << "lhsint != rhs_int" << (lhs_int != rhs_int) << std::endl;
	std::cout << "lhsint <= rhs_int" << (lhs_int <= rhs_int) << std::endl;
	std::cout << "lhsint >= rhs_int" << (lhs_int >= rhs_int) << std::endl;
	std::cout << "lhsint > rhs_int" << (lhs_int > rhs_int) << std::endl;
	
	std::cout << "lhs_int != lhs_copy" << (lhs_int != lhs_copy) << std::endl;
	std::cout << "lhs_int == lhs_copy" << (lhs_int == lhs_copy) << std::endl;
	std::cout << "lhs_int < lhs_copy" << (lhs_int < lhs_copy) << std::endl;
	std::cout << "lhs_int >= lhs_copy" << (lhs_int >= lhs_copy) << std::endl;
	std::cout << "lhs_int > lhs_copy" << (lhs_int > lhs_copy) << std::endl;
	std::cout << "lhs_int <= lhs_copy" << (lhs_int <= lhs_copy) << std::endl;

	std::cout << "lhs != rhs_other" << (lhs != rhs_other) << std::endl;
	std::cout << "lhs == rhs_other" << (lhs == rhs_other) << std::endl;
	std::cout << "lhs < rhs_other" << (lhs < rhs_other) << std::endl;
	std::cout << "lhs >= rhs_other" << (lhs >= rhs_other) << std::endl;
	std::cout << "lhs > rhs_other" << (lhs > rhs_other) << std::endl;
	std::cout << "lhs <= rhs_other" << (lhs <= rhs_other) << std::endl;
/*	
	ft::stack<A, ft::vector<A> > 	stack_push_pop(ft::vector<A>(3, A(12, 4)));

	//NEED TO FIX VECTOR PUSH BACK FOR IT TO WORK
	std::cout << "stack_push_pop.top() = " << stack_push_pop.top() << std::endl;
	std::cout << "stack_push_pop.push(A(2, 10))" << std::endl;
	std::cout << "stack_push_pop size = " << stack_push_pop.size() << std::endl;
	stack_push_pop.push(A(2, 10));
	std::cout << "stack_push_pop.top() = " << stack_push_pop.top() << std::endl;
	std::cout << "stack_push_pop.pop() x 2" << std::endl;
	stack_push_pop.pop();
	stack_push_pop.pop();
	std::cout << "stack_push_pop.top() = " << stack_push_pop.top() << std::endl;
	*/



	
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