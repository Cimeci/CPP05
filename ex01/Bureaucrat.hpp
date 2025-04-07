/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inowak-- <inowak--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 10:46:36 by inowak--          #+#    #+#             */
/*   Updated: 2025/04/07 16:10:22 by inowak--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "colors.hpp"
#include "Form.hpp"
#include <iostream>

class Bureaucrat{
	
	private:
		const std::string name;
		int grade;
		
	public:
		Bureaucrat();
		Bureaucrat(const std::string& name, int grade);
		~Bureaucrat();

		class GradeTooHighException : public std::exception {
			public:
				const char* what() const throw();
			};
		
		class GradeTooLowException : public std::exception {
			public:
				const char* what() const throw();
			};
		
		std::string getName(void) const;
		int getGrade(void) const;

		void	incrementGrade(void);
		void	decrementGrade(void);

		void	signForm(Form &form) const;
};
std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);