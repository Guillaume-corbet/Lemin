/*
** EPITECH PROJECT, 2018
** CPE_pushswap_2018
** File description:
** init_stock_list
*/

#include "include/lemin.h"

rlist_box *dlist_new(void)
{
    rlist_box *p_new;
    if ((p_new = malloc(sizeof(*p_new))) == NULL)
        return (NULL);
    if (p_new != NULL) {
        p_new->length = 0;
        p_new->p_head = NULL;
        p_new->p_tail = NULL;
    }
    return (p_new);
}