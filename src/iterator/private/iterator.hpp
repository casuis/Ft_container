/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimon <asimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 18:47:25 by asimon            #+#    #+#             */
/*   Updated: 2022/09/25 18:57:41 by asimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef __MY_ITERATOR_HPP__
# define __MY_ITERATOR_HPP__

# include "../../../private/header.hpp"

namespace ft
{
	template <typename T>
	class random_iterator
	{
		private:
			T		*pointer;
		public:
			iterator(void);
			~iterator();
	}
}

#endif
