#ifndef _ITER_HPP_
#define _ITER_HPP_

#include <iostream>
#include <string>

typedef std::string str;

template<typename T>
void	iter(T *adress, int lenght, void (*fct)(T& var));

template<typename T>
void	printValue(T val);

#endif