/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bidirectional_iterator.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonnel <abonnel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 12:10:41 by abonnel           #+#    #+#             */
/*   Updated: 2022/05/30 15:47:43 by abonnel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BIDIRECTIONAL_ITERATOR_HPP
#define BIDIRECTIONAL_ITERATOR_HPP

namespace ft
{

template <typename Node>
class bidirectional_iterator : public ft::iterator<ft::bidirectional_iterator_tag, typename Node::value_type>
{
	public : 
		typedef typename bidirectional_iterator::difference_type		difference_type;
		typedef typename bidirectional_iterator::value_type				value_type;
		typedef typename bidirectional_iterator::pointer				pointer;
		typedef typename bidirectional_iterator::reference				reference;
		typedef typename bidirectional_iterator::iterator_category		iterator_category;
		
		//Constructor
		bidirectional_iterator(){
			_p = NULL;};
		bidirectional_iterator(Node* const ptr){
			_p = ptr;};

		//Implicitely declared
		// bidirectional_iterator(bidirectional_iterator const &rhs){};
		// bidirectional_iterator & operator=(bidirectional_iterator const &rhs){};
		// ~bidirectional_iterator(){};
		
		//Equality && inequality && compare
		bool operator==(bidirectional_iterator const &rhs) const {return (_p == rhs._p);};
		bool operator!=(bidirectional_iterator const &rhs) const {return (_p != rhs._p);};


		//Dereference
		//Return value_type (pair) for the std::map
		value_type &operator*(void) const {return *_p->val_ptr;};
		pointer operator->() const {return &(operator*());};
		
		// Increment && decrement
		bidirectional_iterator &operator++(){
			this->_increment();
			return (*this);};
		
		bidirectional_iterator operator++(int){
			bidirectional_iterator tmp(_p);
			this->_increment();
			return (tmp);};

		bidirectional_iterator &operator--(){
			this->_decrement();
			return (*this);};
		
		bidirectional_iterator operator--(int){
			bidirectional_iterator tmp(_p);
			this->_decrement();
			return (tmp);};

	protected :
		Node		*_p;

		void _increment() {
			if (_p->right) 
			{
				_p = _p->right;
				while (_p->left) {
					_p = _p->left;
				}
			}
			else if (_p->parent)
			{
				while (_p->parent->left != _p && _p->parent != NULL)
					_p = _p->parent;
				_p = _p->parent;
			}
		};

		void _decrement() {
			if (_p->left)
			{
				_p = _p->left;
				while (_p->right)
					_p = _p->right;
			}
			else if (_p->parent)
			{
				while (_p->parent->right != _p && _p->parent != NULL)
					_p = _p->parent;
				_p = _p->parent;
			}
		};
};
}

#endif //BIDIRECTIONAL_ITERATOR_HPP