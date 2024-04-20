/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerperez <jerperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 11:19:59 by jerperez          #+#    #+#             */
/*   Updated: 2024/04/20 13:28:10 by jerperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


//Bureaucrat& const operator=(Bureaucrat& const); //
#include "Bureaucrat.hpp"
#include <ostream>

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b)
{
    os << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
    return os;
}

const char*	Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return (ELOWRANK);
}

const char*	Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return (EHIGHRANK);
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
unsigned int const	&Bureaucrat::getGrade(void) const
{
	return (this->_grade);
}

unsigned int const	&Bureaucrat::checkGrade(unsigned int &grade) const
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
