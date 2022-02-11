/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonnel <abonnel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 11:08:39 by                   #+#    #+#             */
/*   Updated: 2022/02/11 11:37:53 by abonnel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"
#include <iostream>

#include <vector> //A ENLEVER
#include <iterator> //A ENLEVER
#include "iterator.hpp"

class A{
	public :
	int		number;
	int 	size;
	int		*array;
	A(int num, int size) : number(num), size(size), array(NULL) {
		array = new int[12];
		// for (int i = 0; i < 12; i++)
			// array[i] = i;
		// std::cout << "ICI" << std::endl;
	};
	A(A const &rhs){ //with proper copy constructor they do have their own memory -> deep copy
		array = new int[12];	
		(void)rhs;
		// for (int i = 0; i < 12; i++)
		// 	array[i] = rhs.array[i];
		// std::cout << "COPY CONSTRUCTOR OF CLASS A" << std::endl;
	};
	A() {
		// std::cout << "LA" << std::endl;
	}
	~A(){
		// std::cout << "Destructor called" << std::endl;
		if (array)
			delete [] array;
	};	
};

int main()
{
	std::vector<int> capacitytest(3, 42);

	std::cout << "capacitytest _capacity = " << capacitytest.capacity() << std::endl;
	capacitytest.push_back(32);
	capacitytest.push_back(32);
	capacitytest.push_back(32);
	capacitytest.push_back(32);
	std::cout << "capacitytest _capacity = " << capacitytest.capacity() << std::endl;
	capacitytest.reserve(10);
	std::cout << "capacitytest _capacity = " << capacitytest.capacity() << std::endl;
	capacitytest.reserve(20);
	std::cout << "capacitytest _capacity = " << capacitytest.capacity() << std::endl;
	capacitytest.reserve(21);
	std::cout << "capacitytest _capacity = " << capacitytest.capacity() << std::endl;
	std::cout << "capacitytest size = " << capacitytest.size() << std::endl;
	capacitytest.reserve(169);
	std::cout << "capacitytest _capacity = " << capacitytest.capacity() << std::endl;
	/*
	//CHECKING push et pop with zero capacity
	ft::vector<A> zerocapacity;

	zerocapacity.pop_back();
	std::cout << "At beginning ---- size = " << zerocapacity.size() << " capacity = " << zerocapacity.capacity() << std::endl;
	zerocapacity.push_back(A(12, 5));
	std::cout << "After one pushback ---- size = " << zerocapacity.size() << " capacity = " << zerocapacity.capacity() << std::endl;
	zerocapacity.push_back(A(12, 5));
	std::cout << "After 2 pushback ---- size = " << zerocapacity.size() << " capacity = " << zerocapacity.capacity() << std::endl;
	zerocapacity.push_back(A(12, 5));
	zerocapacity.push_back(A(12, 5));
	zerocapacity.push_back(A(12, 5));
	std::cout << "After multiple pushback ---- size = " << zerocapacity.size() << " capacity = " << zerocapacity.capacity() << std::endl;
	*/

	/*
	STD TESTS to compare destruction of objects
	free error bc instance_of_a is destructed before the ones in classvec and they point to
	the same memory area --> not a deep copy of instance of a they all point to the same array
	A		instance_of_a(12, 32);
	A 		cpy_inst_a = instance_of_a;
	std::vector<A> classvec(5, instance_of_a);
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

	/*
	//CHECKS how capacity and size grows with push_backs 
	// A		instance_of_a(12, 32);
	ft::vector<A> ftdouble(2, instance_of_a);
	//tester double_alloc function  -> comment capacity et size evolue et si pas de leaks --> changé destroy pr qu'il destroy chaque element
	//tester avec capacity de 0

	std::cout << "Beginning ---- size = " << ftdouble.size() << " capacity = " << ftdouble.capacity() << std::endl;
	ftdouble.push_back(instance_of_a);
	std::cout << "After push_back ---- size = " << ftdouble.size() << " capacity = " << ftdouble.capacity() << std::endl;
	ftdouble.push_back(instance_of_a);
	ftdouble.push_back(instance_of_a);
	std::cout << "After 2 push_back ---- size = " << ftdouble.size() << " capacity = " << ftdouble.capacity() << std::endl;
	ftdouble.push_back(instance_of_a);
	ftdouble.push_back(instance_of_a);
	ftdouble.push_back(instance_of_a);
	ftdouble.push_back(instance_of_a);
	// std::cout << "size = " << ftdouble.size() << " capacity = " << ftdouble.capacity() << std::endl;

	*/

	/*
	//test to determine how capacity grows with reserve function
	std::vector<int> capacitytest(3, 42);

	std::cout << "capacitytest _capacity = " << capacitytest.capacity() << std::endl;
	capacitytest.push_back(32);
	capacitytest.push_back(32);
	capacitytest.push_back(32);
	capacitytest.push_back(32);
	std::cout << "capacitytest _capacity = " << capacitytest.capacity() << std::endl;
	capacitytest.reserve(10);
	std::cout << "capacitytest _capacity = " << capacitytest.capacity() << std::endl;
	capacitytest.reserve(20);
	std::cout << "capacitytest _capacity = " << capacitytest.capacity() << std::endl;
	capacitytest.reserve(21);
	std::cout << "capacitytest _capacity = " << capacitytest.capacity() << std::endl;
	std::cout << "capacitytest size = " << capacitytest.size() << std::endl;
	capacitytest.reserve(169);
	std::cout << "capacitytest _capacity = " << capacitytest.capacity() << std::endl;
	*/
	
	/*
	//Test operator ->
	ft::vector<A> vclass(5, 42);
	ft::vector<A>::iterator itvclass = vclass.begin();
	
	for (; itvclass < vclass.end(); itvclass++)
		itvclass->number = 12;
	for (itvclass = vclass.begin(); itvclass < vclass.end(); itvclass++)
		std::cout << itvclass->number << std ::endl;
	*/

/*
	//CHECKING CAPACITY and SIZE growth
    // std::vector<int> v(5, 0);
	// for (int i = 0; i < 5; i++)
		// v[i] = i;
//  
	// v.push_back(12);
	// v.push_back(42);
	// 
	// std::vector<int> copy(v);
	// for (int i = 0; i < 5; i++)
		// std::cout << copy[i] << std::endl;
	// 
	// std::cout << "size of v = " << v.size() << " and size of copy = " << copy.size() << std::endl;
	// std::cout << "capacity of v = " << v.capacity() << " and capacity of copy = " << copy.capacity() << std::endl;

	
	ft::vector<int> v(5, 0);
	for (int i = 0; i < 5; i++)
		v[i] = i;
 
	// v.push_back(12);
	// v.push_back(42);
	
	ft::vector<int> copy = v;
	for (int i = 0; i < 5; i++)
		std::cout << copy[i] << std::endl;
	
	std::cout << "size of v = " << v.size() << " and size of copy = " << copy.size() << std::endl;
	std::cout << "capacity of v = " << v.capacity() << " and capacity of copy = " << copy.capacity() << std::endl;
*/
	

	/*
	//Test reverse iterators
    ft::vector<int> v(5, 0);
	for (int i = 0; i < 5; i++)
		v[i] = i;
 
	ft::vector<int> copy(v);
	for (int i = 0; i < 5; i++)
		std::cout << copy[i] << std::endl;
	
	typedef ft::reverse_iterator<ft::vector<int>::iterator> RevIt;
    ft::vector<int>::iterator it = v.begin() + 3;
    RevIt r_it(it);
 
    std::cout << "*it == " << *it << '\n'
			//   << "*itstd == " << *itstd << '\n'
              << "*r_it == " << *r_it << '\n'
              << "*r_it.base() == " << *r_it.base() << '\n'
              << "*(r_it.base()-1) == " << *(r_it.base() - 1) << '\n';
 
    RevIt r_end(v.begin());
    RevIt r_begin(v.end());

	RevIt newrev = r_end - 2;
	std::cout << "rev_end + 2 = " << *newrev << std::endl;
	std::cout << "++newrev = " << *++newrev << std::endl;
	std::cout << "--newrev = " << *--newrev << std::endl;
	std::cout << "newrev-- = " << *newrev-- << std::endl;
	std::cout << "newrev = " << *newrev << std::endl;

	std::cout << "r_begin[2] = " << r_begin[2] << std::endl;

	r_begin += 2;	
	std::cout << "r_begin += 2 = " << *r_begin << std::endl;
	
	r_begin -= 2;	
	std::cout << "r_begin -= 2 = " << *r_begin << std::endl;

	std::cout << "r_end - r_begin = " << r_end - r_begin << std::endl;

	RevIt added = 1 + r_begin;
	std::cout << "1 + r_begin = " << *added << std::endl;
	
	//Testing relationnal operators of reverse iterators
	std::cout << std::boolalpha << (r_end == r_end) << std::endl;
	std::cout << (r_end != r_end) << std::endl;
	std::cout << (r_end != r_begin) << std::endl;
	std::cout << (r_end < r_begin) << std::endl;
	std::cout << (r_end > r_begin) << std::noboolalpha << std::endl;

	RevIt 	ending = v.rend();
	RevIt 	beginning = v.rbegin();

	for (;beginning != ending; beginning++)
		std::cout << *beginning << std::endl;
*/
	
	/*
	//Testing random_access_iterators
	ft::vector<int>	hehe(4, 12);

	ft::vector<int>::iterator it = hehe.begin();
	ft::vector<int>::iterator it2 = hehe.begin();
	ft::vector<int>::iterator it3 = ++hehe.begin();
	ft::vector<int>::iterator it4 = hehe.begin()++;
	
	std::cout << "The different iterators are equal to :\nit == it2\nit3 = ++begin()\nit4 = begin()++\n" << std::endl;
	std::cout << std::boolalpha << "(it == it2) :" << (it == it2) << std::endl;
	std::cout << "(it != it2) :" << (it != it2) << std::endl;
	std::cout << "(it <= it2) :"<< (it <= it2) << std::endl;
	std::cout << "(it >= it2) :" << (it >= it2) << std::endl;
	std::cout << "it < it2 :" << (it < it2) << std::endl;
	std::cout << "it < it3 :" << (it < it3) << std::endl;
	std::cout << "(it > it2) :" << (it > it2) << std::endl;
	std::cout << std::noboolalpha << std::endl; //stop printing as bool
	std::cout << "Printing values with index []: " << std::endl;
	for (size_t i = 0; i < hehe.size(); i++)
		std::cout << "it[" << i << "] = " << it[i] << std::endl;

	std::cout << "changing second value to 52 from iterator *it3 = 52" << std::endl;
	*it3 = 52;	
	std::cout << "Printing values with iterators *it : " << std::endl;
	for (ft::vector<int>::iterator it = hehe.begin(); it < hehe.end(); it++)
		std::cout << "it = " << *it << std::endl;

	std::cout << "Printing values with iterators *it from the end : " << std::endl;
	for (ft::vector<int>::iterator it = --hehe.end(); it >= hehe.begin(); --it)
		std::cout << "it = " << *it << std::endl;

	ft::vector<int>::iterator fifty_two = it + 1;
	std::cout << "it + 1 = " << *fifty_two << std::endl;
	std::cout << "it + 1 + 1 = " << *(fifty_two -= 1) << std::endl;
	
	ft::vector<int>::iterator itbegin = hehe.begin();
	ft::vector<int>::iterator itoffset = 1 + itbegin; //hehe.begin();
	
	std::cout << "itoffset = 1 + hehe.begin() = " << *itoffset << std::endl;
	
	ft::vector<int>::iterator::difference_type diff_btw_ptr = itoffset - itbegin; //hehe.begin();
	std::cout << "diff between itoffset - begin() = " << diff_btw_ptr << std::endl;

	ft::vector<int>::random_access_iterator itft = hehe.begin();
	std::vector<int>::iterator itstd;
	std::cout << "itft = " << *itft << std::endl;
	// ft::iterator_traits<ft::iterator<std::random_access_iterator_tag, int> > haha;
	//END of Testing random_access_iterators

	// Basic tests, creating vector etc
	ft::vector<int>	haha(4, 12);
	haha[2] = 66;
	haha[3] = 226;
	ft::vector<int> hoho(haha); //par copy
	
	ft::vector<int>::iterator	last = haha.end();
	
	std::cout << "last - 1 : " << *(last--) << std::endl;
	std::cout << "haha size " << haha.size() << " haha capacity : " << haha.capacity() << std::endl;
	std::cout << "hoho size " << hoho.size() << " hoho capacity : " << hoho.capacity() << std::endl;
	for (size_t i = 0; i < haha.size(); i++)
	{
		std::cout << "haha["<< i << "] " << haha[i] << std::endl;
		std::cout << "hoho["<< i << "] " << hoho[i] << std::endl;

	}
*/

/*
	std::vector<int> value_test(12,42);
	ft::vector<int> ft_value_test(12,42);

	std::cout << "index_test begin " << *(++value_test.begin()) << std::endl;
	std::cout << "index_test begin " << *(++ft_value_test.begin()) << std::endl;
*/

	//testing begin, front, end, back
	// std::vector<int> index_test;
	// ft::vector<int> ft_index_test;
	// std::vector<int> value_test(12,42);
	// ft::vector<int> ft_value_test(12,42);

/*
	//Testing front on empty container
	// std::cout << index_test.front() << std::endl;
	// std::cout << ft_index_test.front() << std::endl;
	
	//Testing front on NON empty container
	// std::cout << value_test.front() << std::endl;
	// std::cout << ft_value_test.front() << std::endl;

	//Testing back on empty container
	// std::cout << index_test.back() << std::endl;
	// std::cout << ft_index_test.back() << std::endl;
	
	//Testing back on NON empty container
	// std::cout << value_test.back() << std::endl;
	// std::cout << ft_value_test.back() << std::endl;
*/
/*
	std::cout << "Testing begin front end back" << std::endl;
	// std::cout << "index_test begin " << ft_index_test.begin() << std::endl;
	// std::cout << "index_test begin " << *(index_test.end() - 1) << std::endl;
	std::vector<int>::iterator first = value_test.begin();
	value_test[1] = 12;
	std::cout << "index_test begin " << *first << std::endl;
	std::cout << "index_test begin " << *(++value_test.begin()) << std::endl;
	first++;
	std::cout << "index_test begin " << *first << std::endl;

	std::cout << "ft:: " << std::endl;
	ft::vector<int>::iterator ft_first = ft_value_test.begin();
	ft_value_test[1] = 12;
	std::cout << "index_test begin " << *ft_first << std::endl;
	// std::cout << "index_test begin " << *(++ft_value_test.begin()) << std::endl;
	ft_first++;
	std::cout << "index_test begin " << *ft_first << std::endl;
*/
	/*
	//testing [] operator
	std::vector<int> index(3, 5);

	std::cout << haha.at(2) << std::endl; //works
	// std::cout << haha.at(4) << std::endl; //throw exception bc out of range
	// std::cout << index.at(524534456) << std::endl; //throw exception bc out of range
	// std::cout << index[524534456] << std::endl; //should segfault or return random value
	*/

	/*
	std::vector<int> real_stuff(5,12);
	std::vector<int> cp_real_stuff(real_stuff);
	

	std::cout << "first" << std::endl;
	std::cout << real_stuff.size() << std::endl;
	std::cout << real_stuff.capacity() << std::endl;
	std::cout << cp_real_stuff.size() << std::endl;
	std::cout << cp_real_stuff.capacity() << std::endl;

	std::cout << "Push backs" << std::endl;
	for (int i = 0; i < 16 ; i++)
	{
		real_stuff.push_back(42);
		std::cout << "size : " << real_stuff.size() << std::endl;
		std::cout << "capacity : " << real_stuff.capacity() << std::endl;
	}

	std::vector<int> cpcpreal(real_stuff);
	std::cout << real_stuff.size() << std::endl;
	std::cout << real_stuff.capacity() << std::endl;
	std::cout << cpcpreal.size() << std::endl;
	std::cout << cpcpreal.capacity() << std::endl;
	*/

	return 0;
}