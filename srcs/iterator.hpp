/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonnel <abonnel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 11:36:32 by ariane            #+#    #+#             */
/*   Updated: 2022/02/02 17:10:26 by abonnel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_HPP
#define ITERATOR_HPP

namespace ft {

struct random_access_iterator_tag {}; //possible d'utiliser ceux de base aussi

//iterator est une interface pour definir ce qu'est un iterateur
template <class Category, class T, class Distance = ptrdiff_t,
          class Pointer = T*, class Reference = T&>
struct iterator {
    typedef T         value_type; 
    typedef Distance  difference_type;
    typedef Pointer   pointer;
    typedef Reference reference;
    typedef Category  iterator_category;
  };

//ex ici pour creer une instance de la class template d'en dessous, il faut :
// ft::iterator_traits<ft::iterator<std::random_access_iterator_tag, int> >

//<class Iterator> est un placeholder donc l'utilisateur pourrait mettre n'importe quoi
//comme iterator_traits<double> MAIS ne fonctionnera pas au compilateur car 
//double::difference_type n'existe pas donc va nous empecher de faire n'imp
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

//SPECIALISATION DE SYNTAXE DU DESSOUS : CLASSE TEMPLATE SUR POINTEUR
//https://www.learncpp.com/cpp-tutorial/partial-template-specialization-for-pointers/
//donc dès qu'on envoit un iterator_traits<POINTEUR> alors ira en bas

//iterator_traits fait le lien entre iterateurs et pointeurs, afin de pouvoir
//les utiliser de maniere quasi interchangeable
//https://forum.hardware.fr/hfr/Programmation/C-2/conception-iterator-introduction-sujet_63686_1.htm
//iterator_traits nous permet d'obtenir les types a utiliser pour difference_type, pointer, iterator_cat etc
//selon si on lui envoi un pointeur ou un iterateur, va permettre d'unifier le tout en ayant un seul
//difference_type, iterator_cat etc...

// ft::iterator_traits<int *>
template <class T>
class iterator_traits<T*>
{
	public :
	
    typedef ptrdiff_t                   	difference_type;
    typedef T                           	value_type;
    typedef	T*	                			pointer;
    typedef T&                 				reference;
    typedef std::random_access_iterator_tag iterator_category;
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

//pour reverse_iterator, heriter de random_ et override increment/decrement operations? !! arithmetics aussi
template <class iterator> //Où, pour vector, iterator sera forcement un random_access_iterator car typedef
class reverse_iterator
{
	public : 
		typedef typename iterator::difference_type		difference_type;
		typedef typename iterator::value_type			value_type;
		typedef typename iterator::pointer				pointer;
		typedef typename iterator::reference			reference;
		typedef typename iterator::iterator_category	iterator_category;

	protected :
		pointer _p;
		iterator base;//????????
};

}; //namespace ft

#endif //ITERATOR_HPP