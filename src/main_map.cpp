/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_map.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimon <asimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 12:14:31 by asimon            #+#    #+#             */
/*   Updated: 2022/12/29 20:30:54 by asimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ftnspace.hpp>
#include <iostream>
#include <map>

int main(void){

	std::cout << std::endl << YELLOW << "##########MAP##########" << RESET << std::endl << std::endl;
	{
		ft::Bst<int, int>		bst;
		
		////////////////////////////////////////////////////////////////////////////////
		{
			std::cout << std::endl << CYAN << "------BST TEST------" << RESET << std::endl << std::endl;
			
			std::cout << CYAN << "=> ADD test: " << RESET << std::endl << std::endl;
			
			ft::Node<int, int>		*node;

			node = bst.createNode(1, 10);
			bst.addNode(node, bst.root);
			node = bst.createNode(2, 1);
			bst.addNode(node, bst.root);
			node = bst.createNode(3, 17);
			bst.addNode(node, bst.root);
			node = bst.createNode(4, 8);
			bst.addNode(node, bst.root);
			node = bst.createNode(6, 6);
			bst.addNode(node, bst.root);
			node = bst.createNode(5, 7);
			bst.addNode(node, bst.root);
			std::cout << "root : [" << bst.root->pair._value << "]" << std::endl; 
			bst.printBst(bst.root);
				
			std::cout << std::endl << YELLOW << "*****fin de test*****" << RESET << std::endl << std::endl;
		}
		////////////////////////////////////////////////////////////////////////////////
		{
			std::cout << std::endl << CYAN << "------BST TEST------" << RESET << std::endl << std::endl;
			
			std::cout << CYAN << "=> SEARCH test: " << RESET << std::endl << std::endl;
			
			ft::Node<int, int>		*tmp;
			
			tmp = bst.searchNode(105, bst.root);
			if (tmp != 0x0)
				std::cout << "print search: [" << tmp->pair._value << "]" << std::endl;
			tmp = bst.searchNode(99, bst.root);
			if (tmp != 0x0)
				std::cout << "print search: [" << tmp->pair._value << "]" << std::endl;
				
				
			std::cout << std::endl << YELLOW << "*****fin de test*****" << RESET << std::endl << std::endl;
		}
		////////////////////////////////////////////////////////////////////////////////
		{
			std::cout << std::endl << CYAN << "------BST TEST------" << RESET << std::endl << std::endl;
			
			std::cout << CYAN << "=> DELETE test: " << RESET << std::endl << std::endl;
			
			
			bst.printBst(bst.root);
			std::cout << "--------------" << std::endl
			<< "Try to delete node 7" << std::endl << std::endl;
			
			bst.deleteNode(7, bst.root);
			bst.printBst(bst.root);
			
			std::cout << "--------------" << std::endl
			<< "Try to delete node 8" << std::endl << std::endl;
			
			bst.deleteNode(8, bst.root);
			bst.printBst(bst.root);
			
			std::cout << "--------------" << std::endl
			<< "Try to delete node 10" << std::endl << std::endl;
			
			bst.deleteNode(10, bst.root);
			bst.printBst(bst.root);
			std::cout << "value of root: [" << bst.root->pair._value << "]" << std::endl;
			
			
			std::cout << std::endl << YELLOW << "*****fin de test*****" << RESET << std::endl << std::endl;
		}
		////////////////////////////////////////////////////////////////////////////////
		{
			std::cout << std::endl << CYAN << "------RBT TEST------" << RESET << std::endl << std::endl;
			
			std::cout << CYAN << "=> RBT test: " << RESET << std::endl << std::endl;
			
			
			ft::Bst<int, int>		bst;
			

			std::cout << std::endl << YELLOW << "*****fin de test*****" << RESET << std::endl << std::endl;
		}
	}

	return (0);
}