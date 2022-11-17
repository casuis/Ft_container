/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimon <asimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 18:47:25 by asimon            #+#    #+#             */
/*   Updated: 2022/11/17 16:22:20 by asimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __MY_ITERATOR_HPP__
# define __MY_ITERATOR_HPP__

// # include <header.hpp>
# include "iterator_traits.hpp"
# include <../../private/header.hpp>
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
		

			typedef std::ptrdiff_t						difference_type; 	 
			typedef T									value_type;
			typedef T*									pointer;			
			typedef const T*							const_pointer;
			typedef T&									reference;
			typedef const T&							const_reference;
			typedef	std::random_access_iterator_tag		iterator_category;


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

			pointer		base(){ return (this->_pointer);}

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
				return (RandomIterator<T>(this->_pointer - n));
			}

			int						operator-(RandomIterator<T> it) const {
				return (this->_pointer - it._pointer);
			}
			
			/* operator + */
			RandomIterator<T>		operator+(int n){
				return (RandomIterator<T>(this->_pointer + n));
			}

			RandomIterator<T>		operator+=(int n){
				this->_pointer += n;
				return (this->_pointer);
			}
			
			RandomIterator<T>		operator-=(int n){
				this->_pointer -= n;
				return (this->_pointer);
			}
			
			/* random_access_ite ope dereference */
			T&			operator*() const {
				return (*(this->_pointer));
			}

			T&			operator[](int i){ return this->_pointer[i];}

			/* random_access_ite operator =  */
			RandomIterator<T>&	operator=(const RandomIterator<T> &rgt) {
				this->_pointer = rgt._pointer;
				return (*this);
			}

			pointer	operator->(){return (this->_pointer);}

	};
	
	////////////////////////////////////////////////////////////////////////////////
	
	/* Comparison operators */
	
	/* RandomIterator ope != */
	template <typename T1, typename Iter>
	bool		operator!=(RandomIterator<T1> lft, Iter rght) {
		return (&(*lft) != &(*rght));
	}
	
	template <typename T1, typename Iter>
	bool		operator==(RandomIterator<T1> lft, Iter rght) {
		return (&(*lft) == &(*rght));
	}
	
	template <typename T1, typename Iter>
	bool		operator<=(RandomIterator<T1> lft, Iter rght) {
		return (&(*lft) <= &(*rght));
	}
	
	template <typename T1, typename Iter>
	bool		operator>=(RandomIterator<T1> lft, Iter rght) {
		return (&(*lft) >= &(*rght));
	}
	
	template <typename T1, typename Iter>
	bool		operator>(RandomIterator<T1> lft, Iter rght) {
		return (&(*lft) > &(*rght));
	}
	
	template <typename T1, typename Iter>
	bool		operator<(RandomIterator<T1> lft, Iter rght) {
		return (&(*lft) < &(*rght));
	}

	template<typename T1>
	RandomIterator<T1> operator+(int i, RandomIterator<T1> it){
		return (RandomIterator<T1>(it + i));
	}
	
	template<typename T1>
	RandomIterator<T1> operator-(int i, RandomIterator<T1> it){
		return (RandomIterator<T1>(it - i));
	}
}

#endif
