/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_utils.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimon <asimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 14:20:31 by hbaudet           #+#    #+#             */
/*   Updated: 2022/11/03 18:49:12 by asimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_UTILS_HPP
# define TEST_UTILS_HPP

# include <iostream>
# include <string>
# include <sstream>

# ifdef DEBUG
#  define PRINT 1
#  else
#  define PRINT 0
# endif


namespace ft
{
# ifndef TO_STRING
#  define TO_STRING
	string	to_string(size_t n)
	{
		std::stringstream tmp;

		tmp << n;

		return tmp.str();
	}
	class Ates{
		public:
			Ates(): test(10){return ;}
			~Ates(){return ;}
		private:
			int		test;
	};

}
			
# endif
}

#endif