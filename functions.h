#include <stdio.h>
#include <unistd.h>

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

typedef struct point
{
    int obs_y;
    int visited;
} point;

int     g_size_x;
int     g_size_y;
char    g_empty;
char    g_obsticle;
char    g_full;

void    loops(point **tab, int max, int dist);
void    find_square(int index_x, int index_y, point **tab, int max, int dist);
void    print_board(int x, point **tab, int dist);
void    find_main(point **tab);

#endif