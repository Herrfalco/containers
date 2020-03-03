/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   List.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcadet <cadet.florian@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 12:21:56 by fcadet            #+#    #+#             */
/*   Updated: 2020/03/03 19:49:46 by fcadet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_HPP
# define LIST_HPP

#include "ListIter.hpp"
#include "RevIter.hpp"
#include "IterTypes.hpp"
#include <memory>

template <class T, class Alloc = std::allocator<T> >
class	List
{
	public:
		typedef T												value_type;
		typedef Alloc											allocator_type;
		typedef typename allocator_type::reference				reference;
		typedef typename allocator_type::const_reference		const_reference;
		typedef typename allocator_type::pointer				pointer;
		typedef typename allocator_type::const_pointer			const_pointer;
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
		List					&operator=(const List &l);
		iterator				begin(void);
		const_iterator			begin(void) const;
		iterator				end(void);
		const_iterator			end(void) const;
		reverse_iterator		rbegin(void);
		const_reverse_iterator	rbegin(void) const;
		reverse_iterator		rend(void);
		const_reverse_iterator	rend(void) const;

	private:
		allocator_type	_alloc;
		ListNode<T>		_front;
		ListNode<T>		_back;
		size_type		_size;
};

template <class T, class Alloc>
List<T, Alloc>::List(const allocator_type &alloc) :
	_alloc(alloc), _front(), _back(), _size(0)
{
	_back.prev = _front;
	_front.next = _back;
}

template <class T, class Alloc>
List<T, Alloc>::List(size_type n, const value_type &val, const allocator_type &alloc) :
	_alloc(alloc), _front(), _back(), _size(0)
{
	while (n--)
		push_back(val);
}

template <class T, class Alloc>
template <class InputIterator>
List<T, Alloc>::List(InputIterator first, InputIterator last, const allocator_type &alloc)
	: _alloc(alloc), _front(), _back(), _size(0)
{
	for (; first != last; ++first)
		push_back(*first);
}

template <class T, class Alloc>
List<T, Alloc>::List(const List &l) : _alloc(l._alloc), _front(), _back(), _size(0)
{
	_back.prev = _front;
	_front.next = _back;
	for (ListIter<bidirectional_iterator_tag, T> it(l.begin()); it != l.end(); ++it)
		push_back(*it);
}

template <class T, class Alloc>
List<T, Alloc>::~List(void)
{
	while (_size)
		pop_back();
}

template <class T, class Alloc>
List<T, Alloc>
&List<T, Alloc>::operator=(const List &l)
{
	if (&l == this)
		return (*this);
	while (_size)
		pop_back();
	for (ListIter<bidirectional_iterator_tag, T> it(l.begin()); it != l.end(); ++it)
		push_back(*it);	
	return (*this);
}

template <class T, class Alloc>
typename List<T, Alloc>::iterator
List<T, Alloc>::begin(void)
{
	return (List<T, Alloc>::iterator(_front.next));
}

template <class T, class Alloc>
typename List<T, Alloc>::const_iterator
List<T, Alloc>::begin(void) const
{
	return (List<T, Alloc>::const_iterator(_front.next));
}

template <class T, class Alloc>
typename List<T, Alloc>::iterator
List<T, Alloc>::end(void)
{
	return (List<T, Alloc>::iterator(_back));
}

template <class T, class Alloc>
typename List<T, Alloc>::const_iterator
List<T, Alloc>::end(void) const
{
	return (List<T, Alloc>::const_iterator(_back));
}

template <class T, class Alloc>
typename List<T, Alloc>::reverse_iterator
List<T, Alloc>::rbegin(void)
{
	return (List<T, Alloc>::reverse_iterator(end()));
}

template <class T, class Alloc>
typename List<T, Alloc>::const_reverse_iterator
List<T, Alloc>::rbegin(void) const
{
	return (List<T, Alloc>::const_reverse_iterator(end()));
}

template <class T, class Alloc>
typename List<T, Alloc>::reverse_iterator
List<T, Alloc>::rend(void)
{
	return (List<T, Alloc>::reverse_iterator(begin()));
}

template <class T, class Alloc>
typename List<T, Alloc>::const_reverse_iterator
List<T, Alloc>::rend(void) const
{
	return (List<T, Alloc>::const_reverse_iterator(begin()));
}

#endif //LIST_HPP
