/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonnel <abonnel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 14:57:33 by abonnel           #+#    #+#             */
/*   Updated: 2022/05/31 10:44:06 by abonnel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
#define VECTOR_H

#include <memory>
#include <limits>
#include <stdexcept>
#include "../iterators/iterator.hpp"
#include "../iterators/reverse_iterator.hpp"
#include "../utils/metafunctions.hpp"
#include "../utils/lexicographical_compare.hpp"
#include "../iterators/random_access_iterator.hpp"

namespace ft
{
	template < class T, class Alloc = std::allocator<T> >
	class vector
	{
	public:
		typedef T 											value_type;
		typedef Alloc 										allocator_type;
		typedef typename allocator_type::reference 			reference;
		typedef typename allocator_type::const_reference 	const_reference;
		typedef typename allocator_type::pointer			pointer;
		typedef typename allocator_type::const_pointer 		const_pointer;
		typedef ptrdiff_t									difference_type;
		typedef size_t 										size_type;
		typedef ft::random_access_iterator<value_type>		iterator;
		typedef ft::random_access_iterator<const value_type>	const_iterator;
		typedef ft::reverse_iterator<iterator>					reverse_iterator;
		typedef ft::reverse_iterator<const_iterator>			const_reverse_iterator;
		
		//Constructors --> construction goes from _array[0] to _array[n] in forward movement
		explicit vector (const allocator_type& alloc = allocator_type()) : _array(NULL), _size(0), _capacity(0), _alloc(alloc) {};

		explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()) : _size(n), _capacity(n), _alloc(alloc)
		{
			if (_size > max_size())
				throw (std::length_error("vector"));
			_array = _alloc.allocate(_size);
			for (size_type i = 0; i < _size; i++)
				_alloc.construct(_array + i, val);
		};
		
		template <class InputIterator>
		vector (typename ft::enable_if<(ft::is_same<InputIterator, reverse_iterator>::value) 
		|| (ft::is_same<InputIterator, iterator>::value) 
		|| (ft::is_same<InputIterator, pointer>::value), InputIterator>::type first, 
		InputIterator last, const allocator_type& alloc = allocator_type()): _size(last - first), _capacity(_size), _alloc(alloc)
		{
			if (_size > max_size())
				throw (std::length_error("vector"));
			_array = _alloc.allocate(_size);
			for (int i = 0; first != last; first++, i++)
				_alloc.construct(_array + i, *first);
		};

		vector (const vector& x) : _size(x.size()), _capacity(_size), _alloc(x.get_allocator())
		{
			_array = _alloc.allocate(_size);
			for (size_type i = 0; i < _size; i++)
				_alloc.construct(_array + i, x[i]);
		};
		
		vector& operator= (const vector& x) {
			_size = x._size;
			_capacity = _size;
			_alloc = x._alloc;
			_array = _alloc.allocate(_size);
			for (size_type i = 0; i < _size; i++)
				_alloc.construct(_array + i, x[i]);
			return (*this);
		};
		
		
		//Destructor
		~vector()
		{
			for (; _size > 0; _size--)
				_alloc.destroy(_array + _size - 1);
			_alloc.deallocate(_array, _capacity);
		};
		
		
		// Iterators OK
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


		//Capacity OK
		size_type 	size() const {
			return _size;
		};
		size_type 	max_size() const {
			return (_alloc.max_size());
		};

		void 		resize (size_type n, value_type val = value_type()) {
			if (n > max_size()) //bc msg is different for resize et reserve
				throw (std::length_error("vector"));
			if (n < _size)
				for (size_type i = _size; i > n; i--)
					this->pop_back();
			if (n > _capacity) {
				ft::vector<T>	tmp;
				tmp._array = (n >= _capacity * 2 ? _alloc.allocate(n) : _alloc.allocate(_capacity * 2));
				tmp._capacity = (n >= _capacity * 2 ? n : _capacity * 2);
				
				//copy extra elements in --> movement to fill vector with value
				_copy(n - _size, val, iterator(tmp._array + _size), tmp);
				//copy existing elements int <-- movement
				_copy(this->rbegin(), this->rend(), reverse_iterator(tmp._array + _size), tmp);
				
				this->~vector();
				_swap_between_two(*this, tmp);
				_set_to_zero(&tmp);				
			}
		};
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
		
		reference front() {
			return *_array;
		};
		const_reference front() const {
			return *_array;
		};
		reference back(){
			reference last_value = *(_array + _size - 1);
			return (last_value);
		};
		const_reference back() const {
			reference last_value = *(_array + _size - 1);
			return (last_value);
		};

		//Modifiers:
		void assign (size_type n, const value_type& val){
			if (n > _capacity)
			{
				_realloc_empty(n);
				for (size_type i = 0; i < n; i++)
					this->push_back(val);
			}
			else 
			{
				size_type i = 0;
				if (n > _size) {
					for (; i < _size; i++)
						_array[i] = val;
					for (; i < n; i++, _size++)
						_alloc.construct(_array + i, val);
				}
				else {
					for (; i < n; i++)
						_array[i] = val;
				}
				while (_size > n)
					this->pop_back();
			}
		};
		
		template <typename InputIterator>
		void assign (typename ft::enable_if<(ft::is_same<InputIterator, reverse_iterator>::value) 
		|| (ft::is_same<InputIterator, iterator>::value) 
		|| (ft::is_same<InputIterator, pointer>::value), InputIterator>::type first, InputIterator last) {
			size_type			n = _distance_between_it(first, last);

			if (n > _capacity)
			{
				_realloc_empty(n);
				for (;first != last; first++)
					this->push_back(*first);
			}
			else 
			{
				size_type i = 0;
				if (n > _size) {
					for (; i < _size; i++, first++)
						_array[i] = *first;
					for (; i < n; i++, _size++, first++)
						_alloc.construct(_array + i, *first);
				}
				else {
					for (; i < n; i++, first++)
						_array[i] = *first;
				}
				while (_size > n)
					this->pop_back();
			}		
		};
		
		void push_back (const value_type& val){
			if (_size == _capacity)
				_array = _realloc_push_back(_capacity * 2, val);
			else {
				_size++;
				_alloc.construct(_array + _size - 1, val);
			}
		};
		
		void pop_back() {
			if (_size > 0)
			{
				_alloc.destroy(_array + _size - 1);
				_size--;
			}
		};
		
		iterator insert (iterator position, const value_type& val) {
			size_type	n = 1; //nb of inserted elements
			size_type	pos_index = _distance_between_it(begin(), position);
			
			if (n + _size > _capacity)
			{
				ft::vector<T>	tmp;
				tmp._array = _alloc.allocate(n + _size);
				tmp._capacity = n + _size;
				
				//Copies first -> last range at right position in --> movement
				_alloc.construct(tmp._array + pos_index, val);
				tmp._size++;
				//Copies elemets before first in <-- movement
				_copy(reverse_iterator(position), this->rend(), reverse_iterator(tmp._array + pos_index), tmp);
				//copies elements after last in --> movement
				_copy(position, end(), iterator(tmp._array + pos_index + n), tmp);
				
				this->~vector();
				_swap_between_two(*this, tmp);
				_set_to_zero(&tmp);
				return (iterator(_array + pos_index));
			}
			if (position == end()) {
				_alloc.construct(_array + _size, val);
				_size++;
				return (--end());
			}
			//copies n last elements of vec to their end position in --> movement
			_alloc.construct(_array + _size, _array[_size - n]);
			_size++;
			//moves (operator =) all prev elements including position to their end position in <-- movement
			_move(reverse_iterator(_array + _size - 2 * n ), reverse_iterator(position), reverse_iterator(_array + _size - n));
			//moves (operator =) val to its location
			*position = val;
			return (position);
		};


		void insert (iterator position, size_type n, const value_type& val){
			size_type	pos_index = _distance_between_it(begin(), position);
			
			if (n + _size > _capacity)
			{
				ft::vector<T>	tmp;
				tmp._array = _alloc.allocate(n + _size);
				tmp._capacity = n + _size;
				
				//Copies n * val at right position in --> movement
				_copy(n, val, iterator(tmp._array + pos_index), tmp);
				//Copies elemets before first in <-- movement
				_copy(reverse_iterator(position), this->rend(), reverse_iterator(tmp._array + pos_index), tmp);
				//copies elements after last val in --> movement
				_copy(position, end(), iterator(tmp._array + pos_index + n), tmp);
				
				this->~vector();
				_swap_between_two(*this, tmp);
				_set_to_zero(&tmp);
			}
			else
				_insert_without_realloc(position, n, val, pos_index);
		};

		template <class InputIterator>
		void insert (iterator position, typename ft::enable_if<(ft::is_same<InputIterator, reverse_iterator>::value) 
		|| (ft::is_same<InputIterator, iterator>::value) 
		|| (ft::is_same<InputIterator, pointer>::value), InputIterator>::type first, InputIterator last) {
			size_type	n = _distance_between_it(first, last); //nb of inserted elements
			size_type	pos_index = _distance_between_it(begin(), position);
			
			if (n + _size > _capacity)
			{
				ft::vector<T>	tmp;
				tmp._array = _alloc.allocate(n + _size);
				tmp._capacity = n + _size;
				
				//Copies first -> last range at right position in --> movement
				_copy(first, last, iterator(tmp._array + pos_index), tmp);
				//Copies elemets before first in <-- movement
				_copy(reverse_iterator(position), this->rend(), reverse_iterator(tmp._array + pos_index), tmp);
				//copies elements after last in --> movement
				_copy(position, end(), iterator(tmp._array + pos_index + n), tmp);
				
				this->~vector();
				_swap_between_two(*this, tmp);
				_set_to_zero(&tmp);
			}
			else
			{
				//copies n last elements of vec to their end position in --> movement
				_copy(iterator(_array + _size - n), iterator(_array + _size), iterator(_array + _size), *this);
				//moves (operator =) all prev elements including position to their end position in <-- movement
				_move(reverse_iterator(_array + _size - 2 * n ), reverse_iterator(position), reverse_iterator(_array + _size - n));
				//moves (operator =) elements from first to last to their location in --> movement
				_move(first, last, position);
				//no need to adapt this part like fill insert bc STD works like this
			}
		};
		
		iterator erase (iterator position){
			// if not last element move elements in --> order to position
			if (position != --end())
				_move(position + 1, end(), position);
			// destroy last element
			_alloc.destroy(_array + _size - 1);
			_size--;
			return (position);
		};

		iterator erase (iterator first, iterator last) {
			size_type dist_to_end = _distance_between_it(last, this->end());
			//move elements from last (included) to end to first
			_move(last, this->end(), first);
			//destroy all ellements past last in <-- order
			while (first + dist_to_end != this->end())
				this->pop_back();
			return (first);
		};
		
		//cannot use '=' otherwise it will copy construct and addresses will not be the same and iterators invalidated
		void swap (vector& x) {
			ft::vector<T>	tmp;
			
			_swap_between_two(tmp, *this);
			_swap_between_two(*this, x);
			_swap_between_two(x, tmp);
			_set_to_zero(&tmp); //So that _array is not destructed with tmp upon exiting
		};

		void clear() {
			for (size_type i = _size; i > 0; i--)
				this->pop_back();
		}

		//Allocator OK :
		allocator_type get_allocator() const {
			return _alloc;
		};

	private:
		value_type	*_array;
		size_type	_size;
		size_type	_capacity;
		allocator_type	_alloc;
		
		value_type *_realloc(size_type n)
		{
			value_type *tmp;

			if (n == 0)
				n = 1;
			tmp = _alloc.allocate(n);
			for (size_type i = _size; i > 0; i--)
				_alloc.construct(tmp + i - 1, _array[i - 1]);
			for (size_type i = _size; i > 0; i--)
				_alloc.destroy(_array + i - 1);
			_alloc.deallocate(_array, _capacity);
			_capacity = n;
			return (tmp);
		};
		
		value_type *_realloc_push_back(size_type n, const value_type &at_end)
		{
			value_type *tmp;

			if (n == 0)
				n = 1;
			tmp = _alloc.allocate(n);
			_alloc.construct(tmp + _size, at_end);
			for (size_type i = _size; i > 0; i--)
				_alloc.construct(tmp + i - 1, _array[i - 1]);
			for (size_type i = _size; i > 0; i--)
				_alloc.destroy(_array + i - 1);
			_alloc.deallocate(_array, _capacity);
			_size++;
			_capacity = n;
			return (tmp);
		};

		void _realloc_empty(size_type n){
			this->clear();
			_alloc.deallocate(_array, _capacity);
			_array = _alloc.allocate(n);
			_capacity = n;
		};

		void _swap_between_two(vector &y, vector &z) {
			y._array = z._array;
			y._capacity = z._capacity;
			y._size = z._size;
			y._alloc = z._alloc;			
		}

		template <class InputIterator>
		size_type _distance_between_it(InputIterator const first, InputIterator const last) const {
			return (static_cast<size_type>(last - first));
		};
		
		void _set_to_zero(ft::vector<T> *tmp) {
			tmp->_capacity = 0;
			tmp->_size = 0;
			tmp->_array = NULL;
		};

		template <typename iterator, typename container>
		void _copy(typename ft::enable_if<(ft::is_same<iterator, reverse_iterator>::value) 
		|| (ft::is_same<iterator, iterator>::value) 
		|| (ft::is_same<iterator, pointer>::value), iterator>::type first, iterator last, iterator at_position, container &destination) {
			for (; first != last; first++, at_position++, destination._size++)
				_alloc.construct(&*at_position, *first);
		};

		template <typename container>
		void _copy(size_type n, const value_type& val, iterator at_position, container &destination) {
			for (size_type i = 0; i < n; i++, at_position++, destination._size++)
				_alloc.construct(&*at_position, val);
		};
		
		template <typename iterator>
		void _move(typename ft::enable_if<(ft::is_same<iterator, reverse_iterator>::value) 
		|| (ft::is_same<iterator, iterator>::value) 
		|| (ft::is_same<iterator, pointer>::value), iterator>::type first, iterator last, iterator at_position) {
			for (; first != last; first++, at_position++)
				*at_position = *first;
		};

		void _move(size_type n, const value_type& val, iterator at_position) {
			for (size_type i = 0; i < n; i++, at_position++)
				*at_position = val;
		};

		void _insert_without_realloc(iterator position, size_type n, const value_type& val, size_type pos_index) {
			size_type nb_of_elements_after_pos = _size - pos_index;
			//if there are more than n numbers after pos in initial vector
			if (nb_of_elements_after_pos >= n){
				//copies n last elements of vec to their end position in --> movement
				_copy(iterator(_array + _size - n), iterator(_array + _size), iterator(_array + _size), *this);
				//moves (operator =) all prev elements including position to their end position in <-- movement
				_move(reverse_iterator(_array + _size - 2 * n ), reverse_iterator(position), reverse_iterator(_array + _size - n));
				//moves (operator =) elements from first to last to their location in --> movement
				_move(n, val, position);
			}
			//if there are not enough numbers after pos in initial vector to copy to their end position directly
			else {
				size_type nb_of_val_copies = n - (_size - pos_index);
				//copy nb_of_val_copies * val to their end position in --> movement
				_copy(nb_of_val_copies, val, iterator(_array + _size), *this);
				//copy last existing elements of the vector at the end of vector in --> movement
				_copy(iterator(_array + _size - n), iterator(_array + _size - nb_of_val_copies), iterator(_array + _size), *this);//ici
				//moves (operator =) as many val as needed to complete insert
				_move(nb_of_elements_after_pos, val, position);
			}
		};

	};

	//Non-member function overloads
	template <class T, class Alloc>
	void swap (vector<T,Alloc>& x, vector<T,Alloc>& y) {
		x.swap(y);
	};

	template <class T, class Alloc>
	bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
		if (lhs.size() != rhs.size())
			return (false);
		return (ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
	};
	
	template <class T, class Alloc>
	bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
		return (!(lhs == rhs));
	};
	
	template <class T, class Alloc>
	bool operator<  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
		return (lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	};
	
	template <class T, class Alloc>
	bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
		return (!(rhs < lhs));
	};
	
	template <class T, class Alloc>
	bool operator>  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
		return (rhs < lhs);
	};
	
	template <class T, class Alloc>
	bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
		return (!(lhs < rhs));
	};
}

#endif //VECTOR_HPP