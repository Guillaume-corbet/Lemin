/*
** EPITECH PROJECT, 2018
** linked_lists.c
** File description:
** basics functions for linked_lists
*/

#include "include/lemin.h"

int insertion(t_list *list, char *name)
{
    t_element *new = malloc(sizeof(*new));

    if (new == NULL)
        return (84);
    new->name = malloc(sizeof(char) * (my_strlen(name) + 1));
    if (new->name == NULL)
        return (84);
    fill_str(new->name, my_strlen(name) + 1);
    new->name = my_strcpy(new->name, name);
    if (list->first == NULL && list->last == NULL) {
        list->first = new;
        list->last = new;
        new->next = NULL;
    } else {
        list->last->next = new;
        new->next = NULL;
        list->last = new;
    }
    list->lenght = list->lenght + 1;
    return (0);
}

void print_list(t_list *list)
{
    t_element *actual;

    actual = list->first;
    while (actual != NULL) {
        my_printf("%s\n", actual->name);
        actual = actual->next;
    }
}

t_list *initialisation(void)
{
    t_list *list = malloc(sizeof(*list));

    if (list == NULL)
        return (NULL);
    list->first = NULL;
    list->last = NULL;
    list->lenght = 0;
    return (list);
}

void destroy_list(t_list *list)
{
    t_element *actual;
    t_element *next;

    actual = list->first;
    while (actual != NULL) {
        next = actual->next;
        free(actual->name);
        free(actual);
        actual = next;
    }
    free(list);
}