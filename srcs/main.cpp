/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonnel <abonnel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 11:08:39 by                   #+#    #+#             */
/*   Updated: 2022/02/02 11:18:05 by abonnel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"
#include <iostream>

#include <vector> //A ENLEVER
#include <iterator> //A ENLEVER

class A{
	public :
	int		number;
	A(int num) : number(num) {};
	~A(){};	
};

int main()
{
	//Testing iterators
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
	//END of Testing iterators


	

	//Basic tests, creating vector etc
	// ft::vector<int>	haha(4, 12);
	// haha[2] = 66;
	// haha[3] = 226;
	// ft::vector<int> hoho(haha); //par copy

	// ft::vector<int>::iterator	last = haha.end();
	// 
	// std::cout << "last - 1 : " << *(last--) << std::endl;

	// std::cout << "haha size " << haha.size() << " haha capacity : " << haha.capacity() << std::endl;
	// std::cout << "hoho size " << hoho.size() << " hoho capacity : " << hoho.capacity() << std::endl;
	// for (size_t i = 0; i < haha.size(); i++)
	// {
		// std::cout << "haha["<< i << "] " << haha[i] << std::endl;
		// std::cout << "hoho["<< i << "] " << hoho[i] << std::endl;
// 
	// }

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