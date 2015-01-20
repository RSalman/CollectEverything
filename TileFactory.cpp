#include "TileFactory.h"
#include <time.h>

// Authors: Sarmad Hashmi (7249729) and Salman Rana (7395721)
// Project Assignment
// Professor: Jochen Lang
// Course: CSI2372

TileFactory::TileFactory(int _nTiles) {	
	int id = 0;
	tiles = new std::vector<Tile*>();	
	int nonDesertTilesEach = _nTiles/14;	
	int tileIndex = 0;
	Tile* t;
	for (int i = 0; i < 13; i++) {				
		for (int j = 0; j < nonDesertTilesEach; j++) {
				t = getTileFromInteger(i+1);							
			tiles->push_back(t);
		};									
	};				
	for (int i = 0; i < (_nTiles - (nonDesertTilesEach*13)); i++) {
		tiles->push_back(new Desert());
	};
};

TileFactory* TileFactory::get(int _nTiles) {
	static TileFactory tf(_nTiles); 
	return &tf;
}

Tile* TileFactory::next() {
	srand(time(NULL));
	int random = rand() % tiles->size();	
	Tile* t = (*tiles)[random];		
	tiles->erase(tiles->begin() + random);		
	return t;
};

Tile* TileFactory::getTileFromInteger(int i, int purchasedRubies) {	
	Tile* t;
	switch(i) {
		default:
		case 0:
			t = new Desert();
			break;
		case 1:					
			t = new Restaurant();
			break;
		case 2:
			t = new SpiceMerchant();
			break;
		case 3:
			t = new FabricManafacturer();
			break;
		case 4:
			t = new Jeweler();
			break;
		case 5:
			t = new CartManafacturer();
			break;
		case 6:
			t = new SmallMarket();
			break;
		case 7:
			t = new SpiceMarket();
			break;
		case 8:
			t = new JewelryMarket();
			break;
		case 9:
			t = new FabricMarket();
			break;
		case 10:
			t = new BlackMarket();
			break;
		case 11:
			t = new Casino();
			break;
		case 12:
			t = new GemMerchant();
			t->setPurchasedRubies(purchasedRubies);
			break;
		case 13:
			t = new Palace();
			break;
	};		
	return t;
};