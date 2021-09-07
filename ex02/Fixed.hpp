//
// Created by Gregorio Velva on 8/29/21.
//

#ifndef FIXED_HPP
#define FIXED_HPP

#include <string>
#include <iostream>
#include <cmath>

#define CONS_MSG "Default constructor called\n"
#define COPY_MSG "Copy constructor called\n"
#define ASSIGN_MSG "Assignation operator called\n"
#define GRB_MSG "getRawBits member function called\n"
#define DES_MSG "Destructor called\n"

class Fixed
{
private:
	int					_value;
	static const int	_fb = 8;

public:
	Fixed();
	Fixed(const Fixed &num);
	explicit Fixed(int num);
	explicit Fixed(float f);
	Fixed & operator=(Fixed const &num);
	Fixed & operator>(Fixed &a);
	Fixed & operator<(Fixed &a);
	Fixed & operator>=(Fixed &a);
	Fixed & operator<=(Fixed &a);
	Fixed & operator++();
	Fixed operator++(int);
	Fixed operator--(int);
	Fixed & operator--();
	Fixed operator+(Fixed &a) const;
	Fixed operator-(Fixed &a) const;
	Fixed operator*(const Fixed &a) const;
	Fixed operator/(Fixed &a) const;
	bool operator==(Fixed &a) const;
	bool operator!=(Fixed &a) const;
	~Fixed();
	int		getRawBits( ) const;
	void	setRawBits( int raw);
	float	toFloat() const;
	int		toInt() const;
	static	Fixed & max(const Fixed &a, const Fixed &b);
	static	Fixed & min(const Fixed &a, const Fixed &b);
};

std::ostream & operator<<(std::ostream &stream, Fixed const &num);

#endif //FIXED_HPP
