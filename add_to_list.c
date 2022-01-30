/*
** EPITECH PROJECT, 2018
** CPE_pushswap_2018
** File description:
** add_to_list
*/

#include "include/lemin.h"

void display_list_box(map_stat_t *ma_st)
{
    struct node_box *actual = ma_st->p_list_box->p_head;

    my_printf("#rooms\n");
    while (actual != NULL) {
        if (actual->room == BEGIN)
            my_printf("##start\n");
        else if (actual->room == END)
            my_printf("##end\n");
        my_printf("%s %d %d\n", actual->name, actual->x, actual->y);
        actual = actual->p_next;
    }
}

void dlist_append_second(rlist_box *p_list, struct node_box *p_new)
{
    if (p_list->p_tail == NULL) {
        p_list->p_head = p_new;
        p_list->p_tail = p_new;
    } else {
        p_list->p_tail->p_next = p_new;
        p_list->p_tail = p_new;
    }
    p_list->length = p_list->length + 1;
}

int is_allready(rlist_box *p_list, char *name)
{
    struct node_box *actual = p_list->p_head;

    while (actual != NULL) {
        if (my_strcmp(actual->name, name) == 0)
            return (84);
        actual = actual->p_next;
    }
    return (0);
}

int dlist_append(rlist_box *p_list, int x, int y, char *name)
{
    struct node_box *p_new = malloc(sizeof(*p_new));

    if (p_list != NULL) {
        if (p_new == NULL || is_allready(p_list, name) == 84)
            return (84);
        if ((p_new->name = malloc(sizeof(char) * my_strlen(name) + 1)) == NULL)
            return (84);
        p_new->x = x;
        p_new->y = y;
        p_new->name = my_strcpy(p_new->name, name);
        p_new->p_next = NULL;
        p_new->ant = NULL;
        p_new->room = 0;
        dlist_append_second(p_list, p_new);
    }
    return (0);
}
