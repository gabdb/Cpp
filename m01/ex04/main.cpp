
#include "sed.hpp"

int main(int ac, char **av)
{
    if (!check_args(ac, av))
        return 1;

    std::ifstream infile(av[1]);
    std::ofstream outfile(std::string(av[1]) + ".replace");
    if (!infile.is_open() || !outfile.is_open())
    {
        std::cerr << "Failed to open file !" << std::endl;
        return 1;
    }
    replace_str(av, infile, outfile);
    infile.close();
    outfile.close();

    return 0;
}