/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerperez <jerperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 11:32:34 by jerperez          #+#    #+#             */
/*   Updated: 2024/04/20 13:34:23 by jerperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

int main(void)
{
	std::cout << "--------Default--------" << std::endl;
	{
		Bureaucrat bob;
		std::cout << bob << std::endl;
		std::cout << std::endl;
	}
	std::cout << "--------Name, Grade--------" << std::endl;
	{
		std::string name;

		name = "Abraracourcix";
		Bureaucrat b1(name, 1);
		std::cout << b1 << std::endl << std::endl;

		name = "Penultimo";
		Bureaucrat b149(name, 149);
		std::cout << b149 << std::endl << std::endl;

		name = "The Rock";
		Bureaucrat b150(name, 150);
		std::cout << b150 << std::endl << std::endl;

		name = "xXx_gamer151_xX";
		std::cout << name << std::endl;
		try
		{
			Bureaucrat b151(name, 151);
			std::cout << b151 << std::endl << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl << std::endl;
		}
		
		name = "Zero";
		std::cout << name << std::endl;
		try
		{

			Bureaucrat b0(name, 0);
			std::cout << b0 << std::endl << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl << std::endl;
		}
	}
	std::cout << "--------Copy--------" << std::endl;
	{
		Bureaucrat original("original", 42);
		std::cout << original << std::endl;
		Bureaucrat clone(original);
		std::cout << clone << "(clone)" << std::endl << std::endl;
	}
	std::cout << "--------Operator=--------" << std::endl;
	{
		Bureaucrat calife("Le Calife", 1);
		Bureaucrat iznogood("Iznogood", 150);
		std::cout << iznogood << std::endl;
		std::cout << calife << std::endl;
		iznogood = calife;
		std::cout << iznogood << std::endl;
		std::cout << std::endl;
	}

	std::cout << "--------Promote--------" << std::endl;
	{
		Bureaucrat poo("Poo", 10);
		try
		{
			for (int i = 0; i < 150; i++)
			{
				std::cout << poo << std::endl;
				poo.promote();
			}
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
		std::cout << std::endl;
	}

	std::cout << "--------Demote--------" << std::endl;
	{
		Bureaucrat louis("Louis XVI", 140);
		try
		{
			for (int i = 0; i < 150; i++)
			{
				std::cout << louis << std::endl;
				louis.demote();
			}
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
		std::cout << std::endl;
	}
}