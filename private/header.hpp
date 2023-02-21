/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimon <asimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 13:46:45 by asimon            #+#    #+#             */
/*   Updated: 2023/02/21 21:22:59 by asimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __HEADER_CONTAINER_HPP__
# define __HEADER_CONTAINER_HPP__

# include <memory>
# include <cmath>
# include <stdlib.h>

/* lib for exception */
# include <stdexcept>

/* stream lib, std::cout / cin  */
# include <iostream>

# include <stack>

/* vector for std */
# include <vector>

# include <set>

/* lib for system fctn */
# include <cstdlib>

/* structur ft::pair */
# include "../templates/map/pair.hpp"

# define M_YELLOW "\033[1;33m"
# define M_GREEN	"\033[1;32m"
# define M_RED	"\033[1;31m"
# define M_BLACK	"\033[1;30m"
# define M_CYAN	"\033[1;36m"
# define M_RESET	"\033[0m"

namespace ft {


	template <typename Key, typename Value>
	class Node;


	template <typename Key>
	class Node_set;

	template <typename Key, typename Compare = std::less<Key>, typename NodeType = ft::Node_set<Key>, class Allocator = std::allocator<NodeType> >
	class _Rb_tree_set;

	template <typename Key, typename Value, typename Compare = std::less<Key>,  typename NodeType = ft::Node<Key, Value>, class Allocator = std::allocator<NodeType> >
	class _Rb_tree;

	template <typename Key, typename Value>
	class NodeSentinel;

	template < class Key,  class T, class Compare = std::less<Key>, class Allocator = std::allocator<ft::pair<const Key, T> > >
	class map;

	template < class T, class Compare = std::less<T>, class Allocator = std::allocator<T> >
	class set;
	
	template <class T, class Allocator = std::allocator<T> >
	class vector;
	
	template <class T, class Container = ft::vector<T> >
	class stack;

	template <typename T, typename N>
	class _Rb_tree_iterator;

	template <typename Iter>
	class _Rb_tree_rev_iterator;

	template <typename T = void>
	class RandomIterator;

}


#endif