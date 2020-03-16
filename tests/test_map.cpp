/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_map.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcadet <cadet.florian@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 15:40:29 by fcadet            #+#    #+#             */
/*   Updated: 2020/03/16 17:11:48 by fcadet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_map.hpp"

void	nmap::test_map(void)
{
	std::pair<std::string, int>		str_int_init[] = { std::make_pair("Bravo", 2),
													   std::make_pair("Alpha", 1),
													   std::make_pair("Delta", 4),
													   std::make_pair("Echo", 5),
													   std::make_pair("Golf", 7),
													   std::make_pair("Charlie", 3),
													   std::make_pair("Foxtrot", 6) };
	std::pair<int, std::string>		int_str_init[] = { std::make_pair(2, "Bravo"),
													   std::make_pair(1, "Alpha"),
													   std::make_pair(4, "Delta"),
													   std::make_pair(5, "Echo"),
													   std::make_pair(7, "Golf"),
													   std::make_pair(3, "Charlie"),
													   std::make_pair(6, "Foxtrot") };
													   
	std::cout << "\033[1;32mCONSTRUCTORS & ASSIGNATION :\n";
	nmap::test_const<ft::Map<std::string, int> >(str_int_init, 7, "ft::Map<string, int>");
	nmap::test_const<ft::Map<int, std::string> >(int_str_init, 7, "ft::Map<int, string>");

	std::cout << "\n\033[1;32mITERATORS :\n";
	nmap::test_iter<ft::Map<std::string, int> >(str_int_init, 7, "ft::Map<string, int>");
	nmap::test_iter<ft::Map<int, std::string> >(int_str_init, 7, "ft::Map<int, string>");

	std::cout << "\n\033[1;32mCAPACITY :\n";
	nmap::test_capacity<ft::Map<std::string, int> >(str_int_init, 7,
		"ft::Map<string, int>");
	nmap::test_capacity<ft::Map<int, std::string> >(int_str_init, 7,
		"ft::Map<int, string>");

	std::cout << "\n\033[1;32mACCESS :\n";
	nmap::test_access<ft::Map<std::string, int> >(str_int_init, 7,
		"ft::Map<string, int>");
	nmap::test_access<ft::Map<int, std::string> >(int_str_init, 7,
		"ft::Map<int, string>");

	std::cout << "\n\033[1;32mMODIFIERS :\n";
	nmap::test_mod<ft::Map<std::string, int> >(str_int_init, 7, "ft::Map<string, int>");
	nmap::test_mod<ft::Map<int, std::string> >(int_str_init, 7, "ft::Map<int, string>");

	std::cout << "\n\033[1;32mOBSERVERS :\n";
	nmap::test_obs<ft::Map<std::string, int> >(str_int_init, 7, "ft::Map<string, int>");
	nmap::test_obs<ft::Map<int, std::string> >(int_str_init, 7, "ft::Map<int, string>");

	std::cout << "\n\033[1;32mOPERATIONS :\n";
	nmap::test_op<ft::Map<std::string, int> >(str_int_init, 7, "ft::Map<string, int>");
	nmap::test_op<ft::Map<int, std::string> >(int_str_init, 7, "ft::Map<int, string>");

/*
	std::cout << "\n\033[1;32mNON-MEMBER :\n";
	nmap::test_nmem<ft::Map<int>, int>(int_init, 9, 0, 9, "ft::Map<int>");
	nmap::test_nmem<ft::Map<double>, double>(double_init, 9, 0, 9, "ft::Map<double>");
	nmap::test_nmem<ft::Map<std::string>, std::string>(string_init, 9, "?", 9,
		"ft::Map<string>");
*/
}
