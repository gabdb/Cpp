
#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(const std::string &databasePath)
{
	loadDatabase(databasePath);
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) : _rates(other._rates) {}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
	if (this != &other)
	{
		_rates = other._rates;
	}
	return *this;
}

BitcoinExchange::~BitcoinExchange() {}

//charger data_base.csv dans _rates
void BitcoinExchange::loadDatabase(const std::string &databasePath)
{
	std::ifstream file(databasePath.c_str());
	if (!file.is_open())
	{
		throw std::runtime_error("Error: could not open file.");
	}

	std::string line;
	if (!std::getline(file, line))
	{
		throw std::runtime_error("Error: empty database file.");
	}

	while (std::getline(file, line))
	{
		if (line.empty())
			continue;
		std::string date;
		std::string valueStr;

		if (!quickSplit(line, ',', date, valueStr) || !isValidDate(date))
			continue;

		char *endptr = NULL;
		double rate = std::strtod(valueStr.c_str(), &endptr);
		if (endptr == valueStr.c_str() || *endptr != '\0')
			continue;

		_rates[date] = rate;
	}

	if (_rates.empty())
	{
		throw std::runtime_error("Error: empty data_base.");
	}
}

bool BitcoinExchange::quickSplit(const std::string &line, char delim, std::string &left, std::string &right)
{
	std::string::size_type pos = line.find(delim);
	if (pos == std::string::npos)
		return false;
	left = trim(line.substr(0, pos));
	right = trim(line.substr(pos + 1));
	return true;
}

bool BitcoinExchange::isValidDate(const std::string &date) const
{
	if (date.size() != 10 || date[4] != '-' || date[7] != '-')
		return false;
	for (size_t i = 0; i < date.size(); ++i)
	{
		if (i == 4 || i == 7)
			continue;
		if (date[i] < '0' || date[i] > '9')
			return false;
	}

	int year = std::atoi(date.substr(0, 4).c_str());
	int month = std::atoi(date.substr(5, 2).c_str());
	int day = std::atoi(date.substr(8, 2).c_str());

	if (month < 1 || month > 12)
		return false;

	const int daysInMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int day_in_m = daysInMonth[month - 1];

	bool isLeap = (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
	if (month == 2 && isLeap)
		day_in_m = 29;

	if (day < 1 || day > day_in_m)
		return false;

	return true;
}

bool BitcoinExchange::parseValue(const std::string &str, double &value) const
{
	std::string s = trim(str);
	if (s.empty())
	return false;

	if (s[0] == '-')
	{
		std::cerr << "Error: not a positive number." << std::endl;
		return false;
	}

	char *endptr = NULL;
	value = std::strtod(s.c_str(), &endptr);
	if (endptr == s.c_str() || *endptr != '\0')
	{
		std::cerr << "Error: bad input => " << s << std::endl;
		return false;
	}

	if (value < 0.0)
	{
		std::cerr << "Error: not a positive number." << std::endl;
		return false;
	}

	if (value > 1000.0)
	{
		std::cerr << "Error: number too large." << std::endl;
		return false;
	}

	return true;
}

double BitcoinExchange::getRateForDate(const std::string &date) const
{
	std::map<std::string, double>::const_iterator it = _rates.lower_bound(date); //return 1e element dont key est >= date

	if (it == _rates.end()) //date demandee > max date file
		--it;

	else if (it->first != date)
	{
		if (it == _rates.begin())
		{
			throw std::runtime_error("Error: bad input");
		}
		--it;
	}

	return it->second;
}

void BitcoinExchange::processInputFile(const std::string &inputPath) const
{
	std::ifstream file(inputPath.c_str());
	if (!file.is_open())
	{
		std::cerr << "Error: could not open file." << std::endl;
		return;
	}

	std::string line;
	if (!std::getline(file, line)) //fichier argument vide
		return;

	while (std::getline(file, line))
	{
		if (line.empty())
			continue;

		std::string originalLine = line;
		std::string date, valueStr;
		if (!quickSplit(line, '|', date, valueStr) || !isValidDate(date)) {
			std::cerr << "Error: bad input => " << originalLine << std::endl;
			continue;
		}

		double value;
		if (!parseValue(valueStr, value))
		{
			continue;
		}

		try {
			double rate = getRateForDate(date);
			double result = rate * value;
			std::cout << date << " => " << value << " = " << result << std::endl;
		} catch (const std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
	}
}

std::string BitcoinExchange::trim(const std::string &s)
{
	std::string::size_type start = s.find_first_not_of(" \t");
	if (start == std::string::npos)
		return "";
	std::string::size_type end = s.find_last_not_of(" \t");
	return s.substr(start, end - start + 1);
}
