/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariane <ariane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 11:08:39 by                   #+#    #+#             */
/*   Updated: 2022/01/27 18:17:40 by ariane           ###   ########.fr       */
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
	ft::iterator_traits<ft::iterator<int, int> >	trait_int;

	
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

/*
	std::vector<int> value_test(12,42);
	ft::vector<int> ft_value_test(12,42);

	std::cout << "index_test begin " << *(++value_test.begin()) << std::endl;
	std::cout << "index_test begin " << *(++ft_value_test.begin()) << std::endl;
*/


	//testing begin, front, end, back
	std::vector<int> index_test;
	ft::vector<int> ft_index_test;
	std::vector<int> value_test(12,42);
	ft::vector<int> ft_value_test(12,42);

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