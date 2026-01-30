
#include "BitcoinExchange.hpp"


int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Error: wrong number arguments !" << std::endl;
		return 1;
	}

	try {
		BitcoinExchange exchange("data.csv");
		exchange.processInputFile(argv[1]);
	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
		return 1;
	}

	return 0;
}