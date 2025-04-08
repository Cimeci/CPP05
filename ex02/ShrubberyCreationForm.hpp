/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inowak-- <inowak--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 10:43:00 by inowak--          #+#    #+#             */
/*   Updated: 2025/04/08 16:04:40 by inowak--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# pragma once

# include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm: public AForm{

	private:
		const std::string target;

	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(const std::string target);
		~ShrubberyCreationForm();

		void execute(Bureaucrat const & executor) const;

		std::string getTarget(void) const;
};
std::ostream& operator<<(std::ostream& os, const ShrubberyCreationForm& b);
