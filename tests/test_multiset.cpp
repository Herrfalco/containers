/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_multiset.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcadet <cadet.florian@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 15:40:29 by fcadet            #+#    #+#             */
/*   Updated: 2020/03/25 16:37:50 by fcadet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_multiset.hpp"

void	nmultiset::test_multiset(void)
{
	int					int_init[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	double				double_init[] = { 0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7,
										 0.8, 0.9 };
	std::string			string_init[] = { "A", "B", "C", "D", "E", "F", "G",
										  "H", "I" };
													   
	std::cout << "\033[1;32mCONSTRUCTORS & ASSIGNATION :\n";
	test_const<ft::Multiset<int>, int>(int_init, 9, "ft::Multiset<int>");
	test_const<ft::Multiset<double>, double>(double_init, 9, "ft::Multiset<double>");
	test_const<ft::Multiset<std::string>, std::string>(string_init, 9, "ft::Multiset<string>");

	std::cout << "\n\033[1;32mITERATORS :\n";
	test_iter<ft::Multiset<int>, int>(int_init, 9, "ft::Multiset<int>");
	test_iter<ft::Multiset<double>, double>(double_init, 9, "ft::Multiset<double>");
	test_iter<ft::Multiset<std::string>, std::string>(string_init, 9, "ft::Multiset<string>");

	std::cout << "\n\033[1;32mCAPACITY :\n";
	test_capacity<ft::Multiset<int>, int>(int_init, 9, "ft::Multiset<int>");
	test_capacity<ft::Multiset<double>, double>(double_init, 9, "ft::Multiset<double>");
	test_capacity<ft::Multiset<std::string>, std::string>(string_init, 9, "ft::Multiset<string>");

	std::cout << "\n\033[1;32mMODIFIERS :\n";
	test_mod<ft::Multiset<int>, int>(int_init, 9, "ft::Multiset<int>");
	test_mod<ft::Multiset<double>, double>(double_init, 9, "ft::Multiset<double>");
	test_mod<ft::Multiset<std::string>, std::string>(string_init, 9, "ft::Multiset<string>");

	std::cout << "\n\033[1;32mOBSERVERS :\n";
	test_obs<ft::Multiset<int>, int>(int_init, 9, "ft::Multiset<int>");
	test_obs<ft::Multiset<double>, double>(double_init, 9, "ft::Multiset<double>");
	test_obs<ft::Multiset<std::string>, std::string>(string_init, 9, "ft::Multiset<string>");

	std::cout << "\n\033[1;32mOPERATIONS :\n";
	test_op<ft::Multiset<int>, int>(int_init, 9, "ft::Multiset<int>");
	test_op<ft::Multiset<double>, double>(double_init, 9, "ft::Multiset<double>");
	test_op<ft::Multiset<std::string>, std::string>(string_init, 9, "ft::Multiset<string>");
}
