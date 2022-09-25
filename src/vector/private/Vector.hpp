/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimon <asimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 13:43:46 by asimon            #+#    #+#             */
/*   Updated: 2022/09/25 19:12:38 by asimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __MY_VECTOR_HPP__
# define __MY_VECTOR_HPP__

# include "../../../private/header.hpp"
# include "../../iterator/private/iterator.hpp"

namespace ft
{
	template <class T, class Allocator = std::allocator<T>>
	class vector
	{
		public:
		////////////////////////////////////////////////////////////////////////////////
		/*                              MEMBER TYPE                                   */
		////////////////////////////////////////////////////////////////////////////////
			typedef T							value_type;
			typedef Allocator					allocator_type;
			typedef std::size_t					size_type;
			typedef std::ptrdiff_t				difference_type;
			typedef value_type&					reference;					
			typedef const value_type&			const_reference
			typedef Allocator::pointer			pointer;
			typedef Allocator::const_pointer	const_pointer;
			typedef	random_iterator<T>			iterator; 
		////////////////////////////////////////////////////////////////////////////////
		/*                            MEMBER FUNCTIONS                                */
		////////////////////////////////////////////////////////////////////////////////
		
			vector(void);
			vector(T elem);
			vector(const vector &old);
			vector(size_type count, const T& value, const Allocator &alloc)
			~vector();
			vector&		operator=(const vector &rght);
			void		assign(size_type count, const T& value );

		////////////////////////////////////////////////////////////////////////////////
		private:
			T*			_array;
			size_type	_size;
			size_type	_capacity;	
	};
}

#endif