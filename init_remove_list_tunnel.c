/*
** EPITECH PROJECT, 2018
** CPE_pushswap_2018
** File description:
** init_stock_list
*/

#include "include/lemin.h"

rlist_tunnel *dlist_new_tunnel(void)
{
    rlist_tunnel *p_new;
    if ((p_new = malloc(sizeof(*p_new))) == NULL)
        return (NULL);
    if (p_new != NULL) {
        p_new->length = 0;
        p_new->p_head = NULL;
        p_new->p_tail = NULL;
    }
    return (p_new);
}

void dlist_display_tunnel(rlist_tunnel *p_list)
{
    struct node_tunnel *p_temp = p_list->p_head;

    my_putstr("#tunnels\n");
    while (p_temp != NULL) {
        my_putstr(p_temp->name);
        my_putchar('-');
        my_putstr(p_temp->name2);
        my_putchar('\n');
        p_temp = p_temp->p_next;
    }
}
