/*
** EPITECH PROJECT, 2019
** epitech
** File description:
** create_anthill
*/

#include "include/lemin.h"

ants_t **create_ants(int number_ant, map_stat_t *ma_st)
{
    ants_t **ants = malloc(sizeof(ants_t *) * (number_ant + 1));

    if (ants == NULL)
        return (NULL);
    for (int i = 0; i < number_ant; i = i + 1) {
        ants[i] = malloc(sizeof(ants_t));
        ants[i]->name = my_int_to_str(i + 1);
        ants[i]->is_end = 0;
        ants[i]->actual = ma_st->first_room;
        ants[i]->last = ma_st->first_room;
    }
    ants[number_ant] = NULL;
    return (ants);
}

void destroy_ants(ants_t **ants)
{
    for (int i = 0; ants[i] != NULL; i = i + 1) {
        free(ants[i]->name);
        free(ants[i]);
    }
    free(ants);
}

int make_link(struct node_box *p_temp, char *tunnel, map_stat_t *ma_st)
{
    struct node_box *to_link = ma_st->p_list_box->p_head;
    t_link *new_link = malloc(sizeof(t_link));
    t_link *find_link = p_temp->link;

    if (new_link == NULL)
        return (84);
    if (p_temp->link == NULL) {
        p_temp->link = new_link;
        while (to_link != NULL && my_strcmp(to_link->name, tunnel) != 0)
            to_link = to_link->p_next;
        p_temp->link->box = to_link;
        p_temp->link->next = NULL;
    } else {
        while (find_link->next != NULL)
            find_link = find_link->next;
        find_link->next = new_link;
        while (to_link != NULL && my_strcmp(to_link->name, tunnel) != 0)
            to_link = to_link->p_next;
        new_link->box = to_link;
        new_link->next = NULL;
    } return (0);
}

int find_tunnels(struct node_box *p_temp, struct node_tunnel *tunnel_temp,
map_stat_t *ma_st)
{
    if (my_strcmp(p_temp->name, tunnel_temp->name) == 0 &&
    p_temp->room != END) {
        if (make_link(p_temp, tunnel_temp->name2, ma_st) == 84)
            return (84);
    } else if (my_strcmp(p_temp->name, tunnel_temp->name2) == 0
    && p_temp->room != END) {
        if (make_link(p_temp, tunnel_temp->name, ma_st) == 84)
            return (84);
    }
    return (0);
}

int create_anthill(map_stat_t *ma_st)
{
    struct node_box *p_temp = ma_st->p_list_box->p_head;
    struct node_tunnel *tunnel_temp = ma_st->p_list_tunnel->p_head;

    while (p_temp != NULL) {
        p_temp->link = NULL;
        if (p_temp->room == BEGIN)
            ma_st->first_room = p_temp;
        while (tunnel_temp != NULL && find_tunnels(p_temp, tunnel_temp,
        ma_st) == 0)
            tunnel_temp = tunnel_temp->p_next;
        if (tunnel_temp != NULL)
            return (84);
        p_temp = p_temp->p_next;
        tunnel_temp = ma_st->p_list_tunnel->p_head;
    }
    return (0);
}
