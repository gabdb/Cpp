
NAME      = form

SRCS      = main.cpp Bureaucrat.cpp Form.cpp

OBJS      = $(SRCS:.cpp=.o)

CXX       = c++

CXXFLAGS  = -Wall -Wextra -Werror -std=c++98

RM        = rm -rf

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@

# Compile each .cpp → .o
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re