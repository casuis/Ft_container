/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimon <asimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 00:02:01 by asimon            #+#    #+#             */
/*   Updated: 2022/12/24 16:54:40 by asimon           ###   ########.fr       */
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
		
		private:
			key_type		_key;
			value_type		_value;
			
		public:

			pair(key_type key, value_type value): _key(key), _value(value) {return ;}

			pair(): _key(key_type()), _value(value_type()) {}
			
			template <typename T, typename Y>
			pair(const pair<T, Y> param): _key(param._key), _value(param._value) {return ;}
			
			~pair() {return ;}

			pair&		operator=(const pair& param){
				key_type		tmp = this->_key;
				value_type		tmp2 = this->_value;

				
				if (*this == param)
					return (*this);
				this->_key = param._key;
				this->_value = param._value;
				param._key = tmp;
				param._value = tmp2;
				return (*this);
			}
	};

	
}

#endif