#ifndef INCLUDE_MAP_H
#define INCLUDE_MAP_H

typedef struct Grid
{
	unsigned int id;
	int x;
	int y;

	int obstracle;
	char obstracle_class;

	int occupied;
}Grid;

int loadMap(char* map);

#endif
