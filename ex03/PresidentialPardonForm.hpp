/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerperez <jerperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 15:19:00 by jerperez          #+#    #+#             */
/*   Updated: 2024/04/23 14:52:25 by jerperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONForm_HPP
# define PRESIDENTIALPARDONForm_HPP

#include "AForm.hpp"
#include "AForm.h"
#include "PresidentialPardonForm.h"
class Bureaucrat;

class PresidentialPardonForm: public AForm
{
	private:
		std::string	_target;
	public:
		PresidentialPardonForm(void) :
			AForm(FP_NAME, FP_SIGN, FP_EXEC), _target(FP_TARGET) {};
		PresidentialPardonForm(std::string target) :
			AForm(FP_NAME, FP_SIGN, FP_EXEC), _target(target) {};
		PresidentialPardonForm(const PresidentialPardonForm& other) :
			AForm(FP_NAME, FP_SIGN, FP_EXEC), _target(other._target) {};
		virtual ~PresidentialPardonForm(void) {};

		PresidentialPardonForm&	operator=(const PresidentialPardonForm&);
		const std::string&		getTarget(void) const;

		void					execute(Bureaucrat const &) const;
};

#endif