SRC_DIR = ./srcs/

LIBFT_DIR = ./libft/

SRC_FILES = main.c built_ins.c ft_strcmp.c

# add predfix to all the src files    prefix = ./srcs/
SRC_NAME =  $(addprefix $(SRC_DIR), $(SRC_FILES))

CFLAG = -Wall -Wextra -Werror

LIBFT_LIB = libft.a

TARGET = minishell

all: ${LIBFT_LIB}  
	@gcc $(SRC_NAME) $(LIBFT_DIR)${LIBFT_LIB} -lreadline -o $(TARGET)

# ${LIBFT_LIB} ---> This will run the makefile inside the libft directory and create libft.a and copy it to the libs folder
${LIBFT_LIB}:
	@$(MAKE) -C $(LIBFT_DIR) all 

clean:
	@$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@rm -rf $(TARGET)

re: fclean all


.PHONY: all clean fclean re