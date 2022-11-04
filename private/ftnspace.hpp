/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftnspace.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimon <asimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 00:33:50 by asimon            #+#    #+#             */
/*   Updated: 2022/11/04 20:20:36 by asimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FT_NAMESPACE__
# define __FT_NAMESPACE__

# include <header.hpp>

# if STD == 1 
#	define NAMESPACE std
# else
#	define NAMESPACE ft
# endif 

# include <vector>
# include <is_integral.hpp>
# include <enable_if.hpp>
# include <iterator_traits.hpp>
# include <iterator.hpp>
# include <reverse_iterator.hpp> 
# include <vector.hpp>

namespace ft{
	
	void		print(NAMESPACE::vector<int> tab, std::string msg){
		for (size_t i = 0; i < tab.size(); i++){
			std:: cout << "\t| ";
			std::cout << msg <<  tab[i] << std::endl;
		}
		std::cout << std::string(42, '-') << std::endl;
	}
	
	void		print( NAMESPACE::vector< NAMESPACE::vector<int> > tab, std::string msg){
		for (size_t i = 0; i < tab.size(); i++){
			for (size_t j = 0; j < tab.at(i).size(); j++){
				std:: cout << "\t| ";
				std::cout << msg <<  tab.at(i).at(j) << std::endl;
			}
		}
		std::cout << std::string(42, '-') << std::endl;
	}
	
}

#endif