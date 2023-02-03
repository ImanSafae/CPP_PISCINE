#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <iomanip>
# include <stdlib.h>
# include <string.h>
# include "Contact.hpp"

# define WRONG_FORMAT 0
# define EMPTY_REPERTORY 1
# define EMPTY_INDEX 2

class	PhoneBook
{

public:
	PhoneBook( void );
	~PhoneBook( void );


	void	add( void );
	void	search( void );
	void	exit_PhoneBook( void );

	void	get_contacts( void );
	void	display_info( int index, int info_type );
	void	display_contact( int index );

private:
	Contact	_contacts_list[8];
	int		_last_contact;
	void	_set_contact( int index, std::string first, std::string last, std::string nick, std::string number, std::string secret );

};

#endif