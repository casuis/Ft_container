/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimon <asimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 13:34:53 by asimon            #+#    #+#             */
/*   Updated: 2022/10/19 13:39:27 by asimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../private/ftnspace.hpp"
# include <iostream>
# include <vector>

class A{};

// template <class Category,  // iterator::iterator_category class T,  // iterator::value_type   class Distance = ptrdiff_t, // iterator::difference_type  ss Pointer = T*,// iterator::pointer  class Reference = T&  // iterator::reference          > class iterator;

int		main(void)
{
	ft::vector<int>					tab;

	tab.push_back(100);
	tab.push_back(990);
	ft::vector<int>::iterator	it = tab.begin();
	ft::vector<int>::iterator	ite = tab.end();
	++it;
	std::cout << "it: " << *it << std::endl;
	for (; it != ite; it++){
		std::cout << "tab: " << *it << std::endl;
	}	
	
	////////////////////////////////////////////////////////////////////////////////
	
	std::cout << "----ASSIGN----" << std::endl;;
	ft::vector<int>						tab_2(20);
	it = tab.begin();
	ite = tab.end(); 
	
	tab_2.assign(it, ite);
	ft::vector<int>::iterator	it2 = tab_2.begin();
	ft::vector<int>::iterator	ite2 = tab_2.end();
	for (; it2 != ite2; it2++){
		std::cout << "tab2: " << *it2 << std::endl;
	}

	////////////////////////////////////////////////////////////////////////////////
	
	std::cout << "----INSERT----" << std::endl;;
	ft::vector<int>::iterator	it3 = tab_2.begin();
	ft::vector<int>::iterator	ite3 = tab_2.end();

	tab_2.erase(tab_2.insert(it3, 42));	
	it3 = tab_2.begin();
	ite3 = tab_2.end();
	for (; it3 != ite3; it3++){
		std::cout << *it3 << std::endl;
	}
	

	////////////////////////////////////////////////////////////////////////////////
		
	// std::cout << "----INSERT----" << std::endl;;
	// ft::vector<int>::iterator	it3 = tab_2.begin();
	// ft::vector<int>::iterator	ite3 = tab_2.end();

	// tab_2.insert(it3, 42);	
	// for (; it3 != ite3; it3++){
	// 	std::cout << *it3 << std::endl;
	// }
	
	return (0);
}