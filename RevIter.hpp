/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RevIter.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcadet <cadet.florian@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 20:10:41 by fcadet            #+#    #+#             */
/*   Updated: 2020/03/02 21:15:01 by fcadet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVITER_HPP
# define REVITER_HPP

template <class Iter>
class	RevIter
{
	public:
		typedef	Iter							iterator_type;
		typedef Iter::iterator_category			iterator_category;
		typedef Iter::value_type				value_type;
		typedef	Iter::difference_type			difference_type;
		typedef Iter::pointer					pointer;
		typedef	Iter::reference					reference;

		RevIter(void);
		RevIter(Iter it);
		RevIter(const RevIter<Iter> &r);
		~RevIter(void);
		Iter		base() const;
		T			&operator*(void) const;
		RevIter		operator+(Iter::difference_type n) const;
		RevIter		&operator++(void);
		RevIter		operator++(int dummy);
		RevIter		&operator+=(Iter:difference_type n);
		RevIter		operator-(Iter::difference_type n) const;
		RevIter		&operator--(void);
		RevIter		operator--(int dummy);
		RevIter		&operator-=(Iter:difference_type n);
		T			*operator->(void) const;
		T			&operator[](Iter:difference_type n) const;
		bool		operator==(const RevIter &l) const;
		bool		operator!=(const RevIter &l) const;
		bool		operator<(const RevIter &l) const;
		bool		operator<=(const RevIter &l) const;
		bool		operator>(const RevIter &l) const;
		bool		operator>=(const RevIter &l) const;

	private:
		Iter		_base;
};

template <class Iter>
RevIter<Iter>::RevIter(void) : _base()
{
}

template <class Iter>
RevIter<Iter>::RevIter(Iter it) : _base(it)
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
RevIter		&operator=(const RevIter &l)
{
}

template <class Iter>
bool		operator==(const RevIter &l) const
{
}

template <class Iter>
bool		operator!=(const RevIter &l) const
{
}

template <class Iter>
T			&operator*(void)
{
}

template <class Iter>
T			*operator->(void)
{
}

template <class Iter>
RevIter		&operator++(void)
{
}

template <class Iter>
RevIter		operator++(int dummy)
{
}

template <class Iter>
RevIter		&operator--(void)
{
}

template <class Iter>
RevIter		operator--(int dummy)
{
}

#endif //REVITER_HPP
