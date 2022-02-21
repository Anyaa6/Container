/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   metafunctions.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariane <ariane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 09:55:30 by ariane            #+#    #+#             */
/*   Updated: 2022/02/18 12:33:15 by ariane           ###   ########.fr       */
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

template <typename T, bool Small = (sizeof(T) == 1)>
struct is_small : false_type {};

template <typename T>
struct is_small<T, true> : true_type {};

template <bool Cond>
struct enable_if {};

template <>
struct enable_if<true>
{
	typedef void type;
};

/*
technique as with is_small2: the primary template will always “return” false_type, the specialization will “return” true_type but will be disabled unless all the requirements are met.
*/

template <typename T, typename /*U*/ = void>
struct is_small2 : false_type {};

template <typename T>
struct is_small2<T, typename enable_if<sizeof(T) == 1>::type> : true_type {};

/*
The primary template has two parameters. The second one has a default “value”, so the users will not know it is there. I also do not need to know it, so I do not even give it a name. The only reason I need 2nd parameter is for the specialization with one parameter T to be more specialized than the primary template, and in the specialization to have a placeholder where to put a type-or-error generated from enable_if_t.

The specialization takes any T and is always more specialized, and it always gets chosen… as long as it is correct. But we know that when the condition we check, sizeof(T) == 1, is false, enable_if_t will be a type-system error. But this is one of these special places where creating a type-system error while instantiating a template is not a compiler error. Or, to put it in other words, template argument substitution failure is not an error (which is abbreviated to SFINAE).

This means that when I instantiate template is_small2 with type int, the specialization is considered, but because substituting int for T fails (enable_if_t<sizeof(T) == 1> would be a type-system error), compiler simply concludes that this specialization will not work, and just goes with the primary template (which, unlike the specialization, derives from false_type).
*/

template <typename >
struct void_t_impl
{
	typedef void type;
};



}

#endif //METAFUNCTIONS_HPP