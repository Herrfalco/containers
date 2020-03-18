/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RevIter.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcadet <cadet.florian@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 20:10:41 by fcadet            #+#    #+#             */
/*   Updated: 2020/03/19 00:46:25 by fcadet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVITER_HPP
# define REVITER_HPP

namespace	ft
{

template <class Iter>
class	RevIter
{
	public:
		//Member types :
		typedef	Iter								iterator_type;
		typedef typename Iter::iterator_category	iterator_category;
		typedef typename Iter::value_type			value_type;
		typedef typename Iter::difference_type		difference_type;
		typedef typename Iter::pointer				pointer;
		typedef typename Iter::reference			reference;

		//Constructors and destructor :
		RevIter(void);
		RevIter(iterator_type it);
		RevIter(const RevIter<iterator_type> &r);
		~RevIter(void);

		//Access operators :
		iterator_type	base() const;
		reference		operator*(void) const;
		RevIter			operator+(difference_type n) const;
		RevIter			&operator++(void);
		RevIter			operator++(int dummy);
		RevIter			&operator+=(difference_type n);
		RevIter			operator-(difference_type n) const;
		RevIter			&operator--(void);
		RevIter			operator--(int dummy);
		RevIter			&operator-=(difference_type n);
		pointer			operator->(void) const;
		reference		operator[](difference_type n) const;

	private:
		//Attibutes :
		iterator_type	_base;

		//Non-member overloads :
		template <class Iter2>
		friend bool		operator==(const RevIter<Iter2> &lhs, const RevIter<Iter2> &rhs);
		template <class Iter2>
		friend bool		operator<(const RevIter<Iter2> &lhs, const RevIter<Iter2> &rhs);
		template <class Iter2>
		friend typename Iter2::difference_type	operator-(const RevIter<Iter2> &lhs,
			const RevIter<Iter2> &rhs);
};

template <class Iter>
RevIter<Iter>::RevIter(void) : _base()
{
}

template <class Iter>
RevIter<Iter>::RevIter(iterator_type it) : _base(it)
{
}

template <class Iter>
RevIter<Iter>::RevIter(const RevIter<Iter> &r) : _base(r._base)
{
}

template <class Iter>
RevIter<Iter>::~RevIter(void)
{
}

template <class Iter>
Iter
RevIter<Iter>::base() const
{
	return (_base);
}

template <class Iter>
typename Iter::reference
RevIter<Iter>::operator*(void) const
{
	Iter	tmp(_base);

	return (*(--tmp));
}

template <class Iter>
RevIter<Iter>
RevIter<Iter>::operator+(typename Iter::difference_type n) const
{
	return (RevIter<Iter>(_base - n));
}

template <class Iter>
RevIter<Iter>
&RevIter<Iter>::operator++(void)
{
	--_base;
	return (*this);
}

template <class Iter>
RevIter<Iter>
RevIter<Iter>::operator++(int dummy)
{
	Iter	tmp(_base);

	(void)dummy;
	--_base;
	return (RevIter<Iter>(tmp));
}

template <class Iter>
RevIter<Iter>
&RevIter<Iter>::operator+=(typename Iter::difference_type n)
{
	_base -= n;
	return (*this);
}

template <class Iter>
RevIter<Iter>
RevIter<Iter>::operator-(typename Iter::difference_type n) const
{
	return (RevIter<Iter>(_base + n));
}

template <class Iter>
RevIter<Iter>
&RevIter<Iter>::operator--(void)
{
	++_base;
	return (*this);
}

template <class Iter>
RevIter<Iter>
RevIter<Iter>::operator--(int dummy)
{
	Iter	tmp(_base);

	(void)dummy;
	++_base;
	return (RevIter<Iter>(tmp));
}

template <class Iter>
RevIter<Iter>
&RevIter<Iter>::operator-=(typename Iter::difference_type n)
{
	_base += n;
	return (*this);
}

template <class Iter>
typename Iter::pointer
RevIter<Iter>::operator->(void) const
{
	Iter	tmp(_base);

	return ((--tmp).operator->());
}

template <class Iter>
typename Iter::reference
RevIter<Iter>::operator[](typename Iter::difference_type n) const
{
	return (*((*this) + n));
}

template <class Iter>
bool
operator==(const RevIter<Iter> &lhs, const RevIter<Iter> &rhs)
{
	return (lhs._base == rhs._base);
}

template <class Iter>
bool
operator!=(const RevIter<Iter> &lhs, const RevIter<Iter> &rhs)
{
	return (!(lhs == rhs));
}

template <class Iter>
bool
operator<(const RevIter<Iter> &lhs, const RevIter<Iter> &rhs)
{
	return (lhs._base > rhs._base);
}

template <class Iter>
bool
operator<=(const RevIter<Iter> &lhs, const RevIter<Iter> &rhs)
{
	return (!(lhs > rhs));
}

template <class Iter>
bool
operator>(const RevIter<Iter> &lhs, const RevIter<Iter> &rhs)
{
	return (rhs < lhs);
}

template <class Iter>
bool
operator>=(const RevIter<Iter> &lhs, const RevIter<Iter> &rhs)
{
	return (!(lhs < rhs));
}

template <class Iter>
RevIter<Iter>
operator+(typename RevIter<Iter>::difference_type n, const RevIter<Iter> &rev_it)
{
	return (rev_it + n);
}

template <class Iter>
typename Iter::difference_type
operator-(const RevIter<Iter> &lhs, const RevIter<Iter> &rhs)
{
	return (rhs._base - lhs._base);
}

}

#endif //REVITER_HPP
