#ifndef INCLUDE_MAP_H
#define INCLUDE_MAP_H

typedef struct Node
{
	unsigned int id;
	int x;
	int y;

	int obstracle;
	char obstracle_class;

	int occupied;
}Node;

int loadMap(char* map);

#endif
