/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alubrano <alubrano@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 16:27:43 by alubrano          #+#    #+#             */
/*   Updated: 2026/11/02 16:27:44 by alubrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Functions.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

int	main(void)
{
	std::srand(std::time(NULL));

	for (int i = 0; i < 5; i++)
	{
		Base	*p = generate();

		std::cout << "Test " << i + 1 << std::endl;
		std::cout << "  identify(Base *) : ";
		identify(p);
		std::cout << "  identify(Base &) : ";
		identify(*p);
		delete p;
	}
	return (0);
}
