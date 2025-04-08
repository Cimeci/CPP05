/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inowak-- <inowak--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 10:43:00 by inowak--          #+#    #+#             */
/*   Updated: 2025/04/08 16:04:19 by inowak--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# pragma once

# include "AForm.hpp"
#include <cstdlib>
#include <ctime>

class RobotomyRequestForm: public AForm{

	private:
		const std::string target;

	public:
		RobotomyRequestForm();
		RobotomyRequestForm(const std::string target);
		~RobotomyRequestForm();

		void execute(Bureaucrat const & executor) const;
		
		std::string getTarget(void) const;
};
std::ostream& operator<<(std::ostream& os, const RobotomyRequestForm& b);