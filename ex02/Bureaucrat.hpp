/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerperez <jerperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 11:05:07 by jerperez          #+#    #+#             */
/*   Updated: 2024/04/20 15:14:07 by jerperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <string>
#include <stdexcept>
#include <exception>
#include "Bureaucrat.h"
class AForm;

class Bureaucrat
{
	private:
		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what(void) const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what(void) const throw();
		};
		std::string	const	_name;
		t_grade				_grade;
		t_grade const		&checkGrade(unsigned int&) const;
	public:
		Bureaucrat(void) : _name(B_NAME_DFLT), _grade(GRADE_RANK_LOW) {};
		Bureaucrat(const std::string& name, t_grade grade) : _name(name), _grade(checkGrade(grade)) {};
		Bureaucrat(const Bureaucrat& other) : _name(other._name), _grade(other._grade) {};
		~Bureaucrat(void) {};

		Bureaucrat&	operator=(const Bureaucrat&);
		std::string	const	&getName(void) const;
		t_grade const		&getGrade(void) const;

		void				promote(void);
		void				demote(void);
		void				signForm(Form&);
};

std::ostream& operator<<(std::ostream&, const Bureaucrat&);

#endif
