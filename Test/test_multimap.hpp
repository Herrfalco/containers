/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_multimap.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcadet <cadet.florian@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 17:00:58 by fcadet            #+#    #+#             */
/*   Updated: 2020/03/29 16:22:53 by fcadet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_MULTIMAP_HPP
# define TEST_MULTIMAP_HPP

# include "../Multimap/Multimap.hpp"

# include <iostream>
# include <string>
# include <sstream>

namespace	nmultimap
{

void	test_multimap(void);

template <class T>
void	print_cont(const T &cont, const std::string &name, const std::string &msg)
{
	typename T::const_iterator		it_var;

	if (msg.size())
	{
		std::cout << "      ";
		for (size_t i = 0; i < msg.size(); ++i)
			std::cout << "\033[1;36m" << msg[i];
		std::cout << std::endl;
	}
	std::cout << "         \033[0m" << name << " : [ ";
	for (typename T::const_iterator it(cont.begin()); it != cont.end(); ++it)
	{
		it_var = it;
		std::cout << it->first << ":" << it->second
			<< (++it_var != cont.end() ? ", " : "");
	}
	std::cout << " ] (" << cont.size() << ")\n";
}

template <class T>
void	rprint_cont(const T &cont, const std::string &name, const std::string &msg)
{
	typename T::const_reverse_iterator		rit_var;

	if (msg.size())
	{
		std::cout << "      ";
		for (size_t i = 0; i < msg.size(); ++i)
			std::cout << "\033[1;36m" << msg[i];
		std::cout << std::endl;
	}
	std::cout << "         \033[0m" << name << " : [ ";
	typename T::const_iterator				it(cont.end());
	for (typename T::const_reverse_iterator rit(cont.rbegin()); rit != cont.rend(); ++rit)
	{
		rit_var = rit;
		std::cout << rit->first << ":" << rit->second
			<< (++rit_var != cont.rend() ? ", " : "");
	}
	std::cout << " ] (" << cont.size() << ")\n";
}

template <class Cont, class T>
void	test_const(T *init, size_t size_init, std::string name)
{
	Cont				c1;
	Cont				c2(init, init + size_init);
	Cont				c3(c2);
	std::stringstream	ss;

	std::cout << "   \033[1;33m" << name << "\033[0m\n";
	print_cont(c1, "I", "I()");
	ss << "II(init, init + " << size_init << ")";
	print_cont(c2, "II", ss.str());
	print_cont(c3, "III", "III(II)");
	c1 = c2;
	print_cont(c1, "I", "I = II");
}

template <class Cont, class T>
void	test_iter(T *init, size_t size_init, std::string name)
{
	Cont	c(init, init + size_init);

	std::cout << "   \033[1;33m" << name << "\n\033[0m";
	print_cont(c, "I", "I()");
	print_cont(c, "I", "Regular");
	rprint_cont(c, "I", "Reverse");
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

template <class Cont, class T>
void	test_mod(T *init, size_t size_init, std::string name)
{
	std::stringstream				ss;
	Cont							c1;
	Cont							c2(init, init + size_init);
	typename	Cont::iterator		it1;
	typename	Cont::iterator		it2;
	
	std::cout << "   \033[1;33m" << name << "\033[0m\n";
	print_cont(c1, "I", "I()");
	c1.insert(init[2]);
	c1.insert(init[5]);
	ss << "I.insert(" << init[2].first << ") & " << "I.insert(" << init[5].first << ")";
	print_cont(c1, "I", ss.str());
	c1.insert(init + 1, init + size_init);
	ss.str("");
	ss << "I.insert(init + 1, init + " << size_init << ")";
	print_cont(c1, "I", ss.str());
	c1.erase(c1.begin());
	print_cont(c1, "I", "I.erase(I.begin())");
	c1.erase(init[5].first);
	ss.str("");
	ss << "I.erase(" << init[5].first << ")";
	print_cont(c1, "I", ss.str());
	it1 = c1.begin();
	it2 = c1.end();
	++it1;
	--it2;
	c1.erase(it1, it2);
	print_cont(c1, "I", "I.erase(begin() + 1, end() - 1)");
	ss.str("");
	ss << "II(init, init + " << size_init << ")";
	print_cont(c2, "II", ss.str());
	c1.swap(c2);
	print_cont(c1, "I", "I.swap(II)");
	print_cont(c2, "II", "");
	c1.clear();
	print_cont(c1, "I", "I.clear()");
}

template <class Cont, class T>
void	test_obs(T *init, size_t size_init, std::string name)
{
	Cont	c(init, init + size_init);

	std::cout << "   \033[1;33m" << name << "\n\033[0m";
	std::cout
		<< "\033[1;36m      I.key_comp()(" << init[0].first	<< ", " << init[1].first
		<< ")\033[0m\n         result : "
		<< (c.key_comp()(init[0].first, init[1].first) ? true : false) << "\n\033[0m";
	std::cout
		<< "\033[1;36m      I.key_comp()(" << init[1].first	<< ", " << init[0].first
		<< ")\033[0m\n         result : "
		<< (c.key_comp()(init[1].first, init[0].first) ? true : false) << "\n\033[0m";
	std::cout
		<< "\033[1;36m      I.value_comp()(" << init[0].first << ":" << init[0].second
		<< ", " << init[1].first << ":" << init[1].second
		<< ")\033[0m\n         result : "
		<< (c.value_comp()(init[0], init[1]) ? true : false) << "\n\033[0m";
	std::cout
		<< "\033[1;36m      I.value_comp()(" << init[1].first << ":" << init[1].second
		<< ", " << init[0].first << ":" << init[0].second
		<< ")\033[0m\n         result : "
		<< (c.value_comp()(init[1], init[0]) ? true : false) << "\n\033[0m";
}

template <class Cont, class T>
void	test_op(T *init, std::string name)
{
	std::stringstream							ss;
	Cont										c(init + 2, init + 6);
	typename Cont::iterator						it;
	ft::Pair<typename Cont::iterator,
		typename Cont::iterator>				p_ret;
	size_t										ret;

	std::cout << "   \033[1;33m" << name << "\033[0m\n";
	c.insert(init + 2, init + 6);
	print_cont(c, "I", "I(init + 2, init + 6) & I.insert(init + 2, init + 6)");
	it = c.find(init[2].first);
	std::cout << "\033[1;36m      I.find(" << init[2].first
		<< ")\033[0m\n         result : " << it->first << ":"
		<< it->second << "\n\033[0m";
	ret = c.count(init[4].first);
	std::cout << "\033[1;36m      I.count(" << init[4].first
		<< ")\033[0m\n         result : " << ret << "\n\033[0m";
	ret = c.count(init[0].first);
	std::cout << "\033[1;36m      I.count(" << init[0].first
		<< ")\033[0m\n         result : " << ret << "\n\033[0m";
	it = c.lower_bound(init[2].first);
	std::cout << "\033[1;36m      I.lower_bound(" << init[2].first
		<< ")\033[0m\n         result : " << it->first << ":"
		<< it->second << "\n\033[0m";
	it = c.upper_bound(init[2].first);
	std::cout << "\033[1;36m      I.upper_bound(" << init[2].first
		<< ")\033[0m\n         result : " << it->first << ":"
		<< it->second << "\n\033[0m";
	p_ret = c.equal_range(init[2].first);
	std::cout << "\033[1;36m      I.equal_range(" << init[2].first
		<< ")\033[0m\n         result : [ " << p_ret.first->first << ":"
		<< p_ret.first->second << ", " << p_ret.second->first << ":"
		<< p_ret.second->second << " ]\n\033[0m";
}

}

#endif	//TEST_MULTIMAP_HPP
