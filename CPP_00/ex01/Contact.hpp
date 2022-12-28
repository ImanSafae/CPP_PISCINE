#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <stdlib.h>
# include <string.h>

# define FIRST_NAME 0
# define LAST_NAME 1
# define NICKNAME 2
# define PHONE 3
# define SECRET 4

class	Contact
{

public:
	Contact( void );
	~Contact( void );
	std::string	information[5];
	// std::string	first_name;
	// std::string	last_name;
	// std::string	nickname;
	// std::string	phone_number;
	// std::string	darkest_secret;
};

#endif