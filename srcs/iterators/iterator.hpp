/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonnel <abonnel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 11:36:32 by ariane            #+#    #+#             */
/*   Updated: 2022/05/30 15:48:23 by abonnel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_HPP
#define ITERATOR_HPP

namespace ft {

struct random_access_iterator_tag {};
struct bidirectional_iterator_tag {};

template <class Category, class T, class Distance = ptrdiff_t,
          class Pointer = T*, class Reference = T&>
struct iterator {
    typedef T         value_type; 
    typedef Distance  difference_type;
    typedef Pointer   pointer;
    typedef Reference reference;
    typedef Category  iterator_category;
  };
  
template <class Iterator>
class iterator_traits
{
	public :
	
    typedef typename Iterator::difference_type   difference_type;
    typedef typename Iterator::value_type        value_type;
    typedef	typename Iterator::pointer	         pointer;
    typedef typename Iterator::reference         reference;
    typedef typename Iterator::iterator_category iterator_category;
};

template <class T>
class iterator_traits<T*>
{
	public :
	
    typedef ptrdiff_t                   	difference_type;
    typedef T                           	value_type;
    typedef	T*	                			pointer;
    typedef T&                 				reference;
    typedef ft::random_access_iterator_tag iterator_category;
};

template <class T> 
class iterator_traits<const T*>
{
	public : 
	
    typedef ptrdiff_t                   difference_type;
    typedef T                           value_type;
    typedef	const value_type*	        pointer;
    typedef const value_type&           reference;
    typedef ft::random_access_iterator_tag  iterator_category;
};

}; //namespace ft

#endif //ITERATOR_HPP