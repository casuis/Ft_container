/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bst.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimon <asimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 13:38:49 by asimon            #+#    #+#             */
/*   Updated: 2023/01/04 18:30:06 by asimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.hpp>

namespace ft{
	
	template <typename Key, typename Value>
	class Node;

	template <typename Key, typename Value, typename NodeType = ft::Node<Key, Value>, class Allocator = std::allocator<NodeType> >
	class Bst;

	template <typename Key, typename Value>
	class NodeSentinel;


	////////////////////////////////////////////////////////////////////////////////
	

	template <typename Key, typename Value>
	class Node
	{
		friend 	class ft::Bst<Key, Value>;

		public:
		////////////////////////////////////////////////////////////////////////////////
		/*                              Attributs                                     */
		////////////////////////////////////////////////////////////////////////////////
			Node*		left;
			Node*		right;
			Node*		parent;
			
			ft::pair<Key, Value>		pair;
			size_t						size;
			bool						black;
			bool						isLeftChild;

			bool						sentinel;
		
		////////////////////////////////////////////////////////////////////////////////
		/*                              Functions                                     */
		////////////////////////////////////////////////////////////////////////////////
		
			Node(Key key, Value value){
				ft::pair<Key, Value>		tmp(key, value);		
				
				this->parent = 0x0;
				this->left = 0x0;
				this->right = 0x0;
				this->pair = tmp;
				this->black = false;
				this->isLeftChild = false;
				this->sentinel = false;
				this->size = 0;
				return ;
			};
			
			Node(){
				ft::pair<Key, Value>		tmp;
				this->parent = 0x0;
				this->pair = tmp;
				this->left = 0x0;
				this->right = 0x0;
				this->black = true;
				this->isLeftChild = false;
				this->sentinel = true;
				this->size = 0;
			};
			
			~Node() {};
	};
	
	template <typename Key, typename Value, typename NodeType, class Allocator>
	class Bst
	{
		// friend			ft::map;
		
		public:
		////////////////////////////////////////////////////////////////////////////////
		/*                              Member Type                                   */
		////////////////////////////////////////////////////////////////////////////////
		
			typedef Allocator				allocator_type;
			typedef Key						key_type;
			typedef Value					value_type;
			typedef Key*					key_pointer;
			typedef Value*					value_pointer;
			typedef Node<Key, Value>		node;			
			
		// private:
		////////////////////////////////////////////////////////////////////////////////
		/*                              Attributs                                     */
		////////////////////////////////////////////////////////////////////////////////
		
			Allocator							_alloc;
			Node<Key, Value>					*root;
			Node<Key, Value>					*sentinel;
			
		////////////////////////////////////////////////////////////////////////////////
		/*                              Constructors                                  */
		////////////////////////////////////////////////////////////////////////////////
		
			Bst(const allocator_type& alloc = allocator_type()): _alloc(alloc), root(0x0) {
				sentinel = this->_alloc.allocate(1);;
				_alloc.construct(sentinel, Node<Key, Value>());
				return ;
			};
			
			~Bst() {
				_alloc.destroy(sentinel);
				_alloc.deallocate(sentinel, 1);
			};

		////////////////////////////////////////////////////////////////////////////////
		/*                              Methodes                                      */
		////////////////////////////////////////////////////////////////////////////////
		/* Add section */
			void	addNode(node *newNode, node *pos) {
				if (root == 0x0){
					root = newNode;
					this->sentinel->left = root;
					this->root->parent = this->sentinel;
					this->root->left = sentinel;
					this->root->right = sentinel;
					this->root->black = true;
					return ;
				}
				else{
					if (newNode->pair._value == pos->pair._value)
						return ;
					if (newNode->pair._value < pos->pair._value && pos->left == sentinel){
						pos->left = newNode;
						newNode->parent = pos;
						newNode->isLeftChild = true;
						newNode->left = sentinel;
						newNode->right = sentinel;
						sentinel->size += 1;
					}
					else if (newNode->pair._value < pos->pair._value && !pos->left->sentinel){
						newNode->size += 1;
						addNode(newNode, pos->left);
					}
					else if (newNode->pair._value > pos->pair._value && pos->right->sentinel){
						pos->right = newNode;
						newNode->parent = pos;
						newNode->isLeftChild = false;
						newNode->left = sentinel;
						newNode->right = sentinel;
						sentinel->size += 1;
					}
					else {
						newNode->size += 1;
						addNode(newNode, pos->right);
					}
					checkColor(newNode);
					returnBlackNodes();
				}
				return ;
			};

			node*		createNode(key_type key, value_type value) {
				node	*newNode;

				newNode = this->_alloc.allocate(1);
				this->_alloc.construct(newNode, node(key, value));
				return (newNode);
			}

			////////////////////////////////////////////////////////////////////////////////
			/* Search section */
	

			node*		searchNode(const value_type& value, node* pos){
				if (root == 0x0){
					std::cerr << "BST is empty" << std::endl;
					return (0x0);
				}
				if (pos->sentinel == true){
					std::cerr << "not in BST" << std::endl;
					return (0x0);
				}
				if (value < pos->pair._value)
					return (searchNode(value, pos->left));
				if (value > pos->pair._value)
					return (searchNode(value, pos->right));
				if (value == pos->pair._value)
					return (pos);
				return (0x0);
			}

			////////////////////////////////////////////////////////////////////////////////
			/* Delete section */			
			
			void		deleteNode(const value_type& value, node *pos){
				node								*swap_node;
				ft::pair<key_type, value_type>		tmp;
				
				if (value < pos->pair._value && !pos->left->sentinel ) {
					deleteNode(value, pos->left);
					return ;
				}
				else if (value > pos->pair._value && !pos->right->sentinel) {
					deleteNode(value, pos->right);
					return ;
				}
				else if (pos->pair._value == value) {
					if (pos->right->sentinel && pos->left->sentinel){
						deleteLeaf(pos);
						return ;
					}
					swap_node = returnSuccessor(pos);
					if (swap_node->sentinel)
						swap_node = returnPrecessor(pos);
					tmp = pos->pair;
					pos->pair = swap_node->pair;
					swap_node->pair = tmp;
					deleteLeaf(swap_node);
				}
				returnBlackNodes();
				return ;
			}

			void		deleteLeaf(node *pos) {
				if (pos == root)
					this->root = 0x0;
					
				else if (pos->isLeftChild)
					pos->parent->left = pos->left;
				else if (!pos->isLeftChild)
					pos->parent->right = pos->right;
				this->_alloc.destroy(pos);
				this->_alloc.deallocate(pos, 1);
				sentinel->size -= 1;
			}
			
			node*		returnSuccessor(node *pos) {
				node		*ret;
				if (pos->left->sentinel)
					return (pos->left);
				else {
					ret = pos->left;
					while (!ret->right->sentinel) // look for the largest node less than pos
						ret = ret->right;
					return (ret);
				}
				return (this->root->parent);
			}

			node*		returnPrecessor(node *pos) {
				node		*ret;
				if (pos->right->sentinel)
					return (pos->left);
				else {
					ret = pos->right;
					while (!ret->left->sentinel) // look for the smalest node greater than pos
						ret = ret->left;
					return (ret);
				}
				return (this->root->parent);
			}

			////////////////////////////////////////////////////////////////////////////////
			/* Rotations */

			node*		leftRotation(node *pos) {
				node		*ret = pos->right;
				node		*tmp = pos->parent;
				
				/* Rotate */
				pos->right = ret->left;
				ret->left = pos;
				
				/* Update parents */
				if (!pos->right->sentinel)
					pos->right->parent = pos;
				ret->isLeftChild = pos->isLeftChild;
				pos->isLeftChild = true;
				pos->parent = ret;
				ret->parent = tmp;
				pos->right->isLeftChild = false;

				if (ret->isLeftChild)
					tmp->left = ret;
				else
					tmp->right = ret;

				/* Update root */
				if (this->root == pos)
					this->root = ret;
				return (ret);
			}

			node*		rightRotation(node *pos) {
				node	*ret = pos->left;
				node	*tmp = pos->parent;
				
				/* Rotate */
				pos->left = ret->right;
				ret->right = pos;
				/* Update parents */
				if (!pos->left->sentinel)
					pos->left->parent = pos;
				ret->isLeftChild = pos->isLeftChild;
				pos->isLeftChild = false;
				pos->parent = ret;
				ret->parent = tmp;
				pos->left->isLeftChild = true;
				if (ret->isLeftChild)
					tmp->left = ret;
				else
					tmp->right = ret;
				
				/* Update root */
				if (this->root == pos)
					this->root = ret;
				return (ret);
			}

			node*		leftRightRotation(node *pos) {
				node 	*leftNode = leftRotation(pos->left);
				node	*ret = rightRotation(leftNode->parent);
				return (ret);
			}

			node*		rightLeftRotation(node *pos) {
				node	*rightNode = rightRotation(pos->right);
				node	*ret = leftRotation(rightNode->parent); 				
				return (ret);
			}

			////////////////////////////////////////////////////////////////////////////////
			/* Check / Updates */
			
			void		checkColor(node *pos) {
				if (root == 0x0 || pos == root || pos->sentinel)
					return ;
				if (!pos->black && !pos->parent->black) {
					pos = correctTree(pos);
				}
				return (checkColor(pos->parent));
			}

			node*		correctTree(node *pos) {
				if (pos == sentinel)
					return (pos);
				if (pos->parent->isLeftChild) {
					if (pos->parent->parent->right->black)
						pos = rotateNode(pos);
					else {
						pos->parent->parent->right->black = true;
						pos->parent->parent->black = false;
						pos->parent->black = true;
						this->root->black = true;
						this->sentinel->black = true;
						return (pos);
					}
				}
				else {
					if (pos->parent->parent->left->black)
						pos = rotateNode(pos);
					else {
						pos->parent->parent->left->black = true;
						pos->parent->parent->black = false;
						pos->parent->black = true;
						this->root->black = true;
						this->sentinel->black = true;
						return (pos) ;
					}
				}
				return (pos);
			}

			node*		rotateNode(node *pos) {
				if (pos->isLeftChild) {
					if (pos->parent->isLeftChild) {
						pos = rightRotation(pos->parent->parent);
						std::cout << "pos : value : [" << pos->pair._value << "]" << std::endl;
						pos->black = true;
						pos->left->black = false;
						pos->right->black = false;
						this->root->black = true;
						this->sentinel->black = true;
					}
					else {
						pos = rightLeftRotation(pos->parent->parent);
						pos->black = true;
						pos->right->black = false;
						pos->left->black = false;
						this->root->black = true;
						this->sentinel->black = true;
					}
				}
				else {
					if (!pos->parent->isLeftChild) {
						pos = leftRotation(pos->parent->parent);
						pos->black = true;
						pos->right->black = false;	
						pos->left->black = false;
						this->root->black = true;
						this->sentinel->black = true;
					}
					else {
						pos = leftRightRotation(pos->parent->parent);
						pos->black = true;
						pos->right->black = false;
						pos->left->black = false;
						this->root->black = true;
						this->sentinel->black = true;
					}
				}
				return (pos);
			}
			////////////////////////////////////////////////////////////////////////////////
			/* Height section */

			size_t		returnHeight() const {
				if (root == 0x0)
					return (0);
				return (returnHeight(root));
			}

			size_t		returnHeight(node *pos) const {
				if (pos->sentinel || root == 0x0)
					return (0);
				int		leftHeight = returnHeight(pos->left) + 1;
				int		rightHeight = returnHeight(pos->right) + 1;
				if (leftHeight > rightHeight)
					return (leftHeight);
				return (rightHeight);
			}

			size_t		returnBlackNodes() {
				return (returnBlackNodes(this->root));
			}

			size_t		returnBlackNodes(node* pos) {
				if (root == 0x0)
					return (0);
				if (pos->sentinel)
					return (1);
					
				size_t	leftBnodes = returnBlackNodes(pos->left);
				size_t	rightBnodes = returnBlackNodes(pos->right);

				if (rightBnodes != leftBnodes) {
					std::cout << "inbalance" << std::endl;
					if (rightBnodes > leftBnodes)
						checkColor(correctTree(pos->right));
					else
						checkColor(correctTree(pos->left));
				}

				if (pos->black)
					leftBnodes++;
				return (leftBnodes);
			}
				
			////////////////////////////////////////////////////////////////////////////////
			/* + */
			
			void		printBstSorted(node* pos) const {
				if (pos->left != sentinel)
					printBstSorted(pos->left);
				std::cout << "value : [" << pos->pair._value  << "]" << std::endl;
				if (pos->right != sentinel)
					printBstSorted(pos->right);
				return ;
			}

			void		printBstFormat(int level, int k, node *pos) const { 
				if (pos->sentinel || this->root == 0x0)
					return ;
				printBstFormat(level + 1, k, pos->left);
				printBstFormat(level + 1, k, pos->right);

				if (k == level) {
					std::cout << ((pos->isLeftChild) ? CYAN : YELLOW) << " |" << RESET 
					<< ((pos->black) ? BLACK : RED) << "value : [" << pos->pair._value  
					<< "]" << RESET << ((pos->isLeftChild) ? CYAN : YELLOW) << "| " << RESET;
				}
				return ;
			}


			void		printAllBst() const {
				size_t		size = this->returnHeight();
				
				std::cout << 
				CYAN << "left child" << RESET << " | " <<
				YELLOW << "right child" << RESET << std::endl  << std::endl;
				for (size_t i = 0; i < size; i++) {
					printBstFormat(0, i, this->root);
					std::cout << std::endl << GREEN << "\t++++++++++++++++" << RESET << std::endl;
				}
				std::cout  << std::endl << YELLOW << "-------------END OF BST PRINT-------------" << RESET << std::endl << std::endl;
			}

			void		print(int choice = 0) const {
				switch (choice) {
					case 0:
						printAllBst();
						break;
					case 1:
						printBstSorted(this->root);
						break;
					default:
						printAllBst();
				}
				return ;
			}
			
	};

}