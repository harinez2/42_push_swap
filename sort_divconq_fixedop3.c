#include "main.h"

static void	move_case_3_arr_a_1(t_stack *s, int a, int b, int c)
{
	if (a > b && b > c)
	{
		rara(s);
		ra(s);
	}
	else if (a > c && c > b)
	{
		sara(s);
		ra(s);
		ra(s);
	}
	else if (b > a && a > c)
	{
		ra(s);
		sara(s);
		ra(s);
	}
}

static void	move_case_3_arr_a_2(t_stack *s, int a, int b, int c)
{
	if (b > c && c > a)
	{
		pb(s);
		sara(s);
		para(s);
		ra(s);
	}
	else if (c > a && a > b)
	{
		pb(s);
		rara(s);
		para(s);
	}
	else if (c > b && b > a)
	{
		pb(s);
		sa(s);
		rara(s);
		pa(s);
		ra(s);
	}
}

static void	move_case_3_arr_b_1(t_stack *s, int a, int b, int c)
{
	if (a > b && b > c)
	{
		para(s);
		para(s);
		para(s);
	}
	else if (a > c && c > b)
	{
		pa(s);
		para(s);
		ra(s);
		para(s);
	}
	else if (b > a && a > c)
	{
		para(s);
		pa(s);
		para(s);
		ra(s);
	}
}

static void	move_case_3_arr_b_2(t_stack *s, int a, int b, int c)
{
	if (b > c && c > a)
	{
		sb(s);
		pa(s);
		pa(s);
		para(s);
		ra(s);
		ra(s);
	}
	else if (c > a && a > b)
	{
		pa(s);
		para(s);
		para(s);
		ra(s);
	}
	else if (c > b && b > a)
	{
		pa(s);
		pa(s);
		para(s);
		ra(s);
		ra(s);
	}
}

void	move_case_3(t_stack *s, int warr)
{
	int		a;
	int		b;
	int		c;

	if (warr == ARR_A)
	{
		a = s->a[s->a_cnt - 3];
		b = s->a[s->a_cnt - 2];
		c = s->a[s->a_cnt - 1];
		move_case_3_arr_a_1(s, a, b, c);
		move_case_3_arr_a_2(s, a, b, c);
	}
	else if (warr == ARR_B)
	{
		a = s->b[s->b_cnt - 3];
		b = s->b[s->b_cnt - 2];
		c = s->b[s->b_cnt - 1];
		move_case_3_arr_b_1(s, a, b, c);
		move_case_3_arr_b_2(s, a, b, c);
	}
}
