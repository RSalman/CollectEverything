#ifndef TILEFACTORY_H
#define TILEFACTORY_H
#include "Tile.h"

// Authors: Sarmad Hashmi (7249729) and Salman Rana (7395721)
// Project Assignment
// Professor: Jochen Lang
// Course: CSI2372


class TileFactory {
private:
	std::vector<Tile*>* tiles;	
public:
	TileFactory(int n_Tiles);
	static TileFactory* get(int _nTiles);
	Tile* next();
	static Tile* getTileFromInteger(int i, int purchasedRubies = 0);
};
#endif