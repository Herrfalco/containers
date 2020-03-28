/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   VectorIter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcadet <cadet.florian@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 13:08:02 by fcadet            #+#    #+#             */
/*   Updated: 2020/03/28 16:35:35 by fcadet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTORITER_HPP
# define VECTORITER_HPP

# include <cstddef>

namespace	ft
{

template <class Category, class T, class Distance = std::ptrdiff_t,
	class Pointer = T*, class Reference = T&>
class	VectorIter
{
	public:
		//Member types :
		typedef T			value_type;
		typedef Distance	difference_type;
		typedef Pointer		pointer;
		typedef Reference	reference;
		typedef Category	iterator_category;

		//Constructors, destructor and assignation :
		VectorIter(value_type *p = 0);
		VectorIter(const VectorIter &v);
		~VectorIter(void);
		VectorIter		&operator=(const VectorIter &v);

		//Relational operators :
		bool			operator==(const VectorIter &v) const;
		bool			operator!=(const VectorIter &v) const;

		//Access operators :
		reference		operator*(void);
		pointer			operator->(void);
		reference		operator[](difference_type n) const;
		VectorIter		&operator++(void);
		VectorIter		operator++(int valptr);
		VectorIter		&operator--(void);
		VectorIter		operator--(int valptr);
		VectorIter		operator+(difference_type n) const;
		VectorIter		operator-(difference_type n) const;
		VectorIter		&operator+=(difference_type n);
		VectorIter		&operator-=(difference_type n);

		//Attibutes :
		value_type		*_ptr;

	private:
		//Friendship :
		template <class Cat, class T2, class Dist, class Point, class Refer>
		friend Dist		operator-(const VectorIter<Cat, T2, Dist, Point, Refer> &lhs,
			const VectorIter<Cat, T2, Dist, Point, Refer> &rhs);
		template <class Cat, class T2, class Dist, class Point, class Refer>
		friend bool		operator<(const VectorIter<Cat, T2, Dist, Point, Refer> &lhs,
			const VectorIter<Cat, T2, Dist, Point, Refer> &rhs);
};

template <class Category, class T, class Distance, class Pointer, class Reference>
VectorIter<Category, T, Distance, Pointer, Reference>::VectorIter(value_type *p) : _ptr(p)
{
}

template <class Category, class T, class Distance, class Pointer, class Reference>
VectorIter<Category, T, Distance, Pointer, Reference>::VectorIter(const
	VectorIter<Category, T, Distance, Pointer, Reference> &v) : _ptr(v._ptr)
{
}

template <class Category, class T, class Distance, class Pointer, class Reference>
VectorIter<Category, T, Distance, Pointer, Reference>::~VectorIter(void)
{
}

template <class Category, class T, class Distance, class Pointer, class Reference>
VectorIter<Category, T, Distance, Pointer, Reference>&
VectorIter<Category, T, Distance, Pointer, Reference>::operator=(const VectorIter &v)
{
	if (&v == this)
		return (*this);
	_ptr = v._ptr;
	return (*this);
}

template <class Category, class T, class Distance, class Pointer, class Reference>
bool
VectorIter<Category, T, Distance, Pointer, Reference>::operator==(const
	VectorIter &v) const
{
	return (_ptr == v._ptr);
}

template <class Category, class T, class Distance, class Pointer, class Reference>
bool
VectorIter<Category, T, Distance, Pointer, Reference>::operator!=(const
	VectorIter &v) const
{
	return (!(*this == v));
}

template <class Category, class T, class Distance, class Pointer, class Reference>
Reference
VectorIter<Category, T, Distance, Pointer, Reference>::operator*(void)
{
	return (*_ptr);
}

template <class Category, class T, class Distance, class Pointer, class Reference>
Pointer
VectorIter<Category, T, Distance, Pointer, Reference>::operator->(void)
{
	return (_ptr);
}

template <class Category, class T, class Distance, class Pointer, class Reference>
Reference
VectorIter<Category, T, Distance, Pointer, Reference>::operator[](difference_type n) const
{
	return (*(_ptr + n));
}

template <class Category, class T, class Distance, class Pointer, class Reference>
VectorIter<Category, T, Distance, Pointer, Reference>&
VectorIter<Category, T, Distance, Pointer, Reference>::operator++(void)
{
	++_ptr;
	return (*this);
}

template <class Category, class T, class Distance, class Pointer, class Reference>
VectorIter<Category, T, Distance, Pointer, Reference>
VectorIter<Category, T, Distance, Pointer, Reference>::operator++(int dummy)
{
	VectorIter<Category, T, Distance, Pointer, Reference>	tmp(*this);

	(void)dummy;
	++_ptr;
	return (tmp);
}

template <class Category, class T, class Distance, class Pointer, class Reference>
VectorIter<Category, T, Distance, Pointer, Reference>&
VectorIter<Category, T, Distance, Pointer, Reference>::operator--(void)
{
	--_ptr;
	return (*this);
}

template <class Category, class T, class Distance, class Pointer, class Reference>
VectorIter<Category, T, Distance, Pointer, Reference>
VectorIter<Category, T, Distance, Pointer, Reference>::operator--(int dummy)
{
	VectorIter<Category, T, Distance, Pointer, Reference>	tmp(*this);

	(void)dummy;
	--_ptr;
	return (tmp);
}

template <class Category, class T, class Distance, class Pointer, class Reference>
VectorIter<Category, T, Distance, Pointer, Reference>
VectorIter<Category, T, Distance, Pointer, Reference>::operator+(difference_type n) const
{
	VectorIter<Category, T, Distance, Pointer, Reference>	tmp(*this);
	
	tmp._ptr += n;
	return (tmp);
}

template <class Category, class T, class Distance, class Pointer, class Reference>
VectorIter<Category, T, Distance, Pointer, Reference>
VectorIter<Category, T, Distance, Pointer, Reference>::operator-(difference_type n) const
{
	VectorIter<Category, T, Distance, Pointer, Reference>	tmp(*this);
	
	tmp._ptr -= n;
	return (tmp);
}

template <class Category, class T, class Distance, class Pointer, class Reference>
VectorIter<Category, T, Distance, Pointer, Reference>
&VectorIter<Category, T, Distance, Pointer, Reference>::operator+=(difference_type n)
{
	_ptr += n;
	return (*this);
}

template <class Category, class T, class Distance, class Pointer, class Reference>
VectorIter<Category, T, Distance, Pointer, Reference>
&VectorIter<Category, T, Distance, Pointer, Reference>::operator-=(difference_type n)
{
	_ptr -= n;
	return (*this);
}

template <class Category, class T, class Distance, class Pointer, class Reference>
VectorIter<Category, T, Distance, Pointer, Reference>
operator+(typename VectorIter<Category, T, Distance, Pointer, Reference>::
	difference_type n, const VectorIter<Category, T, Distance, Pointer, Reference> &v)
{
	return (v + n);
}

template <class Category, class T, class Distance, class Pointer, class Reference>
Distance
operator-(const VectorIter<Category, T, Distance, Pointer, Reference> &lhs,
	const VectorIter<Category, T, Distance, Pointer, Reference> &rhs)
{
	return (lhs._ptr - rhs._ptr);
}

template <class Category, class T, class Distance, class Pointer, class Reference>
bool	
operator<(const VectorIter<Category, T, Distance, Pointer, Reference> &lhs,
	const VectorIter<Category, T, Distance, Pointer, Reference> &rhs)
{
	return (lhs._ptr < rhs._ptr);
}

template <class Category, class T, class Distance, class Pointer, class Reference>
bool	
operator<=(const VectorIter<Category, T, Distance, Pointer, Reference> &lhs,
	const VectorIter<Category, T, Distance, Pointer, Reference> &rhs)
{
	return (!(lhs > rhs));
}

template <class Category, class T, class Distance, class Pointer, class Reference>
bool	
operator>(const VectorIter<Category, T, Distance, Pointer, Reference> &lhs,
	const VectorIter<Category, T, Distance, Pointer, Reference> &rhs)
{
	return (rhs < lhs);
}

template <class Category, class T, class Distance, class Pointer, class Reference>
bool	
operator>=(const VectorIter<Category, T, Distance, Pointer, Reference> &lhs,
	const VectorIter<Category, T, Distance, Pointer, Reference> &rhs)
{
	return (!(lhs < rhs));
}

}

#endif //VECTORITER_HPP
