
#include "Array.hpp"

int main()
{
	try
	{
		std::cout << "Basic int array test: " << std::endl;
		Array<int> a(5);
		for (unsigned int i = 0; i < a.size(); i++)
			a[i] = i * 10;

		for (unsigned int i = 0; i < a.size(); i++)
			std::cout << "a[" << i << "] = " << a[i] << std::endl;

		std::cout << "\nCopy constructor test: " << std::endl;
		Array<int> b(a);
		b[0] = 999;
		std::cout << "b[0] = " << b[0] << " | a[0] = " << a[0] << std::endl;
		for (unsigned int i = 1; i < b.size(); i++)
			std::cout << "b[" << i << "] = " << b[i] << std::endl;

		std::cout << "\nAssignment operator test:" << std::endl;
		Array<int> c;
		c = a;
		c[1] = 555;
		std::cout << "c[1] = " << c[1] << " | a[1] = " << a[1] << std::endl;
		for (unsigned int i = 0; i < c.size(); i++)
			std::cout << "c[" << i << "] = " << c[i] << std::endl;

		std::cout << "\nConst access test:" << std::endl;
		const Array<int> d(a);
		for (unsigned int i = 0; i < d.size(); i++)
			std::cout << "d[" << i << "] = " << d[i] << std::endl;
		//d[0] = 42; // ne compilera pas

		std::cout << "\nException test:" << std::endl;
		std::cout << a[10] << std::endl; // out of bounds
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	std::cout << "\nString array test:" << std::endl;
	Array<std::string> s(3);
    try {
		s[0] = "Hello";
		s[1] = "42";
		s[2] = "jsp";
		for (unsigned int i = 0; i < s.size(); i++)
			std::cout << "s[" << i << "] = " << s[i] << std::endl;
    } catch (std::exception& e) { std::cerr << "Exception caught: " << e.what() << std::endl; }


	return 0;
}
