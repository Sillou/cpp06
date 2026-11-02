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
