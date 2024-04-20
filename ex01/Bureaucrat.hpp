/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerperez <jerperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 11:05:07 by jerperez          #+#    #+#             */
/*   Updated: 2024/04/20 13:25:53 by jerperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <string>
#include <stdexcept>
#include <exception>
#include "Bureaucrat.h"

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
		unsigned int		_grade;
		unsigned int const	&checkGrade(unsigned int&) const;
	public:
		Bureaucrat(void) : _name(NAME_DFLT), _grade(GRADE_RANK_LOW) {};
		Bureaucrat(const std::string& name, unsigned int grade) : _name(name), _grade(checkGrade(grade)) {};
		Bureaucrat(const Bureaucrat& other) : _name(other._name), _grade(other._grade) {};
		~Bureaucrat(void) {};

		Bureaucrat&	operator=(const Bureaucrat&);
		std::string	const	&getName(void) const;
		unsigned int const	&getGrade(void) const;

		void				promote(void);
		void				demote(void);
};

std::ostream& operator<<(std::ostream&, const Bureaucrat&);

#endif
