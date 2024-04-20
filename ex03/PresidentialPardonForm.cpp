/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerperez <jerperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 15:19:00 by jerperez          #+#    #+#             */
/*   Updated: 2024/04/20 17:20:38 by jerperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include <iostream>

PresidentialPardonForm&	PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
	this->_target = other._target;
	return (*this);
}

const std::string&	PresidentialPardonForm::getTarget(void) const
{
	return (this->_target);
}

void	PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	this->AForm::execute(executor);
	std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
