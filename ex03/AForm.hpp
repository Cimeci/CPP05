/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inowak-- <inowak--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 13:36:24 by inowak--          #+#    #+#             */
/*   Updated: 2025/04/08 16:08:33 by inowak--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "colors.hpp"
#include <iostream>

class Bureaucrat;

class AForm{

	protected:
		const std::string name;
		bool indicator;
		const int gradeToSign;
		const int gradeToExecute;
	
	public:
		AForm();
		AForm(const std::string &name, const int gradeToSign, const int gradeToExecute);
		virtual ~AForm(); // abstract class

		class GradeTooHighException : public std::exception {
			public:
				const char* what() const throw();
			};
		
		class GradeTooLowException : public std::exception {
			public:
				const char* what() const throw();
			};
		class AlreadySigned : public std::exception {
			public:
				const char* what() const throw();
			};

		std::string getName(void) const;
		bool getIndicator(void) const;
		int getGradeToSign(void) const;
		int getGradeToExecute(void) const;

		virtual void beSigned(const Bureaucrat &b);
		virtual void execute(Bureaucrat const & executor) const = 0; // abstract class
};
std::ostream& operator<<(std::ostream& os, const AForm& b);