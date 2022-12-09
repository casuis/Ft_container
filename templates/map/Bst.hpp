/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bst.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimon <asimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 13:38:49 by asimon            #+#    #+#             */
/*   Updated: 2022/12/09 16:37:03 by asimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.hpp>

namespace ft{

	template <typename Key, typename Value>
	class Bst;

	template <typename Key, typename Value>
	class Node;

	template <typename Key, typename Value, typename Allocator = std::allocator<std::pair<const Key, Value> > >
	class Node
	{
		friend 	ft::Bst;

		public:
		////////////////////////////////////////////////////////////////////////////////
		/*                              Member Type                                   */
		////////////////////////////////////////////////////////////////////////////////
		typedef Allocator			allocator_type;
		
		
		private:
		////////////////////////////////////////////////////////////////////////////////
		/*                              Attributs                                     */
		////////////////////////////////////////////////////////////////////////////////
			Node*		left;
			Node*		right;
			Node*		parent;
			
			Key*		key;
			Value*		value;
			Allocator	_alloc;
		
		////////////////////////////////////////////////////////////////////////////////
		/*                              Functions                                     */
		////////////////////////////////////////////////////////////////////////////////
			Node(Key& key, Value& value, const allocator_type& alloc = allocator_type())
			: key(key), value(value), _alloc(alloc) {};
			Node() {};
			~Node() {};
	};
	
	template <typename Key, typename Value, class Allocator = std::allocator<std::pair<const Key, value> > >
	class Bst
	{
		friend			ft::map;
		
		public:
		////////////////////////////////////////////////////////////////////////////////
		/*                              Member Type                                   */
		////////////////////////////////////////////////////////////////////////////////
			typedef Allocator		allocator_type;
			typedef Key				key_type;
			typedef Value			value_type;
			typedef Key*			key_pointer;
			typedef Value*			value_pointer;
			
		private:
		////////////////////////////////////////////////////////////////////////////////
		/*                              Attributs                                     */
		////////////////////////////////////////////////////////////////////////////////
			Node<Key, Value, allocator_type>		*root;
			Allocator								_alloc;

		////////////////////////////////////////////////////////////////////////////////
		/*                              Constructors                                  */
		////////////////////////////////////////////////////////////////////////////////
			Bst(const allocator_type& alloc = allocator_type()): _alloc(alloc), root(0x0) {};
			~Bst() {};

		////////////////////////////////////////////////////////////////////////////////
		/*                              Methodes                                      */
		////////////////////////////////////////////////////////////////////////////////
			Node<key_type, value_type>*	newNode(key_type key, value_type value) {
				Node<key_type, value_type>		newOne(key, value);
			};
			
			
	};

}