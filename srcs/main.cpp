/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonnel <abonnel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 11:08:39 by                   #+#    #+#             */
/*   Updated: 2022/02/28 15:53:21 by abonnel          ###   ########.fr       */
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
	};
	~A(){
		std::cout << "Destructor called for number = " << number << " and id_instance = " << id_instance << std::endl;
		if (array)
			delete [] array;
	};
	int operator[](int const &index) const {
		(void)index;
		return id_instance;
	};
};

std::ostream & operator<<(std::ostream &cout, A const &A)
{
	cout << A.id_instance;
	return cout;
}

int A::id = 0;

template <typename T>
void	print_any_vector(T &to_display, std::string vector_name)
{
	std::cout << "\nVector " << vector_name << std::endl;
	for (typename T::size_type i = 0; i < to_display.size(); i++)
		std::cout << to_display[i] << " ";
	std::cout << "\n" << std::endl;
}

int main()
{

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