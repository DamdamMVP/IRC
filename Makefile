NAME		= ircserv

CXX			= c++
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98 -g -I $(INCDIR)

SRCDIR		= src
INCDIR		= inc
OBJDIR		= obj

SRC			= main Server Client
SRCS		= $(addprefix $(SRCDIR)/, $(addsuffix .cpp, $(SRC)))
OBJS		= $(addprefix $(OBJDIR)/, $(SRC:=.o))

all: $(NAME)

$(NAME): $(OBJS)
	@$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

$(OBJDIR):
	@mkdir -p $(OBJDIR)

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp | $(OBJDIR)
	@$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJDIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re