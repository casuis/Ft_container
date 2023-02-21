/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimon <asimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 20:38:00 by asimon            #+#    #+#             */
/*   Updated: 2023/02/21 17:41:18 by asimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __SET_HPP__
# define __SET_HPP__

# include "../../private/ftnspace.hpp"

namespace ft {
	
	template < class T, class Compare, class Allocator >
	class set {
		
	public:
		
			typedef T																					key_type;
			typedef T																					value_type;
			typedef std::size_t																			size_type;
			typedef std::ptrdiff_t																		difference_type;
			typedef Compare																				key_compare;
			typedef Allocator																			allocator_type;
			typedef value_type&																			reference;
			typedef const value_type&																	const_reference;
			typedef	typename Allocator::pointer															pointer;
			typedef	typename Allocator::const_pointer													const_pointer;
			
			typedef	ft::_Rb_tree_iterator_set< const value_type, typename ft::_Rb_tree_set<T>::node >			iterator;
			typedef	ft::_Rb_tree_iterator_set< const value_type, typename ft::_Rb_tree_set<T>::node>	const_iterator;
			
			typedef	ft::_Rb_tree_rev_iterator< iterator >												reverse_iterator;
			typedef	ft::_Rb_tree_rev_iterator< const_iterator >											const_reverse_iterator;
	
			////////////////////////////////////////////////////////////////////////////////
			class value_compare
			{
				friend class set;
				
				protected:
					Compare comp;
					value_compare(Compare c) : comp(c) {}
				
				public:
					typedef bool result_type;
					typedef value_type first_argument_type;
					typedef value_type second_argument_type;
					bool operator() (const value_type& x, const value_type& y) const
					{
						return comp(x, y);
					}
			};
			////////////////////////////////////////////////////////////////////////////////

		public:
			
			set(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
			:_comp(comp), _alloc(alloc) {
				return ;
			}

			template <class InputIterator>  
			set(InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
			:_comp(comp), _alloc(alloc){
				insert(first, last);
				return ;
			}
			
			set (const set& x) {
				*this = x;
				return ;
			}

			~set() {}

			////////////////////////////////////////////////////////////////////////////////

			iterator	begin() {
				return (iterator(this->_Rb_tree.getFirst()));
			}

			const_iterator	begin() const {
				return (const_iterator(this->_Rb_tree.getFirst()));
			}


			iterator	end() {
				return (iterator(this->_Rb_tree.sentinel));
			}

			const_iterator	end() const {
				return (const_iterator(this->_Rb_tree.sentinel));
			}

			reverse_iterator	rbegin() {
				iterator	ret = this->end();
				return (ret);
			}

			const_reverse_iterator	rbegin() const {
				const_iterator	ret = this->end();
				return (ret);
			}

			reverse_iterator	rend() {
				return (reverse_iterator(this->begin()));
			}
			
			const_reverse_iterator	rend() const {
				return (const_reverse_iterator(this->begin()));
			}

			////////////////////////////////////////////////////////////////////////////////
		
			ft::set<T, Compare>&		operator=(ft::set<T, Compare> const &rhs) {
				if (this == &rhs)
					return (*this);
				if (!this->empty())
					this->clear();
				this->_comp = rhs._comp;
				this->_alloc = rhs._alloc;
				
				this->insert(rhs.begin(), rhs.end());
				return (*this);
			}

			////////////////////////////////////////////////////////////////////////////////
			
			bool		empty() const {
				return (this->_Rb_tree.size == 0);
			}

			size_t		size() const {
				return (this->_Rb_tree.size);
			}

			size_t		max_size() const {
				return (this->_Rb_tree.max_size());
			}

			////////////////////////////////////////////////////////////////////////////////
			
			ft::pair<iterator,bool>		insert(const value_type& val) {
				typename ft::_Rb_tree_set<T>::node		*node = _Rb_tree.searchNode(val);
				ft::pair<iterator, bool>				ret;
				
				if (!node) {
					node = _Rb_tree.createNode(val);
					_Rb_tree.addNode(node);
					ret.second = true;
				}
				else
					ret.second = false;
				ret.first = iterator(node);
				return (ret); 
			}
			
			iterator	insert(iterator position, const value_type& val) {
				ft::pair<iterator, bool>	ret = insert(val);
				position = ret.first;
				return (position);
			}
			
			template <class InputIterator> 
			void		insert(InputIterator first, InputIterator last) {
				for (; first != last; first++)
					insert(*first);
				return ;
			}

			////////////////////////////////////////////////////////////////////////////////
			
			void erase (iterator position) {
				_Rb_tree.deleteNode(_Rb_tree.searchNode(*position));
			}
			
			size_type erase (const key_type& k) {
				typename ft::_Rb_tree_set<T, Compare>::node		*node = _Rb_tree.searchNode(k);

				if (!node)
					return (0);
				_Rb_tree.deleteNode(node);
				return (1);
			}
			
			void erase (iterator first, iterator last) {
				while (first != last)
					this->erase(first++);
				return ;
			}

			////////////////////////////////////////////////////////////////////////////////
			
			void swap (set& x) {
				typename ft::_Rb_tree_set<T, Compare>::node					*tmp_root = _Rb_tree.root;
				typename ft::_Rb_tree_set<T, Compare>::node					*tmp_sentinel = _Rb_tree.sentinel;
				typename ft::_Rb_tree_set<T, Compare>::key_compare			tmp_comp = _Rb_tree._comp;
				typename ft::_Rb_tree_set<T, Compare>::allocator_type		tmp_alloc = _Rb_tree._alloc;
				size_t														tmp_size = _Rb_tree.size;
				
				
				if (&(x._Rb_tree) == &(_Rb_tree))
					return ;
				
				_Rb_tree.root = x._Rb_tree.root;
				_Rb_tree.sentinel = x._Rb_tree.sentinel;
				_Rb_tree._comp = x._Rb_tree._comp;
				_Rb_tree._alloc = x._Rb_tree._alloc;
				_Rb_tree.size = x._Rb_tree.size;

				x._Rb_tree.root = tmp_root;
				x._Rb_tree.sentinel = tmp_sentinel;
				x._Rb_tree._alloc = tmp_alloc;
				x._Rb_tree._comp = tmp_comp;
				x._Rb_tree.size = tmp_size;
				return ;
			}

			////////////////////////////////////////////////////////////////////////////////
			
			void clear() {
				this->_Rb_tree.freeRb_tree_set();
				return ;
			}
			
			////////////////////////////////////////////////////////////////////////////////

			key_compare key_comp() const {
				return (key_compare());
			}

			value_compare value_comp() const {
				return (value_compare(key_comp()));
			}

			////////////////////////////////////////////////////////////////////////////////
			
			iterator		find(const key_type& k) {
				typename ft::_Rb_tree_set<T>::node		*node = _Rb_tree.searchNode(k);
				
				if (!node)
					return (this->end());
				return (iterator(node));
			}
			
			const_iterator	find(const key_type& k) const {
				typename ft::_Rb_tree_set<T>::node		*node = _Rb_tree.searchNode(k);
				
				if (!node)
					return (const_iterator(_Rb_tree.sentinel));
				return (const_iterator(node));
			}

			////////////////////////////////////////////////////////////////////////////////
			
			size_type count (const key_type& k) const {
				typename ft::_Rb_tree_set<T>::node		*node = _Rb_tree.searchNode(k);
				
				if (!node)
					return (0);
				return (1);
			}

			////////////////////////////////////////////////////////////////////////////////
			
			iterator	lower_bound(const key_type& k) {
				for (iterator first = this->begin(), last = this->end(); first != last; first++) {
					if (_comp(k, *first) || (!_comp(k, *first) && !_comp(*first, k)))
						return (first);
				}
				return (this->end());
			}
			
			const_iterator	lower_bound(const key_type& k) const {
				for (const_iterator first = this->begin(), last = this->end(); first != last; first++) {
					if (_comp(k, *first) || (!_comp(k, *first) && !_comp(*first, k)))
						return (first);
				}
				return (const_iterator(_Rb_tree.sentinel));
			}
			
			iterator		upper_bound(const key_type& k) {
				for (iterator first = this->begin(), last = this->end(); first != last; first++) {
					if (_comp(k, *first))
						return (first);
				}
				return (this->end());
			}
			
			const_iterator	upper_bound(const key_type& k) const {
				for (const_iterator first = this->begin(), last = this->end(); first != last; first++) {
					if (_comp(k, *first))
						return (first);
				}
				return (const_iterator(_Rb_tree.sentinel));
			}

			pair<const_iterator,const_iterator> equal_range (const key_type& k) const {
				return (ft::pair<const_iterator, const_iterator>(lower_bound(k), upper_bound(k)));
			}
			
			pair<iterator,iterator>             equal_range (const key_type& k) {
				return (ft::pair<iterator, iterator>(lower_bound(k), upper_bound(k)));
			}
			
			////////////////////////////////////////////////////////////////////////////////
			
			allocator_type get_allocator() const {
				return (this->_alloc);
			}

			////////////////////////////////////////////////////////////////////////////////
			/* + DELETE FOR CORRECTION */

			void		print() {
				this->_Rb_tree.printAllRb_tree();
				return ;
			}
			
		private:
			Compare															_comp;
			Allocator														_alloc;
			ft::_Rb_tree_set<key_type, key_compare>							_Rb_tree; 
			
	};

	template <class T, class Compare, class Alloc>
	bool	operator==(const set<T, Compare, Alloc>& lhs, const set<T, Compare, Alloc>& rhs)
	{
		return (ft::equal(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	}

	template < class T, class Compare, class Alloc>
	bool	operator!=(const set<T, Compare, Alloc>& lhs, const set<T, Compare, Alloc>& rhs)
	{
		return (!(lhs == rhs));
	}

	template < class T, class Compare, class Alloc>
	bool	operator<(const set<T, Compare, Alloc>& lhs, const set<T, Compare, Alloc>& rhs)
	{
		return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	}

	template < class T, class Compare, class Alloc>
	bool	operator<=(const set<T, Compare, Alloc>& lhs, const set<T, Compare, Alloc>& rhs)
	{
		return (!(rhs < lhs));
	}

	template < class T, class Compare, class Alloc>
	bool	operator>(const set<T, Compare, Alloc>& lhs, const set<T, Compare, Alloc>& rhs)
	{
		return (rhs < lhs);
	}

	template < class T, class Compare, class Alloc>
	bool	operator>=(const set<T, Compare, Alloc>& lhs, const set<T, Compare, Alloc>& rhs)
	{
		return (!(lhs < rhs));
	}

	template < class T, class Compare, class Alloc>
	void	swap(set<T, Compare, Alloc>& a, set<T, Compare, Alloc>& b)
	{
		a.swap(b);
	}

}

#endif 