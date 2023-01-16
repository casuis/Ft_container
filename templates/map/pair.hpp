/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimon <asimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 00:02:01 by asimon            #+#    #+#             */
/*   Updated: 2023/01/16 20:36:20 by asimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <header.hpp>

#ifndef __PAIR_HPP__
# define __PAIR_HPP__

namespace ft{
	
	template <typename K, typename V>
	struct pair{
		typedef K			key_type;
		typedef V			value_type;
		
		public:
			key_type		first;
			value_type		second;

			pair(key_type key, value_type value): first(key), second(value) {return ;}

			pair(): first(key_type()), second(value_type()) {}
			
			template <typename T, typename Y>
			pair(const pair<T, Y> param): first(param.first), second(param.second) {return ;}
			
			~pair() {return ;}

			////////////////////////////////////////////////////////////////////////////////
			
			pair&		operator=(const pair& param){
				if (*this == param)
					return (*this);
				this->first = param.first;
				this->second = param.second;
				return (*this);
			}
	};

	template <typename First,  typename Second>
	bool		operator==(const ft::pair<First, Second>& lhs, const ft::pair<First, Second>& rhs){
		return (lhs.first == rhs.first && lhs.second == rhs.second);
	}

}
#endif