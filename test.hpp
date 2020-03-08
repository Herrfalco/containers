/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcadet <cadet.florian@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 17:00:58 by fcadet            #+#    #+#             */
/*   Updated: 2020/03/08 20:11:39 by fcadet           ###   ########.fr       */
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

	if (msg.size())
	{
		std::cout << "      ";
		for (int i = 0; i < (int)msg.size(); ++i)
			std::cout << "\033[1;36m" << msg[i];
		std::cout << std::endl;
	}
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
void	test_access(T *init, size_t size_init, std::string name)
{
	Cont	c(init, init + size_init);
	
	std::cout << "   \033[1;33m" << name << "\033[0m\n";
	print_cont(c, "I", "I()");
	std::cout << "\033[1;36m      I.front()\033[0m\n         result : "
		<< c.front() << "\n\033[0m";
	std::cout << "\033[1;36m      I.back()\033[0m\n         result : "
		<< c.back() << "\n\033[0m";
}

template <class Cont, class T>
void	test_mod(T *init, size_t size_init, T def, size_t size_def, std::string name)
{
	std::stringstream	ss;
	Cont				c1;
	Cont				c2(init, init + size_init);
	
	std::cout << "   \033[1;33m" << name << "\033[0m\n";
	print_cont(c1, "I", "I()");
	c1.assign(size_def, def);
	ss << "I.assign(" << size_def << ", " << def << ")";
	print_cont(c1, "I", ss.str());
	c1.assign(init, init + size_init);
	ss.str("");
	ss << "I.assign(init, init + " << size_init << ")";
	print_cont(c1, "I", ss.str());
	c1.push_front(def);
	ss.str("");
	ss << "I.push_front(" << def << ")";
	print_cont(c1, "I", ss.str());
	c1.pop_front();
	print_cont(c1, "I", "I.pop_front()");
	c1.push_back(def);
	ss.str("");
	ss << "I.push_back(" << def << ")";
	print_cont(c1, "I", ss.str());
	c1.pop_back();
	print_cont(c1, "I", "I.pop_back()");
	c1.insert(c1.end(), def);
	ss.str("");
	ss << "I.insert(I.end(), " << def << ")";
	print_cont(c1, "I", ss.str());
	c1.insert(c1.begin(), (size_t)3, def);
	ss.str("");
	ss << "I.insert(I.begin(), 3, " << def << ")";
	print_cont(c1, "I", ss.str());
	c1.insert(c1.begin(), init, init + 3);
	ss.str("");
	ss << "I.insert(I.begin(), init, init + 3)";
	print_cont(c1, "I", ss.str());
	c1.erase(c1.begin());
	print_cont(c1, "I", "I.erase(c.begin())");
	c1.erase(c1.begin(), c1.end());
	print_cont(c1, "I", "I.erase(c.begin(), c.end())");
	print_cont(c2, "II", "II(init, init + size_init)");
 	c1.swap(c2);
	print_cont(c1, "I", "I.swap(II)");
	print_cont(c2, "II", "");
	c1.resize(5, def);
	print_cont(c1, "I", "I.resize(5)");
	c2.resize(5, def);
	print_cont(c2, "II", "II.resize(5)");
	c1.clear();
	print_cont(c1, "I", "I.clear()");
}

template <class T>
bool	one_on_two(const T &elem)
{
	static bool		odd = true;

	(void)elem;
	if (odd)
		return ((odd = false));
	else
		return ((odd = true));
}

template <class T>
bool	equal(const T &a, const T &b)
{
	return (a == b);
}

template <class T>
bool	less(const T &a, const T &b)
{
	return (a < b);
}

template <class Cont, class T>
void	test_op(T *init, size_t size_init, T def, size_t size_def, std::string name)
{
	std::stringstream	ss;
	Cont				c1(size_def, def);
	Cont				c2(init, init + size_init);

	std::cout << "   \033[1;33m" << name << "\033[0m\n";
	ss << "I(" << size_def << ", " << def << ")";
	print_cont(c1, "I", ss.str());
	ss.str("");
	ss << "II(init, init + " << size_init << ")";
	print_cont(c2, "II", ss.str());
	c1.splice(c1.end(), c2);
	print_cont(c1, "I", "I.splice(I.end(), II)");
	print_cont(c2, "II", "");
	c2.splice(c2.begin(), c1, c1.begin());
	print_cont(c1, "I", "II.splice(II.begin(), I, I.begin())");
	print_cont(c2, "II", "");
	c2.splice(c2.begin(), c1, c1.begin(), c1.end());
	print_cont(c1, "I", "II.splice(II.begin(), I, I.begin(), I.end())");
	print_cont(c2, "II", "");
	c2.remove(def);
	ss.str("");
	ss << "II.remove(" << def << ")";
	print_cont(c2, "II", ss.str());
	c2.remove_if(one_on_two<T>);
	print_cont(c2, "II", "II.remove_if(one_on_two)");
	c2.insert(c2.begin(), (size_t)3, def);
	c2.insert(c2.end(), (size_t)3, def);
	ss.str("");
	ss << "II.insert(II.begin(), 3, " << def << ") & II.insert(II.end(), 3, "
		<< def << ")";
	print_cont(c2, "II", ss.str());
	c2.unique();
	print_cont(c2, "II", "II.unique()");
	c2.insert(c2.begin(), (size_t)3, def);
	c2.insert(c2.end(), (size_t)2, def);
	ss.str("");
	ss << "II.insert(II.begin(), 3, " << def << ") & II.insert(II.end(), 2, "
		<< def << ")";
	print_cont(c2, "II", ss.str());
	c2.unique(equal<T>);
	print_cont(c2, "II", "II.unique(equal)");
	ss.str("");
	c1.assign(init, init + size_init - 2);
	c2.assign(init, init + size_init - 2);
	print_cont(c1, "I",
		"I.assign(init, init + size_init - 2) & II.assign(init, init + size_init - 2)");
	print_cont(c2, "II", "");
	c1.merge(c2);
	print_cont(c1, "I", "I.merge(II)");
	print_cont(c2, "II", "");
	c1.unique();
	c2.assign(init, init + size_init - 2);
	print_cont(c1, "I",
		"I.unique() & II.assign(init, init + size_init - 2)");
	print_cont(c2, "II", "");
	c1.merge(c2, less<T>);
	print_cont(c1, "I", "I.merge(II, less)");
	print_cont(c2, "II", "");
	c1.assign(init, init + size_init);
	c1.remove_if(one_on_two<T>);
	c2.assign(init, init + size_init);
	c2.remove_if(one_on_two<T>);
	c1.splice(c1.end(), c2, c2.begin(), c2.end());
	print_cont(c1, "I", "I.assign(init, init + size_init) & I.remove_if(one_on_two)\n      & II.assign(init, init + size_init) & II.remove_if(one_on_two)\n      & I.splice(I.end(), II, II.begin(), II.end())");
	c2.assign(c1.begin(), c1.end());
	print_cont(c2, "II", "II.assign(I.begin(), I.end()");
	c1.sort();
	print_cont(c1, "I", "I.sort()");
	c2.sort(less<T>);
	print_cont(c1, "II", "II.sort(less)");
	c1.reverse();
	print_cont(c1, "I", "I.reverse()");
}

template <class Cont, class T>
void	test_nmem(T *init, size_t size_init, T def, size_t size_def, std::string name)
{
	Cont				c1(size_def, def);
	Cont				c2(init, init + size_init);
	Cont				c3(c2);
	std::stringstream	ss;

	std::cout << "   \033[1;33m" << name << "\033[0m\n";
	ss << "I(" << size_def << ", " << def << ")";
	print_cont(c1, "I", ss.str());
	ss.str("");
	ss << "II(init, init + " << size_init << ")";
	print_cont(c2, "II", ss.str());
	print_cont(c3, "III", "III(II)");
	std::cout << "\033[1;36m      I == II\033[0m\n         result : "
		<< (c1 == c2 ? "true" : "false") << "\n\033[0m";
	std::cout << "\033[1;36m      II == III\033[0m\n         result : "
		<< (c2 == c3 ? "true" : "false") << "\n\033[0m";
	std::cout << "\033[1;36m      I != II\033[0m\n         result : "
		<< (c1 != c2 ? "true" : "false") << "\n\033[0m";
	std::cout << "\033[1;36m      II != III\033[0m\n         result : "
		<< (c2 != c3 ? "true" : "false") << "\n\033[0m";
	std::cout << "\033[1;36m      I < II\033[0m\n         result : "
		<< (c1 < c2 ? "true" : "false") << "\n\033[0m";
	std::cout << "\033[1;36m      II < III\033[0m\n         result : "
		<< (c2 < c3 ? "true" : "false") << "\n\033[0m";
	std::cout << "\033[1;36m      I <= II\033[0m\n         result : "
		<< (c1 <= c2 ? "true" : "false") << "\n\033[0m";
	std::cout << "\033[1;36m      II <= III\033[0m\n         result : "
		<< (c2 <= c3 ? "true" : "false") << "\n\033[0m";
	std::cout << "\033[1;36m      I > II\033[0m\n         result : "
		<< (c1 > c2 ? "true" : "false") << "\n\033[0m";
	std::cout << "\033[1;36m      II > III\033[0m\n         result : "
		<< (c2 > c3 ? "true" : "false") << "\n\033[0m";
	std::cout << "\033[1;36m      I >= II\033[0m\n         result : "
		<< (c1 >= c2 ? "true" : "false") << "\n\033[0m";
	std::cout << "\033[1;36m      II >= III\033[0m\n         result : "
		<< (c2 >= c3 ? "true" : "false") << "\n\033[0m";
	swap(c1, c2);
	print_cont(c1, "I", "swap(I, II)");
	print_cont(c2, "II", "");
}

#endif	//TEST_HPP
