/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inowak-- <inowak--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 10:43:00 by inowak--          #+#    #+#             */
/*   Updated: 2025/04/08 16:05:28 by inowak--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# pragma once

# include "AForm.hpp"
#include <fstream>

class PresidentialPardonForm: public AForm{

	private:
		const std::string target;

	public:
		PresidentialPardonForm();
		PresidentialPardonForm(const std::string target);
		~PresidentialPardonForm();

		void execute(Bureaucrat const & executor) const;

		std::string getTarget(void) const;
};
std::ostream& operator<<(std::ostream& os, const PresidentialPardonForm& b);
