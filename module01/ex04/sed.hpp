#pragma once

#include <iostream>
#include <string>
#include <fstream>

bool	check_args(int ac, char **av);
void	replace_str(char **av, std::ifstream& infile, std::ofstream& outfile);