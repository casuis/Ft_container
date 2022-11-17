/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftnspace.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimon <asimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 00:33:50 by asimon            #+#    #+#             */
/*   Updated: 2022/11/17 15:31:34 by asimon           ###   ########.fr       */
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


# define YELLOW "\033[1;33m"
# define GREEN	"\033[1;32m"
# define RED	"\033[1;31m"
# define BLACK	"\033[1;30m"
# define CYAN	"\033[1;36m"
# define RESET	"\033[0m"

namespace ft{
	
	void		print(NAMESPACE::vector<int> tab, std::string msg){
		for (size_t i = 0; i < tab.size(); i++){
			std:: cout <<  GREEN << "| " << RESET;
			std::cout << msg << "[" << GREEN << tab[i] << RESET << "]" << std::endl;
		}
		std::cout << std::endl << "capacity: [" << GREEN << tab.capacity() << RESET << "]"<< std::endl;
		std::cout << std::endl << "size: [" << GREEN << tab.size() << RESET << "]" << std::endl;
		std::cout << std::endl << "max size: [" << GREEN << tab.max_size() << RESET << "]" << std::endl;
		std::cout << GREEN << std::string(42, '-') << RESET << std::endl;
	}
	
	void		print( NAMESPACE::vector< NAMESPACE::vector<int> > tab, std::string msg){
		for (size_t i = 0; i < tab.size(); i++){
			for (size_t j = 0; j < tab.at(i).size(); j++){
				std:: cout <<  GREEN << "| " << RESET;
				std::cout << msg << "[" << GREEN << tab.at(i).at(j) << RESET << "]" << std::endl;
			}
		}
		std::cout << std::endl << "capacity: [" <<  GREEN << tab.capacity() << RESET << "]"<< std::endl;
		std::cout << std::endl << "size: [" << GREEN << tab.size() << RESET << "]" << std::endl;
		std::cout << std::endl << "max size: [" << GREEN << tab.max_size() << RESET << "]" << std::endl;
		std::cout << GREEN << std::string(42, '-') << RESET << std::endl;
	}
	
	template <class base_it>
	class	input_iterator
	{
			base_it	it;
			bool	valid;
		public:
			typedef typename std::iterator_traits<base_it>::value_type value_type;
			typedef typename std::iterator_traits<base_it>::pointer pointer;
			typedef typename std::iterator_traits<base_it>::reference reference;
			typedef typename std::iterator_traits<base_it>::difference_type difference_type;
			typedef typename std::input_iterator_tag iterator_category;
	};

	template <typename T>
	void test_p(typename enable_if<!is_integral<typename ft::iterator_traits<T>::value_type> ::value, typename ft::iterator_traits<T>::value_type >::type last){
		std::cout << "yes" << std::endl;
		std::cout << last << std::endl;
	}

	void	test_p(size_t test){
		std::cout << "no" << std::endl;
		std::cout << test << std::endl;
	}

	class NullPtr
	{
		public:
			template <class T>
			operator T*() const { return (0); }
			template <class C, class T>
			operator T* C::*() const { return (0); }
		private:
			void operator&() const;
	} NullPtr = {};
}

#endif