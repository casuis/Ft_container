/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_map.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimon <asimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 18:23:17 by asimon            #+#    #+#             */
/*   Updated: 2023/01/25 12:01:55 by asimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <header.hpp>
# include "../../private/header.hpp"


namespace ft {
	
	template <typename T, typename N>
	class _Rb_tree_iterator {
		
		public:
			typedef T																		value_type;
			typedef ft::_Rb_tree_iterator<value_type, N>									iterator;
			typedef typename ft::_Rb_tree<typename N::key_type, typename N::mapped_type>	Rb_tree_type;
			typedef std::ptrdiff_t															difference_type;
			typedef value_type*																pointer;
			typedef value_type&																reference;
			typedef std::random_access_iterator_tag											iterator_category;

			_Rb_tree_iterator(N* param): node(param) {}
			_Rb_tree_iterator(): node(0x0) {}
			
			~_Rb_tree_iterator() {}

			reference		operator*() const {
				return (node->pair);
			}

			pointer		operator->() const {
				return (&(node->pair));
			}

			// pas d'operateur []

			////////////////////////////////////////////////////////////////////////////////
			/* incrementation/decr ope */
		
			iterator&		operator++() {
				typename Rb_tree_type::node			*buff = Rb_tree_type::returnPredecessor(this->node);
				
				if (buff && !buff->sentinel)
					this->node = buff;
				else if (buff && !buff->sentinel && this->node->isLeftChild 
						&& !this->node->parent->sentinel)
					this->node = this->node->parent;
				else if (buff && !buff->sentinel && !this->node->isLeftChild && !this->node->parent->sentinel 
							&& !this->node->parent->parent->sentinel)
					this->node = this->node->parent->parent;
				else if (this->node->sentinel)
					this->node = buff->right;
				else
					this->node = buff;
				return (*this);
			}

			iterator		operator++(int) {
				iterator							tmp(*this);
				typename Rb_tree_type::node			*buff = Rb_tree_type::returnPredecessor(this->node);
				
				if (buff && !buff->sentinel)
					this->node = buff;
				else if (buff && buff->sentinel && this->node->isLeftChild && !this->node->parent->sentinel)
					this->node = this->node->parent;
				else if (buff && buff->sentinel && !this->node->isLeftChild && !this->node->parent->sentinel 
						&& !this->node->parent->parent->sentinel)
					this->node = this->node->parent->parent;
				else if (this->node->sentinel)
					this->node = buff->right;
				else
					this->node = buff;
				return (tmp);
			}

			iterator&		operator--() {
				typename Rb_tree_type::node			*buff = Rb_tree_type::returnSuccessor(this->node);
				
				if (buff && !buff->sentinel)
					this->node = buff;
				else if (buff && buff->sentinel && !this->node->isLeftChild 
						&& !this->node->parent->sentinel)
					this->node = this->node->parent;
				else if (buff && buff->sentinel && this->node->isLeftChild && !this->node->parent->sentinel 
								&& !this->node->parent->parent->sentinel)
					this->node = this->node->parent->parent;
				else if (this->node->sentinel)
					this->node = buff->right;
				else
					this->node = buff;
				return (*this);
			}

			iterator		operator--(int) {
				iterator							tmp(*this);
				typename Rb_tree_type::node			*buff = Rb_tree_type::returnSuccessor(this->node);
				
				if (buff && !buff->sentinel)
					this->node = buff;
				else if (buff && buff->sentinel && !this->node->isLeftChild 
						&& !this->node->parent->sentinel)
					this->node = this->node->parent;
				else if (buff && buff->sentinel && this->node->isLeftChild && !this->node->parent->sentinel 
								&& !this->node->parent->parent->sentinel)
					this->node = this->node->parent->parent;
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
			bool	operator==(const ft::_Rb_tree_iterator<U, N>& src) const
			{
				return (this->node == src.getNode());
			}

			template <class U>
			bool	operator!=(const ft::_Rb_tree_iterator<U, N>& src) const
			{
				return (this->node != src.getNode());
			}

			////////////////////////////////////////////////////////////////////////////////
			/* Comparaison opperator */
			

		private:
			N		*node;

			N*			getNode() const {
				return (this->node);
			}
	};
}