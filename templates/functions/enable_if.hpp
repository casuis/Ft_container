/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enable_if.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimon <asimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 15:33:35 by asimon            #+#    #+#             */
/*   Updated: 2022/10/20 15:38:28 by asimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ENABLE_IF__
# define __ENABLE_IF__
# include <header.hpp>

namespace ft{
	
/* default */
template <bool B, class T = void>
struct enable_if {};

/* right */
template <class C>
struct enable_if<true, C> {typedef C type;};

}

#endif