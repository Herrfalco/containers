/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcadet <cadet.florian@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 12:21:56 by fcadet            #+#    #+#             */
/*   Updated: 2020/03/18 18:35:17 by fcadet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

# include "../Iter/IterTypes.hpp"
# include "../Iter/MapIter.hpp"
# include "../Iter/RevIter.hpp"
# include "../Utils/Pair.hpp"
# include "MapNode.hpp"
# include <limits>
# include <functional>

namespace	ft
{

template <class Key, class T, class Compare = std::less<Key> >
class	Map
{
	public:
		//Member types :
		typedef Key														key_type;
		typedef T														mapped_type;
		typedef ft::Pair<const key_type, mapped_type>					value_type;
		typedef Compare													key_compare;
		class															value_compare;
		typedef value_type&												reference;
		typedef const value_type&										const_reference;
		typedef value_type*												pointer;
		typedef const value_type*										const_pointer;
		typedef MapIter<bidirectional_iterator_tag, value_type>			iterator;
		typedef MapIter<bidirectional_iterator_tag, const value_type>	const_iterator;
		typedef RevIter<iterator>										reverse_iterator;
		typedef RevIter<const_iterator>									const_reverse_iterator;
		typedef ptrdiff_t												difference_type;
		typedef size_t													size_type;

		//Constructors, destructor and assignation :
		explicit Map(const key_compare &comp = key_compare());
		template <class InputIterator>
		Map(InputIterator first, InputIterator last,
			const key_compare &comp = key_compare());
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
		ft::Pair<iterator, bool>	insert(const value_type &val);
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
		ft::Pair<const_iterator, const_iterator>	equal_range(const key_type &k) const;
		ft::Pair<iterator, iterator>				equal_range(const key_type &k);

	private:
		//Attibutes :
		key_compare				_comp;
		MapNode<value_type>		*_root;
		MapNode<value_type>		_front;
		MapNode<value_type>		_back;
		size_type				_size;

		//Utils :
		void					rec_insert(const MapNode<value_type> *n);
		void					left_splice(iterator position);
		void					right_splice(iterator position);
		void					root_splice(iterator position);
};

template <class Key, class T, class Compare>
class	Map<Key, T, Compare>::value_compare :
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

template <class Key, class T, class Compare>
Map<Key, T, Compare>::Map(const key_compare &comp) : _comp(comp), _root(0), _front(),
	_back(), _size(0)
{
	_front.type = lft;
	_back.type = rht;
}

template <class Key, class T, class Compare>
template <class InputIterator>
Map<Key, T, Compare>::Map(InputIterator first, InputIterator last,
	const key_compare &comp) : _comp(comp), _root(0),
	_front(), _back(), _size(0)
{
	_front.type = lft;
	_back.type = rht;
	for (; first != last; ++first)
		insert(*first);
}

template <class Key, class T, class Compare>
void
Map<Key, T, Compare>::rec_insert(const MapNode<value_type> *n)
{
	if (!n || !n->valptr)
		return ;
	insert(*(n->valptr));
	rec_insert(n->left);
	rec_insert(n->right);
}

template <class Key, class T, class Compare>
Map<Key, T, Compare>::Map(const Map &m) : _comp(m._comp), _root(0), _front(), _back(),
	_size(0)
{
	_front.type = lft;
	_back.type = rht;
	rec_insert(m._root);
}

template <class Key, class T, class Compare>
Map<Key, T, Compare>::~Map(void)
{
	clear();
}

template <class Key, class T, class Compare>
Map<Key, T, Compare>
&Map<Key, T, Compare>::operator=(const Map &m)
{
	if (&m == this)
		return (*this);
	clear();
	rec_insert(m._root);
	return (*this);
}

template <class Key, class T, class Compare>
typename Map<Key, T, Compare>::iterator
Map<Key, T, Compare>::begin(void)
{
	return (Map<Key, T, Compare>::iterator(_front.up));
}

template <class Key, class T, class Compare>
typename Map<Key, T, Compare>::const_iterator
Map<Key, T, Compare>::begin(void) const
{
	return (Map<Key, T, Compare>::
		const_iterator(reinterpret_cast<MapNode<const value_type> *>(_front.up)));
}

template <class Key, class T, class Compare>
typename Map<Key, T, Compare>::iterator
Map<Key, T, Compare>::end(void)
{
	return (_size ? Map<Key, T, Compare>::iterator(&_back) : begin());
}

template <class Key, class T, class Compare>
typename Map<Key, T, Compare>::const_iterator
Map<Key, T, Compare>::end(void) const
{
	return (Map<Key, T, Compare>::
		const_iterator(_size ?
			reinterpret_cast<MapNode<const value_type> *>(_back.up->right) : begin()));
}

template <class Key, class T, class Compare>
typename Map<Key, T, Compare>::reverse_iterator
Map<Key, T, Compare>::rbegin(void)
{
	return (Map<Key, T, Compare>::reverse_iterator(end()));
}

template <class Key, class T, class Compare>
typename Map<Key, T, Compare>::const_reverse_iterator
Map<Key, T, Compare>::rbegin(void) const
{
	return (Map<Key, T, Compare>::const_reverse_iterator(end()));
}

template <class Key, class T, class Compare>
typename Map<Key, T, Compare>::reverse_iterator
Map<Key, T, Compare>::rend(void)
{
	return (_size ? Map<Key, T, Compare>::reverse_iterator(begin()) : rbegin());
}

template <class Key, class T, class Compare>
typename Map<Key, T, Compare>::const_reverse_iterator
Map<Key, T, Compare>::rend(void) const
{
	return (_size ? Map<Key, T, Compare>::const_reverse_iterator(begin()) :
		rbegin());
}

template <class Key, class T, class Compare>
bool
Map<Key, T, Compare>::empty(void) const
{
	return (_size ? false : true);
}

template <class Key, class T, class Compare>
typename Map<Key, T, Compare>::size_type
Map<Key, T, Compare>::size(void) const
{
	return (_size);
}

template <class Key, class T, class Compare>
typename Map<Key, T, Compare>::size_type
Map<Key, T, Compare>::max_size(void) const
{
	return (std::numeric_limits<size_type>::max());
}

template <class Key, class T, class Compare>
typename Map<Key, T, Compare>::mapped_type
&Map<Key, T, Compare>::operator[](const key_type &k)
{
	return ((*((insert(ft::make_pair(k, mapped_type()))).first)).second);
}

template <class Key, class T, class Compare>
ft::Pair<typename Map<Key, T, Compare>::iterator, bool>
Map<Key, T, Compare>::insert(const value_type &val)
{
	MapNode<value_type>		*ptr = _root;
	MapNode<value_type>		*tmp;

	if (!_size)
	{
		_root = new MapNode<value_type>(val, no, 0, &_front, &_back);
		_root->up = _root;
		_back.up = _root;
		_front.up = _root;
		++_size;
		return (ft::make_pair(iterator(_root), true));
	}
	while (42)
	{
		if (_comp(val.first, ptr->valptr->first))
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
				return (ft::make_pair(iterator(ptr->left), true));
			}
			ptr = tmp;
		}
		else if (_comp(ptr->valptr->first, val.first))
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
				return (ft::make_pair(iterator(ptr->right), true));
			}
			ptr = tmp;
		}
		else
			return (ft::make_pair(iterator(ptr), false));
	}
}

template <class Key, class T, class Compare>
typename Map<Key, T, Compare>::iterator
Map<Key, T, Compare>::insert(iterator it, const value_type &val)
{
	(void)it;
	insert(val);
}

template <class Key, class T, class Compare>
template <class InputIterator>
void
Map<Key, T, Compare>::insert(InputIterator fst, InputIterator lst)
{
	for (; fst != lst; ++fst)
		insert(*fst);
}

template <class Key, class T, class Compare>
void
Map<Key, T, Compare>::left_splice(iterator position)
{
	MapNode<value_type>		*ptr = position._node;
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
	if (a)
		a->type = lft;
	delete (ptr);
}

template <class Key, class T, class Compare>
void
Map<Key, T, Compare>::right_splice(iterator position)
{
	MapNode<value_type>		*ptr = position._node;
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
	if (a)
		a->type = rht;
	delete (ptr);
}

template <class Key, class T, class Compare>
void
Map<Key, T, Compare>::root_splice(iterator position)
{
	MapNode<value_type>		*ptr = position._node;
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
	a->up = a;
	a->type = no;
	delete (ptr);
}

template <class Key, class T, class Compare>
void
Map<Key, T, Compare>::erase(iterator position)
{
	MapNode<value_type>		*ptr = position._node;

	if (ptr->type == lft)
		left_splice(position);
	else if (ptr->type == rht)
		right_splice(position);
	else
		root_splice(position);
	--_size;
}

template <class Key, class T, class Compare>
typename Map<Key, T, Compare>::size_type
Map<Key, T, Compare>::erase(const key_type &k)
{
	ft::Pair<iterator, bool>	ins_ret(insert(ft::make_pair(k, mapped_type())));

	erase(ins_ret.first);
	return (ins_ret.second ? 0 : 1);
}

template <class Key, class T, class Compare>
void
Map<Key, T, Compare>::erase(iterator first, iterator last)
{
	iterator		tmp(first++);

	for (; tmp != last; tmp = first++)
		erase(tmp);
}

template <class Key, class T, class Compare>
void
Map<Key, T, Compare>::swap(Map &x)
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
		x._front.up->left = &_front;
		x._back.up->right = &_back;
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

template <class Key, class T, class Compare>
void
Map<Key, T, Compare>::clear(void)
{
	while (_size)
	{
		erase(begin());
	}
}

template <class Key, class T, class Compare>
typename Map<Key, T, Compare>::key_compare
Map<Key, T, Compare>::key_comp(void) const
{
	return (key_compare());
}

template <class Key, class T, class Compare>
typename Map<Key, T, Compare>::value_compare
Map<Key, T, Compare>::value_comp(void) const
{
	return (value_compare(Compare()));
}

template <class Key, class T, class Compare>
typename Map<Key, T, Compare>::iterator
Map<Key, T, Compare>::find(const key_type &k)
{
	iterator	it(begin());

	for (; it != end() && (key_comp()(k, it->first) || key_comp()(it->first, k)); ++it);
	return (it);
}

template <class Key, class T, class Compare>
typename Map<Key, T, Compare>::const_iterator
Map<Key, T, Compare>::find(const key_type &k) const
{
	const_iterator		it(begin());

	for (; it != end() && (key_comp()(k, it->first) || key_comp()(it->first, k)); ++it);
	return (it);
}

template <class Key, class T, class Compare>
typename Map<Key, T, Compare>::size_type
Map<Key, T, Compare>::count(const key_type &k) const
{
	const_iterator		it(begin());

	for (; it != end() && (key_comp()(k, it->first) || key_comp()(it->first, k)); ++it);
	return (it == end() ? 0 : 1);
}

template <class Key, class T, class Compare>
typename Map<Key, T, Compare>::iterator
Map<Key, T, Compare>::lower_bound(const key_type &k)
{
	iterator	it(begin());

	for (; it != end() && key_comp()(it->first, k); ++it);
	return (it);
}

template <class Key, class T, class Compare>
typename Map<Key, T, Compare>::const_iterator
Map<Key, T, Compare>::lower_bound(const key_type &k) const
{
	const_iterator	it(begin());

	for (; it != end() && key_comp()(it->first, k); ++it);
	return (it);
}

template <class Key, class T, class Compare>
typename Map<Key, T, Compare>::iterator
Map<Key, T, Compare>::upper_bound(const key_type &k)
{
	iterator	it(begin());

	for (; it != end() && !key_comp()(k, it->first); ++it);
	return (it);
}

template <class Key, class T, class Compare>
typename Map<Key, T, Compare>::const_iterator
Map<Key, T, Compare>::upper_bound(const key_type &k) const
{
	const_iterator	it(begin());

	for (; it != end() && !key_comp()(k, it->first); ++it);
	return (it);
}

template <class Key, class T, class Compare>
ft::Pair<typename Map<Key, T, Compare>::const_iterator,
	typename Map<Key, T, Compare>::const_iterator>
Map<Key, T, Compare>::equal_range(const key_type &k) const
{
	return (ft::make_pair(lower_bound(k), upper_bound(k)));
}

template <class Key, class T, class Compare>
ft::Pair<typename Map<Key, T, Compare>::iterator,
	typename Map<Key, T, Compare>::iterator>
Map<Key, T, Compare>::equal_range(const key_type &k)
{
	return (ft::make_pair(lower_bound(k), upper_bound(k)));
}

}

#endif //MAP_HPP
