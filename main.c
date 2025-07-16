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
            continue ;
        }
        printf("%d %d\n", g_size_x, g_size_y);
        print_map(map, g_size_x, g_size_y);
        //copy board

        printf("aaaaaaaaaaaaaa");
        find_main(map);
        free_map(map, g_size_y);
        k++;
    }
    /*if (argc == 1)
    {
        
    }*/
}