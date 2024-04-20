/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerperez <jerperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 11:19:59 by jerperez          #+#    #+#             */
/*   Updated: 2024/04/20 17:17:27 by jerperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <ostream>

std::ostream& operator<<(std::ostream& os, const AForm& f)
{
    os	<< f.getName() << ", "
		<< (f.getSigned() ? "" : "not ") << "signed, "
		<< "grade " << f.getSign() << " bureaucrat required to sign, "
		<< f.getExec() << " to execute.";
    return (os);
}

const char*	AForm::GradeTooLowException::what(void) const throw()
{
	return (F_ELOWRANK);
}

const char*	AForm::GradeTooHighException::what(void) const throw()
{
	return (F_EHIGHRANK);
}

const char*	AForm::NotSignedException::what(void) const throw()
{
	return (F_ENOSIGN);
}

AForm&	AForm::operator=(const AForm& other)
{
	this->_signed = other._signed;
	return (*this);
}

const std::string	&AForm::getName(void) const
{
	return (this->_name);
}

const t_grade	&AForm::getSign(void) const
{
	return (this->_sign);
}

const t_grade	&AForm::getExec(void) const
{
	return (this->_exec);
}

const bool	&AForm::getSigned(void) const
{
	return (this->_signed);
}

const t_grade	&AForm::checkGrade(const t_grade &grade) const
{
	if (1 > grade)
		throw GradeTooHighException();
	else if (GRADE_RANK_LOW < grade)
		throw GradeTooLowException();
	return (grade);
}

void	AForm::beSigned(const Bureaucrat& b)
{
	const t_grade	grade = b.getGrade();

	if (this->_sign < grade)
		throw GradeTooLowException();
	this->_signed = true;
}

void	AForm::execute(Bureaucrat const &b) const
{
	const t_grade	grade = b.getGrade();

	if (false == this->_signed)
		throw NotSignedException();
	else if (this->_exec < grade)
		throw GradeTooLowException();
}
