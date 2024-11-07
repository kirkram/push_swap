/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klukiano <klukiano@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 11:30:01 by klukiano          #+#    #+#             */
/*   Updated: 2024/01/12 11:43:57 by klukiano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include "printf/ft_printf.h"

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
