/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Less.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcadet <cadet.florian@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/18 19:11:53 by fcadet            #+#    #+#             */
/*   Updated: 2020/03/18 19:32:35 by fcadet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LESS_HPP
# define LESS_HPP

# include "Binary_Function.hpp"

namespace	ft
{

template <class T>
struct	Less : ft::Binary_Function<T, T, bool>
{
	bool	operator()(const T &x, const T &y) const;
};

template <class T>
bool
Less<T>::operator()(const T &x, const T&y) const
{
	return (x < y);
}

}

#endif //LESS_HPP
