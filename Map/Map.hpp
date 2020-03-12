/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcadet <cadet.florian@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 12:21:56 by fcadet            #+#    #+#             */
/*   Updated: 2020/03/13 00:06:13 by fcadet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

#include "../Iter/IterTypes.hpp"
#include "../Iter/MapIter.hpp"
#include "../Iter/RevIter.hpp"
#include "MapNode.hpp"
#include <functional>
#include <memory>

#include <iostream>

namespace	ft {

template <class Key, class T, class Compare = std::less<Key>,
	class Alloc = std::allocator<std::pair<const Key, T> > >
class	Map
{
	public:
		//Member types :
		typedef Key														key_type;
		typedef T														mapped_type;
		typedef std::pair<const key_type, mapped_type>					value_type;
		typedef Compare													key_compare;
		class															value_compare;
		typedef Alloc													allocator_type;
		typedef typename allocator_type::reference						reference;
		typedef typename allocator_type::const_reference				const_reference;
		typedef typename allocator_type::pointer						pointer;
		typedef typename allocator_type::const_pointer					const_pointer;
		typedef MapIter<bidirectional_iterator_tag, value_type>			iterator;
		typedef MapIter<bidirectional_iterator_tag, const value_type>	const_iterator;
		typedef RevIter<iterator>										reverse_iterator;
		typedef RevIter<const_iterator>									const_reverse_iterator;
		typedef ptrdiff_t												difference_type;
		typedef size_t													size_type;

		//Constructors, destructor and assignation :
		explicit Map(const key_compare &comp = key_compare(),
			const allocator_type &alloc = allocator_type());
		template <class InputIterator>
		Map(InputIterator first, InputIterator last,
			const key_compare &comp = key_compare(),
			const allocator_type &alloc = allocator_type());
		Map(const Map &m);
		~Map(void);
		Map					&operator=(const Map &l);

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
		mapped_type				&operator[](const key_type &k);

/*
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
		void					swap(Map &x);
		void					resize(size_type n, value_type val = value_type());
		void					clear();

		//Operations :
		void					splice(iterator position, Map &x);
		void					splice(iterator position, Map &x, iterator i);
		void					splice(iterator pos, Map &x, iterator fst, iterator lst);
		void					remove(const value_type &val);
		template <class Predicate>
		void					remove_if(Predicate pred);
		void					unique();
		template <class BinaryPredicate>
		void					unique(BinaryPredicate binary_pred);
		void					merge(Map &x);
		template <class Compare>
		void					merge(Map &x, Compare comp);
		void					sort();
		template <class Compare>
		void					sort(Compare comp);
		void					reverse();
	
		//Non member functions :
		template <class T2, class Alloc2>
		friend bool	operator==(const Map<T2, Alloc2> &lhs, const Map<T2, Alloc2> &rhs);
		template <class T2, class Alloc2>
		friend bool	operator!=(const Map<T2, Alloc2> &lhs, const Map<T2, Alloc2> &rhs);
		template <class T2, class Alloc2>
		friend bool	operator<(const Map<T2, Alloc2> &lhs, const Map<T2, Alloc2> &rhs);
		template <class T2, class Alloc2>
		friend bool	operator<=(const Map<T2, Alloc2> &lhs, const Map<T2, Alloc2> &rhs);
		template <class T2, class Alloc2>
		friend bool	operator>(const Map<T2, Alloc2> &lhs, const Map<T2, Alloc2> &rhs);
		template <class T2, class Alloc2>
		friend bool	operator>=(const Map<T2, Alloc2> &lhs, const Map<T2, Alloc2> &rhs);
		template <class T2, class Alloc2>
		friend void	swap(Map<T2, Alloc2> &x, Map<T2, Alloc2> &y);

*/
	private:
		//Attibutes :
		allocator_type			_alloc;
		key_compare				_comp;
		MapNode<value_type>		_root;
		MapNode<value_type>		_front;
		MapNode<value_type>		_back;
		size_type				_size;

		//Utils :
		void					rec_insert(const value_type *n);
		/*
		static bool				_equal(const_reference val, const_reference val2);
		static bool				_less(const_reference val, const_reference val2);
		void					_swap_it(iterator &it1, iterator &it2);
*/
};

template <class Key, class T, class Compare, class Alloc>
class	Map<Key, T, Compare, Alloc>::value_compare :
	public std::binary_function<value_type, value_type, bool>
{
	friend class	Map;

	public:
		typedef bool		result_type;
		typedef value_type	first_argument_type;
		typedef value_type	second_argument_type;
		bool	operator()(const value_type &x, const value_type &y) const
		{
			return comp(x.first, y.first);
		}
	protected:
		Compare comp;
		value_compare(Compare c) : comp(c) {}
};

template <class Key, class T, class Compare, class Alloc>
Map<Key, T, Compare, Alloc>::Map(const key_compare &comp, const allocator_type &alloc) :
	_alloc(alloc), _comp(comp), _root(), _front(), _back(), _size(0)
{
	_root.left = &_front;
	_root.right = &_back;
	_front.up = &_root;
	_back.up = &_root;
}

template <class Key, class T, class Compare, class Alloc>
template <class InputIterator>
Map<Key, T, Compare, Alloc>::Map(InputIterator first, InputIterator last,
	const key_compare &comp, const allocator_type &alloc) :
	_alloc(alloc), _comp(comp), _root(), _front(), _back(), _size(0)
{
	for (; first != last; ++first)
		insert(*first);
}

template <class Key, class T, class Compare, class Alloc>
void
Map<Key, T, Compare, Alloc>::rec_insert(const value_type *n)
{
	if (!n || !n->valptr)
		return ;
	insert(*(n->valptr));
	rec_insert(n->left);
	rec_insert(n->right);
}

template <class Key, class T, class Compare, class Alloc>
Map<Key, T, Compare, Alloc>::Map(const Map &m) : _alloc(m._alloc), _comp(m.comp),
	_root(), _front(), _back(), _size(0)
{
	rec_insert(&m._root);
}

template <class Key, class T, class Compare, class Alloc>
Map<Key, T, Compare, Alloc>::~Map(void)
{
	clear();
}

template <class Key, class T, class Compare, class Alloc>
Map<Key, T, Compare, Alloc>
&Map<Key, T, Compare, Alloc>::operator=(const Map &m)
{
	if (&m == this)
		return (*this);
	clear();
	rec_insert(&m.root);
	return (*this);
}

template <class Key, class T, class Compare, class Alloc>
typename Map<Key, T, Compare, Alloc>::iterator
Map<Key, T, Compare, Alloc>::begin(void)
{
	return (Map<Key, T, Compare, Alloc>::iterator(_front.up));
}

template <class Key, class T, class Compare, class Alloc>
typename Map<Key, T, Compare, Alloc>::const_iterator
Map<Key, T, Compare, Alloc>::begin(void) const
{
	return (Map<Key, T, Compare, Alloc>::
		const_iterator(reinterpret_cast<MapNode<const value_type> *>(_front.up)));
}

template <class Key, class T, class Compare, class Alloc>
typename Map<Key, T, Compare, Alloc>::iterator
Map<Key, T, Compare, Alloc>::end(void)
{
	return (Map<Key, T, Compare, Alloc>::iterator(&_back));
}

template <class Key, class T, class Compare, class Alloc>
typename Map<Key, T, Compare, Alloc>::const_iterator
Map<Key, T, Compare, Alloc>::end(void) const
{
	return (Map<Key, T, Compare, Alloc>::
		const_iterator(reinterpret_cast<MapNode<const value_type> *>(_back.up->right)));
}

template <class Key, class T, class Compare, class Alloc>
typename Map<Key, T, Compare, Alloc>::reverse_iterator
Map<Key, T, Compare, Alloc>::rbegin(void)
{
	return (Map<Key, T, Compare, Alloc>::reverse_iterator(end()));
}

template <class Key, class T, class Compare, class Alloc>
typename Map<Key, T, Compare, Alloc>::const_reverse_iterator
Map<Key, T, Compare, Alloc>::rbegin(void) const
{
	return (Map<Key, T, Compare, Alloc>::const_reverse_iterator(end()));
}

template <class Key, class T, class Compare, class Alloc>
typename Map<Key, T, Compare, Alloc>::reverse_iterator
Map<Key, T, Compare, Alloc>::rend(void)
{
	return (Map<Key, T, Compare, Alloc>::reverse_iterator(begin()));
}

template <class Key, class T, class Compare, class Alloc>
typename Map<Key, T, Compare, Alloc>::const_reverse_iterator
Map<Key, T, Compare, Alloc>::rend(void) const
{
	return (Map<Key, T, Compare, Alloc>::const_reverse_iterator(begin()));
}

template <class Key, class T, class Compare, class Alloc>
bool
Map<Key, T, Compare, Alloc>::empty() const
{
	return (_size ? false : true);
}

template <class Key, class T, class Compare, class Alloc>
typename Map<Key, T, Compare, Alloc>::size_type
Map<Key, T, Compare, Alloc>::size() const
{
	return (_size);
}

template <class Key, class T, class Compare, class Alloc>
typename Map<Key, T, Compare, Alloc>::size_type
Map<Key, T, Compare, Alloc>::max_size() const
{
	return (std::allocator<MapNode<value_type> >().max_size() + _size);
}

template <class Key, class T, class Compare, class Alloc>
typename Map<Key, T, Compare, Alloc>::mapped_type
&Map<Key, T, Compare, Alloc>::operator[](const key_type &k)
{
	return ((*((this->insert(make_pair(k, mapped_type()))).first)).second);
}

/*
template <class T, class Alloc>
template <class InputIterator>
void
Map<T, Alloc>::assign(InputIterator first, InputIterator last)
{
	clear();
	for (; first != last; ++first)
		push_back(*first);
}

template <class T, class Alloc>
void
Map<T, Alloc>::assign(size_type n, const value_type &val)
{
	clear();
	while (n--)
		push_back(val);
}

template <class T, class Alloc>
void
Map<T, Alloc>::push_front(const value_type &val)
{
	insert(begin(), val);
}

template <class T, class Alloc>
void
Map<T, Alloc>::pop_front()
{
	erase(begin());
}

template <class T, class Alloc>
void
Map<T, Alloc>::push_back(const value_type &val)
{
	insert(end(), val);
}

template <class T, class Alloc>
void
Map<T, Alloc>::pop_back()
{
	iterator	it = end();

	erase(--it);
}

template <class T, class Alloc>
typename Map<T, Alloc>::iterator
Map<T, Alloc>::insert(iterator it, const value_type &val)
{
	MapNode<T>	*new_node = new MapNode<T>(val);

	new_node->next = it.node;
	new_node->prev = it.node->prev;
	it.node->prev->next = new_node;
	it.node->prev = new_node;
	_size++;
	return (--it);
}

template <class T, class Alloc>
void
Map<T, Alloc>::insert(iterator it, size_type n, const value_type &val)
{
	while (n--)
		insert(it, val);
}

template <class T, class Alloc>
template <class InputIterator>
void
Map<T, Alloc>::insert(iterator it, InputIterator fst, InputIterator lst)
{
	for (; fst != lst; ++fst)
		insert(it, *fst);
}

template <class T, class Alloc>
typename Map<T, Alloc>::iterator
Map<T, Alloc>::erase(iterator position)
{
	MapNode<T> *tmp = position.node;

	++position;
	tmp->prev->next = tmp->next;
	tmp->next->prev = tmp->prev;
	delete tmp;
	_size--;
	return (position);
}

template <class T, class Alloc>
typename Map<T, Alloc>::iterator
Map<T, Alloc>::erase(iterator first, iterator last)
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
Map<T, Alloc>::swap(Map &x)
{
	MapNode<T>					*fst = _front.next;
	MapNode<T>					*lst = _back.prev;
	Map<T, Alloc>::size_type	tmp = _size;

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
Map<T, Alloc>::resize(size_type n, value_type val)
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
Map<T, Alloc>::clear()
{
	while (_size)
		pop_back();
}

template <class T, class Alloc>
void
Map<T, Alloc>::splice(iterator position, Map<T, Alloc> &x)
{
	splice(position, x, x.begin(), x.end());
}

template <class T, class Alloc>
void
Map<T, Alloc>::splice(iterator position, Map<T, Alloc> &x, iterator i)
{
	i.node->prev->next = i.node->next;
	i.node->next->prev = i.node->prev;
	--(x._size);
	position.node->prev->next = i.node;
	i.node->prev = position.node->prev;
	position.node->prev = i.node;
	i.node->next = position.node;
	++_size;
}

template <class T, class Alloc>
void
Map<T, Alloc>::splice(iterator position, Map<T, Alloc> &x, iterator fst, iterator lst)
{
	Map<T, Alloc>::iterator	tmp(fst);

	for (; fst != lst; fst = tmp)
	{
		tmp++;
		splice(position, x, fst);
	}
}

template <class T, class Alloc>
void
Map<T, Alloc>::remove(const value_type &val)
{
	Map<T, Alloc>::iterator tmp;

	for (Map<T, Alloc>::iterator it(begin()); (tmp = it++) != end(); )
		if (*tmp == val)
			erase(tmp);
}

template <class T, class Alloc>
template <class Predicate>
void
Map<T, Alloc>::remove_if(Predicate pred)
{
	Map<T, Alloc>::iterator	tmp;

	for (Map<T, Alloc>::iterator it(begin()); (tmp = it++) != end(); )
		if (pred(*tmp))
			erase(tmp);
}

template <class T, class Alloc>
void
Map<T, Alloc>::unique(void)
{
	unique(_equal);
}

template <class T, class Alloc>
template <class BinaryPredicate>
void
Map<T, Alloc>::unique(BinaryPredicate binary_pred)
{
	Map<T, Alloc>::iterator	it(begin());
	Map<T, Alloc>::iterator	tmp;
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
Map<T, Alloc>::merge(Map &x)
{
	merge(x, _less);
}

template <class T, class Alloc>
template <class Compare>
void
Map<T, Alloc>::merge(Map &x, Compare comp)
{
	Map<T, Alloc>::iterator	tmp;
	Map<T, Alloc>::iterator	to(begin());

	if (&x == this)
		return ;
	for (Map<T, Alloc>::iterator from(x.begin()); (tmp = from++) != x.end(); )
	{
		while (to != end() && !comp(*tmp, *to))
			++to;
		tmp.node->prev->next = tmp.node->next;
		tmp.node->next->prev = tmp.node->prev;
		tmp.node->prev = to.node->prev;
		tmp.node->next = to.node;
		to.node->prev->next = tmp.node;
		to.node->prev = tmp.node;
		--(x._size);
		_size++;
	}
}

template <class T, class Alloc>
void
Map<T, Alloc>::sort(void)
{
	sort(_less);
}

template <class T, class Alloc>
template <class Compare>
void
Map<T, Alloc>::sort(Compare comp)
{
	Map<T, Alloc>::iterator it1;
	Map<T, Alloc>::iterator it2;
	bool	sorted = false;

	while (!sorted)
	{
		sorted = true;
		for (it2 = begin(), it1 = it2++; it2 != end(); ++it1, ++it2)
		{
			if (comp(*it2, *it1))
			{
				sorted = false;
				it1.node->prev->next = it2.node;
				it2.node->next->prev = it1.node;
				it1.node->next = it2.node->next;
				it2.node->prev = it1.node->prev;
				it1.node->prev = it2.node;
				it2.node->next = it1.node;
				_swap_it(it1, it2);
			}
		}
	}
}

template <class T, class Alloc>
void
Map<T, Alloc>::reverse(void)
{
	Map<T, Alloc>::iterator	it_beg(begin());
	Map<T, Alloc>::iterator	it_end(end());
	MapNode<T>					*tmp_next;
	MapNode<T>					*tmp_prev;
	
	for (; it_beg != it_end-- && it_beg != it_end; ++it_beg)
	{
		it_beg.node->prev->next = it_end.node;
		it_end.node->next->prev = it_beg.node;
		if (it_beg.node->next == it_end.node)
		{
			it_beg.node->next = it_end.node->next;
			it_end.node->prev = it_beg.node->prev;
			it_beg.node->prev = it_end.node;
			it_end.node->next = it_beg.node;
		}
		else
		{
			it_beg.node->next->prev = it_end.node;
			it_end.node->prev->next = it_beg.node;
			tmp_next = it_beg.node->next;
			tmp_prev = it_beg.node->prev;
			it_beg.node->next = it_end.node->next;
			it_beg.node->prev = it_end.node->prev;
			it_end.node->next = tmp_next;
			it_end.node->prev = tmp_prev;
		}
		_swap_it(it_beg, it_end);
	}
}

template <class T, class Alloc>
bool
operator==(const Map<T, Alloc> &lhs, const Map<T, Alloc> &rhs)
{
	typename Map<T, Alloc>::const_iterator		lhs_it(lhs.begin());
	typename Map<T, Alloc>::const_iterator		rhs_it(rhs.begin());

	if (lhs._size != rhs._size)
		return (false);
	for (; lhs_it != lhs.end(); ++lhs_it, ++rhs_it)
		if (*lhs_it != *rhs_it)
			return (false);
	return (true);
}

template <class T, class Alloc>
bool
operator!=(const Map<T, Alloc> &lhs, const Map<T, Alloc> &rhs)
{
	return (!(lhs == rhs));
}

template <class T, class Alloc>
bool
operator<(const Map<T, Alloc> &lhs, const Map<T, Alloc> &rhs)
{
	typename Map<T, Alloc>::const_iterator		lhs_it(lhs.begin());
	typename Map<T, Alloc>::const_iterator		rhs_it(rhs.begin());

	for (; rhs_it != rhs.end(); ++lhs_it, ++rhs_it)
	{
		if (lhs_it == lhs.end() || *lhs_it < *rhs_it)
			return (true);
	}
	return (false);
}

template <class T, class Alloc>
bool
operator<=(const Map<T, Alloc> &lhs, const Map<T, Alloc> &rhs)
{
	return (!(lhs > rhs));
}

template <class T, class Alloc>
bool
operator>(const Map<T, Alloc> &lhs, const Map<T, Alloc> &rhs)
{
	return (rhs < lhs);
}

template <class T, class Alloc>
bool
operator>=(const Map<T, Alloc> &lhs, const Map<T, Alloc> &rhs)
{
	return (!(lhs < rhs));
}

template <class T, class Alloc>
void
swap(Map<T,Alloc> &x, Map<T,Alloc> &y)
{
	x.swap(y);
}

template <class T, class Alloc>
bool
Map<T, Alloc>::_equal(const_reference val1, const_reference val2)
{
	return (val1 == val2);
}

template <class T, class Alloc>
bool
Map<T, Alloc>::_less(const_reference val1, const_reference val2)
{
	return (val1 < val2);
}

template <class T, class Alloc>
void
Map<T, Alloc>::_swap_it(Map<T, Alloc>::iterator &it1, Map<T, Alloc>::iterator &it2)
{
	Map<T, Alloc>::iterator	tmp;

	tmp = it1;
	it1 = it2;
	it2 = tmp;
}
*/

}

#endif //MAP_HPP
