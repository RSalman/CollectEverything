#ifndef TILE_H
#define TILE_H
#include <iostream>
#include <vector>
#include "Player.h"

// Authors: Sarmad Hashmi (7249729) and Salman Rana (7395721)
// Project Assignment
// Professor: Jochen Lang
// Course: CSI2372

using namespace std;
class Tile;
ostream& operator<<(ostream& _os, const Tile& _t);
class Tile {
protected:
	int purchasedRubies;
	int tileType;
	static int staticTileID;
	int tileID;
private:
	friend ostream& operator<<(ostream& _os, const Tile& _t);		
public:		
	Tile(int type = 0) : purchasedRubies(0), tileType(type) { tileID = staticTileID++; };
	int getTileType();	
	int getTileID();
	bool operator==(const Tile &t) const;
	virtual Tile* clone() const;		
	virtual bool action(Player &player);	
    virtual void displayAction();
	virtual void display();     
	void setPurchasedRubies(int x);
	int getPurchasedRubies();
};

class Desert : public Tile {
public:
	Desert() : Tile(0) {};
};

class Restaurant : public Tile {
public:
	Restaurant() : Tile(1) {};
	bool action(Player &player);
	void display(); 
    void displayAction();
	Restaurant* clone() const;
};

class SpiceMerchant : public Tile {
public:
	SpiceMerchant() : Tile(2) {};
	bool action(Player &player);
	void display(); 
    void displayAction();
	SpiceMerchant* clone() const;
};

class FabricManafacturer : public Tile {
public:
	FabricManafacturer() : Tile(3) {};
	bool action(Player &player);
	void display(); 
    void displayAction();
	FabricManafacturer* clone() const;
};

class Jeweler : public Tile {
public:
	Jeweler() : Tile(4) {};
	bool action(Player &player);
	void display(); 
    void displayAction();
	Jeweler* clone() const;
};

class CartManafacturer : public Tile {
public:
	CartManafacturer() : Tile(5) {};
	bool action(Player &player);
	void display(); 
    void displayAction();
	CartManafacturer* clone() const;
};

class SmallMarket : public Tile {
public:
	SmallMarket() : Tile(6) {};
	bool action(Player &player);
    void display(); 
    void displayAction();
	SmallMarket* clone() const;
};

class SpiceMarket : public Tile {
public:
	SpiceMarket() : Tile(7) {};
	bool action(Player &player);
	void display(); 
    void displayAction();
	SpiceMarket* clone() const;
};

class JewelryMarket : public Tile {
public:
	JewelryMarket() : Tile(8) {};
	bool action(Player &player);
	void display(); 
    void displayAction();
	JewelryMarket* clone() const;
};

class FabricMarket : public Tile {
public:
	FabricMarket() : Tile(9) {};
	bool action(Player &player);
	void display(); 
    void displayAction();
	FabricMarket* clone() const;
};

class BlackMarket : public Tile {
public:
	BlackMarket() : Tile(10) {};
	bool action(Player &player);
	void display(); 
    void displayAction();
	BlackMarket* clone() const;
};

class Casino : public Tile {	
public:
	Casino() : Tile(11) {};
	bool action(Player &player);
	void display(); 
    void displayAction();
	Casino* clone() const;
};

class GemMerchant : public Tile {	
public:
	GemMerchant() : Tile(12) {};	
	bool action(Player &player);
	void display(); 
    void displayAction();
	GemMerchant* clone() const;
};

class Palace : public Tile {
public:
	Palace() : Tile(13) {};
	bool action(Player &player);
	void display(); 
    void displayAction();
	Palace* clone() const;
};
#endif


