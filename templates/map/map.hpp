/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimon <asimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 12:18:10 by asimon            #+#    #+#             */
/*   Updated: 2023/01/20 16:31:45 by asimon           ###   ########.fr       */
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
				// TEST HER
				this->_Rb_tree.addNode(this->_Rb_tree.createNode(1, 10));
				this->_Rb_tree.print();
				return ;
			}
			
			~map() {}


			iterator	begin() const {
				iterator ret(this->_Rb_tree.getFirst(), this->_Rb_tree.sentinel);
				
				return (ret);
			}

			iterator	end() const {
				iterator ret(this->_Rb_tree.sentinel, this->_Rb_tree.getLast());

				return (ret);
			}
			
			mapped_type& 	operator[](key_type key) {
				typename ft::_Rb_tree<key_type, mapped_type>::node	*tmp = _Rb_tree.searchNode(key);
				
				if (!tmp) {
					tmp = _Rb_tree.createNode(key, mapped_type());
					_Rb_tree.addNode(tmp);
				}
				return (tmp->pair.second);
			}
		
			ft::map<Key, T>		operator=(ft::map<Key,T> const &rhs) {
				if (this->_Rb_tree == rhs._Rb_tree)
					return (*this);
				this->_Rb_tree = rhs._Rb_tree;
				return (*this);
			}
			
		private:
			Allocator					_alloc;
			
	};
	
}