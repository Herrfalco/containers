/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RevIter.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcadet <cadet.florian@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 20:10:41 by fcadet            #+#    #+#             */
/*   Updated: 2020/03/03 16:03:31 by fcadet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVITER_HPP
# define REVITER_HPP

template <class Iter>
class	RevIter
{
	public:
		typedef	Iter								iterator_type;
		typedef typename Iter::iterator_category	iterator_category;
		typedef typename Iter::value_type			value_type;
		typedef typename Iter::difference_type		difference_type;
		typedef typename Iter::pointer				pointer;
		typedef typename Iter::reference			reference;

		RevIter(void);
		RevIter(iterator_type it);
		RevIter(const RevIter<iterator_type> &r);
		~RevIter(void);
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
		bool			operator==(const RevIter &l) const;
		bool			operator!=(const RevIter &l) const;
		bool			operator<(const RevIter &l) const;
		bool			operator<=(const RevIter &l) const;
		bool			operator>(const RevIter &l) const;
		bool			operator>=(const RevIter &l) const;

	private:
		iterator_type	_base;
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
	Iter	tmp(_base);

	while (n--)
		--tmp;
	return (RevIter<Iter>(tmp));
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

	--_base;
	return (RevIter<Iter>(tmp));
}

template <class Iter>
RevIter<Iter>
&RevIter<Iter>::operator+=(typename Iter::difference_type n)
{
	while (n--)
		--_base;
	return (*this);
}

template <class Iter>
RevIter<Iter>
RevIter<Iter>::operator-(typename Iter::difference_type n) const
{
	Iter	tmp(_base);

	while (n--)
		++tmp;
	return (RevIter<Iter>(tmp));
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

	++_base;
	return (RevIter<Iter>(tmp));
}

template <class Iter>
RevIter<Iter>
&RevIter<Iter>::operator-=(typename Iter::difference_type n)
{
	while (n--)
		++_base;
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
	RevIter<Iter>	tmp(*this);

	while (n--)
		tmp++;
	return (*tmp);
}

template <class Iter>
bool
RevIter<Iter>::operator==(const RevIter &l) const
{
	return (this->_base == l._base);
}

template <class Iter>
bool
RevIter<Iter>::operator!=(const RevIter &l) const
{
	return (!(*this == l));
}

template <class Iter>
bool
RevIter<Iter>::operator<(const RevIter &l) const
{
	return (*this > l);
}

template <class Iter>
bool
RevIter<Iter>::operator<=(const RevIter &l) const
{
	return (*this >= l);
}

template <class Iter>
bool
RevIter<Iter>::operator>(const RevIter &l) const
{
	return (*this < l);
}

template <class Iter>
bool
RevIter<Iter>::operator>=(const RevIter &l) const
{
	return (*this <= l);
}

#endif //REVITER_HPP
