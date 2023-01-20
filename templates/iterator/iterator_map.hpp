/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_map.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimon <asimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 18:23:17 by asimon            #+#    #+#             */
/*   Updated: 2023/01/20 18:12:11 by asimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.hpp>

namespace ft {
	
	template <typename T>
	class _Rb_tree_iterator {
		
		public:
			typedef T																			value_type;
			typedef _Rb_tree_iterator<value_type>												iterator;
			typedef typename ft::_Rb_tree<typename T::key_type, typename T::mapped_type>		Rb_tree_type;
			
			_Rb_tree_iterator(value_type* param, value_type* begin, value_type* end): node(param), begin(begin), end(end) {}

			_Rb_tree_iterator(): node(value_type()) {}
			
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
			/*
			**	need to check if it segfault in std
			*/
		
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
				else
					this->node = 0x0;
				return (*this);
			}

			iterator		operator++(int) {
				iterator							tmp(*this);
				typename Rb_tree_type::node			*buff = Rb_tree_type::returnPredecessor(this->node);
				
				
				if (buff && !buff->sentinel)
					this->node = buff;
				else if (buff && !buff->sentinel && this->node->isLeftChild && !this->node->parent->sentinel)
					this->node = this->node->parent;
				else if (buff && !buff->sentinel && !this->node->isLeftChild && !this->node->parent->sentinel 
						&& !this->node->parent->parent->sentinel)
					this->node = this->node->parent->parent;
				else
					this->node = 0x0;
				return (tmp);
			}

			iterator&		operator--() {
				typename Rb_tree_type::node			*buff = Rb_tree_type::returnSuccessor(this->node);
				
				if (buff && !buff->sentinel)
					this->node = buff;
				else if (buff && !buff->sentinel && !this->node->isLeftChild 
						&& !this->node->parent->sentinel)
					this->node = this->node->parent;
				else if (buff && !buff->sentinel && this->node->isLeftChild && !this->node->parent->sentinel 
								&& !this->node->parent->parent->sentinel)
					this->node = this->node->parent->parent;
				else
					this->node = 0x0;
				return (*this);
			}

			iterator		operator--(int) {
				iterator							tmp(*this);
				typename Rb_tree_type::node			*buff = Rb_tree_type::returnSuccessor(this->node);
				
				if (buff && !buff->sentinel)
					this->node = buff;
				else if (buff && !buff->sentinel && !this->node->isLeftChild 
						&& !this->node->parent->sentinel)
					this->node = this->node->parent;
				else if (buff && !buff->sentinel && this->node->isLeftChild && !this->node->parent->sentinel 
								&& !this->node->parent->parent->sentinel)
					this->node = this->node->parent->parent;
				else 
					this->node = 0x0;
				return (tmp);
			}

			////////////////////////////////////////////////////////////////////////////////
			/* Assignation operator */

			iterator		operator=(const iterator param) {
				if (this->node == param->node)
					return (*this);
				else
					this->node = param->node;
				return (*this);
			}

			////////////////////////////////////////////////////////////////////////////////
			/* Comparaison opperator */
			

		private:
			value_type		*node;
			value_type		*begin;
			value_type		*end;
	};
}