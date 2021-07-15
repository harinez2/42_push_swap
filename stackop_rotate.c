#include "main.h"

void	ra(t_stack *s)
{
	int	tmp;
	int	i;

	tmp = s->a[s->a_cnt - 1];
	i = s->a_cnt;
	while (--i > 0)
		s->a[i] = s->a[i - 1];
	s->a[0] = tmp;
	if (s->dsp)
	{
		if (s->color)
			write(1, COL_BK_CYAN"ra"COL_BK_RESET"\n", 13);
		else
			write(1, "ra\n", 3);
	}
	if (s->dbg && s->dsp)
	{
		print_stack_col(s);
		s->op_cnt++;
	}
}

void	rb(t_stack *s)
{
	int	tmp;
	int	i;

	tmp = s->b[s->b_cnt - 1];
	i = s->b_cnt;
	while (--i > 0)
		s->b[i] = s->b[i - 1];
	s->b[0] = tmp;
	if (s->dsp)
	{
		if (s->color)
			write(1, COL_BK_CYAN"rb"COL_BK_RESET"\n", 13);
		else
			write(1, "rb\n", 3);
	}
	if (s->dbg && s->dsp)
	{
		print_stack_col(s);
		s->op_cnt++;
	}
}

void	rr(t_stack *s)
{
	int	dsp;

	dsp = s->dsp;
	s->dsp = DISP_OFF;
	ra(s);
	rb(s);
	s->dsp = dsp;
	if (s->dsp)
	{
		if (s->color)
			write(1, COL_BK_CYAN"rr"COL_BK_RESET"\n", 13);
		else
			write(1, "rr\n", 3);
	}
	if (s->dbg)
	{
		print_stack_col(s);
		s->op_cnt++;
	}
}

void	rotate(t_stack *s, int warr)
{
	if (warr == ARR_A)
		ra(s);
	else
		rb(s);
}

void	rara(t_stack *s)
{
	ra(s);
	ra(s);
}
