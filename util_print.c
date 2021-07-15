#include "main.h"

void	print_num(int d)
{
	char	c;

	if (d >= 10)
		print_num(d / 10);
	c = d % 10 + '0';
	write(1, &c, 1);
}

void	print_total(int d)
{
	write(1, COL_TX_MAZENTA, 6);
	write(1, "total : ", 8);
	print_num(d);
	write(1, " times", 6);
	write(1, COL_TX_RESET, 6);
	write(1, "\n", 1);
}

void	print_stack_col(t_stack *s)
{
	int		i;

	write(1, COL_TX_CYAN, 6);
	write(1, "  a :", 5);
	i = 0;
	while (i < s->a_cnt)
	{
		write(1, " ", 1);
		print_num(s->a[i]);
		i++;
	}
	write(1, COL_TX_RESET, 6);
	write(1, "\n", 1);
	write(1, COL_TX_CYAN, 6);
	write(1, "  b :", 5);
	i = 0;
	while (i < s->b_cnt)
	{
		write(1, " ", 1);
		print_num(s->b[i]);
		i++;
	}
	write(1, COL_TX_RESET, 6);
	write(1, "\n", 1);
}

void	print_stack_row(t_stack *s)
{
	int		i;

	write(1, "-----\n", 6);
	if (s->a_cnt > s->b_cnt)
		i = s->a_cnt;
	else
		i = s->b_cnt;
	while (--i >= 0)
	{
		if (s->a_cnt > i)
			print_num(s->a[i]);
		else
			write(1, " ", 1);
		if (s->b_cnt > i)
		{
			write(1, " ", 1);
			print_num(s->b[i]);
		}
		write(1, "\n", 1);
	}
	write(1, "- -\n", 4);
	write(1, "a b\n", 4);
}
