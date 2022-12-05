/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimon <asimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 16:35:29 by asimon            #+#    #+#             */
/*   Updated: 2022/12/05 17:15:29 by asimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __MY_SACK_HPP__
# define __MY_STACK_HPP__
# include "../../private/header.hpp"
# include "../../private/ftnspace.hpp"


namespace ft{
	
template <class T, class Container = ft::vector<T> >
class stack{
	public:
	
	////////////////////////////////////////////////////////////////////////////////
	/*                              Member Type                                   */
	////////////////////////////////////////////////////////////////////////////////
		typedef T				value_type;
		typedef Container		container_type;
		typedef std::size_t		size_type;

	////////////////////////////////////////////////////////////////////////////////
	/*                              Member Functions                              */
	////////////////////////////////////////////////////////////////////////////////
	/* Lifecycle */
	
		/* Default constructor */
		stack() {}

		/* Param Constructor */
		stack(const Container cpy_param): c(cpy_param) {}
		
		~stack() {}

		////////////////////////////////////////////////////////////////////////////////
	
		bool 	empty() const { return (c.empty()); }

		size_type size() const{ return (c.size()); }

		value_type& top() { return (c[c.size()]); }

		const value_type& top() const { return (c[c.size()]); }

		void push (const value_type& val) { c.push_back(val); }

		void pop() { c.pop(); }

		void swap (stack& x) noexcept() { c.swap(x.c); }
		
		////////////////////////////////////////////////////////////////////////////////

		friend bool operator== (const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs){
			return (lhs.c == rhs.c);
		}

		friend bool operator!= (const stack<T,Container>& lhs, const stack<T,Container>& rhs){
			return (lhs.c != rhs.c);
		}

		friend bool operator<  (const stack<T,Container>& lhs, const stack<T,Container>& rhs){
			return (lhs.c < rhs.c);
		}

		friend bool operator<= (const stack<T,Container>& lhs, const stack<T,Container>& rhs){
			return (lhs.c <= rhs.c);
		}

		friend bool operator>  (const stack<T,Container>& lhs, const stack<T,Container>& rhs){
			return (lhs.c > rhs.c);
		}

		friend bool operator>= (const stack<T,Container>& lhs, const stack<T,Container>& rhs){
			return (lhs.c >= rhs.c);
		}

	////////////////////////////////////////////////////////////////////////////////
		
	protected:
		Container		c;
};



}

#endif