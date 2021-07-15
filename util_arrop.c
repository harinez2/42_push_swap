#include "main.h"

void	init_stack(t_stack *s, int dsp, int dbg)
{
	s->a_cnt = 0;
	s->b_cnt = 0;
	s->op_cnt = 0;
	s->dsp = dsp;
	s->dbg = dbg;
	s->color = 0;
}

void	swap_arr(int *warr)
{
	if (*warr == ARR_A)
		*warr = ARR_B;
	else
		*warr = ARR_A;
}

int	*get_arr(t_stack *s, int warr)
{
	if (warr == ARR_A)
		return (s->a);
	else
		return (s->b);
}

void	print_arr_name(int warr)
{
	if (warr == ARR_A)
		write(1, "ARR_A", 5);
	else
		write(1, "ARR_B", 5);
}

int	get_arrcnt(t_stack *s, int warr)
{
	if (warr == ARR_A)
		return (s->a_cnt);
	else
		return (s->b_cnt);
}
