/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MapNode.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcadet <cadet.florian@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 13:07:57 by fcadet            #+#    #+#             */
/*   Updated: 2020/03/11 19:04:47 by fcadet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAPNODE_HPP
# define MAPNODE_HPP

template	<typename T>
struct		MapNode
{
		//Constructors, destructor and assignation :
		MapNode(void);
		MapNode(const T &v, bool dummy = false, MapNode<T> *u = 0, MapNode<T> *l = 0,
			MapNode<T> *r = 0);
		MapNode(const MapNode<T> &m);
		~MapNode(void);
		MapNode<T>		&operator=(const MapNode<T> &m);

		//Attributes :
		MapNode		*up;
		MapNode		*left;
		MapNode		*right;
		T			val;
		T			*valptr;
};

template	<typename T>
MapNode<T>::MapNode(void) : up(this), left(this), right(this), val(), valptr(0)
{
}

template	<typename T>
MapNode<T>::MapNode(const T &v, bool dummy, MapNode<T> *u, MapNode<T> *l, MapNode<T> *r) :
	up(u), left(l), right(r), val(v), valptr(0)
{
	up = up ? up : this;
	left = left ? left : this;
	right = right ? right : this;
	valptr = dummy ? 0 : &val;
}

template	<typename T>
MapNode<T>::MapNode(const MapNode<T> &m) :
	up(this), left(this), right(this), val(l.val), valptr(0)
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
