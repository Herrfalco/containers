/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcadet <cadet.florian@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 17:04:56 by fcadet            #+#    #+#             */
/*   Updated: 2020/03/07 21:15:29 by fcadet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.hpp"

void	make_tests(void)
{
	int					int_init[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	double				double_init[] = { 0.0, 0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7,
										 0.8, 0.9 };
	std::string			string_init[] = { "zero", "one", "two", "three", "four",
										  "five", "six", "seven", "eight", "nine" };

	std::cout << "\033[1;32mCONSTRUCTORS & ASSIGNATION :\n";
	test_const<List<int>, int>(int_init, 10, 0, 10, "List<int>");
	test_const<List<double>, double>(double_init, 10, 0.0, 10, "List<double>");
	test_const<List<std::string>, std::string>(string_init, 10, "empty", 10,
		"List<string>");
	std::cout << "\n\033[1;32m(R)BEGIN & (R)END :\n";
	print_revprint<List<int>, int>(int_init, 10, "List<int>");
	print_revprint<List<double>, double>(double_init, 10, "List<double>");
	print_revprint<List<std::string>, std::string>(string_init, 10, "List<string>");
	std::cout << "\n\033[1;32mCAPACITY :\n";
	test_capacity<List<int>, int>(int_init, 10, "List<int>");
	test_capacity<List<double>, double>(double_init, 10, "List<double>");
	test_capacity<List<std::string>, std::string>(string_init, 10, "List<string>");
}

int		main(void)
{
	make_tests();
//	system("leaks test");
	return (0);
}
