#include "Tile.h"
#include <string>

// Authors: Sarmad Hashmi (7249729) and Salman Rana (7395721)
// Project Assignment
// Professor: Jochen Lang
// Course: CSI2372


ostream& operator<<(ostream &_os, const Tile &_t) {
	_os << _t.tileType << "\t" << _t.purchasedRubies;	
	return _os;
}

bool Tile::action(Player &player) {
	return true;
};

Tile* Tile::clone() const {
	return new Tile(*this);
};

int Tile::getTileType() {
	return tileType;
};

int Tile::getTileID() {
	return tileID;
};

bool Tile::operator==(const Tile &t) const{
	if (t.tileID == tileID)
		return true;
	return false;
}

bool Restaurant::action(Player &player) {
	player.setFood(10);	
	return true;
};

bool SpiceMerchant::action(Player &player) {
	int pGold = player.getGold();
	int pSpice = player.getSpice();
	if ( pGold > 2) {
		player.incrementGold(-2);
		player.incrementSpice(3);
		return true;
	}
	return false;
};

bool FabricManafacturer::action(Player &player) {
	int pGold = player.getGold();
	int pFabric = player.getFabric();
	if ( pGold > 2) {
		player.incrementGold(-2);
		player.incrementFabric(3);
		return true;
	}
	return false;
};

bool Jeweler::action(Player &player) {
	int pGold = player.getGold();
	int pJewel = player.getJewel();
	if ( pGold > 2) {
		player.incrementGold(-2);
		player.incrementJewel(3);
		return true;
	}
	return false;
};

bool CartManafacturer::action(Player &player) {
	int pGold = player.getGold();	
	if ( pGold > 7) {
		player.incrementGold(-7);
		player.incrementCart(3);
		return true;
	}
	return false;
};

bool SmallMarket::action(Player &player) {
	int pFabric = player.getFabric();	
	int pJewel = player.getJewel();	
	int pSpice = player.getSpice();	
	if (pFabric >= 1 && pJewel >= 1 && pSpice >= 1) {
		player.incrementGold(8);
		player.incrementFabric(-1);
		player.incrementJewel(-1);
		player.incrementSpice(-1);		
		return true;
	}
	return false;
};

bool SpiceMarket::action(Player &player) {	
	int pSpice = player.getSpice();	
	if (pSpice >= 3) {
		player.incrementGold(6);		
		player.incrementSpice(-3);		
		return true;
	}
	return false;
};


bool JewelryMarket::action(Player &player) {
	int pJewel = player.getJewel();	
	if (pJewel >= 3) {
		player.incrementGold(6);		
		player.incrementJewel(-3);		
		return true;
	}
	return false;
};

bool FabricMarket::action(Player &player) {
	int pFabric = player.getFabric();	
	if (pFabric >= 3) {
		player.incrementGold(6);		
		player.incrementFabric(-3);		
		return true;
	}
	return false;
};

bool BlackMarket::action(Player &player) {
	int pGold = player.getGold();		
	if (pGold >= 1) {
		player.incrementGold(-1);
		int ranNums[4];		
		int sum = -1;
		while (!(sum >= 0 && sum <= 5)) {				
			sum = 0;
			for(int i = 0; i < 4; i++)	{
				ranNums[i] = rand() % 6;				
				sum += ranNums[i];				
			}					
		}
		player.incrementFabric(ranNums[0]);
		player.incrementJewel(ranNums[1]);
		player.incrementSpice(ranNums[2]);
		player.incrementRuby(ranNums[3]);		
		return true;
	}
	return false;
};

bool Casino::action(Player &player) {
	int pGold = player.getGold();		
	if (pGold >= 1) {
		player.incrementGold(-1);			
		int randomN = rand() % 10 + 1;		
		if (randomN >= 1 && randomN <= 4) {
			// do nothing
		}
		else if (randomN >= 5 &&  randomN <= 7) {
			player.incrementGold(2);		
		}
		else if (randomN == 8 ||  randomN == 9) {
			player.incrementGold(3);		
		}
		else if (randomN == 10) {
			player.incrementGold(10);
		}
		return true;
	}
	return false;
};

int Tile::getPurchasedRubies() {
	if (tileType == 12) {
		return purchasedRubies;
	}
	return 0;
}

void Tile::setPurchasedRubies(int x) {
	if (tileType == 12) {
		purchasedRubies = x;
	}
}

bool GemMerchant::action(Player &player) {
	int pGold = player.getGold();
	if (pGold >= purchasedRubies+12) {
		player.incrementGold(-(purchasedRubies+12));
		player.incrementRuby(1);
		purchasedRubies++;
		return true;
	}	
	return false;
};

bool Palace::action(Player &player) {
	int pFabric = player.getFabric();
	int pJewel = player.getJewel();
	int pSpice = player.getSpice();
	if (pFabric >= 5 && pJewel >= 5 && pSpice >= 5) {		
		player.incrementFabric(-5);
		player.incrementJewel(-5);
		player.incrementSpice(-5);
		player.incrementRuby(1);
		return true;
	}	
	return false;
};


void Tile::display() {	
	cout << "Desert";
};

void Restaurant::display() {	
	cout << "Restaurant";
};

void SpiceMerchant::display() {
	cout << "Spice Merchant";
};

void FabricManafacturer::display() {	
	cout << "Fabric Manafacturer";
};

void Jeweler::display() {
	cout << "Jeweler";
};

void CartManafacturer::display() {
	cout << "Cart Manafacturer";
};

void SmallMarket::display() {	
	cout << "Small Market";
};

void SpiceMarket::display() {	
	cout << "Spice Market"; 
};

void JewelryMarket::display() {	
	cout << "Jewelry Market";
};

void FabricMarket::display() {
	cout << "Fabric Market";
};

void BlackMarket::display() {
	cout << "Black Market";
};

void Casino::display() {
	cout << "Casino";	
};

void GemMerchant::display() {
	cout << "Gem Merchant";
};

void Palace::display() {
	cout << "Palace";
};

void Tile::displayAction() {	
	cout << "No action can be taken on this tile.";
};

void Restaurant::displayAction() {	
	cout << "Food replenished to 10.";
};

void SpiceMerchant::displayAction() {
	cout << "For 2 pieces of gold, a player can purchase 3 sacks of spices (less if the player does not have a capacity in his/her cart).";
};

void FabricManafacturer::displayAction() {	
	cout << "For 2 pieces of gold, the player gets three rolls of fabrics tissues (less if the player does not have a capacity in his/her cart).";
};

void Jeweler::displayAction() {
	cout << "For 2 pieces of gold, the player gets 3 pieces of jewelry (less if the player does not have a capacity in his cart).";
};

void CartManafacturer::displayAction() {
	cout << "For 7 pieces of gold, the capacity of the cart is increased by 3.";
};

void SmallMarket::displayAction() {	
	cout << "Sell 1 roll of fabric, 1 jewel and 1 sack of spices for 8 pieces of gold.";
};


void SpiceMarket::displayAction() {	
	cout << "Sell 3 sacks of spices for 6 pieces of gold."; 
};

void JewelryMarket::displayAction() {	
	cout << "Sell 3 pieces of jewelry for 6 pieces of gold.";
};

void FabricMarket::displayAction() {
	cout << "Sell 3 rolls of fabrics for 6 pieces of gold. ";
};

void BlackMarket::displayAction() {
	cout << "For 1 piece of gold, a player can get between 0 and 5 goods at random (less if the player does not have a capacity in his/her cart).";
};

void Casino::displayAction() {
	cout << "For 1 piece of gold, the player has 2 in 5 chance to loose, i.e., win 0 pieces of gold, a 3 ";
	cout << "out of 10 chance to get 2 pieces of gold, a 2 out of 10 chance to get 3 pieces of gold and a 1 in 10 " ;
	cout << "chance to win 10 pieces of gold.";
};

void GemMerchant::displayAction() {
	cout << "Buy a ruby for " << purchasedRubies+12 << " gold." << endl;
};

void Palace::displayAction() {
	cout << "Exchange 5 rolls of fabrics, 5 pieces of jewelry and 5 sacks of spices for 1 ruby." << endl;
};

Restaurant* Restaurant::clone() const {
	return new Restaurant(*this);
};

Jeweler* Jeweler::clone() const {
	return new Jeweler(*this);
};

SpiceMarket* SpiceMarket::clone() const {
	return new SpiceMarket(*this);
};

GemMerchant* GemMerchant::clone() const {
	return new GemMerchant(*this);
};

Palace* Palace::clone() const {
	return new Palace(*this);
};

SpiceMerchant* SpiceMerchant::clone() const {
	return new SpiceMerchant(*this);
};

FabricManafacturer* FabricManafacturer::clone() const {
	return new FabricManafacturer(*this);
};

CartManafacturer* CartManafacturer::clone() const {
	return new CartManafacturer(*this);
};

SmallMarket* SmallMarket::clone() const {
	return new SmallMarket(*this);
};

JewelryMarket* JewelryMarket::clone() const {
	return new JewelryMarket(*this);
};

FabricMarket* FabricMarket::clone() const {
	return new FabricMarket(*this);
};

BlackMarket* BlackMarket::clone() const {
	return new BlackMarket(*this);
};

Casino* Casino::clone() const {
	return new Casino(*this);
};