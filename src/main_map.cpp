/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_map.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimon <asimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 12:14:31 by asimon            #+#    #+#             */
/*   Updated: 2023/02/21 22:02:38 by asimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ftnspace.hpp>
#include <iostream>
#include <map>

#if STD == 1
	std::string		print_nspace = "##STD";
#else
	std::string		print_nspace = "##FT";
#endif


int main(void) {

	std::cout << print_nspace << std::endl;
	std::cout << std::endl << M_YELLOW << "##########MAP##########" << M_RESET << std::endl << std::endl;
	{

		NAMESPACE::map<int, int>			map_gen;
		
		for (int i = 0; i < 11 ; i++)
			map_gen[i] = i * 2;
			
		{
			std::cout << std::endl << M_CYAN << "=> Constructors : " << M_RESET << std::endl << std::endl;

			std::cout << "=creation of map_test=" << std::endl;
			NAMESPACE::map<int, int>		map_test;

			std::cout << "print if no error occured" << std::endl << std::endl;

			map_test[0] = 42;
			std::cout << "=insert in map_test[0] element 42" << std::endl
			<< "print elem map_test[0]: " << map_test[0] << std::endl;
			
			
			NAMESPACE::map<int, int>		map_cpy(map_test);
			std::cout << std::endl << "=creation of map_copy=" << std::endl;

			std::cout << std::endl << "print elem map_cpy[0]: " << map_cpy[0] << std::endl;

			
			std::cout << std::endl << "=insert in map_cpy : [(1|2) / (2|4) / (3|6) / (4|8) / ... / (9|18)]=" << std::endl;
			for (int i = 1; i < 10 ; i++)
				map_cpy[i] = i *2;
				

			NAMESPACE::map<int, int>			map_range(map_cpy.begin(), map_cpy.end());
			std::cout << std::endl << "=creation of map_range from map_cpy begin to end=" << std::endl;

			std::cout << "map_range contain:";
			for (NAMESPACE::map<int, int>::iterator it = map_range.begin(), ite = map_range.end(); it != ite; it++)
				std::cout << " (" << it->first << "|" << it->second << ")";

			std::cout << std::endl;
			std::cout << std::endl << M_YELLOW << "*****fin de test*****" << M_RESET << std::endl << std::endl;
		}
		
		////////////////////////////////////////////////////////////////////////////////
		
		{
			std::cout << std::endl << M_CYAN << "=> iterators : " << M_RESET << std::endl << std::endl;
			
			std::cout << "print the value of begin: (" << map_gen.begin()->first << "|" << map_gen.begin()->second << ")" << std::endl; 
			
			std::cout << "map_gen contains:";
			for (NAMESPACE::map<int, int>::iterator it = map_gen.begin(), ite = map_gen.end(); it != ite; it++)
				std::cout << " (" << it->first << "|" << it->second << ")";
			std::cout << std::endl << std::endl;

			NAMESPACE::map<int, int>::const_iterator		const_it = map_gen.begin();
			std::cout << "print the value of const_iterator: (" << const_it->first << "|" << const_it->second << ")" << std::endl; 
			
			std::cout << "map_gen contains with const iter:";
			for (NAMESPACE::map<int, int>::const_iterator it = map_gen.begin(), ite = map_gen.end(); it != ite; it++)
				std::cout << " (" << it->first << "|" << it->second << ")";
			std::cout << std::endl << std::endl;

			std::cout << std::endl << M_YELLOW << "*****fin de test*****" << M_RESET << std::endl << std::endl;
		}

		////////////////////////////////////////////////////////////////////////////////
		
		{
			std::cout << std::endl << M_CYAN << "=> empty / size : " << M_RESET << std::endl << std::endl;

			std::cout << std::boolalpha << "is map_gen empty? " << map_gen.empty() << std::endl;
			std::cout << "print the size of map_gen: " << map_gen.size() << std::endl;


			std::cout << std::endl << "=Create new map" << std::endl;
			NAMESPACE::map<int, int>		new_map;
			
			std::cout << std::boolalpha << "is new_map empty? " << new_map.empty() << std::endl;
			std::cout << "print the size of new_map: " << new_map.size() << std::endl;
			
			std::cout << std::endl << M_YELLOW << "*****fin de test*****" << M_RESET << std::endl << std::endl;
		}

		////////////////////////////////////////////////////////////////////////////////
		
		{
			std::cout << std::endl << M_CYAN << "=> at / operator[] : " << M_RESET << std::endl << std::endl;
			
			NAMESPACE::map<int, int>		map_test;

			std::cout << "=insert in map_test[0] element 42" << std::endl;
			map_test[0] = 42;
			std::cout << "map.at(0): " << map_test.at(0) << std::endl;
			std::cout << "map[0]: " << map_test[0] << std::endl;
			
			std::cout << std::endl << M_YELLOW << "*****fin de test*****" << M_RESET << std::endl << std::endl;
		}

		////////////////////////////////////////////////////////////////////////////////
		
		{
			std::cout << std::endl << M_CYAN << "=> insert : " << M_RESET << std::endl << std::endl;
			
			NAMESPACE::map<int, int>		map_test;
			
			std::cout << "map_gen contains:";
			for (NAMESPACE::map<int, int>::iterator it = map_gen.begin(), ite = map_gen.end(); it != ite; it++)
				std::cout << " (" << it->first << "|" << it->second << ")";
			std::cout << std::endl << std::endl;


			std::cout << std::endl << "=insert begin of map_gen in map_test=" << std::endl;
			map_test.insert(*map_gen.begin());
			std::cout << "map_test begin contains: (" << map_test.begin()->first << "|" << map_test.begin()->second << ")" << std::endl;


			std::cout << std::endl << "=insert begin until end of map_gen in map_test=" << std::endl;
			map_test.insert(map_gen.begin(), map_gen.end());
			std::cout << "map_test contains:";
			for (NAMESPACE::map<int, int>::iterator it = map_test.begin(), ite = map_test.end(); it != ite; it++)
				std::cout << " (" << it->first << "|" << it->second << ")";
			std::cout << std::endl << std::endl;
			
			std::cout << std::endl << M_YELLOW << "*****fin de test*****" << M_RESET << std::endl << std::endl;
		}

		////////////////////////////////////////////////////////////////////////////////
		
		{
			std::cout << std::endl << M_CYAN << "=> erase : " << M_RESET << std::endl << std::endl;

			NAMESPACE::map<int, int>		map_test(map_gen.begin(), map_gen.end());
			
			std::cout << "map_test contains:";
			for (NAMESPACE::map<int, int>::iterator it = map_test.begin(), ite = map_test.end(); it != ite; it++)
				std::cout << " (" << it->first << "|" << it->second << ")";
			std::cout << std::endl << std::endl;
			
			std::cout << std::endl << "=Erase first elem of map_test=" << std::endl;
			map_test.erase(map_test.begin());
			std::cout << "map_test contains:";
			for (NAMESPACE::map<int, int>::iterator it = map_test.begin(), ite = map_test.end(); it != ite; it++)
				std::cout << " (" << it->first << "|" << it->second << ")";
			std::cout << std::endl << std::endl;
			
			std::cout << std::endl << "=Erase (3|6) elem of map_test=" << std::endl;
			map_test.erase(3);
			std::cout << "map_test contains:";
			for (NAMESPACE::map<int, int>::iterator it = map_test.begin(), ite = map_test.end(); it != ite; it++)
				std::cout << " (" << it->first << "|" << it->second << ")";
			std::cout << std::endl << std::endl;
			
			std::cout << std::endl << "=Erase all elem of map_test=" << std::endl;
			map_test.erase(map_test.begin(), map_test.end());
			std::cout << std::boolalpha << "map_test is empty? " << map_test.empty() << std::endl;
			
			
			std::cout << std::endl << M_YELLOW << "*****fin de test*****" << M_RESET << std::endl << std::endl;
		}

		////////////////////////////////////////////////////////////////////////////////
		
		{
			std::cout << std::endl << M_CYAN << "=> swap : " << M_RESET << std::endl << std::endl;

			NAMESPACE::map<std::string, int>		map_test1;
			NAMESPACE::map<std::string, int>		map_test2;

			map_test1["abc"] = 42;
			map_test1["Hello"] = 0;
			map_test1["World"] = 1;
			map_test1["!"] = 3;

			map_test2["Coucou"] = 10;
			map_test2["le"] = 44;
			map_test2["monde !"] = 55;

			std::cout << "map_test1 contains:";
			for (NAMESPACE::map<std::string, int>::iterator it = map_test1.begin(), ite = map_test1.end(); it != ite; it++)
				std::cout << " (" << it->first << "|" << it->second << ")";
			std::cout << std::endl << std::endl;
			
			std::cout << "map_test2 contains:";
			for (NAMESPACE::map<std::string, int>::iterator it = map_test2.begin(), ite = map_test2.end(); it != ite; it++)
				std::cout << " (" << it->first << "|" << it->second << ")";
			std::cout << std::endl << std::string(42, '=') << std::endl;

			swap(map_test1, map_test2);
			
			std::cout << "after swap map_test1 contains:";
			for (NAMESPACE::map<std::string, int>::iterator it = map_test1.begin(), ite = map_test1.end(); it != ite; it++)
				std::cout << " (" << it->first << "|" << it->second << ")";
			std::cout << std::endl << std::endl;
			
			std::cout << "after swap map_test2 contains:";
			for (NAMESPACE::map<std::string, int>::iterator it = map_test2.begin(), ite = map_test2.end(); it != ite; it++)
				std::cout << " (" << it->first << "|" << it->second << ")";
			std::cout << std::endl << std::string(42, '=') << std::endl;
			
			std::cout << std::endl << M_YELLOW << "*****fin de test*****" << M_RESET << std::endl << std::endl;
		}

		////////////////////////////////////////////////////////////////////////////////
		
		{
			std::cout << std::endl << M_CYAN << "=> clear : " << M_RESET << std::endl << std::endl;

			NAMESPACE::map<int, int>		map_test(map_gen);

			std::cout << std::boolalpha << "map_test is empty? " << map_test.empty() << std::endl;

			std::cout << std::endl << "=clear map_test=" << std::endl;
			map_test.clear();
			std::cout << std::boolalpha << "map_test is empty? " << map_test.empty() << std::endl;
			
			std::cout << std::endl << M_YELLOW << "*****fin de test*****" << M_RESET << std::endl << std::endl;
		}

		////////////////////////////////////////////////////////////////////////////////
		
		{
			std::cout << std::endl << M_CYAN << "=> find : " << M_RESET << std::endl << std::endl;

			NAMESPACE::map<int, int>			map_test(map_gen);
			NAMESPACE::map<int, int>::iterator	ret = map_test.find(8); // should find it
			
			std::cout << std::endl << "=try to find 8=" << std::endl;
			if (ret == map_test.end())
				std::cout << "no occurence found" << std::endl;
			else
				std::cout << "found :" << ret->first << std::endl; 

			std::cout << std::endl << "=try to find 9999=" << std::endl;
			ret = map_test.find(9999); // sould'nt find it
			if (ret == map_test.end())
				std::cout << "no occurence found" << std::endl;
			else
				std::cout << "found :" << ret->first << std::endl; 
			
			
			std::cout << std::endl << M_YELLOW << "*****fin de test*****" << M_RESET << std::endl << std::endl;
		}

		////////////////////////////////////////////////////////////////////////////////
		
		{
			std::cout << std::endl << M_CYAN << "=> count : " << M_RESET << std::endl << std::endl;
			NAMESPACE::map<int, int>			map_test(map_gen);

				std::cout << std::endl << "=try count on 8=" << std::endl;
				std::cout << "count return: " << map_test.count(8) << std::endl;
				
				std::cout << std::endl << "=try count on 56=" << std::endl;
				std::cout << "count return: " << map_test.count(56) << std::endl;

			std::cout << std::endl << M_YELLOW << "*****fin de test*****" << M_RESET << std::endl << std::endl;
		}

		////////////////////////////////////////////////////////////////////////////////
		
		{
			std::cout << std::endl << M_CYAN << "=> lower_bound : " << M_RESET << std::endl << std::endl;
			
			
			std::cout << std::endl << "=try lower_bound on 3=" << std::endl;
			std::cout << "lower_bound return: " << map_gen.lower_bound(3)->first;
			
			std::cout << std::endl << "=try lower_bound on 10=" << std::endl;
			std::cout << "lower_bound return: " << map_gen.lower_bound(3)->first;
			
			std::cout << std::endl << "=try lower_bound on 100=" << std::endl;
			std::cout << "lower_bound return: " << map_gen.lower_bound(3)->first;
			
			
			std::cout << std::endl << M_YELLOW << "*****fin de test*****" << M_RESET << std::endl << std::endl;
		}

		////////////////////////////////////////////////////////////////////////////////
		
		{
			std::cout << std::endl << M_CYAN << "=> upper_bound : " << M_RESET << std::endl << std::endl;
			
			
			std::cout << std::endl << "=try upper_bound on 3=" << std::endl;
			std::cout << "upper_bound return: " << map_gen.upper_bound(3)->first;
			
			std::cout << std::endl << "=try upper_bound on 10=" << std::endl;
			std::cout << "upper_bound return: " << map_gen.upper_bound(3)->first;
			
			std::cout << std::endl << "=try upper_bound on 100=" << std::endl;
			std::cout << "upper_bound return: " << map_gen.upper_bound(3)->first;
			
			
			std::cout << std::endl << M_YELLOW << "*****fin de test*****" << M_RESET << std::endl << std::endl;
		}

		////////////////////////////////////////////////////////////////////////////////
		
		{
			std::cout << std::endl << M_CYAN << "=> equal_range : " << M_RESET << std::endl << std::endl;
			
			std::cout << std::endl << "=try equal_range on 3=" << std::endl;
			std::cout << "equal_range return: " << (map_gen.equal_range(3).first)->first;
			
			std::cout << std::endl << "=try equal_range on 10=" << std::endl;
			std::cout << "equal_range return: " << (map_gen.equal_range(3).first)->first;
			
			std::cout << std::endl << "=try equal_range on 100=" << std::endl;
			std::cout << "equal_range return: " << (map_gen.equal_range(3).first)->first;
			
			std::cout << std::endl << M_YELLOW << "*****fin de test*****" << M_RESET << std::endl << std::endl;
		}

		////////////////////////////////////////////////////////////////////////////////
	}

	return (0);
}
