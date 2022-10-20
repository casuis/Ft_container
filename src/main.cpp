/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimon <asimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 13:34:53 by asimon            #+#    #+#             */
/*   Updated: 2022/10/20 15:34:19 by asimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <ftnspace.hpp>
# define YELLOW "\033[1;33m"
# define GREEN	"\033[1;32m"
# define RED	"\033[1;31m"
# define BLACK	"\033[1;30m"
# define CYAN	"\033[1;36m"
# define RESET	"\033[0m"
// template <class Category,  // iterator::iterator_category class T,  // iterator::value_type   class Distance = ptrdiff_t, // iterator::difference_type  ss Pointer = T*,// iterator::pointer  class Reference = T&  // iterator::reference          > class iterator;


int		main(void)
{
	
	////////////////////////////////////////////////////////////////////////////////
	/*                              VECTOR                                        */
	////////////////////////////////////////////////////////////////////////////////
	std::string			format = "\t\t";
	
	std::cout << std::endl <<  format << YELLOW << "VECTOR" << RESET << std::endl << std::endl;
	std::cout << YELLOW << std::string(32, '-') << RESET << std::endl;
	////////////////////////////////////////////////////////////////////////////////
	std::cout << format << CYAN << "CONSTRUCTOR" << RESET << std::endl;
	std::cout << CYAN << std::string(32, '-') << RESET << std::endl;
	ft::vector<int>					tab;

	

	tab.push_back(100);
	tab.push_back(990);
	ft::vector<int>::iterator	it = tab.begin();
	ft::vector<int>::iterator	ite = tab.end();
	++it;
	std::cout <<  "it: " << *it << std::endl;
	for (; it != ite; it++){
		std::cout <<  "tab: " << *it << std::endl;
	}	
	
	////////////////////////////////////////////////////////////////////////////////
	
	std::cout << format << CYAN << "ASSIGN" << RESET << std::endl;;
	ft::vector<int>						tab_2(20);
	it = tab.begin();
	ite = tab.end(); 
	
	tab_2.assign(it, ite);
	ft::vector<int>::iterator	it2 = tab_2.begin();
	ft::vector<int>::iterator	ite2 = tab_2.end();
	for (; it2 != ite2; it2++){
		std::cout <<  "tab2: " << *it2 << std::endl;
	}

	////////////////////////////////////////////////////////////////////////////////
	
	std::cout << format << CYAN << "INSERT" << RESET << std::endl;;
	ft::vector<int>::iterator	it3 = tab_2.begin();
	ft::vector<int>::iterator	ite3 = tab_2.end();

	tab_2.insert(it3, 42);	
	tab_2.erase(tab_2.begin() + 1, tab_2.end());
	it3 = tab_2.begin();
	ite3 = tab_2.end();
	for (; it3 != ite3; it3++){
		std::cout <<  *it3 << std::endl;
	}

	////////////////////////////////////////////////////////////////////////////////

	std::cout << format << CYAN << "SWAP" << RESET << std::endl;;

	tab_2.insert(it3, 42);	
	for (; it3 != ite3; it3++){
		std::cout <<   *it3 << std::endl;
	}
	std::cout << YELLOW << "\t\tEND" << RESET << std::endl;	
	return (0);
}