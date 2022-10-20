/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimon <asimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 18:47:25 by asimon            #+#    #+#             */
/*   Updated: 2022/10/20 15:39:36 by asimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __MY_ITERATOR_HPP__
# define __MY_ITERATOR_HPP__

# include <header.hpp>
# include <iterator_traits.hpp>

namespace ft{

	template <typename T = void>
	class RandomIterator;

	template <typename T>
	class RandomIterator
	{
		private:
			T			*_pointer;
		public:
		////////////////////////////////////////////////////////////////////////////////
		/*                              Member Type                                   */
		////////////////////////////////////////////////////////////////////////////////
		

			typedef std::ptrdiff_t		difference_type; 	 
			typedef T					value_type;
			typedef T*					pointer;			
			typedef const T*			const_pointer;
			typedef T&					reference;
			typedef const T&			const_reference;

		////////////////////////////////////////////////////////////////////////////////
		/*                              Member Function                               */
		////////////////////////////////////////////////////////////////////////////////
		/* Lifecycle */
		
			/* Default constructor */
			RandomIterator(void): _pointer(0x0) {}

			/* Param constructor */
			RandomIterator(pointer param): _pointer(param) {}
			
			/* Copy constructor */
			RandomIterator( const RandomIterator& old): _pointer(old._pointer){}

			~RandomIterator() {};

		////////////////////////////////////////////////////////////////////////////////
		/*                              Operators' overload                           */
		////////////////////////////////////////////////////////////////////////////////
		
			/* conv overload */
			operator RandomIterator<const T>() const{
				return (RandomIterator<const T>(this->_pointer));
			}

			////////////////////////////////////////////////////////////////////////////////
			/* Shift operators */
			
			/* random_access_ite ++ post */
			RandomIterator<T>&	operator++(){
				this->_pointer = (this->_pointer) + 1;
				return (*this);
			}

			/* random_access_ite ++ past */
			RandomIterator<T>	operator++(int){
				RandomIterator<T>	tmp(*this);
				
				this->_pointer = (this->_pointer) + 1;
				return (tmp);
			}

			/* random_access_ite --post */
			RandomIterator<T>& operator--(){
				this->_pointer = (this->_pointer) - 1;
				return (*this);
			}

			/* random_access_ite --past */
			RandomIterator<T> operator--(int){
				RandomIterator<T>	tmp(*this);

				this->_pointer = (this->_pointer) - 1;
				return (tmp);
			}

			////////////////////////////////////////////////////////////////////////////////
			/* Arithmetic operators */
			/* NEED TO DO MORE OPERATION (ite + n, n + it, it += n ...) */

			/* operator - */
			RandomIterator<T>		operator-(int n){
				return (this->_pointer - n);
			}

			/* operator + */
			RandomIterator<T>		operator+(int n){
				return (this->_pointer + n);
			}
			
			/* random_access_ite ope dereference */
			T&			operator*(){
				return (*(this->_pointer));
			}

			/* random_access_ite operator =  */
			RandomIterator<T>&	operator=(const RandomIterator &rgt) {
				this->_pointer = rgt._pointer;
				return (*this);
			}
			
			////////////////////////////////////////////////////////////////////////////////
			/* Comparison operators */
			
			/* RandomIterator ope != */
			bool		operator!=(const RandomIterator& rght) const {
				return (this->_pointer != rght._pointer);
			}

			/* RandomIterator ope == */
			bool		operator==(const RandomIterator& rght) const {
				return (this->_pointer == rght._pointer);
			}

			/* RandomIterator ope > */
			bool		operator>(const RandomIterator& rght) const {
				return (this->_pointer > rght._pointer);
			}

			/* RandomIterator ope >= */
			bool		operator>=(const RandomIterator& rght) const {
				return (this->_pointer >= rght._pointer);
			}

			/* RandomIterator ope < */
			bool		operator<(const RandomIterator& rght) const {
				return (this->_pointer < rght._pointer);
			}
			
			/* RandomIterator ope <= */
			bool		operator<=(const RandomIterator& rght) const {
				return (this->_pointer <= rght._pointer);
			}
	};
}

#endif
