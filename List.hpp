/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   List.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcadet <cadet.florian@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 12:21:56 by fcadet            #+#    #+#             */
/*   Updated: 2020/03/04 20:11:06 by fcadet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_HPP
# define LIST_HPP

#include "ListIter.hpp"
#include "RevIter.hpp"
#include "IterTypes.hpp"
#include <memory>
#include <cmath>

template <class T, class Alloc = std::allocator<T> >
class	List
{
	public:
		//Member types :
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
		typedef unsigned int									size_type;

		//Constructors, destructor and assignation :
		List(const allocator_type &alloc = allocator_type());
		List(size_type n, const value_type &val = value_type(),
			const allocator_type &alloc = allocator_type());
		template <class InputIterator>
		List(InputIterator first, InputIterator last,
			const allocator_type &alloc = allocator_type());
		List(const List &l);
		~List(void);
		List					&operator=(const List &l);

		//Iterators :
		iterator				begin(void);
		const_iterator			begin(void) const;
		iterator				end(void);
		const_iterator			end(void) const;
		reverse_iterator		rbegin(void);
		const_reverse_iterator	rbegin(void) const;
		reverse_iterator		rend(void);
		const_reverse_iterator	rend(void) const;

		//Capacity :
		bool					empty() const;
		size_type				size() const;
		size_type				max_size() const;

		//Element access :
		reference				front();
		const_reference			front() const;
		reference				back();
		const_reference			back() const;

		//Modifiers :
		template <class InputIterator>
		void					assign(InputIterator first, InputIterator last);
		void					assign(size_type n, const value_type& val);
		void					push_front(const value_type& val);
		void					pop_front();
		void					push_back(const value_type& val);
		void					pop_back();
		iterator				insert(iterator it, const value_type& val);
		void					insert(iterator it, size_type n, const value_type& val);
		template <class InputIterator>
		void					insert(iterator it, InputIterator fst, InputIterator lst);
		iterator				erase(iterator position);
		iterator				erase(iterator first, iterator last);
		void					swap(List& x);
		void					resize(size_type n, value_type val = value_type());
		void					clear();

	private:
		//Attibutes :
		allocator_type	_alloc;
		ListNode<T>		_front;
		ListNode<T>		_back;
		size_type		_size;
};

template <class T, class Alloc>
List<T, Alloc>::List(const allocator_type &alloc) :
	_alloc(alloc), _front(), _back(), _size(0)
{
	_back.prev = &_front;
	_front.next = &_back;
}

template <class T, class Alloc>
List<T, Alloc>::List(size_type n, const value_type &val, const allocator_type &alloc) :
	_alloc(alloc), _front(), _back(), _size(0)
{
	_back.prev = &_front;
	_front.next = &_back;
	assign(n, val);
}

template <class T, class Alloc>
template <class InputIterator>
List<T, Alloc>::List(InputIterator first, InputIterator last, const allocator_type &alloc)
	: _alloc(alloc), _front(), _back(), _size(0)
{
	_back.prev = &_front;
	_front.next = &_back;
	assign(first, last);
}

template <class T, class Alloc>
List<T, Alloc>::List(const List &l) : _alloc(l._alloc), _front(), _back(), _size(0)
{
	_back.prev = &_front;
	_front.next = &_back;
	assign(l.begin(), l.end());
}

template <class T, class Alloc>
List<T, Alloc>::~List(void)
{
	clear();
}

template <class T, class Alloc>
List<T, Alloc>
&List<T, Alloc>::operator=(const List &l)
{
	if (&l == this)
		return (*this);
	assign(l.begin(), l.end());
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
	return (List<T, Alloc>::iterator(&_back));
}

template <class T, class Alloc>
typename List<T, Alloc>::const_iterator
List<T, Alloc>::end(void) const
{
	return (List<T, Alloc>::const_iterator(&_back));
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

template <class T, class Alloc>
bool
List<T, Alloc>::empty() const
{
	return (_size ? false : true);
}

template <class T, class Alloc>
typename List<T, Alloc>::size_type
List<T, Alloc>::size() const
{
	return (_size);
}

template <class T, class Alloc>
typename List<T, Alloc>::size_type
List<T, Alloc>::max_size() const
{
	//peut-etre a changer
	return (pow(2, sizeof(typename List<T, Alloc>::size_type) * 8));
}

template <class T, class Alloc>
typename List<T, Alloc>::reference
List<T, Alloc>::front()
{
	return (*begin());
}

template <class T, class Alloc>
typename List<T, Alloc>::const_reference
List<T, Alloc>::front() const
{
	return (*begin());
}

template <class T, class Alloc>
typename List<T, Alloc>::reference
List<T, Alloc>::back()
{
	return (*rbegin());
}

template <class T, class Alloc>
typename List<T, Alloc>::const_reference
List<T, Alloc>::back() const
{
	return (*rbegin());
}

template <class T, class Alloc>
template <class InputIterator>
void
List<T, Alloc>::assign(InputIterator first, InputIterator last)
{
	clear();
	for (; first != last; ++first)
		push_back(*first);
}

template <class T, class Alloc>
void
List<T, Alloc>::assign(size_type n, const value_type& val)
{
	clear();
	while (n--)
		push_back(val);
}

template <class T, class Alloc>
void
List<T, Alloc>::push_front(const value_type& val)
{
	insert(begin(), val);
}

template <class T, class Alloc>
void
List<T, Alloc>::pop_front()
{
	erase(begin());
}

template <class T, class Alloc>
void
List<T, Alloc>::push_back(const value_type& val)
{
	insert(end(), val);
}

template <class T, class Alloc>
void
List<T, Alloc>::pop_back()
{
	iterator	it = end();

	erase(--it);
}

template <class T, class Alloc>
typename List<T, Alloc>::iterator
List<T, Alloc>::insert(iterator it, const value_type& val)
{
	ListNode<T>	*new_node = new ListNode<T>(val);

	new_node->next = it.node;
	new_node->prev = it.node->prev;
	it.node->prev->next = new_node;
	it.node->prev = new_node;
	_size++;
	return (--it);
}

template <class T, class Alloc>
void
List<T, Alloc>::insert(iterator it, size_type n, const value_type &val)
{
	while (n--)
		insert(it, val);
}

template <class T, class Alloc>
template <class InputIterator>
void
List<T, Alloc>::insert(iterator it, InputIterator fst, InputIterator lst)
{
	for (; fst != lst; ++fst)
		insert(it, *fst);
}

template <class T, class Alloc>
typename List<T, Alloc>::iterator
List<T, Alloc>::erase(iterator position)
{
	ListNode<T> *tmp = position.node;

	++position;
	tmp->prev->next = tmp->next;
	tmp->next->prev = tmp->prev;
	delete tmp;
	_size--;
	return (position);
}

template <class T, class Alloc>
typename List<T, Alloc>::iterator
List<T, Alloc>::erase(iterator first, iterator last)
{
	iterator	second = first;

	while (first != last)
	{
		++second;
		erase(first);
		first = second;
	}
	return (last);
}

template <class T, class Alloc>
void
List<T, Alloc>::swap(List& x)
{
	List<T, Alloc>		tmp(*this);

	*this = x;
	x = tmp;
}

template <class T, class Alloc>
void
List<T, Alloc>::resize(size_type n, value_type val)
{
	if (n < _size)
	{
		for (n = _size - n; n > 0; n--)
			pop_back();		
	}
	else if (n > _size)
	{
		for (n = n - _size; n > 0; n--)
			push_back(val);
	}
}

template <class T, class Alloc>
void
List<T, Alloc>::clear()
{
	while (_size)
		pop_back();
}

#endif //LIST_HPP
