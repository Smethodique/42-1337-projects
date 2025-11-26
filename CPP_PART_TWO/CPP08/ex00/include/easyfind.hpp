#ifndef _EASYFIND_HPP_
#define _EASYFIND_HPP_

#include <iostream>
#include <string>
#include <algorithm>
#include <list>
#include <stdexcept>

typedef std::string str;

class NoValueException : public std::exception {
	public:
		virtual const char *	what() const throw();
};

template<typename T>
int	easyfind(T const & array, int val);

#endif