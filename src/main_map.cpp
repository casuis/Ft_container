/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_map.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimon <asimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 12:14:31 by asimon            #+#    #+#             */
/*   Updated: 2022/12/26 18:57:04 by asimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ftnspace.hpp>
#include <iostream>
#include <map>

int main(void){

	std::cout << std::endl << YELLOW << "##########MAP##########" << RESET << std::endl << std::endl;
	{	
		ft::Bst<int, int>		bst;
		ft::Node<int, int>		*tmp;
		ft::Node<int, int>		first_node(1, 100);
		ft::Node<int, int>		second_node(2, 99);
		ft::Node<int, int>		third_node(3, 105);
		ft::Node<int, int>		fourth_node(4, 103);
		
		bst.addNode(first_node, *bst.root);
		std::cout << "value root: [" << bst.root->pair._value << "]" << std::endl; 
		bst.addNode(second_node, *bst.root);
		bst.addNode(third_node, *bst.root);
		bst.addNode(fourth_node, *bst.root);
		bst.printBst(*(bst.root));
		tmp = bst.searchNode(105, *(bst.root));
		if (tmp != 0x0)
			std::cout << "print search: [" << tmp->pair._value << "]" << std::endl;
		tmp = bst.searchNode(99, *(bst.root));
		if (tmp != 0x0)
			std::cout << "print search: [" << tmp->pair._value << "]" << std::endl;

		bst.printBst(*(bst.root));
		std::cout << "--------------" << std::endl;
		bst.deleteNode(99, *(bst.root));
		std::cout << "--------------" << std::endl;
		bst.printBst(*(bst.root));
		std::cout << "--------------" << std::endl;
		bst.deleteNode(108, *(bst.root));
		bst.printBst(*(bst.root));
		std::cout << "--------------" << std::endl;
		bst.deleteNode(103, *(bst.root));
		bst.printBst(*(bst.root));
		std::cout << "--------------" << std::endl;
	}
	std::cout << std::endl << YELLOW << "*****fin de test*****" << RESET << std::endl << std::endl;

	return (0);
}