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
	Fixed(int num);
	Fixed(float f);
	Fixed & operator=(Fixed const &num);
	~Fixed();
	int		getRawBits( void) const;
	void	setRawBits( int const raw);
	float	toFloat(void) const;
	int	toInt(void) const;
};

std::ostream & operator<<(std::ostream &stream, Fixed const &num);

#endif //FIXED_HPP
