/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerperez <jerperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 11:32:34 by jerperez          #+#    #+#             */
/*   Updated: 2024/04/20 15:08:32 by jerperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main(void)
{
	std::cout << "--------Default--------" << std::endl;
	{
		Form f;
		std::cout << f << std::endl;
		std::cout << std::endl;
	}

	std::cout << "--------Name, Grades--------" << std::endl;
	{
		std::string name;

		name = "War Declaration";
		{
			Form f(name, 1, 1);
			std::cout << f << std::endl << std::endl;
		}
		name = "2nd Amed. wif even mor gUns";
		{
			Form f(name, 150, 150);
			std::cout << f << std::endl << std::endl;
		}
		name = "Bill-49-3";
		{
			Form f(name, 49, 3);
			std::cout << f << std::endl << std::endl;
		}
	}

	std::cout << "--------Bad forms--------" << std::endl;
	{
		int	sign;
		int	exec;
		{
			sign = 0;
			exec = 42;
			try
			{
				std::cout << "sign:" << sign << " exec " << exec << std::endl;
				Form f("Trash", sign, exec);
			}
			catch(const std::exception& e)
			{
				std::cerr << e.what() << std::endl << std::endl;
			}
		}
		{
			sign = 42;
			exec = 0;
			try
			{
				std::cout << "sign:" << sign << " exec " << exec << std::endl;
				Form f("Trash", sign, exec);
			}
			catch(const std::exception& e)
			{
				std::cerr << e.what() << std::endl << std::endl;
			}
		}
		{
			sign = 360;
			exec = 42;
			try
			{
				std::cout << "sign:" << sign << " exec " << exec << std::endl;
				Form f("Trash", sign, exec);
			}
			catch(const std::exception& e)
			{
				std::cerr << e.what() << std::endl << std::endl;
			}
		}
		{
			sign = 42;
			exec = 360;
			try
			{
				std::cout << "sign:" << sign << " exec " << exec << std::endl;
				Form f("Trash", sign, exec);
			}
			catch(const std::exception& e)
			{
				std::cerr << e.what() << std::endl << std::endl;
			}
		}
	}
	
	std::cout << "--------Sign--------" << std::endl;
	{
		std::string name;

		name = "War Declaration";
		Form war(name, 1, 1);
		std::cout << war << std::endl << std::endl;

		name = "Abraracourcix";
		Bureaucrat abra(name, 1);
		std::cout << abra << std::endl << std::endl;

		name = "Penultimo";
		Bureaucrat penu(name, 149);
		std::cout << penu << std::endl << std::endl;
	
		penu.signForm(war);
		std::cout << war << std::endl << std::endl;
		abra.signForm(war);
		std::cout << war << std::endl << std::endl;

		std::cout << "--------copy--------" << std::endl;
		Form copy(war);
		std::cout << war << std::endl;
		std::cout << copy << "(copy)"  << std::endl << std::endl;
		std::cout << "--------operator=--------" << std::endl;
		copy = war;
		std::cout << war << std::endl;
		std::cout << copy << "(copy)" << std::endl << std::endl;
	}
	// 	name = "Zero";
	// 	std::cout << name << std::endl;
	// 	try
	// 	{

	// 		Bureaucrat b0(name, 0);
	// 		std::cout << b0 << std::endl << std::endl;
	// 	}
	// 	catch(const std::exception& e)
	// 	{
	// 		std::cerr << e.what() << std::endl << std::endl;
	// 	}
	// }
	// std::cout << "--------Copy--------" << std::endl;
	// {
	// 	Bureaucrat original("original", 42);
	// 	std::cout << original << std::endl;
	// 	Bureaucrat clone(original);
	// 	std::cout << clone << "(clone)" << std::endl << std::endl;
	// }
	// std::cout << "--------Operator=--------" << std::endl;
	// {
	// 	Bureaucrat calife("Le Calife", 1);
	// 	Bureaucrat iznogood("Iznogood", 150);
	// 	std::cout << iznogood << std::endl;
	// 	std::cout << calife << std::endl;
	// 	iznogood = calife;
	// 	std::cout << iznogood << std::endl;
	// 	std::cout << std::endl;
	// }

	// std::cout << "--------Promote--------" << std::endl;
	// {
	// 	Bureaucrat poo("Poo", 10);
	// 	try
	// 	{
	// 		for (int i = 0; i < 150; i++)
	// 		{
	// 			std::cout << poo << std::endl;
	// 			poo.promote();
	// 		}
	// 	}
	// 	catch(const std::exception& e)
	// 	{
	// 		std::cerr << e.what() << std::endl;
	// 	}
	// 	std::cout << std::endl;
	// }

	// std::cout << "--------Demote--------" << std::endl;
	// {
	// 	Bureaucrat louis("Louis XVI", 140);
	// 	try
	// 	{
	// 		for (int i = 0; i < 150; i++)
	// 		{
	// 			std::cout << louis << std::endl;
	// 			louis.demote();
	// 		}
	// 	}
	// 	catch(const std::exception& e)
	// 	{
	// 		std::cerr << e.what() << std::endl;
	// 	}
	// 	std::cout << std::endl;
	// }
}