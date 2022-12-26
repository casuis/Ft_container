/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bst.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimon <asimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 13:38:49 by asimon            #+#    #+#             */
/*   Updated: 2022/12/26 18:56:49 by asimon           ###   ########.fr       */
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
				
				std::cout << "value : [" << tmp._value << "]" << std::endl;
				std::cout << "key : [" << tmp._key << "]" << std::endl;
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
		
			void	addNode(node& newNode, node &pos) {
				if (root == 0x0){
					std::cout << "set root" << std::endl;
					root = &newNode;
					this->sentinel->left = root;
					this->root->parent = this->sentinel;
					this->root->left = sentinel;
					this->root->right = sentinel;
					return ;
				}
				else{
					if (newNode.pair._value == pos.pair._value)
						return ;
					if (newNode.pair._value < pos.pair._value && pos.left == sentinel){
						pos.left = &newNode;
						newNode.parent = &pos;
						newNode.isLeftChild = true;
						newNode.left = sentinel;
						newNode.right = sentinel;
					}
					else if (newNode.pair._value < pos.pair._value && pos.left != sentinel)
						addNode(newNode, *pos.left);
					else if (newNode.pair._value > pos.pair._value && pos.right == sentinel){
						pos.right = &newNode;
						newNode.parent = &pos;
						newNode.left = sentinel;
						newNode.right = sentinel;
						newNode.isLeftChild = false;
					}
					else
						addNode(newNode, *pos.right);
					// checkcolor(newNode);
				}
				return ;
			};

			node*		searchNode(const value_type& value, node& pos){
				if (root == 0x0){
					std::cerr << "BST is empty" << std::endl;
					return (0x0);
				}
				if (pos.sentinel == true){
					std::cerr << "not in BST" << std::endl;
					return (0x0);
				}
				if (value < pos.pair._value)
					return (searchNode(value, *pos.left));
				if (value > pos.pair._value)
					return (searchNode(value, *pos.right));
				if (value == pos.pair._value)
					return (&pos);
				return (0x0);
			}

			void		deleteNode(const value_type& value, node &pos){
				node		*tmp;
				std::cout << "start: " << "pos val: [" << pos.pair._value << "]" << "val : [" << value << "]" << std::endl; 
				if (pos.pair._value == value){
					std::cout << "equal" << std::endl;
					tmp = pos.parent;
					std::cout << "ici" << std::endl;
					if (pos.isLeftChild == true && pos.left->sentinel == false){
						tmp->left = pos.left;
						tmp->left->right = pos.right;
						pos.left->parent = tmp;
						this->_alloc.destroy(&pos);
					}
					else if (pos.isLeftChild == true && pos.left->sentinel == true && pos.right->sentinel == false){
						tmp->left = pos.right;
						pos.right->parent = tmp;
						this->_alloc.destroy(&pos);
					}
					else if (pos.isLeftChild == false && pos.left->sentinel == false){
						tmp->right = pos.left;
						tmp->right->right = pos.right;
						pos.left->parent = tmp;
						this->_alloc.destroy(&pos);
					}
					else if (pos.isLeftChild == false && pos.left->sentinel == true && pos.right->sentinel == false){
						tmp->right = pos.right;
						pos.right->parent = tmp;
						this->_alloc.destroy(&pos);
					}
					else if (pos.isLeftChild == true){
						tmp->left = pos.left;
						pos.left->parent = tmp;
						_alloc.destroy(&pos);
					}
					else if (pos.isLeftChild == false){
						tmp->right = pos.right;
						pos.right->parent = tmp;
						_alloc.destroy(&pos);
					}
					return ;
				}
				else if (value < pos.pair._value && pos.left->sentinel == false){
					std::cout << "less" << std::endl;
					deleteNode(value, *(pos.left));
					return ;
				}
				else if (value > pos.pair._value && pos.right->sentinel == false){
					std::cout << "more" << std::endl;
					deleteNode(value, *(pos.right));
					return ;
				}
				std::cout << "end" << std::endl;
				return ;
			}

			void		printBst(node& pos) const{
				if (pos.left != sentinel)
					printBst(*(pos.left));
				std::cout << "value : [" << pos.pair._value  << "]" << std::endl;
				if (pos.right != sentinel)
					printBst(*(pos.right));
				return ;
			}

	};

}