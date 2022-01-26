/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariane <ariane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 14:57:33 by abonnel           #+#    #+#             */
/*   Updated: 2022/01/26 17:35:40 by ariane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
#define VECTOR_H

#include <memory>
#include <limits>
// #include <exception>
#include <stdexcept>
//# il faudra include reverse_iterator que je dois creer

#include <iostream>//a enlever?

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

		//iterator et const_iterator a cree moi-meme, doivent etre des classes et pas juste
		//des pointeurs
		typedef value_type* 		iterator;
		typedef const value_type*	const_iterator;
		typedef ptrdiff_t			difference_type;
		typedef size_t 				size_type;
		
		//below a creer moi meme, reverse iterator est une classe qui contient pointeur
		//et qd on incremente iterateur alors on decremente ce pointeur
		// reverse_iterator	reverse_iterator<iterator>	
		// const_reverse_iterator	reverse_iterator<const_iterator>	
		
		/*
		at first capacity matches the first size given but then everytime it reallocates memory then it doubles its capacity
		So at first push_back its absolutely sure that it will double its size since size and capacity matches

		la capacity est un multiple de la capacity de depart ! A chaque fois qu'il faut l'augmenter on fait capacity *2
		!! si capacity de depart = 0 alors special case qu'il faudra hard coder car 2 * 0 = 0

		!! implementation dependant donc peut etre que sur ordi de l'ecole ca ne marchera pas
		
		!! be careful about max size and bad_alloc when not possible to allocate more 
		--> FAIRE ALLOCATE QUI SET LA CAPACITY ET s'occupe de throw erreur??
		*/


		//Constructor
		explicit vector (const allocator_type& alloc = allocator_type()) : _array(NULL), _size(0), _capacity(0), _alloc(alloc) {};
		explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()) : _size(n), _capacity(n), _alloc(alloc)
		{
			//works with vector<random_class> :  ft::vector<A>	class_vector(4, 12);
			if (n > max_size())
				throw (std::length_error("vector"));
			_array = _alloc.allocate(_size);
			for (size_type i = 0; i < _size; i++)
				_alloc.construct(_array + i, val);
		};
		/*
		template <class InputIterator> //bc it could be a pointer
		vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type())
		{
			//find distance between iterators (ptrdiff ?) -> set _size
			//last - first / sizeof(T)
			//ou bien cb de fois on fait first++ pour arriver a last puisque ++ incremente du bon nb de bits
			//alloc corresponding capacity and set _capacity
			//iterate over first++ until last not included 
		};// range (3)
		*/

		//!! ici meme si copy de l'autre, la capacity est initialisée à la size
		//creer push_back et tester copier un vector a partir d'un autre apres qu'il
		//ait recu des push back
		vector (const vector& x) : _size(x.size()), _capacity(_size), _alloc(x.get_allocator())
		{
			_array = _alloc.allocate(_size);
			for (size_type i = 0; i < _size; i++)
				_alloc.construct(_array + i, x[i]);
		};
		
		//Destructor
		~vector()
		{
			_alloc.destroy(_array);
			_alloc.deallocate(_array, _size);
		};

		// vector& operator= (const vector& x);
		
		// Iterators
		//Probleme pour std::cout << "index_test begin " << *(++ft_value_test.begin()) << std::endl;
		//error: expression is not assignable
		//alors que vrai vector pas de soucis
		//to fix it iterator must be a CLASS, not a primitive type like pointer to value_type
		//so I need to implement the random_access_iterator class and iterator_traits
		iterator begin(){
			return _array;
		};
		const_iterator begin() const {
			return _array;
		};
		iterator end(){
			return (_array + _size);
		};
		const_iterator end() const {
			return (_array + _size);
		};
		
		// reverse_iterator       rbegin();
		// const_reverse_iterator rbegin() const;
		// reverse_iterator       rend() ;
		// const_reverse_iterator rend() const;


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
		// void 		reserve(size_type n);

		//Element access:
		//Does segfault in real vector if out of bound, whereas at() checks if in the range
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

		// //Modifiers:
		// assign
		// push_back
		// pop_back
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