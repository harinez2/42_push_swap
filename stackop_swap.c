#include "main.h"

void	sa(t_stack *s)
{
	int	tmp;

	if (s->a_cnt < 2)
		return ;
	tmp = s->a[s->a_cnt - 1];
	s->a[s->a_cnt - 1] = s->a[s->a_cnt - 2];
	s->a[s->a_cnt - 2] = tmp;
	if (s->dsp)
	{
		if (s->color)
			write(1, COL_BK_CYAN"sa"COL_BK_RESET"\n", 13);
		else
			write(1, "sa\n", 3);
	}
	if (s->dbg && s->dsp)
	{
		print_stack_col(s);
		s->op_cnt++;
	}
}

void	sb(t_stack *s)
{
	int	tmp;

	if (s->b_cnt < 2)
		return ;
	tmp = s->b[s->b_cnt - 1];
	s->b[s->b_cnt - 1] = s->b[s->b_cnt - 2];
	s->b[s->b_cnt - 2] = tmp;
	if (s->dsp)
	{
		if (s->color)
			write(1, COL_BK_CYAN"sb"COL_BK_RESET"\n", 13);
		else
			write(1, "sb\n", 3);
	}
	if (s->dbg && s->dsp)
	{
		print_stack_col(s);
		s->op_cnt++;
	}
}

void	ss(t_stack *s)
{
	int	dsp;

	dsp = s->dsp;
	s->dsp = DISP_OFF;
	sa(s);
	sb(s);
	s->dsp = dsp;
	if (s->dsp)
	{
		if (s->color)
			write(1, COL_BK_CYAN"ss"COL_BK_RESET"\n", 13);
		else
			write(1, "ss\n", 3);
	}
	if (s->dbg)
	{
		print_stack_col(s);
		s->op_cnt++;
	}
}

void	sara(t_stack *s)
{
	sa(s);
	ra(s);
}
