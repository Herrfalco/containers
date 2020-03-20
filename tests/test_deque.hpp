/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_deque.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcadet <cadet.florian@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 17:00:58 by fcadet            #+#    #+#             */
/*   Updated: 2020/03/20 18:13:54 by fcadet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_DEQUE_HPP
# define TEST_DEQUE_HPP

# include "../Deque/Deque.hpp"
# include "test_common.hpp"

namespace	ndeque
{

void	test_deque(void);

/*
template <class Cont, class T>
void	test_capacity(T def, size_t size_def, std::string name)
{
	Cont					c1;
	std::stringstream		ss;

	std::cout << "   \033[1;33m" << name << "\033[0m\n";
	print_cont(c1, "I", "I()");
	std::cout << "\033[1;36m      I.size()\033[0m\n         result : "
		<< c1.size() << "\n\033[0m";
	std::cout << "\033[1;36m      I.max_size()\033[0m\n         result : "
		<< c1.max_size() << "\n\033[0m";
	std::cout << "\033[1;36m      I.empty()\033[0m\n         result : "
		<< (c1.empty() ? "true" : "false") << "\n\033[0m";
	c1.resize(size_def, def);
	ss << "resize(" << size_def << ")";
	print_cont(c1, "I", ss.str());
	std::cout << "\033[1;36m      I.capacity()\033[0m\n         result : "
		<< c1.capacity() << "\n\033[0m";
	std::cout << "\033[1;36m      I.empty()\033[0m\n         result : "
		<< (c1.empty() ? "true" : "false") << "\n\033[0m";
	c1.resize(5);
	print_cont(c1, "I", "resize(5)");
	std::cout << "\033[1;36m      I.capacity()\033[0m\n         result : "
		<< c1.capacity() << "\n\033[0m";
	c1.reserve(11);
	std::cout << "\033[1;36m      I.reserve(11) & I.capacity()\033[0m\
\n         result : "
		<< c1.capacity() << "\n\033[0m";
	c1.reserve(17);
	std::cout << "\033[1;36m      I.reserve(17) & I.capacity()\033[0m\
\n         result : "
		<< c1.capacity() << "\n\033[0m";
}

template <class Cont, class T>
void	test_access(T *init, size_t size_init, std::string name)
{
	Cont	c(init, init + size_init);
	
	std::cout << "   \033[1;33m" << name << "\033[0m\n";
	print_cont(c, "I", "I()");
	std::cout << "\033[1;36m      I[4]\033[0m\n         result : "
		<< c[4] << "\n\033[0m";
	std::cout << "\033[1;36m      I.at(4)\033[0m\n         result : "
		<< c.at(4) << "\n\033[0m";
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
	c1.insert(c1.begin() + 2, (size_t)3, def);
	ss.str("");
	ss << "I.insert(I.begin() + 2, 3, " << def << ")";
	print_cont(c1, "I", ss.str());
	c1.insert(c1.begin(), init, init + 3);
	ss.str("");
	ss << "I.insert(I.begin(), init, init + 3)";
	print_cont(c1, "I", ss.str());
	c1.erase(c1.begin());
	print_cont(c1, "I", "I.erase(c.begin())");
	c1.erase(c1.begin() + 2, c1.end() - 2);
	print_cont(c1, "I", "I.erase(c.begin() + 2, c.end() - 2)");
	c1.erase(c1.begin(), c1.end());
	print_cont(c1, "I", "I.erase(c.begin(), c.end())");
	print_cont(c2, "II", "II(init, init + size_init)");
 	c1.swap(c2);
	print_cont(c1, "I", "I.swap(II)");
	print_cont(c2, "II", "");
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
void	test_nmem(T *init, size_t size_init, T def, size_t size_def, std::string name)
{
	Cont				c1(size_def, def);
	Cont				c2(init, init + size_init);
	Cont				c3(c2);
	Cont				c4(c2);
	std::stringstream	ss;

	std::cout << "   \033[1;33m" << name << "\033[0m\n";
	ss << "I(" << size_def << ", " << def << ")";
	print_cont(c1, "I", ss.str());
	ss.str("");
	ss << "II(init, init + " << size_init << ")";
	print_cont(c2, "II", ss.str());
	print_cont(c3, "III", "III(II)");
	c4.push_back(def);
	ss.str("");
	ss << "IV(II) & IV.push_back(" << def << ")";
	print_cont(c4, "IV", ss.str());
	std::cout << "\033[1;36m      I == II\033[0m\n         result : "
		<< (c1 == c2 ? "true" : "false") << "\n\033[0m";
	std::cout << "\033[1;36m      II == III\033[0m\n         result : "
		<< (c2 == c3 ? "true" : "false") << "\n\033[0m";
	std::cout << "\033[1;36m      III == IV\033[0m\n         result : "
		<< (c3 == c4 ? "true" : "false") << "\n\033[0m";
	std::cout << "\033[1;36m      I != II\033[0m\n         result : "
		<< (c1 != c2 ? "true" : "false") << "\n\033[0m";
	std::cout << "\033[1;36m      II != III\033[0m\n         result : "
		<< (c2 != c3 ? "true" : "false") << "\n\033[0m";
	std::cout << "\033[1;36m      III != IV\033[0m\n         result : "
		<< (c3 != c4 ? "true" : "false") << "\n\033[0m";
	std::cout << "\033[1;36m      I < II\033[0m\n         result : "
		<< (c1 < c2 ? "true" : "false") << "\n\033[0m";
	std::cout << "\033[1;36m      II < III\033[0m\n         result : "
		<< (c2 < c3 ? "true" : "false") << "\n\033[0m";
	std::cout << "\033[1;36m      III < IV\033[0m\n         result : "
		<< (c3 < c4 ? "true" : "false") << "\n\033[0m";
	std::cout << "\033[1;36m      I <= II\033[0m\n         result : "
		<< (c1 <= c2 ? "true" : "false") << "\n\033[0m";
	std::cout << "\033[1;36m      II <= III\033[0m\n         result : "
		<< (c2 <= c3 ? "true" : "false") << "\n\033[0m";
	std::cout << "\033[1;36m      III <= IV\033[0m\n         result : "
		<< (c3 <= c4 ? "true" : "false") << "\n\033[0m";
	std::cout << "\033[1;36m      I > II\033[0m\n         result : "
		<< (c1 > c2 ? "true" : "false") << "\n\033[0m";
	std::cout << "\033[1;36m      II > III\033[0m\n         result : "
		<< (c2 > c3 ? "true" : "false") << "\n\033[0m";
	std::cout << "\033[1;36m      III > IV\033[0m\n         result : "
		<< (c3 > c4 ? "true" : "false") << "\n\033[0m";
	std::cout << "\033[1;36m      I >= II\033[0m\n         result : "
		<< (c1 >= c2 ? "true" : "false") << "\n\033[0m";
	std::cout << "\033[1;36m      II >= III\033[0m\n         result : "
		<< (c2 >= c3 ? "true" : "false") << "\n\033[0m";
	std::cout << "\033[1;36m      III >= IV\033[0m\n         result : "
		<< (c3 >= c4 ? "true" : "false") << "\n\033[0m";
	swap(c1, c4);
	print_cont(c1, "I", "swap(I, IV)");
	print_cont(c4, "IV", "");
}
*/

}

#endif	//TEST_DEQUE_HPP
