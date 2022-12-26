/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_map.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimon <asimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 12:14:31 by asimon            #+#    #+#             */
/*   Updated: 2022/12/26 14:23:47 by asimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ftnspace.hpp>
#include <iostream>
#include <map>

int main(void){

	std::cout << std::endl << YELLOW << "##########MAP##########" << RESET << std::endl << std::endl;
	{	
		ft::Bst<int, int>		bst;
		ft::Node<int, int>		first_node(1, 100);
		ft::Node<int, int>		second_node(2, 99);
		ft::Node<int, int>		third_node(3, 105);
		ft::Node<int, int>		fourth_node(4, 103);
		
		bst.addNode(first_node);
	}
	std::cout << std::endl << YELLOW << "*****fin de test*****" << RESET << std::endl << std::endl;

	return (0);
}