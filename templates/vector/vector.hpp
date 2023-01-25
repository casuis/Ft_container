/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimon <asimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 13:43:46 by asimon            #+#    #+#             */
/*   Updated: 2023/01/25 15:48:26 by asimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __MY_VECTOR_HPP__
# define __MY_VECTOR_HPP__

/* Comment this area for tester */
// # include <header.hpp>
// # include <iterator.hpp>
// # include <reverse_iterator.hpp>
// # include <enable_if.hpp>
// # include <is_integral.hpp>

/* decomment her for tester */
# include "../../private/header.hpp"
# include "../iterator/iterator.hpp"
# include "../iterator/reverse_iterator.hpp"
# include "../functions/enable_if.hpp"
# include "../functions/is_integral.hpp"

namespace ft
{
	template <class T, class Allocator>
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
			typedef typename ft::ReverseIterator< value_type >			reverse_iterator;
			typedef typename ft::ReverseIterator< const value_type >	const_reverse_iterator;

		////////////////////////////////////////////////////////////////////////////////
		/*                            Member Function                                 */
		////////////////////////////////////////////////////////////////////////////////
		/* Lifecycle */
		
			/* Default constructor */
			vector(const allocator_type& alloc = allocator_type())
			: _alloc(alloc), _data(0x0), _size(0), _capacity(0)  {
				return ;
			}

			/* Fill Constructor */
			vector(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type())
			: _alloc(alloc), _size(n), _capacity(n){
				pointer			newVec;
				newVec = this->_alloc.allocate(this->_capacity);
				for (size_type i = 0; i < n; i++)
					this->_alloc.construct(newVec + i, val);
				this->_data = newVec;
				return ;
			}

			/* Range Constructor */
			template <typename InputIterator>
			vector(typename ft::enable_if<!is_integral<InputIterator>::value, InputIterator>::type first, InputIterator last, const allocator_type &alloc = allocator_type())
			: _alloc(alloc){
				size_t			size = 0;
				pointer			newVec;
				InputIterator	tmp = first;
				
				for (; tmp != last; tmp++)
					size++;
				newVec = this->_alloc.allocate(size);
				for (size_t i = 0; first != last; first++, i++)
					this->_alloc.construct(newVec + i, *first);
				this->_data = newVec;
				this->_capacity = size;
				this->_size = size;
				return ;
			}
			
			/* Copy Constructor */
			vector(const ft::vector<T> &old)
			: _alloc(old._alloc), _size(old._size), _capacity(old._size) {
				size_t i = 0;
				pointer		newVec;
				
				newVec = this->_alloc.allocate(this->_capacity);
				for (; i < old._size; i++)
					this->_alloc.construct(newVec + i, old._data[i]);
				this->_data = newVec;
				return ;
			};

			/* Destructor */
			~vector(){
				for (size_t del = 0; del != this->_size; del++)
					this->_alloc.destroy(this->_data + del);
				if (this->_data) {
					this->_alloc.deallocate(this->_data, this->_capacity);
				}
				return ;
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
			iterator		end() {
				T		*tmp = this->_data;
				iterator	ret(&tmp[this->_size]);
				return (ret);
			}

			const_iterator	end() const{
				T		*tmp = this->_data;
				const_iterator	ret(&tmp[this->_size]);
				return (ret);
			}

			////////////////////////////////////////////////////////////////////////////////
			
			/* rbegin return a reverse pointer to the begining of the container */
			ft::ReverseIterator<T>			rbegin() const{
				pointer				tmp;

				if (this->_size != 0){
					tmp = &this->_data[this->_size - 1];
				}
				else
					tmp = &this->_data[this->_size];
				ft::ReverseIterator<T>			ret(tmp);
				return (ret);
				
			}
			
			/* rend return a reverse pointer to the end of the container */
			ft::ReverseIterator<T>			rend() const{
				pointer				tmp;
				
				if (this->_size != 0)
					tmp = this->_data - 1;
				else
					tmp = this->_data;
				ft::ReverseIterator<T>		ret(tmp);
				return (ret);
			}
			
		////////////////////////////////////////////////////////////////////////////////
		/*                              Capacity                                      */
		////////////////////////////////////////////////////////////////////////////////
		

			/* return a bool, true if container is empty, false if not */
			bool			empty() const { return (this->_size == 0); }

			/* return the size of the container */
			size_type			size() const { return (this->_size);}
			
			/* return the capacity of the vector */
			size_type			capacity() const {return (this->_capacity);}
			
			/* return the max sixe of the type T container */
			size_t			max_size() const throw() {return (this->_alloc.max_size());}			

			////////////////////////////////////////////////////////////////////////////////
			
			/* realloc the container to change his capacity to new_cap, the size don't change */
			void			reserve(size_t new_cap) {
				pointer 		newVec; 
				size_t i = 0;
				
				if (this->_capacity > new_cap)
					return ;
				if (new_cap == 0)
					new_cap = 1;
				newVec = this->_alloc.allocate(new_cap);
				for (; i < new_cap && i < this->_size; i++){
					try{
						this->_alloc.construct(newVec + i, this->_data[i]);
					}
					catch (const std::exception& e){
						for (size_t del = 0; del != i; del++)
							this->_alloc.destroy(newVec + del);
						std::exit(1);
					}
				}
				for (size_t del = 0; del < i; del++)
					this->_alloc.destroy(this->_data + del);
				this->_alloc.deallocate(this->_data, this->_capacity);
				this->_data = newVec;
				this->_capacity = new_cap;
			}

			////////////////////////////////////////////////////////////////////////////////
			
			/* Resizes the container so that it contains n elements */
			void		resize(size_type n, value_type val = value_type()){
				size_t	 i = this->_size;
				size_t	 cap = this->_capacity;
				if (n > this->_capacity){
					if (this->_capacity * 2 >= n)
						this->reserve(cap * 2);
					else
						this->reserve(n);
				}
				if (n > this->_size){
					for (iterator it = this->end(); i < n; i++){
						this->push_back(val);
						it++;
					}
				}
				if (n < this->_size){
					for (; i > n; i--)
						this->pop_back();
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
				if (n != 0 && (n >= this->_size))
					throw (std::out_of_range("Error index out of range\n"));
				else
					return (this->_data[n]);
			}
			
			const_reference	at(size_t n) const{
				if (n != 0 && (n >= this->_size))
					throw (std::out_of_range("Error index out of range\n"));
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
		/*                              Modifier                                      */
		////////////////////////////////////////////////////////////////////////////////
		
			
			void push_back (const value_type& val){
				if (this->_size + 1 > this->_capacity)
					this->reserve(this->_size * 2);
				this->_alloc.construct(this->_data + this->_size, val);
				this->_size += 1;
			}
			
			void	clear(){
				for (size_t i = 0; i < this->_size; ) {this->pop_back();}
			}
			
			void	pop_back(){
				if (this->_size == 0)
					return ;
				this->_alloc.destroy(this->_data + (this->_size - 1));
				this->_size -= 1;
			}

			void			swap(vector<T>& x){
				pointer			tmp_data = this->_data;
				size_t			tmp_cap = this->_capacity;
				size_t			tmp_size = this->_size;
				allocator_type	tmp_alloc = this->_alloc;
				
				this->_data = x._data;
				this->_size = x._size;
				this->_capacity = x._capacity;
				this->_alloc = x._alloc;
				
				x._data = tmp_data;
				x._capacity = tmp_cap;
				x._size = tmp_size;
				x._alloc = tmp_alloc;
			}
			
			////////////////////////////////////////////////////////////////////////////////
			/* ERASE */

			/* Erases the specified elements from the container. */
			iterator erase(iterator position){
				if (this->_size == 1 || position == this->end() - 1){
					this->pop_back();
					return (this->end());
				}
				iterator		it = position;
				iterator		swp = it;
				swp++;
				for (iterator ite = this->end(); (it != ite) && (swp != ite); it++){
					*it = *swp;
					swp++;
				}
				this->_size -= 1;
				return (position);
			}
			
			iterator erase (iterator first, iterator last){
				if (first == last || last < first || first < this->begin() || last > this->end())
					return (first);
				iterator		it = first;
				int				count = 0;
				for (iterator tmp = first; tmp != last; tmp++)
					count++;
				while (count > 0){
					it = this->erase(it);
					count--;
				}
				return (first);
			}
			
			////////////////////////////////////////////////////////////////////////////////
			/* ASSIGN */
			
			/* Change the size and the content of the vector to the new range */
			template <class InputIterator>
			void assign (typename enable_if<!is_integral<InputIterator>::value, InputIterator>::type first, InputIterator last){
				this->clear();
				InputIterator		tmp_it = first;
				InputIterator		tmp_ite = last;
				for (int i = 10; tmp_it != tmp_ite; tmp_it++, i--)
					this->push_back(*tmp_it);
			}
			
			/* Destroy old content and size and a create a new one of size n of value */
			void assign (size_type n, const value_type& val){
				this->clear();
				for (size_t i = 0; i < n; i++)
					this->push_back(val);
			}

			////////////////////////////////////////////////////////////////////////////////
			/* INSERT */

			/* insert by pos */
			iterator 		insert (iterator position, const value_type& val){
				int				pos = 0;
				ft::vector<T>	tmp(*this);
				
				
				for (iterator it = this->begin(), ite = this->end(); it != ite && it != position; it++){
					pos++;
					if ((it + 1 == ite) && (it != position) && (it + 1 != position))
						return (position);
				}
				position = this->begin() + pos;
				if (position == this->end()){
					this->push_back(val);
					return (position);
				}
				
				this->clear();
				for (iterator start = tmp.begin(), end = tmp.end(), cmp = this->begin(); start != end; start++){
					if (cmp == position)
						this->push_back(val);
					this->push_back(*start);
					cmp++;
				}
				return (position);
			}
			
			/* insert n elem by pos */
			void 			insert (iterator position, size_type n, const value_type& val){
				size_t		pos = 0;
				
				for (iterator it = this->begin(), ite = this->end(); it != ite && it != position; it++)
					pos++;
					
				if (this->_size + n > this->_capacity){
					if (this->_size * 2 >= this->_size + n)
						this->reserve(this->_size * 2);
					else
						this->reserve(this->_size + n);
				}
				for (size_t i = 0; i < n; i++)
					position = this->insert(this->begin() + pos, val);
			}
			
			/* insert by range */
			template <typename InputIterator>
			void 			insert (iterator position, InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = 0x0) {
				size_t 		add_size = 0;
				size_t		pos = 0;
				size_t		new_cap = 2;
				
				for (iterator it = this->begin(), ite = this->end(); it != ite && it != position; it++){
					pos++;
					if ((it + 1 == ite) && (it != position) && (it + 1 != position))
						return ;
				}
				
				if (this->_capacity != 0)
					new_cap *= this->_capacity;
				for (InputIterator it = first, ite = last; it != ite; it++, add_size++) {}
				for (; this->_size + add_size > new_cap; new_cap *= 2) {} /* Calcul mem value needed  */
				if (this->_size + add_size > this->_capacity){
					if (this->_size * 2 >= this->_size + add_size)
						this->reserve(this->_size * 2);
					else
						this->reserve(this->_size + add_size);
				}
					
				position = this->begin() + pos;
				for (; first != last; first++){
					this->insert(position, *first);
					position = position + 1;
				}
			}
			
		////////////////////////////////////////////////////////////////////////////////
		/*                              Allocator                                     */
		////////////////////////////////////////////////////////////////////////////////

			allocator_type 	get_allocator() const{
				return (this->_alloc);
			}
			
		////////////////////////////////////////////////////////////////////////////////
		/*                              Operators                                     */
		////////////////////////////////////////////////////////////////////////////////


			vector<T>&		operator=(const vector<T>& param){
				if (&param == this)
					return (*this);

				this->clear();
				if (param.size() > this->_capacity)
				{
					this->_alloc.deallocate(this->_data, this->_capacity);
					this->_capacity = param.size();
					this->_data = this->_alloc.allocate(this->_capacity);
				}

				for (size_type i = 0; i < param.size(); i++)
					this->push_back(param[i]);

				return (*this);
			}
			
			
		private:
			allocator_type	_alloc;
			T*				_data;
			size_type		_size;
			size_type		_capacity;

	};
	
	////////////////////////////////////////////////////////////////////////////////
	/* Operator's overload */
	
	template <typename T1, typename T2>
	bool			operator==(const vector<T1> lft, const vector<T2> old){
		for (size_t i = 0; i < lft.size() && i < old.size(); i++){
			if (lft[i] != old[i])
				return (false);
		}
		if (lft.size() != old.size())
			return (false);
		return (true);
	}

	template <typename T1, typename T2>
	bool			operator<(const vector<T1> lft, const vector<T2>& old){
		size_t i = 0;
		for (; i < lft.size() && i < old.size(); i++){
			if (lft[i] < old[i])
				return (true);
			if (old[i] < lft[i])
				return (false);
		}
		if (i != old.size())
			return (true);
		return (false);
	}		

	template <typename T1, typename T2>
	bool			operator>(const vector<T1> lft, const vector<T2>& old){
		return (old < lft);
	}

	template <typename T1, typename T2>
	bool			operator<=(const vector<T1> lft, const vector<T2>& old){
		return (!(old < lft));
	}
	
	template <typename T1, typename T2>
	bool			operator>=(const vector<T1> lft, const vector<T2>& old){
		return (!(lft < old));
	}

	template <typename T1, typename T2>
	bool			operator!=(const vector<T1> lft, const vector<T2>& old){
		if (lft.size() != old.size())
			return (true);
		for (size_t i = 0; i < lft.size() && i < old.size(); i++){
			if (lft[i] == old[i])
				return (false);
		}
		return (true);
	}
	////////////////////////////////////////////////////////////////////////////////
	
}

#endif