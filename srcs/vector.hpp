/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonnel <abonnel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 14:57:33 by abonnel           #+#    #+#             */
/*   Updated: 2022/02/11 11:36:46 by abonnel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
#define VECTOR_H

#include <memory>
#include <limits>
#include <stdexcept>
#include <iostream> // A ENLEVER
#include "iterator.hpp"

namespace ft
{
	template < class T, class Alloc = std::allocator<T> >
	class vector
	{
	public:
		class random_access_iterator : public ft::iterator<ft::random_access_iterator_tag, T>
		{
			public : 
				typedef typename ft::iterator<ft::random_access_iterator_tag, T>::difference_type		difference_type;
				typedef typename ft::iterator<ft::random_access_iterator_tag, T>::value_type			value_type;
				typedef typename ft::iterator<ft::random_access_iterator_tag, T>::pointer				pointer;
				typedef typename ft::iterator<ft::random_access_iterator_tag, T>::reference				reference;
				typedef typename ft::iterator<ft::random_access_iterator_tag, T>::iterator_category		iterator_category;
				
				//Constructor / Destructor / Canonical
				random_access_iterator(){
					_p = NULL;};
				random_access_iterator(T* const ptr){
					_p = ptr;};
				random_access_iterator(random_access_iterator const &rhs){
					_p = rhs._p;};
				random_access_iterator & operator=(random_access_iterator const &rhs){
					_p = rhs._p;
					return *this;};
				~random_access_iterator(){};
				
				//Equality && inequality && compare
				bool operator==(random_access_iterator const &rhs) const {return ((_p == rhs._p) ? true : false);};
				bool operator!=(random_access_iterator const &rhs) const {return ((_p != rhs._p) ? true : false);};
				bool operator<(random_access_iterator const &rhs) const {return ((_p < rhs._p) ? true : false);};
				bool operator<=(random_access_iterator const &rhs) const {return ((_p <= rhs._p) ? true : false);};
				bool operator>=(random_access_iterator const &rhs) const {return ((_p >= rhs._p) ? true : false);};
				bool operator>(random_access_iterator const &rhs) const {return ((_p > rhs._p) ? true : false);};

				//Arithmetic operations
				random_access_iterator operator+(difference_type const &offset) const {
					return (_p + offset);};
				friend random_access_iterator operator+(difference_type const &offset, random_access_iterator const &it){
					return (it._p + offset);};
				random_access_iterator operator-(difference_type const &offset) const {
					return (_p - offset);};
				difference_type operator-(random_access_iterator const &it) const {
					return (_p - it._p);};
					
				//Compound assignement
				random_access_iterator& operator+=(difference_type const &offset){
					_p += offset;
					return (*this);};
				random_access_iterator& operator-=(difference_type const &offset){
					_p -= offset;
					return (*this);};
				
				//Dereference
				value_type &operator*(void) const {return *_p;};
				pointer operator->() const {return &(operator*());};
				
				//Increment && decrement
				random_access_iterator &operator++(){
					_p++;
					return (*this);};
				
				random_access_iterator operator++(int){
					pointer tmp(_p++);
					return (tmp);};

				random_access_iterator &operator--(){
					_p--;
					return (*this);};
				
				random_access_iterator operator--(int){
					pointer tmp(_p--);
					return (tmp);};

				//operator []
				value_type operator[](int const &index) const {return _p[index];};

			protected :
				pointer		_p;
		};
		
		//VECTOR
		
		typedef T 											value_type;
		typedef Alloc 										allocator_type;
		typedef typename allocator_type::reference 			reference;
		typedef typename allocator_type::const_reference 	const_reference;
		typedef typename allocator_type::pointer			pointer;
		typedef typename allocator_type::const_pointer 		const_pointer;
		typedef ptrdiff_t									difference_type;
		typedef size_t 										size_type;
		typedef random_access_iterator						iterator;
		typedef const random_access_iterator				const_iterator;
		typedef reverse_iterator<const_iterator>			const_reverse_iterator;
		typedef reverse_iterator<iterator>					reverse_iterator;
		
		/*
		Capacity and Allocator at first capacity matches the first size given but then it doubles its capacity
		when there is not enough memory
		
		!! si capacity de depart = 0 alors special case qu'il faudra hard coder car 2 * 0 = 0

		!! be careful about max size and bad_alloc when not possible to allocate more 
		--> FAIRE ALLOCATE QUI SET LA CAPACITY ET s'occupe de throw erreur??
		*/


		//Constructor
		explicit vector (const allocator_type& alloc = allocator_type()) : _array(NULL), _size(0), _capacity(0), _alloc(alloc) {};
		explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()) : _size(n), _capacity(n), _alloc(alloc)
		{
			//works with vector<random_class> :  ft::vector<A>	class_vector(4, 12);
			if (_size > max_size())
				throw (std::length_error("vector"));
			_array = _alloc.allocate(_size);
			for (size_type i = 0; i < _size; i++)
				_alloc.construct(_array + i, val);
			//Here if val is an instance of a class, it will call the copy constructor of that instance
		};

		//PROBLEM --> need to use smth that shows that InputIterator is an iterator		
		// template <class InputIterator> //bc it could be a pointer
		// vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type()): _size(last - first), _capacity(_size), _alloc(alloc)
		// {
		// 	if (_size > max_size())
		// 		throw (std::length_error("vector"));
		// 	_array = _alloc.allocate(_size);
		// 	for (; first != last; first++)
		// 		_alloc.construct(first, *first);
		// };

		//Verifier une fois push_back cree que quand on construit par copy, capacity est bien set a la SIZE de la copy, la capacity n'est pas recopiee
		vector (const vector& x) : _size(x.size()), _capacity(_size), _alloc(x.get_allocator())
		{
			_array = _alloc.allocate(_size);
			for (size_type i = 0; i < _size; i++)
				_alloc.construct(_array + i, x[i]);
		};
		
		//deep copy works, verified
		vector& operator= (const vector& x) {
			_size = x._size;
			_capacity = _size;
			_alloc = x._alloc;
			_array = _alloc.allocate(_size);
			for (size_type i = 0; i < _size; i++)
				_alloc.construct(_array + i, x[i]);
		};
		
		
		//Destructor
		~vector()
		{
			for (size_type i = 0; i < _size; i++)
				_alloc.destroy(_array + i);
			_alloc.deallocate(_array, _capacity);
		};
		
		
		// Iterators
		iterator begin(){
			return _array;};
			
		const_iterator begin() const {
			return _array;};
			
		iterator end(){
			return (_array + _size);};
			
		const_iterator end() const {
			return (_array + _size);};
		
		reverse_iterator       rbegin(){
			return (reverse_iterator(_array + _size));};
			
		const_reverse_iterator rbegin() const {
			return (reverse_iterator(_array + _size));};

		reverse_iterator       rend() {
			return (reverse_iterator(_array));};
			
		const_reverse_iterator rend() const {
			return (reverse_iterator(_array));};


		//Capacity
		size_type 	size() const {
			return _size;
		};
		size_type 	max_size() const {
			return (_alloc.max_size());
		};
		// void 		resize (size_type n, value_type val = value_type());
		size_type 	capacity() const {
			return _capacity;	
		};
		bool 		empty() const {
			return (_size == 0 ? true : false);	
		};
		void 		reserve(size_type n) {
			if (n > _capacity)
				_array = _realloc(n);
		};

		//Element access: [] Does segfault in real vector if out of bound, whereas at() checks if in the range
		reference operator[] (size_type n) {
			return _array[n];
		};
		const_reference operator[] (size_type n) const {
			return _array[n];
		};
		
		reference at(size_type n) {
			if (n >= _size)
				throw std::out_of_range("vector");
			return _array[n];
		};
		const_reference at(size_type n) const {
			if (n >= _size)
				throw std::out_of_range("vector");
			return _array[n];
		};
		
		//tested front() & back() on empty container and NON empty one VS std::vector --> OK
		reference front() {
			return *_array;
		};
		const_reference front() const {
			return *_array;
		};
		reference back(){
			return *(_array + _size - 1);
		};
		const_reference back() const{
			return *(_array + _size - 1);
		};

		//Modifiers:
		// assign
		void push_back (const value_type& val){
			if (_size == _capacity)
				_array = _realloc(_capacity * 2);
			_size++;
			_alloc.construct(_array + _size - 1, val);
		};
		
		void pop_back() {
			if (_size > 0)
			{
				_alloc.destroy(_array + _size - 1);
				_size--;
			}
		};
		// insert
		// erase
		// swap
		// clear

		//Allocator:
		allocator_type get_allocator() const {
			return _alloc;
		};

		//friends
		// template <class T, class Alloc>
		// friend void swap (vector<T,Alloc>& x, vector<T,Alloc>& y);

	private:
		value_type	*_array;
		size_type	_size;
		size_type	_capacity;
		allocator_type	_alloc;

		value_type *_realloc(size_type n){
			value_type *tmp;

			if (n == 0)
				n = 1;
			if (n > max_size())
				throw (std::length_error("vector"));
			tmp = _alloc.allocate(n);
			for (size_type i = 0; i < _size; i++)
				_alloc.construct(tmp + i, _array[i]);
			for (size_type i = 0; i < _size; i++)
				_alloc.destroy(_array + i);
			_alloc.deallocate(_array, _capacity);
			_capacity = n;
			return (tmp);
		};
	
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