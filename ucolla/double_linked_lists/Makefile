FLAGS:= -Wall -Werror -Wextra
CC:= cc

NAME:= push_swap

PATH_LIBFT:= ../libft
LIBFT:= libft.a

#PATH_GNL:= libft/get_next_line
#GNL:= get_next_line.a

PATH_PRINTF:= ../ft_printf
FT_PRINTF:= libftprintf.a

FUNCTIONS_LIST:= lib_dll/ft_create_list \
				lib_dll/ft_create_node \
				lib_dll/ft_free_list \
				lib_dll/ft_list_size \
				lib_dll/ft_list_last \
				lib_dll/ft_list_addback \
				lib_dll/ft_list_addfront \
				lib_dll/ft_list_find_node \
				op_push \
				op_rev_rotate \
				op_rotate \
				op_swap \
				push_swap_utils \
				index_stack \
				ft_sort_three \
				main \

FUNCTIONS:= $(patsubst %, %.c, $(FUNCTIONS_LIST))

FUNCTIONS_OBJ:= $(FUNCTIONS:.c=.o)

all: $(NAME)

%.o: %.c 
	$(CC) -g $(FLAGS) -c $< -o $@
	
$(NAME): $(FUNCTIONS_OBJ)
	$(MAKE) -C $(PATH_LIBFT)
	$(MAKE) -C $(PATH_PRINTF)
	$(CC) $(FLAGS) $(FUNCTIONS_OBJ) $(PATH_LIBFT)/$(LIBFT) $(PATH_PRINTF)/$(FT_PRINTF) -o $(NAME)
	
clean:
	$(MAKE) clean -C $(PATH_LIBFT)
	$(MAKE) clean -C $(PATH_PRINTF)
	rm -f $(FUNCTIONS_OBJ)

fclean: clean
	$(MAKE) fclean -C $(PATH_LIBFT)
	$(MAKE) fclean -C $(PATH_PRINTF)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

.SILENT: