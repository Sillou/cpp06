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
