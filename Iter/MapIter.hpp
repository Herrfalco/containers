/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MapIter.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcadet <cadet.florian@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 13:08:02 by fcadet            #+#    #+#             */
/*   Updated: 2020/03/11 18:38:05 by fcadet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAPITER_HPP
# define MAPITER_HPP

# include <cstddef>
# include "../Map/MapNode.hpp"

template <class Category, class T, class Distance = std::ptrdiff_t,
	class Pointer = T*, class Reference = T&>
struct	MapIter
{
		//Member types :
		typedef T			value_type;
		typedef Distance	difference_type;
		typedef Pointer		pointer;
		typedef Reference	reference;
		typedef Category	iterator_category;

		//Constructors, destructor and assignation :
		MapIter(MapNode<value_type> *n = 0);
		MapIter(const MapIter &l);
		~MapIter(void);
		MapIter		&operator=(const MapIter &l);

		//Relational operators :
		bool			operator==(const MapIter &l) const;
		bool			operator!=(const MapIter &l) const;

		//Access operators :
		reference		operator*(void);
		pointer			operator->(void);
		MapIter		&operator++(void);
		MapIter		operator++(int valptr);
		MapIter		&operator--(void);
		MapIter		operator--(int valptr);

		//Attibutes :
		MapNode<value_type>		*node;
};

template <class Category, class T, class Distance, class Pointer, class Reference>
MapIter<Category, T, Distance, Pointer, Reference>::MapIter(MapNode<T> *n) : node(n)
{
}

template <class Category, class T, class Distance, class Pointer, class Reference>
MapIter<Category, T, Distance, Pointer, Reference>::MapIter(const MapIter<Category,
	T, Distance, Pointer, Reference> &l) : node(l.node)
{
}

template <class Category, class T, class Distance, class Pointer, class Reference>
MapIter<Category, T, Distance, Pointer, Reference>::~MapIter(void)
{
}

template <class Category, class T, class Distance, class Pointer, class Reference>
MapIter<Category, T, Distance, Pointer, Reference>&
MapIter<Category, T, Distance, Pointer, Reference>::operator=(const MapIter &l)
{
	if (&l == this)
		return (*this);
	node = l.node;
	return (*this);
}

template <class Category, class T, class Distance, class Pointer, class Reference>
bool
MapIter<Category, T, Distance, Pointer, Reference>::operator==(const MapIter &l) const
{
	return (node == l.node);
}

template <class Category, class T, class Distance, class Pointer, class Reference>
bool
MapIter<Category, T, Distance, Pointer, Reference>::operator!=(const MapIter &l) const
{
	return (!(*this == l));
}

template <class Category, class T, class Distance, class Pointer, class Reference>
Reference
MapIter<Category, T, Distance, Pointer, Reference>::operator*(void)
{
	return (*(node->valptr));
}

template <class Category, class T, class Distance, class Pointer, class Reference>
Pointer
MapIter<Category, T, Distance, Pointer, Reference>::operator->(void)
{
	return (node->valptr);
}

template <class Category, class T, class Distance, class Pointer, class Reference>
MapIter<Category, T, Distance, Pointer, Reference>&
MapIter<Category, T, Distance, Pointer, Reference>::operator++(void)
{
	node = node->next;
	return (*this);
}

template <class Category, class T, class Distance, class Pointer, class Reference>
MapIter<Category, T, Distance, Pointer, Reference>
MapIter<Category, T, Distance, Pointer, Reference>::operator++(int dummy)
{
	MapIter<Category, T>	tmp;

	(void)dummy;
	tmp = *this;
	node = node->next;
	return (tmp);
}

template <class Category, class T, class Distance, class Pointer, class Reference>
MapIter<Category, T, Distance, Pointer, Reference>&
MapIter<Category, T, Distance, Pointer, Reference>::operator--(void)
{
	node = node->prev;
	return (*this);
}

template <class Category, class T, class Distance, class Pointer, class Reference>
MapIter<Category, T, Distance, Pointer, Reference>
MapIter<Category, T, Distance, Pointer, Reference>::operator--(int dummy)
{
	MapIter<Category, T>	tmp;

	(void)dummy;
	tmp = *this;
	node = node->prev;
	return (tmp);
}

#endif //MAPITER_HPP
