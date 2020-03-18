/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcadet <cadet.florian@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/18 15:27:28 by fcadet            #+#    #+#             */
/*   Updated: 2020/03/19 00:42:44 by fcadet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PAIR_HPP
# define PAIR_HPP

namespace ft
{

template <class T1, class T2>
struct	Pair
{
	public:
		//Member types :
		typedef T1		first_type;
		typedef T2		second_type;

		//Constructors and assignation :
		Pair(void);
		template <class U, class V>
		Pair(const Pair<U, V> &pr);
		Pair(const first_type &a, const second_type &b);
		Pair	&operator=(const Pair &pr);

		//Attributes :
		first_type	first;
		second_type	second;

	private:
		//Non member overloads :
		template <class U1, class U2>
		friend bool operator<  (const Pair<U1,U2>& lhs, const Pair<U1,U2>& rhs);
};

template <class T1, class T2>
Pair<T1, T2>::Pair(void) : first(), second()
{
}

template <class T1, class T2>
template <class U, class V>
Pair<T1, T2>::Pair(const Pair<U, V> &pr) : first(pr.first), second(pr.second)
{
}

template <class T1, class T2>
Pair<T1, T2>::Pair(const T1 &a, const T2 &b) : first(a), second(b)
{
}

template <class T1, class T2>
Pair<T1, T2>
&Pair<T1, T2>::operator=(const Pair<T1, T2> &pr)
{
	if (this == &pr)
		return (*this);
	first = pr.first;
	second = pr.second;
	return (*this);
}

template <class T1, class T2>
bool
operator==(const Pair<T1,T2> &lhs, const Pair<T1,T2> &rhs)
{
	return (!(lhs < rhs || lhs > rhs));
}

template <class T1, class T2>
bool
operator!=(const Pair<T1,T2> &lhs, const Pair<T1,T2> &rhs)
{
	return !(lhs == rhs);
}

template <class T1, class T2>
bool
operator<(const Pair<T1,T2> &lhs, const Pair<T1,T2> &rhs)
{
	return (lhs.first < rhs.first || (!(rhs.first < lhs.first) && lhs.second < rhs.second));
}

template <class T1, class T2>
bool
operator<=(const Pair<T1,T2> &lhs, const Pair<T1,T2> &rhs)
{
	return !(rhs < lhs);
}

template <class T1, class T2>
bool
operator>(const Pair<T1,T2> &lhs, const Pair<T1,T2> &rhs)
{
	return (rhs < lhs);
}

template <class T1, class T2>
bool
operator>=(const Pair<T1,T2> &lhs, const Pair<T1,T2> &rhs)
{
	return !(lhs < rhs);
}

template <class T1, class T2>
Pair<T1, T2>
make_pair(T1 x, T2 y)
{
	return (Pair<T1,T2>(x, y));
}

}

#endif //PAIR_HPP
