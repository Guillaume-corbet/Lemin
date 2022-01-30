/*
** EPITECH PROJECT, 2018
** CPE_pushswap_2018
** File description:
** add_to_list
*/

#include "include/lemin.h"

char *first_part_tunnel(char *str)
{
    char *name;
    int size = 0;

    for (size = 0; str[size] != '\0' && str[size] != '-'; size = size + 1);
    if (str[size] == '\0' || (name = malloc(sizeof(char) * (size + 1))) == NULL)
        return (NULL);
    else if (str[size + 1] == '-')
        return (NULL);
    for (int i = 0; i < size; i = i + 1)
        name[i] = str[i];
    name[size] = '\0';
    return (name);
}

char *second_part_tunnel(char *str)
{
    char *name;
    int i = 0;
    int j = 0;

    for (i = 0; str[i] != '\0' && str[i] != '-'; i = i + 1);
    for (j = i; str[j] != '\0'; j = j + 1);
    i = i + 1;
    if (j == i || (name = malloc(sizeof(char) * (j - i + 3))) == NULL)
        return (NULL);
    fill_str(name, j - i + 3);
    for (int k = 0; i < j; k = k + 1) {
        name[k] = str[i];
        i = i + 1;
    }
    name[i] = '\0';
    return (name);
}

void dlist_append_second_tun(rlist_tunnel *p_list, struct node_tunnel *p_new)
{
    if (p_list->p_tail == NULL) {
        p_new->p_prev = NULL;
        p_list->p_head = p_new;
        p_list->p_tail = p_new;
    } else {
        p_list->p_tail->p_next = p_new;
        p_new->p_prev = p_list->p_tail;
        p_list->p_tail = p_new;
    }
    p_list->length = p_list->length + 1;
}

int is_allready_tun(rlist_tunnel *p_list, struct node_tunnel *p_new)
{
    struct node_tunnel *actual = p_list->p_head;

    while (actual != NULL) {
        if ((my_strcmp(actual->name, p_new->name) == 0 &&
        my_strcmp(actual->name2, p_new->name2) == 0) ||
        (my_strcmp(actual->name, p_new->name2) == 0 &&
        my_strcmp(actual->name2, p_new->name) == 0))
            return (84);
        actual = actual->p_next;
    }
    return (0);
}

int dlist_append_tunnel(rlist_tunnel *p_list, char *str)
{
    struct node_tunnel *p_new;

    if (p_list != NULL) {
        if ((p_new = malloc(sizeof(*p_new))) == NULL)
            return (84);
        p_new->name = first_part_tunnel(str);
        if (p_new->name == NULL)
            return (84);
        p_new->name2 = second_part_tunnel(str);
        if (p_new->name2 == NULL)
            return (84);
        p_new->p_next = NULL;
        if (is_allready_tun(p_list, p_new) != 84)
            dlist_append_second_tun(p_list, p_new);
    }
    return (0);
}
