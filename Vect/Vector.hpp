/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcadet <cadet.florian@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 12:21:56 by fcadet            #+#    #+#             */
/*   Updated: 2020/03/18 18:36:52 by fcadet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include "../Iter/IterTypes.hpp"
# include "../Iter/VectIter.hpp"
# include "../Iter/RevIter.hpp"
# include <cmath>
# include <limits>

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
		typedef VectIter<random_access_iterator_tag, T>			iterator;
		typedef VectIter<random_access_iterator_tag, const T>	const_iterator;
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
		//Non member functions :
		template <class T2>
		friend bool	operator==(const Vector<T2> &lhs, const Vector<T2> &rhs);
		template <class T2>
		friend bool	operator!=(const Vector<T2> &lhs, const Vector<T2> &rhs);
		template <class T2>
		friend bool	operator<(const Vector<T2> &lhs, const Vector<T2> &rhs);
		template <class T2>
		friend bool	operator<=(const Vector<T2> &lhs, const Vector<T2> &rhs);
		template <class T2>
		friend bool	operator>(const Vector<T2> &lhs, const Vector<T2> &rhs);
		template <class T2>
		friend bool	operator>=(const Vector<T2> &lhs, const Vector<T2> &rhs);
		template <class T2>
		friend void	swap(Vector<T2> &x, Vector<T2> &y);

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
	assign(n, val);
}

template <class T>
template <class InputIterator>
Vector<T>::Vector(InputIterator fst, InputIterator lst) : _size(0), _cap_level(0),
	_sequence(0)
{
	assign(fst, lst);
}

template <class T>
Vector<T>::Vector(const Vector &v) : _size(0), _cap_level(0), _sequence(0)
{
	assign(v.begin(), v.end());
}

template <class T>
Vector<T>::~Vector(void)
{
	delete[] (_sequence);
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
	size_type	nb;

	if (n > _size)
	{
		reserve(n);
		nb = n - _size;
		for (iterator it = end(); nb; --nb, ++it)
			*it = val;
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
	size_type	new_cap;
	T			*new_space;

	if (n <= capacity())
		return ;
	while (n > (new_cap = capacity()))
		++_cap_level;
	new_space = new T[new_cap];
	for (size_type i = 0; i < _size; ++i)
		new_space[i] = _sequence[i];
	delete[] (_sequence);
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
	for (; first != last; ++first)
		push_back(*first);
}

template <class T>
void
Vector<T>::assign(size_type n, const value_type &val)
{
	clear();
	while (n--)
		push_back(val);
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
	erase(end() - 1);
}

template <class T>
typename Vector<T>::iterator
Vector<T>::insert(iterator it, const value_type &val)
{
	insert(it, (size_type)1, val);
	return (it);
}

template <class T>
void
Vector<T>::insert(iterator it, size_type n, const value_type &val)
{
	iterator			old_end(end());
	difference_type		it_id = it - begin();

	reserve(_size + n);
	it = _sequence + it_id;
	_size += n; 
	for (iterator b(end() - 1), a(b - n); a >= it; --a, --b)
		*b = *a;
	for (; n; --n, ++it)
		*it = val;
}

template <class T>
template <class InputIterator>
void
Vector<T>::insert(iterator it, InputIterator fst, InputIterator lst)
{
	iterator	old_end(end());

	reserve(_size + (lst - fst));
	_size += lst - fst;
	for (iterator b(end() - 1), a(b - (lst - fst)); a >= it; --a, --b)
		*b = *a;
	for (; fst != lst; ++fst, ++it)
		*it = *fst;
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

	if (lhs._size != rhs._size)
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
