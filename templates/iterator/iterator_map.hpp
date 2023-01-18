/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_map.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimon <asimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 18:23:17 by asimon            #+#    #+#             */
/*   Updated: 2023/01/18 22:54:04 by asimon           ###   ########.fr       */
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
			
			_Rb_tree_iterator(value_type&	param): node(&param) {}

			_Rb_tree_iterator(): node(value_type()) {}
			
			~_Rb_tree_iterator() {}

			value_type&		operator*() {
				return (*node);
			}

			typename value_type::pair_type*		operator->() {
				return (&(node->pair));
			}

			// pas d'operateur []

			////////////////////////////////////////////////////////////////////////////////
			/* incrementation/decr ope */
			/*
			**	need to check if it segfault 
			*/
		
			iterator&		operator++() {
				if (!Rb_tree_type::returnPredecessor(this->node)->sentinel)
					this->node = Rb_tree_type::returnPredecessor(this->node);
				else if (Rb_tree_type::returnPredecessor(this->node)->sentinel 
							&& this->node->isLeftChild && !this->node->parent->sentinel)
					this->node = this->node->parent;
				else if (Rb_tree_type::returnPredecessor(this->node) 
							&& !this->node->isLeftChild && !this->node->parent->sentinel 
								&& !this->node->parent->parent->sentinel)
					this->node = this->node->parent->parent;
				else
					this->node = 0x0;
				return (*this);
			}

			iterator		operator++(int) {
				iterator		tmp(*this);
				
				if (!Rb_tree_type::returnPredecessor(this->node)->sentinel)
					this->node = Rb_tree_type::returnPredecessor(this->node);
				else if (Rb_tree_type::returnPredecessor(this->node)->sentinel 
							&& this->node->isLeftChild && !this->node->parent->sentinel)
					this->node = this->node->parent;
				else if (Rb_tree_type::returnPredecessor(this->node) 
							&& !this->node->isLeftChild && !this->node->parent->sentinel 
								&& !this->node->parent->parent->sentinel)
					this->node = this->node->parent->parent;
				else
					this->node = 0x0;
				return (tmp);
			}

			iterator&		operator--() {
				if (!Rb_tree_type::returnSuccessor(this->node)->sentinel)
					this->node = Rb_tree_type::returnSuccessor(this->node);
				else if (Rb_tree_type::returnSuccessor(this->node)->sentinel 
							&& !this->node->isLeftChild && !this->node->parent->sentinel)
					this->node = this->node->parent;
				else if (Rb_tree_type::returnSuccessor(this->node) 
							&& this->node->isLeftChild && !this->node->parent->sentinel 
								&& !this->node->parent->parent->sentinel)
					this->node = this->node->parent->parent;
				else
					this->node = 0x0;
				return (*this);
			}

			iterator		operator--(int) {
				iterator		tmp(*this);
				
				if (!Rb_tree_type::returnSuccessor(this->node)->sentinel)
					this->node = Rb_tree_type::returnSuccessor(this->node);
				else if (Rb_tree_type::returnSuccessor(this->node)->sentinel 
							&& !this->node->isLeftChild && !this->node->parent->sentinel)
					this->node = this->node->parent;
				else if (Rb_tree_type::returnSuccessor(this->node) 
							&& this->node->isLeftChild && !this->node->parent->sentinel 
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
			
			bool			operator==(iterator const & rhs) {
				return (this->node == rhs.node);
			}

			bool			operator!=(iterator const & rhs) {
				return (this->node != rhs.node);
			}
			
			bool			operator>=(iterator const & rhs) {
				return (this->node.pair.first >= rhs.pair.first);
			}
			
			bool			operator>(iterator const & rhs) {
				return (this->node.pair.first > rhs.pair.first);
			}
			
			bool			operator<(iterator const & rhs) {
				return (rhs > *this);	
			}
			
			bool			operator<=(iterator const & rhs) {
				return (rhs >= *this);
			}

		private:
			value_type		*node;
	};
}