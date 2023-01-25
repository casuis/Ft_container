/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftnspace.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimon <asimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 00:33:50 by asimon            #+#    #+#             */
/*   Updated: 2023/01/25 16:10:16 by asimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FT_NAMESPACE__
# define __FT_NAMESPACE__

# include "./header.hpp"

// # if STD == 1 
// #	define NAMESPACE std
// # else
// #	define NAMESPACE ft
// # endif 


namespace ft{

	template <class InputIterator1, class InputIterator2>
	bool equal (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2)
	{
		while (first1 != last1)
		{
			if (first2 == last2 || *first1 != *first2)
				return false;
			first1++;
			first2++;
		}
		return (first2 == last2);
	}

	template <class InputIterator1, class InputIterator2>
	bool	lexicographical_compare(InputIterator1 first1, InputIterator1 last1,
	InputIterator2 first2, InputIterator2 last2)
	{
		while (first1 != last1)
		{
			if (first2 == last2 || *first2 < *first1)
				return false;
			else if (*first1 < *first2)
				return true;
			++first2;
			++first1;
		}
		return (first2 != last2);
	}
}
# include "../templates/functions/is_integral.hpp"
# include "../templates/functions/enable_if.hpp"
# include "../templates/iterator/iterator_traits.hpp"
# include "../templates/iterator/iterator.hpp"
# include "../templates/iterator/reverse_iterator.hpp" 
// # include <Bst.hpp>
# include "../templates/map/Bst.hpp"
# include "../templates/map/pair.hpp"
# include "../templates/vector/vector.hpp"
# include "../templates/stack/stack.hpp"
# include "../templates/map/map.hpp"
# include "../templates/iterator/iterator_map.hpp"

	
	// void		print(NAMESPACE::vector<int>& tab, std::string msg){
	// 	for (size_t i = 0; i < tab.size(); i++){
	// 		std:: cout <<  GREEN << "| " << RESET;
	// 		std::cout << msg << "[" << GREEN << tab[i] << RESET << "]" << std::endl;
	// 	}
	// 	std::cout << std::endl << "capacity: [" << GREEN << tab.capacity() << RESET << "]"<< std::endl;
	// 	std::cout << std::endl << "size: [" << GREEN << tab.size() << RESET << "]" << std::endl;
	// 	std::cout << std::endl << "max size: [" << GREEN << tab.max_size() << RESET << "]" << std::endl;
	// 	std::cout << GREEN << std::string(42, '-') << RESET << std::endl;
	// }
	
	// void		print( NAMESPACE::vector< NAMESPACE::vector<int> >& tab, std::string msg){
	// 	for (size_t i = 0; i < tab.size(); i++){
	// 		for (size_t j = 0; j < tab.at(i).size(); j++){
	// 			std:: cout <<  GREEN << "| " << RESET;
	// 			std::cout << msg << "[" << GREEN << tab.at(i).at(j) << RESET << "]" << std::endl;
	// 		}
	// 	}
	// 	std::cout << std::endl << "capacity: [" <<  GREEN << tab.capacity() << RESET << "]"<< std::endl;
	// 	std::cout << std::endl << "size: [" << GREEN << tab.size() << RESET << "]" << std::endl;
	// 	std::cout << std::endl << "max size: [" << GREEN << tab.max_size() << RESET << "]" << std::endl;
	// 	std::cout << GREEN << std::string(42, '-') << RESET << std::endl;
	// }
	


#endif