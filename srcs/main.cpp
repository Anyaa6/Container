/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonnel <abonnel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 11:08:39 by                   #+#    #+#             */
/*   Updated: 2022/01/24 17:33:45 by abonnel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"
#include <iostream>


#include <vector> //A ENLEVER

int main()
{
	ft::vector<int>	haha;

	std::vector<int> real_stuff;

	std::cout << real_stuff.max_size() << std::endl;
	std::cout << std::numeric_limits<difference_type>::max() << std::endl;


	return 0;
}