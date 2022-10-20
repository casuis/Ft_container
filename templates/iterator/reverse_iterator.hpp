/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ReverseIterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimon <asimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 19:24:35 by asimon            #+#    #+#             */
/*   Updated: 2022/10/14 06:07:52 by asimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __REVERSE_ITERATOR_HPP__
# define __REVERSE_ITERATOR_HPP__
# include <header.hpp>
# include <iterator_traits.hpp>

namespace ft{

	template <typename T>
	class ReverseIterator {
		public:

		////////////////////////////////////////////////////////////////////////////////
		/*                              Member Type                                   */
		////////////////////////////////////////////////////////////////////////////////
		
			typedef	std::ptrdiff_t			difference_type; 	 
			typedef T					value_type;
			typedef T*					pointer;		
			typedef const T*			const_pointer;
			typedef T&					reference;
			typedef const T&			const_reference;

		////////////////////////////////////////////////////////////////////////////////
		/*                              Member Function                               */
		////////////////////////////////////////////////////////////////////////////////
		/* Liffecycle */

			/* Default constructor */
			ReverseIterator(void): _pointer(0x0) {}

			/* Const Param constructor */
			ReverseIterator(T const * param): _pointer(&param) {}
			
			/* Param constructor */
			ReverseIterator(T * param): _pointer(&param) {}

			/* Copy constructor */
			ReverseIterator(const ReverseIterator<T> &old) : _pointer(old._pointer) {}

			/* Destructor */
			~ReverseIterator() {}

		////////////////////////////////////////////////////////////////////////////////
		/* operators' overload */

			/* operator convertion */
			operator ReverseIterator<const T>(){
				return (ReverseIterator<const T>(this->_pointer));
			}

			/* operator = */
			ReverseIterator<T>&	operator=(ReverseIterator<T> const &old){
				this->_pointer = old._pointer;
				return (*this);
			}

			/* operator ++ post */
			ReverseIterator<T>&	operator++(){
				this->_pointer -= 1;
				return (*this);
			}

			/* operator ++ past */
			ReverseIterator<T>&		operator++(int){
				ReverseIterator<T>		tmp(*this);

				this->_pointer -= 1;
				return (tmp);
			}

			/* operator -- post */
			ReverseIterator<T>&		operator--(){
				this->_pointer += 1;
				return (*this);
			}

			/* operator -- past */
			ReverseIterator<T>&		operator--(int){
				ReverseIterator<T>		tmp(*this);

				this->_pointer += 1;
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