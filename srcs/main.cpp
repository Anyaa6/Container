/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonnel <abonnel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 11:08:39 by                   #+#    #+#             */
/*   Updated: 2022/02/25 16:38:17 by abonnel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"
#include <iostream>

#include <vector> //A ENLEVER
#include <iterator> //A ENLEVER
#include <limits>
#include "iterator.hpp"
#include "metafunctions.hpp"

class A{
	public :
	static int id;
	int		number;
	int		id_instance;
	int 	size;
	int		*array;
	A(int num, int size) : number(num), size(size), array(NULL) {
		id_instance = id;
		std::cout << "Constructor called for id_instance = " << id_instance << std::endl;
		array = new int[12];
		id++;
		// for (int i = 0; i < 12; i++)
			// array[i] = i;
	};
	A(A const &rhs){ //with proper copy constructor they do have their own memory -> deep copy
		number = rhs.number;
		size = rhs.size;
		id_instance = this->id;
		array = new int[12];
		id++;	
		std::cout << "COPY Constructor called for id_instance = " << id_instance << " from id_instance = " << rhs.id_instance << std::endl;
		// for (int i = 0; i < 12; i++)
		// 	array[i] = rhs.array[i];
	};
	A() {
		std::cout << "DEFAULT constructor" << std::endl;
	}
	~A(){
		std::cout << "Destructor called for number = " << number << " and id_instance = " << id_instance << std::endl;
		if (array)
			delete [] array;
	};	
};

int A::id = 0;

int main()
{
	//assign (size_type n, const value_type& val) does not act the same in std and ft when using vector of class A
	//probably due to line 266 of vector.hpp --> this->clear
	std::vector<A> assignclasses(4, A(1, 2));

	std::cout << "\n\n" << std::endl;
	assignclasses.assign(4, A(3, 5));
	std::cout << "\n\n" << std::endl;

	/*
	//TEST ASSIGN WITH vector<A>
	//Shows that this is NOT true : Any elements held in the container before the call are destroyed and replaced by newly constructed elements (no assignments of elements take place).
	//if we put debug messages in the constructors AND destructors of A with an id number
	//we can show that std assign does NOT construct new elements, it only makes it point to the elements
	//that inputiterators point to
	ft::vector<A> assignclasses(2, A(1, 2));

	std::cout << "assignclasses = " << std::endl;
	for (size_t i = 0; i < assignclasses.size(); i++)
		std::cout << assignclasses[i].number << "(id_instance = " << assignclasses[i].id_instance << ")" << " ";
	std::cout << std::endl;

	ft::vector<A> nextvector(5, A(3, 2));
	std::cout << "nextvector = " << std::endl;
	for (size_t i = 0; i < nextvector.size(); i++)
		std::cout << nextvector[i].number << "(id_instance = " << nextvector[i].id_instance << ")" << " ";
	std::cout << std::endl;

	std::cout << "\n\nTesting metafunctions : \n";
	std::cout << std::boolalpha << "ft::is_same<ft::vector<A>::reverse_iterator, ft::reverse_iterator<ft::vector<A>::iterator> >::value = " << ft::is_same<ft::vector<A>::reverse_iterator, ft::reverse_iterator<ft::vector<A>::iterator> >::value << std::endl;

	std::cout << "\n\nAssign\n";
	nextvector.assign(assignclasses.begin(), assignclasses.end());
	std::cout << "nextvector after assign with smaller vector = " << std::endl;
	for (size_t i = 0; i < nextvector.size(); i++)
		std::cout << nextvector[i].number << "(id_instance = " << nextvector[i].id_instance << ")" << " ";
	std::cout << std::endl;

	std::cout << "nextvector size = " << nextvector.size() << " and capacity = " << nextvector.capacity() << std::endl;
	std::cout << "Before the end of the program" << std::endl;
	*/
	/*
	//TEST ASSIGN FUNCTION
	ft::vector<int> verifyassign;
	
	// verifyassign.push_back(14);
	std::cout << "Before assign size = " << verifyassign.size() << " capacity = " << verifyassign.capacity() << std::endl;
	verifyassign.assign(4, 6);
	for (size_t i = 0; i < verifyassign.size(); i++)
		std::cout << verifyassign[i] << " ";
	std::cout << std::endl;
	std::cout << "size = " << verifyassign.size() << " capacity = " << verifyassign.capacity() << std::endl;
	verifyassign.assign(12, 2);
	std::cout << "size = " << verifyassign.size() << " capacity = " << verifyassign.capacity() << std::endl;
	verifyassign.assign(3, 7);
	std::cout << "size = " << verifyassign.size() << " capacity = " << verifyassign.capacity() << std::endl;
	verifyassign.push_back(12);
	for (size_t i = 0; i < verifyassign.size(); i++)
		std::cout << verifyassign[i] << " ";
	std::cout << std::endl;
	
	ft::vector<int> cpyassign;
	cpyassign.push_back(14);
	cpyassign.push_back(14);
	cpyassign.push_back(14);
	cpyassign.push_back(14);
	cpyassign.push_back(14);
	cpyassign.push_back(14);
	std::cout << "cpyassign before being assigned from another shorter vector" << std::endl;
	for (size_t i = 0; i < cpyassign.size(); i++)
		std::cout << cpyassign[i] << " ";
	
	cpyassign.assign<ft::vector<int>::iterator>(verifyassign.begin(), verifyassign.end());
	std::cout << "after assign from another vector" << std::endl;
	for (size_t i = 0; i < cpyassign.size() + 2; i++)
		std::cout << cpyassign[i] << " ";
	std::cout << std::endl;
	*/

	// cpyassign.push_back(14);
	// cpyassign.push_back(71);
	// std::cout << "after push back 14 and 71" << std::endl;
	// for (size_t i = 0; i < cpyassign.size(); i++)
		// std::cout << cpyassign[i] << " ";
	// std::cout << std::endl;

	// cpyassign.assign<ft::vector<int>::reverse_iterator>(cpyassign.rbegin(), cpyassign.rend());
	// for (size_t i = 0; i < cpyassign.size(); i++)
		// std::cout << cpyassign[i] << " ";
	// std::cout << std::endl;

	/*
	//TESTING RESIZE
	ft::vector<int> resize_test(3, 42);

	std::cout << "size = " << resize_test.size() << " capacity = " << resize_test.capacity() << std::endl;
	resize_test.resize(12);
	for (size_t i = 0; i < resize_test.size(); i++)
		std::cout << resize_test[i] << " ";
	std::cout << std::endl;
	std::cout << "size = " << resize_test.size() << " capacity = " << resize_test.capacity() << std::endl;
	resize_test.push_back(12);
	std::cout << "size = " << resize_test.size() << " capacity = " << resize_test.capacity() << std::endl;
	resize_test.resize(13);
	for (size_t i = 0; i < resize_test.size(); i++)
		std::cout << resize_test[i] << " ";
	std::cout << std::endl;
	
	std::cout << "size = " << resize_test.size() << " capacity = " << resize_test.capacity() << std::endl;
	resize_test.resize(2);
	for (size_t i = 0; i < resize_test.size(); i++)
		std::cout << resize_test[i] << " ";
	std::cout << std::endl;
	std::cout << "size = " << resize_test.size() << " capacity = " << resize_test.capacity() << std::endl;
	*/
	
	/*
	STD TESTS to compare destruction of objects
	free error bc instance_of_a is destructed before the ones in classvec and they point to
	the same memory area --> not a deep copy of instance of a they all point to the same array
	A		instance_of_a(12, 32);
	A 		cpy_inst_a = instance_of_a;
	ft::vector<A> classvec(5, instance_of_a);
	classvec[3].array[0] = 1500;
	classvec[4].array[1] = 1500;
	// 
	for (int i = 0; i < 12; i++)
		std::cout << classvec[4].array[i] << " ";
	std::cout << std::endl;
	for (int i = 0; i < 12; i++)
		std::cout << instance_of_a.array[i] << " ";
	std::cout << std::endl;
// 
	classvec.push_back(instance_of_a);
	std::cout << "class vec capacity = " << classvec.capacity() << std::endl;
	classvec.push_back(instance_of_a);
	std::cout << "class vec capacity = " << classvec.capacity() << std::endl;
	classvec.push_back(instance_of_a);
	std::cout << "class vec capacity = " << classvec.capacity() << std::endl;
	// 
	std::cout << classvec[2].size << std::endl;
	*/

	return 0;
}