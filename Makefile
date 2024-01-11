NAME = push_swap
LIBFT_PATH = ./libft
LIBFT = $(LIBFT_PATH)/libft.a
CFLAGS = -Wall -Wextra -Werror
DEBUGFLAGS = -g -fsanitize=address,undefined,integer
SRCS = swap_main.c push_cheapest.c sort_3_and_4.c stack_operations.c stack_operations_2.c input_check.c \
	helper_functions.c create_stack.c assign_targets_and_positions.c prices.c rot_functions.c rot_push_cheapest.c
BONUS_SRCS = checker_apply_bonus.c checker_main_bonus.c checker_stack_operations_2_bonus.c checker_stack_operations_bonus.c input_check.c helper_functions.c create_stack.c checker_stdin_bonus.c
PRINTF_SRCS = printf/ft_printf.c printf/ft_putchar.c printf/ft_putstr.c
OBJCTS = $(SRCS:.c=.o)
BONUS_OBJCTS = $(BONUS_SRCS:.c=.o)
PRINTF_OBJCTS = $(PRINTF_SRCS:.c=.o)
LIBCR = ar rc libft.a $(OBJCTS) $(PRINTF_OBJCTS)
RM = rm -f

#ccf checker_apply_bonus.c checker_main_bonus.c checker_stack_operations_2_bonus.c checker_stack_operations_bonus.c libft.a input_check.c helper_functions.c create_stack.c checker_stdin_bonus.c -o checker


all: $(NAME)

$(NAME):
	$(LIBFT)
	cc $(CFLAGS) $(SRCS) $(PRINTF_SRCS) libft.a -o push_swap

$(LIBFT):
	make -C $(LIBFT_PATH)

bonus: .bonus

.bonus: checker
	cc $(CFLAGS) $(BONUS_SRCS) -o checker
	touch .bonus

debug:
	cc $(DEBUGFLAGS) $(SRCS) libft.a  -o debug.out

%.o: %.c
	cc $(CFLAGS) -c $< -o $@

clean: 
	$(RM) $(OBJCTS) $(BONUS_OBJCTS) $(PRINTF_OBJCTS)
	$(RM) .bonus

fclean: clean
	make -C $(LIBFT_PATH) fclean
	$(RM) $(NAME) push_swap debug.out

re: fclean all
