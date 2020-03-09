/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcadet <cadet.florian@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 12:21:56 by fcadet            #+#    #+#             */
/*   Updated: 2020/03/09 20:38:11 by fcadet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

#include "IterTypes.hpp"
#include "VectorIter.hpp"
#include "RevIter.hpp"
#include <memory>
#include <cmath>

#include <iostream>

namespace	ft {

template <class T, class Alloc = std::allocator<T> >
class	Vector
{
	public:
		//Member types :
		typedef T												value_type;
		typedef Alloc											allocator_type;
		typedef typename allocator_type::reference				reference;
		typedef typename allocator_type::const_reference		const_reference;
		typedef typename allocator_type::pointer				pointer;
		typedef typename allocator_type::const_pointer			const_pointer;
		typedef T*												iterator;
		typedef const T*										const_iterator;
		typedef RevIter<iterator>								reverse_iterator;
		typedef RevIter<const_iterator>							const_reverse_iterator;
		typedef ptrdiff_t										difference_type;
		typedef size_t											size_type;

		//Constructors, destructor and assignation :
		explicit Vector(const allocator_type &alloc = allocator_type());
		explicit Vector(size_type n, const value_type &val = value_type(),
			const allocator_type &alloc = allocator_type());
		template <class InputIterator>
		Vector(InputIterator first, InputIterator last,
			const allocator_type &alloc = allocator_type());
		Vector(const Vector &v);
		~Vector(void);
		Vector					&operator=(const Vector &v);

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
//NEW
  		size_type				capacity() const;
  		void					reserve(size_type n);
  
    	//Element access :
  		reference				operator[](size_type n);
  		const_reference			operator[](size_type n) const;
  		reference				at(size_type n);
  		const_reference			at(size_type n) const;
//NEW
		reference				front();
		const_reference			front() const;
		reference				back();
		const_reference			back() const;

		//Modifiers :
		template <class InputIterator>
		void					assign(InputIterator first, InputIterator last);
		void					assign(size_type n, const value_type &val);
		void					push_back(const value_type &val);
		void					pop_back();
		iterator				insert(iterator it, const value_type &val);
		void					insert(iterator it, size_type n, const value_type &val);
		template <class InputIterator>
		void					insert(iterator it, InputIterator fst, InputIterator lst);
		iterator				erase(iterator position);
		iterator				erase(iterator first, iterator last);
		void					swap(Vector &x);
		void					resize(size_type n, value_type val = value_type());
		void					clear();

		//Non member functions :
		template <class T2, class Alloc2>
		friend bool	operator==(const Vector<T2, Alloc2> &lhs, const Vector<T2, Alloc2> &rhs);
		template <class T2, class Alloc2>
		friend bool	operator!=(const Vector<T2, Alloc2> &lhs, const Vector<T2, Alloc2> &rhs);
		template <class T2, class Alloc2>
		friend bool	operator<(const Vector<T2, Alloc2> &lhs, const Vector<T2, Alloc2> &rhs);
		template <class T2, class Alloc2>
		friend bool	operator<=(const Vector<T2, Alloc2> &lhs, const Vector<T2, Alloc2> &rhs);
		template <class T2, class Alloc2>
		friend bool	operator>(const Vector<T2, Alloc2> &lhs, const Vector<T2, Alloc2> &rhs);
		template <class T2, class Alloc2>
		friend bool	operator>=(const Vector<T2, Alloc2> &lhs, const Vector<T2, Alloc2> &rhs);
		template <class T2, class Alloc2>
		friend void	swap(Vector<T2, Alloc2> &x, Vector<T2, Alloc2> &y);

	private:
		//Attibutes :
		allocator_type		_alloc;
		size_type			_size;
		size_type			_capacity;
		T					*_sequence;
};

template <class T, class Alloc>
Vector<T, Alloc>::Vector(const allocator_type &alloc) :
	_alloc(alloc), _size(0), _cap_level(0), _sequence(0)
{
}

template <class T, class Alloc>
Vector<T, Alloc>::Vector(size_type n, const value_type &val, const allocator_type &alloc) :
	_alloc(alloc), _size(0), _cap_level(0), _sequence(0)
{
	assign(n, val);
}

template <class T, class Alloc>
template <class InputIterator>
Vector<T, Alloc>::Vector(InputIterator fst, InputIterator lst, const allocator_type &alloc)
	: _alloc(alloc), _size(0), _cap_level(0), _sequence(0)
{
	assign(first, last);
}

template <class T, class Alloc>
Vector<T, Alloc>::Vector(const Vector &v)
	: _alloc(alloc), _size(0), _cap_level(0), _sequence(0)
{
	assign(v.begin(), v.end());
}

template <class T, class Alloc>
Vector<T, Alloc>::~Vector(void)
{
	clear();
}

template <class T, class Alloc>
Vector<T, Alloc>
&Vector<T, Alloc>::operator=(const Vector &v)
{
	if (&v == this)
		return (*this);
	assign(v.begin(), v.end());
	return (*this);
}

template <class T, class Alloc>
typename Vector<T, Alloc>::iterator
Vector<T, Alloc>::begin(void)
{
	return (_sequence);
}

template <class T, class Alloc>
typename Vector<T, Alloc>::const_iterator
Vector<T, Alloc>::begin(void) const
{
	return (_sequence);
}

template <class T, class Alloc>
typename Vector<T, Alloc>::iterator
Vector<T, Alloc>::end(void)
{
	return (_sequence + _size);
}

template <class T, class Alloc>
typename Vector<T, Alloc>::const_iterator
Vector<T, Alloc>::end(void) const
{
	return (_sequence + _size);
}

template <class T, class Alloc>
typename Vector<T, Alloc>::reverse_iterator
Vector<T, Alloc>::rbegin(void)
{
	return (Vector<T, Alloc>::reverse_iterator(end()));
}

template <class T, class Alloc>
typename Vector<T, Alloc>::const_reverse_iterator
Vector<T, Alloc>::rbegin(void) const
{
	return (Vector<T, Alloc>::const_reverse_iterator(end()));
}

template <class T, class Alloc>
typename Vector<T, Alloc>::reverse_iterator
Vector<T, Alloc>::rend(void)
{
	return (Vector<T, Alloc>::reverse_iterator(begin()));
}

template <class T, class Alloc>
typename Vector<T, Alloc>::const_reverse_iterator
Vector<T, Alloc>::rend(void) const
{
	return (Vector<T, Alloc>::const_reverse_iterator(begin()));
}

template <class T, class Alloc>
bool
Vector<T, Alloc>::empty() const
{
	return (_size ? false : true);
}

template <class T, class Alloc>
typename Vector<T, Alloc>::size_type
Vector<T, Alloc>::size() const
{
	return (_size);
}

template <class T, class Alloc>
typename Vector<T, Alloc>::size_type
Vector<T, Alloc>::max_size() const
{
	return (_alloc.max_size() / sizeof(T));
}

template <class T, class Alloc>
typename Vector<T, Alloc>::size_type
Vector<T, Alloc>::capacity() const
{
	return (powl(2, _cap_level));
}

template <class T, class Alloc>
void
Vector<T, Alloc>::reserve(size_type n)
{
	size_t	old_cap = capacity();
	size_t	new_cap;
	T		*new_space;

	if (n <= old_cap)
		return ;
	while (n > (new_cap = capacity()))
		++_cap_level;
	new_space = _alloc.allocate(new_cap);
	for (size_t i = 0; i < _size; ++i)
	{
		alloc.construct(new_space + i, _sequence[i]);
		alloc.destroy(_sequence + i);
	}
	alloc.deallocate(_sequence, old_cap);
	_sequence = new_space;
}

template <class T, class Alloc>
typename Vector<T, Alloc>::reference
Vector<T, Alloc>::operator[](size_type n)
{
	return (this->at(n));
}

template <class T, class Alloc>
typename Vector<T, Alloc>::const_reference
Vector<T, Alloc>::operator[](size_type n) const
{
	return (this->at(n));
}

template <class T, class Alloc>
typename Vector<T, Alloc>::reference
Vector<T, Alloc>::at(size_type n)
{
	return (_sequence[n]);
}

template <class T, class Alloc>
typename Vector<T, Alloc>::const_reference
Vector<T, Alloc>::at(size_type n) const
{
	return (_sequence[n]);
}

template <class T, class Alloc>
typename Vector<T, Alloc>::reference
Vector<T, Alloc>::front()
{
	return (*begin());
}

template <class T, class Alloc>
typename Vector<T, Alloc>::const_reference
Vector<T, Alloc>::front() const
{
	return (*begin());
}

template <class T, class Alloc>
typename Vector<T, Alloc>::reference
Vector<T, Alloc>::back()
{
	return (*rbegin());
}

template <class T, class Alloc>
typename Vector<T, Alloc>::const_reference
Vector<T, Alloc>::back() const
{
	return (*rbegin());
}

template <class T, class Alloc>
template <class InputIterator>
void
Vector<T, Alloc>::assign(InputIterator first, InputIterator last)
{
	clear();
	for (; first != last; ++first)
		push_back(*first);
}

template <class T, class Alloc>
void
Vector<T, Alloc>::assign(size_type n, const value_type &val)
{
	clear();
	while (n--)
		push_back(val);
}

template <class T, class Alloc>
void
Vector<T, Alloc>::push_back(const value_type &val)
{
	insert(end(), val);
}

template <class T, class Alloc>
void
Vector<T, Alloc>::pop_back()
{
	erase(end() - 1);
}

template <class T, class Alloc>
typename Vector<T, Alloc>::iterator
Vector<T, Alloc>::insert(iterator it, const value_type &val)
{
	iterator	cpy(it);

	if (_size + 1 > capacity)
		reserve(_size + 1);
	for (T lval = val, T tmp = T(); it != end(); ++it)
	{
		tmp = *it;
		*it = lval;
	}
	++_size;
	return (cpy);
}

template <class T, class Alloc>
void
Vector<T, Alloc>::insert(iterator it, size_type n, const value_type &val)
{
	iterator	cpy(it);

	while (n--)
		insert(it++, val);
	return (cpy);
}

template <class T, class Alloc>
template <class InputIterator>
void
Vector<T, Alloc>::insert(iterator it, InputIterator fst, InputIterator lst)
{
	iterator	cpy(it);

	for (; fst != lst; ++fst)
		insert(it++, *fst);
	return (cpy);
}

template <class T, class Alloc>
typename Vector<T, Alloc>::iterator
Vector<T, Alloc>::erase(iterator position)
{
	VectorNode<T> *tmp = position.node;

	++position;
	tmp->prev->next = tmp->next;
	tmp->next->prev = tmp->prev;
	delete tmp;
	_size--;
	return (position);
}

template <class T, class Alloc>
typename Vector<T, Alloc>::iterator
Vector<T, Alloc>::erase(iterator first, iterator last)
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
Vector<T, Alloc>::swap(Vector &x)
{
	VectorNode<T>					*fst = _front.next;
	VectorNode<T>					*lst = _back.prev;
	Vector<T, Alloc>::size_type	tmp = _size;

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
Vector<T, Alloc>::resize(size_type n, value_type val)
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
Vector<T, Alloc>::clear()
{
	while (_size)
		pop_back();
}

template <class T, class Alloc>
bool
operator==(const Vector<T, Alloc> &lhs, const Vector<T, Alloc> &rhs)
{
	typename Vector<T, Alloc>::const_iterator		lhs_it(lhs.begin());
	typename Vector<T, Alloc>::const_iterator		rhs_it(rhs.begin());

	if (lhs._size != rhs._size)
		return (false);
	for (; lhs_it != lhs.end(); ++lhs_it, ++rhs_it)
		if (*lhs_it != *rhs_it)
			return (false);
	return (true);
}

template <class T, class Alloc>
bool
operator!=(const Vector<T, Alloc> &lhs, const Vector<T, Alloc> &rhs)
{
	return (!(lhs == rhs));
}

template <class T, class Alloc>
bool
operator<(const Vector<T, Alloc> &lhs, const Vector<T, Alloc> &rhs)
{
	typename Vector<T, Alloc>::const_iterator		lhs_it(lhs.begin());
	typename Vector<T, Alloc>::const_iterator		rhs_it(rhs.begin());

	for (; true; ++lhs_it, ++rhs_it)
	{
		if (rhs_it == rhs.end())
			return (false);
		else if (lhs_it == lhs.end() || *lhs_it < *rhs_it)
			return (true);
	}
}

template <class T, class Alloc>
bool
operator<=(const Vector<T, Alloc> &lhs, const Vector<T, Alloc> &rhs)
{
	return (!(lhs > rhs));
}

template <class T, class Alloc>
bool
operator>(const Vector<T, Alloc> &lhs, const Vector<T, Alloc> &rhs)
{
	return (rhs < lhs);
}

template <class T, class Alloc>
bool
operator>=(const Vector<T, Alloc> &lhs, const Vector<T, Alloc> &rhs)
{
	return (!(lhs < rhs));
}

template <class T, class Alloc>
void
swap(Vector<T,Alloc> &x, Vector<T,Alloc> &y)
{
	x.swap(y);
}

template <class T, class Alloc>
bool
Vector<T, Alloc>::_equal(const_reference val1, const_reference val2)
{
	return (val1 == val2);
}

template <class T, class Alloc>
bool
Vector<T, Alloc>::_less(const_reference val1, const_reference val2)
{
	return (val1 < val2);
}

template <class T, class Alloc>
void
Vector<T, Alloc>::_swap_it(Vector<T, Alloc>::iterator &it1, Vector<T, Alloc>::iterator &it2)
{
	Vector<T, Alloc>::iterator	tmp;

	tmp = it1;
	it1 = it2;
	it2 = tmp;
}

}

#endif //VECTOR_HPP
