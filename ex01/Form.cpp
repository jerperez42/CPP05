/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerperez <jerperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 11:19:59 by jerperez          #+#    #+#             */
/*   Updated: 2024/04/20 15:05:45 by jerperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <ostream>

std::ostream& operator<<(std::ostream& os, const Form& f)
{
    os	<< f.getName() << ", "
		<< (f.getSigned() ? "" : "not ") << "signed, "
		<< "grade " << f.getReqSign() << " bureaucrat required to sign, "
		<< f.getReqExec() << " to execute.";
    return (os);
}

const char*	Form::GradeTooLowException::what(void) const throw()
{
	return (F_ELOWRANK);
}

const char*	Form::GradeTooHighException::what(void) const throw()
{
	return (F_EHIGHRANK);
}

Form&	Form::operator=(const Form& other)
{
	this->_signed = other._signed;
	return (*this);
}

const std::string	&Form::getName(void) const
{
	return (this->_name);
}

const t_grade	&Form::getReqSign(void) const
{
	return (this->_req_sign);
}

const t_grade	&Form::getReqExec(void) const
{
	return (this->_req_exec);
}

const bool	&Form::getSigned(void) const
{
	return (this->_signed);
}

const t_grade	&Form::checkGrade(const t_grade &grade) const
{
	if (1 > grade)
		throw GradeTooHighException();
	else if (GRADE_RANK_LOW < grade)
		throw GradeTooLowException();
	return (grade);
}

void	Form::beSigned(const Bureaucrat& b)
{
	const t_grade	grade = b.getGrade();

	if (this->_req_sign < grade)
		throw GradeTooLowException();
	this->_signed = true;
}
