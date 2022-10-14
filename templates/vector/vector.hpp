/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimon <asimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 13:43:46 by asimon            #+#    #+#             */
/*   Updated: 2022/10/15 00:31:45 by asimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __MY_VECTOR_HPP__
# define __MY_VECTOR_HPP__

# include "../../private/header.hpp"
# include "../iterator/iterator.hpp"
# include "../iterator/reverse_iterator.hpp"

namespace ft
{
	template <class T, class Allocator = std::allocator<T> >
	class vector
	{
		public:
		////////////////////////////////////////////////////////////////////////////////
		/*                              MEMBER TYPE                                   */
		////////////////////////////////////////////////////////////////////////////////
			typedef T													value_type;
			typedef Allocator											allocator_type;
			typedef std::size_t											size_type;
			typedef std::ptrdiff_t										difference_type;
			typedef value_type&											reference;					
			typedef const value_type&									const_reference;
			typedef typename allocator_type::pointer					pointer;
			typedef typename allocator_type::const_pointer				const_pointer;
			typedef	typename ft::RandomIterator< value_type >			iterator; 
			typedef	typename ft::RandomIterator< const value_type >		const_iterator; 

		////////////////////////////////////////////////////////////////////////////////
		/*                            MEMBER FUNCTIONS                                */
		////////////////////////////////////////////////////////////////////////////////
		/* Lifecycle */
		
			/* Default constructor */
			vector(void):_array(0x0), _size(0), _capacity(0) {}

			/* Constructor with one elem */
			vector(T elem): _size(1), _capacity(2) {
				Allocator		alloc;
				this->_array = alloc.allocate(this->_capacity);
				this->_array[0] = elem;
				this->_array[1] = 0x0;
			}

			/* Copy Constructor */
			vector(const ft::vector<T> &old): _size(old._size), _capacity(old._capacity) {
				Allocator		alloc;
				int i = 0;
				this->_array = alloc.allocate(this->_capacity);
				for (; old._array[i]; i++)
					this->_array[i] = old._array[i];
				this->_array[i] = 0x0;
			};
			
			/* Constructor by params */
			// vector(size_type count, const T& value, const Allocator &alloc){
			// 	return ;
			// }

			/* Destructor */
			~vector(){};

			/* Operator= overload */
			vector&		operator=(const ft::vector<T> &rght);

			void		assign(size_type count, const T& value );

		////////////////////////////////////////////////////////////////////////////////
		/*                              Iterators                                     */
		////////////////////////////////////////////////////////////////////////////////
		
			/* begin return a iterator pointer to the first element of the container */
			iterator		begin(){
				ft::RandomIterator<T>		ret(this->_array);
				return (ret);
			}

			const_iterator	begin() const{
				ft::RandomIterator<const T>		ret(this->_array);
				return (ret);
			}

			/* end return an iterator pointer to the end of the container */
			iterator		end(){
				T		*tmp = this->_array;
				int i = 0;
				while (tmp[i])
					i++;
				ft::RandomIterator<T>	ret(&tmp[i]);
				return (ret);
			}

			const_iterator	end() const{
				T		*tmp = this->_array;
				int i = 0;
				while (tmp[i])
					i++;
				ft::RandomIterator<const T>	ret(&tmp[i]);
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
			const_iterator	cbegin(){
				const ft::RandomIterator<T> ret(static_cast<const T>(this->_array));		
				return (ret);
			}

			/* cend retutn a const pointer to the end of the container */
			const_iterator	cend(){
				int		i = 0;
				T*		tmp = this->_array;
				while (tmp[i])
					i++;
				const ft::RandomIterator<T>	ret(static_cast<const T>(&tmp[i]));
				return (ret);
			}
			
			/* crbegin return a const reverse pointer to the begining of the container */
			const ft::reverse_iterator<T>			crbegin(){
				int		i = 0;
				T*		tmp = this->_array;
				while (tmp[i])
					i++;
				const ft::reverse_iterator<T>		ret(static_cast<const T>(&tmp[i]));
				return (ret);
			}

			/* crend return a const reverse pointer to the end of the container */
			const ft::reverse_iterator<T>			crend(){
				const ft::reverse_iterator<T>		ret(static_cast<const T>(this->_array));
				return (ret);
			}
		
		////////////////////////////////////////////////////////////////////////////////
		/*                              Capacity                                      */
		////////////////////////////////////////////////////////////////////////////////
		

			/* return a bool, true if container is empty, false if not */
			bool			empty() { return (this->_size == 0); }

			/* return the size of the container */
			size_t			size() const { return (this->_size);}
			
			/* return the capacity of the vector */
			size_t			capacity() const {return (this->_capacity);}
			
			/* return the max sixe of the type T container */
			size_t			max_size() const  {return ((pow(2, (64 - sizeof(T))) - 1));}			

			/* realloc the container to change his capacity to new_cap, the size don't change */
			void			reserve(size_t new_cap) {
				if (new_cap > this->_size){
					ft::vector<T> 		tmp(*this);
					Allocator			alloc;
					
					delete this->_array;
					this->_array = alloc.allocate(new_cap);
					this->_capacity = new_cap;
					for (int i = 0; i < tmp._size; i++){
						this->_array[i] = tmp._array[i];
					}
				}
			}

			/* Requests the container to reduce its capacity to fit its size */
			void			shrink_to_fit(){
				if (this->_size != this->_capacity){
					ft::vector<T>		tmp(*this);
					Allocator			alloc;

					delete this->_array;
					this->_array = alloc.allocate(tmp._size);
					for (int i = 0; i < tmp._size; i++){
						this->_array[i] = tmp._array[i];
					}
					this->_capacity = this->_size;
				}
			}
		
		////////////////////////////////////////////////////////////////////////////////
		/*                              Element Access                                */
		////////////////////////////////////////////////////////////////////////////////
		

			reference		operator[](size_t n){
				return (this->_array[n]);
			}
			
			const_reference	operator[](size_t n) const{
				return (this->_array[n]);
			}
			
			reference		at(size_t n){
				if (n != 0 && (n >= this->_size || n < 0)){
					throw (std::out_of_range("Error index out of range\n"));
				}
				else
					return (this->_array[n]);
			}
			
			const_reference	at(size_t n) const{
				if (n != 0 && (n >= this->_size || n < 0)){
					throw (std::out_of_range("Error index out of range\n"));
				}
				return (this->_array[n]);
			}
			
			reference		front(){
				return (this->_array[0]);
			}

			const_reference	front() const{
				return (this->_array[0]);
			}

			reference		back(){
				return (this->_array[this->_size - 1]);
			}

			const_reference	back() const{
				return (this->_array[this->_size - 1]);
			}

			value_type*			data(){
				return (this->_array);
			}

			const value_type*	data() const{
				return (this->_array);
			}
		
		////////////////////////////////////////////////////////////////////////////////
		/* Modifier */
			// template <class InputIterator,
			// ft::iterator_traits<InputIterator>::difference_type,
			// ft::iterator_traits<InputIterator>::value_type,
			// ft::iterator_traits<InputIterator>::pointer,
			// ft::iterator_traits<InputIterator>::reference,
			// ft::iterator_traits<InputIterator>::iterator_category>
			// void		assign(InputIterator first, InputIterator last){
				
			// }
		
		private:
			T*			_array;
			size_type	_size;
			size_type	_capacity;

	};
}

#endif