FLAGS:= -Wall -Werror -Wextra
CC:= cc

NAME:= push_swap

PATH_LIBFT:= libft
LIBFT:= libft.a

PATH_GNL:= libft/get_next_line
GNL:= get_next_line.a

PATH_PRINTF:= ft_printf
FT_PRINTF:= libftprintf.a

FILES_LIST:= check_efficiency/check_efficiency_no_save \
				check_efficiency/check_efficiency \
				lib_dll/ft_create_list \
				lib_dll/ft_create_node \
				lib_dll/ft_free_list \
				lib_dll/ft_list_size \
				lib_dll/ft_list_last \
				lib_dll/ft_list_addback \
				lib_dll/ft_list_addfront \
				lib_dll/ft_list_find_node \
				operations/op_rev_rotate \
				operations/op_rotate \
				operations/op_swap_and_push \
				sorting_fts/ft_three_numbers \
				sorting_fts/ft_five_numbers \
				sorting_fts/create_array \
				sorting_fts/circular_list \
				sorting_fts/circular_list_utils \
				sorting_fts/lis_utils \
				sorting_fts/push_b_to_a \
				sorting_fts/push_a_to_b \
				sorting_fts/sorting \
				push_swap_utils \
				find_functions \
				index_stack \
				initialize_stack \
				initialize_stack_utils \
				check_input \
				main \

FUNCTIONS:= $(patsubst %, %.c, $(FILES_LIST))

FUNCTIONS_OBJ:= $(FUNCTIONS:.c=.o)

all: $(NAME)

%.o: %.c 
	$(CC) -g $(FLAGS) -c $< -o $@
	
$(NAME): $(FUNCTIONS_OBJ)
	$(MAKE) -C $(PATH_LIBFT)
	$(MAKE) -C $(PATH_GNL)
	$(MAKE) -C $(PATH_PRINTF)
	$(CC) $(FLAGS) $(FUNCTIONS_OBJ) $(PATH_LIBFT)/$(LIBFT) $(PATH_GNL)/$(GNL) $(PATH_PRINTF)/$(FT_PRINTF) -o $(NAME)
	
valgrind: $(NAME)
	valgrind --track-origins=yes --leak-check=full ./$(NAME)

clean:
	$(MAKE) clean -C $(PATH_LIBFT)
	$(MAKE) clean -C $(PATH_GNL)
	$(MAKE) clean -C $(PATH_PRINTF)
	rm -f $(FUNCTIONS_OBJ)

fclean: clean
	$(MAKE) fclean -C $(PATH_LIBFT)
	$(MAKE) fclean -C $(PATH_GNL)
	$(MAKE) fclean -C $(PATH_PRINTF)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

.SILENT: