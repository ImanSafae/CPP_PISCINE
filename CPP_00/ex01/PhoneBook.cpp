/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaouil <itaouil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 19:31:16 by itaouil           #+#    #+#             */
/*   Updated: 2022/12/04 15:22:44 by itaouil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"

// ************************************************************************** //
//                          Constructor & Destructor                          //
// ************************************************************************** //

PhoneBook::PhoneBook( void )
{
	this->_last_contact = 0;
	for (int i = 0; i < 8; i++)
	{
		this->_contacts_list[i].information[FIRST_NAME] = "";
		this->_contacts_list[i].information[LAST_NAME] = "";
		this->_contacts_list[i].information[NICKNAME] = "";
		this->_contacts_list[i].information[PHONE] = "";
		this->_contacts_list[i].information[SECRET] = "";
	}
	return ;
}

PhoneBook::~PhoneBook( void )
{
	return ;
}


// ************************************************************************** //
//                                 Accessors                                  //
// ************************************************************************** //

void	PhoneBook::display_contact( int index )
{
	std::cout << std::endl << "First name: " << this->_contacts_list[index].information[FIRST_NAME] << std::endl;
	std::cout << "Last name: " << this->_contacts_list[index].information[LAST_NAME] << std::endl;
	std::cout << "Nickname: " << this->_contacts_list[index].information[NICKNAME] << std::endl;
	std::cout << "Phone number: " << this->_contacts_list[index].information[PHONE] << std::endl;
	std::cout << "Darkest secret: " << this->_contacts_list[index].information[SECRET] << std::endl << std::endl;
}

void	PhoneBook::display_info( int index, int info )
{
	std::string		str = this->_contacts_list[index].information[info];

	if (this->_contacts_list[index].information[info].length() > 10)
	{
		str = this->_contacts_list[index].information[info].substr(0, 9);
		str.append(".");
	}
	else
		str = this->_contacts_list[index].information[info];
	std::cout << "|";
	std::cout << std::setfill(' ') << std::setw(10) << str;
}

void	PhoneBook::get_contacts( void )
{
	std::cout << std::endl;
	std::cout << "|" << std::setfill(' ') << std::setw(10) << "INDEX";
	std::cout << "|" << std::setfill(' ') << std::setw(10) << "FIRST NAME";
	std::cout << "|" << std::setfill(' ') << std::setw(10) << "LAST NAME";
	std::cout << "|" << std::setfill(' ') << std::setw(10) << "NICKNAME" << "|" << std::endl;
	for (int i = 0; i < 8; i++)
	{
		if (this->_contacts_list[i].information[FIRST_NAME] == "")
			break ;
		std::cout << "|";
		std::cout << std::setfill(' ') << std::setw(9) << "0" << i + 1;
		display_info(i, FIRST_NAME);
		display_info(i, LAST_NAME);
		display_info(i, NICKNAME);
		std::cout << "|" << std::endl;
	}
}

void	PhoneBook::_set_contact( int index, std::string first, std::string last, std::string nick, std::string phone, std::string secret )
{
	this->_contacts_list[index].information[FIRST_NAME] = first;
	this->_contacts_list[index].information[LAST_NAME] = last;
	this->_contacts_list[index].information[NICKNAME]= nick;
	this->_contacts_list[index].information[PHONE] = phone;
	this->_contacts_list[index].information[SECRET] = secret;
}


// ************************************************************************** //
//                                   Utils                                    //
// ************************************************************************** //

int	madeofdigits( std::string str )
{
	for (size_t i = 0; i < str.length(); i++)
	{
		if (!isdigit(str[i]))
			return (0);
	}
	return (1);
}

bool	check_for_eof( void )
{
	if (std::cin.eof())
	{
		std::cin.clear();
		clearerr(stdin);
		return (true);
	}
	return (false);
}

void	send_error( int error_type )
{
	if (error_type == EMPTY_REPERTORY)
	{
		std::cout << "No contacts yet.";
		std::cout << "Enter \"ADD\" to enter your first contact." << std::endl;
	}
	else if (error_type == EMPTY_INDEX)
		std::cout << "No contact at this index." << std::endl << std::endl;
	else if (error_type == WRONG_FORMAT)
	{
		std::cout << "Wrong format.";
		std::cout << "Please enter digit between 1 and 8 only." << std::endl;
	}
}


// ************************************************************************** //
//                                 Operations                                 //
// ************************************************************************** //

void	PhoneBook::search( void )
{
	std::string	desired_index;
	int			index;

	if (this->_contacts_list[0].information[0] == "")
	{
		send_error(EMPTY_REPERTORY);
		return ;
	}

	get_contacts();
	std::cout << std::endl << "Enter index of the contact you want to display.";
	std::cout << "Digit format only." << std::endl;

	std::getline(std::cin, desired_index);
	if (check_for_eof() == true)
		return ;
	if (!madeofdigits(desired_index) || atoi(desired_index.c_str()) < 1 || atoi(desired_index.c_str()) > 8)
	{
		send_error(WRONG_FORMAT);
		search();
		return ;
	}
	index = atoi(desired_index.c_str()) - 1;
	if (this->_contacts_list[index].information[FIRST_NAME] == "")
	{
		send_error(EMPTY_INDEX);
		return ;
	}
	display_contact(index);
}

void	PhoneBook::exit_PhoneBook( void )
{
	std::string	answer;

	std::cout << "All contacts will be lost forever. Are you sure ? [Y/N] ";
	std::getline(std::cin, answer);
	if (!answer.compare("Y") || !answer.compare("y"))
		exit(EXIT_FAILURE);
	else if (!answer.compare("N") || !answer.compare("n"))
		return ;
	else
		exit_PhoneBook();
}

bool	ask_user_for_info( std::string *my_str, int info_type )
{
	std::string	output;

	if (info_type == FIRST_NAME)
		output = "First name?";
	else if (info_type == LAST_NAME)
		output = "Last name?";
	else if (info_type == NICKNAME)
		output = "Nickname?";
	else if (info_type == SECRET)
		output = "Darkest secret?";
	else
	{
		output = "Phone number? Digits only.";
		while (!my_str->compare("") || !madeofdigits(*my_str))
		{
			std::cout << output << std::endl;
			std::getline(std::cin, *my_str);
			if (check_for_eof() == true)
				return (false);
		}
		return (true);
	}
	while (!my_str->compare(""))
	{
		std::cout << output << std::endl;
		std::getline(std::cin, *my_str);
		if (check_for_eof() == true)
			return (false);
	}
	return (true);
}

void PhoneBook::add( void )
{
	std::string	first_name = "";
	std::string	family_name = "";
	std::string	nickname = "";
	std::string	phone_number = "";
	std::string	darkest_secret = "";
	int			new_contact = 0;

	if (this->_last_contact == 8)
		this->_last_contact = 0;
	new_contact = this->_last_contact;

	if (ask_user_for_info(&first_name, FIRST_NAME) == false)
		return ;
	if (ask_user_for_info(&family_name, LAST_NAME) == false)
		return ;
	if (ask_user_for_info(&nickname, NICKNAME) == false)
		return ;
	if (ask_user_for_info(&phone_number, PHONE) == false)
		return ;
	if (ask_user_for_info(&darkest_secret, SECRET) == false)
		return ;

	this->_set_contact(new_contact, first_name, family_name, nickname, phone_number, darkest_secret);
	this->_last_contact++;
}
