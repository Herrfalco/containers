/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ListNode.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcadet <cadet.florian@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 13:07:57 by fcadet            #+#    #+#             */
/*   Updated: 2020/03/01 16:55:37 by fcadet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LISTNODE_HPP
# define LISTNODE_HPP

template	<typename T>
class		ListNode
{
	public:
		ListNode(ListNode<T> *prev = 0, ListNode<T> *next = 0);
		ListNode(const ListNode<T> &l);
		~ListNode(void);
		ListNode<T>		&operator=(const ListNode<T> &l);
		void			set_prev(ListNode<T> *prev);
		ListNode<T>		*get_prev(void);
		void			set_next(ListNode<T> *next);
		ListNode<T>		*get_next(void);
		void			set_val(const T &val);
		T				get_val(void) const;

	private:
		ListNode	*_prev;
		ListNode	*_next;
		T			_val;
};

template	<typename T>
ListNode<T>::ListNode(ListNode<T> *prev, ListNode<T> *next) : _prev(prev), _next(next), _val()
{
}

template	<typename T>
ListNode<T>::ListNode(const ListNode<T> &l) : _prev(0), _next(0), _val(l._val)
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
	_val = l._val;
	return (*this);
}

template	<typename T>
void		ListNode<T>::set_prev(ListNode<T> *prev)
{
	_prev = prev;
}

template	<typename T>
ListNode<T>	*ListNode<T>::get_prev(void)
{
	return (_prev);
}

template	<typename T>
void		ListNode<T>::set_next(ListNode<T> *next)
{
	_next = next;
}

template	<typename T>
ListNode<T>	*ListNode<T>::get_next(void)
{
	return (_next);
}

template	<typename T>
void		ListNode<T>::set_val(const T &val)
{
	_val = val;
}

template	<typename T>
T			ListNode<T>::get_val(void) const
{
	return (_val);
}

#endif //LISTNODE_HPP
