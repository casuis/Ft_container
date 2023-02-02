/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_map.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimon <asimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 12:14:31 by asimon            #+#    #+#             */
/*   Updated: 2023/02/02 18:16:32 by asimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ftnspace.hpp>
#include <iostream>
#include <map>
#define _pair ft::pair

// int main(void) {

// 	std::cout << std::endl << YELLOW << "##########MAP##########" << RESET << std::endl << std::endl;
// 	{
// 		NAMESPACE::map<int, int>			map_tmp;
// 		NAMESPACE::map<int, int>			map_tmp2;
		
		
// 		for (int i = 1; i < 10; i++) {
// 			map_tmp[i] = i * 2;
// 		}
// 		map_tmp2[10] = -40;
// 		map_tmp2[20] = -40;
		
// 		NAMESPACE::map<int, int>::const_iterator		it = map_tmp.begin();
// 		NAMESPACE::map<int, int>::const_iterator		ite = map_tmp.end();
		

// 		for (; it != ite; ++it){
// 			std::cout << "value : [" << it->first << "]" << std::endl;
// 		}
		
// 		// map_tmp.insert(map_tmp2.begin(), map_tmp2.end());
// 		// std::cout << "size : [" << map_tmp2.size() << "]" << std::endl;
// 		std::cout << "size : [" << map_tmp.size() << "]" << std::endl;

// 	}

// 	return (0);
// }
#include <list>

template <typename T>
std::string	printPair(const T &iterator, bool nl = true, std::ostream &o = std::cout)
{
	o << "key: " << iterator->first << " | value: " << iterator->second;
	if (nl)
		o << std::endl;
	return ("");
}

template <typename T_MAP>
void	printSize(T_MAP const &mp, bool print_content = 1)
{
	std::cout << "size: " << mp.size() << std::endl;
	std::cout << "max_size: " << mp.max_size() << std::endl;
	if (print_content)
	{
		typename T_MAP::const_iterator it = mp.begin(), ite = mp.end();
		std::cout << std::endl << "Content is:" << std::endl;
		for (; it != ite; ++it)
			std::cout << "- " << printPair(it, false) << std::endl;
	}
	std::cout << "###############################################" << std::endl;
}

template <typename T1, typename T2>
void	printReverse(ft::map<T1, T2> &mp)
{
	typename ft::map<T1, T2>::iterator it = mp.end(), ite = mp.begin();

	std::cout << "printReverse:" << std::endl;
	while (it != ite) {
		it--;
		std::cout << "-> " << printPair(it, false) << std::endl;
	}
	std::cout << "_______________________________________________" << std::endl;
}

#define T1 int
#define T2 std::string
typedef _pair<const T1, T2> T3;

static int iter = 0;

template <typename MAP, typename U>
void	ft_erase(MAP &mp, U param)
{
	std::cout << "\t-- [" << iter++ << "] --" << std::endl;
	mp.erase(param);
	printSize(mp);
}

template <typename MAP, typename U, typename V>
void	ft_erase(MAP &mp, U param, V param2)
{
	std::cout << "\t-- [" << iter++ << "] --" << std::endl;
	mp.erase(param, param2);
	printSize(mp);
}

int		main(void)
{

	std::list<T3> lst;
	unsigned int lst_size = 10;
	for (unsigned int i = 0; i < lst_size; ++i)
		lst.push_back(T3(i, std::string((lst_size - i), i + 65)));
	ft::map<T1, T2> mp(lst.begin(), lst.end());
	printSize(mp);
	std::cout << "=== START TEST ===" << std::endl;
	ft_erase(mp, ++mp.begin());

	// ft_erase(mp, mp.begin());
	// ft_erase(mp, --mp.end());

	// ft_erase(mp, mp.begin(), ++(++(++mp.begin())));
	// ft_erase(mp, --(--(--mp.end())), --mp.end());

	// mp[10] = "Hello";
	// mp[11] = "Hi there";
	// printSize(mp);
	// ft_erase(mp, --(--(--mp.end())), mp.end());

	// mp[12] = "ONE";
	// mp[13] = "TWO";
	// mp[14] = "THREE";
	// mp[15] = "FOUR";
	// printSize(mp);
	// ft_erase(mp, mp.begin(), mp.end());

	return (0);
}
