/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_traits.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimon <asimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 15:54:10 by asimon            #+#    #+#             */
/*   Updated: 2022/10/15 00:03:36 by asimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ITERATOR_TRAITS_HPP__
# define __ITERATOR_TRAITS_HPP__

namespace ft{

template < typename T >
struct iterator_traits{
	typedef	typename T::difference_type 	difference_type; 	 
	typedef typename T::value_type			value_type;
	typedef typename T::pointer				pointer;			
	typedef typename T::reference			reference;
	typedef T						iterator_category;
};

template < typename T >
struct iterator_traits< const T* >{
	std::ptrdiff_t	difference_type;
	T				value_type;
	const T*		pointer;
	const T&		reference;
};

}

#endif