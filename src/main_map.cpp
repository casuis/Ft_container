/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_map.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimon <asimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 12:14:31 by asimon            #+#    #+#             */
/*   Updated: 2022/12/09 11:49:02 by asimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ftnspace.hpp>
#include <iostream>
#include <map>

int main(void){

	std::cout << std::endl << YELLOW << "##########VECTOR##########" << RESET << std::endl << std::endl;
	{	
		// std::map<char *, int>		mp;
		std::map<std::string, int>			mp_2;
		std::string	test1("salut");
		std::string	test2("arthur");
		std::string	test3("cest");
		std::string	test31("c");
		std::string	test32("bieeeeeeeeen");
		std::string	test33("biee");
		std::string	test4("tonton");
	
		mp_2[test1] = 1;
		mp_2[test2] = 12;
		mp_2[test3] = 13;
		mp_2[test31] = 131;
		mp_2[test32] = 1312;
		mp_2[test33] = 1313;
		mp_2[test4] = 14;
	
		std::map<std::string, int>::iterator	it = mp_2.begin();
		std::map<std::string, int>::iterator	ite = mp_2.end();
		system("clear");
		for (; it != ite; it++){
			std::cout << "key: [" << it->first << "]" << std::endl
			<< "value: [" << it->second << "]" << std::endl << std::endl;
		}
		std::cout << std::endl << YELLOW << "*****fin de test*****" << RESET << std::endl << std::endl;
	}

	return (0);
}