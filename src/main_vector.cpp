/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_vector.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimon <asimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 13:34:53 by asimon            #+#    #+#             */
/*   Updated: 2023/02/20 20:24:43 by asimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <ftnspace.hpp>
# include <iostream>
# include <unistd.h>

#if STD == 1
	std::string		print_nspace = "##STD";
#else
	std::string		print_nspace = "##FT";
#endif


using namespace NAMESPACE;


template <class T>
void	print(vector<vector<T> >& lst)
{
	for (typename vector<vector<T> >::iterator it = lst.begin(); it != lst.end(); it++)
	{
		for (typename vector<T>::iterator it2 = it->begin(); it2 != it->end(); it2++)
			std::cout << *it2 << ' ';
		std::cout << '\n';
	}
}

template <class T>
void	print(vector<T>& lst)
{
	for (typename vector<T>::iterator it = lst.begin(); it != lst.end(); it++)
		std::cout << *it << ' ';
	std::cout << '\n';
}

int main ()
{
  vector<int> foo (3,100);   // three ints with a value of 100
  vector<int> bar (5,200);   // five ints with a value of 200

  foo.swap(bar);

  std::cout << "foo contains:";
  for (unsigned i=0; i<foo.size(); i++)
    std::cout << ' ' << foo[i];
  std::cout << '\n';

  std::cout << "bar contains:";
  for (unsigned i=0; i<bar.size(); i++)
    std::cout << ' ' << bar[i];
  std::cout << '\n';

{
	vector<int> foo,bar;

	foo.push_back(100);
	foo.push_back(200);

	bar.push_back(11);
	bar.push_back(22);
	bar.push_back(33);


	vector<int>::const_iterator tmp = foo.begin(); //tmp iterates through foo
	vector<int>::const_iterator tmp2 = bar.begin(); //tmp2 iterates through bar

	std::cout << "adresse de tmp (foo): " << &(*tmp) << std::endl;
	std::cout << "adresse de tmp2 (bar): " << &(*tmp2) << std::endl;
	std::cout << "adresse de bar.begin(): " << &(*bar.begin()) << std::endl;

	std::cout << "===================" << std::endl;
	
	swap(bar, foo); //tmp iterates through bar
					//tmp2 iterates through foo


	std::cout << "adresse de tmp : " << &(*tmp) << std::endl;
	std::cout << "adresse de bar.begin(): " << &(*bar.begin()) << std::endl;
	vector<int>	other;

	other.push_back(73);
	other.push_back(173);
	other.push_back(763);
	other.push_back(73854);
	other.push_back(74683);
	other.push_back(753);

	vector<int>::const_iterator tmp3 = other.begin(); // tmp3 iterates through other

	std::cout << "foo contains:\n";
	for (vector<int>::iterator it=foo.begin(); it!=foo.end(); ++it)
		std::cout << " " << *it;
		
	std::cout << std::endl;
	
	std::cout << "bar contains:\n";
	for (vector<int>::iterator it=bar.begin(); it!=bar.end(); ++it)
		std::cout << " " << *it;
	
	std::cout << std::endl;
	
	while(tmp != bar.end())
	{
		std::cout << "la << " << *tmp << '\n';
		tmp++;
		usleep(800000);
	}
	tmp--;

	while(tmp2 != foo.end())
	{
		std::cout << "ici << " << *tmp2 << '\n';
		tmp2++;
	}
	tmp2--;

	swap(other, foo); //tmp2 iterates through other
					//tmp3 iterates throught foo
	print(other);
	print(foo);
	print(bar);
	while(tmp != bar.begin())
	{
		std::cout << *tmp << '\n';
		tmp--;
	}
	std::cout << *tmp << '\n';

	while(tmp2 != other.begin())
	{
		std::cout << *tmp2 << '\n';
		tmp2--;
	}
		std::cout << *tmp2 << '\n';

	while(tmp3 != foo.end())
	{
		std::cout << "you know << " << std::endl;
		std::cout << *tmp3 << '\n';
		tmp3++;
	}
	tmp3--;

	// swap(bar, foo);
	// swap(foo, bar);
	// swap(bar, foo); //tmp3 iterates through bar
	// 			//tmp iterates through foo

	// print(other);
	// print(foo);
	// print(bar);

	// while(tmp != foo.end())
	// {
	// 	std::cout << *tmp << '\n';
	// 	tmp++;
	// }

	// while(tmp2 != other.end())
	// {
	// 	std::cout << *tmp2 << '\n';
	// 	tmp2++;
	// }

	// while(tmp3 != bar.begin())
	// {
	// 	std::cout << *tmp3 << '\n';
	// 	tmp3--;
	// }
	// 	std::cout << *tmp3 << '\n';
}

  return 0;
}



// int		main(void)
// {

// 	// ////////////////////////////////////////////////////////////////////////////////
// 	// /*                              VECTOR                                        */
// 	// ////////////////////////////////////////////////////////////////////////////////
// 	// std::cout << print_nspace << std::endl;
// 	// std::cout << std::endl << M_YELLOW << "##########VECTOR##########" << M_M_RESET << std::endl << std::endl;

// 	// ////////////////////////////////////////////////////////////////////////////////
// 	// {	
// 	// 	std::cout << M_M_CYAN << "=========CONSTRUCTOR=========" << M_M_RESET << std::endl;
		
// 	// 	NAMESPACE::vector<int>										tab(1, 40);
// 	// 	NAMESPACE::vector<int>										tab_bis(2, 10);
		
// 	// 	////////////////////////////////////////////////////////////////////////////////
// 	// 	{
// 	// 		std::cout << M_M_CYAN << "=> Test Default Constructor " << M_M_RESET << std::endl << std::endl;
// 	// 		NAMESPACE::vector< int >			test;

// 	// 		ft::print(test, "default: ");

// 	// 		std::cout << std::endl << M_YELLOW << "*****fin de test*****" << M_M_RESET << std::endl << std::endl;
// 	// 	}
// 	// 	////////////////////////////////////////////////////////////////////////////////
// 	// 	{
// 	// 		std::cout << M_M_CYAN << "=> Test copy Constructor" << M_M_RESET << std::endl << std::endl;
// 	// 		NAMESPACE::vector< int >			copy(tab);

// 	// 		ft::print(tab, "original: ");
// 	// 		ft::print(copy, "copy: ");

// 	// 		std::cout << std::endl << M_YELLOW << "*****fin de test*****" << M_M_RESET << std::endl << std::endl;
// 	// 	}
// 	// 	////////////////////////////////////////////////////////////////////////////////
// 	// 	{
// 	// 		std::cout << M_M_CYAN << "=> Test range constructor" << M_M_RESET << std::endl << std::endl;
			
// 	// 		NAMESPACE::vector< int >		fill(tab.begin() + 1, tab.end());
			
// 	// 		ft::print(tab, "tab utilise pour fill: ");
// 	// 		ft::print(fill, "fill by range + 1: ");

// 	// 		std::cout << std::endl << M_YELLOW << "*****fin de test*****" << M_M_RESET << std::endl << std::endl;
// 	// 	}
// 	// }	
// 	// ////////////////////////////////////////////////////////////////////////////////
// 	// {
// 	// 	std::cout << M_M_CYAN << "=========OPERATOR=========" << M_M_RESET << std::endl;
		
// 	// 		NAMESPACE::vector<int>		std_tab(10,20);
// 	// 	////////////////////////////////////////////////////////////////////////////////
// 	// 	{
	
// 	// 		NAMESPACE::vector<int>		std_tab2 = std_tab;
	
// 	// 		std_tab.push_back(100);
// 	// 		std::cout << std::boolalpha << (std_tab < std_tab2) << std::endl;
			
// 	// 		for (NAMESPACE::vector<int>::iterator std_it = std_tab2.begin(), std_ite = std_tab2.end();
// 	// 		std_it != std_ite; std_it++){
// 	// 			std::cout << *std_it << std::endl;
// 	// 		}
// 	// 	}
// 	// 	////////////////////////////////////////////////////////////////////////////////
// 	// }

// 	// ////////////////////////////////////////////////////////////////////////////////
// 	// {
// 	// 	std::cout << M_M_CYAN << "=========INCEPTION=========" << M_M_RESET << std::endl;

// 	// 		NAMESPACE::vector<int>										tab_to_insert(1, 40);
// 	// 		NAMESPACE::vector<int>										tab_bis_to_insert(2, 10);
// 	// 		NAMESPACE::vector< NAMESPACE::vector<int> >					tab(4, tab_to_insert);
// 	// 		NAMESPACE::vector< NAMESPACE::vector<int> >					tab_bis(2, tab_bis_to_insert);


// 	// 	////////////////////////////////////////////////////////////////////////////////
// 	// 	{
// 	// 		std::cout << M_M_CYAN << "=> Test Default Constructor " << M_M_RESET << std::endl << std::endl;
// 	// 		NAMESPACE::vector< NAMESPACE::vector<int> >			test;

// 	// 		ft::print(test, "default: ");

// 	// 		std::cout << std::endl << M_YELLOW << "*****fin de test*****" << M_M_RESET << std::endl << std::endl;
// 	// 	}
// 	// 	////////////////////////////////////////////////////////////////////////////////
// 	// 	{
// 	// 		std::cout << M_M_CYAN << "=> Test copy Constructor" << M_M_RESET << std::endl << std::endl;
// 	// 		NAMESPACE::vector< NAMESPACE::vector<int> >			copy(tab);

// 	// 		ft::print(tab, "original: ");
// 	// 		ft::print(copy, "copy: ");

// 	// 		std::cout << std::endl << M_YELLOW << "*****fin de test*****" << M_M_RESET << std::endl << std::endl;
// 	// 	}
// 	// 	////////////////////////////////////////////////////////////////////////////////
// 	// 	{
// 	// 		std::cout << M_M_CYAN << "=> Test range constructor" << M_M_RESET << std::endl << std::endl;
			
// 	// 		NAMESPACE::vector< NAMESPACE::vector<int> >		fill(tab.begin() + 1, tab.end());
			
// 	// 		ft::print(tab, "tab utilise pour fill: ");
// 	// 		ft::print(fill, "fill by range + 1: ");

// 	// 		std::cout << std::endl << M_YELLOW << "*****fin de test*****" << M_M_RESET << std::endl << std::endl;
// 	// 	}
// 	// 	////////////////////////////////////////////////////////////////////////////////
// 	// 	{
// 	// 		std::cout << M_M_CYAN << "=> Test capacity section:" << M_M_RESET << std::endl << std::endl;

// 	// 		NAMESPACE::vector< NAMESPACE::vector<int> >			test;

// 	// 		ft::print(tab, "tab: ");
// 	// 		std::cout << std::boolalpha << "test is empty? [" << M_GREEN << test.empty() << M_M_RESET << "]" << std::endl; 
// 	// 		std::cout << std::boolalpha << "tab is empty? [" << M_GREEN << tab.empty() << M_M_RESET << "]" << std::endl; 

// 	// 		std::cout << std::endl << M_YELLOW << "*****fin de test*****" << M_M_RESET << std::endl << std::endl;
// 	// 	}
// 	// 	////////////////////////////////////////////////////////////////////////////////
// 	// 	{
// 	// 		std::cout << M_M_CYAN << "=> Test reserve: " << M_M_RESET << std::endl << std::endl;

// 	// 		NAMESPACE::vector< NAMESPACE::vector<int> >			test(tab);

// 	// 		ft::print(test, "test: ");
			
// 	// 		std::cout << "reserve for 10" << std::endl; 
// 	// 		test.reserve(10);
			
// 	// 		ft::print(test, "test after: ");

// 	// 		std::cout << std::endl << M_YELLOW << "*****fin de test*****" << M_M_RESET << std::endl << std::endl;
// 	// 	}
// 	// 	////////////////////////////////////////////////////////////////////////////////
// 	// 	{
// 	// 		std::cout << M_M_CYAN << "=> Test resize:" << M_M_RESET << std::endl << std::endl;
			
// 	// 		NAMESPACE::vector< NAMESPACE::vector<int> >			test(tab);
			
// 	// 		ft::print(test, "test: ");
			
// 	// 		std::cout << "resize to 42" << std::endl;
// 	// 		test.resize(42);

// 	// 		ft::print(test, "test after: ");			

// 	// 		std::cout << std::endl << M_YELLOW << "*****fin de test*****" << M_M_RESET << std::endl << std::endl;
// 	// 	}
// 	// 	////////////////////////////////////////////////////////////////////////////////
// 	// 	{
// 	// 		std::cout << M_M_CYAN << "=> Test operator[]:" << M_M_RESET << std::endl << std::endl;
// 	// 		NAMESPACE::vector<int>			test;

// 	// 		for (int i = 0; i < 10; i++){
// 	// 			test.push_back(i);
// 	// 			std::cout << "cap: [" << test.capacity() << "]" << std::endl; 
				
// 	// 		}
			
				
// 	// 		ft::print(test, "test: ");
			
// 	// 		std::cout << "value tab[0]: [" << M_GREEN << test[0] << M_M_RESET << "]" << std::endl;			
			
// 	// 		std::cout << std::endl << M_YELLOW << "*****fin de test*****" << M_M_RESET << std::endl << std::endl;
// 	// 	}
// 	// 	////////////////////////////////////////////////////////////////////////////////
// 	// 	{
// 	// 		std::cout << M_M_CYAN << "=> Test at:" << M_M_RESET << std::endl << std::endl;
// 	// 		NAMESPACE::vector<int>			test;

// 	// 		for (int i = 0; i < 10; i++)
// 	// 			test.push_back(i);

// 	// 		ft::print(test, "test: ");
			
// 	// 		std::cout << "value tab[2]: [" << M_GREEN << test.at(2) << M_M_RESET << "]" << std::endl;			
			
// 	// 		std::cout << std::endl << M_YELLOW << "*****fin de test*****" << M_M_RESET << std::endl << std::endl;
// 	// 	}
// 	// 	////////////////////////////////////////////////////////////////////////////////
// 	// 	{
// 	// 		std::cout << M_M_CYAN << "=> Test front:" << M_M_RESET << std::endl << std::endl;
// 	// 		NAMESPACE::vector<int>			test;

// 	// 		for (int i = 0; i < 10; i++)
// 	// 			test.push_back(i);
				
// 	// 		ft::print(test, "test: ");
			
// 	// 		std::cout << "value front: [" << M_GREEN << test.front() << M_M_RESET << "]" << std::endl;			
			
// 	// 		std::cout << std::endl << M_YELLOW << "*****fin de test*****" << M_M_RESET << std::endl << std::endl;
// 	// 	}
// 	// 	////////////////////////////////////////////////////////////////////////////////
// 	// 	{
// 	// 		std::cout << M_M_CYAN << "=> Test back:" << M_M_RESET << std::endl << std::endl;
// 	// 		NAMESPACE::vector<int>			test;

// 	// 		for (int i = 0; i < 10; i++)
// 	// 			test.push_back(i);
				
// 	// 		ft::print(test, "test: ");
			
// 	// 		std::cout << "value back: [" << M_GREEN << test.back() << M_M_RESET << "]" << std::endl;			
			
// 	// 		std::cout << std::endl << M_YELLOW << "*****fin de test*****" << M_M_RESET << std::endl << std::endl;
// 	// 	}
// 	// 	////////////////////////////////////////////////////////////////////////////////
// 	// 	{
// 	// 		std::cout << M_M_CYAN << "=> Test clear:" << M_M_RESET << std::endl << std::endl;
// 	// 		NAMESPACE::vector<int>			test;

// 	// 		for (int i = 0; i < 10; i++)
// 	// 			test.push_back(i);
				
// 	// 		ft::print(test, "test: ");
			
// 	// 		test.clear();
			
// 	// 		ft::print(test, "test: ");
			
// 	// 		// std::cout << std::endl << "value test.at(1): [" << test.at(1) << "]" << std::endl; 
// 	// 		// std::cout << std::endl << "value test[1]: [" << test[1] << "]" << std::endl; 
			
// 	// 		std::cout << std::endl << M_YELLOW << "*****fin de test*****" << M_M_RESET << std::endl << std::endl;
// 	// 	}
// 	// 	////////////////////////////////////////////////////////////////////////////////
// 	// 	{
// 	// 		std::cout << M_M_CYAN << "=> Test pop_back:" << M_M_RESET << std::endl << std::endl;
// 	// 		NAMESPACE::vector<int>			test;

// 	// 		for (int i = 0; i < 10; i++)
// 	// 			test.push_back(i);
				
// 	// 		ft::print(test, "test: ");
			
// 	// 		std::cout << std::endl << "back value: [" << test.back() << "]" << std::endl; 
// 	// 		test.pop_back();
// 	// 		std::cout << std::endl << "back value after pop_back: [" << test.back() << "]" << std::endl; 
			
// 	// 		std::cout << std::endl << M_YELLOW << "*****fin de test*****" << M_M_RESET << std::endl << std::endl;
// 	// 	}
// 	// 	////////////////////////////////////////////////////////////////////////////////
// 	// 	{
// 	// 		std::cout << M_M_CYAN << "=> Test swap:" << M_M_RESET << std::endl << std::endl;
// 	// 		NAMESPACE::vector<int>			test;
// 	// 		NAMESPACE::vector<int>			test_bis;
// 	// 		NAMESPACE::vector<int>			test_tier;


// 	// 		for (int i = 0; i < 10; i++)
// 	// 			test.push_back(i);
// 	// 		for (int i = 10; i < 24; i++)
// 	// 			test_bis.push_back(i);
			
// 	// 		ft::print(test, "test: ");
// 	// 		ft::print(test_bis, "test_bis: ");
			
// 	// 		test.swap(test_bis);
			
// 	// 		ft::print(test, "test after swap : ");
// 	// 		ft::print(test_bis, "test_bis after swap: ");

// 	// 		test.swap(test_tier);
// 	// 		ft::print(test, "test after swap : ");
// 	// 		ft::print(test_tier, "test_tiers after swap : ");
			
// 	// 		std::cout << std::endl << M_YELLOW << "*****fin de test*****" << M_M_RESET << std::endl << std::endl;
// 	// 	}
// 	// 	////////////////////////////////////////////////////////////////////////////////
// 	// 	{
// 	// 		std::cout << M_M_CYAN << "=> Test erase:" << M_M_RESET << std::endl << std::endl;
// 	// 		NAMESPACE::vector<int>			test;


// 	// 		for (int i = 0; i < 10; i++)
// 	// 			test.push_back(i);
			
// 	// 		ft::print(test, "test: ");
			
// 	// 		test.erase(test.begin() + 4, test.end());
			
// 	// 		ft::print(test, "test: ");
			
// 	// 		std::cout << std::endl << M_YELLOW << "*****fin de test*****" << M_M_RESET << std::endl << std::endl;
// 	// 	}
// 	// 	////////////////////////////////////////////////////////////////////////////////
// 	// 	{
// 	// 		std::cout << M_M_CYAN << "=> Test assign:" << M_M_RESET << std::endl << std::endl;
// 	// 		NAMESPACE::vector<int>			test;
// 	// 		NAMESPACE::vector<int>			test_bis;
			
// 	// 		for (int i = 0; i < 10; i++)
// 	// 			test.push_back(i);
// 	// 		for (int i = 10; i < 24; i++)
// 	// 			test_bis.push_back(i);
			
// 	// 		ft::print(test, "test: ");
// 	// 		ft::print(test_bis, "test_bis: ");
			
// 	// 		test.assign(test_bis.begin() + 1, test_bis.end());
// 	// 		ft::print(test, "test 1: ");
// 	// 		test.assign(8, 42);
// 	// 		ft::print(test, "test 2: ");
			
// 	// 		std::cout << std::endl << M_YELLOW << "*****fin de test*****" << M_M_RESET << std::endl << std::endl;
// 	// 	}
// 	// 	////////////////////////////////////////////////////////////////////////////////
// 	// 	{
// 	// 		std::cout << M_M_CYAN << "=> Test insert normale:" << M_M_RESET << std::endl << std::endl;
// 	// 		NAMESPACE::vector<int>			test;
// 	// 		NAMESPACE::vector<int>			test_bis;
// 	// 		NAMESPACE::vector<int>			more_test;
			
// 	// 		for (int i = 0; i < 10; i++)
// 	// 			test.push_back(0);
// 	// 		for (int i = 10; i < 24; i++)
// 	// 			test_bis.push_back(i);
			
// 	// 		ft::print(test, "test: ");
// 	// 		ft::print(test_bis, "test_bis: ");
			
// 	// 		test.insert(test.begin() + 1, test_bis.begin() + 2, test_bis.end());
			
// 	// 		ft::print(test, "test 1: ");
			
// 	// 		std::cout << "cap: [" << more_test.capacity() << "]" << std::endl; 
// 	// 		more_test.insert(more_test.begin(), 9, 42);
// 	// 		std::cout << "cap: [" << more_test.capacity() << "]" << std::endl;
// 	// 		ft::print(more_test, "test 2: ");

			
// 	// 		std::cout << std::endl << M_YELLOW << "*****fin de test*****" << M_M_RESET << std::endl << std::endl;
// 	// 	}
// 	// 	////////////////////////////////////////////////////////////////////////////////
// 	// 	{
// 	// 		std::cout << M_M_CYAN << "=> Test insert inception:" << M_M_RESET << std::endl << std::endl;

// 	// 		NAMESPACE::vector< NAMESPACE::vector<int> >::iterator		it = tab_bis.begin();
// 	// 		NAMESPACE::vector< NAMESPACE::vector<int> >::iterator		ite = tab_bis.end();

// 	// 		std::cout << std::endl;
// 	// 		ft::print(tab, "tab avant insert: ");
// 	// 		tab.insert(tab.begin(), it, ite);
// 	// 		ft::print(tab, "tab apres insert: ");
// 	// 		std::cout << "tab size " << tab.size() << std::endl;

// 	// 		std::cout << std::endl << M_YELLOW << "*****fin de test*****" << M_M_RESET << std::endl << std::endl;
// 	// 	}
// 	// 	////////////////////////////////////////////////////////////////////////////////
// 	// 	{
// 	// 		std::cout << M_M_CYAN << "=> Test swap:" << M_M_RESET << std::endl << std::endl;
// 	// 		/* tab_to_insert | tab_bis_to_insert | tab | tab_bis */
			
// 	// 		ft::print(tab, "tab: ");
// 	// 		ft::print(tab_bis, "tab_bis: ");
// 	// 		std::cout << std::endl;
// 	// 		tab.swap(tab_bis);
// 	// 		ft::print(tab, "tab 2eme call: ");
// 	// 		ft::print(tab, "tab_bis 2eme call: ");

// 	// 		std::cout << std::endl << M_YELLOW << "*****fin de test*****" << M_M_RESET << std::endl << std::endl;
// 	// 	}	
// 	// 	////////////////////////////////////////////////////////////////////////////////
// 	// }
// 	// ////////////////////////////////////////////////////////////////////////////////
// 	// {
// 	// 	std::cout << M_M_CYAN << "=========MORE TEST=========" << M_M_RESET << std::endl;

// 	// 	// NAMESPACE::vector<std::string>					test(8);
// 	// 	// NAMESPACE::vector<std::string>::iterator		it = test.begin();

// 	// 	// test.push_back("AAAAAA");
// 	// 	// std::cout << *it << std::endl;
		
// 	// 	////////////////////////////////////////////////////////////////////////////////
// 	// }

	
// 	// 	////////////////////////////////////////////////////////////////////////////////
// 	/* INCEPTION */
	

// 	//////////////////////////////////////////////////////////////////////////////////////
	
// 	return (0);
// }
