/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcadet <cadet.florian@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 12:21:56 by fcadet            #+#    #+#             */
/*   Updated: 2020/03/11 15:20:34 by fcadet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

#include "../Iter/IterTypes.hpp"
#include "../Iter/VectIter.hpp"
#include "../Iter/RevIter.hpp"
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
		typedef VectIter<random_access_iterator_tag, T>			iterator;
		typedef VectIter<random_access_iterator_tag, const T>	const_iterator;
		typedef RevIter<iterator>								reverse_iterator;
		typedef RevIter<const_iterator>							const_reverse_iterator;
		typedef std::ptrdiff_t									difference_type;
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
		size_type				size() const;
		size_type				max_size() const;
		void					resize(size_type n, value_type val = value_type());
  		size_type				capacity() const;
		bool					empty() const;
  		void					reserve(size_type n);
  
    	//Element access :
  		reference				operator[](size_type n);
  		const_reference			operator[](size_type n) const;
  		reference				at(size_type n);
  		const_reference			at(size_type n) const;
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
		size_type			_cap_level;
		value_type			*_sequence;
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
	assign(fst, lst);
}

template <class T, class Alloc>
Vector<T, Alloc>::Vector(const Vector &v)
	: _alloc(v._alloc), _size(0), _cap_level(0), _sequence(0)
{
	assign(v.begin(), v.end());
}

template <class T, class Alloc>
Vector<T, Alloc>::~Vector(void)
{
	clear();
	_alloc.deallocate(_sequence, capacity());
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
	return (iterator(_sequence));
}

template <class T, class Alloc>
typename Vector<T, Alloc>::const_iterator
Vector<T, Alloc>::begin(void) const
{
	return (const_iterator(reinterpret_cast<const T*>(_sequence)));
}

template <class T, class Alloc>
typename Vector<T, Alloc>::iterator
Vector<T, Alloc>::end(void)
{
	return (iterator(_sequence + _size));
}

template <class T, class Alloc>
typename Vector<T, Alloc>::const_iterator
Vector<T, Alloc>::end(void) const
{
	return (const_iterator(reinterpret_cast<const T*>(_sequence + _size)));
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
void
Vector<T, Alloc>::resize(size_type n, value_type val)
{
	size_type	nb;

	if (n < _size)
	{
		for (iterator it = end() - (_size - n); it != end(); ++it)
			_alloc.destroy(it.ptr);
	}
	else if (n > _size)
	{
		reserve(n);
		nb = n - _size;
		for (iterator it = end(); nb; --nb, ++it)
			_alloc.construct(it.ptr, val);
	}
	_size = n;
}

template <class T, class Alloc>
typename Vector<T, Alloc>::size_type
Vector<T, Alloc>::capacity() const
{
	return (!_cap_level ? 0 : powl(2, _cap_level - 1));
}

template <class T, class Alloc>
bool
Vector<T, Alloc>::empty() const
{
	return (_size ? false : true);
}

template <class T, class Alloc>
void
Vector<T, Alloc>::reserve(size_type n)
{
	size_type	old_cap = capacity();
	size_type	new_cap;
	T			*new_space;

	if (n <= old_cap)
		return ;
	while (n > (new_cap = capacity()))
		++_cap_level;
	new_space = _alloc.allocate(new_cap);
	for (size_type i = 0; i < _size; ++i)
	{
		_alloc.construct(new_space + i, _sequence[i]);
		_alloc.destroy(_sequence + i);
	}
	_alloc.deallocate(_sequence, old_cap);
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
	insert(it, (size_type)1, val);
	return (it);
}

template <class T, class Alloc>
void
Vector<T, Alloc>::insert(iterator it, size_type n, const value_type &val)
{
	iterator			old_end(end());
	difference_type		it_id = it - begin();

	reserve(_size + n);
	it = _sequence + it_id;
	_size += n; 
	for (iterator b(end() - 1), a(b - n); a >= it; --a, --b)
	{
		if (b >= old_end)
			_alloc.construct(b.ptr, *a);
		else
			*b = *a;
	}
	for (; n; --n, ++it)
	{
		if (it >= old_end)
			_alloc.construct(it.ptr, val);
		else
			*it = val;
	}
}

template <class T, class Alloc>
template <class InputIterator>
void
Vector<T, Alloc>::insert(iterator it, InputIterator fst, InputIterator lst)
{
	iterator	old_end(end());

	reserve(_size + (lst - fst));
	_size += lst - fst;
	for (iterator b(end() - 1), a(b - (lst - fst)); a >= it; --a, --b)
	{
		if (b >= old_end)
			_alloc.construct(b.ptr, *a);
		else
			*b = *a;
	}
	for (; fst != lst; ++fst, ++it)
	{
		if (it >= old_end)
			_alloc.construct(it.ptr, *fst);
		else
			*it = *fst;
	}
}

template <class T, class Alloc>
typename Vector<T, Alloc>::iterator
Vector<T, Alloc>::erase(iterator position)
{
	return (erase(position, position + 1));
}

template <class T, class Alloc>
typename Vector<T, Alloc>::iterator
Vector<T, Alloc>::erase(iterator first, iterator last)
{
	iterator	tmp(first);

	for (; last != end(); ++first, ++last)
		*first = *last;	
	resize(_size - (last - first));
	return (tmp);
}

template <class T, class Alloc>
void
Vector<T, Alloc>::swap(Vector &x)
{
	T			*seq_tmp(_sequence);
	size_type	siz_tmp(_size);

	_sequence = x._sequence;
	x._sequence = seq_tmp;
	_size = x._size;
	x._size = siz_tmp;
	siz_tmp = _cap_level;
	_cap_level = x._cap_level;
	x._cap_level = siz_tmp;
}

template <class T, class Alloc>
void
Vector<T, Alloc>::clear()
{
	resize(0);
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

	for (; rhs_it != rhs.end(); ++lhs_it, ++rhs_it)
	{
		if (lhs_it == lhs.end() || *lhs_it < *rhs_it)
			return (true);
	}
	return (false);
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

}

#endif //VECTOR_HPP
