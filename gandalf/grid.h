#ifndef __GRID_H__
#define __GRID_H__

typedef struct Tile {
	int active; /* So you can mark as unreachable to make more complex patterns */
	int explored;
	struct Tile * north;
	struct Tile * west;
	struct Tile * south;
	struct Tile * east;
} Tile;

typedef  struct Grid {
	Tile * first; /* First tile of the grid, the top left tile */
	Tile * origin; /* Origin of the exploration */
} Grid;

Tile * newTile( int active , Tile * north, Tile * west, Tile * south, Tile * east);
Grid * newGrid( int width, int heigth, int randomizeState, int randomizeOrigin);
void freeTile(Tile * tile);
void freeGrid(Grid * grid);

#endif
