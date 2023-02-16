/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimon <asimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 16:35:29 by asimon            #+#    #+#             */
/*   Updated: 2023/02/16 17:13:54 by asimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __MY_STACK_HPP__
# define __MY_STACK_HPP__

/* Comment her for tester */
# include "../../private/ftnspace.hpp"

/* Decomment her for tester */
// # include "../../private/ftnspace.hpp"

namespace ft{
	
	template <class T, class Container>
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

			value_type& top() { return (*(c.rbegin())); }

			const value_type& top() const { return (*(c.rbegin())); }

			void push (const value_type& val) { c.push_back(val); }

			void pop() { c.pop_back(); }

			void swap (stack& x) { c.swap(x.c); }
			
			////////////////////////////////////////////////////////////////////////////////

			friend bool operator== (const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs) {
				return (lhs.c == rhs.c);
			}

			friend bool operator!= (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
				return (lhs.c != rhs.c);
			}

			friend bool operator<  (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
				return (lhs.c < rhs.c);
			}

			friend bool operator<= (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
				return (lhs.c <= rhs.c);
			}

			friend bool operator>  (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
				return (lhs.c > rhs.c);
			}

			friend bool operator>= (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
				return (lhs.c >= rhs.c);
			}

		////////////////////////////////////////////////////////////////////////////////
			
		protected:
			container_type		c;
	};

}

#endif