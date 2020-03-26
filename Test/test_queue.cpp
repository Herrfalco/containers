/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_queue.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcadet <cadet.florian@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 15:40:29 by fcadet            #+#    #+#             */
/*   Updated: 2020/03/23 14:56:14 by fcadet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_queue.hpp"

void	nqueue::test_queue(void)
{
	int					int_init[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	double				double_init[] = { 0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7,
										 0.8, 0.9 };
	std::string			string_init[] = { "A", "B", "C", "D", "E", "F", "G",
										  "H", "I" };

	std::cout << "\033[1;32mCONSTRUCTORS & ASSIGNATION :\n";
	test_memb<ft::Queue<int>, int>(int_init, "ft::Queue<int>");
	test_memb<ft::Queue<double>, double>(double_init, "ft::Queue<double>");
	test_memb<ft::Queue<std::string>, std::string>(string_init, "ft::Queue<string>");

	std::cout << "\n\033[1;32mNON-MEMBER :\n";
	test_nmem<ft::Queue<int>, int>(int_init, "ft::Queue<int>");
	test_nmem<ft::Queue<double>, double>(double_init, "ft::Queue<double>");
	test_nmem<ft::Queue<std::string>, std::string>(string_init, "ft::Queue<string>");
}
