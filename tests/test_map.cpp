/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_map.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcadet <cadet.florian@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 15:40:29 by fcadet            #+#    #+#             */
/*   Updated: 2020/03/25 14:26:31 by fcadet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_map.hpp"

void	nmap::test_map(void)
{
	ft::Pair<std::string, int>		str_int_init[] = { ft::make_pair("Bravo", 2),
													   ft::make_pair("Alpha", 1),
													   ft::make_pair("Delta", 4),
													   ft::make_pair("Echo", 5),
													   ft::make_pair("Golf", 7),
													   ft::make_pair("Charlie", 3),
													   ft::make_pair("Foxtrot", 6) };
	ft::Pair<int, std::string>		int_str_init[] = { ft::make_pair(2, "Bravo"),
													   ft::make_pair(1, "Alpha"),
													   ft::make_pair(4, "Delta"),
													   ft::make_pair(5, "Echo"),
													   ft::make_pair(7, "Golf"),
													   ft::make_pair(3, "Charlie"),
													   ft::make_pair(6, "Foxtrot") };
													   
	std::cout << "\033[1;32mCONSTRUCTORS & ASSIGNATION :\n";
	test_const<ft::Map<std::string, int> >(str_int_init, 7, "ft::Map<string, int>");
	test_const<ft::Map<int, std::string> >(int_str_init, 7, "ft::Map<int, string>");

	std::cout << "\n\033[1;32mITERATORS :\n";
	test_iter<ft::Map<std::string, int> >(str_int_init, 7, "ft::Map<string, int>");
	test_iter<ft::Map<int, std::string> >(int_str_init, 7, "ft::Map<int, string>");

	std::cout << "\n\033[1;32mCAPACITY :\n";
	test_capacity<ft::Map<std::string, int> >(str_int_init, 7, "ft::Map<string, int>");
	test_capacity<ft::Map<int, std::string> >(int_str_init, 7, "ft::Map<int, string>");

	std::cout << "\n\033[1;32mACCESS :\n";
	test_access<ft::Map<std::string, int> >(str_int_init, 7, "ft::Map<string, int>");
	test_access<ft::Map<int, std::string> >(int_str_init, 7, "ft::Map<int, string>");

	std::cout << "\n\033[1;32mMODIFIERS :\n";
	test_mod<ft::Map<std::string, int> >(str_int_init, 7, "ft::Map<string, int>");
	test_mod<ft::Map<int, std::string> >(int_str_init, 7, "ft::Map<int, string>");

	std::cout << "\n\033[1;32mOBSERVERS :\n";
	test_obs<ft::Map<std::string, int> >(str_int_init, 7, "ft::Map<string, int>");
	test_obs<ft::Map<int, std::string> >(int_str_init, 7, "ft::Map<int, string>");

	std::cout << "\n\033[1;32mOPERATIONS :\n";
	test_op<ft::Map<std::string, int> >(str_int_init, 7, "ft::Map<string, int>");
	test_op<ft::Map<int, std::string> >(int_str_init, 7, "ft::Map<int, string>");
}
