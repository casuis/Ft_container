/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimon <asimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 13:43:46 by asimon            #+#    #+#             */
/*   Updated: 2022/10/09 00:10:24 by asimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __MY_VECTOR_HPP__
# define __MY_VECTOR_HPP__

# include "../../private/header.hpp"
# include "../iterator/iterator.hpp"
# include "../iterator/reverse_iterator.hpp"

namespace ft
{
	template <class T, class Allocator = std::allocator<T>>
	class vector
	{
		public:
		////////////////////////////////////////////////////////////////////////////////
		/*                              MEMBER TYPE                                   */
		////////////////////////////////////////////////////////////////////////////////
			typedef T								value_type;
			typedef Allocator						allocator_type;
			typedef std::size_t						size_type;
			typedef std::ptrdiff_t					difference_type;
			typedef value_type&						reference;					
			typedef const value_type&				const_reference;
			typedef allocator_type::pointer			pointer;
			typedef allocator_type::const_pointer	const_pointer;
			typedef	ft::random_iterator<T>			iterator; 
		////////////////////////////////////////////////////////////////////////////////
		/*                            MEMBER FUNCTIONS                                */
		////////////////////////////////////////////////////////////////////////////////
		/* Lifecycle */
		
			/* Default constructor */
			vector(void):_array(nullptr), _size(0), _capacity(0) {}

			/* Constructor with one elem */
			vector(T elem): _size(1), _capacity(2) {
				Allocator		alloc;
				this->_array = alloc.allocate(this->_capacity);
				this->_array[0] = elem;
				this->_array[1] = nullptr;
			}

			/* Copy Constructor */
			vector(const vector &old): _size(old.size), _capacity(old._capacity) {
				Alloc		alloc;
				int i = 0;
				this->_array = alloc.allocate(this->_capacity)
				for (; old._array[i]; i++)
					this->_array[i] = old._array[i];
				this->_array[i] = nullptr;
			};
			
			/* Constructor by params */
			vector(size_type count, const T& value, const Allocator &alloc){
				return ;
			}

			/* Destructor */
			~vector();

			/* Operator= overload */
			vector&		operator=(const vector &rght);

			void		assign(size_type count, const T& value );

		////////////////////////////////////////////////////////////////////////////////
		/*                              Iterators                                      */
		////////////////////////////////////////////////////////////////////////////////
		
		/* begin return a iterator pointer to the first element of the container */
		ft::random_access_iterator<T>		begin(){
			ft::random_access_iterator<T>		ret(this->_array);
			return (ret);
		}

		/* end return an iterator pointer to the end of the container */
		ft::random_access_iterator<T>		end(){
			T		*tmp = this->_array;
			int i = 0;
			while (tmp[i])
				i++;
			ft::random_access_iterator<T>	ret(&tmp[i]);
			return (ret);
		}

		/* rbegin return a reverse pointer to the begining of the container */
		ft::reverse_iterator<T>			rbegin(){
			int		i = 0;
			T		*tmp = this->_array;
			while (tmp[i])
				i++;
			ft::reverse_iterator<T>			ret(&tmp[i]);
			return (ret);
			
		}
		
		/* rend return a reverse pointer to the end of the container */
		ft::reverse_iterator<T>			rend(){
			ft::reverse_iterator<T>		ret(static_cast<const T>(this->_array));
			return (ret);
		}
		
		////////////////////////////////////////////////////////////////////////////////
		/* C++11 */
		
		/* cbegin return a const pointer to the begining of the container */
		ft::random_access_iterator<T>	cbegin(){
			ft::random_access_iterator<T> ret(static_cast<const T>(this->_array));		
			return (ret);
		}

		/* cend retutn a const pointer to the end of the container */
		ft::random_access_iterator<T>	cend(){
			int		i = 0;
			T*		tmp = this->_array;
			while (tmp[i])
				i++;
			ft::random_access_iterator<T>	ret(static_cast<const T>(&tmp[i]));
			return (ret);
		}
		
		/* crbegin return a const reverse pointer to the begining of the container */
		ft::reverse_iterator<T>			crbegin(){
			int		i = 0;
			T*		tmp = this->_array;
			while (tmp[i])
				i++;
			ft::reverse_iterator<T>		ret(static_cast<const T>(&tmp[i]));
			return (ret);
		}

		/* crend return a const reverse pointer to the end of the container */
		ft::reverse_iterator<T>			crend(){
			ft::reverse_iterator<T>		ret(static_cast<const T>(this->_array);
			return (ret);
		}
		
		////////////////////////////////////////////////////////////////////////////////
		/* Capacity */

		bool			empty() { return (this->_size == 0); }

		size_t			size() const { return (this->_size);}
		
		size_t			max_size() const  {return ((pow(2, (64 - sizeof(T))) - 1));}			

		void			reserve(size_t new_cap) {
			
		}
			
		private:
			T*			_array;
			size_type	_size;
			size_type	_capacity;	
	};
}

#endif