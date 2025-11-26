#include "../include/iter.hpp"

template<typename T>
void	iter(T *adress, int lenght, void (*fct)(T& var)) {
	for (int i = 0; i < lenght; i++)
		fct(adress[i]);
}

template<typename T>
void	printValue(T &val) {
	std::cout << val;
}

int	main() {
	char	array[] = {'a', 'b', 'c', 'd'};

	iter(array, 4, printValue<char>);
}