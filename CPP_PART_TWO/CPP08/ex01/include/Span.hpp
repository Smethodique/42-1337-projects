#ifndef _SPAN_HPP_
#define _SPAN_HPP_

#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include <climits>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <unistd.h>

typedef std::string str;

class Span {
	public:
		Span();
		Span(unsigned int N);
		Span(Span const &src);
		~Span();

		Span &	operator=(Span const &rSym);

		void	addNumber(int n);
		void	bigAdd(int n);
		int		shortestSpan();
		int		longestSpan() const;

		class MaxNumbersException : public std::exception {
			public:
				virtual const char *	what() const throw();
		};
		class NoNumberException : public std::exception {
			public:
				virtual const char *	what() const throw();
		};
		class OneNumberException : public std::exception {
			public:
				virtual const char *	what() const throw();
		};
	private:
		std::vector<int>	_array;
		unsigned int		_maxSize;
		unsigned int		_size;

		std::vector<int>	_sort() const;
};

#endif