/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_stack.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimon <asimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 18:30:36 by asimon            #+#    #+#             */
/*   Updated: 2023/01/30 20:30:07 by asimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <ftnspace.hpp>
# include <iostream>

int		main(void){
	
	////////////////////////////////////////////////////////////////////////////////
	/*                              STACK                                        */
	////////////////////////////////////////////////////////////////////////////////

	std::cout << std::endl << YELLOW << "##########STACK##########" << RESET << std::endl << std::endl;
	
	////////////////////////////////////////////////////////////////////////////////
	{
		
		std::cout << std::endl << YELLOW << "*****fin de test*****" << RESET << std::endl << std::endl;

		{
			NAMESPACE::stack<int> a, b, c;
			a.push(10);
			a.push(20);
			a.push(30);

			b.push(10);
			b.push(20);
			b.push(30);

			c.push(30);
			c.push(20);
			c.push(10);

			if (a==b) std::cout << "a and b are equal\n";
			if (b!=c) std::cout << "b and c are not equal\n";
			if (b<c) std::cout << "b is less than c\n";
			if (c>b) std::cout << "c is greater than b\n";
			if (a<=b) std::cout << "a is less than or equal to b\n";
			if (a>=b) std::cout << "a is greater than or equal to b\n";

		}
	}
	return (0);
}