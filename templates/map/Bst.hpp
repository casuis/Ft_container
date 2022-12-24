/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bst.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimon <asimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 13:38:49 by asimon            #+#    #+#             */
/*   Updated: 2022/12/24 16:57:30 by asimon           ###   ########.fr       */
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
			bool						black;
			bool						isLeftChild;

			bool						sentinel;
		
		////////////////////////////////////////////////////////////////////////////////
		/*                              Functions                                     */
		////////////////////////////////////////////////////////////////////////////////
		
			Node(Key& key, Value& value){
				ft::pair<Key, Value>		tmp(key, value);		
				
				this->parent = 0x0;
				this->left = 0x0;
				this->right = 0x0;
				this->pair = tmp;
				this->black = false;
				this->isLeftChild = false;
				this->sentinel = false;
				return ;
			};
			
			Node(){
				this->parent = 0x0;
				this->left = 0x0;
				this->right = 0x0;
				this->black = true;
				this->isLeftChild = false;
				this->sentinel = true;
			};
			
			~Node() {};
	};

	template <typename Key, typename Value>
	class NodeSentinel: public Node<Key, Value>{
		friend 	class ft::Bst<Key, Value>;

		
		private:
			size_t	size;
			
			NodeSentinel(): Node<Key, Value>() {
				this->size = 0;
			}
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
			NodeSentinel<Key, Value>			*sentinel;
			
		////////////////////////////////////////////////////////////////////////////////
		/*                              Constructors                                  */
		////////////////////////////////////////////////////////////////////////////////
		
			Bst(const allocator_type& alloc = allocator_type()): _alloc(alloc), root(0x0) {
				std::cout << "start of Bst constructor" << std::endl;
				sentinel = this->_alloc.allocate(1);
				this->_alloc.construct(sentinel, NodeSentinel<Key, Value>());
				// this->sentinel = NodeSentinel();
				std::cout << "end of Bst constructor" << std::endl;
				return ;
			};
			
			~Bst() {};

		////////////////////////////////////////////////////////////////////////////////
		/*                              Methodes                                      */
		////////////////////////////////////////////////////////////////////////////////
		
			void	addNode(node pos, node newNode) {
				if (root == 0x0){
					root = newNode;
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
						addNode(pos->left, newNode);
					else if (newNode->value > pos->value && pos->right == sentinel){
						pos->right = newNode;
						newNode->parent = pos;
						newNode->left = sentinel;
						newNode->right = sentinel;
						newNode->isLeftChild = false;
					}
					else
						addNode(pos->right, newNode);
					checkcolor(newNode);
				}
				return ;
			};

	};

}