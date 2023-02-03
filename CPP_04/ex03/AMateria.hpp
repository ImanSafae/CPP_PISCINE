#pragma once AMATERIA_HPP
#include <iostream>

class	AMateria
{
public:
	AMateria( void );
	AMateria( std::string const &type );
	~AMateria( void );

	AMateria			&operator=( AMateria const &src );

	std::string const	&getType( void ) const;
	void				setType( std::string type );

	virtual AMateria	*clone( void ) const = 0;
	virtual void		use( ICharacter &target );

protected:
	std::string	type;
};


class	Ice : public AMateria
{
public:
	Ice( void );
	~Ice( void );

	Ice	&operator=( Ice const &src );

	virtual Ice		*clone( void ) const;
	virtual void	use( ICharacter &target );
};

class	Cure : public AMateria
{
public:
	Cure( void );
	~Cure( void );

	Cure	&operator=( Cure const &src );

	virtual Cure	*clone( void ) const;
	virtual void	use( ICharacter &target );
};
