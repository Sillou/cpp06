/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alubrano <alubrano@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 16:27:18 by alubrano          #+#    #+#             */
/*   Updated: 2026/11/02 16:27:19 by alubrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP


#include <string>
#include <stdint.h>
#include "Data.hpp"

class Serializer
{
private:
	Serializer( void );
	Serializer(Serializer const &src);
	Serializer &operator=(Serializer const &src);
	~Serializer();

public:
	static uintptr_t	serialize(Data *ptr);
	static Data	*deserialize(uintptr_t raw);


};

#endif
