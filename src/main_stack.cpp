/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_stack.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimon <asimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 18:30:36 by asimon            #+#    #+#             */
/*   Updated: 2023/02/21 22:02:26 by asimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <ftnspace.hpp>
# include <iostream>

#if STD == 1
	std::string		print_nspace = "##STD";
#else
	std::string		print_nspace = "##FT";
#endif


int		main(void){
	
	////////////////////////////////////////////////////////////////////////////////
	/*                              STACK                                        */
	////////////////////////////////////////////////////////////////////////////////
	std::cout << print_nspace << std::endl;
	std::cout << std::endl << M_YELLOW << "##########STACK##########" << M_RESET << std::endl << std::endl;
	
	////////////////////////////////////////////////////////////////////////////////
	{
		
		{
			std::cout << std::endl << M_CYAN << "=> Constructors: " << M_RESET << std::endl << std::endl;
			NAMESPACE::stack<int>		test;

			std::cout << "apres creation du container" << std::endl;

			std::cout << std::endl << M_YELLOW << "*****fin de test*****" << M_RESET << std::endl << std::endl;
		}
		
		////////////////////////////////////////////////////////////////////////////////

		{
			std::cout << std::endl << M_CYAN << "=> empty: " << M_RESET << std::endl << std::endl;
			
			NAMESPACE::stack<int>		test;

			std::cout << "=Test with nothing in the stack test=" << std::endl;
			if (test.empty())
				std::cout << "test is empty" << std::endl;
			else
				std::cout << "test is not empty" << std::endl;

			std::cout << "=push an element in test=" << std::endl;
			test.push(10);
			
			std::cout << "=Test with something in the stack test=" << std::endl;
			if (test.empty())
				std::cout << "test is empty" << std::endl;
			else
				std::cout << "test is not empty" << std::endl;
			
			std::cout << std::endl << M_YELLOW << "*****fin de test*****" << M_RESET << std::endl << std::endl;
		}
		
		////////////////////////////////////////////////////////////////////////////////

		{
			std::cout << std::endl << M_CYAN << "=> size: " << M_RESET << std::endl << std::endl;

			NAMESPACE::stack<int>		test;

			std::cout << "=push element in test stack=" << std::endl;	

			test.push(42);
			std::cout << "test has a size of : " << test.size() << " element" << std::endl;
			
			std::cout << "=push element in test stack=" << std::endl;	
			test.push(24);
			std::cout << "test has a size of : " << test.size() << " element" << std::endl;
				
			std::cout << std::endl << M_YELLOW << "*****fin de test*****" << M_RESET << std::endl << std::endl;
		}
		
		////////////////////////////////////////////////////////////////////////////////
		
		{
			std::cout << std::endl << M_CYAN << "=> top / push : " << M_RESET << std::endl << std::endl;

			NAMESPACE::stack<int>		test;

			std::cout << "=push element 420 in test stack=" << std::endl;	
			test.push(420);
			std::cout << "top element in test stack: " << test.top() << std::endl;
			
			std::cout << "=push element 32 in test stack=" << std::endl;	
			test.push(32);
			std::cout << "top element in test stack: " << test.top() << std::endl;
			
			std::cout << "=push element 24 in test stack=" << std::endl;	
			test.push(24);
			std::cout << "top element in test stack: " << test.top() << std::endl;
			
			
			std::cout << std::endl << M_YELLOW << "*****fin de test*****" << M_RESET << std::endl << std::endl;
		}
		
		////////////////////////////////////////////////////////////////////////////////
		{
			std::cout << std::endl << M_CYAN << "=> pop : " << M_RESET << std::endl << std::endl;

			NAMESPACE::stack<int>		test;

			test.push(42);
			test.push(34);
			test.push(666);
			test.push(999);

			std::cout << "=Pushed [42 / 34 / 666 / 999] in test stack=" << std::endl; 
			
			std::cout << "top element in test stack: " << test.top() << std::endl;
			test.pop();
			std::cout << "top element in test stack after pop: " << test.top() << std::endl;
			
			std::cout << "top element in test stack: " << test.top() << std::endl;
			test.pop();
			std::cout << "top element in test stack after pop: " << test.top() << std::endl;
			
			std::cout << "top element in test stack: " << test.top() << std::endl;
			test.pop();
			std::cout << "top element in test stack after pop: " << test.top() << std::endl;


			std::cout << std::endl << M_YELLOW << "*****fin de test*****" << M_RESET << std::endl << std::endl;
		}
		
		////////////////////////////////////////////////////////////////////////////////
		
		{
			std::cout << std::endl << M_CYAN << "=> swap : " << M_RESET << std::endl << std::endl;

			NAMESPACE::stack<int>		test;
			NAMESPACE::stack<int>		test2;

			std::cout << "=Pushing [10 / 20 / 30 ] in test stack=" << std::endl;
			test.push(10);
			test.push(20);
			test.push(30);
			std::cout << "top element in test stack: " << test.top() << std::endl;
			std::cout << "test has a size of : " << test.size() << " elements" << std::endl;
			
			std::cout << "=Pushing [50 / 60 / 70 / 80] in test2 stack=" << std::endl;
			test2.push(50);
			test2.push(60);
			test2.push(70);
			test2.push(80);
			std::cout << "top element in test2 stack: " << test2.top() << std::endl;
			std::cout << "test2 has a size of : " << test2.size() << " elements" << std::endl;

			std::cout << "=swap stack test and stack test2" << std::endl;

			swap(test, test2);
			std::cout << "top element in test stack: " << test.top() << std::endl;
			std::cout << "test has a size of : " << test.size() << " elements" << std::endl;
			std::cout << "top element in test2 stack: " << test.top() << std::endl;
			std::cout << "test2 has a size of : " << test2.size() << " elements" << std::endl;
			
			
			std::cout << std::endl << M_YELLOW << "*****fin de test*****" << M_RESET << std::endl << std::endl;
		}
		
		////////////////////////////////////////////////////////////////////////////////
		
		{
			std::cout << std::endl << M_CYAN << "=> relational operators: " << M_RESET << std::endl << std::endl;
			NAMESPACE::stack<int> a, b, c;
			a.push(10);
			a.push(20);
			a.push(30);

			b.push(10);
			b.push(20);
			b.push(30);

			c.push(30);
			c.push(20);
			c.push(10);

			if (a==b) std::cout << "a and b are equal\n";
			if (b!=c) std::cout << "b and c are not equal\n";
			if (b<c) std::cout << "b is less than c\n";
			if (c>b) std::cout << "c is greater than b\n";
			if (a<=b) std::cout << "a is less than or equal to b\n";
			if (a>=b) std::cout << "a is greater than or equal to b\n";

			std::cout << std::endl << M_YELLOW << "*****fin de test*****" << M_RESET << std::endl << std::endl;
		}
	}
	return (0);
}