/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ListIter.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcadet <cadet.florian@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 13:08:02 by fcadet            #+#    #+#             */
/*   Updated: 2020/03/01 18:22:41 by fcadet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LISTITER_HPP
# define LISTITER_HPP

template <typename T>
class	ListIter : public std::bidirectional_iterator_tag
{
	public:
		ListIter(ListNode **node = 0);
		ListIter(const ListIter &l);
		~ListIter(void);
		ListIter		&operator=(const ListIter &l);
		bool			operator==(const ListIter &l);
		bool			operator!=(const ListIter &l);
		T				&operator*(void);
		ListIter		&operator++(void);
		ListIter		operator++(int dummy);
		ListIter		&operator--(void);
		ListIter		operator--(int dummy);

	private:
		ListNode		**_node;
};

ListIter::ListIter(ListNode **n) : _node(node)
{
}

ListIter::ListIter(const ListIter &l) : _node(l._node)
{
}

ListIter::~ListIter(void)
{
}

ListIter		&ListIter::operator=(const ListIter &l)
{
	if (&l == this)
		return (*this);
	_node = l._node;
	return (*this);
}

#endif //LISTITER_HPP
