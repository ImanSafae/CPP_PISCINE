#include "Animals.hpp"
#include "WrongAnimal.hpp"

// ANIMAL TESTS

int main()
{
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;

    i->makeSound(); //will output the cat sound!
    j->makeSound();
    meta->makeSound();


	delete j;
	delete i;
    return 0;
}

// WRONG ANIMAL TESTS

int main()
{
    const WrongAnimal* meta = new WrongAnimal();
    const WrongAnimal* i = new WrongCat();

    std::cout << i->getType() << " " << std::endl;

    i->makeSound(); //will output the wrong animal sound!
    meta->makeSound();

	std::cout << i->getType() << std::endl;
    return 0;
}
