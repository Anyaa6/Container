/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonnel <abonnel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 14:57:38 by abonnel           #+#    #+#             */
/*   Updated: 2022/04/26 13:22:32 by abonnel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
#define STACK_HPP
#include "vector.hpp"

namespace ft 
{
	template <class T, class Container = ft::vector<T> > 
	class stack {
	public : 
		
		typedef T								value_type;
		typedef Container						container_type;
		typedef typename Container::size_type	size_type;

		explicit stack (const container_type& ctnr = container_type()): _ctnr(ctnr) {
		};
		bool empty() const {
			return (_ctnr.empty());
		};
		size_type size() const {
			return (_ctnr.size());
		};
		value_type& top() {
			return (_ctnr.back());
		};
		const value_type& top() const {
			return (_ctnr.back());
		};
		void push (const value_type& val){
			_ctnr.push_back(val);
		};
		void pop() {
			_ctnr.pop_back();
		};

	//RELATIONAL OPERATORS
	friend bool operator== (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
		return (lhs._ctnr == rhs._ctnr);
	};
	friend bool operator!= (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
		return (lhs._ctnr != rhs._ctnr);
	};
	friend bool operator< (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
		return (lhs._ctnr < rhs._ctnr);
	};
	friend bool operator<= (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
		return (lhs._ctnr <= rhs._ctnr);
	};
	friend bool operator> (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
		return (lhs._ctnr > rhs._ctnr);
	};
	friend bool operator>= (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
		return (lhs._ctnr >= rhs._ctnr);
	};
		
	protected :
		container_type		_ctnr;
	};
}

#endif //STACK_HPP