/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inowak-- <inowak--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 11:30:15 by inowak--          #+#    #+#             */
/*   Updated: 2025/04/08 16:44:23 by inowak--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "PresidentialPardonForm.hpp"
# include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm():AForm("PresidentialPardonForm", 25, 5), target("default"){}
PresidentialPardonForm::PresidentialPardonForm(const std::string target):AForm("PresidentialPardonForm", 25, 5), target(target){}
PresidentialPardonForm::~PresidentialPardonForm(){}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const{
	if(indicator == true && executor.getGrade() <= gradeToExecute)
		std::cout << target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
	else
		throw GradeTooLowException();
}

std::string PresidentialPardonForm::getTarget() const {return target;}

std::ostream& operator<<(std::ostream& os, const PresidentialPardonForm& b){
	os << RED << "PresidentialPardonForm" << RESET << " have target: " << b.getTarget() << YELLOW <<", gradeToSign: 25 and gradeToExecute: 5 ." << RESET;
	return os;
}