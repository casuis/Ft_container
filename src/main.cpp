/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimon <asimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 13:34:53 by asimon            #+#    #+#             */
/*   Updated: 2022/11/04 19:07:41 by asimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <ftnspace.hpp>
# define YELLOW "\033[1;33m"
# define GREEN	"\033[1;32m"
# define RED	"\033[1;31m"
# define BLACK	"\033[1;30m"
# define CYAN	"\033[1;36m"
# define RESET	"\033[0m"


int		main(void)
{
	
	////////////////////////////////////////////////////////////////////////////////
	/*                              VECTOR                                        */
	////////////////////////////////////////////////////////////////////////////////
	
	std::cout << std::endl << YELLOW << "##########VECTOR##########" << RESET << std::endl << std::endl;

	////////////////////////////////////////////////////////////////////////////////
	{	
		std::cout << CYAN << "=========CONSTRUCTOR=========" << RESET << std::endl;
		
		////////////////////////////////////////////////////////////////////////////////
		{
			NAMESPACE::vector<int>					tab;



			tab.push_back(100);
			tab.push_back(990);
			NAMESPACE::vector<int>::iterator	it = tab.begin();
			NAMESPACE::vector<int>::iterator	ite = tab.end();
			++it;
			std::cout <<  "it: " << *it << std::endl;
			for (; it != ite; it++){
				std::cout <<  "tab: " << *it << std::endl;
			}	
		}
	}	
	////////////////////////////////////////////////////////////////////////////////
	{	
		std::cout << CYAN << "=========ASSIGN=========" << RESET << std::endl;;
		
		////////////////////////////////////////////////////////////////////////////////
		{
			NAMESPACE::vector<int>						tab(20);
			NAMESPACE::vector<int>::iterator	it = tab.begin();
			NAMESPACE::vector<int>::iterator	ite = tab.end();
			
			it = tab.begin();
			ite = tab.end(); 
			tab.assign(it, ite);
			
			NAMESPACE::vector<int>::iterator	it2 = tab.begin();
			NAMESPACE::vector<int>::iterator	ite2 = tab.end();
			for (; it2 != ite2; it2++){
				std::cout <<  "tab: " << *it2 << std::endl;
			}
		}
		////////////////////////////////////////////////////////////////////////////////
		
	}
	////////////////////////////////////////////////////////////////////////////////
	{
		std::cout << CYAN << "=========INSERT=========" << RESET << std::endl;
		
		////////////////////////////////////////////////////////////////////////////////
		/* insert pos */
		{
			std::cout << "=>Insert by position and val:" << std::endl;
			
			NAMESPACE::vector<int>				tab(10, 42);

			for (NAMESPACE::vector<int>::iterator it3 = tab.begin(), ite3 = tab.end(); it3 != ite3; it3++){
				std::cout << "befor: " << *it3 << std::endl;
			}
			std::cout << "------------" << std::endl;
			tab.insert(tab.begin() + 1, 20);	
			for (NAMESPACE::vector<int>::iterator it3 = tab.begin(), ite3 = tab.end(); it3 != ite3; it3++){
				std::cout << "after: " << *it3 << std::endl;
			}
			std::cout << std::endl;
			}
		////////////////////////////////////////////////////////////////////////////////
		/* insert range */
		{
			std::cout << "=>Insert by range:" << std::endl;
	
			NAMESPACE::vector<int>				tab(5, 42);
			NAMESPACE::vector<int>				tab_bis(2, 100);
			
			for (NAMESPACE::vector<int>::iterator it3 = tab.begin(), ite3 = tab.end(); it3 != ite3; it3++){
				std::cout << "befor: " << *it3 << std::endl;
			}
			std::cout << "------------" << std::endl;
			tab.insert(tab.begin() + 1, tab_bis.begin(), tab_bis.end());	
			for (NAMESPACE::vector<int>::iterator it3 = tab.begin(), ite3 = tab.end(); it3 != ite3; it3++){
				std::cout << "after: " << *it3 << std::endl;
			}
			std::cout << std::endl;
		}
		////////////////////////////////////////////////////////////////////////////////
		/* insert errors | out of range pos */
	// 	{
	// 		std::cout << "=>Insert by range | errors : Out of range:" << std::endl;
	
	// 		NAMESPACE::vector<int>				tab(5, 42);
	// 		NAMESPACE::vector<int>				tab_bis(2, 100);
			
	// 		for (NAMESPACE::vector<int>::iterator it3 = tab.begin(), ite3 = tab.end(); it3 != ite3; it3++){
	// 			std::cout << "befor: " << *it3 << std::endl;
	// 		}
	// 		std::cout << "------------" << std::endl;
	// 		tab.insert(tab_bis.begin() + 1, tab_bis.begin(), tab_bis.end());	
	// 		for (NAMESPACE::vector<int>::iterator it3 = tab.begin(), ite3 = tab.end(); it3 != ite3; it3++){
	// 			std::cout << "after: " << *it3 << std::endl;
	// 		}
	// 		std::cout << std::endl;
	// 	}
		////////////////////////////////////////////////////////////////////////////////
	
	}
	////////////////////////////////////////////////////////////////////////////////
	{
		std::cout << CYAN << "=========SWAP=========" << RESET << std::endl;
		
			NAMESPACE::vector<int>				tab(10, 99);
			NAMESPACE::vector<int>				tab2(5, 100);
		////////////////////////////////////////////////////////////////////////////////
		{
			
			std::cout << "=> test simple swap:" << std::endl; 
			for (NAMESPACE::vector<int>::iterator it = tab.begin(), ite = tab.end(); it != ite; it++){
				std::cout <<  "tab: " << *it << std::endl;
			}
			tab.swap(tab2);
			std::cout << std::endl;
			for (NAMESPACE::vector<int>::iterator it = tab.begin(), ite = tab.end(); it != ite; it++){
				std::cout <<  "tab: " << *it << std::endl;
			}
			for (NAMESPACE::vector<int>::iterator it1 = tab2.begin(), ite1=tab2.end(); it1 != ite1; it1++){
				std::cout <<  "tab1: " << *it1 << std::endl;
			}
			std::cout << std::endl;	
		}
		////////////////////////////////////////////////////////////////////////////////
	}
	////////////////////////////////////////////////////////////////////////////////
	{
		std::cout << CYAN << "=========OPERATOR=========" << RESET << std::endl;
		
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
		std::cout << CYAN << "=========INCEPTION=========" << RESET << std::endl;
		
			NAMESPACE::vector<int>										tab_to_insert(1, 40);
			NAMESPACE::vector<int>										tab_bis_to_insert(2, 10);
			NAMESPACE::vector< NAMESPACE::vector<int> >					tab(4, tab_to_insert);
			NAMESPACE::vector< NAMESPACE::vector<int> >					tab_bis(2, tab_bis_to_insert);
			

		////////////////////////////////////////////////////////////////////////////////
		{
			std::cout << "=> Test Default Constructor " << std::endl;	
			NAMESPACE::vector< NAMESPACE::vector<int> >			test;

			ft::print(test, "default: ");
			std::cout << std::endl << "capacity: [" << test.capacity() << "]" << std::endl;
			std::cout << std::endl << "size: [" << test.size() << "]" << std::endl;
			
			std::cout << std::endl << "*****fin de test*****" << std::endl << std::endl;
		}
		////////////////////////////////////////////////////////////////////////////////
		{
			std::cout << "=> Test copy Constructor" << std::endl;
			NAMESPACE::vector< NAMESPACE::vector<int> >			copy(tab);

			ft::print(tab, "original: ");
			ft::print(copy, "copy: ");
			std::cout << std::endl << "capacity: [" << copy.capacity() << "]" << std::endl;
			std::cout << std::endl << "size: [" << copy.size() << "]" << std::endl;
			
			std::cout << std::endl << "*****fin de test*****" << std::endl << std::endl;
		}
		////////////////////////////////////////////////////////////////////////////////
		{
			std::cout << "=> Test range constructor" << std::endl;	

			ft::print(tab, "tab utilise pour fill: ");
			NAMESPACE::vector< NAMESPACE::vector<int> >		fill(tab.begin() + 1, tab.end());
			ft::print(fill, "fill by range + 1: ");
			std::cout << std::endl << "capacity: [" << fill.capacity() << "]"<< std::endl;
			std::cout << std::endl << "size: [" << fill.size() << "]" << std::endl;
			
			std::cout << std::endl << "*****fin de test*****" << std::endl << std::endl;
		}
		////////////////////////////////////////////////////////////////////////////////
		{
			std::cout << "=> Test capacity section:" << std::endl;
			NAMESPACE::vector< NAMESPACE::vector<int> >			test;
			
			std::cout << std::boolalpha << "tab is empty? [" << tab.empty() << "]" << std::endl; 
			std::cout << std::endl << "capacity: [" << tab.capacity() << "]"<< std::endl;
			std::cout << std::endl << "size: [" << tab.size() << "]" << std::endl;
			std::cout << std::endl << "*****fin de test*****" << std::endl << std::endl;
		}
		////////////////////////////////////////////////////////////////////////////////
		{
		}
		////////////////////////////////////////////////////////////////////////////////
		{
			std::cout << "=> Test insert:" << std::endl;
			NAMESPACE::vector< NAMESPACE::vector<int> >::iterator		it = tab_bis.begin();
			NAMESPACE::vector< NAMESPACE::vector<int> >::iterator		ite = tab_bis.end();
			
			std::cout << std::endl;
			ft::print(tab, "tab avant insert: ");
			tab.insert(tab.begin(), it, ite);
			ft::print(tab, "tab apres insert: ");
			
			std::cout << std::endl << "*****fin de test*****" << std::endl << std::endl;
		}
		////////////////////////////////////////////////////////////////////////////////
		{
			std::cout << "=> Test swap:" << std::endl;
			/* tab_to_insert | tab_bis_to_insert | tab | tab_bis */
			
			ft::print(tab, "tab: ");
			ft::print(tab_bis, "tab_bis: ");
			std::cout << std::endl;
			tab.swap(tab_bis);
			ft::print(tab, "tab 2eme call: ");
			ft::print(tab, "tab_bis 2eme call: ");
			std::cout << std::endl << "*****fin de test*****" << std::endl << std::endl;
		}	
		////////////////////////////////////////////////////////////////////////////////
	}
	////////////////////////////////////////////////////////////////////////////////
	// {
	// 	std::cout << CYAN << "=========MORE TEST=========" << RESET << std::endl;

	// 	NAMESPACE::vector<int>		tab;
	// 	////////////////////////////////////////////////////////////////////////////////
	// 	{
	// 		std::cout << "print size on a default vector: " << tab.size() << std::endl << std::endl;
	// 		std::cout << "print capacity on a default vector: " << tab.capacity() << std::endl << std::endl;
	// 		tab.push_back(10);
	// 		std::cout << "print size on a vector 1: " << tab.size() << std::endl << std::endl;
	// 		std::cout << "print capacity on a vector 1: " << tab.capacity() << std::endl << std::endl;
	// 	}
	// }
	std::cout << YELLOW << "\t\tEND" << RESET << std::endl;	
	return (0);
}
