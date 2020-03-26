/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_stack.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcadet <cadet.florian@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 15:40:29 by fcadet            #+#    #+#             */
/*   Updated: 2020/03/22 17:26:26 by fcadet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_stack.hpp"

void	nstack::test_stack(void)
{
	int					int_init[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	double				double_init[] = { 0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7,
										 0.8, 0.9 };
	std::string			string_init[] = { "A", "B", "C", "D", "E", "F", "G",
										  "H", "I" };

	std::cout << "\033[1;32mCONSTRUCTORS & ASSIGNATION :\n";
	test_memb<ft::Stack<int>, int>(int_init, "ft::Stack<int>");
	test_memb<ft::Stack<double>, double>(double_init, "ft::Stack<double>");
	test_memb<ft::Stack<std::string>, std::string>(string_init, "ft::Stack<string>");

	std::cout << "\n\033[1;32mNON-MEMBER :\n";
	test_nmem<ft::Stack<int>, int>(int_init, "ft::Stack<int>");
	test_nmem<ft::Stack<double>, double>(double_init, "ft::Stack<double>");
	test_nmem<ft::Stack<std::string>, std::string>(string_init, "ft::Stack<string>");
}
