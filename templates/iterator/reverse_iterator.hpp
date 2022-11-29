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
// # include <header.hpp>
# include <../../private/header.hpp>
# include "iterator_traits.hpp"
// # include <iterator_traits.hpp>

namespace ft{

	template <typename T>
	class ReverseIterator {
		public:

		////////////////////////////////////////////////////////////////////////////////
		/*                              Member Type                                   */
		////////////////////////////////////////////////////////////////////////////////
		
			typedef	std::ptrdiff_t						difference_type; 	 
			typedef T									value_type;
			typedef T*									pointer;		
			typedef const T*							const_pointer;
			typedef T&									reference;
			typedef const T&							const_reference;
			typedef	std::random_access_iterator_tag		iterator_category;

		////////////////////////////////////////////////////////////////////////////////
		/*                              Member Function                               */
		////////////////////////////////////////////////////////////////////////////////
		/* Liffecycle */

			/* Default constructor */
			ReverseIterator(void): _pointer(0x0) {}


			/* Iterator constructor */
			ReverseIterator(RandomIterator<T> it): _pointer(&(*it) - 1) {}
			

			// ReverseIterator(const ReverseIterator<T> &old) : _pointer(old._pointer) {}
			ReverseIterator(T* param): _pointer(param) {}

			/* Copy constructor */
			template <class Iter>
			ReverseIterator(const ReverseIterator<Iter>& other): _pointer(&(*other.base()) - 1){}

			/* Destructor */
			~ReverseIterator() {}

			RandomIterator<T>	base() const { return (RandomIterator<T>(this->_pointer + 1));}

		////////////////////////////////////////////////////////////////////////////////
		/* operators' overload */

			/* operator convertion */
			// operator ReverseIterator<const T>(){
			// 	return (ReverseIterator<const T>(this->_pointer));
			// }

			/* operator [] */
			T&			operator[](int n){return (*(this->_pointer - n));}

			/* operator = */
			ReverseIterator<T>	operator=(ReverseIterator<T> const &old){
				this->_pointer = old._pointer;
				return (*this);
			}

			/* operator ++ post */
			ReverseIterator<T>	operator++(){
				this->_pointer -= 1;
				return (*this);
			}

			/* operator ++ past */
			ReverseIterator<T>		operator++(int){
				ReverseIterator<T>		tmp(*this);

				this->_pointer -= 1;
				return (tmp);
			}

			/* operator -- post */
			ReverseIterator<T>		operator--(){
				this->_pointer += 1;
				return (*this);
			}

			/* operator -- past */
			ReverseIterator<T>		operator--(int){
				ReverseIterator<T>		tmp(*this);

				this->_pointer += 1;
				return (tmp);
			}

			/* operator * */
			T&			operator*(){
				return (*(this->_pointer));
			}

			ReverseIterator<T>		operator+(difference_type n){ return (ReverseIterator<T>(this->_pointer - n));}

			ReverseIterator<T>		operator-(difference_type n){ return (ReverseIterator<T>(this->_pointer + n));}

			template <class Iterator>	
			difference_type operator-(const ReverseIterator<Iterator>& rhs)
			{
				return (rhs.base() - this->base());
			}

			ReverseIterator<T>		operator+=(int n) {
				this->_pointer -= n;
				return (ReverseIterator<T>(this->_pointer));
			}

			ReverseIterator<T>		operator-=(int n) {
				this->_pointer += n;
				return (ReverseIterator<T>(this->_pointer));
			}

			pointer					operator->(){return (this->_pointer);}

		private:
			T*			_pointer;

			/* Const Param constructor */
	};

	/* RandomIterator ope != */
	template <typename T1, typename T2>
	bool		operator!=(ReverseIterator<T1> lft, ReverseIterator<T2> rght) {
		return (lft.base() != rght.base());
	}
	
	template <typename T1, typename T2>
	bool		operator==(ReverseIterator<T1> lft, ReverseIterator<T2> rght) {
		return (lft.base() == rght.base());
	}
	
	template <typename T1, typename T2>
	bool		operator<=(ReverseIterator<T1> lft, ReverseIterator<T2> rght) {
		return (lft.base() >= rght.base());
	}
	
	template <typename T1, typename T2>
	bool		operator>=(ReverseIterator<T1> lft, ReverseIterator<T2> rght) {
		return (lft.base() <= rght.base());
	}
	
	template <typename T1, typename T2>
	bool		operator>(ReverseIterator<T1> lft, ReverseIterator<T2> rght) {
		return (lft.base() < rght.base());
	}
	
	template <typename T1, typename T2>
	bool		operator<(ReverseIterator<T1> lft, ReverseIterator<T2> rght) {
		return (lft.base() > rght.base());
	}

	template <typename T2>
	ReverseIterator<T2>		operator+(int lft, ReverseIterator<T2> rght) {
		return (ReverseIterator<T2>(rght - lft));
	}
	
	template <typename T1, typename T2>
	typename ReverseIterator<T1>::difference_type		operator-(const ReverseIterator<T1>& lhs, const ReverseIterator<T2>& rhs){
		return (lhs.base() + rhs.base());
	}	

}

#endif