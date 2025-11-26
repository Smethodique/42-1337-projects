#include "../include/easyfind.tpp"

int	main() {
	std::list<int>	lst;
	int				ret;
	bool			exception_caught = true;

	lst.push_back(5);
	lst.push_back(6);
	lst.push_back(32);
	lst.push_back(15);

	try {
		ret = easyfind(lst, 33);
		exception_caught = false;
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	
	if (!exception_caught)
		std::cout << "Value found : " << ret << "." << std::endl;

	return 0;
}