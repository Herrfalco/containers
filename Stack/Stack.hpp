/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcadet <cadet.florian@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 12:21:56 by fcadet            #+#    #+#             */
/*   Updated: 2020/03/22 17:10:07 by fcadet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
# define STACK_HPP

# include "../Deque/Deque.hpp"

namespace	ft
{

template <class T, class Container = ft::Deque<T> >
class	Stack
{
	public:
		//Member types :
		typedef T					value_type;
		typedef	Container			container_type;
		typedef size_t				size_type;

		//Constructors, destructor :
		explicit Stack(const container_type &ctnr = container_type());
		~Stack(void);

		//Capacity :
		bool					empty() const;
		size_type				size() const;
		value_type				&top();
		const value_type		&top() const;
		void					push(const value_type &val);
		void					pop();

	private:
		//Friendship :
		template <class T2, class Container2>
		friend bool
		operator<(const Stack<T2, Container2> &lhs, const Stack<T2, Container2> &rhs);

		//Private constructor, destructor & assignation :
		Stack(const Stack &s);
		Stack					&operator=(const Stack &s);

		//Attibutes :
		Container			_cont;
};

template <class T, class Container>
Stack<T, Container>::Stack(const container_type &ctnr) : _cont(ctnr)
{
}

template <class T, class Container>
Stack<T, Container>::Stack(const Stack &s) : _cont(s._cont)
{
}

template <class T, class Container>
Stack<T, Container>::~Stack(void)
{
}

template <class T, class Container>
Stack<T, Container>
&Stack<T, Container>::operator=(const Stack &s)
{
	if (&s == this)
		return (*this);
	_cont = s._cont;
	return (*this);
}

template <class T, class Container>
bool
Stack<T, Container>::empty(void) const
{
	return (_cont.empty());
}

template <class T, class Container>
typename Stack<T, Container>::size_type
Stack<T, Container>::size(void) const
{
	return (_cont.size());
}

template <class T, class Container>
typename Stack<T, Container>::value_type
&Stack<T, Container>::top(void)
{
	return (_cont.back());
}

template <class T, class Container>
const typename Stack<T, Container>::value_type
&Stack<T, Container>::top(void) const
{
	return (_cont.back());
}

template <class T, class Container>
void
Stack<T, Container>::push(const value_type &val)
{
	_cont.push_back(val);
}

template <class T, class Container>
void
Stack<T, Container>::pop()
{
	_cont.pop_back();	
}

template <class T, class Container>
bool
operator==(const Stack<T, Container> &lhs, const Stack<T, Container> &rhs)
{
	return (!(lhs != rhs));
}

template <class T, class Container>
bool
operator!=(const Stack<T, Container> &lhs, const Stack<T, Container> &rhs)
{
	return (lhs < rhs || rhs < lhs);
}

template <class T, class Container>
bool
operator<(const Stack<T, Container> &lhs, const Stack<T, Container> &rhs)
{
	return (lhs._cont < rhs._cont);
}

template <class T, class Container>
bool
operator<=(const Stack<T, Container> &lhs, const Stack<T, Container> &rhs)
{
	return (!(lhs > rhs));
}

template <class T, class Container>
bool
operator>(const Stack<T, Container> &lhs, const Stack<T, Container> &rhs)
{
	return (rhs < lhs);
}

template <class T, class Container>
bool
operator>=(const Stack<T, Container> &lhs, const Stack<T, Container> &rhs)
{
	return (!(lhs < rhs));
}

}

#endif //STACK_HPP
