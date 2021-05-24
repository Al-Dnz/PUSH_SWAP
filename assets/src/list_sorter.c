#include "header.h"

/* See https:// www.geeksforgeeks.org/?p=3622 for details of this
function */
t_list* sorted_merge(t_list* a, t_list* b)
{
    t_list* result = NULL;
 
    /* Base cases */
    if (a == NULL)
        return (b);
    else if (b == NULL)
        return (a);
 
    /* Pick either a or b, and recur */
    if ((int)a->content <= (int)b->content)
    {
        result = a;
        result->next = sorted_merge(a->next, b);
    }
    else
    {
        result = b;
        result->next = sorted_merge(a, b->next);
    }
    return (result);
}

void front_backsplit(t_list* source, t_list** frontRef, t_list** backRef)
{
    t_list* fast;
    t_list* slow;
    slow = source;
    fast = source->next;
 
    /* Advance 'fast' two nodes, and advance 'slow' one node */
    while (fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL) {
            slow = slow->next;
            fast = fast->next;
        }
    }
    /* 'slow' is before the midpoint in the list, so split it in two
    at that point. */
    *frontRef = source;
    *backRef = slow->next;
    slow->next = NULL;
}

/* sorts the linked list by changing next pointers (not data) */
void list_merge_sort(t_list** head_ref)
{
    t_list* head = *head_ref;
    t_list* a;
    t_list* b;
 
    /* Base case -- length 0 or 1 */
    if ((head == NULL) || (head->next == NULL))
        return;
    /* Split head into 'a' and 'b' sublists */
    front_backsplit(head, &a, &b);
    /* Recursively sort the sublists */
    list_merge_sort(&a);
    list_merge_sort(&b);
    /* answer = merge the two sorted lists together */
    *head_ref = sorted_merge(a, b);
}
 



 