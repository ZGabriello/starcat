#ifndef _TERRAIN_H
#define _TERRAIN_H

typedef struct
{
	int dimx;
	int dimy;
	char **tab;
} Terrain;

void InitialiserTerrain(Terrain *);

void LibererTerrain(Terrain *);

int TestPositionValide(const Terrain *, const int x, const int y);

const char GetTerrainXY(const Terrain *, const int x, const int y);

void SetTerrainXY(const Terrain *, const int x, const int y, const char);

const int GetDimX(const Terrain *);

const int GetDimY(const Terrain *);

#endif
