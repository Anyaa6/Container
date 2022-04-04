/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonnel <abonnel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 15:17:02 by abonnel           #+#    #+#             */
/*   Updated: 2022/04/01 10:18:06 by abonnel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
#define UTILS_HPP

namespace ft {

template <class InputIterator1, class InputIterator2>
bool equal ( InputIterator1 first1, InputIterator1 last1, InputIterator2 first2 )
{
  for (;first1!=last1; first1++, first2++) {
    if (!(*first1 == *first2))   // or: if (!pred(*first1,*first2)), for version 2
      return false;
  }
  return true;
};

			  
template <class InputIterator1, class InputIterator2, class BinaryPredicate>
bool equal (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, BinaryPredicate pred) {
  while (first1!=last1) {
    if (!pred(*first1,*first2))
      return false;
    ++first1; ++first2;
  }
  return true;
};

template <class InputIterator1, class InputIterator2>
bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2) {
	while (first1!=last1)
	{
		if (first2 == last2 || *first2 < *first1) 
			return false;
		else if (*first1 < *first2)
			return true;
		++first1; ++first2;
	}
	return (first2 != last2);
};

// template <class InputIterator1, class InputIterator2, class Compare>
// bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2, Compare comp) {
// 	while (first1!=last1)
// 	{
// 		if (first2==last2 || *first2<*first1) 
// 			return false;
// 		else if (comp(*first1, *first2))
// 			return true;
// 		++first1; ++first2;
// 	}
// 	return (first2!=last2);
// };

}

#endif //UTILS_HPP