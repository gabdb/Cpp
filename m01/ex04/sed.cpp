
#include "sed.hpp"

bool	check_args(int ac, char **av)
{
	std::string s1;
	std::string s2;

	if (ac != 4)
	{
		std::cout << "Wrong number of arguments !" << std::endl;
		return (false);
	}
	s1 = av[2];
	s2 = av[3];
	if (s1.empty() || s2.empty())
	{
		std::cerr << "empty string(s) !" << std::endl;
		return (false);
	}
	return (true);
}

void    replace_str(char **av, std::ifstream& infile, std::ofstream& outfile)
{
    std::string s1 = av[2];
    std::string s2 = av[3];
    std::string line;
    std::size_t cursor;

    int i = 0;
    while (std::getline(infile, line))
    {
        if (i > 0)
            outfile << std::endl;
        cursor = 0;
        while ((cursor = line.find(s1, cursor)) != std::string::npos)
        {
            line.erase(cursor, s1.size());
            line.insert(cursor, s2);
            cursor += s2.size();
        }
        outfile << line;
        i++;
    }
}
