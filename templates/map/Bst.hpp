/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bst.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimon <asimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 13:38:49 by asimon            #+#    #+#             */
/*   Updated: 2022/12/26 14:26:00 by asimon           ###   ########.fr       */
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
				this->parent = 0x0;
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
		
			void	addNode(node& newNode, node pos) {
				if (root == 0x0){
					root = &newNode;
					this->sentinel->left = root;
					this->root->parent = this->sentinel;
					return ;
				}
				else{
					if (newNode->value < pos->value && pos->left == sentinel){
						pos->left = newNode;
						newNode->parent = pos;
						newNode->isLeftChild = true;
						newNode->left = sentinel;
						newNode->right = sentinel;
					}
					else if (newNode->value < pos->value && pos->left != sentinel)
						addNode(newNode, pos->left);
					else if (newNode->value > pos->value && pos->right == sentinel){
						pos->right = newNode;
						newNode->parent = pos;
						newNode->left = sentinel;
						newNode->right = sentinel;
						newNode->isLeftChild = false;
					}
					else
						addNode(newNode, pos->right);
					// checkcolor(newNode);
				}
				return ;
			};

	};

}