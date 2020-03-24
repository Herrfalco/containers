/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SetNode.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcadet <cadet.florian@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 13:07:57 by fcadet            #+#    #+#             */
/*   Updated: 2020/03/24 16:30:31 by fcadet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SETNODE_HPP
# define SETNODE_HPP

# ifndef T_NODE
#  define T_NODE
typedef enum	e_node
{
	no,
	lft,
	rht
}				t_node;
# endif //T_NODE

template <typename T>
struct		SetNode
{
	//Constructors, destructor and assignation :
	SetNode(void);
	SetNode(const T &v, t_node typ, SetNode<T> *u = 0, SetNode<T> *l = 0,
		SetNode<T> *r = 0);
	SetNode(const SetNode<T> &s);
	~SetNode(void);
	SetNode<T>		&operator=(const SetNode<T> &s);

	//Attributes :
	t_node		type;
	SetNode		*up;
	SetNode		*left;
	SetNode		*right;
	T			val;
	T			*valptr;
};

template <typename T>
SetNode<T>::SetNode(void) : type(no), up(this), left(this), right(this), val(), valptr(0)
{
}

template <typename T>
SetNode<T>::SetNode(const T &v, t_node typ, SetNode<T> *u, SetNode<T> *l,
	SetNode<T> *r) : type(typ), up(u), left(l), right(r), val(v), valptr(0)
{
	valptr = &val;
}

template <typename T>
SetNode<T>::SetNode(const SetNode<T> &s) :
	type(no), up(this), left(this), right(this), val(s.val), valptr(0)
{
	valptr = !s.valptr ? 0 : &val;
}

template <typename T>
SetNode<T>::~SetNode(void)
{
}

template <typename T>
SetNode<T>	&SetNode<T>::operator=(const SetNode<T> &s)
{
	if (&s == this)
		return (*this);
	val = s.val;
	valptr = !s.valptr ? 0 : &val;
	return (*this);
}

#endif //SETNODE_HPP
