/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerperez <jerperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 11:05:07 by jerperez          #+#    #+#             */
/*   Updated: 2024/04/23 14:33:00 by jerperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

#include "Intern.h"
#include <string>
#include <stdexcept>
#include <exception>
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
class Intern;
typedef	AForm* (Intern::*t_newform)(const std::string&) const;

class Intern
{
	private:
		t_newform	_fun[I_NFORMS];
		std::string	_fun_label[I_NFORMS];
		t_newform	findFun(const std::string&) const;
		AForm*		newRobotomyRequestForm(const std::string&) const;
		AForm*		newShrubberyCreationForm(const std::string&) const;
		AForm*		newPresidentialPardonForm(const std::string&) const;
		class UnknownFormException : public std::exception
		{
			public:
				virtual const char* what(void) const throw();
		};
	public:
		Intern(void);
		Intern(const Intern& other);
		~Intern(void) {};

		Intern&	operator=(const Intern&);
		AForm*	makeForm(const std::string&, const std::string&) const;
};

#endif
