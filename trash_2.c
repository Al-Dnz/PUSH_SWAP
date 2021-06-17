#include "header.h"

void	scan_seq(t_reg *seq, t_list **li_a, t_list **li_b)
{
	static char	*arr[12] = {"", "sa", "sb", "ss", "pb", "pa", "rra", "rrb",
"rrr", "ra", "rb", "rr"};

	while (seq)
	{
		switcher(arr[seq->n], li_a, li_b);
		seq = seq->next;
	}
}

void	get_instruct(t_list **li_a, t_list **li_b, int *error)
{
	char	*str;
	int		ret;
	//(void)li_a;
	//(void)li_b;
	t_reg	*seq;
	seq =  NULL;

	ret = 1;
	while (ret != 0)
	{
		str = NULL;
		ret = get_next_line(0, &str);

		if (ft_strlen(str) > 0)
		{
			if (!auth_str(str))
			{
				*error = 1;
				ret = 0;
			}
			else
				record_seq(&seq, str);
		}
		else
			record_seq(&seq, "");
		ft_strclr(&str);
		if (seq_problem(seq))
		{
			*error = 1;
			ret = 0;
		}
	}
	ft_strclr(&str);
	read_seq_scaffold(seq);
	if (error == 0)
		scan_seq(seq, li_a, li_b);
}
void	go_error(int *error, int *ret)
{
		*error = 1;
		*ret = 0;
}

int	read_seq_scaffold(t_reg *reg)
{
	int			n;
	static char	*arr[12] = {"", "sa", "sb", "ss", "pb", "pa", "rra", "rrb",
"rrr", "ra", "rb", "rr"};

	n = 0;
	while (reg != NULL)
	{
		ft_putstr_fd("[", 1);
		ft_putstr_fd(arr[reg->n], 1);
		ft_putstr_fd("]=>", 1);
		n++;
		reg = reg->next;
	}
	ft_putstr_fd("NULL\n", 1);
	return (n);
}

int seq_problem(t_reg *seq)
{
	if (seq->next == NULL && seq->n == 0)
		return (1);
	while (seq->next)
		seq = seq->next;
	if (seq->n == 0)
			return (1);
	return (0);
}

void	record_seq(t_reg **seq, char *str)
{
	static char	*arr[12] = {"", "sa", "sb", "ss", "pb", "pa", "rra", "rrb",
"rrr", "ra", "rb", "rr"};
	t_reg	*temp;

	temp = NULL;
	temp = register_new(ft_str_index(str, arr));
	register_add_back(seq, temp);
}
