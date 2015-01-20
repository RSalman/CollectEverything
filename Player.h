#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
using namespace std;

// Authors: Sarmad Hashmi (7249729) and Salman Rana (7395721)
// Project Assignment
// Professor: Jochen Lang
// Course: CSI2372


class Player;
ostream& operator<<(ostream& _os, const Player& _p);
istream& operator>>(istream& _is, Player& _p);
class Player {
	friend ostream& operator<<(ostream& _os, const Player& _p);
	friend istream& operator>>(istream& _is, Player& _p);
	string _name;	
	int _gold, _ruby, _spice, _fabric, _jewel, _cart, _food, _currentCartN, _x, _y;
public:	
	Player(string name = " ") : _gold(5), _ruby(0), _spice(1), _fabric(1), _jewel(1), _food(10), _cart(9), _currentCartN(3), _name(name), _x(0), _y(0) {};	
	bool canAct() const;
	bool pay(Player& player);
	void eat();
	void display();
	bool setFood(int x);
	bool incrementCart(int x);	
	bool incrementGold(int x);
	void incrementRuby(int x);
	void incrementSpice(int x);
	void incrementFabric(int x);
	void incrementJewel(int x);
	void setX(int x);
	void setY(int y);
	string getName() const;		
	int getGold();
	int getRuby();
	int getSpice();
	int getFabric();
	int getJewel();
	int getFood();
	int getX() const;
	int getY() const;
};
#endif
