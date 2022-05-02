/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bidirectional_iterator.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonnel <abonnel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 12:10:41 by abonnel           #+#    #+#             */
/*   Updated: 2022/05/02 14:48:30 by abonnel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BIDIRECTIONAL_ITERATOR_HPP
#define BIDIRECTIONAL_ITERATOR_HPP

//Constant iterators are iterators that do not fulfill the requirements of an output iterator; 
//Dereferencing them yields a reference to a constant element (such as const T&).

//std::map has its own class for const iterator
namespace ft
{

template <typename Node>
class bidirectional_iterator : public ft::iterator<ft::bidirectional_iterator_tag, typename Node::value_type>
{
	public : 
		typedef typename bidirectional_iterator::difference_type		difference_type;
		typedef typename bidirectional_iterator::value_type				value_type;
		//Below "pointer" comes from iterator<..., Node::value_type> so is equal to value_type* so a pointer to a pair
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
			//if right child then go there then outmost left child
			if (_p->right) 
			{
				_p = _p->right;
				while (_p->left) {
					_p = _p->left;
				}
			}
			else if (_p->parent)
			{
				//go up looking for parent with a right child
				//does it work when getting to the end?? YES if end has random value for left child, end()++ should segfault
				while (_p->parent->left != _p && _p->parent != NULL)
					_p = _p->parent;
				_p = _p->parent;
			}
		};

		void _decrement() {
			//if left child then go there them outmost right child
			if (_p->left)
			{
				_p = _p->left;
				while (_p->right)
					_p = _p->right;
			}
			else if (_p->parent)//do only "else" not "else if" so that next stuff are done no matter what and will give segfault when going before begin
			{
				//go up looking for parent with a left child
				//decrement should segfault if goes before begin -> YES if root has random value for parent
				while (_p->parent->right != _p && _p->parent != NULL)
					_p = _p->parent;
				_p = _p->parent;
			}
		};
};
}

#endif //BIDIRECTIONAL_ITERATOR_HPP