/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_map.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimon <asimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 12:14:31 by asimon            #+#    #+#             */
/*   Updated: 2023/01/04 18:31:35 by asimon           ###   ########.fr       */
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
			std::cout << std::endl << CYAN << "------------------BST TEST------------------" << RESET << std::endl << std::endl;
			
			std::cout << CYAN << "=> ADD test: " << RESET << std::endl << std::endl;
			
			ft::Node<int, int>		*node;

			bst.print();
			node = bst.createNode(1, 10);
			bst.addNode(node, bst.root);
			bst.print();
			node = bst.createNode(2, 1);
			bst.addNode(node, bst.root);
			bst.print();
			node = bst.createNode(3, 17);
			bst.addNode(node, bst.root);
			bst.print();
			node = bst.createNode(4, 8);
			bst.addNode(node, bst.root);
			bst.print();
			node = bst.createNode(6, 6);
			bst.addNode(node, bst.root);
			bst.print();
			node = bst.createNode(5, 7);
			bst.addNode(node, bst.root);
			bst.print();
			node = bst.createNode(5, 9);
			bst.addNode(node, bst.root);
			bst.print();
			node = bst.createNode(5, -9);
			bst.addNode(node, bst.root);
			bst.print();
			node = bst.createNode(5, -1);
			bst.addNode(node, bst.root);
			bst.print();
			node = bst.createNode(5, -2);
			bst.addNode(node, bst.root);
			bst.print();
			node = bst.createNode(5, 20);
			bst.addNode(node, bst.root);
			bst.print();
			for (int i = 20, j = 21; i < 50; i++, j++) {
				node = bst.createNode(i, j);
				bst.addNode(node, bst.root);
				bst.print();
			}


			////////////////////////////////////////////////////////////////////////////////
			/* Search */

			ft::Node<int, int>		*tmp_node = bst.searchNode(9, bst.root);

			std::cout << "tmp_node parent: [" << tmp_node->parent->parent->left->pair._value << "]" << std::endl;
				
			std::cout << std::endl << YELLOW << "******************fin de test******************" << RESET << std::endl << std::endl;
		}
		////////////////////////////////////////////////////////////////////////////////
		// {
		// 	std::cout << std::endl << CYAN << "------------------BST TEST------------------" << RESET << std::endl << std::endl;
			
		// 	std::cout << CYAN << "=> SEARCH test: " << RESET << std::endl << std::endl;
			
		// 	ft::Node<int, int>		*tmp;
			
		// 	tmp = bst.searchNode(10, bst.root);
		// 	if (tmp != 0x0)
		// 		std::cout << "print search: [" << tmp->pair._value << "]" << std::endl;
		// 	tmp = bst.searchNode(99, bst.root);
		// 	if (tmp != 0x0)
		// 		std::cout << "print search: [" << tmp->pair._value << "]" << std::endl;
				
				
		// 	std::cout << std::endl << YELLOW << "******************fin de test******************" << RESET << std::endl << std::endl;
		// }
		////////////////////////////////////////////////////////////////////////////////
		{
			std::cout << std::endl << CYAN << "------------------BST TEST------------------" << RESET << std::endl << std::endl;
			
			std::cout << CYAN << "=> DELETE test: " << RESET << std::endl << std::endl;
			
			
			bst.print(1);
			std::cout << "--------------" << std::endl
			<< "Try to delete node 7" << std::endl << std::endl;
			
			bst.deleteNode(7, bst.root);
			bst.print(1);
			
			std::cout << "--------------" << std::endl
			<< "Try to delete node 8" << std::endl << std::endl;
			
			bst.deleteNode(8, bst.root);
			bst.print(1);
			
			std::cout << "--------------" << std::endl
			<< "Try to delete node 10" << std::endl << std::endl;
			
			bst.deleteNode(10, bst.root);
			bst.print();
			std::cout << "value of root: [" << bst.root->pair._value << "]" << std::endl;
			
			bst.deleteNode(28, bst.root);
			bst.print();

			bst.returnBlackNodes();
			bst.print();
			
			
			std::cout << std::endl << YELLOW << "******************fin de test******************" << RESET << std::endl << std::endl;
		}
		////////////////////////////////////////////////////////////////////////////////
		// {
		// 	std::cout << std::endl << CYAN << "------RBT TEST------" << RESET << std::endl << std::endl;
			
		// 	std::cout << CYAN << "=> RBT test: " << RESET << std::endl << std::endl;
			
			
		// 	bst.print(1);
		// 	std::cout  << std::endl << YELLOW << "-------------END OF BST SORTED PRINT-------------" << RESET << std::endl << std::endl;


		// 	bst.addNode(bst.createNode(9 , -4), bst.root);
		// 	bst.addNode(bst.createNode(19 , -40), bst.root);
		// 	bst.addNode(bst.createNode(20 , 400), bst.root);
		// 	bst.addNode(bst.createNode(21 , 500), bst.root);
		// 	bst.addNode(bst.createNode(25 , 42), bst.root);
		// 	bst.addNode(bst.createNode(23 , 5), bst.root);
		// 	bst.print();

		// 	std::cout << "nb b node: [" << bst.returnBlackNodes() << "]" << std::endl; 

		// 	std::cout << std::endl << YELLOW << "******************fin de test******************" << RESET << std::endl << std::endl;
		// }
	}

	return (0);
}