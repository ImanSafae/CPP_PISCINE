#include "Animals.hpp"
#include "WrongAnimals.hpp"
#include "Brain.hpp"

int main()
{
	const AAnimal*		j = new Dog();
	std::cout << std::endl;
	const AAnimal*		i = new Cat();
	std::cout << std::endl;

	delete j; //should not create a leak
	std::cout << std::endl;
	delete i;
	std::cout << std::endl;

	// system("leaks Animals");
	return 0;
}
