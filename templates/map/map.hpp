/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimon <asimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 12:18:10 by asimon            #+#    #+#             */
/*   Updated: 2023/01/21 13:04:55 by asimon           ###   ########.fr       */
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
					value_compare (Compare c) : comp(c) {}  // constructed with map's comparison object
				
				public:
					typedef bool result_type;
					typedef value_type first_argument_type;
					typedef value_type second_argument_type;
					bool operator() (const value_type& x, const value_type& y) const
					{
						return comp(x.first, y.first);
					}
			};
			
			ft::_Rb_tree<key_type, mapped_type>				_Rb_tree;

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
					node = _Rb_tree.createNode(val)
					_Rb_tree.addNode(node);
					ret->second = true;
				}
				else
					ret->second = false;
				ret->first = iterator(node);
				return; 
			}
			
			// iterator	insert(iterator position, const value_type& val);
			
			// template <class InputIterator> 
			// void		insert(InputIterator first, InputIterator last);

			
		private:
			Allocator					_alloc;
			
	};
	
}