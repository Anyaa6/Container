/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonnel <abonnel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 11:36:32 by ariane            #+#    #+#             */
/*   Updated: 2022/01/31 16:31:07 by abonnel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_HPP
#define ITERATOR_HPP
// struct random_access_iterator_tag {}; UTILISER CEUX DE BASE

namespace ft {

template <class Category, class T, class Distance = ptrdiff_t,
          class Pointer = T*, class Reference = T&>
struct iterator {
    typedef T         value_type; 
    typedef Distance  difference_type;
    typedef Pointer   pointer;
    typedef Reference reference;
    typedef Category  iterator_category;
  };

//ex ici pour creer iterator_traits<iterator<random_access_iterator, int>> au minimum
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

// ft::iterator_traits<ft::iterator<std::random_access_iterator_tag, int> >	trait_int;
//appelle classe du dessus

// ft::iterator_traits<int *>	trait_other;
//appelle classe du dessous

template <class T>
class iterator_traits<T*>
{
	public :
	
    typedef ptrdiff_t                   difference_type;
    typedef T                           value_type;
    typedef	value_type*	                pointer;
    typedef value_type&                 reference;
    typedef std::random_access_iterator_tag  iterator_category;
};

template <class T> 
class iterator_traits<const T*>
{
	public : 
	
    typedef ptrdiff_t                   difference_type;
    typedef T                           value_type;
    typedef	const value_type*	        pointer;
    typedef const value_type&           reference;
    typedef std::random_access_iterator_tag  iterator_category;
};

}; //namespace ft

#endif //ITERATOR_HPP