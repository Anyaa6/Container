/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_access_iterator.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonnel <abonnel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 14:57:33 by abonnel           #+#    #+#             */
/*   Updated: 2022/04/19 15:21:45 by abonnel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RANDOM_ACCESS_ITERATOR_HPP
#define RANDOM_ACCESS_ITERATOR_HPP

#include <memory>
#include <limits>
#include <stdexcept>
#include "iterator.hpp"
#include "metafunctions.hpp"
#include "utils.hpp"


namespace ft
{

template <typename T>
class random_access_iterator : public ft::iterator<ft::random_access_iterator_tag, T>
{
	public : 
		typedef typename random_access_iterator::difference_type		difference_type;
		typedef typename random_access_iterator::value_type				value_type;
		typedef typename random_access_iterator::pointer				pointer;
		typedef typename random_access_iterator::reference				reference;
		typedef typename random_access_iterator::iterator_category		iterator_category;
		
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
}

#endif //VECTOR_HPP