#define BUF_SIZE 10000

point   *readmap( char *filename)
{
    int fd = open(filename, O_RDONLY);
    if (fd < 0)
    {
        return NULL;        
    }
}

static int	read_file_to_buffer(char *filename, char *buffer)
{
	int	fd;
	int	bytes;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (-1);
	bytes = read(fd, buffer, BUF_SIZE - 1);
	if (bytes < 0) {
		close(fd);
		return (-1);
	}
	buffer[bytes] = '\0';
	close(fd);
	return (0);
}

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define BUF_SIZE 10000

typedef struct point
{
	int obs_y;     // 1 = obstacle, 0 = empty
	int visited;
} point;

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

point **readmap(char *filename, int *out_lines, int *out_cols)
{
	char	buffer[BUF_SIZE];
	if (read_file_to_buffer(filename, buffer) == -1)
		return NULL;

	// 1. Odczyt konfiguracji
	int i = 0;
	while (buffer[i] && buffer[i] != '\n') i++;
	if (i < 4) return NULL;

	// Znaki konfiguracyjne
	char full = buffer[i - 1];
	char obstacle = buffer[i - 2];
	char empty = buffer[i - 3];

	int lines = atoi(buffer[0]);
	if (lines <= 0) return NULL;

	*out_lines = lines;

	int row = 0;
	int pos = i + 1;
	int columns = 0;

	while (buffer[pos + columns] && buffer[pos + columns] != '\n')
		columns++;

	*out_cols = columns;

	// Alokacja dwuwymiarowej tablicy
	point **map = malloc(sizeof(point *) * lines);
	if (!map) return NULL;
	for (int y = 0; y < lines; y++) {
		map[y] = malloc(sizeof(point) * columns);
		if (!map[y]) return NULL;

		for (int x = 0; x < columns; x++) {
			char c = buffer[pos++];
			if (c != empty && c != obstacle && c != full)
				return NULL;

			map[y][x].obs_y = (c == obstacle) ? 1 : 0;
			map[y][x].visited = 0;
		}
		if (buffer[pos] == '\n') pos++;
	}

	return map;
}

void free_map(point *map)
{
	if (!map) return;
	for (int i = 0; i < map->lines; i++)
		free(map->map[i]);
	free(map->map);
	free(map);
}
