#include "Player.h"
#include <iostream>
#include <string>

// Authors: Sarmad Hashmi (7249729) and Salman Rana (7395721)
// Project Assignment
// Professor: Jochen Lang
// Course: CSI2372

ostream& operator<<(ostream &_os, const Player &_p) {
	_os <<  _p._x << "\t" << _p._y << "\t" << _p._name << "\t" << _p._gold << "\t" << _p._ruby << "\t" << _p._spice << "\t";
	_os << _p._fabric << "\t" << _p._jewel << "\t" << _p._food << "\t" << _p._cart << "\t" << _p._currentCartN;
	return _os;
}

istream& operator>>(istream &_is, Player&_p) {
	_is >> _p._x >> _p._y >> _p._name >> _p._gold >> _p._ruby >> _p._spice >> _p._fabric >> _p._jewel >> _p._food >> _p._cart >> _p._currentCartN;
	return _is;
}
bool Player::canAct() const {
	return _food > 0;
}

bool Player::pay(Player &player) {
	if (_gold > 0) {				
		player.incrementGold(1);
		_gold--;
		return true;
	}
	return false;
}

void Player::eat() {
	if (_food > 0) {	
		_food--;		
	}	
}

void Player::display() {	
	cout << "\t \t \t \t"<<_name << "'s Turn" << endl;
	cout << "Jewels: " << _jewel << "\t" << "Fabric: " << _fabric << endl << "Spices: " << _spice << "\t" << "Gold: " << _gold << endl << "Ruby: " << _ruby << "\t\t" << "Food: " << _food << endl << "Cart Capacity: " << _cart << endl << "Items in Cart: " << _currentCartN << endl;
	cout << endl;
}

string Player::getName() const{
	return _name;
}

int Player::getFood() {
	return _food;
}

bool Player::incrementCart(int x) {	
	_cart += x;
	return true;
}

bool Player::setFood(int x) {	
	if (x < 0) {
		return false;
	}	
	_food = x;
	return true;
}

bool Player::incrementGold(int x) {	
	_gold += x;
	return true;
}
void Player::incrementRuby(int x) {	
	if (_currentCartN+x > _cart) {		
		_ruby = _ruby + (_cart - _currentCartN);
		_currentCartN = _cart;		
	}
	else if(_currentCartN+x < 0) {
		_currentCartN = 0;
		_ruby = 0;
	}
	else {
		_currentCartN += x;
		_ruby += x;	
	}
}
void Player::incrementSpice(int x) {
	if (_currentCartN+x > _cart) {		
		_spice = _spice + (_cart - _currentCartN);
		_currentCartN = _cart;		
	}
	else if(_currentCartN+x < 0) {
		_currentCartN = 0;
		_spice = 0;
	}
	else {
		_currentCartN += x;
		_spice += x;	
	}
}
void Player::incrementFabric(int x) {
	if (_currentCartN+x > _cart) {		
		_fabric = _fabric + (_cart - _currentCartN);
		_currentCartN = _cart;		
	}
	else if(_currentCartN+x < 0) {
		_currentCartN = 0;
		_fabric = 0;
	}
	else {
		_currentCartN += x;
		_fabric += x;	
	}
}
void Player::incrementJewel(int x) {
	if (_currentCartN+x > _cart) {		
		_jewel = _jewel + (_cart - _currentCartN);
		_currentCartN = _cart;		
	}
	else if(_currentCartN+x < 0) {
		_currentCartN = 0;
		_jewel = 0;
	}
	else {
		_currentCartN += x;
		_jewel += x;	
	}
}
int Player::getGold() {
	return _gold;
}
int Player::getRuby() {
	return _ruby;
}
int Player::getSpice() {
	return _spice;
}
int Player::getFabric() {
	return _fabric;
}
int Player::getJewel() {
	return _jewel;
}
int Player::getX() const {
	return _x;
}
int Player::getY() const {
	return _y;
}
void Player::setX(int x) {
	_x = x;
}
void Player::setY(int y) {
	_y = y;
}

