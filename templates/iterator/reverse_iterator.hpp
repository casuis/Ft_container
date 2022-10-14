/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimon <asimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 19:24:35 by asimon            #+#    #+#             */
/*   Updated: 2022/10/14 06:07:52 by asimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __REVERSE_ITERATOR_HPP__
# define __REVERSE_ITERATOR_HPP__
# include "../../private/header.hpp"
# include "./iterator_traits.hpp"

namespace ft{

	template <typename T>
	class reverse_iterator {
		public:

		/* Member types */
			typedef	std::ptrdiff_t			difference_type; 	 
			typedef T					value_type;
			typedef T*					pointer;		
			typedef const T*			const_pointer;
			typedef T&					reference;
			typedef const T&			const_reference;
			typedef reverse_iterator<T>	iterator_category;

		////////////////////////////////////////////////////////////////////////////////
		/* Liffecycle */

			/* Default constructor */
			reverse_iterator(void): _pointer(0x0) {}

			/* Const Param constructor */
			reverse_iterator(T const * param): _pointer(&param) {}
			
			/* Param constructor */
			reverse_iterator(T * param): _pointer(&param) {}

			/* Copy constructor */
			reverse_iterator(const reverse_iterator<T> &old) : _pointer(old._pointer) {}

			/* Destructor */
			~reverse_iterator() {}

		////////////////////////////////////////////////////////////////////////////////
		/* operators' overload */

			/* operator = */
			reverse_iterator<T>&	operator=(reverse_iterator<T> const &old){
				this->_pointer = old._pointer;
				return (*this);
			}

			/* operator ++ post */
			reverse_iterator<T>&	operator++(){
				this->_pointer += 1;
				return (*this);
			}

			/* operator ++ past */
			reverse_iterator<T>&		operator++(int){
				reverse_iterator<T>		tmp(*this);

				this->_pointer += 1;
				return (tmp);
			}

			/* operator -- post */
			reverse_iterator<T>&		operator--(){
				this->_pointer -= 1;
				return (*this);
			}

			/* operator -- past */
			reverse_iterator<T>&		operator--(int){
				reverse_iterator<T>		tmp(*this);

				this->_pointer -= 1;
				return (tmp);
			}

			/* operator * */
			T&			operator*(){
				return (this->_pointer);
			}
			
		private:
			T*			_pointer;
	};
}

#endif