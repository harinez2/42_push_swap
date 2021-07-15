#include "main.h"

static void	check_and_print_ans(t_stack *s)
{
	int	i;
	int	flg;

	if (s->b_cnt != 0)
	{
		write(1, "KO\n", 3);
		return ;
	}
	flg = 0;
	i = 1;
	while (i < s->a_cnt)
	{
		if (s->a[i - 1] < s->a[i])
		{
			flg = 1;
			break ;
		}
		i++;
	}
	if (flg)
		write(1, "KO\n", 3);
	else
		write(1, "OK\n", 3);
}

static void	exec_op(t_stack *s, char *line)
{
	if (ft_strncmp("rra", line, 3) == 0)
		rra(s);
	else if (ft_strncmp("rrb", line, 3) == 0)
		rrb(s);
	else if (ft_strncmp("rrr", line, 3) == 0)
		rrr(s);
	else if (ft_strncmp("sa", line, 2) == 0)
		sa(s);
	else if (ft_strncmp("sb", line, 2) == 0)
		sb(s);
	else if (ft_strncmp("ss", line, 2) == 0)
		ss(s);
	else if (ft_strncmp("pa", line, 2) == 0)
		pa(s);
	else if (ft_strncmp("pb", line, 2) == 0)
		pb(s);
	else if (ft_strncmp("ra", line, 2) == 0)
		ra(s);
	else if (ft_strncmp("rb", line, 2) == 0)
		rb(s);
	else if (ft_strncmp("rr", line, 2) == 0)
		rr(s);
}

static void	print_read_data(int i, char *line)
{
	int		j;

	write(1, COL_TX_MAZENTA, 6);
	write(1, "  read data : ", 14);
	print_num(i);
	write(1, " : ", 3);
	j = 0;
	while (line[j] != '\0')
		write(1, &(line[j++]), 1);
	write(1, COL_TX_RESET, 6);
	write(1, "\n", 1);
}

int	main(int argc, char **argv)
{
	t_stack	s;
	int		i;
	char	*line;

	if (argc < 2)
		return (0);
	init_stack(&s, DISP_OFF, 0);
	read_argv(&s, argc, argv);
	if (s.dbg)
		s.dsp = DISP_ON;
	line = NULL;
	i = 1;
	while (0 < i)
	{
		i = get_next_line(0, &line);
		if (s.dbg)
			print_read_data(i, line);
		exec_op(&s, line);
		free(line);
	}
	check_and_print_ans(&s);
	if (s.dbg)
		print_total(s.op_cnt);
	return (0);
}
