/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonnel <abonnel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 11:08:39 by                   #+#    #+#             */
/*   Updated: 2022/03/07 17:52:51 by abonnel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

// #include <vector> //A ENLEVER
// #include <iterator> //A ENLEVER
// #include <limits>
// #include "vector.hpp"
// #include "iterator.hpp"
// #include "metafunctions.hpp"

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
	A& operator=(const A& rhs) {
		number = rhs.number;
		size = rhs.size;
		id_instance = rhs.id_instance;
		array = rhs.array; //lhs gets rhs array
		// rhs.array = NULL; //rhs array set to NULL so that it is not deleted
		std::cout << "= overload from : " << id_instance << std::endl;
		return *this;
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

#if 1 //CREATE A REAL STL EXAMPLE
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

int main()
{
	std::cout << TESTING << std::endl;
	//--------------------------------------
	/*
	//PBLM WITH SWAP now that I have reversed constructor and destructor order
	ft::vector<int> swap1_int(2, 5);
	ft::vector<int> swap2_int;
	
	for (int i = 0; i < 6; i++)
		swap2_int.push_back(i);
	print_any_vector(swap2_int, "swap2_int");
	print_any_vector(swap1_int, "swap1_int");

	swap1_int.swap(swap2_int);
	print_any_vector(swap2_int, "swap2_int");
	print_any_vector(swap1_int, "swap1");
	*/
	
	//TEST ON EMPTY CONT
	//TEST WITH EMPTY first -> last
	std::cout << "\nTesting void insert (iterator position, size_type n, const value_type& val); " << std::endl;
	ft::vector<A> to_grow_by_value(7, A(2, 3));
	// for (size_t i = 0; i < to_grow_by_value.size(); i++)
		// to_grow_by_value[i] = i;
	
	to_grow_by_value.reserve(12);
	
	print_any_vector(to_grow_by_value, "to_grow_by_value");
	std::cout << "to_grow_by_value.capacity() : " << to_grow_by_value.capacity() << std::endl;
	std::cout << "inserted elements are 3*7 at position 4" << std::endl;
	
	ft::vector<A>::iterator it_grow_int = ++to_grow_by_value.begin();
	it_grow_int++;
	it_grow_int++;
	it_grow_int++;
	

	std::cout << "\ninsert : " << std::endl;
	to_grow_by_value.insert(it_grow_int, 6, A(3, 4));

	print_any_vector(to_grow_by_value, "to_grow_by_value");
	
	/*
	std::cout << "\nTesting void insert (iterator position, size_type n, const value_type& val); " << std::endl;
	ft::vector<int> to_grow_by_value(6);
	for (size_t i = 0; i < to_grow_by_value.size(); i++)
		to_grow_by_value[i] = i;
	
	to_grow_by_value.reserve(12);
	
	print_any_vector(to_grow_by_value, "to_grow_by_value");
	std::cout << "to_grow_by_value.capacity() : " << to_grow_by_value.capacity() << std::endl;
	std::cout << "inserted elements are 3*7" << std::endl;
	
	ft::vector<int>::iterator it_grow_int = ++to_grow_by_value.begin();
	it_grow_int++;
	it_grow_int++;
	it_grow_int++;
	
	print_any_vector(to_grow_by_value, "to_grow_by_value");

	std::cout << "\ninsert : " << std::endl;
	to_grow_by_value.insert(it_grow_int, 3, 7);

	print_any_vector(to_grow_by_value, "to_grow_by_value");
	*/


/*
		std::cout << "\nTesting void insert (iterator position, size_type n, const value_type& val); " << std::endl;
	//same as void insert (iterator position, InputIterator first, InputIterator last);
	ft::vector<A> to_grow_by_value(6, A(5, 1));
	
	to_grow_by_value.reserve(12);
	
	print_any_vector(to_grow_by_value, "to_grow_by_value");
	std::cout << "to_grow_by_value.capacity() : " << to_grow_by_value.capacity() << std::endl;
	std::cout << "inserted elements are A(8, 2)" << std::endl;
	
	ft::vector<A>::iterator it_grow = ++to_grow_by_value.begin();
	it_grow++;

	std::cout << "\ninsert : " << std::endl;
	to_grow_by_value.insert(it_grow, 3, A(8, 2));

	print_any_vector(to_grow_by_value, "to_grow_by_value");
*/

	//Testing iterator insert (iterator position, const value_type& val);
	// ft::vector<A> insert_single_value(6, A(5, 1));
	// A instance(8,2);
	// 
	// insert_single_value.reserve(12);
	// insert_single_value.push_back(A(3, 2)); //augments capacity to 2 * initial _capacity
	// insert_single_value.pop_back();
	// 
	// print_any_vector(insert_single_value, "insert_single_value");
	// std::cout << "insert_single_value.capacity() : " << insert_single_value.capacity() << std::endl;
	// std::cout << "inserted elements is A(8, 2)" << std::endl;
// 
	// ft::vector<A>::iterator it_grow = ++insert_single_value.begin();
	// it_grow++;
// 
	// std::cout << "\ninsert : " << std::endl;
	// insert_single_value.insert(it_grow,  instance);
// 
	// print_any_vector(insert_single_value, "insert_single_value");









	// ft::vector<A> resize_growth;

	// resize_growth.reserve(9);
	// std::cout << "resize_growth capacity = " << resize_growth.capacity() << std::endl;
	
	// resize_growth.resize(10);
	// std::cout << "resize_growth capacity = " << resize_growth.capacity() << std::endl;
	
	return 0;
}