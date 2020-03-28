/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SetIter.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcadet <cadet.florian@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 13:08:02 by fcadet            #+#    #+#             */
/*   Updated: 2020/03/28 17:14:28 by fcadet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SETITER_HPP
# define SETITER_HPP

# include <cstddef>
# include "../Set/SetNode.hpp"

namespace	ft
{

template <class Category, class T, class Distance = std::ptrdiff_t,
	class Pointer = T*, class Reference = T&>
class	SetIter
{
	public:
		//Member types :
		typedef T			value_type;
		typedef Distance	difference_type;
		typedef Pointer		pointer;
		typedef Reference	reference;
		typedef Category	iterator_category;

		//Constructors, destructor and assignation :
		SetIter(SetNode<value_type> *n = 0);
		SetIter(const SetIter &s);
		~SetIter(void);
		SetIter		&operator=(const SetIter &s);

		//Relational operators :
		bool			operator==(const SetIter &s) const;
		bool			operator!=(const SetIter &s) const;

		//Access operators :
		reference		operator*(void);
		pointer			operator->(void);
		SetIter			&operator++(void);
		SetIter			operator++(int valptr);
		SetIter			&operator--(void);
		SetIter			operator--(int valptr);

		//Attibutes :
		SetNode<value_type>		*_node;
};

template <class Category, class T, class Distance, class Pointer, class Reference>
SetIter<Category, T, Distance, Pointer, Reference>::SetIter(SetNode<T> *n) : _node(n)
{
}

template <class Category, class T, class Distance, class Pointer, class Reference>
SetIter<Category, T, Distance, Pointer, Reference>::SetIter(const SetIter<Category,
	T, Distance, Pointer, Reference> &s) : _node(s._node)
{
}

template <class Category, class T, class Distance, class Pointer, class Reference>
SetIter<Category, T, Distance, Pointer, Reference>::~SetIter(void)
{
}

template <class Category, class T, class Distance, class Pointer, class Reference>
SetIter<Category, T, Distance, Pointer, Reference>&
SetIter<Category, T, Distance, Pointer, Reference>::operator=(const SetIter &s)
{
	if (&s == this)
		return (*this);
	_node = s._node;
	return (*this);
}

template <class Category, class T, class Distance, class Pointer, class Reference>
bool
SetIter<Category, T, Distance, Pointer, Reference>::operator==(const SetIter &s) const
{
	return (_node == s._node);
}

template <class Category, class T, class Distance, class Pointer, class Reference>
bool
SetIter<Category, T, Distance, Pointer, Reference>::operator!=(const SetIter &s) const
{
	return (!(*this == s));
}

template <class Category, class T, class Distance, class Pointer, class Reference>
Reference
SetIter<Category, T, Distance, Pointer, Reference>::operator*(void)
{
	return (*(_node->valptr));
}

template <class Category, class T, class Distance, class Pointer, class Reference>
Pointer
SetIter<Category, T, Distance, Pointer, Reference>::operator->(void)
{
	return (_node->valptr);
}

template <class Category, class T, class Distance, class Pointer, class Reference>
SetIter<Category, T, Distance, Pointer, Reference>&
SetIter<Category, T, Distance, Pointer, Reference>::operator++(void)
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
SetIter<Category, T, Distance, Pointer, Reference>
SetIter<Category, T, Distance, Pointer, Reference>::operator++(int dummy)
{
	SetIter<Category, T, Distance, Pointer, Reference>	tmp;

	(void)dummy;
	tmp = *this;
	++(*this);
	return (tmp);
}

template <class Category, class T, class Distance, class Pointer, class Reference>
SetIter<Category, T, Distance, Pointer, Reference>&
SetIter<Category, T, Distance, Pointer, Reference>::operator--(void)
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
SetIter<Category, T, Distance, Pointer, Reference>
SetIter<Category, T, Distance, Pointer, Reference>::operator--(int dummy)
{
	SetIter<Category, T, Distance, Pointer, Reference>	tmp;

	(void)dummy;
	tmp = *this;
	--(*this);
	return (tmp);
}

}

#endif //SETITER_HPP
