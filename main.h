#ifndef MAIN_H
# define MAIN_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "gnl/get_next_line.h"

# define STACK_MAX	10000

# define DISP_ON	1
# define DISP_OFF	0

# define ARR_A		2
# define ARR_B		3

# define COL_BK_CYAN	"\x1b[46m"
# define COL_BK_RESET	"\x1b[49m"

# define COL_TX_MAZENTA	"\x1b[35m"
# define COL_TX_CYAN	"\x1b[36m"
# define COL_TX_RESET	"\x1b[39m"

typedef struct s_stack
{
	int	a[STACK_MAX];
	int	b[STACK_MAX];
	int	a_cnt;
	int	b_cnt;
	int	op_cnt;
	int	dsp;
	int	dbg;
	int	color;
}	t_stack;

void	sa(t_stack *s);
void	sb(t_stack *s);
void	ss(t_stack *s);
void	sara(t_stack *s);

void	pa(t_stack *s);
void	pb(t_stack *s);
void	push(t_stack *s, int warr);
void	pushr(t_stack *s, int warr);
void	para(t_stack *s);

void	ra(t_stack *s);
void	rb(t_stack *s);
void	rr(t_stack *s);
void	rotate(t_stack *s, int warr);
void	rara(t_stack *s);

void	rra(t_stack *s);
void	rrb(t_stack *s);
void	rrr(t_stack *s);
void	rrotate(t_stack *s, int warr);

void	init_stack(t_stack *s, int dsp, int dbg);
void	swap_arr(int *warr);
int		*get_arr(t_stack *s, int warr);
void	print_arr_name(int warr);
int		get_arrcnt(t_stack *s, int warr);

int		ft_atoi(char *s, int *errflg);
int		ft_strncmp(char *s1, char *s2, unsigned int n);
void	read_argv(t_stack *s, int argc, char **argv);

void	print_num(long d);
void	print_total(int d);
void	print_stack_col(t_stack *s);
void	print_stack_row(t_stack *s);

void	sort_3(t_stack *s);
void	sort_6(t_stack *s);

void	move_case_3(t_stack *s, int warr);
void	move_case_2(t_stack *s, int warr);
void	move_case_1(t_stack *s, int warr);

int		move_half_to_another(t_stack *s, int warr, int arrcnt);

#endif
