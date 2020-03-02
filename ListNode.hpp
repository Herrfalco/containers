/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ListNode.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcadet <cadet.florian@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 13:07:57 by fcadet            #+#    #+#             */
/*   Updated: 2020/03/01 17:07:21 by fcadet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LISTNODE_HPP
# define LISTNODE_HPP

template	<typename T>
struct		ListNode
{
		ListNode(ListNode<T> *p = 0, ListNode<T> *n = 0);
		ListNode(const ListNode<T> &l);
		~ListNode(void);
		ListNode<T>		&operator=(const ListNode<T> &l);

		ListNode	*prev;
		ListNode	*next;
		T			val;
};

template	<typename T>
ListNode<T>::ListNode(ListNode<T> *p, ListNode<T> *n) : prev(p), next(n), val()
{
}

template	<typename T>
ListNode<T>::ListNode(const ListNode<T> &l) : prev(0), next(0), val(l.val)
{
}

template	<typename T>
ListNode<T>::~ListNode(void)
{
}

template	<typename T>
ListNode<T>	&ListNode<T>::operator=(const ListNode<T> &l)
{
	if (&l == this)
		return (*this);
	val = l.val;
	return (*this);
}

#endif //LISTNODE_HPP
