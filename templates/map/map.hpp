/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimon <asimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 12:18:10 by asimon            #+#    #+#             */
/*   Updated: 2023/02/02 18:09:39 by asimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _MAP_CONTAINER_
# define _MAP_CONTAINER_
/* Comment her for tester */
// # include <ftnspace.hpp>

/* Decomment her for tester */
# include "../../private/ftnspace.hpp"

namespace ft {
	
	template < class Key, class T, class Compare, class Allocator>
	class map {
		
		public:
		
			typedef Key																					key_type;
			typedef T																					mapped_type;
			typedef ft::pair<Key, T>																	value_type;
			typedef std::size_t																			size_type;
			typedef std::ptrdiff_t																		difference_type;
			typedef Compare																				key_compare;
			typedef Allocator																			allocator_type;
			typedef value_type&																			reference;
			typedef const value_type&																	const_reference;
			typedef	typename Allocator::pointer															pointer;
			typedef	typename Allocator::const_pointer													const_pointer;
			typedef	ft::_Rb_tree_iterator< value_type, typename ft::_Rb_tree<Key, T>::node >			iterator;
			typedef	ft::_Rb_tree_iterator< const value_type, typename ft::_Rb_tree<Key, T>::node>		const_iterator;
			typedef	ft::ReverseIterator<iterator>														reverse_iterator;
			typedef	ft::ReverseIterator<const_iterator>													const_reverse_iterator;
	
			////////////////////////////////////////////////////////////////////////////////
			class value_compare
			{   // in C++98, it is required to inherit binary_function<value_type,value_type,bool>
				friend class map;
				
				protected:
					Compare comp;
					value_compare(Compare c) : comp(c) {}  // constructed with map's comparison object
				
				public:
					typedef bool result_type;
					typedef value_type first_argument_type;
					typedef value_type second_argument_type;
					bool operator() (const value_type& x, const value_type& y) const
					{
						return comp(x.first, y.first);
					}
			};
			////////////////////////////////////////////////////////////////////////////////

		public:
			
			map(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
			:_comp(comp), _alloc(alloc) {
				return ;
			}

			template <class InputIterator>  
			map(InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
			:_comp(comp), _alloc(alloc){
				insert(first, last);
				return ;
			}
			
			map (const map& x) {
				*this = x;
				return ;
			}

			~map() {}

			iterator	begin() const {
				return (iterator(this->_Rb_tree.getFirst()));
			}

			iterator	end() const {
				return (iterator(this->_Rb_tree.sentinel));
			}

			////////////////////////////////////////////////////////////////////////////////
		
			ft::map<Key, T, Compare>&		operator=(ft::map<Key,T, Compare> const &rhs) {
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
			
			mapped_type& 	operator[](key_type key) {
				typename ft::_Rb_tree<key_type, mapped_type>::node	*tmp = _Rb_tree.searchNode(key);
				
				if (!tmp) {
					tmp = _Rb_tree.createNode(key, mapped_type());
					_Rb_tree.addNode(tmp);
				}
				return (tmp->pair.second);
			}
			
			mapped_type&	at(const key_type& k) {
				typename ft::_Rb_tree<Key, T>::node	*node = _Rb_tree.searchNode(k);

				if (node == 0x0)
					throw (std::out_of_range("Out of Range"));
				return (node);
			}
			
			////////////////////////////////////////////////////////////////////////////////
			
			ft::pair<iterator,bool>		insert(const value_type& val) {
				typename ft::_Rb_tree<Key, T>::node		*node = _Rb_tree.searchNode(val.first);
				ft::pair<iterator, bool>				ret;
				
				if (!node) {
					node = _Rb_tree.createNode(val.first, val.second);
					_Rb_tree.addNode(node);
					ret.second = true;
				}
				else
					ret.second = false;
				ret.first = iterator(node);
				return (ret); 
			}
			
			iterator	insert(iterator position, const value_type& val) {
				insert(val);
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
				std::cout << "start erase pos" << std::endl;
				std::cout << "pos->first: " << position->first << std::endl;
				_Rb_tree.deleteNode(_Rb_tree.searchNode(position->first));
			}
			
			size_type erase (const key_type& k) {
				std::cout << "start erase key_type" << std::endl;
				typename ft::_Rb_tree<Key, T>::node		*node = _Rb_tree.searchNode(k);

				if (!node)
					return (0);
				_Rb_tree.deleteNode(node);
				return (1);
			}
			
			void erase (iterator first, iterator last) {
				std::cout << "start erase iter" << std::endl;
				while (first != last) {
					std::cout << "------------------ici" << std::endl;
					this->erase(first++);

				}
				return ;
			}

			////////////////////////////////////////////////////////////////////////////////
			
			void swap (map& x) {
				typename ft::_Rb_tree<Key, T, Compare>::node				tmp_root = _Rb_tree.root;
				typename ft::_Rb_tree<Key, T, Compare>::node				tmp_sentinel = _Rb_tree.sentinel;
				typename ft::_Rb_tree<Key, T, Compare>::key_compare			tmp_comp = _Rb_tree._comp;
				typename ft::_Rb_tree<Key, T, Compare>::Allocator_type		tmp_alloc = _Rb_tree._alloc;
				
				
				if (&(x._Rb_tree) == &(_Rb_tree))
					return ;
				
				_Rb_tree.root = x._Rb_tree.root;
				_Rb_tree.sentinel = x._Rb_tree.sentinel;
				_Rb_tree._comp = x._Rb_tree._comp;
				_Rb_tree._alloc = x._Rb_tree._alloc;

				x._Rb_tree.root = tmp_root;
				x._Rb_tree.sentinel = tmp_sentinel;
				x._Rb_tree._alloc = tmp_alloc;
				x._Rb_tree._comp = tmp_comp;
				return ;
			}

			////////////////////////////////////////////////////////////////////////////////
			
			void clear() {
				this->_Rb_tree.freeRb_tree();
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
				typename ft::_Rb_tree<Key, T>::node		*node = _Rb_tree.searchNode(k);
				
				if (!node)
					return (this->end());
				return (iterator(node));
			}
			
			const_iterator	find(const key_type& k) const {
				typename ft::_Rb_tree<Key, T>::node		*node = _Rb_tree.searchNode(k);
				
				if (!node)
					return (const_iterator(_Rb_tree.sentinel));
				return (const_iterator(node));
			}

			////////////////////////////////////////////////////////////////////////////////
			
			size_type count (const key_type& k) const {
				typename ft::_Rb_tree<Key, T>::node		*node = _Rb_tree.searchNode(k);
				
				if (!node)
					return (0);
				return (1);
			}

			////////////////////////////////////////////////////////////////////////////////
			
			iterator	lower_bound(const key_type& k) {
				for (iterator first = this->begin(), last = this->end(); first != last; first++) {
					if (_comp(k, first->first) || (!_comp(k, first->first) && !_comp(first->first, k)))
						return (first);
				}
				return (this->end());
			}
			
			const_iterator	lower_bound(const key_type& k) const {
				for (const_iterator first = this->begin(), last = this->end(); first != last; first++) {
					if (_comp(k, first->first) || (!_comp(k, first->first) && !_comp(first->first, k)))
						return (first);
				}
				return (const_iterator(_Rb_tree.sentinel));
			}
			
			iterator		upper_bound(const key_type& k) {
				for (iterator first = this->begin(), last = this->end(); first != last; first++) {
					if (_comp(k, first->first))
						return (first);
				}
				return (this->end());
			}
			
			const_iterator	upper_bound(const key_type& k) const {
				for (const_iterator first = this->begin(), last = this->end(); first != last; first++) {
					if (_comp(k, first->first))
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
			
		private:
			Compare															_comp;
			Allocator														_alloc;
			ft::_Rb_tree<key_type, mapped_type, key_compare>				_Rb_tree; 
			
	};

	template <class Key, class T, class Compare, class Alloc>
	bool	operator==(const map<Key, T, Compare, Alloc>& lhs, const map<Key, T, Compare, Alloc>& rhs)
	{
		return (ft::equal(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	}

	template <class Key, class T, class Compare, class Alloc>
	bool	operator!=(const map<Key, T, Compare, Alloc>& lhs, const map<Key, T, Compare, Alloc>& rhs)
	{
		return (!(lhs == rhs));
	}

	template <class Key, class T, class Compare, class Alloc>
	bool	operator<(const map<Key, T, Compare, Alloc>& lhs, const map<Key, T, Compare, Alloc>& rhs)
	{
		return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	}

	template <class Key, class T, class Compare, class Alloc>
	bool	operator<=(const map<Key, T, Compare, Alloc>& lhs, const map<Key, T, Compare, Alloc>& rhs)
	{
		return (!(rhs < lhs));
	}

	template <class Key, class T, class Compare, class Alloc>
	bool	operator>(const map<Key, T, Compare, Alloc>& lhs, const map<Key, T, Compare, Alloc>& rhs)
	{
		return (rhs < lhs);
	}

	template <class Key, class T, class Compare, class Alloc>
	bool	operator>=(const map<Key, T, Compare, Alloc>& lhs, const map<Key, T, Compare, Alloc>& rhs)
	{
		return (!(lhs < rhs));
	}

	template <class Key, class T, class Compare, class Alloc>
	void	swap(map<Key, T, Compare, Alloc>& a, map<Key, T, Compare, Alloc>& b)
	{
		a.swap(b);
	}

}

#endif