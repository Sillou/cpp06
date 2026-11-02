#include "Serializer.hpp"
#include <iostream>

int	main(void)
{
	Data	data;

	data.id = 42;
	data.name = "Marvin";

	uintptr_t	raw = Serializer::serialize(&data);
	Data		*ptr = Serializer::deserialize(raw);

	std::cout << "Original address : " << &data << std::endl;
	std::cout << "Serialized (raw) : " << raw << std::endl;
	std::cout << "Deserialized ptr : " << ptr << std::endl;

	if (ptr == &data)
		std::cout << "OK : ptr == &data" << std::endl;
	else
		std::cout << "KO : ptr != &data" << std::endl;

	std::cout << "ptr->id   : " << ptr->id << std::endl;
	std::cout << "ptr->name : " << ptr->name << std::endl;
	return (0);
}
