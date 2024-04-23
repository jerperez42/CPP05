/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerperez <jerperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 16:10:23 by jerperez          #+#    #+#             */
/*   Updated: 2024/04/23 14:52:37 by jerperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include "AForm.h"
#include "ShrubberyCreationForm.h"
class Bureaucrat;

class ShrubberyCreationForm: public AForm
{
	private:
		std::string	_target;
	public:
		ShrubberyCreationForm(void) :
			AForm(FS_NAME, FS_SIGN, FS_EXEC), _target(FS_TARGET) {};
		ShrubberyCreationForm(std::string target) :
			AForm(FS_NAME, FS_SIGN, FS_EXEC), _target(target) {};
		ShrubberyCreationForm(const ShrubberyCreationForm& other) :
			AForm(FS_NAME, FS_SIGN, FS_EXEC), _target(other._target) {};
		virtual ~ShrubberyCreationForm(void) {};

		ShrubberyCreationForm&	operator=(const ShrubberyCreationForm&);
		const std::string&		getTarget(void) const;

		void					execute(Bureaucrat const &) const;
};

#endif
