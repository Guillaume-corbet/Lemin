/*
** EPITECH PROJECT, 2019
** epitech
** File description:
** ants_moves
*/

#include "include/lemin.h"

void make_a_move(ants_t *ant, struct node_box *to_go, int is_f_move)
{
    ant->last = ant->actual;
    ant->actual->ant = NULL;
    ant->actual = to_go;
    to_go->ant = ant;
    ant->nb_moves = ant->nb_moves + 1;
    if (to_go->room == END) {
        ant->is_end = END;
        to_go->ant = NULL;
    }
    if (is_f_move != 0)
        my_putchar(' ');
    my_printf("P%s-%s", ant->name, to_go->name);
}

int find_the_move(ants_t *ant, int is_f_move)
{
    t_link *link = ant->actual->link;

    while (link != NULL && link->box != NULL) {
        if (link->box->room == END) {
            make_a_move(ant, link->box, is_f_move);
            return (1);
        }
        link = link->next;
    }
    link = ant->actual->link;
    while (link != NULL && link->box != NULL) {
        if (link->box->ant == NULL && link->box != ant->last) {
            make_a_move(ant, link->box, is_f_move);
            return (1);
        }
        link = link->next;
    }
    return (0);
}

int ants_moves(map_stat_t *ma_st, ants_t **ants)
{
    struct node_box *box;
    int is_moves = 0;

    for (int i = 0; ants[i] != NULL; i = i + 1) {
        is_moves = is_moves + find_the_move(ants[i], is_moves);
        if (ants[i]->nb_moves > 10000)
            return (0);
    }
    if (is_moves != 0)
        my_putchar('\n');
    return (is_moves);
}