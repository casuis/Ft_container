/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimon <asimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 13:43:46 by asimon            #+#    #+#             */
/*   Updated: 2022/10/19 13:41:45 by asimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*  
	https://cplusplus.com/reference/vector/vector/
*/

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
		/*                              Member Type                                  */
		////////////////////////////////////////////////////////////////////////////////
		
			typedef T													value_type;
			typedef Allocator											allocator_type;
			typedef std::size_t											size_type;
			typedef std::ptrdiff_t										difference_type;
			typedef value_type&											reference;
			typedef const value_type&									const_reference;
			typedef typename allocator_type::pointer					pointer;
			typedef const T*											const_pointer;
			typedef	typename ft::RandomIterator< value_type >			iterator;
			typedef	typename ft::RandomIterator< const value_type >		const_iterator;
			typedef typename ft::ReverseIterator< value_type >			r_iterator;
			typedef typename ft::ReverseIterator< const value_type >	const_r_iterator;

		////////////////////////////////////////////////////////////////////////////////
		/*                            Member Function                                 */
		////////////////////////////////////////////////////////////////////////////////
		/* Lifecycle */
		
			/* Default constructor */
			vector (const allocator_type& alloc = allocator_type())
			: _alloc(alloc), _data(0x0), _size(0), _capacity(0) {}

			/* Fill Constructor */
			vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type())
			: _alloc(alloc), _size(n), _capacity(n + 1){
				this->_data = this->_alloc.allocate(n + 1);
				size_type		i = 0;
				for (; i < n; i++){
					this->_data[i] = val;
				}
				this->_data[i] = 0x0;
			}

			/* Range Constructor */
			template <typename InputIterator>
			vector (InputIterator first, typename ft::enable_if<!is_integral<InputIterator>::value, InputIterator>::type last, const allocator_type &alloc = allocator_type())
			: _alloc(alloc){
				size_t			size = 0;
				InputIterator	tmp = first;
				for (; tmp != last; tmp++){
					size++;
				}
				this->_data = this->_alloc.allocate(size);
				this->_capacity = size;
				this->_size = size;
				for (int i = 0; first != last; first++){
					this->_data[i] = *first;
					i++;
				}
				this->_data[this->_size] = 0x0;
			}
			
			/* Copy Constructor */
			vector(const ft::vector<T> &old)
			: _size(old._size), _capacity(old._capacity) {
				Allocator		alloc;
				int i = 0;
				this->_data = alloc.allocate(this->_capacity);
				for (; old._data[i]; i++){
					this->_data[i] = old._data[i];
				}
				this->_data[i] = 0x0;
			};

			/* Destructor */
			~vector(){
				this->_alloc.deallocate(this->_data, this->_capacity);
			};

		////////////////////////////////////////////////////////////////////////////////
		/*                              Iterators                                     */
		////////////////////////////////////////////////////////////////////////////////
		
			/* begin return a iterator pointer to the first element of the container */
			const_iterator	begin() const{
				const_iterator		ret(this->_data);
				return (ret);
			}
			
			iterator		begin(){
				iterator		ret(this->_data);
				return (ret);
			}


			////////////////////////////////////////////////////////////////////////////////
			
			/* end return an iterator pointer to the end of the container */
			iterator		end(){
				T		*tmp = this->_data;
				size_t i = 0;
				while (i < this->_size)
					i++;
				iterator	ret(&tmp[i]);
				return (ret);
			}

			const_iterator	end() const{
				T		*tmp = this->_data;
				const_iterator	ret(&tmp[this->_size]);
				return (ret);
			}

			////////////////////////////////////////////////////////////////////////////////
			
			/* rbegin return a reverse pointer to the begining of the container */
			ft::ReverseIterator<T>			rbegin(){
				int		i = 0;
				T		*tmp = this->_data;
				while (i < this->_size)
					i++;
				ft::ReverseIterator<T>			ret(&tmp[i]);
				return (ret);
				
			}
			
			/* rend return a reverse pointer to the end of the container */
			ft::ReverseIterator<T>			rend(){
				ft::ReverseIterator<T>		ret(static_cast<const T>(this->_data));
				return (ret);
			}
			
		////////////////////////////////////////////////////////////////////////////////
		/* C++11 */
		
			/* cbegin return a const pointer to the begining of the container */
			const_iterator	cbegin(){
				const ft::RandomIterator<T> ret(static_cast<const T>(this->_data));		
				return (ret);
			}

			/* cend retutn a const pointer to the end of the container */
			const_iterator	cend(){
				int		i = 0;
				T*		tmp = this->_data;
				while (tmp[i])
					i++;
				const ft::RandomIterator<T>	ret(static_cast<const T>(&tmp[i]));
				return (ret);
			}
			
			////////////////////////////////////////////////////////////////////////////////
			
			/* crbegin return a const reverse pointer to the begining of the container */
			const ft::ReverseIterator<T>			crbegin(){
				int		i = 0;
				T*		tmp = this->_data;
				while (tmp[i])
					i++;
				const ft::ReverseIterator<T>		ret(static_cast<const T>(&tmp[i]));
				return (ret);
			}

			/* crend return a const reverse pointer to the end of the container */
			const ft::ReverseIterator<T>			crend(){
				const ft::ReverseIterator<T>		ret(static_cast<const T>(this->_data));
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

			////////////////////////////////////////////////////////////////////////////////
			
			/* realloc the container to change his capacity to new_cap, the size don't change */
			void			reserve(size_t new_cap) {
				pointer newVec = this->_alloc.allocate(new_cap);
				for (size_t i = 0; i < new_cap && i < this->_size; i++){
					newVec[i] = this->_data[i];
				}
				this->_alloc.deallocate(this->_data, this->_capacity);
				this->_data = newVec;
				this->_capacity = new_cap;
			}

			/* Requests the container to reduce its capacity to fit its size */
			void			shrink_to_fit(){
				if (this->_size != this->_capacity){
					ft::vector<T>		tmp(*this);
					Allocator			alloc;

					delete this->_data;
					this->_data = alloc.allocate(tmp._size);
					for (int i = 0; i < tmp._size; i++){
						this->_data[i] = tmp._data[i];
					}
					this->_capacity = this->_size;
				}
			}
		
		////////////////////////////////////////////////////////////////////////////////
		/*                              Element Access                                */
		////////////////////////////////////////////////////////////////////////////////
		

			reference		operator[](size_t n){
				return (this->_data[n]);
			}
			
			const_reference	operator[](size_t n) const{
				return (this->_data[n]);
			}
			////////////////////////////////////////////////////////////////////////////////
			
			reference		at(size_t n){
				if (n != 0 && (n >= this->_size || n < 0)){
					throw (std::out_of_range("Error index out of range\n"));
				}
				else
					return (this->_data[n]);
			}
			
			const_reference	at(size_t n) const{
				if (n != 0 && (n >= this->_size || n < 0)){
					throw (std::out_of_range("Error index out of range\n"));
				}
				return (this->_data[n]);
			}
			
			////////////////////////////////////////////////////////////////////////////////
			
			reference		front(){
				return (this->_data[0]);
			}

			const_reference	front() const{
				return (this->_data[0]);
			}

			////////////////////////////////////////////////////////////////////////////////
			
			reference		back(){
				return (this->_data[this->_size - 1]);
			}

			const_reference	back() const{
				return (this->_data[this->_size - 1]);
			}
			
			////////////////////////////////////////////////////////////////////////////////

			value_type*			data(){
				return (this->_data);
			}

			const value_type*	data() const{
				return (this->_data);
			}
		
		////////////////////////////////////////////////////////////////////////////////
		/*                              Modifier                                      */
		////////////////////////////////////////////////////////////////////////////////
		
			
			void push_back (const value_type& val){
				if (this->_capacity == 0)
					this->reserve(1);
				while (this->_size + 1 > this->_capacity)
					this->reserve(this->_capacity * 2);
				this->_data[this->_size] = val;
				this->_size += 1;
			}
			
			void	clear(){
				for (size_t i = 0; i < this->_size; i++){
					this->_data[i] = 0x0;
				}
				this->_size = 0;
			}
			
			void	pop_back(){
				if (this->_size == 0)
					return ;
				this->_data[this->_size - 1] = 0x0;
				this->_size -= 1;
			}
			
			////////////////////////////////////////////////////////////////////////////////

			iterator erase(iterator position){
				iterator		ite = this->end();	
				iterator		tmp = position;
				iterator		swp;
				std::cout << "test: " << *position << std::endl;
				if (tmp != ite)
					++tmp;
				for (; position != ite; position++){
					swp = position;
					position = tmp;
					tmp = swp;
				}
				this->pop_back();
				return (position);
			}
			
			// iterator erase (iterator first, iterator last){
			
			// }
			
			////////////////////////////////////////////////////////////////////////////////

			/* Change the size and the content of the vector to the new range */
			template <class InputIterator>
			void assign (InputIterator first, InputIterator last){
				this->clear();
				InputIterator		tmp_it = first;
				InputIterator		tmp_ite = last;
				for (; tmp_it != tmp_ite; tmp_it++){
					this->push_back(*tmp_it);
				}
			}
			
			/* Destroy old content and size and a create a new one of size n of value */
			void assign (size_type n, const value_type& val){
				this->clear();
				for (int i = 0; i < n; i++){
					this->push_back(val);
				}
			}

			////////////////////////////////////////////////////////////////////////////////
			
			iterator insert (iterator position, const value_type& val){
				if (position > this->end() || position < this->begin())
					return (this->begin());
				while (this->_size + 1 > this->_capacity)
					this->reserve(this->_capacity * 2);
				if (position == this->end()){
					this->push_back(val);
					return (position);
				}
				vector<int>			tab(*this);
				this->clear();
				iterator			cmp = this->begin();
				for (iterator start = tab.begin(), end = tab.end(); start != end; start++){
					if (cmp == position)
						this->push_back(val);
					this->push_back(*start);
					cmp++;
				}
				++cmp;
				*cmp = 0x0;
				return (position);
			}
			
			template <class InputIterator>
			void insert (iterator position, typename enable_if<!is_integral<InputIterator>::value, InputIterator>::type first, InputIterator last){
				if (position > this->end() || position < this->begin())
					return (this->begin());
				size_t 		size = last - first;
				while (this->_size + size > this->_capacity)
					this->reserve(this->_capacity * 2);
				for (; first != last; first++){
					this->insert(position, first);
				}
			}
			
			void insert (iterator position, size_type n, const value_type& val){
				if (position > this->end() || position < this->begin())
					return (this->begin());
				while (this->_size + n > this->_capacity)	
					this->reserve(this->_capacity * 2);
				for (int i = 0; i <= n; i++){
					this->insert(position, val);
				}
			}
			
			////////////////////////////////////////////////////////////////////////////////
		
		
		private:
			allocator_type	_alloc;
			T*				_data;
			size_type		_size;
			size_type		_capacity;

	};
}

#endif