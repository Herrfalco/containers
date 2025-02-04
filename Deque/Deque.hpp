/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Deque.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcadet <cadet.florian@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 12:21:56 by fcadet            #+#    #+#             */
/*   Updated: 2020/03/28 18:53:37 by fcadet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEQUE_HPP
# define DEQUE_HPP

# include "../Iter/IterTypes.hpp"
# include "../Iter/DequeIter.hpp"
# include "../Iter/RevIter.hpp"
# include "../Vector/Vector.hpp"

namespace	ft
{

template <class T>
class	Deque
{
	public:
		//Member types :
		typedef T												value_type;
		typedef T&												reference;
		typedef const T&										const_reference;
		typedef T*												pointer;
		typedef const T*										const_pointer;
		typedef DequeIter<random_access_iterator_tag, T>		iterator;
		typedef DequeIter<random_access_iterator_tag, const T>	const_iterator;
		typedef RevIter<iterator>								reverse_iterator;
		typedef RevIter<const_iterator>							const_reverse_iterator;
		typedef std::ptrdiff_t									difference_type;
		typedef size_t											size_type;

		//Constructors, destructor and assignation :
		explicit Deque(void);
		explicit Deque(size_type n, const value_type &val = value_type());
		template <class InputIterator>
		Deque(InputIterator first, InputIterator last);
		Deque(const Deque &d);
		~Deque(void);
		Deque					&operator=(const Deque &d);

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
		size_type				size(void) const;
		size_type				max_size(void) const;
		void					resize(size_type n, value_type val = value_type());
		bool					empty(void) const;
  
    	//Element access :
  		reference				operator[](size_type n);
  		const_reference			operator[](size_type n) const;
  		reference				at(size_type n);
  		const_reference			at(size_type n) const;
		reference				front(void);
		const_reference			front(void) const;
		reference				back(void);
		const_reference			back(void) const;

		//Modifiers :
		template <class InputIterator>
		void					assign(InputIterator first, InputIterator last);
		void					assign(size_type n, const value_type &val);
		void					push_back(const value_type &val);
		void					push_front(const value_type &val);
		void					pop_back(void);
		void					pop_front(void);
		iterator				insert(iterator it, const value_type &val);
		void					insert(iterator it, size_type n, const value_type &val);
		template <class InputIterator>
		void					insert(iterator it, InputIterator fst, InputIterator lst);
		iterator				erase(iterator position);
		iterator				erase(iterator first, iterator last);
		void					swap(Deque &x);
		void					clear(void);

	private:
		//Attibutes :
		Vector<T>			_up;
		Vector<T>			_down;
};

template <class T>
Deque<T>::Deque(void) : _up(), _down()
{
}

template <class T>
Deque<T>::Deque(size_type n, const value_type &val) : _up(n, val), _down()
{
}

template <class T>
template <class InputIterator>
Deque<T>::Deque(InputIterator fst, InputIterator lst) : _up(fst, lst), _down()
{
}

template <class T>
Deque<T>::Deque(const Deque &d) : _up(d._up), _down(d._down)
{
}

template <class T>
Deque<T>::~Deque(void)
{
}

template <class T>
Deque<T>
&Deque<T>::operator=(const Deque &d)
{
	if (&d == this)
		return (*this);
	_up = d._up;
	_down = d._down;
	return (*this);
}

template <class T>
typename Deque<T>::iterator
Deque<T>::begin(void)
{
	if (!_down.size())
		return (iterator(0, &_down, &_up, up));
	else
		return (iterator(_down.size() - 1, &_down, &_up, down));
}

template <class T>
typename Deque<T>::const_iterator
Deque<T>::begin(void) const
{
	if (!_down.size())
		return (const_iterator(0,
			reinterpret_cast<Vector<const T> *>(const_cast<Vector<T> *>(&_down)),
			reinterpret_cast<Vector<const T> *>(const_cast<Vector<T> *>(&_up)), up));
	else
		return (const_iterator(_down.size() - 1,
			reinterpret_cast<Vector<const T> *>(const_cast<Vector<T> *>(&_down)),
			reinterpret_cast<Vector<const T> *>(const_cast<Vector<T> *>(&_up)), down));
}

template <class T>
typename Deque<T>::iterator
Deque<T>::end(void)
{
	return (iterator(_up.size(), &_down, &_up, up));
}

template <class T>
typename Deque<T>::const_iterator
Deque<T>::end(void) const
{
	return (const_iterator(_up.size(),
		reinterpret_cast<Vector<const T> *>(const_cast<Vector<T> *>(&_down)),
		reinterpret_cast<Vector<const T> *>(const_cast<Vector<T> *>(&_up)), up));
}

template <class T>
typename Deque<T>::reverse_iterator
Deque<T>::rbegin(void)
{
	return (reverse_iterator(end()));
}

template <class T>
typename Deque<T>::const_reverse_iterator
Deque<T>::rbegin(void) const
{
	return (const_reverse_iterator(end()));
}

template <class T>
typename Deque<T>::reverse_iterator
Deque<T>::rend(void)
{
	return (reverse_iterator(begin()));
}

template <class T>
typename Deque<T>::const_reverse_iterator
Deque<T>::rend(void) const
{
	return (const_reverse_iterator(begin()));
}

template <class T>
typename Deque<T>::size_type
Deque<T>::size(void) const
{
	return (_down.size() + _up.size());
}

template <class T>
typename Deque<T>::size_type
Deque<T>::max_size(void) const
{
	return (std::numeric_limits<size_type>::max());
}

template <class T>
void
Deque<T>::resize(size_type n, value_type val)
{
	if (n < _down.size())
	{
		_up.clear();
		_down.erase(_down.begin(), _down.begin() + (_down.size() - n));
	}
	else
		_up.resize(n - _down.size(), val);
}

template <class T>
bool
Deque<T>::empty(void) const
{
	return (size() ? false : true);
}

template <class T>
typename Deque<T>::reference
Deque<T>::operator[](size_type n)
{
	return (at(n));
}

template <class T>
typename Deque<T>::const_reference
Deque<T>::operator[](size_type n) const
{
	return (at(n));
}

template <class T>
typename Deque<T>::reference
Deque<T>::at(size_type n)
{
	return (*(begin() + n));
}

template <class T>
typename Deque<T>::const_reference
Deque<T>::at(size_type n) const
{
	return (*(begin() + n));
}

template <class T>
typename Deque<T>::reference
Deque<T>::front(void)
{
	return (*begin());
}

template <class T>
typename Deque<T>::const_reference
Deque<T>::front(void) const
{
	return (*begin());
}

template <class T>
typename Deque<T>::reference
Deque<T>::back(void)
{
	return (*rbegin());
}

template <class T>
typename Deque<T>::const_reference
Deque<T>::back(void) const
{
	return (*rbegin());
}

template <class T>
template <class InputIterator>
void
Deque<T>::assign(InputIterator first, InputIterator last)
{
	_down.clear();
	_up.assign(first, last);
}

template <class T>
void
Deque<T>::assign(size_type n, const value_type &val)
{
	_down.clear();
	_up.assign(n, val);
}

template <class T>
void
Deque<T>::push_back(const value_type &val)
{
	_up.push_back(val);
}

template <class T>
void
Deque<T>::pop_back(void)
{
	if (_up.size())
		_up.pop_back();
	else if (_down.size())
		_down.erase(_down.begin());
}

template <class T>
void
Deque<T>::push_front(const value_type &val)
{
	_down.push_back(val);
}

template <class T>
void
Deque<T>::pop_front(void)
{
	if (_down.size())
		_down.pop_back();
	else if (_up.size())
		_up.erase(_up.begin());
}

template <class T>
typename Deque<T>::iterator
Deque<T>::insert(iterator it, const value_type &val)
{
	if (it._attr.side == up)
	{
		_up.insert(&_up[it._attr.id], val);
		return (it);
	}
	else
	{
		_down.insert(&_down[it._attr.id + 1], val);
		return (it - 1);
	}
}

template <class T>
void
Deque<T>::insert(iterator it, size_type n, const value_type &val)
{
	for (; n; --n)
		insert(it, val);
}

template <class T>
template <class InputIterator>
void
Deque<T>::insert(iterator it, InputIterator fst, InputIterator lst)
{
	for (; fst != lst; ++fst, (it._attr.side == up ? ++it : 0))
		insert(it, *fst);
}

template <class T>
typename Deque<T>::iterator
Deque<T>::erase(iterator position)
{
	if (position._attr.side == up)
	{
		_up.erase(&_up[position._attr.id]);
		return (position);
	}
	else
	{
		_down.erase(&_down[position._attr.id]);
		return (position + 1);
	}
}

template <class T>
typename Deque<T>::iterator
Deque<T>::erase(iterator first, iterator last)
{
	if (first._attr.side == last._attr.side)
	{
		if (first._attr.side == up)
		{
			_up.erase(&_up[first._attr.id], &_up[last._attr.id]);
			return (first);
		}
		else
		{
			_down.erase(&_down[last._attr.id + 1], &_down[first._attr.id + 1]);
			return (last - 1);
		}
	}
	else
	{
		_down.erase(&_down[0], &_down[first._attr.id + 1]);
		_up.erase(&_up[0], &_up[last._attr.id]);
		return (iterator(0, &_down, &_up, up));
	}
}

template <class T>
void
Deque<T>::swap(Deque &x)
{
	_up.swap(x._up);
	_down.swap(x._down);
}

template <class T>
void
Deque<T>::clear(void)
{
	_up.clear();
	_down.clear();
}

template <class T>
bool
operator==(const Deque<T> &lhs, const Deque<T> &rhs)
{
	return (lhs < rhs || rhs < lhs ? false : true);
}

template <class T>
bool
operator!=(const Deque<T> &lhs, const Deque<T> &rhs)
{
	return (!(lhs == rhs));
}

template <class T>
bool
operator<(const Deque<T> &lhs, const Deque<T> &rhs)
{
	typename Deque<T>::const_iterator		lhs_it(lhs.begin());
	typename Deque<T>::const_iterator		rhs_it(rhs.begin());

	for (; rhs_it != rhs.end(); ++lhs_it, ++rhs_it)
	{
		if (lhs_it == lhs.end() || *lhs_it < *rhs_it)
			return (true);
	}
	return (false);
}

template <class T>
bool
operator<=(const Deque<T> &lhs, const Deque<T> &rhs)
{
	return (!(lhs > rhs));
}

template <class T>
bool
operator>(const Deque<T> &lhs, const Deque<T> &rhs)
{
	return (rhs < lhs);
}

template <class T>
bool
operator>=(const Deque<T> &lhs, const Deque<T> &rhs)
{
	return (!(lhs < rhs));
}

template <class T>
void
swap(Deque<T> &x, Deque<T> &y)
{
	x.swap(y);
}

}

#endif //DEQUE_HPP
