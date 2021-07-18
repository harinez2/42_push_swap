#include "main.h"

int	ft_atoi(char *s, int *errflg)
{
	long	ret;
	int		i;
	int		neg;

	*errflg = 0;
	i = 0;
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n'
		|| s[i] == '\f' || s[i] == '\r' || s[i] == '\v')
		i++;
	neg = 1;
	if (s[i] == '+')
		i++;
	else if (s[i] == '-')
	{
		neg = -neg;
		i++;
	}
	ret = 0;
	while (s[i] >= '0' && s[i] <= '9')
		ret = ret * 10 + s[i++] - '0';
	if (i == 0 || s[i] != '\0' || ret * neg > INT_MAX || ret * neg < INT_MIN)
		*errflg = -1;
	return (ret * neg);
}

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;
	int				diff;

	i = 0;
	while (i < n)
	{
		diff = (unsigned char)s1[i] - (unsigned char)s2[i];
		if (diff)
			return (diff);
		if (s1[i] == '\0' || s2[i] == '\0')
			return (diff);
		i++;
	}
	return (0);
}

static int	check_duplicate(t_stack *s, int d)
{
	int		i;

	i = 0;
	while (i < s->a_cnt)
	{
		if (s->a[i] == d)
			return (-1);
		i++;
	}
	return (0);
}

static void	error_exit(int retcode)
{
	write(1, "Error\n", 6);
	exit(retcode);
}

void	read_argv(t_stack *s, int argc, char **argv)
{
	int		i;
	int		tmp;
	int		errflg;

	i = argc;
	while (--i > 0)
	{
		if (ft_strncmp(argv[i], "-v", 3) == 0)
		{
			s->dbg = DBG_ON;
			continue ;
		}
		if (ft_strncmp(argv[i], "-c", 3) == 0)
		{
			s->color = 1;
			continue ;
		}
		tmp = ft_atoi(argv[i], &errflg);
		if (errflg == -1 || check_duplicate(s, tmp) == -1)
			error_exit(-1);
		s->a[s->a_cnt++] = tmp;
	}
	if (s->a_cnt == 0)
		error_exit(-1);
}
