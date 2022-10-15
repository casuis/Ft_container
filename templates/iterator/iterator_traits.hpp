/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_traits.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimon <asimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 15:54:10 by asimon            #+#    #+#             */
/*   Updated: 2022/10/15 06:07:53 by asimon           ###   ########.fr       */
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
};

template < typename T >
struct iterator_traits< const T* >{
	typedef std::ptrdiff_t	difference_type;
	typedef T				value_type;
	typedef const T*		pointer;
	typedef const T&		reference;
};

}

#endif