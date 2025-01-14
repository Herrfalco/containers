/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MapNode.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcadet <cadet.florian@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 13:07:57 by fcadet            #+#    #+#             */
/*   Updated: 2020/03/28 17:44:18 by fcadet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAPNODE_HPP
# define MAPNODE_HPP

namespace	ft
{

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
struct		MapNode
{
	//Constructors, destructor and assignation :
	MapNode(void);
	MapNode(const T &v, t_node typ, MapNode<T> *u = 0, MapNode<T> *l = 0,
		MapNode<T> *r = 0);
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

template <typename T>
MapNode<T>::MapNode(void) : type(no), up(this), left(this), right(this), val(), valptr(0)
{
}

template <typename T>
MapNode<T>::MapNode(const T &v, t_node typ, MapNode<T> *u, MapNode<T> *l,
	MapNode<T> *r) : type(typ), up(u), left(l), right(r), val(v), valptr(0)
{
	valptr = &val;
}

template <typename T>
MapNode<T>::MapNode(const MapNode<T> &m) :
	type(no), up(this), left(this), right(this), val(m.val), valptr(0)
{
	valptr = !m.valptr ? 0 : &val;
}

template <typename T>
MapNode<T>::~MapNode(void)
{
}

template <typename T>
MapNode<T>	&MapNode<T>::operator=(const MapNode<T> &m)
{
	if (&m == this)
		return (*this);
	val = m.val;
	valptr = !m.valptr ? 0 : &val;
	return (*this);
}

}

#endif //MAPNODE_HPP
