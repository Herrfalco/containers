/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcadet <cadet.florian@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 12:21:56 by fcadet            #+#    #+#             */
/*   Updated: 2020/03/25 13:52:37 by fcadet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include "../Iter/IterTypes.hpp"
# include "../Iter/VectorIter.hpp"
# include "../Iter/RevIter.hpp"
# include <cmath>
# include <limits>
# include <memory>

namespace	ft
{

template <class T>
class	Vector
{
	public:
		//Member types :
		typedef T												value_type;
		typedef T&												reference;
		typedef const T&										const_reference;
		typedef T*												pointer;
		typedef const T*										const_pointer;
		typedef VectorIter<random_access_iterator_tag, T>		iterator;
		typedef VectorIter<random_access_iterator_tag, const T>	const_iterator;
		typedef RevIter<iterator>								reverse_iterator;
		typedef RevIter<const_iterator>							const_reverse_iterator;
		typedef std::ptrdiff_t									difference_type;
		typedef size_t											size_type;

		//Constructors, destructor and assignation :
		explicit Vector(void);
		explicit Vector(size_type n, const value_type &val = value_type());
		template <class InputIterator>
		Vector(InputIterator first, InputIterator last);
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

	private:
		//Attibutes :
		size_type			_size;
		size_type			_cap_level;
		value_type			*_sequence;
};

template <class T>
Vector<T>::Vector(void) : _size(0), _cap_level(0), _sequence(0)
{
}

template <class T>
Vector<T>::Vector(size_type n, const value_type &val) : _size(0), _cap_level(0),
	_sequence(0)
{
	insert(begin(), n, val);
}

template <class T>
template <class InputIterator>
Vector<T>::Vector(InputIterator fst, InputIterator lst) : _size(0), _cap_level(0),
	_sequence(0)
{
	insert(begin(), fst, lst);
}

template <class T>
Vector<T>::Vector(const Vector &v) : _size(0), _cap_level(0), _sequence(0)
{
	if (v.size())
		insert(begin(), v.begin(), v.end());
}

template <class T>
Vector<T>::~Vector(void)
{
	std::allocator<T>	alloc;

	clear();
	alloc.deallocate(_sequence, capacity());
}

template <class T>
Vector<T>
&Vector<T>::operator=(const Vector &v)
{
	if (&v == this)
		return (*this);
	assign(v.begin(), v.end());
	return (*this);
}

template <class T>
typename Vector<T>::iterator
Vector<T>::begin(void)
{
	return (iterator(_sequence));
}

template <class T>
typename Vector<T>::const_iterator
Vector<T>::begin(void) const
{
	return (const_iterator(reinterpret_cast<const T*>(_sequence)));
}

template <class T>
typename Vector<T>::iterator
Vector<T>::end(void)
{
	return (iterator(_sequence + _size));
}

template <class T>
typename Vector<T>::const_iterator
Vector<T>::end(void) const
{
	return (const_iterator(reinterpret_cast<const T*>(_sequence + _size)));
}

template <class T>
typename Vector<T>::reverse_iterator
Vector<T>::rbegin(void)
{
	return (Vector<T>::reverse_iterator(end()));
}

template <class T>
typename Vector<T>::const_reverse_iterator
Vector<T>::rbegin(void) const
{
	return (Vector<T>::const_reverse_iterator(end()));
}

template <class T>
typename Vector<T>::reverse_iterator
Vector<T>::rend(void)
{
	return (Vector<T>::reverse_iterator(begin()));
}

template <class T>
typename Vector<T>::const_reverse_iterator
Vector<T>::rend(void) const
{
	return (Vector<T>::const_reverse_iterator(begin()));
}

template <class T>
typename Vector<T>::size_type
Vector<T>::size() const
{
	return (_size);
}

template <class T>
typename Vector<T>::size_type
Vector<T>::max_size() const
{
	return (std::numeric_limits<size_type>::max());
}

template <class T>
void
Vector<T>::resize(size_type n, value_type val)
{
	size_type			nb;
	std::allocator<T>	alloc;

	if (n < _size)
	{
		for (iterator it = end() - (_size - n); it != end(); ++it)
			alloc.destroy(it._ptr);	
	}
	else if (n > _size)
	{
		reserve(n);
		nb = n - _size;
		for (iterator it = end(); nb; --nb, ++it)
			alloc.construct(it._ptr, val);
	}
	_size = n;
}

template <class T>
typename Vector<T>::size_type
Vector<T>::capacity() const
{
	return (!_cap_level ? 0 : powl(2, _cap_level - 1));
}

template <class T>
bool
Vector<T>::empty() const
{
	return (_size ? false : true);
}

template <class T>
void
Vector<T>::reserve(size_type n)
{
	std::allocator<T>	alloc;
	size_type			old_cap = capacity();
	size_type			new_cap;
	T		 			*new_space;

	if (n <= old_cap)
		return ;
	while (n > (new_cap = capacity()))
		++_cap_level;
	new_space = alloc.allocate(new_cap);
	for (size_type i = 0; i < _size; ++i)
	{
		alloc.construct(new_space + i, _sequence[i]);
		alloc.destroy(_sequence + i);
	}
	alloc.deallocate(_sequence, old_cap);
	_sequence = new_space;
}

template <class T>
typename Vector<T>::reference
Vector<T>::operator[](size_type n)
{
	return (at(n));
}

template <class T>
typename Vector<T>::const_reference
Vector<T>::operator[](size_type n) const
{
	return (at(n));
}

template <class T>
typename Vector<T>::reference
Vector<T>::at(size_type n)
{
	return (_sequence[n]);
}

template <class T>
typename Vector<T>::const_reference
Vector<T>::at(size_type n) const
{
	return (_sequence[n]);
}

template <class T>
typename Vector<T>::reference
Vector<T>::front()
{
	return (*begin());
}

template <class T>
typename Vector<T>::const_reference
Vector<T>::front() const
{
	return (*begin());
}

template <class T>
typename Vector<T>::reference
Vector<T>::back()
{
	return (*rbegin());
}

template <class T>
typename Vector<T>::const_reference
Vector<T>::back() const
{
	return (*rbegin());
}

template <class T>
template <class InputIterator>
void
Vector<T>::assign(InputIterator first, InputIterator last)
{
	clear();
	insert(end(), first, last);
}

template <class T>
void
Vector<T>::assign(size_type n, const value_type &val)
{
	clear();
	insert(end(), n, val);
}

template <class T>
void
Vector<T>::push_back(const value_type &val)
{
	insert(end(), val);
}

template <class T>
void
Vector<T>::pop_back()
{
	if (_size)
		erase(end() - 1);
}

template <class T>
typename Vector<T>::iterator
Vector<T>::insert(iterator it, const value_type &val)
{
	difference_type		it_id = it - begin();

	insert(it, (size_type)1, val);
	return (begin() + it_id);
}

template <class T>
void
Vector<T>::insert(iterator it, size_type n, const value_type &val)
{
	std::allocator<T>	alloc;
	iterator			old_end(end());
	difference_type		it_id = it - begin();

	if (!n)
		return ;
	reserve(_size + n);
	it = begin() + it_id;
	_size += n; 
	for (iterator b(end() - 1), a(b - n); a >= it; --a, --b)
	{
		if (b >= old_end)
			alloc.construct(b._ptr, *a);
		else
			*b = *a;
	}
	for (; n; --n, ++it)
	{
		if (it >= old_end)
			alloc.construct(it._ptr, val);
		else
			*it = val;
	}
}

template <class T>
template <class InputIterator>
void
Vector<T>::insert(iterator it, InputIterator fst, InputIterator lst)
{
	std::allocator<T>	alloc;
	iterator			old_end(end());
	difference_type		it_id = it - begin();

	if (fst == lst)
		return ;
	reserve(_size + (lst - fst));
	it = begin() + it_id;
	_size += lst - fst;
	for (iterator b(end() - 1), a(b - (lst - fst)); a >= it; --a, --b)
	{
		if (b >= old_end)
			alloc.construct(b._ptr, *a);
		else
			*b = *a;
	}
	for (; fst != lst; ++fst, ++it)
	{
		if (it >= old_end)
			alloc.construct(it._ptr, *fst);
		else
			*it = *fst;
	}
}

template <class T>
typename Vector<T>::iterator
Vector<T>::erase(iterator position)
{
	return (erase(position, position + 1));
}

template <class T>
typename Vector<T>::iterator
Vector<T>::erase(iterator first, iterator last)
{
	iterator	tmp(first);

	for (; last != end(); ++first, ++last)
		*first = *last;	
	resize(_size - (last - first));
	return (tmp);
}

template <class T>
void
Vector<T>::swap(Vector &x)
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

template <class T>
void
Vector<T>::clear()
{
	resize(0);
}

template <class T>
bool
operator==(const Vector<T> &lhs, const Vector<T> &rhs)
{
	typename Vector<T>::const_iterator		lhs_it(lhs.begin());
	typename Vector<T>::const_iterator		rhs_it(rhs.begin());

	if (lhs.size() != rhs.size())
		return (false);
	for (; lhs_it != lhs.end(); ++lhs_it, ++rhs_it)
		if (*lhs_it != *rhs_it)
			return (false);
	return (true);
}

template <class T>
bool
operator!=(const Vector<T> &lhs, const Vector<T> &rhs)
{
	return (!(lhs == rhs));
}

template <class T>
bool
operator<(const Vector<T> &lhs, const Vector<T> &rhs)
{
	typename Vector<T>::const_iterator		lhs_it(lhs.begin());
	typename Vector<T>::const_iterator		rhs_it(rhs.begin());

	for (; rhs_it != rhs.end(); ++lhs_it, ++rhs_it)
	{
		if (lhs_it == lhs.end() || *lhs_it < *rhs_it)
			return (true);
	}
	return (false);
}

template <class T>
bool
operator<=(const Vector<T> &lhs, const Vector<T> &rhs)
{
	return (!(lhs > rhs));
}

template <class T>
bool
operator>(const Vector<T> &lhs, const Vector<T> &rhs)
{
	return (rhs < lhs);
}

template <class T>
bool
operator>=(const Vector<T> &lhs, const Vector<T> &rhs)
{
	return (!(lhs < rhs));
}

template <class T>
void
swap(Vector<T> &x, Vector<T> &y)
{
	x.swap(y);
}

}

#endif //VECTOR_HPP
