#include "main.h"

void	pa(t_stack *s)
{
	if (s->b_cnt < 1)
		return ;
	s->a[s->a_cnt] = s->b[s->b_cnt - 1];
	s->a_cnt++;
	s->b_cnt--;
	if (s->dsp)
	{
		if (s->color)
			write(1, COL_BK_CYAN"pa"COL_BK_RESET"\n", 13);
		else
			write(1, "pa\n", 3);
	}
	if (s->dbg)
	{
		print_stack_col(s);
		s->op_cnt++;
	}
}

void	pb(t_stack *s)
{
	if (s->a_cnt < 1)
		return ;
	s->b[s->b_cnt] = s->a[s->a_cnt - 1];
	s->b_cnt++;
	s->a_cnt--;
	if (s->dsp)
	{
		if (s->color)
			write(1, COL_BK_CYAN"pb"COL_BK_RESET"\n", 13);
		else
			write(1, "pb\n", 3);
	}
	if (s->dbg)
	{
		print_stack_col(s);
		s->op_cnt++;
	}
}

void	push(t_stack *s, int warr)
{
	if (warr == ARR_A)
		pa(s);
	else
		pb(s);
}

void	pushr(t_stack *s, int warr)
{
	if (warr == ARR_A)
		pb(s);
	else
		pa(s);
}

void	para(t_stack *s)
{
	pa(s);
	ra(s);
}
