#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << CONS_MSG;
	this->_value = 0;
}

Fixed::Fixed(const Fixed &num) : _value(num.getRawBits())
{
	std::cout << COPY_MSG;
	*this = num;
}

Fixed::Fixed(int num)
{
	this->_value = (num << Fixed::_fb);
}

Fixed::Fixed(float f)
{
	this->_value = (int)roundf(f * (1 << Fixed::_fb));
}

Fixed& Fixed::operator=(Fixed const& num)
{
	std::cout << ASSIGN_MSG;
	this->_value = num._value;
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << DES_MSG;
}

int	Fixed::getRawBits() const
{
	std::cout << GRB_MSG;
	return (this->_value);
}

void	Fixed::setRawBits(int const raw)
{
	this->_value = raw;
}

float	Fixed::toFloat() const
{
	return (((float)this->_value / (1 << Fixed::_fb)));
}

int		Fixed::toInt() const
{
	return (this->_value >> Fixed::_fb);
}

Fixed &Fixed::operator>( Fixed &a)
{
	if (this->getRawBits() > a.getRawBits())
		return (*this);
	return (a);
}

Fixed &Fixed::operator<( Fixed &a)
{
	if (this->getRawBits() > a.getRawBits())
		return (*this);
	return (a);
}

Fixed &Fixed::operator>=( Fixed &a)
{
	if (this->getRawBits() >= a.getRawBits())
		return (*this);
	return (a);
}

Fixed &Fixed::operator<=( Fixed &a)
{
	if (this->getRawBits() >= a.getRawBits())
		return (*this);
	return (a);
}

bool Fixed::operator==( Fixed &a) const
{
	if (this->getRawBits() == a.getRawBits())
		return (true);
	return (false);
}

bool Fixed::operator!=( Fixed &a) const
{
	if (this->getRawBits() != a.getRawBits())
		return (true);
	return (false);
}

Fixed Fixed::operator+(Fixed &a) const
{
	Fixed result;
	result.setRawBits(this->_value + a.getRawBits());
	return (result);
}

Fixed Fixed::operator-(Fixed &a) const
{
	Fixed result;
	result.setRawBits(this->_value - a.getRawBits());
	return (result);
}

Fixed Fixed::operator*(const Fixed &a) const
{
	Fixed result;
	result.setRawBits((this->_value * a.getRawBits()) >> Fixed::_fb);
	return (result);
}


Fixed Fixed::operator/(Fixed &a) const
{
	Fixed result;
	result.setRawBits(((this->_value << Fixed::_fb) / a.getRawBits()));
	return (result);
}

Fixed & Fixed::operator++()
{
	this->setRawBits(this->getRawBits() + 1);
	return (*this);
}

Fixed Fixed::operator++(int)
{
	const Fixed result(*this);
	this->setRawBits(this->getRawBits() + 1);
	return (result);
}

Fixed Fixed::operator--(int)
{
	const Fixed result(*this);
	this->setRawBits(this->getRawBits() - 1);
	return (result);
}

Fixed & Fixed::operator--()
{
	this->setRawBits(this->getRawBits() - 1);
	return (*this);
}

Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
	return const_cast<Fixed &>((a.getRawBits() > b.getRawBits()) ? a : b);
}

Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
	return const_cast<Fixed &>((a.getRawBits() < b.getRawBits()) ? a : b);
}

std::ostream &operator<<(std::ostream &stream, Fixed const &num)
{
	stream << num.toFloat();
	return (stream);
}
