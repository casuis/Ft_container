/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator_map.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimon <asimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 19:49:47 by asimon            #+#    #+#             */
/*   Updated: 2023/02/21 22:59:26 by asimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __REV_ITERATOR_MAP__
# define __REV_ITERATOR_MAP__

# include "../../private/header.hpp"

namespace ft {

	template <typename Iter>
	class _Rb_tree_rev_iterator {
		
		public:
			typedef typename ft::iterator_traits<Iter>::reference 			reference;
			typedef typename ft::iterator_traits<Iter>::value_type 			value_type;
			typedef typename ft::iterator_traits<Iter>::pointer				pointer;
			typedef typename ft::iterator_traits<Iter>::difference_type		difference_type;
			typedef typename ft::iterator_traits<Iter>::iterator_category	iterator_category;
			typedef	Iter													iterator_type;
			typedef	_Rb_tree_rev_iterator< Iter >							reverse_iterator;

			////////////////////////////////////////////////////////////////////////////////

			_Rb_tree_rev_iterator(): _current() {}
			
			_Rb_tree_rev_iterator(iterator_type src): _current(iterator_type(src)) {}

			template <class U>
			_Rb_tree_rev_iterator( const _Rb_tree_rev_iterator<U> &src) : _current(src.base()) {}

			_Rb_tree_rev_iterator( const _Rb_tree_rev_iterator &src) : _current(src.base()) {}
			
			~_Rb_tree_rev_iterator() {}

			////////////////////////////////////////////////////////////////////////////////

			reference		operator*() const {
				iterator_type tmp(this->_current);
				return (*--tmp);
			}

			pointer		operator->() const {
				return (&(operator*()));
			}

			////////////////////////////////////////////////////////////////////////////////
			/* incrementation/decr ope */
		
			reverse_iterator&		operator--() {
				++(this->_current);
				return (*this);
				
			}

			reverse_iterator		operator--(int) {
				reverse_iterator		tmp(*this);
				--(*this);
				return (tmp);
			}

			reverse_iterator&		operator++() {
				--this->_current;
				return (*this);
			}

			reverse_iterator		operator++(int) {
				reverse_iterator	tmp(*this);
				++(*this);
				return (tmp);
			}

			////////////////////////////////////////////////////////////////////////////////
			/* Assignation operator */

			reverse_iterator		operator=(const reverse_iterator param) {
				if (this->_current == param._current)
					return (*this);
				else
					this->_current = param._current;
				return (*this);
			}
			
			template <class U>
			bool	operator==(const ft::_Rb_tree_rev_iterator<U>& src) const {
				return (this->_current == src.base());
			}

			template <class U>
			bool	operator!=(const ft::_Rb_tree_rev_iterator<U>& src) const {
				return (this->_current != src.base());
			}

			////////////////////////////////////////////////////////////////////////////////
			
			iterator_type		base() const { return (this->_current); }
			
		private:
		
			iterator_type		_current;

	};


	////////////////////////////////////////////////////////////////////////////////
	
}

#endif