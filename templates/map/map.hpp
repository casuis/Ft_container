/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimon <asimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 12:18:10 by asimon            #+#    #+#             */
/*   Updated: 2023/01/23 12:54:53 by asimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Comment her for tester */
# include <ftnspace.hpp>

/* Decomment her for tester */
// # include <../../private/ftnspace.hpp>

namespace ft {
	
	template < class Key, class T, class Compare, class Allocator>
	class map {
		
		public:
			typedef Key																		key_type;
			typedef T																		mapped_type;
			typedef ft::pair<const Key, T>													value_type;
			typedef std::size_t																size_type;
			typedef std::ptrdiff_t															difference_type;
			typedef Compare																	key_compare;
			typedef Allocator																allocator_type;
			typedef value_type&																reference;
			typedef const value_type&														const_reference;
			typedef	typename Allocator::pointer												pointer;
			typedef	typename Allocator::const_pointer										const_pointer;
			typedef	ft::_Rb_tree_iterator< typename ft::_Rb_tree<Key, T>::node >			iterator;
			typedef	ft::_Rb_tree_iterator< const typename ft::_Rb_tree<Key, T>::node>		const_iterator;
			// typedef	to_do						reverse_iterator;
			// typedef	to_do						const_reverse_iterator;
	
			////////////////////////////////////////////////////////////////////////////////
			// TO DO | CHECK THIS FCTN
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
			
			map() {
				return ;
			}
			
			~map() {}


			iterator	begin() const {
				iterator ret(this->_Rb_tree.getFirst());
				
				return (ret);
			}

			iterator	end() const {
				iterator ret(this->_Rb_tree.sentinel);

				return (ret);
			}

			////////////////////////////////////////////////////////////////////////////////
		
			ft::map<Key, T>		operator=(ft::map<Key,T> const &rhs) {
				if (this->_Rb_tree == rhs._Rb_tree)
					return (*this);
				this->_Rb_tree = rhs._Rb_tree;
				return (*this);
			}

			////////////////////////////////////////////////////////////////////////////////
			
			bool		empty() const {
				return (this->_Rb_tree.root == 0x0);
			}

			size_t		size() const {
				return (this->_Rb_tree.sentinel->size);
			}

			size_t		max_size() const {
				return (this->_alloc.max_size());
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
				
				if (!node){
					node = _Rb_tree.createNode(val);
					_Rb_tree.addNode(node);
					ret->second = true;
				}
				else
					ret->second = false;
				ret->first = iterator(node);
				return (ret); 
			}
			
			iterator	insert(iterator position, const value_type& val) {
				insert(val);
				return (position);
			}
			
			template <class InputIterator> 
			void		insert(InputIterator first, InputIterator last) {
				for (; first != last; first++) {
					insert(first->node->pair);
				}
				return ;
			}

			////////////////////////////////////////////////////////////////////////////////
			
			void erase (iterator position) {
				_Rb_tree.deleteNode(*position);
			}
			
			size_type erase (const key_type& k) {
				typename ft::_Rb_tree<Key, T>::node		*node = _Rb_tree.searchNode(k);

				if (!node)
					return (0);
				_Rb_tree.deleteNode(node);
				return (1);
			}
			
			void erase (iterator first, iterator last) {
				for (; first != last; first++) {
					_Rb_tree.deleteNode(*first);
				}
				return ;
			}

			////////////////////////////////////////////////////////////////////////////////
			
			void swap (map& x) {
				ft::_Rb_tree<Key, T>		tmp = _Rb_tree;
				
				if (x == _Rb_tree)
					return ;
				_Rb_tree = x;
				x = tmp;
				return ;
			}

			////////////////////////////////////////////////////////////////////////////////
			
			void clear() {
				ft::_Rb_tree<Key, T>		tmp;
				
				this->_Rb_tree = tmp;
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
			key_compare		comp = key_compare();
				for (iterator first = this->begin(), last = this->end(); first != last; first++) {
					if (comp(first->first, k))
						return (first);
				}
				return (this->end());
			}
			
			const_iterator	lower_bound(const key_type& k) const {
				for (iterator first = this->begin(), last = this->end(); first != last; first++) {
					if (comp(first->first, k))
						return (first);
				}
				return (const_iterator(_Rb_tree.sentinel));
			}
			
			iterator		upper_bound(const key_type& k) {
				for (iterator first = this->begin(), last = this->end(); first != last; first++) {
					if (comp(k, first->first))
						return (first);
				}
				return (this->end());
			}
			
			const_iterator	upper_bound(const key_type& k) const {
				for (iterator first = this->begin(), last = this->end(); first != last; first++) {
					if (comp(k, first->first))
						return (first);
				}
				return (const_iterator(_Rb_tree.sentinel));
			}

			pair<const_iterator,const_iterator> equal_range (const key_type& k) const {
				for (const_iterator first = const_iterator(_Rb_tree.getFirst()), last = const_iterator(_Rb_tree.sentinel); first != last; first++) {
					if (key_compare(first->first, k) && key_compare(k, first->first))
						return (ft::pair<const_iterator, const_iterator>(first, first));
				}
				return (ft::pair<const_iterator, const_iterator>(upper_bound(k), upper_bound(k)));
			}
			
			pair<iterator,iterator>             equal_range (const key_type& k) {
				for (iterator first = iterator(_Rb_tree.getFirst()), last = iterator(_Rb_tree.sentinel); first != last; first++) {
					if (key_compare(first->first, k) && key_compare(k, first->first))
						return (ft::pair<iterator, iterator>(first, first));
				}
				return (ft::pair<iterator, iterator>(upper_bound(k), upper_bound(k)));
			}
			
			////////////////////////////////////////////////////////////////////////////////
			
			allocator_type get_allocator() const {
				return (this->_alloc);
			}
			
		private:
			Allocator										_alloc;
			ft::_Rb_tree<key_type, mapped_type, key_compare>				_Rb_tree;
			
	};
	
}