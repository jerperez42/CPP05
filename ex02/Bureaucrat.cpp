/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerperez <jerperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 11:19:59 by jerperez          #+#    #+#             */
/*   Updated: 2024/04/20 15:13:55 by jerperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <ostream>
#include <iostream>

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b)
{
    os << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
    return os;
}

const char*	Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return (B_ELOWRANK);
}

const char*	Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return (B_EHIGHRANK);
}

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat& other)
{
	this->_grade = other._grade;
	this->checkGrade(this->_grade);
	return (*this);
}

std::string const	&Bureaucrat::getName(void) const
{
	return (this->_name);
}

t_grade const	&Bureaucrat::getGrade(void) const
{
	return (this->_grade);
}

t_grade const	&Bureaucrat::checkGrade(t_grade &grade) const
{
	if (1 > grade)
		throw GradeTooHighException();
	else if (GRADE_RANK_LOW < grade)
		throw GradeTooLowException();
	return (grade);
}

void	Bureaucrat::promote(void)
{
	this->_grade -= 1;
	this->checkGrade(this->_grade);
}

void	Bureaucrat::demote(void)
{
	this->_grade += 1;
	this->checkGrade(this->_grade);
}

void	Bureaucrat::signForm(AForm& form)
{
	try
	{
		form.beSigned(*this);
		std::cout << this->_name << " signed " << form.getName() << std::endl;
	}
	catch(const Form::GradeTooLowException& e)
	{
		std::cout << this->_name << " couldn’t sign " << form.getName() << " because they are underqualified." << std::endl;
	}
	catch(const Form::GradeTooHighException& e)
	{
		std::cout << this->_name << " couldn’t sign " << form.getName() << " because they are overqualified." << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << this->_name << " couldn’t sign " << form.getName() << " because of some reason." << std::endl;
	}
}