/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimon <asimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 13:34:53 by asimon            #+#    #+#             */
/*   Updated: 2022/10/17 06:37:56 by asimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../private/ftnspace.hpp"
# include <iostream>

class A{};

// template <class Category,  // iterator::iterator_category class T,  // iterator::value_type   class Distance = ptrdiff_t, // iterator::difference_type  ss Pointer = T*,// iterator::pointer  class Reference = T&  // iterator::reference          > class iterator;

int		main(void)
{
	ft::vector<int>					tab(10, 30);

	tab.push_back(100);
	ft::vector<int>::iterator	it = tab.begin();
	ft::vector<int>::iterator	ite = tab.end();
	
	for (; it != ite; it++){
		std::cout << *it << std::endl;
	}
	return (0);
}