/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonnel <abonnel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 11:08:39 by                   #+#    #+#             */
/*   Updated: 2022/03/08 13:50:30 by abonnel          ###   ########.fr       */
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
	friend bool operator== (const A& lhs, const A& rhs) {
		if (lhs.size != rhs.size || lhs.number != rhs.number)
			return (false);
		return (true);
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
	std::cout << "Testing == operator" << std::endl;
	ft::vector<A>  lhs(12, A(12, 5));
	ft::vector<A>  rhs(12, A(3, 5));
	ft::vector<A>  rhs_other(lhs);

	ft::vector<int>  lhs_int(12, 7);
	for (size_t i = 0; i < lhs_int.size(); i++)
		lhs_int[i] = i + 2;
	ft::vector<int>  lhs_copy(lhs_int);
	lhs_int[2] = 16;
	ft::vector<int>  rhs_int(12, 4);
	ft::vector<int>  rhs_other_int(lhs_int);



	// std::cout << "\nVector lhs" << std::endl;
	// for (size_t i = 0; i < lhs.size(); i++)
		// std::cout << "for [" << i << "], size = " << lhs[i].size << " number = " << lhs[i].number << std::endl;
	// std::cout << "\n" << std::endl;
// 
	// std::cout << "\nVector rhs_other" << std::endl;
	// for (size_t i = 0; i < rhs_other.size(); i++)
		// std::cout << "for [" << i << "], size = " << rhs_other[i].size << " number = " << rhs_other[i].number << std::endl;
	// std::cout << "\n" << std::endl;
	
	std::cout << std::boolalpha << "\n\nlhs == rhs = " << (lhs == rhs) << "\nlhs == rhs_other = " << (lhs == rhs_other) << "\n\n" << std::endl;
	std::cout << std::boolalpha << "\n\nlhs_int == rhs_int = " << (lhs_int == rhs_int) << "\nlhs_int == rhs_other_int = " << (lhs_int == rhs_other_int) << " lhs_int == lhs_copy = " << (lhs_int == lhs_copy) << "\n\n" << std::endl;

	/*
	ft::vector<A> resize_growth(3, A(12, 5));
	print_any_vector(resize_growth, "resize_growth");
	// resize_growth.reserve(9);
	// std::cout << "resize_growth capacity = " << resize_growth.capacity() << std::endl;
	std::cout << "\nBefore resize : " << std::endl;
	resize_growth.resize(10, A(3, 0));
	std::cout << "resize_growth capacity = " << resize_growth.capacity() << std::endl;

	std::cout << "\nAfter resize : " << std::endl;
	print_any_vector(resize_growth, "resize_growth");
	*/
	







	/*
	//PBLM WITH SWAP now that I have reversed constructor and destructor order
	//dest et const are not in right order
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
	return 0;
}