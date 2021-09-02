//
// Created by Gregorio Velva on 8/29/21.
//

#ifndef FIXED_HPP
#define FIXED_HPP

#include <string>
#include <iostream>

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
	Fixed(Fixed &num);
	Fixed & operator=(Fixed const &num);
	~Fixed();
	int		getRawBits( void) const;
	void	setRawBits( int const raw);
};

#endif //FIXED_HPP
