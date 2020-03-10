/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_vect.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcadet <cadet.florian@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 15:40:29 by fcadet            #+#    #+#             */
/*   Updated: 2020/03/10 23:58:17 by fcadet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_vect.hpp"

void	nvect::test_vect(void)
{
	int					int_init[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	double				double_init[] = { 0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7,
										 0.8, 0.9 };
	std::string			string_init[] = { "A", "B", "C", "D", "E", "F", "G",
										  "H", "I" };

	std::cout << "\033[1;32mCONSTRUCTORS & ASSIGNATION :\n";
	test_const<ft::Vector<int>, int>(int_init, 9, 0, 9, "ft::Vector<int>");
	test_const<ft::Vector<double>, double>(double_init, 9, 0.0, 9, "ft::Vector<double>");
	test_const<ft::Vector<std::string>, std::string>(string_init, 9, "?", 9,
		"ft::Vector<string>");

	std::cout << "\n\033[1;32mITERATORS :\n";
	test_iter<ft::Vector<int>, int>(int_init, 9, "ft::Vector<int>");
	test_iter<ft::Vector<double>, double>(double_init, 9, "ft::Vector<double>");
	test_iter<ft::Vector<std::string>, std::string>(string_init, 9, "ft::Vector<string>");

	std::cout << "\n\033[1;32mCAPACITY :\n";
	test_capacity<ft::Vector<int>, int>(0, 9, "ft::Vector<int>");
	test_capacity<ft::Vector<double>, double>(0, 9, "ft::Vector<double>");
	test_capacity<ft::Vector<std::string>, std::string>("?", 9, "ft::Vector<string>");

	std::cout << "\n\033[1;32mACCESS :\n";
	test_access<ft::Vector<int>, int>(int_init, 9, "ft::Vector<int>");
	test_access<ft::Vector<double>, double>(double_init, 9, "ft::Vector<double>");
	test_access<ft::Vector<std::string>, std::string>(string_init, 9, "ft::Vector<string>");

/*
	std::cout << "\n\033[1;32mMODIFIERS :\n";
	test_mod<ft::Vector<int>, int>(int_init, 9, 0, 9, "ft::Vector<int>");
	test_mod<ft::Vector<double>, double>(double_init, 9, 0, 9, "ft::Vector<double>");
	test_mod<ft::Vector<std::string>, std::string>(string_init, 9, "?", 9,
		"ft::Vector<string>");

	std::cout << "\n\033[1;32mOPERATIONS :\n";
	test_op<ft::Vector<int>, int>(int_init, 9, 0, 9, "ft::Vector<int>");
	test_op<ft::Vector<double>, double>(double_init, 9, 0, 9, "ft::Vector<double>");
	test_op<ft::Vector<std::string>, std::string>(string_init, 9, "?", 9,
		"ft::Vector<string>");

	std::cout << "\n\033[1;32mNON-MEMBER :\n";
	test_nmem<ft::Vector<int>, int>(int_init, 9, 0, 9, "ft::Vector<int>");
	test_nmem<ft::Vector<double>, double>(double_init, 9, 0, 9, "ft::Vector<double>");
	test_nmem<ft::Vector<std::string>, std::string>(string_init, 9, "?", 9,
		"ft::Vector<string>");
*/
}
