/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inowak-- <inowak--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 10:28:01 by inowak--          #+#    #+#             */
/*   Updated: 2025/04/08 15:30:21 by inowak--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Bureaucrat.hpp"
# include "colors.hpp"
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"

int main(int argc, char **argv){
	
	int grade;
	if (argc == 1)
		grade = 100;
	else
		grade = atoi(argv[1]);
	Bureaucrat bureaucrat("Mallory", grade);
	std::cout << bureaucrat << std::endl;
	
	ShrubberyCreationForm Sform("creation");
	try{std::cout << Sform << std::endl;Sform.beSigned(bureaucrat);}
	catch (ShrubberyCreationForm::GradeTooLowException &e){std::cout << BOLD << bureaucrat.getName() << RESET << " couldn't sign " << Sform.getName() << " because " << BLUE_BOLD << bureaucrat.getGrade() << " > " << "145" << "." << std::endl << RESET;}
	catch (ShrubberyCreationForm::AlreadySigned &e){std::cout << BOLD << bureaucrat.getName() << RESET << " has already signed " << Sform.getName() << "." << std::endl;}	
	try{Sform.execute(bureaucrat);}
	catch (ShrubberyCreationForm::GradeTooLowException &e){std::cout << BOLD << bureaucrat.getName() << RESET << " couldn't sign " << Sform.getName() << " because " << BLUE_BOLD << bureaucrat.getGrade() << " > " << "137" << "." << std::endl << RESET;}

	RobotomyRequestForm Rform("robot");
	try{std::cout << Rform << std::endl;Rform.beSigned(bureaucrat);}
	catch (RobotomyRequestForm::GradeTooLowException &e){std::cout << BOLD << bureaucrat.getName() << RESET << " couldn't sign " << Rform.getName() << " because " << BLUE_BOLD << bureaucrat.getGrade() << " > " << "72" << "." << std::endl << RESET;}
	catch (RobotomyRequestForm::AlreadySigned &e){std::cout << BOLD << bureaucrat.getName() << RESET << " has already signed " << Rform.getName() << "." << std::endl;}	
	try{Rform.execute(bureaucrat);}
	catch (RobotomyRequestForm::GradeTooLowException &e){std::cout << BOLD << bureaucrat.getName() << RESET << " couldn't sign " << Rform.getName() << " because " << BLUE_BOLD << bureaucrat.getGrade() << " > " << "45" << "." << std::endl << RESET;}
	
	PresidentialPardonForm Pform("robot");
	try{std::cout << Pform << std::endl;Pform.beSigned(bureaucrat);}
	catch (PresidentialPardonForm::GradeTooLowException &e){std::cout << BOLD << bureaucrat.getName() << RESET << " couldn't sign " << Pform.getName() << " because " << BLUE_BOLD << bureaucrat.getGrade() << " > " << "25" << "." << std::endl << RESET;}
	catch (PresidentialPardonForm::AlreadySigned &e){std::cout << BOLD << bureaucrat.getName() << RESET << " has already signed " << Pform.getName() << "." << std::endl;}	
	try{Pform.execute(bureaucrat);}
	catch (PresidentialPardonForm::GradeTooLowException &e){std::cout << BOLD << bureaucrat.getName() << RESET << " couldn't sign " << Pform.getName() << " because " << BLUE_BOLD << bureaucrat.getGrade() << " > " << "5" << "." << std::endl << RESET;}
}	