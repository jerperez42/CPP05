/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerperez <jerperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 11:32:34 by jerperez          #+#    #+#             */
/*   Updated: 2024/04/20 18:09:59 by jerperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include <fstream>
#include <sys/stat.h>
#include <unistd.h>

int main(void)
{
	std::cout << "--------Default--------" << std::endl;
	{
		PresidentialPardonForm pardon;
		std::cout << pardon << std::endl;
		std::cout << std::endl;

		RobotomyRequestForm robotomy;
		std::cout << robotomy << std::endl;
		std::cout << std::endl;

		ShrubberyCreationForm shrub;
		std::cout << shrub << std::endl;
		std::cout << std::endl;
	}

	std::cout << "--------OK--------" << std::endl;
	{
		Bureaucrat	abraracourcix("Abraracourcix", 1);

		PresidentialPardonForm pardon("Abraracourcix");
		std::cout << pardon << std::endl;
		abraracourcix.signForm(pardon);
		std::cout << pardon << std::endl;
		abraracourcix.executeForm(pardon);
		std::cout << std::endl;

		RobotomyRequestForm robotomy("Caius Bonus");
		std::cout << robotomy << std::endl;
		abraracourcix.signForm(robotomy);
		std::cout << robotomy << std::endl;
		abraracourcix.executeForm(robotomy);
		std::cout << std::endl;

		ShrubberyCreationForm shrub("Rome");
		std::cout << shrub << std::endl;
		abraracourcix.signForm(shrub);
		std::cout << shrub << std::endl;
		abraracourcix.executeForm(shrub);
		std::cout << std::endl;
	}

	std::cout << "--------Execute LOW--------" << std::endl;
	{
		Bureaucrat	abraracourcix("Abraracourcix", 1);
		Bureaucrat	penultimo("Penultimo", 149);

		PresidentialPardonForm pardon("Abraracourcix");
		std::cout << pardon << std::endl;
		abraracourcix.signForm(pardon);
		std::cout << pardon << std::endl;
		penultimo.executeForm(pardon);
		std::cout << std::endl;

		RobotomyRequestForm robotomy("Caius Bonus");
		std::cout << robotomy << std::endl;
		abraracourcix.signForm(robotomy);
		std::cout << robotomy << std::endl;
		penultimo.executeForm(robotomy);
		std::cout << std::endl;

		ShrubberyCreationForm shrub("Rome");
		std::cout << shrub << std::endl;
		abraracourcix.signForm(shrub);
		std::cout << shrub << std::endl;
		penultimo.executeForm(shrub);
		std::cout << std::endl;
	}

	std::cout << "--------Execute Unsigned--------" << std::endl;
	{
		Bureaucrat	abraracourcix("Abraracourcix", 1);

		PresidentialPardonForm pardon("Abraracourcix");
		std::cout << pardon << std::endl;
		abraracourcix.executeForm(pardon);
		std::cout << std::endl;

		RobotomyRequestForm robotomy("Caius Bonus");
		std::cout << robotomy << std::endl;
		abraracourcix.executeForm(robotomy);
		std::cout << std::endl;

		ShrubberyCreationForm shrub("Rome");
		std::cout << shrub << std::endl;
		abraracourcix.executeForm(shrub);
		std::cout << std::endl;
	}

	std::cout << "--------Robotomy 50%--------" << std::endl;
	{
		Bureaucrat	abraracourcix("Abraracourcix", 1);

		RobotomyRequestForm robotomy("Caius Bonus");
		abraracourcix.signForm(robotomy);
		std::cout << robotomy << std::endl;
		for (int i = 0; i < 10; i++)
			abraracourcix.executeForm(robotomy);
		std::cout << std::endl;
	}

	std::cout << "--------Shrubbery Fail (chmod 000)--------" << std::endl;
	{
		Bureaucrat	abraracourcix("Abraracourcix", 1);
		std::string target("fail");
		std::string name = target + std::string("_shrubbery");
		std::ofstream ofile;

		ShrubberyCreationForm shrub(target);
		abraracourcix.signForm(shrub);
		std::cout << shrub << std::endl;
		ofile.open(name.c_str());
		chmod(name.c_str(), 000);
		abraracourcix.executeForm(shrub);
		chmod(name.c_str(), 0777);
		ofile.close();
		unlink(name.c_str());
		std::cout << std::endl;
	}
}