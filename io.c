#define BUF_SIZE 10000
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include "functions.h"
#include "point.h"

int     g_size_x;
int     g_size_y;
char    g_empty;
char    g_obsticle;
char    g_full;

static int	read_file_to_buffer(char *filename, char *buffer)
{
	int	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (-1);
	int bytes = read(fd, buffer, BUF_SIZE - 1);
	if (bytes < 0) {
		close(fd);
		return (-1);
	}
	buffer[bytes] = '\0';
	close(fd);
	return (0);
}

point **readmap(char *filename)
{
    int x;
	int y;

	x = 0;
	y = 0;
	char	buffer[BUF_SIZE];
    if (read_file_to_buffer(filename, buffer) == -1)
        return NULL;

    int i = 0;
    while (buffer[i] && buffer[i] != '\n') i++;
    if (i < 4) return NULL;

    int config_len = i;
    char full = buffer[config_len - 1];
    char obstacle = buffer[config_len - 2];
    char empty = buffer[config_len - 3];

    char lines_str[16] = {0};
    for (int j = 0; j < config_len - 3 && j < 15; j++)
        lines_str[j] = buffer[j];
    int lines = atoi(lines_str);
    if (lines <= 0) return NULL;
    g_size_y = lines;

    int pos = i + 1;
    int columns = 0;
    while (buffer[pos + columns] && buffer[pos + columns] != '\n')
        columns++;
    g_size_x = columns;
	point **map = malloc(sizeof(point *) * lines);
    if (!map) return NULL;
    while (y < lines) {
        int row_columns = 0;
        while (buffer[pos + row_columns] && buffer[pos + row_columns] != '\n')
            row_columns++;
        if (row_columns != g_size_x)
            return NULL;

        map[y] = malloc(sizeof(point) * g_size_x);
        if (!map[y]) return NULL;
		x = 0;
        while (x < columns)
		{
            char c = buffer[pos++];
            if (c != empty && c != obstacle && c != full)
                return NULL;

            map[y][x].obs_y = (c == obstacle) ? 1 : 0;
            if (c == empty)
                map[y][x].visited = 0;
            else if (c == obstacle)
                map[y][x].visited = -1;
			x ++;
        }
        if (buffer[pos] == '\n') pos++;
        y++;
    }
    return map;
}

void free_map(point **map, int lines)
{
	int i;

	i = 0;
	if (!map) return;
	while (i < lines && map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}
