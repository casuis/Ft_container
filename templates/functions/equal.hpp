/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   equal.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimon <asimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 18:29:14 by asimon            #+#    #+#             */
/*   Updated: 2022/10/03 14:03:48 by asimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __EQUAL_HPP__
# define __EQUAL_HPP__
# include "../../private/header.hpp"

namespace ft{

	template <typename It1, typename It2>
	bool	equal(It1 first1, It1 end1, It2 first2)
	{
		while (first1 != end1)
		{
			if (!(*first1 != *first2))
				return false;
			first1++; first2++;
		}
		return true;
	}
}

#endif
