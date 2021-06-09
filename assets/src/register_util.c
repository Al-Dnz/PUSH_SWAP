#include "header.h"

void	register_add_back(t_reg **alst, t_reg *new)
{
	t_reg	*li;

	if (!*alst)
	{
		*alst = new;
		return ;
	}
	li = register_last(*alst);
	li->next = new;
}

void	register_add_front(t_reg **alst, t_reg *new)
{
	t_reg	*li;

	li = new;
	if (li == NULL)
		return ;
	if (*alst != NULL)
		li->next = *alst;
	*alst = li;
}

void	register_clear(t_reg **lst)
{
	t_reg	*li;

	if (*lst == NULL)
		return ;
	if ((*lst)->next != NULL)
		li = (*lst)->next;
	else
		li = NULL;
	(*lst)->n = 0;
	free(*lst);
	*lst = li;
	register_clear(&(*lst));
}

void	register_pop(t_reg **head_ref)
{
	t_reg	*head;
	int		result;

	head = NULL;
	if (*head_ref == NULL)
		return ;
	head = *head_ref;
	result = head->n;
	(*head_ref) = (*head_ref)->next;
	free(head);
}

t_reg	*register_new(int n)
{
	t_reg	*li;

	li = malloc(sizeof(t_reg));
	if (li == NULL)
		return (NULL);
	li->n = n;
	li->next = NULL;
	return (li);
}
