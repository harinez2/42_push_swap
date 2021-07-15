#include "main.h"

void	rra(t_stack *s)
{
	int	tmp;
	int	i;

	tmp = s->a[0];
	i = 0;
	while (++i < s->a_cnt)
		s->a[i - 1] = s->a[i];
	s->a[s->a_cnt - 1] = tmp;
	if (s->dsp)
	{
		if (s->color)
			write(1, COL_BK_CYAN"rra"COL_BK_RESET"\n", 14);
		else
			write(1, "rra\n", 4);
	}
	if (s->dbg && s->dsp)
	{
		print_stack_col(s);
		s->op_cnt++;
	}
}

void	rrb(t_stack *s)
{
	int	tmp;
	int	i;

	tmp = s->b[0];
	i = 0;
	while (++i < s->b_cnt)
		s->b[i - 1] = s->b[i];
	s->b[s->b_cnt - 1] = tmp;
	if (s->dsp)
	{
		if (s->color)
			write(1, COL_BK_CYAN"rrb"COL_BK_RESET"\n", 14);
		else
			write(1, "rrb\n", 4);
	}
	if (s->dbg && s->dsp)
	{
		print_stack_col(s);
		s->op_cnt++;
	}
}

void	rrr(t_stack *s)
{
	int	dsp;

	dsp = s->dsp;
	s->dsp = DISP_OFF;
	rra(s);
	rrb(s);
	s->dsp = dsp;
	if (s->dsp)
	{
		if (s->color)
			write(1, COL_BK_CYAN"rrr"COL_BK_RESET"\n", 14);
		else
			write(1, "rrr\n", 4);
	}
	if (s->dbg)
	{
		print_stack_col(s);
		s->op_cnt++;
	}
}

void	rrotate(t_stack *s, int warr)
{
	if (warr == ARR_A)
		rra(s);
	else
		rrb(s);
}
