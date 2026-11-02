#include "ScalarConverter.hpp"
#include <cctype>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <climits>
#include <cfloat>
#include <cmath>


ScalarConverter::ScalarConverter( void )
{
}

ScalarConverter::~ScalarConverter()
{
}

ScalarConverter::ScalarConverter(ScalarConverter const &src)
{
	(void)src;
}

ScalarConverter &ScalarConverter::operator=(ScalarConverter const &src)
{
	(void)src;
	return (*this);
}

static bool	isChar(const std::string &arg)
{
	if (arg.size() == 1 && !std::isdigit(arg[0]))
		return (true);
	else if (arg.size() == 3 && arg[0] == '\''&& arg[2] == '\'')
		return (true);
	else
		return (false);
}

static bool	isInt(const std::string &arg)
{
	size_t i = 0;
	if (arg[0] == '+' || arg[0] == '-')
		i = 1;
	if (arg.size() == i)
		return (false);
	while (i < arg.size())
	{
		if (!std::isdigit(arg[i]))
			return (false);
		i++;
	}
	return (true);
}

static bool isDouble(const std::string &arg)
{
	size_t i = 0;
	size_t compteur_point = 0;
	size_t compteur_chiffre = 0;

	if (arg[0] == '+' || arg[0] == '-')
		i = 1;
	while (i < arg.size())
	{
		if (arg[i] == '.')
			compteur_point++;
		else if (std::isdigit(arg[i]))
			compteur_chiffre++;
		else
			return (false);
		i++;
	}
	if (compteur_point == 1 && compteur_chiffre >= 1)
		return (true);
	else
		return (false);
}

static bool isFloat(const std::string &arg)
{
	if (arg.size() < 2 || arg[arg.size() - 1] != 'f')
		return (false);
	else
		return (isDouble(arg.substr(0, arg.size() - 1)));
}

static bool	isPseudoFloat(const std::string &arg)
{
	return (arg == "nanf" || arg == "+inff" || arg == "-inff");
}

static bool	isPseudoDouble(const std::string &arg)
{
	return (arg == "nan" || arg == "+inf" || arg == "-inf");
}

static void	fromChar(char c)
{
	int		i = static_cast<int>(c);
	float	f = static_cast<float>(c);
	double	d = static_cast<double>(c);

	if (c < 0)
		std::cout << "char: impossible" << std::endl;
	else if (!std::isprint(c))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << c << "'" << std::endl;
	std::cout << "int: " << i << std::endl;
	std::cout << std::fixed << std::setprecision(1);
	std::cout << "float: " << f << "f" << std::endl;
	std::cout << "double: " << d << std::endl;
}

static void	printChar(double v)
{
	if (v != v || v < 0 || v > 127)
		std::cout << "char: impossible" << std::endl;
	else if (!std::isprint(static_cast<int>(v)))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(v) << "'" << std::endl;
}

static void	printInt(double v)
{
	if (v != v || v < INT_MIN || v > INT_MAX)
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(v) << std::endl;
}

static void	printNumber(double v, int precision)
{
	if (v == std::floor(v))
		std::cout << std::fixed << std::setprecision(1) << v;
	else
	{
		std::cout.unsetf(std::ios::fixed);
		std::cout << std::setprecision(precision) << v;
	}
}

static void	fromDouble(const std::string &literal)
{
	double	d = std::strtod(literal.c_str(), NULL);

	printChar(d);
	printInt(d);
	if (d - d == 0 && (d > FLT_MAX || d < -FLT_MAX))
		std::cout << "float: impossible" << std::endl;
	else
	{
		std::cout << "float: ";
		printNumber(static_cast<float>(d), 7);
		std::cout << "f" << std::endl;
	}
	std::cout << "double: ";
	printNumber(d, 15);
	std::cout << std::endl;
}

static void	fromFloat(const std::string &literal)
{
	double	tmp = std::strtod(literal.c_str(), NULL);

	if (tmp - tmp == 0 && (tmp > FLT_MAX || tmp < -FLT_MAX))
	{
		fromDouble(literal);
		return;
	}
	float	f = static_cast<float>(tmp);

	printChar(f);
	printInt(f);
	std::cout << "float: ";
	printNumber(f, 7);
	std::cout << "f" << std::endl;
	std::cout << "double: ";
	printNumber(static_cast<double>(f), 7);
	std::cout << std::endl;
}

static void fromInt(const std::string &literal)
{
	long	l = std::strtol(literal.c_str(), NULL, 10);

	if (l < INT_MIN || l > INT_MAX)
	{
		fromDouble(literal);
		return;
	}
	int		i = static_cast<int>(l);
	float	f = static_cast<float>(i);
	double	d = static_cast<double>(i);

	if (i < 0 || i > 127)
		std::cout << "char: impossible" << std::endl;
	else if (!std::isprint(i))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(i) << "'" << std::endl;
	std::cout << "int: " << i << std::endl;
	std::cout << std::fixed << std::setprecision(1);
	std::cout << "float: " << f << "f" << std::endl;
	std::cout << "double: " << d << std::endl;
}


void ScalarConverter::convert(const std::string &literal)
{
	if (isPseudoFloat(literal))
		fromFloat(literal);
	else if (isPseudoDouble(literal))
		fromDouble(literal);
	else if (isChar(literal))
		fromChar(literal.size() == 1 ? literal[0] : literal[1]);
	else if (isInt(literal))
		fromInt(literal);
	else if (isFloat(literal))
		fromFloat(literal);
	else if (isDouble(literal))
		fromDouble(literal);
	else
		std::cout << "Error: invalid literal" << std::endl;
}

