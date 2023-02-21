/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_set.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimon <asimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 12:14:31 by asimon            #+#    #+#             */
/*   Updated: 2023/02/21 22:45:43 by asimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ftnspace.hpp>
#include <iostream>

#if STD == 1
	std::string		print_nspace = "##STD";
#else
	std::string		print_nspace = "##FT";
#endif


int main(void) {

	std::cout << print_nspace << std::endl;
	std::cout << std::endl << M_YELLOW << "##########SET##########" << M_RESET << std::endl << std::endl;
	{

		NAMESPACE::set<int>			set_gen;
		
		for (int i = 0; i < 11 ; i++)
			set_gen.insert(i * 2);
			
		{
			std::cout << std::endl << M_CYAN << "=> Constructors : " << M_RESET << std::endl << std::endl;

			std::cout << "=creation of set_test=" << std::endl;
			NAMESPACE::set<int>		set_test;

			std::cout << "print if no error occured" << std::endl << std::endl;

			set_test.insert(42);
			std::cout << "=insert in set_test element 42" << std::endl
			<< "print elem set_test begin: " << *set_test.begin() << std::endl;
			
			
			NAMESPACE::set<int>		set_cpy(set_test);
			std::cout << std::endl << "=creation of set_copy=" << std::endl;

			std::cout << std::endl << "print elem set_cpy[0]: " << *set_cpy.begin() << std::endl;

			
			std::cout << std::endl << "=insert in set_cpy : [(1|2) / (2|4) / (3|6) / (4|8) / ... / (9|18)]=" << std::endl;
			for (int i = 1; i < 10 ; i++)
				set_cpy.insert(i * 2);
				

			NAMESPACE::set<int>			set_range(set_cpy.begin(), set_cpy.end());
			std::cout << std::endl << "=creation of set_range from set_cpy begin to end=" << std::endl;

			std::cout << "set_range contain:";
			for (NAMESPACE::set<int>::iterator it = set_range.begin(), ite = set_range.end(); it != ite; it++)
				std::cout << " (" << *it << ")";

			std::cout << std::endl;
			std::cout << std::endl << M_YELLOW << "*****fin de test*****" << M_RESET << std::endl << std::endl;
		}
		
		////////////////////////////////////////////////////////////////////////////////
		
		{
			std::cout << std::endl << M_CYAN << "=> iterators : " << M_RESET << std::endl << std::endl;
			
			std::cout << "print the value of begin: (" << *set_gen.begin() << "|" << *set_gen.begin() << ")" << std::endl; 
			
			std::cout << "set_gen contains:";
			for (NAMESPACE::set<int>::iterator it = set_gen.begin(), ite = set_gen.end(); it != ite; it++)
				std::cout << " (" << *it << ")";
			std::cout << std::endl << std::endl;

			NAMESPACE::set<int>::const_iterator		const_it = set_gen.begin();
			std::cout << "print the value of const_iterator: (" << *const_it << "|" << *const_it << ")" << std::endl; 
			
			std::cout << "set_gen contains with const iter:";
			for (NAMESPACE::set<int>::const_iterator it = set_gen.begin(), ite = set_gen.end(); it != ite; it++)
				std::cout << " (" << *it << ")";
			std::cout << std::endl << std::endl;

			std::cout << std::endl << M_YELLOW << "*****fin de test*****" << M_RESET << std::endl << std::endl;
		}

		////////////////////////////////////////////////////////////////////////////////
		
		{
			std::cout << std::endl << M_CYAN << "=> empty / size : " << M_RESET << std::endl << std::endl;

			std::cout << std::boolalpha << "is set_gen empty? " << set_gen.empty() << std::endl;
			std::cout << "print the size of set_gen: " << set_gen.size() << std::endl;


			std::cout << std::endl << "=Create new set" << std::endl;
			NAMESPACE::set<int>		new_set;
			
			std::cout << std::boolalpha << "is new_set empty? " << new_set.empty() << std::endl;
			std::cout << "print the size of new_set: " << new_set.size() << std::endl;
			
			std::cout << std::endl << M_YELLOW << "*****fin de test*****" << M_RESET << std::endl << std::endl;
		}

		////////////////////////////////////////////////////////////////////////////////
		
		{
			std::cout << std::endl << M_CYAN << "=> insert : " << M_RESET << std::endl << std::endl;
			
			NAMESPACE::set<int>		set_test;
			
			std::cout << "set_gen contains:";
			for (NAMESPACE::set<int>::iterator it = set_gen.begin(), ite = set_gen.end(); it != ite; it++)
				std::cout << " (" << *it << ")";
			std::cout << std::endl << std::endl;


			std::cout << std::endl << "=insert begin of set_gen in set_test=" << std::endl;
			set_test.insert(*set_gen.begin());
			std::cout << "set_test begin contains: (" << *set_test.begin() << "|" << *set_test.begin() << ")" << std::endl;


			std::cout << std::endl << "=insert begin until end of set_gen in set_test=" << std::endl;
			set_test.insert(set_gen.begin(), set_gen.end());
			std::cout << "set_test contains:";
			for (NAMESPACE::set<int>::iterator it = set_test.begin(), ite = set_test.end(); it != ite; it++)
				std::cout << " (" << *it << ")";
			std::cout << std::endl << std::endl;
			
			std::cout << std::endl << M_YELLOW << "*****fin de test*****" << M_RESET << std::endl << std::endl;
		}

		////////////////////////////////////////////////////////////////////////////////
		
		{
			std::cout << std::endl << M_CYAN << "=> erase : " << M_RESET << std::endl << std::endl;

			NAMESPACE::set<int>		set_test(set_gen.begin(), set_gen.end());
			
			std::cout << "set_test contains:";
			for (NAMESPACE::set<int>::iterator it = set_test.begin(), ite = set_test.end(); it != ite; it++)
				std::cout << " (" << *it << ")";
			std::cout << std::endl << std::endl;
			
			std::cout << std::endl << "=Erase first elem of set_test=" << std::endl;
			set_test.erase(set_test.begin());
			std::cout << "set_test contains:";
			for (NAMESPACE::set<int>::iterator it = set_test.begin(), ite = set_test.end(); it != ite; it++)
				std::cout << " (" << *it << ")";
			std::cout << std::endl << std::endl;
			
			std::cout << std::endl << "=Erase (3|6) elem of set_test=" << std::endl;
			set_test.erase(3);
			std::cout << "set_test contains:";
			for (NAMESPACE::set<int>::iterator it = set_test.begin(), ite = set_test.end(); it != ite; it++)
				std::cout << " (" << *it << ")";
			std::cout << std::endl << std::endl;
			
			std::cout << std::endl << "=Erase all elem of set_test=" << std::endl;
			set_test.erase(set_test.begin(), set_test.end());
			std::cout << std::boolalpha << "set_test is empty? " << set_test.empty() << std::endl;
			
			
			std::cout << std::endl << M_YELLOW << "*****fin de test*****" << M_RESET << std::endl << std::endl;
		}

		////////////////////////////////////////////////////////////////////////////////
		
		{
			std::cout << std::endl << M_CYAN << "=> swap : " << M_RESET << std::endl << std::endl;

			NAMESPACE::set<std::string>		set_test1;
			NAMESPACE::set<std::string>		set_test2;

			set_test1.insert("abc");
			set_test1.insert("Hello");
			set_test1.insert("World");
			set_test1.insert("!");

			set_test2.insert("Coucou");
			set_test2.insert("le");
			set_test2.insert("monde !");

			std::cout << "set_test1 contains:";
			for (NAMESPACE::set<std::string>::iterator it = set_test1.begin(), ite = set_test1.end(); it != ite; it++)
				std::cout << " (" << *it << ")";
			std::cout << std::endl << std::endl;
			
			std::cout << "set_test2 contains:";
			for (NAMESPACE::set<std::string>::iterator it = set_test2.begin(), ite = set_test2.end(); it != ite; it++)
				std::cout << " (" << *it << ")";
			std::cout << std::endl << std::string(42, '=') << std::endl;

			swap(set_test1, set_test2);
			
			std::cout << "after swap set_test1 contains:";
			for (NAMESPACE::set<std::string>::iterator it = set_test1.begin(), ite = set_test1.end(); it != ite; it++)
				std::cout << " (" << *it << ")";
			std::cout << std::endl << std::endl;
			
			std::cout << "after swap set_test2 contains:";
			for (NAMESPACE::set<std::string>::iterator it = set_test2.begin(), ite = set_test2.end(); it != ite; it++)
				std::cout << " (" << *it << ")";
			std::cout << std::endl << std::string(42, '=') << std::endl;
			
			std::cout << std::endl << M_YELLOW << "*****fin de test*****" << M_RESET << std::endl << std::endl;
		}

		////////////////////////////////////////////////////////////////////////////////
		
		{
			std::cout << std::endl << M_CYAN << "=> clear : " << M_RESET << std::endl << std::endl;

			NAMESPACE::set<int>		set_test(set_gen);

			std::cout << std::boolalpha << "set_test is empty? " << set_test.empty() << std::endl;

			std::cout << std::endl << "=clear set_test=" << std::endl;
			set_test.clear();
			std::cout << std::boolalpha << "set_test is empty? " << set_test.empty() << std::endl;
			
			std::cout << std::endl << M_YELLOW << "*****fin de test*****" << M_RESET << std::endl << std::endl;
		}

		////////////////////////////////////////////////////////////////////////////////
		
		{
			std::cout << std::endl << M_CYAN << "=> find : " << M_RESET << std::endl << std::endl;

			NAMESPACE::set<int>			set_test(set_gen);
			NAMESPACE::set<int>::iterator	ret = set_test.find(8); // should find it
			
			std::cout << std::endl << "=try to find 8=" << std::endl;
			if (ret == set_test.end())
				std::cout << "no occurence found" << std::endl;
			else
				std::cout << "found :" << *ret << std::endl; 

			std::cout << std::endl << "=try to find 9999=" << std::endl;
			ret = set_test.find(9999); // sould'nt find it
			if (ret == set_test.end())
				std::cout << "no occurence found" << std::endl;
			else
				std::cout << "found :" << *ret << std::endl; 
			
			
			std::cout << std::endl << M_YELLOW << "*****fin de test*****" << M_RESET << std::endl << std::endl;
		}

		////////////////////////////////////////////////////////////////////////////////
		
		{
			std::cout << std::endl << M_CYAN << "=> count : " << M_RESET << std::endl << std::endl;
			NAMESPACE::set<int>			set_test(set_gen);

				std::cout << std::endl << "=try count on 8=" << std::endl;
				std::cout << "count return: " << set_test.count(8) << std::endl;
				
				std::cout << std::endl << "=try count on 56=" << std::endl;
				std::cout << "count return: " << set_test.count(56) << std::endl;

			std::cout << std::endl << M_YELLOW << "*****fin de test*****" << M_RESET << std::endl << std::endl;
		}

		////////////////////////////////////////////////////////////////////////////////
		
		{
			std::cout << std::endl << M_CYAN << "=> lower_bound : " << M_RESET << std::endl << std::endl;
			
			NAMESPACE::set<std::string>		test;

			std::cout << "test" << std::endl;
			test.insert(std::string("coucou"));
			test.insert(std::string("toi"));
			test.insert(std::string("c'est"));
			test.insert(std::string("mon"));
			test.insert(std::string("test"));

			
			
			std::cout << std::endl << "=try lower_bound on 'coucou'=" << std::endl;
			if (test.lower_bound(std::string("coucou")) == test.end())
				std::cout << "end() has been returned" << std::endl;
			else
				std::cout << "lower_bound return: " << *test.lower_bound(std::string("coucou"));
				
			std::cout << std::endl << "=try lower_bound on 'pas la'=" << std::endl;
			if (test.lower_bound(std::string("pas la")) == test.end())
				std::cout << "end() has been returned" << std::endl;
			else
				std::cout << "lower_bound return: " << *test.lower_bound(std::string("pas la"));
				
			std::cout << std::endl << "=try lower_bound on 'test'=" << std::endl;
			if (test.lower_bound(std::string("test")) == test.end())
				std::cout << "end() has been returned" << std::endl;
			else
				std::cout << "lower_bound return: " << *test.lower_bound(std::string("test"));
			
			
			
			
			std::cout << std::endl << M_YELLOW << "*****fin de test*****" << M_RESET << std::endl << std::endl;
		}

		////////////////////////////////////////////////////////////////////////////////
		
		{
			std::cout << std::endl << M_CYAN << "=> upper_bound : " << M_RESET << std::endl << std::endl;
			
			std::cout << "in set_gen contains:";
			for (NAMESPACE::set<int>::iterator it = set_gen.begin(), ite = set_gen.end(); it != ite; it++)
				std::cout << " " << *it;
			std::cout << std::endl;

			std::cout << std::endl << "=try upper_bound on 3=" << std::endl;
			if (set_gen.upper_bound(3) == set_gen.end())
				std::cout << "end() has been returned" << std::endl;
			else
				std::cout << "upper_bound return: " << *set_gen.upper_bound(3);
				
			std::cout << std::endl << "=try upper_bound on 10=" << std::endl;
			if (set_gen.upper_bound(10) == set_gen.end())
				std::cout << "end() has been returned" << std::endl;
			else
				std::cout << "upper_bound return: " << *set_gen.upper_bound(10);
				
			std::cout << std::endl << "=try upper_bound on 100=" << std::endl;
			if (set_gen.upper_bound(100) == set_gen.end())
				std::cout << "end() has been returned" << std::endl;
			else
				std::cout << "upper_bound return: " << *set_gen.upper_bound(100);
			
			
			std::cout << std::endl << M_YELLOW << "*****fin de test*****" << M_RESET << std::endl << std::endl;
		}

		////////////////////////////////////////////////////////////////////////////////
		
		{
			std::cout << std::endl << M_CYAN << "=> equal_range : " << M_RESET << std::endl << std::endl;
			
			
			std::cout << std::endl << "=try equal_range on 3=" << std::endl;
			if ((set_gen.equal_range(3).first) == set_gen.end())
				std::cout << "end() has been returned" << std::endl;
			else
				std::cout << "equal_range return: " << *(set_gen.equal_range(3).first);
				
			std::cout << std::endl << "=try equal_range on 10=" << std::endl;
			if ((set_gen.equal_range(10).first) == set_gen.end())
				std::cout << "end() has been returned" << std::endl;
			else
				std::cout << "equal_range return: " << *(set_gen.equal_range(10).first);
				
			std::cout << std::endl << "=try equal_range on 100=" << std::endl;
			if ((set_gen.equal_range(100).first) == set_gen.end())
				std::cout << "end() has been returned" << std::endl;
			else
				std::cout << "equal_range return: " << *(set_gen.equal_range(100).first);
				
				
			std::cout << std::endl << M_YELLOW << "*****fin de test*****" << M_RESET << std::endl << std::endl;
		}

		////////////////////////////////////////////////////////////////////////////////
	}

	return (0);
}
