/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimon <asimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 13:34:53 by asimon            #+#    #+#             */
/*   Updated: 2022/10/08 23:56:47 by asimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../templates/functions/is_integral.hpp"
# include "../templates/functions/enable_if.hpp"
# include "../templates/iterator/iterator_traits.hpp"
# include "../templates/iterator/iterator.hpp"
# include <iostream>
# include <vector>
# include <iterator>
# include <string>

class A{};

// template <class Category,  // iterator::iterator_category class T,  // iterator::value_type   class Distance = ptrdiff_t, // iterator::difference_type  ss Pointer = T*,// iterator::pointer  class Reference = T&  // iterator::reference          > class iterator;

int		main(int ac, char **av)
{
	// int		*tab = new int [10];
	std::vector<int>			tab;

	// for (int i = 0; i < 10; i++){
	// 	tab[i] = 100 - i;
	// }

	std::cout << "max:  " << tab.max_size() << std::endl;

	return (0);
}