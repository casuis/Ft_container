/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_map.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimon <asimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 18:23:17 by asimon            #+#    #+#             */
/*   Updated: 2023/01/23 15:57:55 by asimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <header.hpp>
# include "../../private/header.hpp"


namespace ft {
	
	template <typename T>
	class _Rb_tree_iterator {
		
		public:
			typedef T																			value_type;
			typedef _Rb_tree_iterator<value_type>												iterator;
			typedef typename ft::_Rb_tree<typename T::key_type, typename T::mapped_type>		Rb_tree_type;
			typedef std::ptrdiff_t																difference_type;
			typedef T*																			pointer;
			typedef T&																			reference;
			typedef std::random_access_iterator_tag												iterator_category;
			_Rb_tree_iterator(value_type* param): node(param) {}

			_Rb_tree_iterator(): node(0x0) {}
			
			~_Rb_tree_iterator() {}

			value_type&		operator*() const {
				return (*node);
			}

			typename value_type::pair_type*		operator->() const {
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
				if (this->node == &(*param))
					return (*this);
				else
					this->node = &(*param);
				return (*this);
			}

			bool			operator!=(iterator & rhs) const {
				return (this->node != rhs.node);
			}

			////////////////////////////////////////////////////////////////////////////////
			/* Comparaison opperator */
			

		private:
			value_type		*node;
	};
}