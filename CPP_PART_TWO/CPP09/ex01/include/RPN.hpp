#ifndef _RPN_HPP_
#define _RPN_HPP_

#include <iostream>
#include <string>
#include <stack>
#include <cctype>
#include <cstdlib>
#include <stdexcept>

#define SIGN(c) ((c) == '*' || (c) == '/' || (c) == '+' || (c) == '-')

typedef std::string str;

class RPN {
	public:
		RPN();
		RPN(char *input);
		RPN(RPN const &src);
		~RPN();

		RPN &	operator=(RPN const &rSym);
	private:
		std::stack<int>	_stack;
};

#endif