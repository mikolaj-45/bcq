#include <stdio.h>
#include <unistd.h>
#include "point.h"

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

extern int     g_size_x;
extern int     g_size_y;
extern char    g_empty;
extern char    g_obsticle;
extern char    g_full;

void    loops(point **tab, int *max, int *dist);
void    find_square(int index_x, int index_y, point **tab, int *max, int *dist);
void    print_board(int x, point **tab, int dist);
void    find_main(point **tab);
static int	read_file_to_buffer(char *filename, char *buffer);
point **readmap(char *filename);
void print_map(point **map, int size_x, int size_y);
void free_map(point **map, int lines);


#endif