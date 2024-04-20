/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerperez <jerperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 16:09:52 by jerperez          #+#    #+#             */
/*   Updated: 2024/04/20 16:19:51 by jerperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include <fstream>

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	this->_target = other._target;
}

const std::string&	ShrubberyCreationForm::getTarget(void) const
{
	return (this->_target);
}

void	ShrubberyCreationForm::execute(Bureaucrat const &executor)
{
	std::ofstream ofile;

	ofile.open(this->_target + "_shrubbery");
	if (false == ofile.is_open())
	{
		std::cerr << "ShrubberyCreationForm: failed to create file" << std::endl;
		return ;
	}
	ofile << "ASCII trees" << std::endl;
	ofile.close();
}
