/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_deque.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcadet <cadet.florian@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 15:40:29 by fcadet            #+#    #+#             */
/*   Updated: 2020/03/21 18:31:40 by fcadet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_deque.hpp"

void	ndeque::test_deque(void)
{
	int					int_init[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	double				double_init[] = { 0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7,
										 0.8, 0.9 };
	std::string			string_init[] = { "A", "B", "C", "D", "E", "F", "G",
										  "H", "I" };

	(void)double_init;
	(void)string_init;

	std::cout << "\033[1;32mCONSTRUCTORS & ASSIGNATION :\n";
	test_const<ft::Deque<int>, int>(int_init, 9, 0, 9, "ft::Deque<int>");
	test_const<ft::Deque<double>, double>(double_init, 9, 0.0, 9, "ft::Deque<double>");
	test_const<ft::Deque<std::string>, std::string>(string_init, 9, "?", 9,
		"ft::Deque<string>");

	std::cout << "\n\033[1;32mITERATORS :\n";
	test_iter<ft::Deque<int>, int>(int_init, 9, "ft::Deque<int>");
	test_iter<ft::Deque<double>, double>(double_init, 9, "ft::Deque<double>");
	test_iter<ft::Deque<std::string>, std::string>(string_init, 9, "ft::Deque<string>");

	std::cout << "\n\033[1;32mCAPACITY :\n";
	test_capacity<ft::Deque<int>, int>(0, 9, "ft::Deque<int>");
	test_capacity<ft::Deque<double>, double>(0, 9, "ft::Deque<double>");
	test_capacity<ft::Deque<std::string>, std::string>("?", 9, "ft::Deque<string>");

	std::cout << "\n\033[1;32mACCESS :\n";
	test_access<ft::Deque<int>, int>(int_init, 9, "ft::Deque<int>");
	test_access<ft::Deque<double>, double>(double_init, 9, "ft::Deque<double>");
	test_access<ft::Deque<std::string>, std::string>(string_init, 9, "ft::Deque<string>");

	std::cout << "\n\033[1;32mMODIFIERS :\n";
	test_mod<ft::Deque<int>, int>(int_init, 9, 0, 9, "ft::Deque<int>");
	test_mod<ft::Deque<double>, double>(double_init, 9, 0, 9, "ft::Deque<double>");
	test_mod<ft::Deque<std::string>, std::string>(string_init, 9, "?", 9,
		"ft::Deque<string>");

	std::cout << "\n\033[1;32mNON-MEMBER :\n";
	test_nmem<ft::Deque<int>, int>(int_init, 9, 0, 9, "ft::Deque<int>");
	test_nmem<ft::Deque<double>, double>(double_init, 9, 0, 9, "ft::Deque<double>");
	test_nmem<ft::Deque<std::string>, std::string>(string_init, 9, "?", 9,
		"ft::Deque<string>");
}
