/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonnel <abonnel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 10:00:21 by abonnel           #+#    #+#             */
/*   Updated: 2022/04/19 15:02:13 by abonnel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PAIR_HPP
#define PAIR_HPP

//pair prototype for make pair
namespace ft {
	template <class T1, class T2> 
	struct pair;
}

namespace ft {
	template <class T1, class T2>
	pair<T1,T2> make_pair (T1 x, T2 y) {
		return ( ft::pair<T1,T2>(x,y) );
	};
}

namespace ft
{
	template <class T1, class T2>
	struct pair {
	
	typedef T1 first_type;
	typedef T2 second_type;
	
	first_type first;
	second_type second;

	//constructors
	pair() : first(first_type()), second(second_type()) {};

	template<class U, class V>
	pair (const pair<U,V>& pr) : first(pr.first), second(pr.second) {};
	
	pair (const first_type& a, const second_type& b) : first(a), second(b) {};

	//implicitly declared
	// pair& operator= (const pair& pr);
	//~pair();
	};//pair
}//namespace

namespace ft {
	
	//relational operators
	template <class T1, class T2>
	bool operator== (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{ return lhs.first==rhs.first && lhs.second==rhs.second; }
	
	template <class T1, class T2>
	bool operator!= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{ return !(lhs==rhs); }
	
	template <class T1, class T2>
	bool operator<  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{ return lhs.first < rhs.first || (!(rhs.first < lhs.first) && lhs.second < rhs.second); }
	
	template <class T1, class T2>
	bool operator<= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{ return !(rhs<lhs); }
	
	template <class T1, class T2>
	bool operator>  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{ return rhs<lhs; }
	
	template <class T1, class T2>
	bool operator>= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{ return !(lhs<rhs); }
} //namespace ft




#endif //PAIR_HPP