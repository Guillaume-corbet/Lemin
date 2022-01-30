/*
** EPITECH PROJECT, 2019
** epitech
** File description:
** create_rooms
*/

#include "include/lemin.h"

t_element *looking_for_nb_ants(t_list *list, map_stat_t *ma_st)
{
    t_element *actual = list->first;
    char **ants = NULL;

    while (actual != NULL && actual->name[0] == '#') {
        actual = actual->next;
    }
    if (actual != NULL)
        ants = my_str_to_word_array(actual->name);
    if (ants != NULL && ants[0] != NULL && is_digits(ants[0]) == 0)
        ma_st->number_ant = my_getnbr(ants[0]);
    if (ma_st->number_ant <= 0 || (ants[1] != NULL && ants[1][0] != '#') ||
    ma_st->number_ant > 2147483647 || my_strlen(ants[0]) > 10) {
        ma_st->number_ant = 0;
        destroy_double_array(ants);
        return (NULL);
    }
    destroy_double_array(ants);
    return (actual);
}

t_element *make_tests(t_list *list, map_stat_t *ma_st, t_element *actual)
{
    int r = is_room_start_end(list, ma_st, actual);

    if (actual->name[0] == '#')
        return (actual);
    if (r == 84)
        return (NULL);
    else if (r == 1)
        return (actual->next);
    r = is_normal_room(list, ma_st, actual);
    if (r == 84)
        return (NULL);
    else if (r == 1)
        return (actual);
    r = is_tunnel(list, ma_st, actual);
    if (r == 84)
        return (NULL);
    if (r == 1)
        return (actual);
    return (NULL);
}

int create_rooms(t_list *list, map_stat_t *ma_st)
{
    t_element *actual = looking_for_nb_ants(list, ma_st);
    int r = 0;

    if (actual == NULL)
        return (84);
    actual = actual->next;
    while (actual != NULL) {
        ma_st->tests = actual;
        if ((actual = make_tests(list, ma_st, actual)) == NULL)
            return (84);
        actual = ma_st->tests;
        if (actual != NULL)
            actual = actual->next;
    }
    return (0);
}

int verify_start_end(map_stat_t *ma_st)
{
    int start = 0;
    int end = 0;
    struct node_box *actual = ma_st->p_list_box->p_head;

    while (actual != NULL) {
        if (actual->room == BEGIN)
            start = start + 1;
        else if (actual->room == END)
            end = end + 1;
        actual = actual->p_next;
    }
    if (start != 1 || end != 1)
        return (84);
    return (0);
}

int verify_tunnels(map_stat_t *ma_st)
{
    struct node_box *box = ma_st->p_list_box->p_head;
    struct node_tunnel *tun = ma_st->p_list_tunnel->p_head;

    if (tun == NULL)
        return (84);
    while (tun != NULL) {
        box = ma_st->p_list_box->p_head;
        for (box; box != NULL && my_strcmp(box->name, tun->name) != 0;
        box = box->p_next);
        if (box == NULL)
            return (84);
        box = ma_st->p_list_box->p_head;
        for (box; box != NULL && my_strcmp(box->name, tun->name2) != 0;
        box = box->p_next);
        if (box == NULL)
            return (84);
        tun = tun->p_next;
    }
    return (0);
}
