#include "../include/Bureaucrat.hpp"
#include "../include/AForm.hpp"
#include "../include/PresidentialPardonForm.hpp"
#include "../include/ShrubberyCreationForm.hpp"
#include "../include/RobotomyRequestForm.hpp"

int	main() {
	Bureaucrat *	Donald = new Bureaucrat("Donald", 2);
	Bureaucrat *	Joe = new Bureaucrat("Joe", 10);
	Bureaucrat *	Miguel = new Bureaucrat("Miguel", 65);
	AForm *			shru = new ShrubberyCreationForm(*Joe);
	AForm *			robot = new RobotomyRequestForm(*Donald);

	try {
		robot->beSigned(*Miguel);
		shru->beSigned(*Joe);
		robot->execute(*Donald);
		shru->execute(*Donald);
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}

	std::cout << *shru << std::endl;
	std::cout << *robot << std::endl;

	delete robot;
	delete shru;
	delete Miguel;
	delete Joe;
	delete Donald;
}