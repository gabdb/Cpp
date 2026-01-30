
#pragma once

#include <string>
#include <iostream>
#include <stack>
#include <stdexcept>
#include <sstream>

class RPN
{
	public:
		RPN();
		RPN(const RPN &other);
		RPN &operator=(const RPN &other);
		~RPN();

		static int evaluate(const std::string &expression);
};