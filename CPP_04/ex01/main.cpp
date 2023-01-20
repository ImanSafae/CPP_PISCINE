#include "Animals.hpp"
#include "WrongAnimals.hpp"
#include "Brain.hpp"

int main()
{
	Animal	*tab[10];

	for (int i = 0; i < 10; i++)
	{
		if (i % 2 == 0)
			tab[i] = new Cat;
		else
			tab[i] = new Dog;
	}
	std::cout <<std::endl;
	for (int i = 0; i < 10; i++)
	{
		delete tab[i];
		std::cout <<std::endl;
	}

	const Animal* j = new Dog();
	const Animal* i = new Cat();

	delete j; //should not create a leak
	delete i;

	// system("leaks Animals");
	return 0;
}
