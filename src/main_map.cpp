/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_map.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimon <asimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 12:14:31 by asimon            #+#    #+#             */
/*   Updated: 2023/01/12 14:00:22 by asimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ftnspace.hpp>
#include <iostream>
#include <map>

int main(void) {

	std::cout << std::endl << YELLOW << "##########MAP##########" << RESET << std::endl << std::endl;
	{
		// ft::map<int, int>		map_cont;
		std::map<int, int>			map_cont_tmp;
		std::vector<int> 			vec_tmp;

		map_cont_tmp[0] = 1;
		vec_tmp.push_back(1);
		
		std::map<int, int>::iterator it = map_cont_tmp.begin();
		std::vector<int>::iterator it2= vec_tmp.begin();

		it[1] = 42;
		std::cout << "value : [" << it[1] << "]" << std::endl;
	}

	return (0);
}