/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   List.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcadet <cadet.florian@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 12:21:56 by fcadet            #+#    #+#             */
/*   Updated: 2020/03/17 20:33:51 by fcadet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_HPP
# define LIST_HPP

# include "../Iter/IterTypes.hpp"
# include "../Iter/ListIter.hpp"
# include "../Iter/RevIter.hpp"
# include <memory>

namespace	ft
{

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
		typedef size_t											size_type;

		//Constructors, destructor and assignation :
		explicit List(const allocator_type &alloc = allocator_type());
		explicit List(size_type n, const value_type &val = value_type(),
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
		template <class T2, class Alloc2>
		friend bool	operator==(const List<T2, Alloc2> &lhs, const List<T2, Alloc2> &rhs);
		template <class T2, class Alloc2>
		friend bool	operator!=(const List<T2, Alloc2> &lhs, const List<T2, Alloc2> &rhs);
		template <class T2, class Alloc2>
		friend bool	operator<(const List<T2, Alloc2> &lhs, const List<T2, Alloc2> &rhs);
		template <class T2, class Alloc2>
		friend bool	operator<=(const List<T2, Alloc2> &lhs, const List<T2, Alloc2> &rhs);
		template <class T2, class Alloc2>
		friend bool	operator>(const List<T2, Alloc2> &lhs, const List<T2, Alloc2> &rhs);
		template <class T2, class Alloc2>
		friend bool	operator>=(const List<T2, Alloc2> &lhs, const List<T2, Alloc2> &rhs);
		template <class T2, class Alloc2>
		friend void	swap(List<T2, Alloc2> &x, List<T2, Alloc2> &y);

	private:
		//Attibutes :
		allocator_type	_alloc;
		ListNode<T>		_front;
		ListNode<T>		_back;
		size_type		_size;

		//Utils :
		static bool				_equal(const_reference val, const_reference val2);
		static bool				_less(const_reference val, const_reference val2);
		void					_swap_it(iterator &it1, iterator &it2);
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
	return (List<T, Alloc>::const_iterator(reinterpret_cast<ListNode<const T>*>
		(_front.next)));
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
	return (List<T, Alloc>::const_iterator(reinterpret_cast<ListNode<const T>*>
		(_back.prev->next)));
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
	return (std::allocator<ListNode<T> >().max_size() + _size);
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
List<T, Alloc>::assign(size_type n, const value_type &val)
{
	clear();
	while (n--)
		push_back(val);
}

template <class T, class Alloc>
void
List<T, Alloc>::push_front(const value_type &val)
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
List<T, Alloc>::push_back(const value_type &val)
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
List<T, Alloc>::insert(iterator it, const value_type &val)
{
	ListNode<T>	*new__node = new ListNode<T>(val);

	new__node->next = it._node;
	new__node->prev = it._node->prev;
	it._node->prev->next = new__node;
	it._node->prev = new__node;
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
	ListNode<T> *tmp = position._node;

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
List<T, Alloc>::swap(List &x)
{
	ListNode<T>					*fst = _front.next;
	ListNode<T>					*lst = _back.prev;
	List<T, Alloc>::size_type	tmp = _size;

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

template <class T, class Alloc>
void
List<T, Alloc>::splice(iterator position, List<T, Alloc> &x)
{
	splice(position, x, x.begin(), x.end());
}

template <class T, class Alloc>
void
List<T, Alloc>::splice(iterator position, List<T, Alloc> &x, iterator i)
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

template <class T, class Alloc>
void
List<T, Alloc>::splice(iterator position, List<T, Alloc> &x, iterator fst, iterator lst)
{
	List<T, Alloc>::iterator	tmp(fst);

	for (; fst != lst; fst = tmp)
	{
		tmp++;
		splice(position, x, fst);
	}
}

template <class T, class Alloc>
void
List<T, Alloc>::remove(const value_type &val)
{
	List<T, Alloc>::iterator tmp;

	for (List<T, Alloc>::iterator it(begin()); (tmp = it++) != end(); )
		if (*tmp == val)
			erase(tmp);
}

template <class T, class Alloc>
template <class Predicate>
void
List<T, Alloc>::remove_if(Predicate pred)
{
	List<T, Alloc>::iterator	tmp;

	for (List<T, Alloc>::iterator it(begin()); (tmp = it++) != end(); )
		if (pred(*tmp))
			erase(tmp);
}

template <class T, class Alloc>
void
List<T, Alloc>::unique(void)
{
	unique(_equal);
}

template <class T, class Alloc>
template <class BinaryPredicate>
void
List<T, Alloc>::unique(BinaryPredicate binary_pred)
{
	List<T, Alloc>::iterator	it(begin());
	List<T, Alloc>::iterator	tmp;
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

template <class T, class Alloc>
void
List<T, Alloc>::merge(List &x)
{
	merge(x, _less);
}

template <class T, class Alloc>
template <class Compare>
void
List<T, Alloc>::merge(List &x, Compare comp)
{
	List<T, Alloc>::iterator	tmp;
	List<T, Alloc>::iterator	to(begin());

	if (&x == this)
		return ;
	for (List<T, Alloc>::iterator from(x.begin()); (tmp = from++) != x.end(); )
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

template <class T, class Alloc>
void
List<T, Alloc>::sort(void)
{
	sort(_less);
}

template <class T, class Alloc>
template <class Compare>
void
List<T, Alloc>::sort(Compare comp)
{
	List<T, Alloc>::iterator it1;
	List<T, Alloc>::iterator it2;
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

template <class T, class Alloc>
void
List<T, Alloc>::reverse(void)
{
	List<T, Alloc>::iterator	it_beg(begin());
	List<T, Alloc>::iterator	it_end(end());
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

template <class T, class Alloc>
bool
operator==(const List<T, Alloc> &lhs, const List<T, Alloc> &rhs)
{
	typename List<T, Alloc>::const_iterator		lhs_it(lhs.begin());
	typename List<T, Alloc>::const_iterator		rhs_it(rhs.begin());

	if (lhs._size != rhs._size)
		return (false);
	for (; lhs_it != lhs.end(); ++lhs_it, ++rhs_it)
		if (*lhs_it != *rhs_it)
			return (false);
	return (true);
}

template <class T, class Alloc>
bool
operator!=(const List<T, Alloc> &lhs, const List<T, Alloc> &rhs)
{
	return (!(lhs == rhs));
}

template <class T, class Alloc>
bool
operator<(const List<T, Alloc> &lhs, const List<T, Alloc> &rhs)
{
	typename List<T, Alloc>::const_iterator		lhs_it(lhs.begin());
	typename List<T, Alloc>::const_iterator		rhs_it(rhs.begin());

	for (; rhs_it != rhs.end(); ++lhs_it, ++rhs_it)
	{
		if (lhs_it == lhs.end() || *lhs_it < *rhs_it)
			return (true);
	}
	return (false);
}

template <class T, class Alloc>
bool
operator<=(const List<T, Alloc> &lhs, const List<T, Alloc> &rhs)
{
	return (!(lhs > rhs));
}

template <class T, class Alloc>
bool
operator>(const List<T, Alloc> &lhs, const List<T, Alloc> &rhs)
{
	return (rhs < lhs);
}

template <class T, class Alloc>
bool
operator>=(const List<T, Alloc> &lhs, const List<T, Alloc> &rhs)
{
	return (!(lhs < rhs));
}

template <class T, class Alloc>
void
swap(List<T,Alloc> &x, List<T,Alloc> &y)
{
	x.swap(y);
}

template <class T, class Alloc>
bool
List<T, Alloc>::_equal(const_reference val1, const_reference val2)
{
	return (val1 == val2);
}

template <class T, class Alloc>
bool
List<T, Alloc>::_less(const_reference val1, const_reference val2)
{
	return (val1 < val2);
}

template <class T, class Alloc>
void
List<T, Alloc>::_swap_it(List<T, Alloc>::iterator &it1, List<T, Alloc>::iterator &it2)
{
	List<T, Alloc>::iterator	tmp;

	tmp = it1;
	it1 = it2;
	it2 = tmp;
}

}

#endif //LIST_HPP
