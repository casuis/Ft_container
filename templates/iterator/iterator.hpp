/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimon <asimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 18:47:25 by asimon            #+#    #+#             */
/*   Updated: 2022/10/02 17:55:36 by asimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef __MY_ITERATOR_HPP__
# define __MY_ITERATOR_HPP__

# include "../../private/header.hpp"

namespace ft{

	template <typename T>
	class random_access_iterator;

	template <typename T>
	class random_access_iterator
	{
		private:
			T			*_pointer;
		public:
		/* Member Type */
		
			typedef	ptrdiff_t 				difference_type; 	 
			typedef T						value_type;
			typedef T*						pointer;			
			typedef T&						reference;	
			typedef random_access_iterator	iterator;
		
		////////////////////////////////////////////////////////////////////////////////
		/* Constructors/Destructor */
		
			/* Default constructor */
			iterator(void): _pointer(void) {}

			/* Copy constructor */
			iterator(const iterator& old): _pointer(old.pointer){}
			~iterator();

		////////////////////////////////////////////////////////////////////////////////
		/* operators' overload */
		
			/* random_access_ite operator =  */
			iterator&	operator=(const iterator &rgt) {
				this->_pointer = rgt._pointer;
				return ;
			}

			/* random_access_ite ++ post */
			iterator&	operator++(){
				this->_pointer = (this->_pointer) + 1;
				return ;
			}

			/* random_access_ite ++ past */
			iterator&	operator++(int){
				iterator	tmp(*this);
				
				this->_pointer = (this->_pointer) + 1;
				return (tmp);
			}

			/* random_access_ite ope dereference */
			T&			operator*(){
				return (*(this->_pointer));
			}
	};
}

#endif
