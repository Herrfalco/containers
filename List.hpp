/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   List.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcadet <cadet.florian@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 12:21:56 by fcadet            #+#    #+#             */
/*   Updated: 2020/03/03 19:04:08 by fcadet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_HPP
# define LIST_HPP

#include "ListIter.hpp"
#include "RevIter.hpp"
#include "IterTypes.hpp"
#include <memory>

template <class T, class Alloc = allocator<T> >
class	List
{
	public:
		typedef T												value_type;
		typedef Alloc											allocator_type;
		typedef allocator_type::reference						reference;
		typedef allocator_type::const_reference					const_reference;
		typedef allocator_type::pointer							pointer;
		typedef allocator_type::const_pointer					const_pointer;
		typedef ListIter<bidirectional_iterator_tag, T>			iterator;
		typedef ListIter<bidirectional_iterator_tag, const T>	const_iterator;
		typedef RevIter<iterator>								reverse_iterator;
		typedef RevIter<const_iterator>							const_reverse_iterator;
		typedef ptrdiff_t										difference_type;
		typedef size_t											size_type;

		List(const allocator_type &alloc = allocator_type());
		List(size_type n, const value_type &val = value_type(),
			const allocator_type &alloc = allocator_type());
		template <class InputIterator>
		List(InputIterator first, InputIterator last,
			const allocator_type &alloc = allocator_type());
		List(const List &l);
		~List(void);
		List		&operator=(const List &l);
		iterator				begin();
		const_iterator			begin() const;
		iterator				end();
		const_iterator			end() const;
		reverse_iterator		rbegin();
		const_revers_iterator	rbeginr() const;
		reverse_iterator		rend();
		const_revers_iterator	rend() const;

	private:
		allocator_type	_alloc;
		ListNode<T>		_front;
		ListNode<T>		_back;
		size_type		_size;
};

template <class T, class Alloc>
List::List(const allocator_type &alloc) : _alloc(alloc), _front(), _back(), _size(0)
{
	_back.prev = _front;
	_front.next = _back;
}

template <class T, class Alloc>
List::List(size_type n, const value_type &val, const allocator_type &alloc)
	_alloc(alloc), _front(), _back(), _size(0)
{
	while (n--)
		push_back(val);
}

template <class InputIterator>
List(InputIterator first, InputIterator last, const allocator_type &alloc)
	_alloc(alloc), _front(), _back(), _size(0)
{
	for (; first != last; ++first)
		push_back(*first);
}

template <class T, class Alloc>
List::List(const List &l) : _alloc(l._alloc), _front(), _back(), _size(0)
{
	_back.prev = _front;
	_front.next = _back;
	for (ListIter<bidirectional_iterator_tag, T> it(l.begin()), it != l.end(), ++it)
		push_back(*it);
}

template <class T, class Alloc>
List::~List(void)
{
	while (_size)
		pop_back();
}

template <class T, class Alloc>
List		&List::operator=(const List &l)
{
	if (&l == this)
		return (*this);
	while (_size)
		pop_back();
	for (ListIter<bidirectional_iterator_tag, T> it(l.begin()), it != l.end(), ++it)
		push_back(*it);	
	return (*this);
}

template <class T, class Alloc>
List::iterator				begin()
{
}

template <class T, class Alloc>
List::const_iterator			begin() const
{
}

template <class T, class Alloc>
iterator				end()
{
}

template <class T, class Alloc>
const_iterator			end() const
{
}

template <class T, class Alloc>
reverse_iterator		rbegin()
{
}

template <class T, class Alloc>
const_revers_iterator	rbeginr() const
{
}

template <class T, class Alloc>
reverse_iterator		rend()
{
}

template <class T, class Alloc>
const_revers_iterator	rend() const
{
}

#endif //LIST_HPP
