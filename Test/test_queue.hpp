/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_queue.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcadet <cadet.florian@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 17:00:58 by fcadet            #+#    #+#             */
/*   Updated: 2020/03/23 15:54:47 by fcadet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_QUEUE_HPP
# define TEST_QUEUE_HPP

# include "../Queue/Queue.hpp"
# include "test_common.hpp"

namespace	nqueue
{

void	test_queue(void);

template <class Cont, class T>
static void		print_queue(const Cont &s, std::string msg)
{
	std::cout << "\033[1;36m      " << msg << "\033[0m\n         size : "
		<< s.size() << " | front : ";
	(s.size() ? std::cout << s.front() : std::cout << "none");
	std::cout << " | back : ";
	(s.size() ? std::cout << s.back() : std::cout << "none");
	std::cout << "\n\033[0m";
}

template <class Cont, class T>
void	test_memb(T *init, std::string name)
{
	Cont					c1;
	std::stringstream		ss;

	std::cout << "   \033[1;33m" << name << "\033[0m\n";
	print_queue<Cont, T>(c1, "I()");
	std::cout << "\033[1;36m      I.empty()\033[0m\n         result : "
		<< (c1.empty() ? "true" : "false") << "\n\033[0m";
	c1.push(init[0]);
	ss << "I.push(" << init[0] << ")";
	print_queue<Cont, T>(c1, ss.str());
	std::cout << "\033[1;36m      I.empty()\033[0m\n         result : "
		<< (c1.empty() ? "true" : "false") << "\n\033[0m";
	c1.push(init[1]);
	ss.str("");
	ss << "I.push(" << init[1] << ")";
	print_queue<Cont, T>(c1, ss.str());
	c1.pop();
	print_queue<Cont, T>(c1, "I.pop()");
	c1.pop();
	print_queue<Cont, T>(c1, "I.pop()");
}

template <class Cont, class T>
void	test_nmem(T *init, std::string name)
{
	Cont				c1;
	Cont				c2;
	Cont				c3;
	Cont				c4;
	std::stringstream	ss;

	std::cout << "   \033[1;33m" << name << "\033[0m\n";
	print_queue<Cont, T>(c1, "I()");
	for (int i = 0; i < 4; ++i)
		c2.push(init[i]);
	ss << "II() & II.push(" << init[0] << "~" << init[3] << ")";
	print_queue<Cont, T>(c2, ss.str());
	for (int i = 4; i < 8; ++i)
		c3.push(init[i]);
	ss.str("");
	ss << "III() & III.push(" << init[4] << "~" << init[7] << ")";
	print_queue<Cont, T>(c3, ss.str());
	for (int i = 4; i < 8; ++i)
		c4.push(init[i]);
	ss.str("");
	ss << "IV() & IV.push(" << init[4] << "~" << init[7] << ")";
	print_queue<Cont, T>(c4, ss.str());
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
}

}

#endif	//TEST_QUEUE_HPP
