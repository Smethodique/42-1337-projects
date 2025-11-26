#ifndef _EASYFIND_TPP_
#define _EASYFIND_TPP_

#include "easyfind.hpp"

const char *	NoValueException::what() const throw() {
	return "No occurrence found in the container.";
}

template<typename T>
int	easyfind(T const & array, int val) {
	typename T::const_iterator	it;
	typename T::const_iterator	ite = array.end();

	for (it = array.begin(); it != ite; ++it) {
		if (*it == val)
			return *it;
	}
	throw NoValueException();
}

#endif