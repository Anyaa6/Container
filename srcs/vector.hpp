/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonnel <abonnel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 14:57:33 by abonnel           #+#    #+#             */
/*   Updated: 2022/01/24 17:33:02 by abonnel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
#define VECTOR_H

#include <memory>

namespace ft
{
	template < class T, class Alloc = std::allocator<T> >
	class vector
	{
	public:
		//Coplien
		vector(){};
		~vector(){};
		// ft::vector &operator=(ft::vector const &rhs);
		
		//typedef T	value_type; //exemple
		
		// //Iterators
		// begin
		// end
		// rbegin
		// rend

		// //Capacity
		//size_type size() const {return _size;};
		// max_size
		// resize
		// capacity
		// empty
		// reserve

		// //Element access:
		// operator[]
		// at
		// front
		// back

		// //Modifiers:
		// assign
		// push_back
		// pop_back
		// insert
		// erase
		// swap
		// clear

		// //Allocator:
		// get_allocator

		// //Non-member function overloads
		// relational operators
		// swap

	private:
		T	*array;
		unsigned int	_size;
	
	};
}


#endif