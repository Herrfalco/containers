/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   List.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcadet <cadet.florian@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 12:21:56 by fcadet            #+#    #+#             */
/*   Updated: 2020/03/02 19:40:26 by fcadet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_HPP
# define LIST_HPP

#include "ListNode.hpp"
#include "ListIter.hpp"

template <class T, class Alloc = allocator<T>>
class	List
{
	public:
		List(void);
		List(const List &l);
		~List(void);
		List		&operator=(const List &l);

		typedef T												value_type;
		typedef Alloc											allocator_type;
		typedef allocator_type::reference						reference;
		typedef allocator_type::const_reference					const_reference;
		typedef allocator_type::pointer							pointer;
		typedef allocator_type::const_pointer					const_pointer;
		typedef ListIter<bidirectional_iterator_tag, T>			iterator;
		typedef ListIter<bidirectional_iterator_tag, const T>	const_iterator;

	private:
		ListNode<T>	_beg;
		ListNode<T>	_end;
		size_type	_size;
};

template <class T, class Alloc = allocator<T>>
List::List(ListNod *prev, ListNode *next) : _prev(prev), _next(next), _val()
{
}

template <class T, class Alloc = allocator<T>>
List::List(const List &l) : _prev(0), _next(0), _val(l._val)
{
}

template <class T, class Alloc = allocator<T>>
List::~List(void)
{
}

template <class T, class Alloc = allocator<T>>
List		&List::operator=(const List &l)
{
	if (&l == this)
		return (*this);
	return (*this);
}

#endif //LIST_HPP
