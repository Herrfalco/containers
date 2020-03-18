/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MapIter.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcadet <cadet.florian@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 13:08:02 by fcadet            #+#    #+#             */
/*   Updated: 2020/03/18 17:02:16 by fcadet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAPITER_HPP
# define MAPITER_HPP

# include <cstddef>
# include "../Map/MapNode.hpp"

namespace	ft
{

template <class Category, class T, class Distance = std::ptrdiff_t,
	class Pointer = T*, class Reference = T&>
class	MapIter
{
	public:
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
		MapIter			&operator++(void);
		MapIter			operator++(int valptr);
		MapIter			&operator--(void);
		MapIter			operator--(int valptr);

	private:
		//Friendship :
		template <class Key2, class T2, class Compare2>
		friend class			Map;

		//Attibutes :
		MapNode<value_type>		*_node;
};

template <class Category, class T, class Distance, class Pointer, class Reference>
MapIter<Category, T, Distance, Pointer, Reference>::MapIter(MapNode<T> *n) : _node(n)
{
}

template <class Category, class T, class Distance, class Pointer, class Reference>
MapIter<Category, T, Distance, Pointer, Reference>::MapIter(const MapIter<Category,
	T, Distance, Pointer, Reference> &l) : _node(l._node)
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
	_node = l._node;
	return (*this);
}

template <class Category, class T, class Distance, class Pointer, class Reference>
bool
MapIter<Category, T, Distance, Pointer, Reference>::operator==(const MapIter &l) const
{
	return (_node == l._node);
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
	return (*(_node->valptr));
}

template <class Category, class T, class Distance, class Pointer, class Reference>
Pointer
MapIter<Category, T, Distance, Pointer, Reference>::operator->(void)
{
	return (_node->valptr);
}

template <class Category, class T, class Distance, class Pointer, class Reference>
MapIter<Category, T, Distance, Pointer, Reference>&
MapIter<Category, T, Distance, Pointer, Reference>::operator++(void)
{
	if (_node->right && _node->right != _node)
	{
		_node = _node->right;
		while (_node->left && _node->left != _node)
			_node = _node->left;
	}
	else if (_node->type == lft)
		_node = _node->up;
	else if (_node->type == rht && _node->valptr)
	{
		do
			_node = _node->up;
		while (_node->type != lft);
		_node = _node->up;
	}
	return (*this);
}

template <class Category, class T, class Distance, class Pointer, class Reference>
MapIter<Category, T, Distance, Pointer, Reference>
MapIter<Category, T, Distance, Pointer, Reference>::operator++(int dummy)
{
	MapIter<Category, T, Distance, Pointer, Reference>	tmp;

	(void)dummy;
	tmp = *this;
	++(*this);
	return (tmp);
}

template <class Category, class T, class Distance, class Pointer, class Reference>
MapIter<Category, T, Distance, Pointer, Reference>&
MapIter<Category, T, Distance, Pointer, Reference>::operator--(void)
{
	if (_node->left && _node->left != _node)
	{
		_node = _node->left;
		while (_node->right && _node->right != _node)
			_node = _node->right;
	}
	else if (_node->type == rht)
		_node = _node->up;
	else if (_node->type == lft && _node->valptr)
	{
		do
			_node = _node->up;
		while (_node->type != rht);
		_node = _node->up;
	}
	return (*this);
}

template <class Category, class T, class Distance, class Pointer, class Reference>
MapIter<Category, T, Distance, Pointer, Reference>
MapIter<Category, T, Distance, Pointer, Reference>::operator--(int dummy)
{
	MapIter<Category, T, Distance, Pointer, Reference>	tmp;

	(void)dummy;
	tmp = *this;
	--(*this);
	return (tmp);
}

}

#endif //MAPITER_HPP
