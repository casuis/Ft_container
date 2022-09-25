/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimon <asimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 18:06:53 by asimon            #+#    #+#             */
/*   Updated: 2022/09/25 19:06:52 by asimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../private/Vector.hpp"

namespace ft
{
	template <typename T>
	vector::vector(void): _size(0), _capacity(0), _array(nullptr)	
	{
		return ;
	}
}