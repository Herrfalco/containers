/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcadet <cadet.florian@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 12:21:56 by fcadet            #+#    #+#             */
/*   Updated: 2020/03/14 19:20:25 by fcadet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

#include "../Iter/IterTypes.hpp"
#include "../Iter/MapIter.hpp"
#include "../Iter/RevIter.hpp"
#include "MapNode.hpp"
#include <functional>
#include <memory>

#include <iostream>

namespace	ft {

template <class Key, class T, class Compare = std::less<Key>,
	class Alloc = std::allocator<std::pair<const Key, T> > >
class	Map
{
	public:
		//Member types :
		typedef Key														key_type;
		typedef T														mapped_type;
		typedef std::pair<const key_type, mapped_type>					value_type;
		typedef Compare													key_compare;
		class															value_compare;
		typedef Alloc													allocator_type;
		typedef typename allocator_type::reference						reference;
		typedef typename allocator_type::const_reference				const_reference;
		typedef typename allocator_type::pointer						pointer;
		typedef typename allocator_type::const_pointer					const_pointer;
		typedef MapIter<bidirectional_iterator_tag, value_type>			iterator;
		typedef MapIter<bidirectional_iterator_tag, const value_type>	const_iterator;
		typedef RevIter<iterator>										reverse_iterator;
		typedef RevIter<const_iterator>									const_reverse_iterator;
		typedef ptrdiff_t												difference_type;
		typedef size_t													size_type;

		//Constructors, destructor and assignation :
		explicit Map(const key_compare &comp = key_compare(),
			const allocator_type &alloc = allocator_type());
		template <class InputIterator>
		Map(InputIterator first, InputIterator last,
			const key_compare &comp = key_compare(),
			const allocator_type &alloc = allocator_type());
		Map(const Map &m);
		~Map(void);
		Map					&operator=(const Map &l);

		//Iterators :
		iterator					begin(void);
		const_iterator				begin(void) const;
		iterator					end(void);
		const_iterator				end(void) const;
		reverse_iterator			rbegin(void);
		const_reverse_iterator		rbegin(void) const;
		reverse_iterator			rend(void);
		const_reverse_iterator		rend(void) const;

		//Capacity :
		bool						empty(void) const;
		size_type					size(void) const;
		size_type					max_size() const;

		//Element access :
		mapped_type					&operator[](const key_type &k);

		//Modifiers :
		std::pair<iterator, bool>	insert(const value_type &val);
		iterator					insert(iterator it, const value_type &val);
		template <class InputIterator>
		void						insert(InputIterator fst, InputIterator lst);
		void						erase(iterator position);
		size_type					erase(const key_type &k);
		void						erase(iterator first, iterator last);
		void						swap(Map &x);
		void						clear(void);

		//Observers :
		key_compare					key_comp(void) const;
		value_compare				value_comp(void) const;
	
		//Operations :
		iterator									find(const key_type &k);
		const_iterator								find(const key_type &k) const;
		size_type									count(const key_type &k) const;
		iterator									lower_bound(const key_type &k);
		const_iterator								lower_bound(const key_type &k) const;
		iterator									upper_bound(const key_type &k);
		const_iterator								upper_bound(const key_type &k) const;
		std::pair<const_iterator, const_iterator>	equal_range(const key_type &k) const;
		std::pair<iterator, iterator>				equal_range(const key_type &k);

	private:
		//Attibutes :
		allocator_type			_alloc;
		key_compare				_comp;
		MapNode<value_type>		*_root;
		MapNode<value_type>		_front;
		MapNode<value_type>		_back;
		size_type				_size;

		//Utils :
		void					rec_insert(const value_type *n);
		void					left_splice(iterator position);
		void					right_splice(iterator position);
		void					root_splice(iterator position);
};

template <class Key, class T, class Compare, class Alloc>
class	Map<Key, T, Compare, Alloc>::value_compare :
	public std::binary_function<value_type, value_type, bool>
{
	friend class	Map;

	public:
		typedef bool		result_type;
		typedef value_type	first_argument_type;
		typedef value_type	second_argument_type;
		bool	operator()(const value_type &x, const value_type &y) const
		{
			return comp(x.first, y.first);
		}
	protected:
		Compare comp;
		value_compare(Compare c) : comp(c) {}
};

template <class Key, class T, class Compare, class Alloc>
Map<Key, T, Compare, Alloc>::Map(const key_compare &comp, const allocator_type &alloc) :
	_alloc(alloc), _comp(comp), _root(0), _front(), _back(), _size(0)
{
}

template <class Key, class T, class Compare, class Alloc>
template <class InputIterator>
Map<Key, T, Compare, Alloc>::Map(InputIterator first, InputIterator last,
	const key_compare &comp, const allocator_type &alloc) :
	_alloc(alloc), _comp(comp), _root(0), _front(), _back(), _size(0)
{
	for (; first != last; ++first)
		insert(*first);
}

template <class Key, class T, class Compare, class Alloc>
void
Map<Key, T, Compare, Alloc>::rec_insert(const value_type *n)
{
	if (!n || !n->valptr)
		return ;
	insert(*(n->valptr));
	rec_insert(n->left);
	rec_insert(n->right);
}

template <class Key, class T, class Compare, class Alloc>
Map<Key, T, Compare, Alloc>::Map(const Map &m) : _alloc(m._alloc), _comp(m.comp),
	_root(0), _front(), _back(), _size(0)
{
	rec_insert(m._root);
}

template <class Key, class T, class Compare, class Alloc>
Map<Key, T, Compare, Alloc>::~Map(void)
{
	clear();
}

template <class Key, class T, class Compare, class Alloc>
Map<Key, T, Compare, Alloc>
&Map<Key, T, Compare, Alloc>::operator=(const Map &m)
{
	if (&m == this)
		return (*this);
	clear();
	rec_insert(m._root);
	return (*this);
}

template <class Key, class T, class Compare, class Alloc>
typename Map<Key, T, Compare, Alloc>::iterator
Map<Key, T, Compare, Alloc>::begin(void)
{
	return (Map<Key, T, Compare, Alloc>::iterator(_front.up));
}

template <class Key, class T, class Compare, class Alloc>
typename Map<Key, T, Compare, Alloc>::const_iterator
Map<Key, T, Compare, Alloc>::begin(void) const
{
	return (Map<Key, T, Compare, Alloc>::
		const_iterator(reinterpret_cast<MapNode<const value_type> *>(_front.up)));
}

template <class Key, class T, class Compare, class Alloc>
typename Map<Key, T, Compare, Alloc>::iterator
Map<Key, T, Compare, Alloc>::end(void)
{
	return (Map<Key, T, Compare, Alloc>::iterator(&_back));
}

template <class Key, class T, class Compare, class Alloc>
typename Map<Key, T, Compare, Alloc>::const_iterator
Map<Key, T, Compare, Alloc>::end(void) const
{
	return (Map<Key, T, Compare, Alloc>::
		const_iterator(reinterpret_cast<MapNode<const value_type> *>(_back.up->right)));
}

template <class Key, class T, class Compare, class Alloc>
typename Map<Key, T, Compare, Alloc>::reverse_iterator
Map<Key, T, Compare, Alloc>::rbegin(void)
{
	return (Map<Key, T, Compare, Alloc>::reverse_iterator(end()));
}

template <class Key, class T, class Compare, class Alloc>
typename Map<Key, T, Compare, Alloc>::const_reverse_iterator
Map<Key, T, Compare, Alloc>::rbegin(void) const
{
	return (Map<Key, T, Compare, Alloc>::const_reverse_iterator(end()));
}

template <class Key, class T, class Compare, class Alloc>
typename Map<Key, T, Compare, Alloc>::reverse_iterator
Map<Key, T, Compare, Alloc>::rend(void)
{
	return (Map<Key, T, Compare, Alloc>::reverse_iterator(begin()));
}

template <class Key, class T, class Compare, class Alloc>
typename Map<Key, T, Compare, Alloc>::const_reverse_iterator
Map<Key, T, Compare, Alloc>::rend(void) const
{
	return (Map<Key, T, Compare, Alloc>::const_reverse_iterator(begin()));
}

template <class Key, class T, class Compare, class Alloc>
bool
Map<Key, T, Compare, Alloc>::empty(void) const
{
	return (_size ? false : true);
}

template <class Key, class T, class Compare, class Alloc>
typename Map<Key, T, Compare, Alloc>::size_type
Map<Key, T, Compare, Alloc>::size(void) const
{
	return (_size);
}

template <class Key, class T, class Compare, class Alloc>
typename Map<Key, T, Compare, Alloc>::size_type
Map<Key, T, Compare, Alloc>::max_size(void) const
{
	return (std::allocator<MapNode<value_type> >().max_size() + _size);
}

template <class Key, class T, class Compare, class Alloc>
typename Map<Key, T, Compare, Alloc>::mapped_type
&Map<Key, T, Compare, Alloc>::operator[](const key_type &k)
{
	return ((*((insert(make_pair(k, mapped_type()))).first)).second);
}

template <class Key, class T, class Compare, class Alloc>
std::pair<typename Map<Key, T, Compare, Alloc>::iterator, bool>
Map<Key, T, Compare, Alloc>::insert(const value_type &val)
{
	MapNode<value_type>		*ptr = _root;
	MapNode<value_type>		*tmp;

	if (!_size)
	{
		_root = new MapNode<value_type>(val, no, this, &_front, &_back);
		_back.up = _root;
		_front.up = _root;
		++_size;
		return (make_pair(iterator(_root), true));
	}
	while (42)
	{
		if (Compare(val.first, *(ptr->valptr).first))
		{
			tmp = ptr->left;
			if (!tmp || !tmp->valptr)
			{
				ptr->left = new MapNode<value_type>(val, lft, ptr);
				if (tmp)
				{
					ptr->left->left = tmp;
					tmp->up = ptr->left;
				}
				++_size;
				return (make_pair(iterator(ptr->left), true));
			}
			ptr = tmp;
		}
		else if (Compare(*(ptr->valptr).first), val.first)
		{
			tmp = ptr->right;
			if (!tmp || !tmp->valptr)
			{
				ptr->right = new MapNode<value_type>(val, rht, ptr);
				if (tmp)
				{
					ptr->right->right = tmp;
					tmp->up = ptr->right;
				}
				++_size;
				return (make_pair(iterator(ptr->right), true));
			}
			ptr = tmp;
		}
		else
			return (make_pair(iterator(ptr), false));
	}
}

template <class Key, class T, class Compare, class Alloc>
typename Map<Key, T, Compare, Alloc>::iterator
Map<Key, T, Compare, Alloc>::insert(iterator it, const value_type &val)
{
	(void)it;
	insert(val);
}

template <class Key, class T, class Compare, class Alloc>
template <class InputIterator>
void
Map<Key, T, Compare, Alloc>::insert(InputIterator fst, InputIterator lst)
{
	for (; fst != lst; ++fst)
		insert(*fst);
}

template <class Key, class T, class Compare, class Alloc>
void
Map<Key, T, Compare, Alloc>::left_splice(iterator position)
{
	MapNode<value_type>		*ptr = position.node;
	MapNode<value_type>		*a;
	MapNode<value_type>		*b;

	if (ptr->right)
	{
		for (a = ptr->right, b = a; b->left; b = b->left);
		a->up = ptr->up;
		b->left = ptr->left;
	}
	else
	{
		a = ptr->left;
		b = ptr->up;
	}
	ptr->up->left = a;
	if (ptr->left)
		ptr->left->up = b;
	delete (ptr);
}

template <class Key, class T, class Compare, class Alloc>
void
Map<Key, T, Compare, Alloc>::right_splice(iterator position)
{
	MapNode<value_type>		*ptr = position.node;
	MapNode<value_type>		*a;
	MapNode<value_type>		*b;

	if (ptr->left)
	{
		for (a = ptr->left, b = a; b->right; b = b->right);
		a->up = ptr->up;
		b->right = ptr->right;
	}
	else
	{
		a = ptr->right;
		b = ptr->up;
	}
	ptr->up->right = a;
	if (ptr->right)
		ptr->right->up = b;
	delete (ptr);
}

template <class Key, class T, class Compare, class Alloc>
void
Map<Key, T, Compare, Alloc>::root_splice(iterator position)
{
	MapNode<value_type>		*ptr = position.node;
	MapNode<value_type>		*a;
	MapNode<value_type>		*b;

	if (ptr->left && ptr->left->valptr)
	{
		for (a = ptr->left, b = a; b->right; b = b->right);
		b->right = ptr->right;
		ptr->right->up = b;
	}
	else if (ptr->right && ptr->right->valptr)
	{
		for (a = ptr->right, b = a; b->left; b = b->left);
		b->left = ptr->left;
		ptr->left->up = b;
	}
	else
	{
		_root = 0;
		_front.up = &_front;
		_back.up = &_back;
		delete (ptr);
		return ;
	}
	_root = a;
	a->up = &a;
	a->typ = no;
	delete (ptr);
}

template <class Key, class T, class Compare, class Alloc>
void
Map<Key, T, Compare, Alloc>::erase(iterator position)
{
	MapNode<value_type>		*ptr = position.node;

	if (ptr->typ == lft)
		left_splice(position);
	else if (ptr->typ == rht)
		right_splice(position);
	else
		root_splice(position);
	--_size;
}

template <class Key, class T, class Compare, class Alloc>
typename Map<Key, T, Compare, Alloc>::size_type
Map<Key, T, Compare, Alloc>::erase(const key_type &k)
{
	std::pair<iterator, bool>	ins_ret(insert(make_pair(k, mapped_type())));

	erase(ins_ret.first);
	return (ins_ret.second ? 0 : 1);
}

template <class Key, class T, class Compare, class Alloc>
void
Map<Key, T, Compare, Alloc>::erase(iterator first, iterator last)
{
	for (; first != last; ++first)
		erase(first);
}

template <class Key, class T, class Compare, class Alloc>
void
Map<Key, T, Compare, Alloc>::swap(Map &x)
{
	MapNode<value_type>		*tmp = _root;
	size_type				size_tmp = _size;;
	
	_root = x._root;
	x._root = tmp;
	if (_size)
	{
		_front.up->left = &(x._front);
		_back.up->right = &(x._back);
	}
	if (x._size)
	{
		x._front->up->left = &_front;
		x._back->up->right = &_back;
	}
	tmp = _front.up;
	_front.up = x._size ? x._front.up : &_front;
	x._front.up = _size ? tmp : &(x._front);
	tmp = _back.up;
	_back.up = x._size ? x._back.up : &_back;
	x._back.up = _size ? tmp : &(x._back);
	_size = x._size;
	x._size = size_tmp;
}

template <class Key, class T, class Compare, class Alloc>
void
Map<Key, T, Compare, Alloc>::clear(void)
{
	while (_size)
		erase(begin());
}

template <class Key, class T, class Compare, class Alloc>
typename Map<Key, T, Compare, Alloc>::key_compare
Map<Key, T, Compare, Alloc>::key_comp(void) const
{
	return (key_compare());
}

template <class Key, class T, class Compare, class Alloc>
typename Map<Key, T, Compare, Alloc>::value_compare
Map<Key, T, Compare, Alloc>::value_comp(void) const
{
	return (value_compare());
}

template <class Key, class T, class Compare, class Alloc>
typename Map<Key, T, Compare, Alloc>::iterator
Map<Key, T, Compare, Alloc>::find(const key_type &k)
{
	iterator	it(begin());

	for (; it != end() && (key_compare(k, it->first) || key_compare(it->first, k)); ++it);
	return (it);
}

template <class Key, class T, class Compare, class Alloc>
typename Map<Key, T, Compare, Alloc>::const_iterator
Map<Key, T, Compare, Alloc>::find(const key_type &k) const
{
	const_iterator		it(begin());

	for (; it != end() && (key_compare(k, it->first) || key_compare(it->first, k)); ++it);
	return (it);
}

template <class Key, class T, class Compare, class Alloc>
typename Map<Key, T, Compare, Alloc>::size_type
Map<Key, T, Compare, Alloc>::count(const key_type &k) const
{
	iterator	it(begin());

	for (; it != end() && (key_compare(k, it->first) || key_compare(it->first, k)); ++it);
	return (it == end() ? 0 : 1);
}

template <class Key, class T, class Compare, class Alloc>
typename Map<Key, T, Compare, Alloc>::iterator
Map<Key, T, Compare, Alloc>::lower_bound(const key_type &k)
{
	iterator	it(begin());

	for (; it != end() && key_compare(it->first, k); ++it);
	return (it);
}

template <class Key, class T, class Compare, class Alloc>
typename Map<Key, T, Compare, Alloc>::const_iterator
Map<Key, T, Compare, Alloc>::lower_bound(const key_type &k) const
{
	const_iterator	it(begin());

	for (; it != end() && key_compare(it->first, k); ++it);
	return (it);
}

template <class Key, class T, class Compare, class Alloc>
typename Map<Key, T, Compare, Alloc>::iterator
Map<Key, T, Compare, Alloc>::upper_bound(const key_type &k)
{
	iterator	it(begin());

	for (; it != end() && !key_compare(k, it->first); ++it);
	return (it);
}

template <class Key, class T, class Compare, class Alloc>
typename Map<Key, T, Compare, Alloc>::const_iterator
Map<Key, T, Compare, Alloc>::upper_bound(const key_type &k) const
{
	const_iterator	it(begin());

	for (; it != end() && !key_compare(k, it->first); ++it);
	return (it);
}

template <class Key, class T, class Compare, class Alloc>
std::pair<typename Map<Key, T, Compare, Alloc>::const_iterator,
	typename Map<Key, T, Compare, Alloc>::const_iterator>
Map<Key, T, Compare, Alloc>::equal_range(const key_type &k) const
{
	return (make_pair(lower_bound(k), upper_boud(k)));
}

template <class Key, class T, class Compare, class Alloc>
std::pair<typename Map<Key, T, Compare, Alloc>::iterator,
	typename Map<Key, T, Compare, Alloc>::iterator>
Map<Key, T, Compare, Alloc>::equal_range(const key_type &k)
{
	return (make_pair(lower_bound(k), upper_boud(k)));
}

}

#endif //MAP_HPP
