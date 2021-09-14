#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << CONS_MSG;
	this->_value = 0;
}

Fixed::Fixed(Fixed &num)
{
	std::cout << COPY_MSG;
	this->_value = num._value;
}

Fixed& Fixed::operator=(Fixed const& num)
{
	std::cout << ASSIGN_MSG;
	this->_value = num.getRawBits();
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << DES_MSG;
}

int	Fixed::getRawBits(void) const
{
	std::cout << GRB_MSG;
	return (this->_value);
}

void	Fixed::setRawBits(int const raw)
{
	this->_value = raw;
}

