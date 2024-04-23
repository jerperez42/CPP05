/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerperez <jerperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 11:32:34 by jerperez          #+#    #+#             */
/*   Updated: 2024/04/23 15:04:18 by jerperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <fstream>
#include <sys/stat.h>
#include <unistd.h>

int main(void)
{
	std::cout << "--------Constructors--------" << std::endl;
	{
		Intern steve;
		Intern bob(steve);
		steve = bob;
	}

	std::cout << "--------OK--------" << std::endl;
	{
		Intern 		steve;
		Bureaucrat	abraracourcix("Abraracourcix", 1);
		AForm 		*f;
		std::string target("Caius Bonus");
		std::string name;

		name = FS_NAME;
		f = steve.makeForm(name, target);
		std::cout << *f << "(" << name << ")" << std::endl;
		f->beSigned(abraracourcix);
		abraracourcix.executeForm(*f);
		delete f;

		name = FP_NAME;
		f = steve.makeForm(name, target);
		std::cout << *f << "(" << name << ")" << std::endl;
		f->beSigned(abraracourcix);
		abraracourcix.executeForm(*f);
		delete f;

		name = FR_NAME;
		f = steve.makeForm(name, target);
		std::cout << *f << "(" << name << ")" << std::endl;
		f->beSigned(abraracourcix);
		abraracourcix.executeForm(*f);
		delete f;
	}

	std::cout << "--------Error--------" << std::endl;
	{
		Intern steve;
		AForm *f;
		std::string target("Steve");
		std::string name;

		try
		{
			name = "tenure";
			f = steve.makeForm(name, target);
			std::cout << f << "(" << name << ")" << std::endl;
			delete f;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
}