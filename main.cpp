/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcadet <cadet.florian@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 17:04:56 by fcadet            #+#    #+#             */
/*   Updated: 2020/03/02 18:46:17 by fcadet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ListIter.hpp"
#include "IterTypes.hpp"
#include <iostream>

struct	Test
{
	Test(int v = 0) : val(v) {}	
	int		val;
};

int		main(void)
{
/*
	ListNode<Test>	elem1(1);	
	ListNode<Test>	elem2(2);	
	ListNode<Test>	elem3(3);	
	ListIter<Test>	ite(&elem1);

	elem1.next = &elem2;
	elem2.next = &elem3;
	elem3.prev = &elem2;
	elem2.prev = &elem1;
	std::cout << *ite << std::endl;
*/

	ListNode<int>	elem1(1);
	ListNode<int>	elem2(0);
	ListNode<int>	elem3(3);
	ListIter<bidirectional_iterator_tag, int>	ite(&elem1);
	ListIter<bidirectional_iterator_tag, int>	ite2(ite);

	elem1.next = &elem2;
	elem2.next = &elem3;
	elem3.prev = &elem2;
	elem2.prev = &elem1;
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
}
