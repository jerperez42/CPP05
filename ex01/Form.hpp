/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerperez <jerperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 13:39:28 by jerperez          #+#    #+#             */
/*   Updated: 2024/04/20 15:02:48 by jerperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include <string>
#include <exception>
#include "Form.h"
#include "Bureaucrat.h"
class Bureaucrat;

class Form
{
	private:
		const std::string	_name;
		const t_grade		_req_sign;
		const t_grade		_req_exec;
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
		Form(void) :
			_name(F_NAME_DFLT),
			_req_sign(GRADE_RANK_LOW),
			_req_exec(GRADE_RANK_LOW),
			_signed(false) {};
		Form(const std::string& name, t_grade req_sign, t_grade req_exec) :
			_name(name),
			_req_sign(checkGrade(req_sign)),
			_req_exec(checkGrade(req_exec)),
			_signed(false) {};
		Form(const Form& other) :
			_name(other._name),
			_req_sign(checkGrade(other._req_sign)),
			_req_exec(checkGrade(other._req_exec)),
			_signed(false) {};
		~Form(void) {};
		Form&	operator=(const Form&);
		const std::string	&getName(void) const;
		const t_grade		&getReqSign(void) const;
		const t_grade		&getReqExec(void) const;
		const bool			&getSigned(void) const;
		void				beSigned(const Bureaucrat&);
};

std::ostream& operator<<(std::ostream&, const Form&);

#endif
