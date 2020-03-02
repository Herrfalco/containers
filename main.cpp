/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcadet <cadet.florian@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 17:04:56 by fcadet            #+#    #+#             */
/*   Updated: 2020/03/01 17:09:23 by fcadet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ListNode.hpp"
#include <iostream>

int		main(void)
{
	ListNode<int>	list(0, 0);

	list.val = 999;
	std::cout << list.val << std::endl;
}


