/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Queue.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcadet <cadet.florian@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 12:21:56 by fcadet            #+#    #+#             */
/*   Updated: 2020/03/28 18:48:45 by fcadet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUEUE_HPP
# define QUEUE_HPP

# include "../Deque/Deque.hpp"

namespace	ft
{

template <class T, class Container = ft::Deque<T> >
class	Queue
{
	public:
		//Member types :
		typedef T					value_type;
		typedef	Container			container_type;
		typedef size_t				size_type;

		//Constructors, destructor :
		explicit Queue(const container_type &ctnr = container_type());
		~Queue(void);

		//Capacity :
		bool					empty(void) const;
		size_type				size(void) const;
		value_type				&front(void);
		const value_type		&front(void) const;
		value_type				&back(void);
		const value_type		&back(void) const;
		void					push(const value_type &val);
		void					pop(void);

	private:
		//Friendship :
		template <class T2, class Container2>
		friend bool
		operator<(const Queue<T2, Container2> &lhs, const Queue<T2, Container2> &rhs);

		//Private constructor, destructor & assignation :
		Queue(const Queue &s);
		Queue					&operator=(const Queue &s);

		//Attibutes :
		Container			_cont;
};

template <class T, class Container>
Queue<T, Container>::Queue(const container_type &ctnr) : _cont(ctnr)
{
}

template <class T, class Container>
Queue<T, Container>::Queue(const Queue &s) : _cont(s._cont)
{
}

template <class T, class Container>
Queue<T, Container>::~Queue(void)
{
}

template <class T, class Container>
Queue<T, Container>
&Queue<T, Container>::operator=(const Queue &s)
{
	if (&s == this)
		return (*this);
	_cont = s._cont;
	return (*this);
}

template <class T, class Container>
bool
Queue<T, Container>::empty(void) const
{
	return (_cont.empty());
}

template <class T, class Container>
typename Queue<T, Container>::size_type
Queue<T, Container>::size(void) const
{
	return (_cont.size());
}

template <class T, class Container>
typename Queue<T, Container>::value_type
&Queue<T, Container>::front(void)
{
	return (_cont.front());
}

template <class T, class Container>
const typename Queue<T, Container>::value_type
&Queue<T, Container>::front(void) const
{
	return (_cont.front());
}

template <class T, class Container>
typename Queue<T, Container>::value_type
&Queue<T, Container>::back(void)
{
	return (_cont.back());
}

template <class T, class Container>
const typename Queue<T, Container>::value_type
&Queue<T, Container>::back(void) const
{
	return (_cont.back());
}

template <class T, class Container>
void
Queue<T, Container>::push(const value_type &val)
{
	_cont.push_back(val);
}

template <class T, class Container>
void
Queue<T, Container>::pop(void)
{
	_cont.pop_front();
}

template <class T, class Container>
bool
operator==(const Queue<T, Container> &lhs, const Queue<T, Container> &rhs)
{
	return (!(lhs != rhs));
}

template <class T, class Container>
bool
operator!=(const Queue<T, Container> &lhs, const Queue<T, Container> &rhs)
{
	return (lhs < rhs || rhs < lhs);
}

template <class T, class Container>
bool
operator<(const Queue<T, Container> &lhs, const Queue<T, Container> &rhs)
{
	return (lhs._cont < rhs._cont);
}

template <class T, class Container>
bool
operator<=(const Queue<T, Container> &lhs, const Queue<T, Container> &rhs)
{
	return (!(lhs > rhs));
}

template <class T, class Container>
bool
operator>(const Queue<T, Container> &lhs, const Queue<T, Container> &rhs)
{
	return (rhs < lhs);
}

template <class T, class Container>
bool
operator>=(const Queue<T, Container> &lhs, const Queue<T, Container> &rhs)
{
	return (!(lhs < rhs));
}

}

#endif //QUEUE_HPP
