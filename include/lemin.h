/*
** EPITECH PROJECT, 2019
** epitech
** File description:
** lemin
*/

#ifndef LEMIN_H
#define LEMIN_H

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "../lib/my/mylib.h"

#define BEGIN 42
#define END 666

#define ERROR_BAC_ZERO  if (str[i] == '\0') { return (84); }
#define ERROR_COMMENT   if (str[i] == '#') { return (84); }

typedef struct t_link t_link;
typedef struct ants_t ants_t;

struct node_box
{
    ants_t *ant;
    int room;
    t_link *link;
    char *name;
    int x;
    int y;
    struct node_box *p_next;
};

struct t_link
{
    struct node_box *box;
    t_link *next;
};

struct ants_t
{
    char *name;
    int is_end;
    int nb_moves;
    struct node_box *actual;
    struct node_box *last;
};

typedef struct dlist_box
{
    size_t length;
    struct node_box *p_tail;
    struct node_box *p_head;
}rlist_box;

struct node_tunnel
{
    char *name;
    char *name2;
    struct node_tunnel *p_next;
    struct node_tunnel *p_prev;
};

typedef struct dlist_tunnel
{
    size_t length;
    struct node_tunnel *p_tail;
    struct node_tunnel *p_head;
}rlist_tunnel;

typedef struct t_element t_element;
struct t_element
{
    char *name;
    t_element *next;
};

typedef struct t_list t_list;
struct t_list
{
    t_element *first;
    t_element *last;
    int lenght;
};

typedef struct map_stat
{
    int number_ant;
    t_element *tests;
    struct node_box *first_room;
    rlist_box *p_list_box;
    rlist_tunnel *p_list_tunnel;
}map_stat_t;

void dlist_display(rlist_box *p_list, char *begin, char *end);

rlist_box *dlist_new(void);
void dlist_remove_third(rlist_box *p_list, struct node_box *p_temp, int pos,
int i);
void dlist_remove_second(rlist_box *p_list, struct node_box *p_temp);
void dlist_remove(rlist_box *p_list, int position);

void dlist_append_second(rlist_box *p_list, struct node_box *p_new);
int dlist_append(rlist_box *p_list, int x, int y, char *name);

rlist_tunnel *dlist_new_tunnel(void);
void dlist_remove_third_tun(rlist_tunnel *p_list, struct node_tunnel *p_temp,
int pos, int i);
void dlist_remove_second_tun(rlist_tunnel *p_list, struct node_tunnel *p_temp);
void dlist_remove_tunnel(rlist_tunnel *p_list, int position);
void dlist_display_tunnel(rlist_tunnel *p_list);

void dlist_append_second_tun(rlist_tunnel *p_list, struct node_tunnel *p_new);
int dlist_append_tunnel(rlist_tunnel *p_list, char *str);

int verif_box(char *str);
int verif_tunnel(char *str);
int verif_begin_end(map_stat_t *ma_st, char **tab, int j);

int stock_ant_struct_map(map_stat_t *ma_st, char **tab);
int stock_in_struct_map(map_stat_t *ma_st, char **tab);
map_stat_t *init_map_stat(void);

char **read_on_zero(void);
void display_all_information(map_stat_t *ma_st);
void destroy_linked_list(map_stat_t *ma_st, char **tab);

ants_t **create_ants(int number_ant, map_stat_t *ma_st);
void destroy_double_array(char **array);
int create_anthill(map_stat_t *ma_st);
int find_tunnels(struct node_box *p_temp, struct node_tunnel *tunnel_temp,
map_stat_t *ma_st);
int make_link(struct node_box *p_temp, char *tunnel, map_stat_t *ma_st);
void destroy_ants(ants_t **ants);
int ants_moves(map_stat_t *ma_st, ants_t **ants);
void make_a_move(ants_t *ant, struct node_box *to_go, int is_f_move);
int find_the_move(ants_t *ant, int is_f_move);

int insertion(t_list *list, char *name);
void print_list(t_list *list);
t_list *initialisation(void);
void destroy_list(t_list *list);

t_element *looking_for_nb_ants(t_list *list, map_stat_t *ma_st);
int create_rooms(t_list *list, map_stat_t *ma_st);
void display_list_box(map_stat_t *ma_st);
int is_tunnel(t_list *list, map_stat_t *ma_st, t_element *actual);
int is_normal_room(t_list *list, map_stat_t *ma_st, t_element *actual);
int is_room_start_end(t_list *list, map_stat_t *ma_st, t_element *actual);
int add_a_room(t_list *list, map_stat_t *ma_st, t_element *actual);
int verify_start_end(map_stat_t *ma_st);
int verify_tunnels(map_stat_t *ma_st);
void destroy_links(map_stat_t *ma_st);
int moves(map_stat_t *ma_st, int r);

#endif
