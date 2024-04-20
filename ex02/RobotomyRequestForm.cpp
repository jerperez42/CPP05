/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerperez <jerperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 15:59:39 by jerperez          #+#    #+#             */
/*   Updated: 2024/04/20 16:07:58 by jerperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <iostream>

RobotomyRequestForm&	RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	this->_target = other._target;
}

const std::string&	RobotomyRequestForm::getTarget(void) const
{
	return (this->_target);
}

void	RobotomyRequestForm::execute(Bureaucrat const &executor)
{
	std::cout << "*Drilling noises*" << std::endl;
	if (rand() % 2)
		std::cerr << this->_target << "'s robotomy failed" << std::endl;
	else
		std::cout << this->_target << " has been robotomized." << std::endl;
}
