/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_common.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcadet <cadet.florian@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 16:19:42 by fcadet            #+#    #+#             */
/*   Updated: 2020/03/24 18:04:36 by fcadet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_COMMON_HPP
# define TEST_COMMON_HPP

# include <iostream>
# include <string>
# include <sstream>

template <class T>
void	print_cont(const T &cont, const std::string &name, const std::string &msg)
{
	typename T::const_iterator		it_var;

	if (msg.size())
		std::cout << "      \033[1;36m" << msg << "\n";
	std::cout << "         \033[0m" << name << " : [ ";
	for (typename T::const_iterator it(cont.begin()); it != cont.end(); ++it)
	{
		it_var = it;
		std::cout << *it << (++it_var != cont.end() ? ", " : "");
	}
	std::cout << " ] (" << cont.size() << ")\n";
}

template <class T>
void	rprint_cont(const T &cont, const std::string &name, const std::string &msg)
{
	typename T::const_reverse_iterator		rit_var;

	if (msg.size())
		std::cout << "      \033[1;36m" << msg << "\n";
	std::cout << "         \033[0m" << name << " : [ ";
	for (typename T::const_reverse_iterator rit(cont.rbegin()); rit != cont.rend(); ++rit)
	{
		rit_var = rit;
		std::cout << *rit << (++rit_var != cont.rend() ? ", " : "");
	}
	std::cout << " ] (" << cont.size() << ")\n";
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
void	test_iter(T *init, size_t size_init, std::string name)
{
	Cont				c(init, init + size_init);
	std::stringstream		ss;

	std::cout << "   \033[1;33m" << name << "\n\033[0m";
	ss << "I(init, init + " << size_init << ")";
	print_cont(c, "I", ss.str());
	print_cont(c, "I", "Regular");
	rprint_cont(c, "I", "Reverse");
}

#endif //TEST_COMMON_HPP
