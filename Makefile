SRC = ./src/main.c\
	./src/line_work.c\
	./src/check_for_command.c\
	./src/do_echo.c\
	./src/quotes.c\
	./src/do_cd.c\
	./src/do_pwd.c\
	./src/push_back.c\
	./src/push_front.c\
	./src/insert.c\
	./src/ft_dblcon_new.c\
	./src/ft_dblcon_del.c\
	./src/getnth.c\
	./src/check_export_end_environment_variable.c\
	./src/environment_variable.c\
	./src/export.c\
	./src/secondary_functions.c\
	./src/do_exec.c\
	./src/what_a_command.c\
	./src/do_pipe.c\
	./src/do_redir.c\

	
OBJ = $(SRC:.c=.o)
NAME = minishell
FLAG = clang -g -Wall -Wextra -Werror
LIBFT = ./libft/libft.a
RM = rm -f

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	$(FLAG) -o $(NAME) $(OBJ) $(LIBFT)

$(LIBFT):
	@$(MAKE) -C libft

clean:
	$(RM) $(OBJ)
	$(RM) ./libft/*.o

fclean: clean	
	$(RM) $(NAME) $(LIBFT)

re: fclean $(NAME)

.PHONY: all clean fclean re libft