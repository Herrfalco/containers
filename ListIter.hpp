/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ListIter.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcadet <cadet.florian@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 13:08:02 by fcadet            #+#    #+#             */
/*   Updated: 2020/03/02 16:19:57 by fcadet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LISTITER_HPP
# define LISTITER_HPP

# include <iterator>
# include "ListNode.hpp"

template <typename T>
class	ListIter : public std::iterator<std::bidirectional_iterator_tag, T >
{
	public:
		ListIter(ListNode<T> *node = 0);
		ListIter(const ListIter &l);
		~ListIter(void);
		ListIter		&operator=(const ListIter &l);
		bool			operator==(const ListIter &l);
		bool			operator!=(const ListIter &l);
		T				&operator*(void);
		T				*operator->(void);
		ListIter		&operator++(void);
		ListIter		operator++(int dummy);
		ListIter		&operator--(void);
		ListIter		operator--(int dummy);

	private:
		ListNode<T>		*_node;
};

template <typename T>
ListIter<T>::ListIter(ListNode<T> *n) : _node(n)
{
}

template <typename T>
ListIter<T>::ListIter(const ListIter<T> &l) : _node(l._node)
{
}

template <typename T>
ListIter<T>::~ListIter(void)
{
}

template <typename T>
ListIter<T>		&ListIter<T>::operator=(const ListIter &l)
{
	if (&l == this)
		return (*this);
	_node = l._node;
	return (*this);
}

template <typename T>
bool			ListIter<T>::operator==(const ListIter &l)
{
	return (_node == l._node);
}

template <typename T>
bool			ListIter<T>::operator!=(const ListIter &l)
{
	return (!(*this == l));
}

template <typename T>
T				&ListIter<T>::operator*(void)
{
	return (_node->val);
}

template <typename T>
T				*ListIter<T>::operator->(void)
{
	return (&_node->val);
}

template <typename T>
ListIter<T>		&ListIter<T>::operator++(void)
{
	_node = _node->next;
	return (*this);
}

template <typename T>
ListIter<T>		ListIter<T>::operator++(int dummy)
{
	ListIter<T>	tmp;

	tmp = *this;
	_node = _node->next;
	return (tmp);
}

template <typename T>
ListIter<T>		&ListIter<T>::operator--(void)
{
	_node = _node->prev;
	return (*this);
}

template <typename T>
ListIter<T>		ListIter<T>::operator--(int dummy)
{
	ListIter<T>	tmp;

	tmp = *this;
	_node = _node->prev;
	return (tmp);
}

#endif //LISTITER_HPP
