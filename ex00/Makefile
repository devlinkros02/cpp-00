# Variables
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
SRC = $(shell find . -name "*.cpp")
OBJ = $(SRC:.cpp=.o)
TARGET = megaphone

# Rules
all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(TARGET)

re: fclean all

.PHONY: all clean fclean re