/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ListNode.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcadet <cadet.florian@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 13:07:57 by fcadet            #+#    #+#             */
/*   Updated: 2020/03/12 20:48:55 by fcadet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LISTNODE_HPP
# define LISTNODE_HPP

template	<typename T>
struct		ListNode
{
	//Constructors, destructor and assignation :
	ListNode(void);
	ListNode(const T &v, bool dummy = false, ListNode<T> *p = 0, ListNode<T> *n = 0);
	ListNode(const ListNode<T> &l);
	~ListNode(void);
	ListNode<T>		&operator=(const ListNode<T> &l);

	//Attributes :
	ListNode	*prev;
	ListNode	*next;
	T			val;
	T			*valptr;
};

template	<typename T>
ListNode<T>::ListNode(void) : prev(this), next(this), val(), valptr(0)
{
}

template	<typename T>
ListNode<T>::ListNode(const T &v, bool dummy, ListNode<T> *p, ListNode<T> *n) :
	prev(p), next(n), val(v), valptr(0)
{
	prev = prev ? prev : this;
	next = next ? next : this;
	valptr = dummy ? 0 : &val;
}

template	<typename T>
ListNode<T>::ListNode(const ListNode<T> &l) :
	prev(this), next(this), val(l.val), valptr(0)
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
