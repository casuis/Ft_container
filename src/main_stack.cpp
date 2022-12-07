/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_stack.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimon <asimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 18:30:36 by asimon            #+#    #+#             */
/*   Updated: 2022/12/07 12:11:03 by asimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <ftnspace.hpp>
# include <iostream>

int		main(void){
	
	////////////////////////////////////////////////////////////////////////////////
	/*                              STACK                                        */
	////////////////////////////////////////////////////////////////////////////////

	std::cout << std::endl << YELLOW << "##########STACK##########" << RESET << std::endl << std::endl;
	
	////////////////////////////////////////////////////////////////////////////////
	{
		std::cout << CYAN << "=> Basic tests:" << RESET << std::endl << std::endl;
		
		NAMESPACE::stack<int>					test1;
		NAMESPACE::vector<int>					vect_test(2, 42);
		NAMESPACE::stack<int>					test2(vect_test);
		
		std::cout << "test1.top: [" << test1.top() << "]" << std::endl
		<< "test1.size: [" << test1.size() << "]" << std::endl
		<< std::boolalpha << "test1.empty: [" << test1.empty() << "]" << std::endl;

		std::cout << std::endl;

		std::cout << "test2.top: [" << test2.top() << "]" << std::endl
		<< "test2.size: [" << test2.size() << "]" << std::endl
		<< std::boolalpha << "test2.empty: [" << test2.empty() << "]" << std::endl;
		
		std::cout << std::endl;
		
		test2.pop();
		std::cout << "test2.pop => test2.size: [" << test2.size() << "]" << std::endl
		<< "test2.top: [" << test2.top() << "]" << std::endl;
		

		std::cout << std::endl << YELLOW << "*****fin de test*****" << RESET << std::endl << std::endl;
	}
	////////////////////////////////////////////////////////////////////////////////
	{
		std::cout << CYAN << "=> Other tests:" << RESET << std::endl << std::endl;
		
		////////////////////////////////////////////////////////////////////////////////
		{
			std::cout << CYAN << "\t=> Inception tests:" << RESET << std::endl << std::endl;
			NAMESPACE::stack<NAMESPACE::vector<int> >		test1;
			NAMESPACE::vector<int>							test_to_insert(4, 10);
			
			std::cout << "Create a stack< vector<int> > and push in it an vector< int >: " << std::endl;
			test1.push(test_to_insert);
			
			std::cout << "test1.size: [" << test1.size() << "]" << std::endl;
			
			std::cout << std::endl << YELLOW << "*****fin de test*****" << RESET << std::endl << std::endl;
		}
		////////////////////////////////////////////////////////////////////////////////
		{
			std::cout << CYAN << "\t=> Opperator tests:" << RESET << std::endl << std::endl;
			
			NAMESPACE::stack<int>		stack1;
			NAMESPACE::stack<int>		stack2;

			stack1.push(42);
			stack2.push(21);

			std::cout << std::boolalpha
			<< "stack1.top : [" << stack1.top() << "]" << std::endl
			<< "stack2.top : [" << stack2.top() << "]" << std::endl
			<< "stack1 == stack2: [" << (stack1 == stack2) << "]" << std::endl
			<< "stack1 != stack2: [" << (stack1 != stack2) << "]" << std::endl
			<< "stack1 >= stack2: [" << (stack1 >= stack2) << "]" << std::endl
			<< "stack1 <= stack2: [" << (stack1 <= stack2) << "]" << std::endl
			<< "stack1 < stack2: [" << (stack1 < stack2) << "]" << std::endl
			<< "stack1 > stack2: [" << (stack1 > stack2) << "]" << std::endl;

		}
		std::cout << std::endl << YELLOW << "*****fin de test*****" << RESET << std::endl << std::endl;
	}
	return (0);
}