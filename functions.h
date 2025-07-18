#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdio.h>
#include <unistd.h>
#include "point.h"

extern int     g_size_x;
extern int     g_size_y;
extern char    g_empty;
extern char    g_obsticle;
extern char    g_full;

void    loops(point **tab);
void	give_value(point **tab, int index_x, int index_y, int x);
void    find_square(int index_x, int index_y, point **tab);
void    print_board(point **tab);
void	find_obs(point **t);
void    find_main(point **tab);
point **readmap(char *filename);
void print_map(point **map, int size_x, int size_y);
void free_map(point **map, int lines);
int ft_atoi(char *str);
int is_valid(char *add_info, int *lines, int header_len);
int fill_map(point **map, char *buffer, int pos, int lines, int columns, rowinfo info);
int alloc_and_fill_row(point **row, char *buffer, int pos, rowinfo info);
int count_columns(char *buffer, int pos);



#endif