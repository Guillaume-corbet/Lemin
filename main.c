/*
** EPITECH PROJECT, 2019
** epitech
** File description:
** main
*/

#include "include/lemin.h"

int read_map(t_list *list)
{
    char *str;

    if (list == NULL)
        return (84);
    while ((str = get_next_line(0)) != NULL) {
        if (insertion(list, str) == 84)
            return (84);
        free(str);
    }
    if (list->first == NULL)
        return (84);
    return (0);
}

map_stat_t *init_map_stat(void)
{
    map_stat_t *ma_st;
    int i = 0;

    if (!(ma_st = malloc(sizeof(map_stat_t))))
        return (NULL);
    ma_st->number_ant = 0;
    if ((ma_st->p_list_box = dlist_new()) == NULL)
        return (NULL);
    if ((ma_st->p_list_tunnel = dlist_new_tunnel()) == NULL)
        return (NULL);
    return (ma_st);
}

void displays(map_stat_t *ma_st)
{
    my_printf("#number_of_ants\n");
    if (ma_st->number_ant != 0)
        my_printf("%d\n", ma_st->number_ant);
    display_list_box(ma_st);
    dlist_display_tunnel(ma_st->p_list_tunnel);
    my_putstr("#moves\n");
}

int last_tests(t_list *list, map_stat_t *ma_st)
{
    int i = 0;
    int j = 0;
    int k = 0;

    i = create_rooms(list, ma_st);
    j = verify_start_end(ma_st);
    k = verify_tunnels(ma_st);
    if (i == 84 || j == 84 || k == 84)
        return (84);
    return (0);
}

int main(int ac, char **av)
{
    t_list *list = initialisation();
    map_stat_t *ma_st;
    int r = 0;

    if (read_map(list) == 84) {
        write(2, "Error reading map\n", 18);
        return (84);
    }
    ma_st = init_map_stat();
    if (ma_st == NULL)
        return (84);
    r = last_tests(list, ma_st);
    displays(ma_st);
    if (moves(ma_st, r) == 84)
        return (84);
    destroy_list(list);
    return (r);
}