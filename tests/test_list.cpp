/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_list.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcadet <cadet.florian@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 15:40:29 by fcadet            #+#    #+#             */
/*   Updated: 2020/03/25 14:25:42 by fcadet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_list.hpp"

void	nlist::test_list(void)
{
	int					int_init[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	double				double_init[] = { 0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7,
										 0.8, 0.9 };
	std::string			string_init[] = { "A", "B", "C", "D", "E", "F", "G",
										  "H", "I" };

	std::cout << "\033[1;32mCONSTRUCTORS & ASSIGNATION :\n";
	test_const<ft::List<int>, int>(int_init, 9, 0, 9, "ft::List<int>");
	test_const<ft::List<double>, double>(double_init, 9, 0.0, 9, "ft::List<double>");
	test_const<ft::List<std::string>, std::string>(string_init, 9, "?", 9,
		"ft::List<string>");

	std::cout << "\n\033[1;32mITERATORS :\n";
	test_iter<ft::List<int>, int>(int_init, 9, "ft::List<int>");
	test_iter<ft::List<double>, double>(double_init, 9, "ft::List<double>");
	test_iter<ft::List<std::string>, std::string>(string_init, 9, "ft::List<string>");

	std::cout << "\n\033[1;32mCAPACITY :\n";
	test_capacity<ft::List<int>, int>(int_init, 9, "ft::List<int>");
	test_capacity<ft::List<double>, double>(double_init, 9, "ft::List<double>");
	test_capacity<ft::List<std::string>, std::string>(string_init, 9, "ft::List<string>");

	std::cout << "\n\033[1;32mACCESS :\n";
	test_access<ft::List<int>, int>(int_init, 9, "ft::List<int>");
	test_access<ft::List<double>, double>(double_init, 9, "ft::List<double>");
	test_access<ft::List<std::string>, std::string>(string_init, 9, "ft::List<string>");

	std::cout << "\n\033[1;32mMODIFIERS :\n";
	test_mod<ft::List<int>, int>(int_init, 9, 0, 9, "ft::List<int>");
	test_mod<ft::List<double>, double>(double_init, 9, 0, 9, "ft::List<double>");
	test_mod<ft::List<std::string>, std::string>(string_init, 9, "?", 9,
		"ft::List<string>");

	std::cout << "\n\033[1;32mOPERATIONS :\n";
	test_op<ft::List<int>, int>(int_init, 9, 0, 9, "ft::List<int>");
	test_op<ft::List<double>, double>(double_init, 9, 0, 9, "ft::List<double>");
	test_op<ft::List<std::string>, std::string>(string_init, 9, "?", 9,
		"ft::List<string>");

	std::cout << "\n\033[1;32mNON-MEMBER :\n";
	test_nmem<ft::List<int>, int>(int_init, 9, 0, 9, "ft::List<int>");
	test_nmem<ft::List<double>, double>(double_init, 9, 0, 9, "ft::List<double>");
	test_nmem<ft::List<std::string>, std::string>(string_init, 9, "?", 9,
		"ft::List<string>");
}
