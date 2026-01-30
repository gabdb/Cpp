
#pragma once

#include <iostream>
#include <map>
#include <string>
#include <sstream>
#include <stdexcept>
#include <cstdlib>
#include <fstream>

class BitcoinExchange
{
	private:
		std::map<std::string, double> _rates;
		void loadDatabase(const std::string &databasePath);
		bool isValidDate(const std::string &date) const;
		bool parseValue(const std::string &str, double &value) const;
		double getRateForDate(const std::string &date) const;

		static std::string trim(const std::string &s);
		static bool quickSplit(const std::string &line, char delim, std::string &left, std::string &right);

	public:
		BitcoinExchange(const std::string &databasePath);
		BitcoinExchange(const BitcoinExchange &other);
		BitcoinExchange &operator=(const BitcoinExchange &other);
		~BitcoinExchange();

		void processInputFile(const std::string &inputPath) const;
};
