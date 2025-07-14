#include <stdio.h>
#include <unistd.h>

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

typedef struct point
{
    int obs_y;
    int visited;
} point;

int g_size_x;
int g_size_y;
char    g_empty;
char    g_obsticle;
char    g_full;

int    loops(point **tab);
int    find_square(int index_x, int index_y, point **tab);
void    print_board(int x, point **tab);
void    find_main(point **tab);

#endif