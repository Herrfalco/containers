/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcadet <cadet.florian@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 17:00:58 by fcadet            #+#    #+#             */
/*   Updated: 2020/03/07 21:13:51 by fcadet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_HPP
# define TEST_HPP

# include "List.hpp"
# include <iostream>
# include <string>
# include <sstream>

template <class T>
void	print_cont(const T &cont, const std::string &name, const std::string &msg)
{
	typename T::const_iterator		it_var;

	std::cout << "      \033[1;36m" << msg << "\n";
	std::cout << "         \033[0m" << name << " : [ ";
	for (typename T::const_iterator it(cont.begin()); it != cont.end(); ++it)
	{
		it_var = it;
		std::cout << *it << (++it_var != cont.end() ? ", " : "");
	}
	std::cout << " ]\n";
}

template <class T>
void	rprint_cont(const T &cont, const std::string &name, const std::string &msg)
{
	typename T::const_reverse_iterator		rit_var;

	std::cout << "      \033[1;36m" << msg << "\n";
	std::cout << "         \033[0m" << name << " : [ ";
	for (typename T::const_reverse_iterator rit(cont.rbegin()); rit != cont.rend(); ++rit)
	{
		rit_var = rit;
		std::cout << *rit << (++rit_var != cont.rend() ? ", " : "");
	}
	std::cout << " ]\n";
}

template <class Cont, class T>
void	test_const(T *init, size_t size_init, T def, size_t size_def, std::string name)
{
	Cont				c1;
	Cont				c2(size_def, def);
	Cont				c3(init, init + size_init);
	Cont				c4(c3);
	std::stringstream	ss;

	std::cout << "   \033[1;33m" << name << "\033[0m\n";
	print_cont(c1, "I", "I()");
	ss << "II(" << size_def << ", " << def << ")";
	print_cont(c2, "II", ss.str());
	ss.str("");
	ss << "III(init, init + " << size_init << ")";
	print_cont(c3, "III", ss.str());
	print_cont(c4, "IV", "IV(III)");
	c1 = c2;
	print_cont(c1, "I", "I = II");
}

template <class Cont, class T>
void	print_revprint(T *init, size_t size_init, std::string name)
{
	Cont	c(init, init + size_init);

	std::cout << "   \033[1;33m" << name << "\n\033[0m";
	print_cont(c, "Order", "Forward");
	rprint_cont(c, "Order", "Backward");
}

template <class Cont, class T>
void	test_capacity(T *init, size_t size_init, std::string name)
{
	Cont				c1;
	Cont				c2(init, init + size_init);
	std::stringstream	ss;

	std::cout << "   \033[1;33m" << name << "\033[0m\n";
	print_cont(c1, "I", "I()");
	std::cout << "\033[1;36m      I.empty()\033[0m\n         result : "
		<< (c1.empty() ? "true" : "false") << "\n\033[0m";
	std::cout << "\033[1;36m      I.size()\033[0m\n         result : "
		<< c1.size() << "\n\033[0m";
	std::cout << "\033[1;36m      I.max_size()\033[0m\n         result : "
		<< c1.max_size() << "\n\033[0m";
	ss << "II(init, init + " << size_init << ")";
	print_cont(c2, "II", ss.str());
	std::cout << "\033[1;36m      II.empty()\033[0m\n         result : "
		<< (c2.empty() ? "true" : "false") << "\n\033[0m";
	std::cout << "\033[1;36m      II.size()\033[0m\n         result : "
		<< c2.size() << "\n\033[0m";
	std::cout << "\033[1;36m      II.max_size()\033[0m\n         result : "
		<< c2.max_size() << "\n\033[0m";
}

#endif	//TEST_HPP
