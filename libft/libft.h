/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klukiano <klukiano@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 12:31:10 by klukiano          #+#    #+#             */
/*   Updated: 2024/01/10 15:48:36 by klukiano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>
# include <limits.h>
# include "../printf/ft_printf.h"

int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
size_t	ft_strlen(const char *str);
void	*ft_memset(void *str, int c, size_t len);
void	ft_bzero(void *str, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
size_t	ft_strlcpy(char *dst, char *src, size_t dstsize);
size_t	ft_strlcat(char *dst, char *src, size_t dstsize);
int		ft_toupper(int c);
int		ft_tolower(int c);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_strchr(char *str, int c);
char	*ft_strrchr(char *str, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
char	*ft_strnstr(const char *h1, const char *ndl, size_t len);
int		ft_atoi(const char *str);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strdup(const char *s1);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	**ft_split(char const *str, char c);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

typedef struct s_list
{
	int				array_size;
	int				number;
	int				current_position;
	int				above_m;
	int				max;
	int				min;
	int				price;
	int				direction;
	void			*content;
	struct s_list	*next;
	struct s_list	*target;
}					t_list;

t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void*));
void	ft_lstclear(t_list **lst, void (*del)(void*));

void	sa(t_list **stack_a);
void	sb(t_list **stack_b);
void	ss(t_list **stack_a, t_list **stack_b);
void	pa(t_list **stack_a, t_list **stack_b);
void	pb(t_list **stack_a, t_list **stack_b);
void	ra(t_list **stack_a);
void	rb(t_list **stack_b);
void	rr(t_list **stack_a, t_list **stack_b);
void	rra(t_list **stack_a);
void	rrb(t_list **stack_b);
void	rrr(t_list **stack_a, t_list **stack_b);

int		check_input(int ac, char **av);
int		check_input_array(int *array, int ac, char **av);
int		check_input_character(char **av, int ac, int i, int j);
int		is_sorted(t_list *stack_a);
int		is_sorted_reverse(t_list *stack_a); //helper, delete
int		free_n_0(int **array, char **str_array);
t_list	*find_min(t_list *stack);
t_list	*find_max(t_list *stack);
int		input_two(int ac, char **str_array, int *int_array);
int		input_many(int ac, char **av, char **str_array, int *int_array);
void	a_several_args(int ac, char **av, t_list **stack_a_head);
void	a_two_args(t_list **stack_a_head, char **str_array);
void	rot_no_target(t_list **stack_a, t_list **stack_b, t_list *cheapest);
void	rot_notrgt_opp(t_list **a, t_list **b, t_list *cheapest, t_list *min_n);
void	rot_above_m(t_list **stack_a, t_list **stack_b, t_list *cheapest);
void	rot_below_m(t_list **stack_a, t_list **stack_b, t_list *cheapest);
void	rot_diff_pos_0(t_list **stack_a, t_list **stack_b, t_list *cheapest);
void	rot_diff_pos_1(t_list **stack_a, t_list **stack_b, t_list *cheapest);
void	rot_diff_pos_min1(t_list **stack_a, t_list **stack_b, t_list *cheapest);
void	final_rot(t_list **stack_a);
void	rot_b_to_top(t_list **stack_b);

void	p_swap(t_list **stack_a, t_list **stack_b);
void	p_swap_2(t_list **stack_a, t_list **stack_b);
t_list	*create_stack_a(int ac, char **av);
void	sort_3(t_list **stack_a);
void	sort_4(t_list **stack_a, t_list **stack_b);
void	price_a(t_list *stack_a, t_list *stack_b);
void	price_and_dir_up(t_list *ptr_a, t_list *target);
void	price_and_dir_down(t_list *ptr_a, t_list *target);
int		opposite_price(t_list *ptr_a, t_list *target);
void	push_cheapest(t_list **stack_a, t_list **stack_b);
t_list	*find_cheapest(t_list **stack_a);
void	assign_target_a(t_list *stack_a, t_list *stack_b);
void	find_positions_and_minmax(t_list *stack);
void	find_min_max(t_list *stack);
void	assign_target_b(t_list *stack_a, t_list *stack_b);


void	print_current_stack(t_list *stack_a, t_list *stack_b);

#endif
