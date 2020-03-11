/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcadet <cadet.florian@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 17:04:56 by fcadet            #+#    #+#             */
/*   Updated: 2020/03/11 16:13:55 by fcadet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests/test_list.hpp"
#include "tests/test_vect.hpp"

int		error(std::string msg, int ret)
{
	std::cout << "error: " << msg << ".\n";
	return (ret);
}

int		main(int ac, char **av)
{
	std::string		par;

	if (ac != 2)
		return (error("tester needs a container type as parameter", 1));
	par = *(++av);
	if (!par.compare("List") || !par.compare("list"))
		nlist::test_list();
	else if (!par.compare("Vector") || !par.compare("vector"))
		nvect::test_vect();
	else
		return (error("unknown container type", 2));
//	system("leaks test");
	return (0);
}
