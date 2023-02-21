/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_set.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimon <asimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 18:23:17 by asimon            #+#    #+#             */
/*   Updated: 2023/02/21 16:02:27 by asimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ITERATOR_SET__
# define __ITERATOR_SET__
# include "../../private/header.hpp"


namespace ft {
	
	template <typename T, typename N>
	class _Rb_tree_iterator_set {
		
		public:
			typedef T																		value_type;
			typedef ft::_Rb_tree_iterator_set<value_type, N>								iterator;
			typedef typename ft::_Rb_tree_set<typename N::key_type>											Rb_tree_type;
			typedef std::ptrdiff_t															difference_type;
			typedef value_type*																pointer;
			typedef value_type&																reference;
			typedef std::random_access_iterator_tag											iterator_category;
			typedef typename Rb_tree_type::node												node_type;

			_Rb_tree_iterator_set(): node(0x0) {}
			_Rb_tree_iterator_set(N* param): node(param) {}

			template <class U>
			_Rb_tree_iterator_set(const _Rb_tree_iterator_set<T, N > &src)
			:node(src.node) {} 
			
			~_Rb_tree_iterator_set() {}

			operator _Rb_tree_iterator_set<const T, N>() const {
				return (_Rb_tree_iterator_set<const T, N>(this->node));
			}

			reference		operator*() const {
				return (node->key);
			}

			pointer			operator->() const {
				return (&(node->key));
			}

			////////////////////////////////////////////////////////////////////////////////
			/* incrementation/decr ope */
		
			iterator&		operator++() {
				node_type		*buff = Rb_tree_type::returnPredecessor(this->node);
				
				if (buff && !buff->sentinel)
					this->node = buff;
				else if (buff && buff->sentinel && this->node->isLeftChild 
						&& !this->node->parent->sentinel)
					this->node = this->node->parent;
				else if (!this->node->sentinel) {
					this->node = getNext(this->node);
				}
				else if (this->node->sentinel)
					this->node = buff->right;
				else
					this->node = buff;
				return (*this);
			}

			iterator		operator++(int) {
				iterator		tmp(*this);
				node_type		*buff = Rb_tree_type::returnPredecessor(this->node);
				
				if (buff && !buff->sentinel)
					this->node = buff;
				else if (buff && buff->sentinel && this->node->isLeftChild 
						&& !this->node->parent->sentinel)
					this->node = this->node->parent;
				else if (!this->node->sentinel) {
					this->node = getNext(this->node);
				}
				else if (this->node->sentinel)
					this->node = buff->right;
				else
					this->node = buff;
				return (tmp);
			}

			iterator&		operator--() {
				node_type		*buff = Rb_tree_type::returnSuccessor(this->node);
				
				if (buff && !buff->sentinel)
					this->node = buff;
				else if (buff && buff->sentinel && !this->node->isLeftChild 
						&& !this->node->parent->sentinel)
					this->node = this->node->parent;
				else if (!this->node->sentinel) {
					this->node = getPrev(this->node);
				}
				else if (this->node->sentinel)
					this->node = buff->right;
				else
					this->node = buff;
				return (*this);
			}

			iterator		operator--(int) {
				iterator		tmp(*this);
				node_type		*buff = Rb_tree_type::returnSuccessor(this->node);
				
				if (buff && !buff->sentinel)
					this->node = buff;
				else if (buff && buff->sentinel && !this->node->isLeftChild 
						&& !this->node->parent->sentinel)
					this->node = this->node->parent;
				else if (!this->node->sentinel) {
					this->node = getPrev(this->node);
				}
				else if (this->node->sentinel)
					this->node = buff->right;
				else
					this->node = buff;
				return (tmp);
			}

			////////////////////////////////////////////////////////////////////////////////
			/* Assignation operator */

			iterator		operator=(const iterator param) {
				if (this->node == param.getNode())
					return (*this);
				else
					this->node = param.getNode();
				return (*this);
			}
			
			template <class U>
			bool	operator==(const ft::_Rb_tree_iterator_set<U, N>& src) const
			{
				return (this->node == src.getNode());
			}

			template <class U>
			bool	operator!=(const ft::_Rb_tree_iterator_set<U, N>& src) const
			{
				return (this->node != src.getNode());
			}

			N*			getNode() const {
				return (this->node);
			}

		private:
			N		*node;

			node_type*			getNext(node_type *current) {
				while (!current->parent->isLeftChild && !current->parent->sentinel)
					current = current->parent;
				if (current->parent->sentinel)
					return (current->parent);
				if (current->parent->isLeftChild)
					return (current->parent->parent);
				return (0x0);
			}

			node_type*			getPrev(node_type *current) {
				while (current->parent->isLeftChild && !current->parent->sentinel)
					current = current->parent;
				if (current->parent->sentinel)
					return (current->parent);
				if (!current->parent->isLeftChild)
					return (current->parent->parent);
				return (0x0);
			}

	};
}

#endif