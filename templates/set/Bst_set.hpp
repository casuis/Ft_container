/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bst_set.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimon <asimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 13:38:49 by asimon            #+#    #+#             */
/*   Updated: 2023/02/21 22:26:42 by asimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __BST_SET_HPP__
# define __BST_SET_HPP__
# include "../../private/header.hpp"

namespace ft{


	template <typename Key>
	class Node_set
	{
		friend 	class ft::_Rb_tree_set<Key>;
		friend	class ft::set<Key>;


		public:
			typedef Key								key_type;
			typedef ft::Node_set<Key>				node_type;
		////////////////////////////////////////////////////////////////////////////////
		/*                              Attributs                                     */
		////////////////////////////////////////////////////////////////////////////////
			Node_set*						left;
			Node_set*						right;
			Node_set*						parent;
			
			key_type					key;
			bool						black;
			bool						isLeftChild;

			bool						sentinel;
		
		////////////////////////////////////////////////////////////////////////////////
		/*                              Functions                                     */
		////////////////////////////////////////////////////////////////////////////////
		
			Node_set(key_type& param) {
				this->parent = 0x0;
				this->left = 0x0;
				this->right = 0x0;
				this->key = param;
				this->black = false;
				this->isLeftChild = false;
				this->sentinel = false;
			}
		
			Node_set() {
				this->parent = 0x0;
				this->key = key_type();
				this->left = 0x0;
				this->right = 0x0;
				this->black = true;
				this->isLeftChild = false;
				this->sentinel = true;
			};
			
			~Node_set() {};

			operator Node_set<const Key>() const {
				return (Node_set<const Key>(this->key));
			}

			bool		operator<(node_type const & rhs) const {
				return (this->key < rhs.key);
			}

			bool		operator<=(node_type const & rhs) const {
				return (this->key <= rhs.key);
			}

			bool		operator>(node_type const & rhs) const {
				return (rhs < this);
			}
			
			bool		operator>=(node_type const & rhs) const {
				return (rhs <= this);
			}

			bool		operator==(node_type const & rhs) const {
				return (this->key == rhs.key);
			}

			bool		operator!=(node_type const & rhs) const {
				if (this->sentinel || rhs.sentinel)
					return (this->sentinel && rhs.sentinel && (this->parent == rhs.parent));
				return (this->key != rhs.key);
			}
	};
	
	
////////////////////////////////////////////////////////////////////////////////
	
	
	template <typename Key, typename Compare, typename NodeType, class Allocator>
	class _Rb_tree_set {
		friend			class ft::set<Key, Compare>;
		friend			class ft::_Rb_tree_iterator<Key, ft::Node_set<Key> >;
		
			
		public:
		////////////////////////////////////////////////////////////////////////////////
		/*                              Member Type                                   */
		////////////////////////////////////////////////////////////////////////////////
		
			typedef Allocator					allocator_type;
			typedef Key							key_type;
			typedef Key*						key_pointer;
			typedef ft::Node_set<Key>			node;
			typedef Compare						key_compare;	
			
		////////////////////////////////////////////////////////////////////////////////
		/*                              Constructors                                  */
		////////////////////////////////////////////////////////////////////////////////
		
			_Rb_tree_set(const allocator_type& alloc = allocator_type()): _alloc(alloc), _comp(key_compare()), root(0x0), size(0) {
				sentinel = this->_alloc.allocate(1);;
				_alloc.construct(sentinel, Node_set<Key>());
				return ;
			};
			
			~_Rb_tree_set() {
				freeRb_tree_set(root);
				_alloc.destroy(sentinel);
				_alloc.deallocate(sentinel, 1);
			};

		////////////////////////////////////////////////////////////////////////////////
		/*                              Methodes                                      */
		////////////////////////////////////////////////////////////////////////////////
		/* free section */

			void		freeRb_tree_set() {
				freeRb_tree_set(root);
				return ;
			}
			
			void		freeRb_tree_set(node* pos) {
				if (pos == sentinel || pos == 0x0)
					return;
				freeRb_tree_set(pos->left);
				freeRb_tree_set(pos->right);
				_alloc.destroy(pos);
				_alloc.deallocate(pos, 1);
				size = 0;
				root = 0x0;
				return ;
			}
		
		////////////////////////////////////////////////////////////////////////////////
		
		/* Add section */
		public:
			
			void	addNode(node*newNode) {
				addNode(newNode, this->root);
				return ;
			}

			void	addNode(node *newNode, node *pos) {
				if (root == 0x0){
					root = newNode;
					this->sentinel->left = root;
					this->size += 1;
					this->root->parent = this->sentinel;
					this->root->left = sentinel;
					this->root->right = sentinel;
					this->root->black = true;
					updateSentinel();
					return ;
				}
				else{
					if (newNode->key == pos->key)
						return ;
					if (_comp(newNode->key, pos->key) && pos->left->sentinel){
						pos->left = newNode;
						newNode->parent = pos;
						newNode->isLeftChild = true;
						newNode->left = sentinel;
						newNode->right = sentinel;
						this->size += 1;
					}
					else if (_comp(newNode->key, pos->key) && !pos->left->sentinel){
						addNode(newNode, pos->left);
					}
					else if (_comp(pos->key, newNode->key) && pos->right->sentinel){
						pos->right = newNode;
						newNode->parent = pos;
						newNode->isLeftChild = false;
						newNode->left = sentinel;
						newNode->right = sentinel;
						this->size += 1;
					}
					else {
						addNode(newNode, pos->right);
					}
					checkColor(newNode);
					updateSentinel();
				}
				return ;
			};

			void		updateSentinel() {
				this->sentinel->right = getLast();
				this->sentinel->left = getLast();
			}

			node*		createNode(key_type key) {
				node	*newNode;

				newNode = this->_alloc.allocate(1);
				this->_alloc.construct(newNode, node(key));
				return (newNode);
			}

			////////////////////////////////////////////////////////////////////////////////
			/* Search section */
	

			node*		searchNode(const key_type value) const {
				return (searchNode(value, this->root));
			}

			node*		searchNode(const key_type& value, node* pos) const {
				if (root == 0x0)
					return (0x0);
				if (pos->sentinel == true)
					return (0x0);
				if (_comp(value, pos->key))
					return (searchNode(value, pos->left));
				if (_comp(pos->key, value))
					return (searchNode(value, pos->right));
				if (!_comp(value, pos->key) && !_comp(pos->key, value))
					return (pos);
				return (0x0);
			}

			////////////////////////////////////////////////////////////////////////////////
			/* Delete section */			
			
			void		deleteNode(const key_type& value) {
				deleteNode(value, this->root);
				return ;
			}
			
			/* find the node to delete*/
			void		deleteNode(const key_type& value, node *pos){
				if (_comp(value, pos->key) && !pos->left->sentinel ) {
					deleteNode(value, pos->left);
					return ;
				}
				else if (_comp(pos->key, value) && !pos->right->sentinel) {
					deleteNode(value, pos->right);
					return ;
				}
				else if (!_comp(pos->key, value) && !_comp(value, pos->key))
					deleteNode(pos);
				return ;
			}

			/* delete node */
			void		deleteNode(node* pos) {
				bool								need_to_fix = pos->black;
				bool								is_left = pos->isLeftChild;
				node								*fixNode = pos->parent;
				node								*swap_node;
				
				if (pos->right->sentinel && pos->left->sentinel){
					if (pos->isLeftChild)
						pos->parent->left = sentinel;
					else
						pos->parent->right = sentinel;
					deleteLeaf(pos);
					if (fixNode != sentinel)
						fixDelete(fixNode, is_left, need_to_fix);
					updateSentinel();
					return ;
				}
				
				swap_node = returnSuccessor(pos);
				if (swap_node->sentinel)
					swap_node = returnPredecessor(pos);
				is_left = swap_node->isLeftChild;
				need_to_fix = swap_node->black;
				swapLeaf(swap_node, pos);
				fixNode = pos->parent;
				deleteLeaf(pos);
				fixDelete(fixNode, is_left, need_to_fix);
				updateSentinel();
				return ;
			}
			
			/* NEED TO SWAP ALL NODE AND NOT JUST PAIR */
			void		swapLeaf(node* swap_node, node* pos) {
				node*								parent_tmp = pos->parent;
				node*								Lchild_tmp = pos->left;
				node*								Rchild_tmp = pos->right;
				bool								is_left = pos->isLeftChild;
				bool								black_tmp = pos->black;

				if (pos == this->root)
					this->root = swap_node;
				pos->left = swap_node->left; 
				if (!swap_node->left->sentinel)
					pos->left->parent = pos;
				pos->right = swap_node->right;
				if (!swap_node->right->sentinel)
					pos->right->parent = pos;
				if (pos != swap_node->parent) {
					pos->parent = swap_node->parent;
					if (swap_node->isLeftChild)
						pos->parent->left = pos;
					else
						pos->parent->right = pos;
					swap_node->left = Lchild_tmp;
					swap_node->left->parent = swap_node;
					swap_node->right = Rchild_tmp;
					swap_node->right->parent = swap_node;
				}
				else {
					pos->parent = swap_node;
					if (swap_node->isLeftChild) {
						swap_node->left = pos;
						swap_node->right = Rchild_tmp;
						swap_node->right->parent = swap_node;
					}
					else {
						swap_node->right = pos;
						swap_node->left = Lchild_tmp;
						swap_node->left->parent = swap_node;
					}
				}
				swap_node->parent = parent_tmp;
				if (pos->isLeftChild)
					parent_tmp->left = swap_node;
				else
					parent_tmp->right = swap_node;
				pos->black = swap_node->black;
				pos->isLeftChild = swap_node->isLeftChild;
				swap_node->black = black_tmp;
				swap_node->isLeftChild = is_left;
				return;	
			}
				
			void		deleteLeaf(node *pos) {
				if (pos == root)
					this->root = 0x0;
				if (pos->isLeftChild) {
					if (!pos->left->sentinel) {
						pos->parent->left = pos->left;
						pos->left->parent = pos->parent;
						pos->left->isLeftChild = true;
					}
					else if (!pos->right->sentinel) {
						pos->parent->left = pos->right;
						pos->right->parent = pos->parent;
						pos->right->isLeftChild = true;
					}
					else
						pos->parent->left = sentinel;
				}
				else if (!pos->isLeftChild) {
					if (!pos->left->sentinel) {
						pos->parent->right = pos->left;
						pos->left->parent = pos->parent;
						pos->left->isLeftChild = false;
					}
					else if (!pos->right->sentinel) {
						pos->parent->right = pos->right;
						pos->right->parent = pos->parent;
						pos->right->isLeftChild = false;
					}
					else
						pos->parent->right = sentinel;
				}
				this->_alloc.destroy(pos);
				this->_alloc.deallocate(pos, 1);
				this->size -= 1;
			}

			void		fixDelete(node* pos, bool lft, bool need_to_fix = true) {
				if (!need_to_fix || pos == sentinel)
					return;
				if (lft && !pos->left->black)
					pos->left->black = true;
				else if (!lft && !pos->right->black)
					pos->right->black = true;
				else if (is_red_sib(pos, lft))
					red_sib(pos, lft);
				else if (is_black_sibling_red_child(pos, lft))
					black_sibling_red_child(pos, lft);
				else if (is_black_sibling_black_child(pos, lft))
					black_sibling_black_child(pos, lft);
					
				return ;
			}
			
			/////////////////////////////////////////////////////////////////////////
				/* Fix deletion comparaisons */
				
				bool		is_black_sibling_black_child(node *pos, bool lft) {
					/* check if pos sibling have only black child */
					return ((lft && !pos->right->sentinel 
						&& (pos->right->left->black && pos->right->right->black))
						|| (!lft && !pos->left->sentinel 
						&& (pos->left->left->black && pos->left->right->black)));
				}
				
				bool		is_black_sibling_red_child(node *pos, bool lft) {
					/* check if pos sibling have a red child */
					return ((lft && !pos->right->sentinel 
						&& (!pos->right->left->black || !pos->right->right->black))
						|| (!lft && !pos->left->sentinel 
						&& (!pos->left->left->black || !pos->left->right->black))); 
				}

				bool		is_red_sib(node* pos, bool lft) {
					/* Check if sibling is red */
					return ((lft && !pos->right->black) || (!lft && !pos->left->black));
				}
			
				/////////////////////////////////////////////////////////////////////////
				/* Fix deletion operations */
			
				void		black_sibling_red_child(node *pos, bool lft) {
					/* Check what rotation need to be done */
					bool		color_swap;
					
					if (lft && !pos->right->sentinel && !pos->right->right->black) {
						pos->right->black = pos->black;
						pos->black = true;
						pos->right->right->black = true;
						leftRotation(pos); 	
					}
					else if (!lft && !pos->left->sentinel && !pos->left->left->black) {
						pos->left->black = pos->black;
						pos->black = true;
						pos->left->left->black = true;
						rightRotation(pos); 	
					}
					else if (lft && !pos->right->sentinel && !pos->right->left->black) {
						color_swap = pos->right->left->black;
						pos->right->left->black = pos->right->black;
						pos->right->black = color_swap;
						rightRotation(pos->right);
						black_sibling_red_child(pos, lft);
					}
					else if (!lft && !pos->left->sentinel && !pos->left->right->black) {
						color_swap = pos->left->right->black;
						pos->left->right->black = pos->left->black;
						pos->left->black = color_swap;
						leftRotation(pos->left);
						black_sibling_red_child(pos, lft);
					}
				}

				void		black_sibling_black_child(node *pos, bool lft) {
					if (lft) {
						pos->right->black = false;
						if (!pos->black)
							pos->black = true;
						else
							fixDelete(pos->parent, pos->isLeftChild);
					}
					else {
						pos->left->black = false;
						if (!pos->black)
							pos->black = true;
						else
							fixDelete(pos->parent, pos->isLeftChild);
					}
					return ;
				}
			
				void	red_sib(node* pos, bool lft) {
					bool	color_swap;
					if (lft) {
						color_swap = pos->right->black;
						pos->right->black = pos->black;
						pos->black = color_swap;
						leftRotation(pos);
						fixDelete(pos, lft);
					}
					else {
						color_swap = pos->left->black;
						pos->left->black = pos->black;
						pos->black = color_swap;
						rightRotation(pos);
						fixDelete(pos, lft);
					}
					return ;
				}
				
			////////////////////////////////////////////////////////////////////////////////

			/* the biggest of the smallest */
			static node*		returnSuccessor(node *pos) {
				node		*ret;
				
				if (pos == 0x0 || !pos->left || !pos->right)
					return (0x0);
				if (pos->left->sentinel)
					return (pos->left);
				else {
					ret = pos->left;
					while (!ret->right->sentinel) // look for the largest node less than pos
						ret = ret->right;
					return (ret);
				}
				return (0x0);
			}

			/* the smallest of the biggest */
			static node*		returnPredecessor(node *pos) {
				node		*ret;
				
				if (pos == 0x0 || !pos->left || !pos->right)
					return (0x0);
				if (pos->right->sentinel)
					return (pos->right);
				else {
					ret = pos->right;
					while (!ret->left->sentinel) // look for the smalest node greater than pos
						ret = ret->left;
					return (ret);
				}
				return (0x0);
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
				
				/* Update colors */
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
					if (pos->parent->parent->right->black) {
						pos = rotateNode(pos);
					}
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
					if (pos->parent->parent->left->black) {
						pos = rotateNode(pos);
					}
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
						pos->black = true;
						pos->right->black = false;
						pos->left->black = false;
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
					std::cerr << "unbalanced on pos: [" << pos->key << "]" << std::endl;
					exit(1);
				}

				if (pos->black)
					leftBnodes++;
				return (leftBnodes);
			}

			////////////////////////////////////////////////////////////////////////////////
			/* Geter section */

			node*		getFirst() const {
				node*	tmp = this->root;
				if (!size)
					return (sentinel);
				while (!tmp->left->sentinel)
					tmp = tmp->left;
				return (tmp);
			}

			node*		getLast() const {
				node*	tmp = this->root;
				if (!size)
					return (sentinel);
				while (!tmp->right->sentinel)
					tmp = tmp->right;
				return (tmp);
			}
				
			////////////////////////////////////////////////////////////////////////////////
			/* + */
			
			void		printRb_treeSorted(node* pos) const {
				if (pos->left != sentinel)
					printRb_treeSorted(pos->left);
				std::cout << "value : [" << pos->key  << "]" << std::endl;
				if (pos->right != sentinel)
					printRb_treeSorted(pos->right);
				return ;
			}

			void		printRb_treeFormat(int level, int k, node *pos) const { 
				if (pos->sentinel || this->root == 0x0)
					return ;
				printRb_treeFormat(level + 1, k, pos->left);
				printRb_treeFormat(level + 1, k, pos->right);

				if (k == level) {
					std::cout << ((pos->isLeftChild) ? M_CYAN : M_YELLOW) << " |" << M_RESET 
					<< ((pos->black) ? M_BLACK : M_RED) << "value : [" << pos->key  
					<< "] | p: [" << pos->parent->key << "]" << M_RESET << ((pos->isLeftChild) ? M_CYAN : M_YELLOW) << "| " << M_RESET;
				}
				return ;
			}


			void		printAllRb_tree() const {
				size_t		size = this->returnHeight();
				std::cout << "size : " << size << std::endl;
				
				std::cout << 
				M_CYAN << "left child" << M_RESET << " | " <<
				M_YELLOW << "right child" << M_RESET << std::endl  << std::endl;
				for (size_t i = 0; i < size; i++) {
					printRb_treeFormat(0, i, this->root);
					std::cout << std::endl << M_GREEN << "\t++++++++++++++++" << M_RESET << std::endl;
				}
				std::cout  << std::endl << M_YELLOW << "-------------END OF Rb_tree PRINT-------------" << M_RESET << std::endl << std::endl;
			}

			void		print(int choice = 0) const {
				switch (choice) {
					case 0:
						printAllRb_tree();
						break;
					case 1:
						printRb_treeSorted(this->root);
						break;
					default:
						printAllRb_tree();
				}
				return ;
			}

			ft::_Rb_tree_set<Key, Compare>	operator=(typename ft::_Rb_tree_set<Key, Compare>& tree) {
				this->root = tree.root;
				this->sentinel = tree.sentinel;
				this->_alloc = tree._alloc;
				this->_comp = tree._comp;
				return (*this);
			}

			size_t			max_size() const {
				return (this->_alloc.max_size());
			}
			
		private:
		////////////////////////////////////////////////////////////////////////////////
		/*                              Attributs                                     */
		////////////////////////////////////////////////////////////////////////////////
		
			Allocator							_alloc;
			key_compare							_comp;
			Node_set<Key>						*root;
			Node_set<Key>						*sentinel;
			size_t								size;

			
	};

}

#endif