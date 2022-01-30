/*
** EPITECH PROJECT, 2018
** my_getnbr.c
** File description:
** Task05 of CPool Day04
*/

#include "mylib.h"

int set_sign_getnbr(char const *str, int *sign)
{
    int i = 0;

    while (str[i] == '+' || str[i] == '-') {
        if (str[i] == '-')
            *sign = *sign * -1;
        i++;
    }
    return (i);
}

int my_getnbr(char const *str)
{
    int nb = 0;
    int sign = 1;
    int i = set_sign_getnbr(str, &sign);

    while (str[i] != '\0') {
        if (str[i] >= '0' && str[i] <= '9') {
            nb = nb * 10;
            nb = nb + str[i] - '0';
            i++;
        } else
            return (nb * sign);
    }
    return (nb * sign);
}
