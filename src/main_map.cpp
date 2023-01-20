/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_map.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimon <asimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 12:14:31 by asimon            #+#    #+#             */
/*   Updated: 2023/01/20 17:43:55 by asimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ftnspace.hpp>
#include <iostream>
#include <map>

int main(void) {

	std::cout << std::endl << YELLOW << "##########MAP##########" << RESET << std::endl << std::endl;
	{
		std::map<int, int>			map_tmp;
		std::map<int, int>			map_tmp2;
		
		map_tmp[1] = -42;
		map_tmp[0] = 10;
		map_tmp[2] = 420;

		map_tmp2[1] = -40;
		
		// NAMESPACE::map<int, int>::iterator		it = map_tmp.begin();
		std::map<int, int>::iterator		ite = map_tmp.end();
		
		// NAMESPACE::map<int, int>::iterator		it_comp = it++;
		// NAMESPACE::map<int, int>::iterator		it_comp2 = map_tmp2.begin();
		

		// NAMESPACE::map<int, int*>::iterator	map_it = map_tmp.begin();
		// for (; it != ite; it++) {
		// }
		ite++;
		std::cout << "value of it :[" << ite->second << "]" << std::endl;

	}

	return (0);
}