/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerperez <jerperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 16:09:52 by jerperez          #+#    #+#             */
/*   Updated: 2024/04/20 18:03:03 by jerperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include <fstream>

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	this->_target = other._target;
	return (*this);
}

const std::string&	ShrubberyCreationForm::getTarget(void) const
{
	return (this->_target);
}

void	ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	std::ofstream ofile;

	this->AForm::execute(executor);
	ofile.open((this->_target + std::string("_shrubbery")).c_str());
	if (false == ofile.is_open())
	{
		throw std::exception();
	}
	ofile << "ASCII trees" << std::endl;
	ofile.close();
}
