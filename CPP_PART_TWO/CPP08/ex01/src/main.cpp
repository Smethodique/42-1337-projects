#include "../include/Span.hpp"

int main() {
	Span	array(100);

	srand(time(NULL));
	try {
		// array.bigAdd(99);
		array.addNumber(10);
		array.addNumber(5);
		array.addNumber(14);
		array.addNumber(3);
		array.addNumber(7);
	}
	catch(const std::exception & e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << array.longestSpan() << std::endl;
	std::cout << array.shortestSpan() << std::endl;

	return 0;
}