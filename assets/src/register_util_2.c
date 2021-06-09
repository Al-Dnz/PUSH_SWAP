#include "header.h"

t_reg	*register_last(t_reg *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

void	read_seq(t_reg *reg)
{
	static char	*arr[12] = {"", "sa", "sb", "ss", "pa", "pb", "ra", "rb",
"rr", "rra", "rrb", "rrr"};

	while (reg != NULL)
	{
		ft_putstr_fd(arr[reg->n], 1);
		ft_putstr_fd("\n", 1);
		reg = reg->next;
	}
}

void	display_register(t_reg *li)
{
	while (li != NULL)
	{
		ft_putstr_fd("[", 1);
		ft_putnbr_fd((int)li->n, 1);
		ft_putstr_fd("]->", 1);
		li = li->next;
	}
	ft_putstr_fd("NULL\n", 1);
}
