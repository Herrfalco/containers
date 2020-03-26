/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Multiset.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcadet <cadet.florian@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 12:21:56 by fcadet            #+#    #+#             */
/*   Updated: 2020/03/26 14:16:25 by fcadet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MULTISET_HPP
# define MULTISET_HPP

# include "../Iter/IterTypes.hpp"
# include "../Iter/SetIter.hpp"
# include "../Iter/RevIter.hpp"
# include "../Utils/Pair.hpp"
# include "../Utils/Less.hpp"
# include "../Set/SetNode.hpp"
# include <limits>

namespace	ft
{

template <class T, class Compare = ft::Less<T> >
class	Multiset
{
	public:
		//Member types :
		typedef T														key_type;
		typedef T														value_type;
		typedef Compare													key_compare;
		typedef Compare													value_compare;
		typedef value_type&												reference;
		typedef const value_type&										const_reference;
		typedef value_type*												pointer;
		typedef const value_type*										const_pointer;
		typedef SetIter<bidirectional_iterator_tag, value_type>			iterator;
		typedef SetIter<bidirectional_iterator_tag, const value_type>	const_iterator;
		typedef RevIter<iterator>										reverse_iterator;
		typedef RevIter<const_iterator>
			const_reverse_iterator;
		typedef ptrdiff_t												difference_type;
		typedef size_t													size_type;

		//Constructors, destructor and assignation :
		explicit Multiset(const key_compare &comp = key_compare());
		template <class InputIterator>
		Multiset(InputIterator first, InputIterator last,
			const key_compare &comp = key_compare());
		Multiset(const Multiset &m);
		~Multiset(void);
		Multiset					&operator=(const Multiset &m);

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

		//Modifiers :
		iterator					insert(const value_type &val);
		iterator					insert(iterator it, const value_type &val);
		template <class InputIterator>
		void						insert(InputIterator fst, InputIterator lst);
		void						erase(iterator position);
		size_type					erase(const value_type &v);
		void						erase(iterator first, iterator last);
		void						swap(Multiset &x);
		void						clear(void);

		//Observers :
		key_compare					key_comp(void) const;
		value_compare				value_comp(void) const;
	
		//Operations :
		iterator								find(const value_type &v) const;
		size_type								count(const value_type &v) const;
		iterator								lower_bound(const value_type &v) const;
		iterator								upper_bound(const value_type &v) const;
		ft::Pair<iterator, iterator>			equal_range(const value_type &v) const;

	private:
		//Attibutes :
		key_compare					_comp;
		SetNode<value_type>	*_root;
		SetNode<value_type>	_front;
		SetNode<value_type>	_back;
		size_type					_size;

		//Utils :
		void					rec_insert(const SetNode<value_type> *n);
		void					left_splice(iterator position);
		void					right_splice(iterator position);
		void					root_splice(iterator position);
};

template <class T, class Compare>
Multiset<T, Compare>::Multiset(const key_compare &comp) : _comp(comp), _root(0), _front(),
	_back(), _size(0)
{
	_front.type = lft;
	_back.type = rht;
}

template <class T, class Compare>
template <class InputIterator>
Multiset<T, Compare>::Multiset(InputIterator first, InputIterator last,
	const key_compare &comp) : _comp(comp), _root(0), _front(), _back(), _size(0)
{
	_front.type = lft;
	_back.type = rht;
	for (; first != last; ++first)
		insert(*first);
}

template <class T, class Compare>
void
Multiset<T, Compare>::rec_insert(const SetNode<value_type> *n)
{
	if (!n || !n->valptr)
		return ;
	insert(*(n->valptr));
	rec_insert(n->left);
	rec_insert(n->right);
}

template <class T, class Compare>
Multiset<T, Compare>::Multiset(const Multiset &m) : _comp(m._comp), _root(0), _front(),
	_back(), _size(0)
{
	_front.type = lft;
	_back.type = rht;
	rec_insert(m._root);
}

template <class T, class Compare>
Multiset<T, Compare>::~Multiset(void)
{
	clear();
}

template <class T, class Compare>
Multiset<T, Compare>
&Multiset<T, Compare>::operator=(const Multiset &m)
{
	if (&m == this)
		return (*this);
	clear();
	rec_insert(m._root);
	return (*this);
}

template <class T, class Compare>
typename Multiset<T, Compare>::iterator
Multiset<T, Compare>::begin(void)
{
	return (Multiset<T, Compare>::iterator(_front.up));
}

template <class T, class Compare>
typename Multiset<T, Compare>::const_iterator
Multiset<T, Compare>::begin(void) const
{
	return (Multiset<T, Compare>::
		const_iterator(reinterpret_cast<SetNode<const value_type> *>(_front.up)));
}

template <class T, class Compare>
typename Multiset<T, Compare>::iterator
Multiset<T, Compare>::end(void)
{
	return (_size ? Multiset<T, Compare>::iterator(&_back) : begin());
}

template <class T, class Compare>
typename Multiset<T, Compare>::const_iterator
Multiset<T, Compare>::end(void) const
{
	return (Multiset<T, Compare>::
		const_iterator(_size ?
		reinterpret_cast<SetNode<const value_type> *>(_back.up->right) : begin()));
}

template <class T, class Compare>
typename Multiset<T, Compare>::reverse_iterator
Multiset<T, Compare>::rbegin(void)
{
	return (Multiset<T, Compare>::reverse_iterator(end()));
}

template <class T, class Compare>
typename Multiset<T, Compare>::const_reverse_iterator
Multiset<T, Compare>::rbegin(void) const
{
	return (Multiset<T, Compare>::const_reverse_iterator(end()));
}

template <class T, class Compare>
typename Multiset<T, Compare>::reverse_iterator
Multiset<T, Compare>::rend(void)
{
	return (_size ? Multiset<T, Compare>::reverse_iterator(begin()) : rbegin());
}

template <class T, class Compare>
typename Multiset<T, Compare>::const_reverse_iterator
Multiset<T, Compare>::rend(void) const
{
	return (_size ? Multiset<T, Compare>::const_reverse_iterator(begin()) :
		rbegin());
}

template <class T, class Compare>
bool
Multiset<T, Compare>::empty(void) const
{
	return (_size ? false : true);
}

template <class T, class Compare>
typename Multiset<T, Compare>::size_type
Multiset<T, Compare>::size(void) const
{
	return (_size);
}

template <class T, class Compare>
typename Multiset<T, Compare>::size_type
Multiset<T, Compare>::max_size(void) const
{
	return (std::numeric_limits<size_type>::max());
}


template <class T, class Compare>
typename Multiset<T, Compare>::iterator
Multiset<T, Compare>::insert(const value_type &val)
{
	SetNode<value_type>		*ptr = _root;
	SetNode<value_type>		*tmp;

	if (!_size)
	{
		_root = new SetNode<value_type>(val, no, 0, &_front, &_back);
		_root->up = _root;
		_back.up = _root;
		_front.up = _root;
		++_size;
		return (_root);
	}
	while (42)
	{
		if (_comp(val, *(ptr->valptr)))
		{
			tmp = ptr->left;
			if (!tmp || !tmp->valptr)
			{
				ptr->left = new SetNode<value_type>(val, lft, ptr);
				if (tmp)
				{
					ptr->left->left = tmp;
					tmp->up = ptr->left;
				}
				++_size;
				return (ptr->left);
			}
			ptr = tmp;
		}
		else
		{
			tmp = ptr->right;
			if (!tmp || !tmp->valptr)
			{
				ptr->right = new SetNode<value_type>(val, rht, ptr);
				if (tmp)
				{
					ptr->right->right = tmp;
					tmp->up = ptr->right;
				}
				++_size;
				return (ptr->right);
			}
			ptr = tmp;
		}
	}
}

template <class T, class Compare>
typename Multiset<T, Compare>::iterator
Multiset<T, Compare>::insert(iterator it, const value_type &val)
{
	(void)it;
	return (insert(val));
}

template <class T, class Compare>
template <class InputIterator>
void
Multiset<T, Compare>::insert(InputIterator fst, InputIterator lst)
{
	for (; fst != lst; ++fst)
		insert(*fst);
}

template <class T, class Compare>
void
Multiset<T, Compare>::left_splice(iterator position)
{
	SetNode<value_type>		*ptr = position._node;
	SetNode<value_type>		*a;
	SetNode<value_type>		*b;

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

template <class T, class Compare>
void
Multiset<T, Compare>::right_splice(iterator position)
{
	SetNode<value_type>		*ptr = position._node;
	SetNode<value_type>		*a;
	SetNode<value_type>		*b;

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

template <class T, class Compare>
void
Multiset<T, Compare>::root_splice(iterator position)
{
	SetNode<value_type>		*ptr = position._node;
	SetNode<value_type>		*a;
	SetNode<value_type>		*b;

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

template <class T, class Compare>
void
Multiset<T, Compare>::erase(iterator position)
{
	SetNode<value_type>		*ptr = position._node;

	if (ptr->type == lft)
		left_splice(position);
	else if (ptr->type == rht)
		right_splice(position);
	else
		root_splice(position);
	--_size;
}

template <class T, class Compare>
typename Multiset<T, Compare>::size_type
Multiset<T, Compare>::erase(const value_type &v)
{
	iterator	it;
	size_type	count;

	for (count = 0; (it = lower_bound(v)) != upper_bound(v); ++count)
		erase(it);
	return (count);
}

template <class T, class Compare>
void
Multiset<T, Compare>::erase(iterator first, iterator last)
{
	iterator		tmp(first++);

	for (; tmp != last; tmp = first++)
		erase(tmp);
}

template <class T, class Compare>
void
Multiset<T, Compare>::swap(Multiset &x)
{
	SetNode<value_type>		*tmp = _root;
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

template <class T, class Compare>
void
Multiset<T, Compare>::clear(void)
{
	while (_size)
		erase(begin());
}

template <class T, class Compare>
typename Multiset<T, Compare>::key_compare
Multiset<T, Compare>::key_comp(void) const
{
	return (key_compare());
}

template <class T, class Compare>
typename Multiset<T, Compare>::value_compare
Multiset<T, Compare>::value_comp(void) const
{
	return (value_compare());
}

template <class T, class Compare>
typename Multiset<T, Compare>::iterator
Multiset<T, Compare>::find(const value_type &v) const
{
	iterator	it(_front.up);
	iterator	it_end(_size ? iterator(_back.up->right) : it);

	for (; it != it_end && (key_comp()(v, *it) || key_comp()(*it, v)); ++it);
	return (it);
}

template <class T, class Compare>
typename Multiset<T, Compare>::size_type
Multiset<T, Compare>::count(const value_type &v) const
{
	const_iterator		it(begin());
	size_type			count;

	for (count = 0; it != end(); ++it)
		if (!key_comp()(v, *it) && !key_comp()(*it, v))
			++count;
	return (count);
}

template <class T, class Compare>
typename Multiset<T, Compare>::iterator
Multiset<T, Compare>::lower_bound(const value_type &v) const
{
	iterator	it(_front.up);
	iterator	it_end(_size ? iterator(_back.up->right) : it);

	for (; it != it_end && key_comp()(*it, v); ++it);
	return (it);
}

template <class T, class Compare>
typename Multiset<T, Compare>::iterator
Multiset<T, Compare>::upper_bound(const value_type &v) const
{
	iterator	it(lower_bound(v));
	iterator	it_end(_size ? iterator(_back.up->right) : it);

	for (; it != it_end && !key_comp()(v, *it); ++it);
	return (it);
}

template <class T, class Compare>
ft::Pair<typename Multiset<T, Compare>::iterator, typename Multiset<T, Compare>::iterator>
Multiset<T, Compare>::equal_range(const value_type &v) const
{
	return (ft::make_pair(lower_bound(v), upper_bound(v)));
}

}

#endif //MULTISET_HPP
