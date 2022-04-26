/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator_hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonnel <abonnel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 12:13:25 by abonnel           #+#    #+#             */
/*   Updated: 2022/04/26 12:14:06 by abonnel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_ITERATOR_HPP
#define REVERSE_ITERATOR_HPP

namespace ft {
//pour reverse_iterator, heriter de random_ et override increment/decrement operations? !! arithmetics aussi
template <class iterator>
class reverse_iterator
{
	public : 
		typedef iterator								iterator_type;//must be at least bidirectionnal
		typedef typename iterator::difference_type		difference_type;
		typedef typename iterator::value_type			value_type;
		typedef typename iterator::pointer				pointer;
		typedef typename iterator::reference			reference;
		typedef typename iterator::iterator_category	iterator_category;

		//Const Destructor
		reverse_iterator(){
			_base = iterator_type();};
			
		explicit reverse_iterator (iterator_type it){
			_base = it;};
			
		template <class Iter>
		reverse_iterator (const reverse_iterator<Iter>& rev_it){
			_base = rev_it._base;};

		iterator_type base() const{
			return _base;};

		//Dereference and []
		reference operator*() const {
			return *(_base - 1);};

		reference operator[] (difference_type n) const {
			return (*(_base - n - 1));};

		pointer operator->() const {
			return &(operator*());};
			
		//Arithmetic
		reverse_iterator operator+ (difference_type n) const {
			return (reverse_iterator(_base - n));};

		friend reverse_iterator operator+(difference_type n, reverse_iterator &rev_it){
			return (reverse_iterator(rev_it._base - n));};

		reverse_iterator& operator+= (difference_type n) {
			_base -= n;
			return (*this);};

		reverse_iterator operator- (difference_type n) const {
			return (reverse_iterator(_base + n));};
		
		friend difference_type operator- (const reverse_iterator& lhs, const reverse_iterator& rhs) {
			// return (lhs._base - rhs._base);
			return (rhs._base - lhs._base);
		};

		reverse_iterator& operator-= (difference_type n) {
			_base += n;
			return (*this);};

		//Increment / decrement
		reverse_iterator& operator++() {
			_base--;
			return *this;};
			
		reverse_iterator  operator++(int) {
			reverse_iterator tmp = *this;
			--_base;
			return (tmp);};

		reverse_iterator& operator--(){
			_base++;
			return *this;};
			
		reverse_iterator  operator--(int){
			reverse_iterator tmp = *this;
			++_base;
			return tmp;};

		//Relational operator
  		friend bool operator== (const reverse_iterator& lhs, const reverse_iterator& rhs){
			return (lhs._base == rhs._base);};
  		friend bool operator!= (const reverse_iterator& lhs, const reverse_iterator& rhs){
			return (lhs._base != rhs._base);};
  		friend bool operator<  (const reverse_iterator& lhs, const reverse_iterator& rhs){
			return (lhs._base > rhs._base);};
  		friend bool operator<= (const reverse_iterator& lhs, const reverse_iterator& rhs){
			return (lhs._base >= rhs._base);};
  		friend bool operator>  (const reverse_iterator& lhs, const reverse_iterator& rhs){
			return (lhs._base < rhs._base);};
  		friend bool operator>= (const reverse_iterator& lhs, const reverse_iterator& rhs){
			return (lhs._base <= rhs._base);};

	protected :
		iterator_type _base;
		
};

};

#endif //REVERSE_ITERATOR_HPP
