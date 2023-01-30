/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_map.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimon <asimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 12:14:31 by asimon            #+#    #+#             */
/*   Updated: 2023/01/25 11:38:51 by asimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ftnspace.hpp>
#include <iostream>
#include <map>

int main(void) {

	std::cout << std::endl << YELLOW << "##########MAP##########" << RESET << std::endl << std::endl;
	{
		NAMESPACE::map<int, int>			map_tmp;
		NAMESPACE::map<int, int>			map_tmp2;
		
		
		map_tmp[0] = 10;
		map_tmp[1] = -42;
		map_tmp[2] = 420;

		map_tmp2[10] = -40;
		map_tmp2[20] = -40;
		
		NAMESPACE::map<int, int>::iterator		it = map_tmp.begin();
		NAMESPACE::map<int, int>::iterator		ite = map_tmp.end();
		

		for (; it != ite; it++){
			std::cout << "value : [" << it->second << "]" << std::endl;
		}
		
		map_tmp.insert(map_tmp2.begin(), map_tmp2.end());
		// std::cout << "size : [" << map_tmp2.size() << "]" << std::endl;
		std::cout << "size : [" << map_tmp.size() << "]" << std::endl;

	}

	return (0);
}