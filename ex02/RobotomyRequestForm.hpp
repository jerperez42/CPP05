/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerperez <jerperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 16:02:28 by jerperez          #+#    #+#             */
/*   Updated: 2024/04/20 16:11:39 by jerperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFROM_HPP
# define ROBOTOMYREQUESTFROM_HPP

#include "AForm.hpp"
#include "AForm.h"
#include "RobotomyRequestForm.h"
class Bureaucrat;

class RobotomyRequestForm: public AForm
{
	private:
		std::string	_target;
	public:
		RobotomyRequestForm(void) :
			AForm(F_NAME, F_SIGN, F_EXEC), _target(F_TARGET) {};
		RobotomyRequestForm(std::string target) :
			AForm(F_NAME, F_SIGN, F_EXEC), _target(target) {};
		RobotomyRequestForm(const RobotomyRequestForm& other) :
			AForm(F_NAME, F_SIGN, F_EXEC), _target(other._target) {};
		~RobotomyRequestForm(void) {};

		RobotomyRequestForm&	operator=(const RobotomyRequestForm&);
		const std::string&		getTarget(void) const;

		void					execute(Bureaucrat const &);
};

#endif