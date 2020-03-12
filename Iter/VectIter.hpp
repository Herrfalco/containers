/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   VectIter.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcadet <cadet.florian@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 13:08:02 by fcadet            #+#    #+#             */
/*   Updated: 2020/03/11 16:09:31 by fcadet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTITER_HPP
# define VECTITER_HPP

# include <cstddef>

template <class Category, class T, class Distance = std::ptrdiff_t,
	class Pointer = T*, class Reference = T&>
struct	VectIter
{
		//Member types :
		typedef T			value_type;
		typedef Distance	difference_type;
		typedef Pointer		pointer;
		typedef Reference	reference;
		typedef Category	iterator_category;

		//Constructors, destructor and assignation :
		VectIter(value_type *p = 0);
		VectIter(const VectIter &v);
		~VectIter(void);
		VectIter		&operator=(const VectIter &v);

		//Relational operators :
		bool			operator==(const VectIter &v) const;
		bool			operator!=(const VectIter &v) const;

		//Access operators :
		reference		operator*(void);
		pointer			operator->(void);
		reference		operator[](difference_type n) const;
		VectIter		&operator++(void);
		VectIter		operator++(int valptr);
		VectIter		&operator--(void);
		VectIter		operator--(int valptr);
		VectIter		operator+(difference_type n) const;
		VectIter		operator-(difference_type n) const;
		VectIter		&operator+=(difference_type n);
		VectIter		&operator-=(difference_type n);

		//Non-member overloads :
		template <class Cat, class T2, class Dist, class Point, class Refer>
		friend VectIter			operator+(difference_type n, const VectIter &v);
		template <class Cat, class T2, class Dist, class Point, class Refer>
		friend difference_type	operator-(const VectIter &lhs, const VectIter &rhs);
		template <class Cat, class T2, class Dist, class Point, class Refer>
		friend bool				operator<(const VectIter &lhs, const VectIter &rhs);
		template <class Cat, class T2, class Dist, class Point, class Refer>
		friend bool				operator<=(const VectIter &lhs, const VectIter &rhs);
		template <class Cat, class T2, class Dist, class Point, class Refer>
		friend bool				operator>(const VectIter &lhs, const VectIter &rhs);
		template <class Cat, class T2, class Dist, class Point, class Refer>
		friend bool				operator>=(const VectIter &lhs, const VectIter &rhs);

		//Attibutes :
		value_type		*ptr;
};

template <class Category, class T, class Distance, class Pointer, class Reference>
VectIter<Category, T, Distance, Pointer, Reference>::VectIter(value_type *p) : ptr(p)
{
}

template <class Category, class T, class Distance, class Pointer, class Reference>
VectIter<Category, T, Distance, Pointer, Reference>::VectIter(const VectIter<Category,
	T, Distance, Pointer, Reference> &v) : ptr(v.ptr)
{
}

template <class Category, class T, class Distance, class Pointer, class Reference>
VectIter<Category, T, Distance, Pointer, Reference>::~VectIter(void)
{
}

template <class Category, class T, class Distance, class Pointer, class Reference>
VectIter<Category, T, Distance, Pointer, Reference>&
VectIter<Category, T, Distance, Pointer, Reference>::operator=(const VectIter &v)
{
	if (&v == this)
		return (*this);
	ptr = v.ptr;
	return (*this);
}

template <class Category, class T, class Distance, class Pointer, class Reference>
bool
VectIter<Category, T, Distance, Pointer, Reference>::operator==(const VectIter &v) const
{
	return (ptr == v.ptr);
}

template <class Category, class T, class Distance, class Pointer, class Reference>
bool
VectIter<Category, T, Distance, Pointer, Reference>::operator!=(const VectIter &v) const
{
	return (!(*this == v));
}

template <class Category, class T, class Distance, class Pointer, class Reference>
Reference
VectIter<Category, T, Distance, Pointer, Reference>::operator*(void)
{
	return (*ptr);
}

template <class Category, class T, class Distance, class Pointer, class Reference>
Pointer
VectIter<Category, T, Distance, Pointer, Reference>::operator->(void)
{
	return (ptr);
}

template <class Category, class T, class Distance, class Pointer, class Reference>
Reference
VectIter<Category, T, Distance, Pointer, Reference>::operator[](difference_type n) const
{
	return (*(ptr + n));
}

template <class Category, class T, class Distance, class Pointer, class Reference>
VectIter<Category, T, Distance, Pointer, Reference>&
VectIter<Category, T, Distance, Pointer, Reference>::operator++(void)
{
	++ptr;
	return (*this);
}

template <class Category, class T, class Distance, class Pointer, class Reference>
VectIter<Category, T, Distance, Pointer, Reference>
VectIter<Category, T, Distance, Pointer, Reference>::operator++(int dummy)
{
	VectIter<Category, T, Distance, Pointer, Reference>	tmp(*this);

	(void)dummy;
	++ptr;
	return (tmp);
}

template <class Category, class T, class Distance, class Pointer, class Reference>
VectIter<Category, T, Distance, Pointer, Reference>&
VectIter<Category, T, Distance, Pointer, Reference>::operator--(void)
{
	--ptr;
	return (*this);
}

template <class Category, class T, class Distance, class Pointer, class Reference>
VectIter<Category, T, Distance, Pointer, Reference>
VectIter<Category, T, Distance, Pointer, Reference>::operator--(int dummy)
{
	VectIter<Category, T, Distance, Pointer, Reference>	tmp(*this);

	(void)dummy;
	--ptr;
	return (tmp);
}

template <class Category, class T, class Distance, class Pointer, class Reference>
VectIter<Category, T, Distance, Pointer, Reference>
VectIter<Category, T, Distance, Pointer, Reference>::operator+(difference_type n) const
{
	VectIter<Category, T, Distance, Pointer, Reference>	tmp(*this);
	
	tmp.ptr += n;
	return (tmp);
}

template <class Category, class T, class Distance, class Pointer, class Reference>
VectIter<Category, T, Distance, Pointer, Reference>
VectIter<Category, T, Distance, Pointer, Reference>::operator-(difference_type n) const
{
	VectIter<Category, T, Distance, Pointer, Reference>	tmp(*this);
	
	tmp.ptr -= n;
	return (tmp);
}

template <class Category, class T, class Distance, class Pointer, class Reference>
VectIter<Category, T, Distance, Pointer, Reference>
&VectIter<Category, T, Distance, Pointer, Reference>::operator+=(difference_type n)
{
	ptr += n;
	return (*this);
}

template <class Category, class T, class Distance, class Pointer, class Reference>
VectIter<Category, T, Distance, Pointer, Reference>
&VectIter<Category, T, Distance, Pointer, Reference>::operator-=(difference_type n)
{
	ptr -= n;
	return (*this);
}

template <class Category, class T, class Distance, class Pointer, class Reference>
VectIter<Category, T, Distance, Pointer, Reference>
operator+(typename VectIter<Category, T, Distance, Pointer, Reference>::difference_type n,
	const VectIter<Category, T, Distance, Pointer, Reference> &v)
{
	return (v + n);
}

template <class Category, class T, class Distance, class Pointer, class Reference>
typename VectIter<Category, T, Distance, Pointer, Reference>::difference_type
operator-(const VectIter<Category, T, Distance, Pointer, Reference> &lhs,
	const VectIter<Category, T, Distance, Pointer, Reference> &rhs)
{
	return (lhs.ptr - rhs.ptr);
}

template <class Category, class T, class Distance, class Pointer, class Reference>
bool	
operator<(const VectIter<Category, T, Distance, Pointer, Reference> &lhs,
	const VectIter<Category, T, Distance, Pointer, Reference> &rhs)
{
	return (lhs.ptr < rhs.ptr);
}

template <class Category, class T, class Distance, class Pointer, class Reference>
bool	
operator<=(const VectIter<Category, T, Distance, Pointer, Reference> &lhs,
	const VectIter<Category, T, Distance, Pointer, Reference> &rhs)
{
	return (!(lhs > rhs));
}

template <class Category, class T, class Distance, class Pointer, class Reference>
bool	
operator>(const VectIter<Category, T, Distance, Pointer, Reference> &lhs,
	const VectIter<Category, T, Distance, Pointer, Reference> &rhs)
{
	return (rhs < lhs);
}

template <class Category, class T, class Distance, class Pointer, class Reference>
bool	
operator>=(const VectIter<Category, T, Distance, Pointer, Reference> &lhs,
	const VectIter<Category, T, Distance, Pointer, Reference> &rhs)
{
	return (!(lhs < rhs));
}

#endif //VECTITER_HPP