/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimon <asimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 16:35:29 by asimon            #+#    #+#             */
/*   Updated: 2022/12/02 17:16:52 by asimon           ###   ########.fr       */
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
	
		stack(){};
		~stack(){};

	////////////////////////////////////////////////////////////////////////////////
	
		bool 	empty() const;

		size_type size() const;

		value_type& top();

		const value_type& top() const;

		void push (const value_type& val);

		template <class... Args> void emplace (Args&&... args);

		void pop();

		void swap (stack& x) noexcept(/*see below*/);

		
		
	private:
		T*	stack;
};

template <class T, class Container>
bool operator== (const stack<T,Container>& lhs, const stack<T,Container>& rhs);

template <class T, class Container>
bool operator!= (const stack<T,Container>& lhs, const stack<T,Container>& rhs);

template <class T, class Container>
bool operator<  (const stack<T,Container>& lhs, const stack<T,Container>& rhs);

template <class T, class Container>
bool operator<= (const stack<T,Container>& lhs, const stack<T,Container>& rhs);

template <class T, class Container>
bool operator>  (const stack<T,Container>& lhs, const stack<T,Container>& rhs);

template <class T, class Container>
bool operator>= (const stack<T,Container>& lhs, const stack<T,Container>& rhs);

template <class T, class Container>
void swap (stack<T,Container>& x, stack<T,Container>& y) noexcept(noexcept(x.swap(y)));

}

#endif