/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimon <asimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 00:02:01 by asimon            #+#    #+#             */
/*   Updated: 2023/01/11 16:56:58 by asimon           ###   ########.fr       */
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
			key_type		_key;
			value_type		_value;

			pair(key_type key, value_type value): _key(key), _value(value) {return ;}

			pair(): _key(key_type()), _value(value_type()) {}
			
			template <typename T, typename Y>
			pair(const pair<T, Y> param): _key(param._key), _value(param._value) {return ;}
			
			~pair() {return ;}

			////////////////////////////////////////////////////////////////////////////////
			
			pair&		operator=(const pair& param){
				if (*this == param)
					return (*this);
				this->_key = param._key;
				this->_value = param._value;
				return (*this);
			}
	};

	template <typename First,  typename Second>
	bool		operator==(const ft::pair<First, Second>& lhs, const ft::pair<First, Second>& rhs){
		return (lhs._key == rhs._key && lhs._value == rhs._value);
	}

}
#endif