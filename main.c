#include "point.h"
#include "functions.h"
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char **argv)
{
    int k;

    k = 1;
    while (k < argc)
    {
        if (k != 1)
            write(1, "\n", 1);
        point **map = readmap(argv[k]);
        if (!map)
        {
            write(1, "map error\n", 10);
            k++;
            continue;
        }
        int i;
        int j;
        i = 0;
        j = 0;
        printf("%d %d\n", g_size_x, g_size_y);
        while (i < g_size_y)
        {
            j = 0;
            while (j < g_size_x)
            {
                if (map[i][j].visited == -1)
                    write(1, "o", 1);
                else
                    write(1, ".", 1);
                j++;
            }
            write(1, "\n", 1);
            i++;
        }
        //copy board

        //find_main();
        free_map(map, g_size_y);
        k++;
    }
    /*if (argc == 1)
    {
        
    }*/
}