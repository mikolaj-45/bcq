#include <stdio.h>
#include "functions.h"
#include "point.h"

int g_size;
int g_dist_x;
int g_dist_y;

void    find_obs(point **t)
{
    int i;
    int j;
    int k;

    i = 0;
    //printf("ccc\n");
    while (i < g_size_y)
    {
        j = 0;
        while (j < g_size_x)
        {
            //printf("ddd\n");
            if (t[i][j].visited == -1)
                t[i][j].obs_y = -1;
            else
            {
                k = 1;
                while ((i + k) < g_size_y && t[i + k][j].visited != -1)
                {
                    k++;
                }
                t[i][j].obs_y = k;
            }
            //printf("obs = %d", k);
            j++;
        }
        //printf("\n");
        i++;
    }
}

void    loops(point **tab)
{
    int     i;
    int     j;
    int     current;

    i = 0;
    while (i < g_size_y)
    {
    j = 0;
        while (j < g_size_x)
        {
            if (tab[i][j].visited == 0)
            {
                printf("loop %d - %d\n", i, j);
                find_square(j, i, tab);
            }
            j++;
        }
        i++;
    }
}

void    find_square(int index_x, int index_y, point **tab)
{
    int y_min;
    int d_x;
    int d_y;
    int x;
    int i;
    int j;

    x = 0;
    y_min = 1000000000;
    while (x < y_min && (x + index_x) < g_size_x && tab[index_y][index_x + x].visited == 0)
    {
        if (tab[index_y][index_x + x].obs_y < y_min)
            y_min = tab[index_y][index_x + x].obs_y;
        x++;
    }
    if (y_min < x)
        x--;
    i = 0;
    d_x = index_x;
    d_y = index_y;
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
    if (x > g_size || (x == g_size && d_x < g_dist_x) || (x == g_size && d_x == g_dist_x && d_y < g_dist_y))
    {
        printf("x = %d, dist x = %d, dist y = %d\n", x, d_x, d_y);
        g_size = x;
        g_dist_x = d_x;
        g_dist_y = d_y;
    }
}

void    print_board(point **tab)
{
    printf("printing started\n");
    int i;
    int j;

    i = 0;
    while (i < g_size_y)
    {
        j = 0;
        //printf("i = %d\n", i);
        while (j < g_size_x)
        {
            //printf("j = %d, ", j);
            if (tab[i][j].visited == g_size && i < g_dist_y + g_size && i >= g_dist_y && j < g_dist_x + g_size && j >= g_dist_x)
            {
                //write(1, &g_full, 1);
                write(1, "x", 1);
            }
            else 
                if (tab[i][j].visited == -1)
                    write(1, "o", 1);
                else
                    write(1, ".", 1);
            j++;
        }
        write(1, "\n", 1);
        i++;
    }
}

void    find_main(point **tab)
{
    g_size = 0;
    g_dist_x = 0;
    g_dist_y = 0;
    printf("bbb\n");
    find_obs(tab);
    loops(tab);
    printf("loops finished\n");
    printf("x = %d, dist x = %d, dist y =%d\n", g_size, g_dist_x, g_dist_y);
    for (int i = 0; i < g_size_y; i++){
        for(int j = 0; j< g_size_x; j++)
            printf("%d ", tab[i][j].visited);
        printf("\n");
    }
    print_board(tab);
}