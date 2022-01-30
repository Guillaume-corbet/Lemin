/*
** EPITECH PROJECT, 2019
** rooms.c
** File description:
** lemin
*/

#include "include/lemin.h"

int add_a_room(t_list *list, map_stat_t *ma_st, t_element *actual)
{
    char **room;

    if (actual == NULL || (room = my_str_to_word_array(actual->name)) == NULL)
        return (84);
    for (int i = 0; i < 3; i = i + 1) {
        if (room[i] == NULL) {
            destroy_double_array(room);
            return (84);
        }
    } if (is_digits(room[1]) != 0 || is_digits(room[2]) != 0) {
        destroy_double_array(room);
        return (84);
    } else if (room[3] != NULL && room[3][0] != '#') {
        destroy_double_array(room);
        return (84);
    } else {
        if (dlist_append(ma_st->p_list_box, my_getnbr(room[1]),
        my_getnbr(room[2]), room[0]) == 84)
            return (84);
    } destroy_double_array(room);
    return (0);
}

int is_room_start_end(t_list *list, map_stat_t *ma_st, t_element *actual)
{
    if (my_strcmp(ma_st->tests->name, "##start") == 0) {
        ma_st->tests = ma_st->tests->next;
        while (ma_st->tests != NULL && ma_st->tests->name[0] == '#')
            ma_st->tests = ma_st->tests->next;
        if (add_a_room(list, ma_st, ma_st->tests) == 84)
            return (84);
        ma_st->p_list_box->p_tail->room = BEGIN;
        return (1);
    } if (my_strcmp(ma_st->tests->name, "##end") == 0) {
        ma_st->tests = ma_st->tests->next;
        while (ma_st->tests != NULL && ma_st->tests->name[0] == '#')
            ma_st->tests = ma_st->tests->next;
        if (add_a_room(list, ma_st, ma_st->tests) == 84)
            return (84);
        ma_st->p_list_box->p_tail->room = END;
        return (1);
    } if (ma_st->tests->name[0] == '#')
        return (0);
    return (0);
}

int is_normal_room(t_list *list, map_stat_t *ma_st, t_element *actual)
{
    char **room;

    if (actual == NULL || (room = my_str_to_word_array(actual->name)) == NULL)
        return (84);
    for (int i = 0; i < 3; i = i + 1) {
        if (room[i] == NULL) {
            destroy_double_array(room);
            return (0);
        }
    } if (is_digits(room[1]) != 0 || is_digits(room[2]) != 0) {
        destroy_double_array(room);
        return (0);
    } else if (room[3] != NULL && room[3][0] != '#') {
        destroy_double_array(room);
        return (0);
    } else {
        if (dlist_append(ma_st->p_list_box, my_getnbr(room[1]),
        my_getnbr(room[2]), room[0]) == 84)
            return (84);
    } destroy_double_array(room);
    return (1);
}

int is_tunnel(t_list *list, map_stat_t *ma_st, t_element *actual)
{
    char **room;

    if (actual == NULL || (room = my_str_to_word_array(actual->name)) == NULL)
        return (84);
    if (room[0] == NULL) {
        destroy_double_array(room);
        return (84);
    } if (room[1] != NULL && room[1][0] != '#') {
        destroy_double_array(room);
        return (84);
    } if (dlist_append_tunnel(ma_st->p_list_tunnel, room[0]) == 84) {
        destroy_double_array(room);
        return (84);
    }
    destroy_double_array(room);
    return (1);
}

void destroy_links(map_stat_t *ma_st)
{
    struct node_box *p_temp = ma_st->p_list_box->p_head;
    t_link *link_tmp;
    t_link *link_next;

    while (p_temp != NULL) {
        link_tmp = p_temp->link;
        while (link_tmp != NULL) {
            link_next = link_tmp->next;
            free(link_tmp);
            link_tmp = link_next;
        }
        p_temp = p_temp->p_next;
    }
}