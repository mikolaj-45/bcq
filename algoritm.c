#include <stdio.h>
#include "functions.h"
#include "point.h"

void    find_obs(point **t)
{
    int i;
    int j;
    int k;

    i = 0;
    printf("aaa");
    while (i < g_size_y)
    {
        j = 0;
        while (j < g_size_x)
        {
            if (t[i][j].visited == -1)
                t[i][j].obs_y = -1;
            else
            {
                k = 1;
                while (t[i + k][j].visited != -1 && (i + k) < g_size_y)
                    k++;
                t[i][j].obs_y = k;
                printf("obs = %d", t[i][j].obs_y);
            }
            j++;
        }
        i++;
        printf("\n");
    }
}

void    loops(point **tab, int *max, int *dist)
{
    int     i;
    int     j;
    int     current;

    i = 0;
    while (i < g_size_x)
    {
    j = 0;
        while (tab[i][j].visited != 0 && j < g_size_y)
        {
            find_square(i, j, tab, max, dist);
            j++;
        }
        i++;
    }
}

void    find_square(int index_x, int index_y, point **tab, int *max, int *dist)
{
    int y_min;
    int d;
    int x;
    int i;
    int j;

    x = 0;
    y_min = 1000000000;
    while (x < y_min && (x + index_x) < g_size_x && tab[index_x + x][index_y].visited == 0)
    {
        if (tab[index_y][index_x + x].obs_y < y_min)
            y_min = tab[index_y][index_x + x].obs_y;
        x++;
    }
    if (y_min < x)
        x--;
    i = 0;
    if(index_x > index_y)
        d = index_x;
    else
        d = index_y;
    while (i < x)
    {
        j = 0;
        while (j < x)
        {
            tab[j + index_y][i + index_x].visited = x;
            j++;
        }
        i++;
    }
    if (x > *max || (x == *max && d < *dist))
    {
        *max = x;
        *dist = d;
    }
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
    while (i < g_size_y)
    {
        j = start;
        while (j < g_size_x)
        {
            if (tab[i][j].visited == x && found == 0 && (dist == i || dist == j))
            {
                start = j;
                found++;
                write(1, &g_full, 1);
            }
            if (start != 0 && j - start < x)
                write(1, &g_full, 1);
            else 
                if (tab[i][j].visited == -1)
                    write(1, &g_obsticle, 1);
                else
                    write(1, &g_empty, 1);
            j++;
        }
        write(1, "\n", 1);
        i++;
    }
}

void    find_main(point **tab)
{
    int *size;
    int *dist;

    printf("aaa");
    loops(tab, size, dist);
    print_board(*size, tab, *dist);
}