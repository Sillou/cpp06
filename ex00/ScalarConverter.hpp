/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alubrano <alubrano@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 16:26:59 by alubrano          #+#    #+#             */
/*   Updated: 2026/11/02 16:27:00 by alubrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP



#include <string>

class ScalarConverter
{
private:

	ScalarConverter( void );
	ScalarConverter(ScalarConverter const &src);
	ScalarConverter &operator=(ScalarConverter const &src);
	~ScalarConverter();

public:

	static void convert(const std::string &literal);


};


#endif
