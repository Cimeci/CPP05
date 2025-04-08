/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inowak-- <inowak--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 11:30:15 by inowak--          #+#    #+#             */
/*   Updated: 2025/04/08 15:11:47 by inowak--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "RobotomyRequestForm.hpp"
# include "Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm():AForm("RobotomyRequestForm", 72, 45), target("default"){}
RobotomyRequestForm::RobotomyRequestForm(std::string target):AForm("RobotomyRequestForm", 72, 45), target(target){}
RobotomyRequestForm::~RobotomyRequestForm(){}

void RobotomyRequestForm::beSigned(const Bureaucrat &b){
	if (b.getGrade() <= gradeToSign)
	{
		if (indicator == true)
			throw AlreadySigned();
		indicator = true;
	}
	else
		throw GradeTooLowException();
}

void RobotomyRequestForm::execute(Bureaucrat const & executor){
	if(indicator == true && executor.getGrade() < gradeToExecute)
	{
		std::cout << "Drilling noises..." << std :: endl;
		std::srand(std::time(0));
		int r = std::rand() % 2;
		if (r == 0)
			std::cout << "Robotomy failed!" << std::endl;
   		else
			std::cout << "Robotomy succeeded!" << std::endl;
	}
	else
		throw GradeTooLowException();
}

std::string RobotomyRequestForm::getTarget() const {return target;}

std::ostream& operator<<(std::ostream& os, const RobotomyRequestForm& b){
	os << YELLOW << "RobotomyRequestForm have " << RESET << b.getTarget() << YELLOW <<", gradeToSign: 72 and gradeToExecute: 45 ." << RESET;
	return os;
}
