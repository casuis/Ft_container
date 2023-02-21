/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_vector.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimon <asimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 13:34:53 by asimon            #+#    #+#             */
/*   Updated: 2023/02/21 22:52:20 by asimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <ftnspace.hpp>


#if STD == 1
	std::string		print_nspace = "##STD";
#else
	std::string		print_nspace = "##FT";
#endif


int		main(void)
{

	 ////////////////////////////////////////////////////////////////////////////////
	 /*                              VECTOR                                        */
	 ////////////////////////////////////////////////////////////////////////////////
	 std::cout << print_nspace << std::endl;
	 std::cout << std::endl << M_YELLOW << "##########VECTOR##########" << M_RESET << std::endl << std::endl;

	 ////////////////////////////////////////////////////////////////////////////////
	 {	
	 	std::cout << M_CYAN << "=========CONSTRUCTOR=========" << M_RESET << std::endl;

	 	NAMESPACE::vector<int>										tab(1, 40);
	 	NAMESPACE::vector<int>										tab_bis(2, 10);

	 	////////////////////////////////////////////////////////////////////////////////
	 	{
	 		std::cout << M_CYAN << "=> Test Default Constructor " << M_RESET << std::endl << std::endl;
	 		NAMESPACE::vector< int >			test;

	 		ft::print(test, "default: ");

	 		std::cout << std::endl << M_YELLOW << "*****fin de test*****" << M_RESET << std::endl << std::endl;
	 	}
	 	////////////////////////////////////////////////////////////////////////////////
	 	{
	 		std::cout << M_CYAN << "=> Test copy Constructor" << M_RESET << std::endl << std::endl;
	 		NAMESPACE::vector< int >			copy(tab);

	 		ft::print(tab, "original: ");
	 		ft::print(copy, "copy: ");

	 		std::cout << std::endl << M_YELLOW << "*****fin de test*****" << M_RESET << std::endl << std::endl;
	 	}
	 	////////////////////////////////////////////////////////////////////////////////
	 	{
	 		std::cout << M_CYAN << "=> Test range constructor" << M_RESET << std::endl << std::endl;
	
	 		NAMESPACE::vector< int >		fill(tab.begin() + 1, tab.end());
	
	 		ft::print(tab, "tab utilise pour fill: ");
	 		ft::print(fill, "fill by range + 1: ");

	 		std::cout << std::endl << M_YELLOW << "*****fin de test*****" << M_RESET << std::endl << std::endl;
	 	}
	 }	
	 ////////////////////////////////////////////////////////////////////////////////
	 {
	 	std::cout << M_CYAN << "=========OPERATOR=========" << M_RESET << std::endl;

	 		NAMESPACE::vector<int>		std_tab(10,20);
	 	////////////////////////////////////////////////////////////////////////////////
	 	{
	 		NAMESPACE::vector<int>		std_tab2 = std_tab;
	 		std_tab.push_back(100);
	 		std::cout << std::boolalpha << (std_tab < std_tab2) << std::endl;
	
	 		for (NAMESPACE::vector<int>::iterator std_it = std_tab2.begin(), std_ite = std_tab2.end();
	 		std_it != std_ite; std_it++){
	 			std::cout << *std_it << std::endl;
	 		}
	 	}
	 	////////////////////////////////////////////////////////////////////////////////
	 }

	 ////////////////////////////////////////////////////////////////////////////////
	 {
	 	std::cout << M_CYAN << "=========INCEPTION=========" << M_RESET << std::endl;

	 		NAMESPACE::vector<int>										tab_to_insert(1, 40);
	 		NAMESPACE::vector<int>										tab_bis_to_insert(2, 10);
	 		NAMESPACE::vector< NAMESPACE::vector<int> >					tab(4, tab_to_insert);
	 		NAMESPACE::vector< NAMESPACE::vector<int> >					tab_bis(2, tab_bis_to_insert);
	 	////////////////////////////////////////////////////////////////////////////////
	 	{
	 		std::cout << M_CYAN << "=> Test Default Constructor " << M_RESET << std::endl << std::endl;
	 		NAMESPACE::vector< NAMESPACE::vector<int> >			test;

	 		ft::print(test, "default: ");

	 		std::cout << std::endl << M_YELLOW << "*****fin de test*****" << M_RESET << std::endl << std::endl;
	 	}
	 	////////////////////////////////////////////////////////////////////////////////
	 	{
	 		std::cout << M_CYAN << "=> Test copy Constructor" << M_RESET << std::endl << std::endl;
	 		NAMESPACE::vector< NAMESPACE::vector<int> >			copy(tab);

	 		ft::print(tab, "original: ");
	 		ft::print(copy, "copy: ");

	 		std::cout << std::endl << M_YELLOW << "*****fin de test*****" << M_RESET << std::endl << std::endl;
	 	}
	 	////////////////////////////////////////////////////////////////////////////////
	 	{
	 		std::cout << M_CYAN << "=> Test range constructor" << M_RESET << std::endl << std::endl;
	
	 		NAMESPACE::vector< NAMESPACE::vector<int> >		fill(tab.begin() + 1, tab.end());
	
	 		ft::print(tab, "tab utilise pour fill: ");
	 		ft::print(fill, "fill by range + 1: ");

	 		std::cout << std::endl << M_YELLOW << "*****fin de test*****" << M_RESET << std::endl << std::endl;
	 	}
	 	////////////////////////////////////////////////////////////////////////////////
	 	{
	 		std::cout << M_CYAN << "=> Test capacity section:" << M_RESET << std::endl << std::endl;

	 		NAMESPACE::vector< NAMESPACE::vector<int> >			test;

	 		ft::print(tab, "tab: ");
	 		std::cout << std::boolalpha << "test is empty? [" << M_GREEN << test.empty() << M_RESET << "]" << std::endl; 
	 		std::cout << std::boolalpha << "tab is empty? [" << M_GREEN << tab.empty() << M_RESET << "]" << std::endl; 

	 		std::cout << std::endl << M_YELLOW << "*****fin de test*****" << M_RESET << std::endl << std::endl;
	 	}
	 	////////////////////////////////////////////////////////////////////////////////
	 	{
	 		std::cout << M_CYAN << "=> Test reserve: " << M_RESET << std::endl << std::endl;

	 		NAMESPACE::vector< NAMESPACE::vector<int> >			test(tab);

	 		ft::print(test, "test: ");
	
	 		std::cout << "reserve for 10" << std::endl; 
	 		test.reserve(10);
	
	 		ft::print(test, "test after: ");

	 		std::cout << std::endl << M_YELLOW << "*****fin de test*****" << M_RESET << std::endl << std::endl;
	 	}
	 	////////////////////////////////////////////////////////////////////////////////
	 	{
	 		std::cout << M_CYAN << "=> Test resize:" << M_RESET << std::endl << std::endl;
	
	 		NAMESPACE::vector< NAMESPACE::vector<int> >			test(tab);
	
	 		ft::print(test, "test: ");
	
	 		std::cout << "resize to 42" << std::endl;
	 		test.resize(42);

	 		ft::print(test, "test after: ");			

	 		std::cout << std::endl << M_YELLOW << "*****fin de test*****" << M_RESET << std::endl << std::endl;
	 	}
	 	////////////////////////////////////////////////////////////////////////////////
	 	{
	 		std::cout << M_CYAN << "=> Test operator[]:" << M_RESET << std::endl << std::endl;
	 		NAMESPACE::vector<int>			test;

	 		for (int i = 0; i < 10; i++){
	 			test.push_back(i);
	 			std::cout << "cap: [" << test.capacity() << "]" << std::endl; 
		
	 		}
	
		
	 		ft::print(test, "test: ");
	
	 		std::cout << "value tab[0]: [" << M_GREEN << test[0] << M_RESET << "]" << std::endl;			
	
	 		std::cout << std::endl << M_YELLOW << "*****fin de test*****" << M_RESET << std::endl << std::endl;
	 	}
	 	////////////////////////////////////////////////////////////////////////////////
	 	{
	 		std::cout << M_CYAN << "=> Test at:" << M_RESET << std::endl << std::endl;
	 		NAMESPACE::vector<int>			test;

	 		for (int i = 0; i < 10; i++)
	 			test.push_back(i);

	 		ft::print(test, "test: ");
	
	 		std::cout << "value tab[2]: [" << M_GREEN << test.at(2) << M_RESET << "]" << std::endl;			
	
	 		std::cout << std::endl << M_YELLOW << "*****fin de test*****" << M_RESET << std::endl << std::endl;
	 	}
	 	////////////////////////////////////////////////////////////////////////////////
	 	{
	 		std::cout << M_CYAN << "=> Test front:" << M_RESET << std::endl << std::endl;
	 		NAMESPACE::vector<int>			test;

	 		for (int i = 0; i < 10; i++)
	 			test.push_back(i);
		
	 		ft::print(test, "test: ");
	
	 		std::cout << "value front: [" << M_GREEN << test.front() << M_RESET << "]" << std::endl;			
	
	 		std::cout << std::endl << M_YELLOW << "*****fin de test*****" << M_RESET << std::endl << std::endl;
	 	}
	 	////////////////////////////////////////////////////////////////////////////////
	 	{
	 		std::cout << M_CYAN << "=> Test back:" << M_RESET << std::endl << std::endl;
	 		NAMESPACE::vector<int>			test;

	 		for (int i = 0; i < 10; i++)
	 			test.push_back(i);
		
	 		ft::print(test, "test: ");
	
	 		std::cout << "value back: [" << M_GREEN << test.back() << M_RESET << "]" << std::endl;			
	
	 		std::cout << std::endl << M_YELLOW << "*****fin de test*****" << M_RESET << std::endl << std::endl;
	 	}
	 	////////////////////////////////////////////////////////////////////////////////
	 	{
	 		std::cout << M_CYAN << "=> Test clear:" << M_RESET << std::endl << std::endl;
	 		NAMESPACE::vector<int>			test;

	 		for (int i = 0; i < 10; i++)
	 			test.push_back(i);
		
	 		ft::print(test, "test: ");
	
	 		test.clear();
	
	 		ft::print(test, "test: ");
	
	 		std::cout << std::endl << M_YELLOW << "*****fin de test*****" << M_RESET << std::endl << std::endl;
	 	}
	 	////////////////////////////////////////////////////////////////////////////////
	 	{
	 		std::cout << M_CYAN << "=> Test pop_back:" << M_RESET << std::endl << std::endl;
	 		NAMESPACE::vector<int>			test;

	 		for (int i = 0; i < 10; i++)
	 			test.push_back(i);
		
	 		ft::print(test, "test: ");
	
	 		std::cout << std::endl << "back value: [" << test.back() << "]" << std::endl; 
	 		test.pop_back();
	 		std::cout << std::endl << "back value after pop_back: [" << test.back() << "]" << std::endl; 
	
	 		std::cout << std::endl << M_YELLOW << "*****fin de test*****" << M_RESET << std::endl << std::endl;
	 	}
	 	////////////////////////////////////////////////////////////////////////////////
	 	{
	 		std::cout << M_CYAN << "=> Test swap:" << M_RESET << std::endl << std::endl;
	 		NAMESPACE::vector<int>			test;
	 		NAMESPACE::vector<int>			test_bis;
	 		NAMESPACE::vector<int>			test_tier;
	 		for (int i = 0; i < 10; i++)
	 			test.push_back(i);
	 		for (int i = 10; i < 24; i++)
	 			test_bis.push_back(i);
	
	 		ft::print(test, "test: ");
	 		ft::print(test_bis, "test_bis: ");
	
	 		test.swap(test_bis);
	
	 		ft::print(test, "test after swap : ");
	 		ft::print(test_bis, "test_bis after swap: ");

	 		test.swap(test_tier);
	 		ft::print(test, "test after swap : ");
	 		ft::print(test_tier, "test_tiers after swap : ");
	
	 		std::cout << std::endl << M_YELLOW << "*****fin de test*****" << M_RESET << std::endl << std::endl;
	 	}
	 	////////////////////////////////////////////////////////////////////////////////
	 	{
	 		std::cout << M_CYAN << "=> Test erase:" << M_RESET << std::endl << std::endl;
	 		NAMESPACE::vector<int>			test;
	 		for (int i = 0; i < 10; i++)
	 			test.push_back(i);
	
	 		ft::print(test, "test: ");
	
	 		test.erase(test.begin() + 4, test.end());
	
	 		ft::print(test, "test: ");
	
	 		std::cout << std::endl << M_YELLOW << "*****fin de test*****" << M_RESET << std::endl << std::endl;
	 	}
	 	////////////////////////////////////////////////////////////////////////////////
	 	{
	 		std::cout << M_CYAN << "=> Test assign:" << M_RESET << std::endl << std::endl;
	 		NAMESPACE::vector<int>			test;
	 		NAMESPACE::vector<int>			test_bis;
	
	 		for (int i = 0; i < 10; i++)
	 			test.push_back(i);
	 		for (int i = 10; i < 24; i++)
	 			test_bis.push_back(i);
	
	 		ft::print(test, "test: ");
	 		ft::print(test_bis, "test_bis: ");
	
	 		test.assign(test_bis.begin() + 1, test_bis.end());
	 		ft::print(test, "test 1: ");
	 		test.assign(8, 42);
	 		ft::print(test, "test 2: ");
	
	 		std::cout << std::endl << M_YELLOW << "*****fin de test*****" << M_RESET << std::endl << std::endl;
	 	}
	 	////////////////////////////////////////////////////////////////////////////////
	 	{
	 		std::cout << M_CYAN << "=> Test insert normale:" << M_RESET << std::endl << std::endl;
	 		NAMESPACE::vector<int>			test;
	 		NAMESPACE::vector<int>			test_bis;
	 		NAMESPACE::vector<int>			more_test;
	
	 		for (int i = 0; i < 10; i++)
	 			test.push_back(0);
	 		for (int i = 10; i < 24; i++)
	 			test_bis.push_back(i);
	
	 		ft::print(test, "test: ");
	 		ft::print(test_bis, "test_bis: ");
	
	 		test.insert(test.begin() + 1, test_bis.begin() + 2, test_bis.end());
	
	 		ft::print(test, "test 1: ");
	
	 		std::cout << "cap: [" << more_test.capacity() << "]" << std::endl; 
	 		more_test.insert(more_test.begin(), 9, 42);
	 		std::cout << "cap: [" << more_test.capacity() << "]" << std::endl;
	 		ft::print(more_test, "test 2: ");

	
	 		std::cout << std::endl << M_YELLOW << "*****fin de test*****" << M_RESET << std::endl << std::endl;
	 	}
	 	////////////////////////////////////////////////////////////////////////////////
	 	{
	 		std::cout << M_CYAN << "=> Test insert inception:" << M_RESET << std::endl << std::endl;

	 		NAMESPACE::vector< NAMESPACE::vector<int> >::iterator		it = tab_bis.begin();
	 		NAMESPACE::vector< NAMESPACE::vector<int> >::iterator		ite = tab_bis.end();

	 		std::cout << std::endl;
	 		ft::print(tab, "tab avant insert: ");
	 		tab.insert(tab.begin(), it, ite);
	 		ft::print(tab, "tab apres insert: ");
	 		std::cout << "tab size " << tab.size() << std::endl;

	 		std::cout << std::endl << M_YELLOW << "*****fin de test*****" << M_RESET << std::endl << std::endl;
	 	}
	 	////////////////////////////////////////////////////////////////////////////////
	 	{
	 		std::cout << M_CYAN << "=> Test swap:" << M_RESET << std::endl << std::endl;
	 		/* tab_to_insert | tab_bis_to_insert | tab | tab_bis */
	
	 		ft::print(tab, "tab: ");
	 		ft::print(tab_bis, "tab_bis: ");
	 		std::cout << std::endl;
	 		tab.swap(tab_bis);
	 		ft::print(tab, "tab 2eme call: ");
	 		ft::print(tab, "tab_bis 2eme call: ");

	 		std::cout << std::endl << M_YELLOW << "*****fin de test*****" << M_RESET << std::endl << std::endl;
	 	}	
	 	////////////////////////////////////////////////////////////////////////////////
	 }
	 ////////////////////////////////////////////////////////////////////////////////
	 {
	 	std::cout << M_CYAN << "=========MORE TEST=========" << M_RESET << std::endl;

	 	// NAMESPACE::vector<std::string>					test(8);
	 	// NAMESPACE::vector<std::string>::iterator		it = test.begin();

	 	// test.push_back("AAAAAA");
	 	// std::cout << *it << std::endl;

	 	////////////////////////////////////////////////////////////////////////////////
	 }

	 	////////////////////////////////////////////////////////////////////////////////
	/* INCEPTION */
	

	//////////////////////////////////////////////////////////////////////////////////////
	
	return (0);
}
