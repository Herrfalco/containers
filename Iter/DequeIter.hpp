/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DequeIter.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcadet <cadet.florian@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 13:08:02 by fcadet            #+#    #+#             */
/*   Updated: 2020/03/21 16:42:27 by fcadet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEQUEITER_HPP
# define DEQUEITER_HPP

# include <cstddef>
# include "../Vect/Vector.hpp"

namespace	ft
{

typedef enum	e_side { down, up } t_side;

template <class Category, class T, class Distance = std::ptrdiff_t,
	class Pointer = T*, class Reference = T&>
class	DequeIter
{
	public:
		//Member types :
		typedef T			value_type;
		typedef Distance	difference_type;
		typedef Pointer		pointer;
		typedef Reference	reference;
		typedef Category	iterator_category;

		//Constructors, destructor and assignation :
		DequeIter(size_t i = 0, Vector<T> *d = 0, Vector<T> *u = 0, t_side s = up);
		DequeIter(const DequeIter &v);
		~DequeIter(void);
		DequeIter		&operator=(const DequeIter &v);

		//Relational operators :
		bool			operator==(const DequeIter &v) const;
		bool			operator!=(const DequeIter &v) const;

		//Access operators :
		reference		operator*(void);
		pointer			operator->(void);
		reference		operator[](difference_type n) const;
		DequeIter		&operator++(void);
		DequeIter		operator++(int valptr);
		DequeIter		&operator--(void);
		DequeIter		operator--(int valptr);
		DequeIter		operator+(difference_type n) const;
		DequeIter		operator-(difference_type n) const;
		DequeIter		&operator+=(difference_type n);
		DequeIter		&operator-=(difference_type n);

	private:
		//Friendship :
		template <class Cat, class T2, class Dist, class Point, class Refer>
		friend Dist		operator-(const DequeIter<Cat, T2, Dist, Point, Refer> &lhs,
			const DequeIter<Cat, T2, Dist, Point, Refer> &rhs);
		template <class Cat, class T2, class Dist, class Point, class Refer>
		friend bool		operator<(const DequeIter<Cat, T2, Dist, Point, Refer> &lhs,
			const DequeIter<Cat, T2, Dist, Point, Refer> &rhs);
		template <class T2>
		friend class	Deque;

		//Attributes :
		size_t				_id;
		Vector<value_type>	*_data[2];
		t_side				_side;
};

template <class Category, class T, class Distance, class Pointer, class Reference>
DequeIter<Category, T, Distance, Pointer, Reference>::DequeIter(size_t i, Vector<T> *l,
	Vector<T> *u, t_side s) : _id(i), _data(), _side(s)
{
	_data[down] = l;
	_data[up] = u;
}

template <class Category, class T, class Distance, class Pointer, class Reference>
DequeIter<Category, T, Distance, Pointer, Reference>::DequeIter(const DequeIter<Category,
	T, Distance, Pointer, Reference> &v) : _id(v._id), _data(), _side(v._side)
{
	_data[down] = v._data[down];
	_data[up] = v._data[up];
}

template <class Category, class T, class Distance, class Pointer, class Reference>
DequeIter<Category, T, Distance, Pointer, Reference>::~DequeIter(void)
{
}

template <class Category, class T, class Distance, class Pointer, class Reference>
DequeIter<Category, T, Distance, Pointer, Reference>&
DequeIter<Category, T, Distance, Pointer, Reference>::operator=(const DequeIter &v)
{
	if (&v == this)
		return (*this);
	_id = v._id;
	_data[down] = v._data[down];
	_data[up] = v._data[up];
	_side = v._side;
	return (*this);
}

template <class Category, class T, class Distance, class Pointer, class Reference>
bool
DequeIter<Category, T, Distance, Pointer, Reference>::operator==(const DequeIter &v) const
{
	return (_data[_side] == v._data[v._side] && _id == v._id);
}

template <class Category, class T, class Distance, class Pointer, class Reference>
bool
DequeIter<Category, T, Distance, Pointer, Reference>::operator!=(const DequeIter &v) const
{
	return (!(*this == v));
}

template <class Category, class T, class Distance, class Pointer, class Reference>
Reference
DequeIter<Category, T, Distance, Pointer, Reference>::operator*(void)
{
	return ((*(_data[_side]))[_id]);
}

template <class Category, class T, class Distance, class Pointer, class Reference>
Pointer
DequeIter<Category, T, Distance, Pointer, Reference>::operator->(void)
{
	return (&(*(_data[_side]))[_id]);
}

template <class Category, class T, class Distance, class Pointer, class Reference>
Reference
DequeIter<Category, T, Distance, Pointer, Reference>::operator[](difference_type n) const
{
	return (*(*this + n));
}

template <class Category, class T, class Distance, class Pointer, class Reference>
DequeIter<Category, T, Distance, Pointer, Reference>&
DequeIter<Category, T, Distance, Pointer, Reference>::operator++(void)
{
	*this += 1;
	return (*this);
}

template <class Category, class T, class Distance, class Pointer, class Reference>
DequeIter<Category, T, Distance, Pointer, Reference>
DequeIter<Category, T, Distance, Pointer, Reference>::operator++(int dummy)
{
	DequeIter<Category, T, Distance, Pointer, Reference>	tmp(*this);

	(void)dummy;
	*this += 1;
	return (tmp);
}

template <class Category, class T, class Distance, class Pointer, class Reference>
DequeIter<Category, T, Distance, Pointer, Reference>&
DequeIter<Category, T, Distance, Pointer, Reference>::operator--(void)
{
	*this -= 1;	
	return (*this);
}

template <class Category, class T, class Distance, class Pointer, class Reference>
DequeIter<Category, T, Distance, Pointer, Reference>
DequeIter<Category, T, Distance, Pointer, Reference>::operator--(int dummy)
{
	DequeIter<Category, T, Distance, Pointer, Reference>	tmp(*this);

	(void)dummy;
	*this -= 1;	
	return (tmp);
}

template <class Category, class T, class Distance, class Pointer, class Reference>
DequeIter<Category, T, Distance, Pointer, Reference>
DequeIter<Category, T, Distance, Pointer, Reference>::operator+(difference_type n) const
{
	DequeIter<Category, T, Distance, Pointer, Reference>	tmp(*this);
	
	tmp += n;
	return (tmp);
}

template <class Category, class T, class Distance, class Pointer, class Reference>
DequeIter<Category, T, Distance, Pointer, Reference>
DequeIter<Category, T, Distance, Pointer, Reference>::operator-(difference_type n) const
{
	DequeIter<Category, T, Distance, Pointer, Reference>	tmp(*this);
	
	tmp -= n;
	return (tmp);
}

template <class Category, class T, class Distance, class Pointer, class Reference>
DequeIter<Category, T, Distance, Pointer, Reference>
&DequeIter<Category, T, Distance, Pointer, Reference>::operator+=(difference_type n)
{
	if (_side == up)
		_id += n;
	else if (_id < (size_t)n)
	{
		_side = up;
		_id = (_id - n + 1) * -1;
	}
	else
		_id -= n;
	return (*this);
}

template <class Category, class T, class Distance, class Pointer, class Reference>
DequeIter<Category, T, Distance, Pointer, Reference>
&DequeIter<Category, T, Distance, Pointer, Reference>::operator-=(difference_type n)
{
	if (_side == down)
		_id += n;
	else if (_id < (size_t)n)
	{
		_side = down;
		_id = (_id - n + 1) * -1;
	}
	else
		_id -= n;
	return (*this);
}

template <class Category, class T, class Distance, class Pointer, class Reference>
DequeIter<Category, T, Distance, Pointer, Reference>
operator+(
	typename DequeIter<Category, T, Distance, Pointer, Reference>::difference_type n,
	const DequeIter<Category, T, Distance, Pointer, Reference> &v)
{
	return (v + n);
}

template <class Category, class T, class Distance, class Pointer, class Reference>
Distance
operator-(const DequeIter<Category, T, Distance, Pointer, Reference> &lhs,
	const DequeIter<Category, T, Distance, Pointer, Reference> &rhs)
{
	if (lhs._side == rhs._side)
		return ((lhs._id - rhs._id) * (lhs._side == up ? 1 : -1));
	else
		return ((lhs._id + rhs._id + 1) * (lhs._side == up ? 1 : -1));
}

template <class Category, class T, class Distance, class Pointer, class Reference>
bool	
operator<(const DequeIter<Category, T, Distance, Pointer, Reference> &lhs,
	const DequeIter<Category, T, Distance, Pointer, Reference> &rhs)
{
	if (lhs._side == rhs._side)
		return (lhs._side == up ? lhs._id < rhs._id : lhs._id > rhs._id);
	else
		return (lhs._side == up ? false : true);
}

template <class Category, class T, class Distance, class Pointer, class Reference>
bool	
operator<=(const DequeIter<Category, T, Distance, Pointer, Reference> &lhs,
	const DequeIter<Category, T, Distance, Pointer, Reference> &rhs)
{
	return (!(lhs > rhs));
}

template <class Category, class T, class Distance, class Pointer, class Reference>
bool	
operator>(const DequeIter<Category, T, Distance, Pointer, Reference> &lhs,
	const DequeIter<Category, T, Distance, Pointer, Reference> &rhs)
{
	return (rhs < lhs);
}

template <class Category, class T, class Distance, class Pointer, class Reference>
bool	
operator>=(const DequeIter<Category, T, Distance, Pointer, Reference> &lhs,
	const DequeIter<Category, T, Distance, Pointer, Reference> &rhs)
{
	return (!(lhs < rhs));
}

}

#endif //DEQUEITER_HPP
