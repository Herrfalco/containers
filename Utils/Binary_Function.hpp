/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Binary_Function.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcadet <cadet.florian@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/18 19:18:14 by fcadet            #+#    #+#             */
/*   Updated: 2020/03/18 19:20:21 by fcadet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BINARY_FUNCTION_HPP
# define BINARY_FUNCTION_HPP

namespace	ft
{

template <class Arg1, class Arg2, class Result>
struct	Binary_Function
{
	typedef Arg1	first_argument_type;
	typedef Arg2	second_argument_type;
	typedef Result	result_type;
};

}

#endif //BINARY_FUNCTION_HPP
