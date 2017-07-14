#include "grid.h"

Tile * newTile( int active , Tile * north, Tile * west, Tile * south, Tile * east)
{
	Tile * tile = (*Tile)malloc(sizeof(Tile));
	if (tile == NULL) {
		return NULL;
	}

	tile->active = active;
	tile->explored = 0;
	tile->north = north;
	tile->west = west;
	tile->south = south;
	tile->east = east;
	
	return tile;
}
Grid * newGrid( int width, int heigth, int randomizeState, int randomizeOrigin)
{
	Grid *grid = NULL;

	/* Just got bored. U know... summer */
}
void freeTile(Tile * tile);
void freeGrid(Grid * grid);

