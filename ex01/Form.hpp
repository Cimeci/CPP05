/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inowak-- <inowak--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 13:36:24 by inowak--          #+#    #+#             */
/*   Updated: 2025/04/08 10:36:20 by inowak--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "colors.hpp"
#include <iostream>

class Bureaucrat;

class Form{

	private:
		const std::string name;
		bool indicator;
		const int gradeToSign;
		const int gradeToExecute;
	
	public:
		Form();
		Form(const std::string &name, const int gradeToSign, const int gradeToExecute);
		~Form();

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

		void beSigned(const Bureaucrat &b);
};
std::ostream& operator<<(std::ostream& os, const Form& b);