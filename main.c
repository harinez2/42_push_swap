#include "main.h"

static int	check_finished(t_stack *s)
{
	int	i;

	i = 0;
	while (i < s->a_cnt - 1)
	{
		if (s->a[i] <= s->a[i + 1])
			return (1);
		i++;
	}
	return (0);
}

void	sort(t_stack *s)
{
	if (check_finished(s) == 0)
		return ;
	else if (s->a_cnt == 2 && s->a[0] < s->a[1])
		sa(s);
	else if (s->a_cnt == 3)
		sort_3(s);
	else if (s->a_cnt >= 4 && s->a_cnt <= 6)
		sort_6(s);
	else if (s->a_cnt >= 7)
		move_half_to_another(s, ARR_A, get_arrcnt(s, ARR_A));
}

// sa  : swap a - swap the first 2 elements at the top of stack a.
// sb  : swap b - swap the first 2 elements at the top of stack b.
// ss  : sa and sb at the same time.
// pa  : push a - take the first element at the top of b 
//                and put it at the top of a.
// pb  : push b - take the first element at the top of a
//                and put it at the top of b.
// ra  : rotate a - shift up all elements of stack a by 1.
//                  The first element becomesthe last one.
// rb  : rotate b - shift up all elements of stack b by 1.
//                  The first element becomesthe last one.
// rr  : ra and rb at the same time.
// rra : reverse rotate a - shift down all elements of stack a by 1.
//                          The last element becomes the first one.
// rrb : reverse rotate b - shift down all elements of stack b by 1.
//                          The last element becomes the first one.
// rrr : rra and rrb at the same time.
int	main(int argc, char **argv)
{
	t_stack	s;

	if (argc < 2)
		return (0);
	init_stack(&s, DISP_ON, 0);
	read_argv(&s, argc, argv);
	if (s.dbg)
		print_stack_col(&s);
	sort(&s);
	if (s.dbg)
		print_total(s.op_cnt);
	return (0);
}
