/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   equal.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimon <asimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 18:29:14 by asimon            #+#    #+#             */
/*   Updated: 2023/02/21 22:58:42 by asimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __EQUAL_HPP__
# define __EQUAL_HPP__

// # include <header.hpp>
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

	template <class InputIterator1, class InputIterator2>
	bool equal (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2)
	{
		while (first1 != last1)
		{
			if (first2 == last2 || *first1 != *first2)
				return false;
			first1++;
			first2++;
		}
		return (first2 == last2);
	}

	template <class InputIterator1, class InputIterator2>
	bool	lexicographical_compare(InputIterator1 first1, InputIterator1 last1,
	InputIterator2 first2, InputIterator2 last2)
	{
		while (first1 != last1)
		{
			if (first2 == last2 || *first2 < *first1)
				return false;
			else if (*first1 < *first2)
				return true;
			++first2;
			++first1;
		}
		return (first2 != last2);
	}
}

#endif
