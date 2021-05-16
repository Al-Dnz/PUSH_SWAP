#include "header.h"

t_register	*register_last(t_register *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

void	register_add_back(t_register **alst, t_register *new)
{
	t_register	*li;

	if (!*alst)
	{
		*alst = new;
		return ;
	}
	li = register_last(*alst);
	li->next = new;
}

void	register_add_front(t_register **alst, t_register *new)
{
	t_register	*li;

	li = new;
	if (li == NULL)
		return ;
	if (*alst != NULL)
		li->next = *alst;
	*alst = li;
}

 void	register_clear(t_register **lst)
{
	t_register	*li;

	if (*lst == NULL)
		return ;
	li = (*lst)->next != NULL ? (*lst)->next : NULL;
	(*lst)->n = 0;
	free(*lst);
	*lst = li;
	register_clear(&(*lst));
}

void	register_pop(t_register **head_ref)
{
	t_register	*head;
	int			result;

	head = NULL;
	if (*head_ref == NULL)
		return ;
	head = *head_ref;
	result = head->n;
	(*head_ref) = (*head_ref)->next;
	free(head);
}

t_register	*register_new(int n)
{
	t_register	*li;

	li = malloc(sizeof(t_register));
	if (li == NULL)
		return (NULL);
	li->n = n;
	li->next = NULL;
	return (li);
}


void	display_register(t_register *li)
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

