/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_set.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcadet <cadet.florian@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 15:40:29 by fcadet            #+#    #+#             */
/*   Updated: 2020/03/25 14:27:08 by fcadet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_set.hpp"

void	nset::test_set(void)
{
	int					int_init[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	double				double_init[] = { 0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7,
										 0.8, 0.9 };
	std::string			string_init[] = { "A", "B", "C", "D", "E", "F", "G",
										  "H", "I" };
													   
	std::cout << "\033[1;32mCONSTRUCTORS & ASSIGNATION :\n";
	test_const<ft::Set<int>, int>(int_init, 9, "ft::Set<int>");
	test_const<ft::Set<double>, double>(double_init, 9, "ft::Set<double>");
	test_const<ft::Set<std::string>, std::string>(string_init, 9, "ft::Set<string>");

	std::cout << "\n\033[1;32mITERATORS :\n";
	test_iter<ft::Set<int>, int>(int_init, 9, "ft::Set<int>");
	test_iter<ft::Set<double>, double>(double_init, 9, "ft::Set<double>");
	test_iter<ft::Set<std::string>, std::string>(string_init, 9, "ft::Set<string>");

	std::cout << "\n\033[1;32mCAPACITY :\n";
	test_capacity<ft::Set<int>, int>(int_init, 9, "ft::Set<int>");
	test_capacity<ft::Set<double>, double>(double_init, 9, "ft::Set<double>");
	test_capacity<ft::Set<std::string>, std::string>(string_init, 9, "ft::Set<string>");

	std::cout << "\n\033[1;32mMODIFIERS :\n";
	test_mod<ft::Set<int>, int>(int_init, 9, "ft::Set<int>");
	test_mod<ft::Set<double>, double>(double_init, 9, "ft::Set<double>");
	test_mod<ft::Set<std::string>, std::string>(string_init, 9, "ft::Set<string>");

	std::cout << "\n\033[1;32mOBSERVERS :\n";
	test_obs<ft::Set<int>, int>(int_init, 9, "ft::Set<int>");
	test_obs<ft::Set<double>, double>(double_init, 9, "ft::Set<double>");
	test_obs<ft::Set<std::string>, std::string>(string_init, 9, "ft::Set<string>");

	std::cout << "\n\033[1;32mOPERATIONS :\n";
	test_op<ft::Set<int>, int>(int_init, 9, "ft::Set<int>");
	test_op<ft::Set<double>, double>(double_init, 9, "ft::Set<double>");
	test_op<ft::Set<std::string>, std::string>(string_init, 9, "ft::Set<string>");
}
