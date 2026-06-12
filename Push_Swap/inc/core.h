/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-arau <ade-arau@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 17:42:49 by ade-arau          #+#    #+#             */
/*   Updated: 2026/06/12 12:41:32 by ade-arau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CORE_H
# define CORE_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdarg.h>

typedef enum e_op
{
	SA,
	SB,
	SS,
	PA,
	PB,
	RA,
	RB,
	RR,
	RRA,
	RRB,
	RRR,
}	t_op;

typedef struct s_plan
{
	int	ops[RRR + 1];
}	t_plan;

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
	struct s_stack	*target;
	t_plan			plan;
}					t_stack;

typedef enum e_strat
{
	INVALID,
	SIMPLE,
	MEDIUM,
	COMPLEX,
	ADAPTIVE
}	t_strat;

int		ft_atoi(const char *str);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		valid_num(char *str);
int		check_dups(t_stack *stack);
void	free_split(char **arg);
int		parse_argument(t_stack **stack, char *str);
int		is_sorted(t_stack *stack);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(const char *str);
size_t	subs_count(char const *s, char c);
int		fill(char **split, char const *s, char c);
char	**ft_split(char const *s, char c);
void	swap_stack(t_stack **stack);
void	push_stack(t_stack **src, t_stack **dst);
void	rotate_stack(t_stack **stack);
void	reverse_rotate_stack(t_stack **stack);
void	update_index(t_stack *stack);
int		printchar(int c);
int		printstr(char *str);
int		printint(int c);
int		printfloat(double c);
int		print(const char *content, ...);
int		parsing(t_stack **stack, char **argv);
void	lst_addback(t_stack **stack, int value);
void	free_stack(t_stack **stack);
int		lst_size(t_stack *stack);
int		ft_strlen(char *str);

#endif