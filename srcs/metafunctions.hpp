/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   metafunctions.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonnel <abonnel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 09:55:30 by ariane            #+#    #+#             */
/*   Updated: 2022/02/21 16:36:33 by abonnel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef METAFUNCTIONS_HPP
#define METAFUNCTIONS_HPP

namespace ft {

struct true_type {
	static const bool value = true;
};

struct false_type {
	static const bool value = false;
};

template <typename T, typename U>
struct is_same : false_type {};

template <typename T>
struct is_same<T, T> : true_type {};

template <bool Cond, class T = void> 
struct enable_if {};

template<class T> 
struct enable_if<true, T> { 
	typedef T type;
};

}

#endif //METAFUNCTIONS_HPP