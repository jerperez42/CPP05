/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerperez <jerperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 15:19:00 by jerperez          #+#    #+#             */
/*   Updated: 2024/04/20 16:11:45 by jerperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFROM_HPP
# define PRESIDENTIALPARDONFROM_HPP

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
			AForm(F_NAME, F_SIGN, F_EXEC), _target(F_TARGET) {};
		PresidentialPardonForm(std::string target) :
			AForm(F_NAME, F_SIGN, F_EXEC), _target(target) {};
		PresidentialPardonForm(const PresidentialPardonForm& other) :
			AForm(F_NAME, F_SIGN, F_EXEC), _target(other._target) {};
		~PresidentialPardonForm(void) {};

		PresidentialPardonForm&	operator=(const PresidentialPardonForm&);
		const std::string&		getTarget(void) const;

		void					execute(Bureaucrat const &);
};

#endif