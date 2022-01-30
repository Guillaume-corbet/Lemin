/*
** EPITECH PROJECT, 2019
** epitech
** File description:
** moves
*/

#include "include/lemin.h"

int moves(map_stat_t *ma_st, int r)
{
    ants_t **ants;

    if (r != 84) {
        if (create_anthill(ma_st) == 84)
            return (84);
        if ((ants = create_ants(ma_st->number_ant, ma_st)) == NULL)
            return (84);
        while (ants_moves(ma_st, ants) != 0);
        destroy_ants(ants);
        destroy_links(ma_st);
    }
    return (0);
}