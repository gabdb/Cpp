
#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN &other)
{
	(void)other;
}

RPN &RPN::operator=(const RPN &other)
{
  (void)other;
  return *this;
}

RPN::~RPN() {}

void applyOperator(std::stack<int> &st, char op)
{
	if (st.size() < 2)
	{
		throw std::runtime_error("Error");
	}
	int right = st.top();
	st.pop();
	int left = st.top();
	st.pop();

	int result;
	switch (op)
	{
		case '+':
			result = left + right;
			break;
		case '-':
			result = left - right;
			break;
		case '*':
			result = left * right;
			break;
		case '/':
			if (right == 0)
			{
				throw std::runtime_error("Error");
			}
			result = left / right;
			break;
		default:
			throw std::runtime_error("Error");
	}

	st.push(result);
}

int RPN::evaluate(const std::string &expression)
{
	std::stack<int> st;
	std::istringstream iss(expression);
	std::string tok;

	while (iss >> tok)
	{
		if (tok.size() == 1 && tok[0] >= '0' && tok[0] <= '9')
		{
			st.push(tok[0] - '0');
		}
		else if (tok.size() == 1 &&
					(tok[0] == '+' || tok[0] == '-' || tok[0] == '*' || tok[0] == '/'))
		{
			applyOperator(st, tok[0]);
		}
		else
		{
			throw std::runtime_error("Error");
		}
	}

	if (st.size() != 1)
		throw std::runtime_error("Error");

	return st.top();
}
