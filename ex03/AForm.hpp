/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerperez <jerperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 13:39:28 by jerperez          #+#    #+#             */
/*   Updated: 2024/04/20 17:16:07 by jerperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include <string>
#include <exception>
#include "AForm.h"
#include "Bureaucrat.h"
class Bureaucrat;

class AForm
{
	private:
		const std::string	_name;
		const t_grade		_sign;
		const t_grade		_exec;
		bool				_signed;
		const t_grade		&checkGrade(const t_grade&) const;
	public:
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
		class NotSignedException : public std::exception
		{
			public:
				virtual const char* what(void) const throw();
		};
		AForm(void) :
			_name(F_NAME_DFLT),
			_sign(GRADE_RANK_LOW),
			_exec(GRADE_RANK_LOW),
			_signed(false) {};
		AForm(const std::string& name, t_grade req_sign, t_grade req_exec) :
			_name(name),
			_sign(checkGrade(req_sign)),
			_exec(checkGrade(req_exec)),
			_signed(false) {};
		AForm(const AForm& other) :
			_name(other._name),
			_sign(checkGrade(other._sign)),
			_exec(checkGrade(other._exec)),
			_signed(false) {};
		~AForm(void) {};
		AForm&	operator=(const AForm&);
		const std::string	&getName(void) const;
		const t_grade		&getSign(void) const;
		const t_grade		&getExec(void) const;
		const bool			&getSigned(void) const;
		void				beSigned(const Bureaucrat&);
		virtual void		execute(Bureaucrat const &) const;
};

std::ostream& operator<<(std::ostream&, const AForm&);

#endif
