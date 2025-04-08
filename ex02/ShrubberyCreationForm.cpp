/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inowak-- <inowak--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 10:52:30 by inowak--          #+#    #+#             */
/*   Updated: 2025/04/08 16:17:30 by inowak--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ShrubberyCreationForm.hpp"
# include "Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm():AForm("ShrubberyCreationForm", 145, 137), target("default"){}
ShrubberyCreationForm::ShrubberyCreationForm(const std::string target):AForm("ShrubberyCreationForm", 145, 137), target(target){}
ShrubberyCreationForm::~ShrubberyCreationForm(){}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const{
	if(indicator == true && executor.getGrade() <= gradeToExecute)
	{
		std::ofstream file;
		std::string filename = target + "_shrubbery";
		file.open(filename.c_str(), std::ios::out);
		if (!file.is_open()){
			std::cerr << "Error : open file !" << std::endl;
			return ;
		}
		file << "       ###" << std::endl;
		file << "      #o###" << std::endl;
		file << "    #####o###" << std::endl;
		file << "   #o#\\#|#/###" << std::endl;
		file << "    ###\\|/#o#" << std::endl;
		file << "     # }|{  #" << std::endl;
		file << "       }|{   " << std::endl;
		file.close();
	}
	else
		throw GradeTooLowException();
}

std::string ShrubberyCreationForm::getTarget() const {return target;}

std::ostream& operator<<(std::ostream& os, const ShrubberyCreationForm& b){
	os << RED << "ShrubberyCreationForm" << RESET << " have target: " << b.getTarget() << YELLOW << ", gradeToSign: 145 and gradeToExecute: 137 ." << RESET;
	return os;
}