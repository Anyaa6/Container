/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonnel <abonnel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 11:36:32 by ariane            #+#    #+#             */
/*   Updated: 2022/02/25 16:10:34 by abonnel          ###   ########.fr       */
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
			return *(_base -1);};

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

}; //namespace ft

#endif //ITERATOR_HPP