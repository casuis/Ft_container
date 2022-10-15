/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimon <asimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 13:34:53 by asimon            #+#    #+#             */
/*   Updated: 2022/10/15 06:33:37 by asimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../private/ftnspace.hpp"
# include <iostream>
# include <vector>
# include <iterator>
# include <string>

class A{};

// template <class Category,  // iterator::iterator_category class T,  // iterator::value_type   class Distance = ptrdiff_t, // iterator::difference_type  ss Pointer = T*,// iterator::pointer  class Reference = T&  // iterator::reference          > class iterator;

int		main(int ac, char **av)
{
	ft::vector<int>				tab(10);
	ft::vector<int>::iterator	it = tab.begin();
	ft::vector<int>::iterator	ite = tab.end();
	ft::vector<int>				tab2(it, ite);

	for (; it != ite; it++){
		std::cout << *it << std::endl;
	}
	return (0);
}