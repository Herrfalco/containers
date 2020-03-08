/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcadet <cadet.florian@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 17:04:56 by fcadet            #+#    #+#             */
/*   Updated: 2020/03/08 01:54:19 by fcadet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.hpp"

void	make_tests(void)
{
	int					int_init[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	double				double_init[] = { 0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7,
										 0.8, 0.9 };
	std::string			string_init[] = { "A", "B", "C", "D", "E", "F", "G",
										  "H", "I" };

	std::cout << "\033[1;32mCONSTRUCTORS & ASSIGNATION :\n";
	test_const<List<int>, int>(int_init, 9, 0, 9, "List<int>");
	test_const<List<double>, double>(double_init, 9, 0.0, 9, "List<double>");
	test_const<List<std::string>, std::string>(string_init, 9, "?", 9,
		"List<string>");

	std::cout << "\n\033[1;32mITERATORS :\n";
	test_iter<List<int>, int>(int_init, 9, "List<int>");
	test_iter<List<double>, double>(double_init, 9, "List<double>");
	test_iter<List<std::string>, std::string>(string_init, 9, "List<string>");

	std::cout << "\n\033[1;32mCAPACITY :\n";
	test_capacity<List<int>, int>(int_init, 9, "List<int>");
	test_capacity<List<double>, double>(double_init, 9, "List<double>");
	test_capacity<List<std::string>, std::string>(string_init, 9, "List<string>");

	std::cout << "\n\033[1;32mACCESS :\n";
	test_access<List<int>, int>(int_init, 9, "List<int>");
	test_access<List<double>, double>(double_init, 9, "List<double>");
	test_access<List<std::string>, std::string>(string_init, 9, "List<string>");

	std::cout << "\n\033[1;32mMODIFIERS :\n";
	test_mod<List<int>, int>(int_init, 9, 0, 9, "List<int>");
	test_mod<List<double>, double>(double_init, 9, 0, 9, "List<double>");
	test_mod<List<std::string>, std::string>(string_init, 9, "?", 9,
		"List<string>");
}

int		main(void)
{
	make_tests();
//	system("leaks test");
	return (0);
}
