/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MapNode.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcadet <cadet.florian@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 13:07:57 by fcadet            #+#    #+#             */
/*   Updated: 2020/03/12 16:03:41 by fcadet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAPNODE_HPP
# define MAPNODE_HPP

typedef enum	e_node
{
	no;
	lft;
	rht;
}				t_node;

template	<typename T>
struct		MapNode
{
		//Constructors, destructor and assignation :
		MapNode(const T &v = 0, t_node typ = no, bool dummy = false,
			MapNode<T> *u = 0, MapNode<T> *l = 0, MapNode<T> *r = 0);
		MapNode(const MapNode<T> &m);
		~MapNode(void);
		MapNode<T>		&operator=(const MapNode<T> &m);

		//Attributes :
		t_node		type;
		MapNode		*up;
		MapNode		*left;
		MapNode		*right;
		T			val;
		T			*valptr;
};

template	<typename T>
MapNode<T>::MapNode(const T &v, t_node typ, bool dummy, MapNode<T> *u, MapNode<T> *l,
	MapNode<T> *r) : type(typ), up(u), left(l), right(r), val(v), valptr(0)
{
	up = up ? up : this;
	left = left ? left : this;
	right = right ? right : this;
	valptr = dummy ? 0 : &val;
}

template	<typename T>
MapNode<T>::MapNode(const MapNode<T> &m) :
	type(no), up(this), left(this), right(this), val(l.val), valptr(0)
{
	valptr = !l.valptr ? 0 : &val;
}

template	<typename T>
MapNode<T>::~MapNode(void)
{
}

template	<typename T>
MapNode<T>	&MapNode<T>::operator=(const MapNode<T> &l)
{
	if (&l == this)
		return (*this);
	val = l.val;
	valptr = !l.valptr ? 0 : &val;
	return (*this);
}

#endif //MAPNODE_HPP
