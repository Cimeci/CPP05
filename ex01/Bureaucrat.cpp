/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inowak-- <inowak--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 10:58:42 by inowak--          #+#    #+#             */
/*   Updated: 2025/04/07 16:39:19 by inowak--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): name("default"), grade(150){}

Bureaucrat::Bureaucrat(const std::string& name, int grade): name(name){
	if (grade > 150)
		throw GradeTooLowException();
	else if (grade < 1)
		throw GradeTooHighException();
	this->grade = grade;
}
Bureaucrat::~Bureaucrat(){}

const char* Bureaucrat::GradeTooHighException::what() const throw() {return "GradeTooHighException";}

const char* Bureaucrat::GradeTooLowException::what() const throw() {return "GradeTooLowException";}

std::string Bureaucrat::getName(void) const{return (name);}
int Bureaucrat::getGrade(void) const{return (grade);}

void	Bureaucrat::incrementGrade(void) {
	if (grade > 1)grade--;
	else throw GradeTooHighException();
}
void	Bureaucrat::decrementGrade(void) {
	if (grade < 150)grade++;
	else throw GradeTooLowException();
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b) {
	os << GREEN << b.getName() << ", bureaucrat grade " << b.getGrade() << "." << RESET;
	return os;
}

void	Bureaucrat::signForm(Form &form) const{
	
	try{
		form.beSigned(*this);
    	std::cout << name << " signed " << form.getName() << std::endl;
	}
	catch (Form::GradeTooLowException &e){
		std::cout << name << " couldn't sign " << form.getName() << " because " << BLUE_BOLD << grade << " > " << form.getGradeToSign() << "." << std::endl << RESET;
	}
	
	bool tmp = form.getIndicator();
	form.beSigned(*this);
	if (tmp == false && form.getIndicator() == true)
    	std::cout << name << " signed " << form.getName() << std::endl;
	else if (tmp == true && form.getIndicator() == true)
		std::cout << name << " has already signed " << form.getName() << std::endl;
	else
   		std::cout << name << " couldn't sign " << form.getName() << " because " << BLUE_BOLD << grade << " > " << form.getGradeToSign() << "." << std::endl << RESET;	
}