/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ListIter.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcadet <cadet.florian@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 13:08:02 by fcadet            #+#    #+#             */
/*   Updated: 2020/03/07 16:12:52 by fcadet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LISTITER_HPP
# define LISTITER_HPP

# include <cstddef>
# include "ListNode.hpp"

template <class Category, class T, class Distance = std::ptrdiff_t,
	class Pointer = T*, class Reference = T&>
struct	ListIter
{
		//Member types :
		typedef T			value_type;
		typedef Distance	difference_type;
		typedef Pointer		pointer;
		typedef Reference	reference;
		typedef Category	iterator_category;

		//Constructors, destructor and assignation :
		ListIter(ListNode<value_type> *n = 0);
		ListIter(const ListIter &l);
		~ListIter(void);
		ListIter		&operator=(const ListIter &l);

		//Relational operators :
		bool			operator==(const ListIter &l) const;
		bool			operator!=(const ListIter &l) const;

		//Access operators :
		reference		operator*(void);
		pointer			operator->(void);
		ListIter		&operator++(void);
		ListIter		operator++(int valptr);
		ListIter		&operator--(void);
		ListIter		operator--(int valptr);

		//Attibutes :
		ListNode<value_type>		*node;
};

template <class Category, class T, class Distance, class Pointer, class Reference>
ListIter<Category, T, Distance, Pointer, Reference>::ListIter(ListNode<T> *n) : node(n)
{
}

template <class Category, class T, class Distance, class Pointer, class Reference>
ListIter<Category, T, Distance, Pointer, Reference>::ListIter(const ListIter<Category,
	T, Distance, Pointer, Reference> &l) : node(l.node)
{
}

template <class Category, class T, class Distance, class Pointer, class Reference>
ListIter<Category, T, Distance, Pointer, Reference>::~ListIter(void)
{
}

template <class Category, class T, class Distance, class Pointer, class Reference>
ListIter<Category, T, Distance, Pointer, Reference>&
ListIter<Category, T, Distance, Pointer, Reference>::operator=(const ListIter &l)
{
	if (&l == this)
		return (*this);
	node = l.node;
	return (*this);
}

template <class Category, class T, class Distance, class Pointer, class Reference>
bool
ListIter<Category, T, Distance, Pointer, Reference>::operator==(const ListIter &l) const
{
	return (node == l.node);
}

template <class Category, class T, class Distance, class Pointer, class Reference>
bool
ListIter<Category, T, Distance, Pointer, Reference>::operator!=(const ListIter &l) const
{
	return (!(*this == l));
}

template <class Category, class T, class Distance, class Pointer, class Reference>
Reference
ListIter<Category, T, Distance, Pointer, Reference>::operator*(void)
{
	return (*(node->valptr));
}

template <class Category, class T, class Distance, class Pointer, class Reference>
Pointer
ListIter<Category, T, Distance, Pointer, Reference>::operator->(void)
{
	return (node->valptr);
}

template <class Category, class T, class Distance, class Pointer, class Reference>
ListIter<Category, T, Distance, Pointer, Reference>&
ListIter<Category, T, Distance, Pointer, Reference>::operator++(void)
{
	node = node->next;
	return (*this);
}

template <class Category, class T, class Distance, class Pointer, class Reference>
ListIter<Category, T, Distance, Pointer, Reference>
ListIter<Category, T, Distance, Pointer, Reference>::operator++(int dummy)
{
	ListIter<Category, T>	tmp;

	(void)dummy;
	tmp = *this;
	node = node->next;
	return (tmp);
}

template <class Category, class T, class Distance, class Pointer, class Reference>
ListIter<Category, T, Distance, Pointer, Reference>&
ListIter<Category, T, Distance, Pointer, Reference>::operator--(void)
{
	node = node->prev;
	return (*this);
}

template <class Category, class T, class Distance, class Pointer, class Reference>
ListIter<Category, T, Distance, Pointer, Reference>
ListIter<Category, T, Distance, Pointer, Reference>::operator--(int dummy)
{
	ListIter<Category, T>	tmp;

	(void)dummy;
	tmp = *this;
	node = node->prev;
	return (tmp);
}

#endif //LISTITER_HPP
