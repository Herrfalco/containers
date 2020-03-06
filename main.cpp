/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcadet <cadet.florian@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 17:04:56 by fcadet            #+#    #+#             */
/*   Updated: 2020/03/06 18:58:40 by fcadet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "List.hpp"
#include <iostream>

struct	Test
{
	Test(int v = 0) : val(v) {}	
	int		val;
};

int		main(void)
{
	int						init1[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };		
	List<int>				lst1(init1, init1 + 10);
	int						init2[] = { 10, 11, 11, 12, 13, 14, 15, 16, 17, 18, 19 };
	List<int>				lst2(init2, init2 + 11);
	List<int>::iterator		ite = lst1.end();

	std::cout << (lst1 == lst2 ? "equal" : "different") << std::endl;
/*
	ite++;
	++ite;
	ite++;
	for (List<int>::reverse_iterator it(ite); it != lst1.rend(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
*/
/*
	lst.insert(ite, size_t(3), 0);
	for (List<int>::reverse_iterator it = lst.rbegin(); it != lst.rend(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	lst.insert(ite, init2, init2 + 10);
	for (List<int>::reverse_iterator it = lst.rbegin(); it != lst.rend(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	lst.sort();
	lst.unique();
	lst.reverse();
	for (List<int>::reverse_iterator it = lst.rbegin(); it != lst.rend(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
*/
/*
	ListNode<Test>	dumbeg;
	ListNode<Test>	elem1(1);
	ListNode<Test>	elem2(2);
	ListNode<Test>	elem3(3);
	ListNode<Test>	dumend;
	ListIter<bidirectional_iterator_tag, Test>	beg(&elem1);
	ListIter<bidirectional_iterator_tag, Test>	end(&dumend);

	dumbeg.next = &elem1;
	elem1.next = &elem2;
	elem2.next = &elem3;
	elem3.next = &dumend;
	dumend.prev = &elem3;
	elem3.prev = &elem2;
	elem2.prev = &elem1;
	elem1.prev = &dumbeg;
	for (; beg != end; ++beg)
		std::cout << beg->val << std::endl;
	RevIter<ListIter<bidirectional_iterator_tag, Test> >	rbeg(end);
	RevIter<ListIter<bidirectional_iterator_tag, Test> >	rend(&elem1);
	for (; rbeg != rend; ++rbeg)
		std::cout << rbeg->val << std::endl;

	std::cout << (ite == ite2 ? "equal" : "different") << std::endl;
	ite2++;
	std::cout << (ite == ite2 ? "equal" : "different") << std::endl;
	ite2 = ite;
	std::cout << (ite == ite2 ? "equal" : "different") << std::endl;
	std::cout << *ite2 << std::endl;
	*ite2 = 2;
	std::cout << *ite2 << std::endl;
	std::cout << *ite++ << std::endl;
	std::cout << *ite << std::endl;
	std::cout << *++ite << std::endl;
	std::cout << *ite-- << std::endl;
	std::cout << *ite << std::endl;
	std::cout << *--ite << std::endl;
	ListNode<int>	elem4(elem3);
	std::cout << elem4.val << std::endl;
*/
	return (0);
}
