/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_map.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimon <asimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 12:14:31 by asimon            #+#    #+#             */
/*   Updated: 2023/01/16 20:57:19 by asimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ftnspace.hpp>
#include <iostream>
#include <map>

int main(void) {

	std::cout << std::endl << YELLOW << "##########MAP##########" << RESET << std::endl << std::endl;
	{
		NAMESPACE::map<int, int>			map_tmp;
		
		// map_tmp[1] = 42;
		// map_tmp[0] = -42;

		NAMESPACE::map<int, int>::iterator	map_it = map_tmp.begin();

		std::cout << "value ite: [" << map_it->first << "]" << std::endl;
	}

	return (0);
}