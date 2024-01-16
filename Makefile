NAME = push_swap
LIBFT_PATH = ./libft
LIBFT = $(LIBFT_PATH)/libft.a
PRINTF_PATH = ./printf
CFLAGS = -Wall -Wextra -Werror
DEBUGFLAGS = -g -fsanitize=address,undefined,integer
SRCS = swap_main.c push_cheapest.c sort_3_and_4.c stack_operations.c stack_operations_2.c input_check.c \
	helper_functions.c create_stack.c assign_targets_and_positions.c prices.c rot_functions.c rot_push_cheapest.c
BONUS_SRCS = checker_apply_bonus.c checker_main_bonus.c checker_stack_operations_2_bonus.c checker_stack_operations_bonus.c input_check.c helper_functions.c create_stack.c checker_stdin_bonus.c
PRINTF_SRCS = ./printf/ft_printf.c ./printf/ft_putchar.c ./printf/ft_putstr.c
OBJCTS = $(SRCS:.c=.o)
BONUS_OBJCTS = $(BONUS_SRCS:.c=.o)
PRINTF_OBJCTS = $(PRINTF_SRCS:.c=.o)
RM = rm -f

all: $(NAME)

$(NAME): $(LIBFT)
	cc $(CFLAGS) $(SRCS) $(PRINTF_SRCS) $(LIBFT) -o $(NAME)

$(LIBFT):
	make -C $(LIBFT_PATH)

bonus: .bonus

.bonus: $(LIBFT)
	cc $(CFLAGS) $(BONUS_SRCS) $(PRINTF_SRCS) $(LIBFT) -o checker
	touch .bonus

debug: $(LIBFT)
	cc $(DEBUGFLAGS) $(SRCS) $(PRINTF_SRCS) $(LIBFT) -o debug.out

%.o: %.c
	cc $(CFLAGS) -c $< -o $@

both: $(NAME) bonus

clean: 
	make clean -C $(LIBFT_PATH)
	$(RM) $(OBJCTS) $(BONUS_OBJCTS) $(PRINTF_OBJCTS)
	
fclean: clean
	make -C $(LIBFT_PATH) fclean
	$(RM) $(NAME) push_swap debug.out checker
	$(RM) .bonus

re: fclean all

.PHONY: all clean fclean re bonus
	
