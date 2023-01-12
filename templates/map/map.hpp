/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimon <asimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 12:18:10 by asimon            #+#    #+#             */
/*   Updated: 2023/01/12 13:24:00 by asimon           ###   ########.fr       */
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
			typedef Key									key_type;
			typedef T									mapped_type;
			typedef std::pair<const Key, T>				value_type;
			typedef std::size_t							size_type;
			typedef std::ptrdiff_t						difference_type;
			typedef Compare								key_compare;
			typedef Allocator							allocator_type;
			typedef value_type&							reference;
			typedef const value_type&					const_reference;
			typedef	typename Allocator::pointer			pointer;
			typedef	typename Allocator::const_pointer	const_pointer;
			// typedef	_Rb_tree_iterator<>				iterator;
			// typedef	to_do						const_iterator;
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
			
			ft::Bst<key_type, mapped_type>				bst;

			////////////////////////////////////////////////////////////////////////////////
			
			map() {
				this->bst.addNode(this->bst.createNode(1, 10));
				this->bst.print();
				return ;
			}
			
			~map() {}
		
		private:
			Allocator					_alloc;
			
	};
	
}