/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerperez <jerperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 16:02:28 by jerperez          #+#    #+#             */
/*   Updated: 2024/04/20 17:26:26 by jerperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTForm_HPP
# define ROBOTOMYREQUESTForm_HPP

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
			AForm(FR_NAME, FR_SIGN, FR_EXEC), _target(FR_TARGET) {};
		RobotomyRequestForm(std::string target) :
			AForm(FR_NAME, FR_SIGN, FR_EXEC), _target(target) {};
		RobotomyRequestForm(const RobotomyRequestForm& other) :
			AForm(FR_NAME, FR_SIGN, FR_EXEC), _target(other._target) {};
		~RobotomyRequestForm(void) {};

		RobotomyRequestForm&	operator=(const RobotomyRequestForm&);
		const std::string&		getTarget(void) const;

		void					execute(Bureaucrat const &) const;
};

#endif