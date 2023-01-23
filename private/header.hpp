/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimon <asimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 13:46:45 by asimon            #+#    #+#             */
/*   Updated: 2023/01/23 13:16:18 by asimon           ###   ########.fr       */
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

/* vector for std */
# include <vector>

/* lib for system fctn */
# include <cstdlib>

/* structur ft::pair */
// # include <pair.hpp>

# include "../templates/map/pair.hpp"

# define YELLOW "\033[1;33m"
# define GREEN	"\033[1;32m"
# define RED	"\033[1;31m"
# define BLACK	"\033[1;30m"
# define CYAN	"\033[1;36m"
# define RESET	"\033[0m"

namespace ft {


	template <typename Key, typename Value>
	class Node;

	template <typename Key, typename Value, typename Compare = std::less<Key>,  typename NodeType = ft::Node<Key, Value>, class Allocator = std::allocator<NodeType> >
	class _Rb_tree;

	template <typename Key, typename Value>
	class NodeSentinel;

	template < class Key,  class T, class Compare = std::less<Key>, class Allocator = std::allocator<ft::pair<const Key, T> > >
	class map;
	
	template <class T, class Allocator = std::allocator<T> >
	class vector;
	
	template <class T, class Container = ft::vector<T> >
	class stack;

	template <typename T>
	class _Rb_tree_iterator;

}


#endif