/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_traits.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimon <asimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 15:54:10 by asimon            #+#    #+#             */
/*   Updated: 2022/10/02 16:31:16 by asimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ITERATOR_TRAITS_HPP__
# define __ITERATOR_TRAITS_HPP__

namespace ft{

template <typename T>
struct iterator_traits{
	typedef	T::difference_type 		difference_type; 	 
	typedef T::value_type			value_type;
	typedef T::pointer				pointer;			
	typedef T::reference			reference;
	typedef T						iterator_category;
};

}

#endif