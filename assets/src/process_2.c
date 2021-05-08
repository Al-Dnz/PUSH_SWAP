#include "header.h"

t_list	*pivot_list(t_list *li, int n)
{
	t_list	*tmp;
	t_list	*tmp2;
	int		inf;
	int		sup;

	tmp = li;
	while (tmp)
	{
		inf = 0;
		sup = 0;
		tmp2 = li;
		while (tmp2)
		{
			if ((int)tmp->content < (int)tmp2->content)
				sup++;
			if ((int)tmp->content > (int)tmp2->content)
				inf++;
			tmp2 = tmp2->next;
		}
		if (inf <= ft_lstsize(li) / n && sup <= (n - 1) * ft_lstsize(li) / n)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}