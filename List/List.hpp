/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   List.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcadet <cadet.florian@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 12:21:56 by fcadet            #+#    #+#             */
/*   Updated: 2020/03/18 14:58:24 by fcadet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_HPP
# define LIST_HPP

# include "../Iter/IterTypes.hpp"
# include "../Iter/ListIter.hpp"
# include "../Iter/RevIter.hpp"
# include <memory>
# include <cmath>

namespace	ft
{

template <class T>
class	List
{
	public:
		//Member types :
		typedef T												value_type;
		typedef T&												reference;
		typedef const T&										const_reference;
		typedef T*												pointer;
		typedef const T*										const_pointer;
		typedef ListIter<bidirectional_iterator_tag, T>			iterator;
		typedef ListIter<bidirectional_iterator_tag, const T>	const_iterator;
		typedef RevIter<iterator>								reverse_iterator;
		typedef RevIter<const_iterator>							const_reverse_iterator;
		typedef ptrdiff_t										difference_type;
		typedef size_t											size_type;

		//Constructors, destructor and assignation :
		explicit List(void);
		explicit List(size_type n, const value_type &val = value_type());
		template <class InputIterator>
		List(InputIterator first, InputIterator last);
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
		void					assign(size_type n, const value_type &val);
		void					push_front(const value_type &val);
		void					pop_front();
		void					push_back(const value_type &val);
		void					pop_back();
		iterator				insert(iterator it, const value_type &val);
		void					insert(iterator it, size_type n, const value_type &val);
		template <class InputIterator>
		void					insert(iterator it, InputIterator fst, InputIterator lst);
		iterator				erase(iterator position);
		iterator				erase(iterator first, iterator last);
		void					swap(List &x);
		void					resize(size_type n, value_type val = value_type());
		void					clear();

		//Operations :
		void					splice(iterator position, List &x);
		void					splice(iterator position, List &x, iterator i);
		void					splice(iterator pos, List &x, iterator fst, iterator lst);
		void					remove(const value_type &val);
		template <class Predicate>
		void					remove_if(Predicate pred);
		void					unique();
		template <class BinaryPredicate>
		void					unique(BinaryPredicate binary_pred);
		void					merge(List &x);
		template <class Compare>
		void					merge(List &x, Compare comp);
		void					sort();
		template <class Compare>
		void					sort(Compare comp);
		void					reverse();
	
		//Non member functions :
		template <class T2>
		friend bool	operator==(const List<T2> &lhs, const List<T2> &rhs);
		template <class T2>
		friend bool	operator!=(const List<T2> &lhs, const List<T2> &rhs);
		template <class T2>
		friend bool	operator<(const List<T2> &lhs, const List<T2> &rhs);
		template <class T2>
		friend bool	operator<=(const List<T2> &lhs, const List<T2> &rhs);
		template <class T2>
		friend bool	operator>(const List<T2> &lhs, const List<T2> &rhs);
		template <class T2>
		friend bool	operator>=(const List<T2> &lhs, const List<T2> &rhs);
		template <class T2>
		friend void	swap(List<T2> &x, List<T2> &y);

	private:
		//Attibutes :
		ListNode<T>		_front;
		ListNode<T>		_back;
		size_type		_size;

		//Utils :
		static bool				_equal(const_reference val, const_reference val2);
		static bool				_less(const_reference val, const_reference val2);
		void					_swap_it(iterator &it1, iterator &it2);
};

template <class T>
List<T>::List(void) : _front(), _back(), _size(0)
{
	_back.prev = &_front;
	_front.next = &_back;
}

template <class T>
List<T>::List(size_type n, const value_type &val) : _front(), _back(), _size(0)
{
	_back.prev = &_front;
	_front.next = &_back;
	assign(n, val);
}

template <class T>
template <class InputIterator>
List<T>::List(InputIterator first, InputIterator last) : _front(), _back(), _size(0)
{
	_back.prev = &_front;
	_front.next = &_back;
	assign(first, last);
}

template <class T>
List<T>::List(const List &l) : _front(), _back(), _size(0)
{
	_back.prev = &_front;
	_front.next = &_back;
	assign(l.begin(), l.end());
}

template <class T>
List<T>::~List(void)
{
	clear();
}

template <class T>
List<T>
&List<T>::operator=(const List &l)
{
	if (&l == this)
		return (*this);
	assign(l.begin(), l.end());
	return (*this);
}

template <class T>
typename List<T>::iterator
List<T>::begin(void)
{
	return (List<T>::iterator(_front.next));
}

template <class T>
typename List<T>::const_iterator
List<T>::begin(void) const
{
	return (List<T>::const_iterator(reinterpret_cast<ListNode<const T>*>
		(_front.next)));
}

template <class T>
typename List<T>::iterator
List<T>::end(void)
{
	return (List<T>::iterator(&_back));
}

template <class T>
typename List<T>::const_iterator
List<T>::end(void) const
{
	return (List<T>::const_iterator(reinterpret_cast<ListNode<const T>*>
		(_back.prev->next)));
}

template <class T>
typename List<T>::reverse_iterator
List<T>::rbegin(void)
{
	return (List<T>::reverse_iterator(end()));
}

template <class T>
typename List<T>::const_reverse_iterator
List<T>::rbegin(void) const
{
	return (List<T>::const_reverse_iterator(end()));
}

template <class T>
typename List<T>::reverse_iterator
List<T>::rend(void)
{
	return (List<T>::reverse_iterator(begin()));
}

template <class T>
typename List<T>::const_reverse_iterator
List<T>::rend(void) const
{
	return (List<T>::const_reverse_iterator(begin()));
}

template <class T>
bool
List<T>::empty() const
{
	return (_size ? false : true);
}

template <class T>
typename List<T>::size_type
List<T>::size() const
{
	return (_size);
}

template <class T>
typename List<T>::size_type
List<T>::max_size() const
{
	return (powl(2, sizeof(size_type) * 8));
}

template <class T>
typename List<T>::reference
List<T>::front()
{
	return (*begin());
}

template <class T>
typename List<T>::const_reference
List<T>::front() const
{
	return (*begin());
}

template <class T>
typename List<T>::reference
List<T>::back()
{
	return (*rbegin());
}

template <class T>
typename List<T>::const_reference
List<T>::back() const
{
	return (*rbegin());
}

template <class T>
template <class InputIterator>
void
List<T>::assign(InputIterator first, InputIterator last)
{
	clear();
	for (; first != last; ++first)
		push_back(*first);
}

template <class T>
void
List<T>::assign(size_type n, const value_type &val)
{
	clear();
	while (n--)
		push_back(val);
}

template <class T>
void
List<T>::push_front(const value_type &val)
{
	insert(begin(), val);
}

template <class T>
void
List<T>::pop_front()
{
	erase(begin());
}

template <class T>
void
List<T>::push_back(const value_type &val)
{
	insert(end(), val);
}

template <class T>
void
List<T>::pop_back()
{
	iterator	it = end();

	erase(--it);
}

template <class T>
typename List<T>::iterator
List<T>::insert(iterator it, const value_type &val)
{
	ListNode<T>	*new__node = new ListNode<T>(val);

	new__node->next = it._node;
	new__node->prev = it._node->prev;
	it._node->prev->next = new__node;
	it._node->prev = new__node;
	_size++;
	return (--it);
}

template <class T>
void
List<T>::insert(iterator it, size_type n, const value_type &val)
{
	while (n--)
		insert(it, val);
}

template <class T>
template <class InputIterator>
void
List<T>::insert(iterator it, InputIterator fst, InputIterator lst)
{
	for (; fst != lst; ++fst)
		insert(it, *fst);
}

template <class T>
typename List<T>::iterator
List<T>::erase(iterator position)
{
	ListNode<T> *tmp = position._node;

	++position;
	tmp->prev->next = tmp->next;
	tmp->next->prev = tmp->prev;
	delete tmp;
	_size--;
	return (position);
}

template <class T>
typename List<T>::iterator
List<T>::erase(iterator first, iterator last)
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

template <class T>
void
List<T>::swap(List &x)
{
	ListNode<T>					*fst = _front.next;
	ListNode<T>					*lst = _back.prev;
	List<T>::size_type	tmp = _size;

	if (_size)
	{
		_front.next->prev = &x._front;
		_back.prev->next = &x._back;
	}
	if (x._size)
	{
		x._front.next->prev = &_front;
		x._back.prev->next = &_back;
	}
	_front.next = x._size ? x._front.next : &_back;
	_back.prev = x._size ? x._back.prev : &_front;
	x._front.next = _size ? fst : &x._back;
	x._back.prev = _size ? lst : &x._front;
	_size = x._size;
	x._size = tmp;
}

template <class T>
void
List<T>::resize(size_type n, value_type val)
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

template <class T>
void
List<T>::clear()
{
	while (_size)
		pop_back();
}

template <class T>
void
List<T>::splice(iterator position, List<T> &x)
{
	splice(position, x, x.begin(), x.end());
}

template <class T>
void
List<T>::splice(iterator position, List<T> &x, iterator i)
{
	i._node->prev->next = i._node->next;
	i._node->next->prev = i._node->prev;
	--(x._size);
	position._node->prev->next = i._node;
	i._node->prev = position._node->prev;
	position._node->prev = i._node;
	i._node->next = position._node;
	++_size;
}

template <class T>
void
List<T>::splice(iterator position, List<T> &x, iterator fst, iterator lst)
{
	List<T>::iterator	tmp(fst);

	for (; fst != lst; fst = tmp)
	{
		tmp++;
		splice(position, x, fst);
	}
}

template <class T>
void
List<T>::remove(const value_type &val)
{
	List<T>::iterator tmp;

	for (List<T>::iterator it(begin()); (tmp = it++) != end(); )
		if (*tmp == val)
			erase(tmp);
}

template <class T>
template <class Predicate>
void
List<T>::remove_if(Predicate pred)
{
	List<T>::iterator	tmp;

	for (List<T>::iterator it(begin()); (tmp = it++) != end(); )
		if (pred(*tmp))
			erase(tmp);
}

template <class T>
void
List<T>::unique(void)
{
	unique(_equal);
}

template <class T>
template <class BinaryPredicate>
void
List<T>::unique(BinaryPredicate binary_pred)
{
	List<T>::iterator	it(begin());
	List<T>::iterator	tmp;
	T							last;

	if (it != end())
		last = *(it++);
	else
		return ;
	while ((tmp = it++) != end())
	{
		if (binary_pred(*tmp, last))
			erase(tmp);
		else
			last = *tmp;
	}
}

template <class T>
void
List<T>::merge(List &x)
{
	merge(x, _less);
}

template <class T>
template <class Compare>
void
List<T>::merge(List &x, Compare comp)
{
	List<T>::iterator	tmp;
	List<T>::iterator	to(begin());

	if (&x == this)
		return ;
	for (List<T>::iterator from(x.begin()); (tmp = from++) != x.end(); )
	{
		while (to != end() && !comp(*tmp, *to))
			++to;
		tmp._node->prev->next = tmp._node->next;
		tmp._node->next->prev = tmp._node->prev;
		tmp._node->prev = to._node->prev;
		tmp._node->next = to._node;
		to._node->prev->next = tmp._node;
		to._node->prev = tmp._node;
		--(x._size);
		_size++;
	}
}

template <class T>
void
List<T>::sort(void)
{
	sort(_less);
}

template <class T>
template <class Compare>
void
List<T>::sort(Compare comp)
{
	List<T>::iterator it1;
	List<T>::iterator it2;
	bool	sorted = false;

	while (!sorted)
	{
		sorted = true;
		for (it2 = begin(), it1 = it2++; it2 != end(); ++it1, ++it2)
		{
			if (comp(*it2, *it1))
			{
				sorted = false;
				it1._node->prev->next = it2._node;
				it2._node->next->prev = it1._node;
				it1._node->next = it2._node->next;
				it2._node->prev = it1._node->prev;
				it1._node->prev = it2._node;
				it2._node->next = it1._node;
				_swap_it(it1, it2);
			}
		}
	}
}

template <class T>
void
List<T>::reverse(void)
{
	List<T>::iterator	it_beg(begin());
	List<T>::iterator	it_end(end());
	ListNode<T>					*tmp_next;
	ListNode<T>					*tmp_prev;
	
	for (; it_beg != it_end-- && it_beg != it_end; ++it_beg)
	{
		it_beg._node->prev->next = it_end._node;
		it_end._node->next->prev = it_beg._node;
		if (it_beg._node->next == it_end._node)
		{
			it_beg._node->next = it_end._node->next;
			it_end._node->prev = it_beg._node->prev;
			it_beg._node->prev = it_end._node;
			it_end._node->next = it_beg._node;
		}
		else
		{
			it_beg._node->next->prev = it_end._node;
			it_end._node->prev->next = it_beg._node;
			tmp_next = it_beg._node->next;
			tmp_prev = it_beg._node->prev;
			it_beg._node->next = it_end._node->next;
			it_beg._node->prev = it_end._node->prev;
			it_end._node->next = tmp_next;
			it_end._node->prev = tmp_prev;
		}
		_swap_it(it_beg, it_end);
	}
}

template <class T>
bool
operator==(const List<T> &lhs, const List<T> &rhs)
{
	typename List<T>::const_iterator		lhs_it(lhs.begin());
	typename List<T>::const_iterator		rhs_it(rhs.begin());

	if (lhs._size != rhs._size)
		return (false);
	for (; lhs_it != lhs.end(); ++lhs_it, ++rhs_it)
		if (*lhs_it != *rhs_it)
			return (false);
	return (true);
}

template <class T>
bool
operator!=(const List<T> &lhs, const List<T> &rhs)
{
	return (!(lhs == rhs));
}

template <class T>
bool
operator<(const List<T> &lhs, const List<T> &rhs)
{
	typename List<T>::const_iterator		lhs_it(lhs.begin());
	typename List<T>::const_iterator		rhs_it(rhs.begin());

	for (; rhs_it != rhs.end(); ++lhs_it, ++rhs_it)
	{
		if (lhs_it == lhs.end() || *lhs_it < *rhs_it)
			return (true);
	}
	return (false);
}

template <class T>
bool
operator<=(const List<T> &lhs, const List<T> &rhs)
{
	return (!(lhs > rhs));
}

template <class T>
bool
operator>(const List<T> &lhs, const List<T> &rhs)
{
	return (rhs < lhs);
}

template <class T>
bool
operator>=(const List<T> &lhs, const List<T> &rhs)
{
	return (!(lhs < rhs));
}

template <class T>
void
swap(List<T> &x, List<T> &y)
{
	x.swap(y);
}

template <class T>
bool
List<T>::_equal(const_reference val1, const_reference val2)
{
	return (val1 == val2);
}

template <class T>
bool
List<T>::_less(const_reference val1, const_reference val2)
{
	return (val1 < val2);
}

template <class T>
void
List<T>::_swap_it(List<T>::iterator &it1, List<T>::iterator &it2)
{
	List<T>::iterator	tmp;

	tmp = it1;
	it1 = it2;
	it2 = tmp;
}

}

#endif //LIST_HPP
