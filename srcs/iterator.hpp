/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariane <ariane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 11:36:32 by ariane            #+#    #+#             */
/*   Updated: 2022/01/27 18:14:13 by ariane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_HPP
#define ITERATOR_HPP
//Note that any custom class will have a valid instantiation of iterator_traits 
//if it publicly inherits the base class std::iterator.

//So base class std::iterator CONTAINS an std::iterator_traits class, it does
//not inherit from it, it contains it --> nested class

//iterator_traits is a template class that contains nothing but nested typedefs

//la classe mère ft::iterator contient un pointer en privé 

//cree d'abord iterator_traits puisqu'elle va etre nestee dans iterator
//doit donc apparaitre en amont de cette derniere
namespace ft {

struct random_access_iterator_tag {};

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
template <class iterator> 
class iterator_traits
{
	public :
	
    typedef typename iterator::difference_type   difference_type;
    typedef typename iterator::value_type        value_type;
    typedef	typename iterator::pointer	         pointer;
    typedef typename iterator::reference         reference;
    typedef typename iterator::iterator_category iterator_category;
    
};

template <class T> //specialisation a revoir //ici T reste variable 
class iterator_traits<T*> //pour spé seulement on specifie entre chevrons les variables qui vont
//etre utilisees dans la paire
//peut etre que fait reference a class Pointer = T* dans le template plu haut,
//donc si on laisse par defaut ce param alors iterator traits fera appel a cette spé
//TESTER, voir dans quel iterator_traits il va en fonction de quels param entres
{
	public :
	
    typedef ptrdiff_t                   difference_type;
    typedef T                           value_type;
    typedef	value_type*	                pointer;
    typedef value_type&                 reference;
    typedef random_access_iterator_tag  iterator_category;
};

template <class T> 
class iterator_traits<const T*>
{
	public : 
	
    typedef ptrdiff_t                   difference_type;
    typedef T                           value_type;
    typedef	const value_type*	        pointer;
    typedef const value_type&           reference;
    typedef random_access_iterator_tag  iterator_category;
};

}; //namespace ft

#endif //ITERATOR_HPP