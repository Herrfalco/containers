/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   List.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcadet <cadet.florian@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 12:21:56 by fcadet            #+#    #+#             */
/*   Updated: 2020/03/01 16:59:41 by fcadet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "List.hpp"

List::List(ListNod *prev, ListNode *next) : _prev(prev), _next(next), _val()
{
}

List::List(const List &l) : _prev(0), _next(0), _val(l._val)
{
}

List::~List(void)
{
}

List		&List::operator=(const List &l)
{
	if (&l == this)
		return (*this);
	return (*this);
}
