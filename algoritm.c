#include <stdio.h>
#include "functions.h"

void    loops(point **tab, int max, int dist)
{
    int     i;
    int     j;
    int     max;
    int     current;
    int     dist;

    max = 0;
    i = 0;
    while (i < g_size_x)
    j = 0;
        while (tab[i][j].visited != 0 && j < g_size_y)
        {
            find_square(i, j, tab, &max, &dist);
            i++;
        }
}

void    find_square(int index_x, int index_y, point **tab, int max, int dist)
{
    int y_min;
    int y_min_pre;
    int x;
    int i;
    int j;

    x = 0;
    y_min = 1000000000;
    while (x < y_min && x + index_x < g_size_x && tab[index_x + x][index_y].visited == 0)
    {
        if (tab[index_x + x][index_y].obs_y < y_min)
            y_min = tab[index_x + x][index_y].obs_y;
        x++;
    }
    if (y_min < x)
        x--;
    i = 0;
    
    while (i < x)
    {
        j = 0;
        while (j < x)
        {
            tab[i + index_x][j + index_y].visited = x;
            j++;
        }
    }
    return (x);
}

void    print_board(int x, point **tab, int dist)
{
    int i;
    int j;
    int start;
    int found;

    i = 0;
    start = 0;
    found = 0;
    while (i < g_size_x)
    {
        j = start;
        while (j < g_size_y)
        {
            if (tab[i][j].visited == x && found == 0)
            {
                start = j;
                found++;
            }
            if (start != 0 && j - start < x)
                //wypisz pelne pole
                i += 0;
            else
                //wypisz pole
                i += 0;
            j++;
        }
        write(1, "\n", 1);
        i++;
    }
    write(1, )
}

void    find_main(point **tab)
{
    int size;
    int dist;

    loops(tab, size, dist);
    print_board(size, tab, dist);
}