/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ListNode.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcadet <cadet.florian@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 13:07:57 by fcadet            #+#    #+#             */
/*   Updated: 2020/03/03 17:27:54 by fcadet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LISTNODE_HPP
# define LISTNODE_HPP

template	<typename T>
struct		ListNode
{
		ListNode(void);
		ListNode(const T &v, bool dummy = false, ListNode<T> *p = 0, ListNode<T> *n = 0);
		ListNode(const ListNode<T> &l);
		~ListNode(void);
		ListNode<T>		&operator=(const ListNode<T> &l);

		ListNode	*prev;
		ListNode	*next;
		T			val;
		T			*valptr;
};

template	<typename T>
ListNode<T>::ListNode(void) : prev(0), next(0), val(), valptr(0)
{
}

template	<typename T>
ListNode<T>::ListNode(const T &v, bool dummy, ListNode<T> *p, ListNode<T> *n) :
	prev(p), next(n), val(v), valptr(0)
{
	valptr = dummy ? 0 : &val;
}

template	<typename T>
ListNode<T>::ListNode(const ListNode<T> &l) :
	prev(l.prev), next(l.next), val(l.val), valptr(0)
{
	valptr = !l.valptr ? 0 : &val;
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
	valptr = !l.valptr ? 0 : &val;
	return (*this);
}

#endif //LISTNODE_HPP
