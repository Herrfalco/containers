/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcadet <cadet.florian@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 17:04:56 by fcadet            #+#    #+#             */
/*   Updated: 2020/03/25 17:01:08 by fcadet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests/test_list.hpp"
#include "tests/test_vector.hpp"
#include "tests/test_map.hpp"
#include "tests/test_deque.hpp"
#include "tests/test_stack.hpp"
#include "tests/test_queue.hpp"
#include "tests/test_set.hpp"
#include "tests/test_multiset.hpp"
#include <fstream>

int		error(std::string msg, int ret)
{
	std::cout << "error: " << msg << ".\n";
	return (ret);
}

int		main(int ac, char **av)
{
	std::ofstream	out(".tmp");
	std::string		par;
	std::streambuf	*out_sav;

	if (ac != 2)
		return (error("tester needs a container type as parameter", 1));
	par = *(++av);
	out_sav = std::cout.rdbuf();
	std::cout.rdbuf(out.rdbuf());
	if (!par.compare("List") || !par.compare("list"))
		nlist::test_list();
	else if (!par.compare("Vector") || !par.compare("vector"))
		nvector::test_vector();
	else if (!par.compare("Map") || !par.compare("map"))
		nmap::test_map();
	else if (!par.compare("Deque") || !par.compare("deque"))
		ndeque::test_deque();
	else if (!par.compare("Stack") || !par.compare("stack"))
		nstack::test_stack();
	else if (!par.compare("Queue") || !par.compare("queue"))
		nqueue::test_queue();
	else if (!par.compare("Set") || !par.compare("set"))
		nset::test_set();
	else if (!par.compare("Multiset") || !par.compare("multiset"))
		nmultiset::test_multiset();
	else
	{
		std::cout.rdbuf(out_sav);
		return (error("unknown container type", 2));
	}
	std::cout << std::endl;
	std::cout.rdbuf(out_sav);
	return (system("cat .tmp | less"));
}
