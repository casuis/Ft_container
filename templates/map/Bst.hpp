/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bst.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimon <asimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 13:38:49 by asimon            #+#    #+#             */
/*   Updated: 2022/12/29 20:36:03 by asimon           ###   ########.fr       */
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
					}
					else if (newNode->pair._value < pos->pair._value && !pos->left->sentinel)
						addNode(newNode, pos->left);
					else if (newNode->pair._value > pos->pair._value && pos->right->sentinel){
						pos->right = newNode;
						newNode->parent = pos;
						newNode->left = sentinel;
						newNode->right = sentinel;
						newNode->isLeftChild = false;
					}
					else
						addNode(newNode, pos->right);
					checkColor(newNode);
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
				pos->parent = ret;
				ret->parent = tmp;

				/* Update root */
				if (this->root == pos)
					this->root = ret;
				return (ret);
			}

			node*		rightRotation(node *pos) {
				node	*tmp = pos->parent;
				node	*ret = pos->left;
				
				/* Rotate */
				pos->left = ret->right;
				ret->right = pos;

				/* Update parents */
				if (!pos->right->sentinel)
					pos->left->parent = pos;
				ret->parent = tmp;
				pos->parent = ret;
				
				/* Update root */
				if (this->root == pos)
					this->root = ret;
				return (ret);
			}

			node*		leftRightRotation(node *pos) {
				node	*nodeRight = leftRotation(pos->left);
				node	*ret = rightRotation(nodeRight);
				return (ret);
			}

			node*		rightLeftRotation(node *pos) {
				node	*nodeLeft = rightRotation(pos->right);
				node	*ret = leftRotation(nodeLeft); 				
				return (ret);
			}

			////////////////////////////////////////////////////////////////////////////////
			/* Check / Updates */
			
			void		checkColor(node *pos) {
				if (root == 0x0 || pos == root || pos->sentinel)
					return ;
				if (!pos->black && !pos->parent->black)
					correctTree(pos);
				return (checkColor(pos->parent));
			}

			void		correctTree(node *pos) {
				if (pos->parent->isLeftChild) {
					if (pos->parent->parent->right->black)
						rotateNode(pos);
					else {
						pos->parent->parent->right->black = true;
						pos->parent->parent->black = false;
						pos->parent->black = true;
						return;
					}
				}
				else {
					if (pos->parent->parent->left->black)
						rotateNode(pos);
					else {
						pos->parent->parent->left->black = true;
						pos->parent->parent->black = false;
						pos->parent->black = true;
					}
				}
				return ;
			}

			void		rotateNode(node *pos) {
				if (pos->isLeftChild) {
					if (pos->parent->isLeftChild) {
						rightRotation(pos->parent->parent);
						pos->black = false;
						pos->parent->black = true;	
						pos->parent->right->black = false;
					}
					else {
						rightLeftRotation(pos->parent->parent);
						pos->black = true;
						pos->right->black = false;
						pos->left->black = false;
					}
				}
				else {
					if (pos->parent->isLeftChild) {
						leftRotation(pos->parent->parent);
						pos->black = false;
						pos->parent->black = true;	
						pos->parent->left->black = false;
					}
					else {
						leftRightRotation(pos->parent->parent);
						pos->black = true;
						pos->right->black = false;
						pos->left->black = false;
					}
				}
			}
				
			////////////////////////////////////////////////////////////////////////////////
			/* + */
			
			void		printBst(node* pos) const {
				if (pos->left != sentinel)
					printBst(pos->left);
				std::cout << "value : [" << pos->pair._value  << "]" << std::endl;
				if (pos->right != sentinel)
					printBst(pos->right);
				return ;
			}

	};

}