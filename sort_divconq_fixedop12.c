#include "main.h"

void	move_case_2(t_stack *s, int warr)
{
	if (warr == ARR_A && s->a[s->a_cnt - 2] < s->a[s->a_cnt - 1])
	{
		sara(s);
		ra(s);
	}
	else if (warr == ARR_A && s->a[s->a_cnt - 2] > s->a[s->a_cnt - 1])
	{
		ra(s);
		ra(s);
	}
	else if (warr == ARR_B && s->b[s->b_cnt - 2] < s->b[s->b_cnt - 1])
	{
		pa(s);
		para(s);
		ra(s);
	}
	else if (warr == ARR_B && s->b[s->b_cnt - 2] > s->b[s->b_cnt - 1])
	{
		para(s);
		para(s);
	}
}

void	move_case_1(t_stack *s, int warr)
{
	if (warr == ARR_A)
		ra(s);
	else if (warr == ARR_B)
		para(s);
}
