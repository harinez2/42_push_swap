#include "main.h"

// 3 2 1 : nothing to do
// 3 1 2 : sa
// 2 1 3 : ra
// 1 3 2 : rra
// other : sa -> do one of the above op
void	sort_3(t_stack *s)
{
	if (s->a[0] > s->a[1] && s->a[1] > s->a[2])
		;
	else if (s->a[0] > s->a[2] && s->a[2] > s->a[1])
		sa(s);
	else if (s->a[2] > s->a[0] && s->a[0] > s->a[1])
		ra(s);
	else if (s->a[1] > s->a[2] && s->a[2] > s->a[0])
		rra(s);
	else
	{
		sa(s);
		sort_3(s);
	}
}

static void	push_smallest_to_b(t_stack *s)
{
	int	i;
	int	smallest_i;
	int	smallest_v;

	smallest_i = 0;
	smallest_v = s->a[0];
	i = 1;
	while (i < s->a_cnt)
	{
		if (s->a[i] < smallest_v)
		{
			smallest_i = i;
			smallest_v = s->a[i];
		}
		i++;
	}
	while (s->a[s->a_cnt - 1] != smallest_v)
	{
		if (smallest_i < s->a_cnt / 2)
			rra(s);
		else
			ra(s);
	}
	pb(s);
}

void	sort_6(t_stack *s)
{
	while (s->a_cnt > 3)
		push_smallest_to_b(s);
	sort_3(s);
	while (s->b_cnt > 0)
		pa(s);
}
