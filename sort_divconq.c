#include "main.h"

static void	bubble_sort(int *c, int cnt)
{
	int		i;
	int		j;
	int		tmp;

	i = 0;
	while (i < cnt)
	{
		j = i;
		while (j < cnt)
		{
			if (c[i] > c[j])
			{
				tmp = c[i];
				c[i] = c[j];
				c[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

static double	calc_mid_v(t_stack *s, int warr, int cnt)
{
	int		i;
	int		c[STACK_MAX];
	int		diff;

	i = cnt;
	diff = get_arrcnt(s, warr) - cnt;
	while (i >= 0)
	{
		c[i] = get_arr(s, warr)[diff + i];
		i--;
	}
	bubble_sort(c, cnt);
	if (cnt % 2 == 0)
		return ((c[cnt / 2 - 1] + c[cnt / 2]) / 2);
	else
		return (c[cnt / 2]);
}

static int	push_or_rotate(t_stack *s, int warr, int mid_v)
{
	int		moved;

	moved = 0;
	if (get_arr(s, warr)[get_arrcnt(s, warr) - 1] <= mid_v)
	{
		pushr(s, warr);
		moved++;
	}
	else
		rotate(s, warr);
	return (moved);
}

static void	rotate_back(t_stack *s, int warr, int arrcnt, int moved)
{
	int		i;

	if (get_arrcnt(s, warr) + moved - arrcnt > arrcnt - moved)
	{
		i = arrcnt - moved;
		while (--i >= 0)
			rrotate(s, warr);
	}
	else
	{
		i = get_arrcnt(s, warr) + moved - arrcnt;
		while (--i >= 0)
			rotate(s, warr);
	}
}

int	move_half_to_another(t_stack *s, int warr, int arrcnt)
{
	int		i;
	double	mid_v;
	int		moved;

	if (arrcnt <= 3)
	{
		if (arrcnt == 3)
			move_case_3(s, warr);
		else if (arrcnt == 2)
			move_case_2(s, warr);
		else if (arrcnt == 1)
			move_case_1(s, warr);
		return (0);
	}
	mid_v = calc_mid_v(s, warr, arrcnt);
	moved = 0;
	i = arrcnt;
	while (--i >= 0)
		moved += push_or_rotate(s, warr, mid_v);
	rotate_back(s, warr, arrcnt, moved);
	swap_arr(&warr);
	move_half_to_another(s, warr, moved);
	swap_arr(&warr);
	move_half_to_another(s, warr, arrcnt - moved);
	return (arrcnt);
}
