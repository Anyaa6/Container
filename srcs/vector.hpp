/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonnel <abonnel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 14:57:33 by abonnel           #+#    #+#             */
/*   Updated: 2022/01/25 18:00:13 by abonnel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
#define VECTOR_H

#include <memory>
//# il faudra include reverse_iterator que je dois creer

namespace ft
{
	template < class T, class Alloc = std::allocator<T> >
	class vector
	{
	public:
		//Members
		typedef T 			value_type;
		typedef Alloc 		allocator_type;
		typedef typename allocator_type::reference 			reference;
		typedef typename allocator_type::const_reference 	const_reference;
		typedef typename allocator_type::pointer			pointer;
		typedef typename allocator_type::const_pointer 		const_pointer;
		typedef value_type* 		iterator;
		typedef const value_type*	const_iterator;
		typedef ptrdiff_t			difference_type;
		typedef size_t 				size_type;
		
		//below a creer moi meme, reverse iterator est une classe qui contient pointeur
		//et qd on incremente iterateur alors on decremente ce pointeur
		// reverse_iterator	reverse_iterator<iterator>	
		// const_reverse_iterator	reverse_iterator<const_iterator>	
		


		//Constructor
		explicit vector (const allocator_type& alloc = allocator_type()) : _array(NULL), _size(0), _capacity(0), _alloc(alloc) {};
		explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()) : _size(n), _alloc(alloc)
		{
			_array = _alloc.allocate(_size);
			_alloc.construct(_array, val);
		};	
		// template <class InputIterator> //bc it could be a pointer
		// vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type());// range (3)
		// 
		// vector (const vector& x);// copy (4)

		//Destructor
		~vector()
		{
			_alloc.destroy(_array);
			_alloc.deallocate(_array, _size);
		};

		// vector& operator= (const vector& x);
		
		// //Iterators //pas de noexcept en c++98
		// iterator               begin();
		// const_iterator         begin() const;
		// iterator               end() ;
		// const_iterator         end() const;
	// 
		// reverse_iterator       rbegin();
		// const_reverse_iterator rbegin() const;
		// reverse_iterator       rend() ;
		// const_reverse_iterator rend() const;


		// //Capacity
		size_type 	size() const
		{
			return _size;
		};
		// size_type 	max_size() const; //std::cout << std::numeric_limits<difference_type>::max() << std::endl;
		// void 		resize (size_type n, value_type val = value_type());
		size_type 	capacity() const
		{
			return _capacity;	
		};
		bool 		empty() const
		{
			return (_size == 0 ? true : false);	
		};
		// void 		reserve(size_type n);

		// //Element access:
		reference operator[] (size_type n) {
			return _array[n];
		};
		const_reference operator[] (size_type n) const {
			return _array[n];
		};

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

		//friends
		// template <class T, class Alloc>
		// friend void swap (vector<T,Alloc>& x, vector<T,Alloc>& y);

	private:
		value_type	*_array;
		size_type	_size;
		size_type	_capacity;
		allocator_type	_alloc;
	
	};
}

		// //Non-member function overloads --> friend autorisé
		// relational operators
		// swap -> existe comme fonction membre vector.swap(other_vector) et aussi comme fonction
		//non membre : swap(vector<int>, other_vector<int>) et dans ce cas il faudra que swap ait
		//accès au attributs private de vector -> friend 
		// template <class T, class Alloc>
		// void swap (vector<T,Alloc>& x, vector<T,Alloc>& y);

#endif