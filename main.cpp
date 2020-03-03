/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcadet <cadet.florian@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 17:04:56 by fcadet            #+#    #+#             */
/*   Updated: 2020/03/03 19:36:36 by fcadet           ###   ########.fr       */
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
