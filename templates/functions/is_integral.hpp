/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_integral.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimon <asimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 16:03:55 by asimon            #+#    #+#             */
/*   Updated: 2022/10/17 03:55:37 by asimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __IS_INTEGRAL_HPP__
# define __IS_INTEGRAL_HPP__

# include "../../private/header.hpp"

namespace ft{

/* Default template */
template < class T >
struct is_integral
{
	typedef T value_type;
	typedef ft::is_integral<T> type;
	static const bool		value = false;
};

////////////////////////////////////////////////////////////////////////////////
/* bool template */
template <>
struct is_integral <bool>
{
	typedef bool value_type;
	typedef ft::is_integral<bool> type;

	
	public :
		static const bool		value = true;
};

////////////////////////////////////////////////////////////////////////////////
/* Char Template */
template <>
struct is_integral <char>
{
	typedef char value_type;
	typedef ft::is_integral<char> type;

	
	public :
		static const bool		value = true;
};

////////////////////////////////////////////////////////////////////////////////
/* wchar_t template */
template <  >
struct is_integral <wchar_t>
{
	typedef wchar_t value_type;
	typedef ft::is_integral<wchar_t> type;

	
	public :
		static const bool		value = true;
};

////////////////////////////////////////////////////////////////////////////////
/* signed char template */
template <  >
struct is_integral<signed char>
{
	typedef signed char value_type;
	typedef ft::is_integral<signed char> type;

	
	public :
		static const bool		value = true;
};

////////////////////////////////////////////////////////////////////////////////
/* short int template */
template <  >
struct is_integral <short int>
{
	typedef short int value_type;
	typedef ft::is_integral<short int> type;

	
	public :
		static const bool		value = true;
};

////////////////////////////////////////////////////////////////////////////////
/* Int template */
template <  >
struct is_integral <int>
{
	typedef int value_type;
	typedef ft::is_integral<int> type;

	
	public :
		static const bool		value = true;
};

////////////////////////////////////////////////////////////////////////////////
/* long int template */
template <  >
struct is_integral <long int>
{
	typedef long int value_type;
	typedef ft::is_integral<long int> type;

	
	public :
		static const bool		value = true;
};

////////////////////////////////////////////////////////////////////////////////
/* long long int template */
template <  >
struct is_integral <long long int>
{
	typedef long long int value_type;
	typedef ft::is_integral<long long int> type;

	
	public :
		static const bool		value = true;
};

////////////////////////////////////////////////////////////////////////////////
/* unsigned char template */
template <  >
struct is_integral <unsigned char>
{
	typedef unsigned char value_type;
	typedef ft::is_integral<unsigned char> type;

	
	public :
		static const bool		value = true;
};

////////////////////////////////////////////////////////////////////////////////
/* unsigned short int template */
template <  >
struct is_integral <unsigned short int>
{
	typedef unsigned short int value_type;
	typedef ft::is_integral<unsigned short int> type;

	
	public :
		static const bool		value = true;
};

////////////////////////////////////////////////////////////////////////////////
/* unsigned int template */
template <  >
struct is_integral <unsigned int>
{
	typedef unsigned int value_type;
	typedef ft::is_integral<unsigned int> type;

	
	public :
		static const bool		value = true;
};

////////////////////////////////////////////////////////////////////////////////
/* unsigned long int template */
template <  >
struct is_integral <unsigned long int>
{
	typedef unsigned long int value_type;
	typedef ft::is_integral<unsigned long int> type;

	
	public :
		static const bool		value = true;
};

////////////////////////////////////////////////////////////////////////////////
/* unsigned long long int template */
template <  >
struct is_integral<unsigned long long int>
{
	typedef unsigned long long int value_type;
	typedef ft::is_integral<unsigned long long int> type;

	
	public :
		static const bool		value = true;
};

}

#endif