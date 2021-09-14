#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << CONS_MSG;
	this->_value = 0;
}

Fixed::Fixed(const Fixed &num)
{
	std::cout << COPY_MSG;
	*this = num;
}

Fixed::Fixed(int num)
{
	std::cout << INT_CONS_MSG;
	this->_value = (num << this->_fb);
}

Fixed::Fixed(float f)
{
	std::cout << FLT_CONS_MSG;
	this->_value = roundf(f * (1 << this->_fb));
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

float	Fixed::toFloat(void) const
{
	return (((float)this->_value / (1 << this->_fb)));
}

int		Fixed::toInt(void) const
{
	return (this->_value >> this->_fb);
}

std::ostream &operator<<(std::ostream &stream, Fixed const &num)
{
	stream << num.toFloat();
	return (stream);
}
