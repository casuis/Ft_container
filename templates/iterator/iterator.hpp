/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimon <asimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 18:47:25 by asimon            #+#    #+#             */
/*   Updated: 2022/10/08 21:48:13 by asimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef __MY_ITERATOR_HPP__
# define __MY_ITERATOR_HPP__

# include "../../private/header.hpp"
# include "./iterator_traits.hpp"

namespace ft{

	template <typename T = void>
	class random_access_iterator;

	template <typename T>
	class random_access_iterator
	{
		private:
			T			*_pointer;
		public:
		/* Member Type */

			typedef ptrdiff_t		difference_type; 	 
			typedef T				value_type;
			typedef T*				pointer;			
			typedef const T*		const_pointer;
			typedef T&				reference;
			typedef const T&		const_reference;
			typedef random_access_iterator	iterator_category;


		////////////////////////////////////////////////////////////////////////////////
		/* Lifecycle */
		
			/* Default constructor */
			random_access_iterator(void): _pointer(nullptr) {}

			/* Param constructor */
			random_access_iterator(T *param): _pointer(param) {}
			
			/* Const Param constructor */
			random_access_iterator(T const *param): _pointer(param) {}

			/* Copy constructor */
			random_access_iterator(const random_access_iterator& old): _pointer(old._pointer){}
			
			~random_access_iterator() {};

		////////////////////////////////////////////////////////////////////////////////
		/* Operators' overload */
		
			/* random_access_ite operator =  */
			random_access_iterator<T>&	operator=(const random_access_iterator &rgt) {
				this->_pointer = rgt._pointer;
				return (*this);
			}

			/* random_access_ite ++ post */
			random_access_iterator<T>&	operator++(){
				this->_pointer = (this->_pointer) + 1;
				return (*this);
			}

			/* random_access_ite ++ past */
			random_access_iterator<T>	operator++(int){
				random_access_iterator<T>	tmp(*this);
				
				this->_pointer = (this->_pointer) + 1;
				return (tmp);
			}

			/* random_access_ite --post */
			random_access_iterator<T>& operator--(){
				this->_pointer -= 1;
				return (*this);
			}

			/* random_access_ite --past */
			random_access_iterator<T> operator--(int){
				random_access_iterator<T>	tmp(*this);

				this->_pointer -= 1;
				return (tmp);
			}

			/* random_access_ite ope dereference */
			T&			operator*(){
				return (*(this->_pointer));
			}

			/* random_access_iterator ope != */
			bool		operator!=(const random_access_iterator& rght){
				return (this->_pointer != rght._pointer);
			}

			/* random_access_iterator ope == */
			bool		operator==(const random_access_iterator& rght){
				return (this->_pointer == rght->_pointer);
			}

			/* random_access_iterator ope > */
			bool		operator>(const random_access_iterator& rght){
				return (this->_pointer > rght->_pointer);
			}

			/* random_access_iterator ope >= */
			bool		operator>=(const random_access_iterator& rght){
				return (this->_pointer >= rght->_pointer);
			}

			/* random_access_iterator ope < */
			bool		operator<(const random_access_iterator& rght){
				return (this->_pointer < rght->_pointer);
			}
			
			/* random_access_iterator ope <= */
			bool		operator<=(const random_access_iterator& rght){
				return (this->_pointer <= rght->_pointer);
			}
	};
}

#endif
