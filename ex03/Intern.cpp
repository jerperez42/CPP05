/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerperez <jerperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 11:05:07 by jerperez          #+#    #+#             */
/*   Updated: 2024/04/23 14:59:24 by jerperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
typedef	AForm *(Intern::*t_newform)(const std::string &target) const;

Intern::Intern(void)
{
	size_t	i;

	i = 0;
	this->_fun[i] = &Intern::newRobotomyRequestForm;
	this->_fun_label[i] = FR_NAME;
	i++;
	this->_fun[i] = &Intern::newShrubberyCreationForm;
	this->_fun_label[i] = FS_NAME;
	i++;
	this->_fun[i] = &Intern::newPresidentialPardonForm;
	this->_fun_label[i] = FP_NAME;
	i++;
	while (i < I_NFORMS)
	{
		this->_fun[i] = 0;
		this->_fun_label[i] = "";
		i++;
	}
}

Intern::Intern(const Intern &other)
{
	for (size_t i = 0; i < (I_NFORMS - 1); i++)
	{
		this->_fun_label[i] = other._fun_label[i];
		this->_fun[i] = other._fun[i];
	}
	this->_fun[I_NFORMS - 1] = 0;
	this->_fun_label[I_NFORMS - 1] = "";
}

AForm*		Intern::newRobotomyRequestForm(const std::string &target) const
{
	return (new RobotomyRequestForm(target));
}

AForm*		Intern::newShrubberyCreationForm(const std::string &target) const
{
	return (new ShrubberyCreationForm(target));
}

AForm*		Intern::newPresidentialPardonForm(const std::string &target) const
{
	return (new PresidentialPardonForm(target));
}

t_newform	Intern::findFun(const std::string &label) const
{
	for (size_t i = 0; i < (I_NFORMS - 1); i++)
	{
		if (label == this->_fun_label[i])
			return (this->_fun[i]);
	}
	return (0);
}

AForm*	Intern::makeForm(const std::string &name, const std::string &target) const
{
	size_t	index = 0;

	while (index < I_NFORMS && (name != this->_fun_label[index]))
		index++;
	if (index < I_NFORMS && this->_fun[index] && (name == this->_fun_label[index]))
		return ((this->*_fun[index])(target));
	throw UnknownFormException();
	return (0);
}

Intern&	Intern::operator=(const Intern &other)
{
	(void)other;
	return (*this);
}

const char*	Intern::UnknownFormException::what(void) const throw()
{
	return (B_EUNKNOWN);
}