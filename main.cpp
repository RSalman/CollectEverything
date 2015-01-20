#include "Player.h"
#include "Tile.h"
#include "TileFactory.h"
#include "GameBoard.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

// Authors: Sarmad Hashmi (7249729) and Salman Rana (7395721)
// Project Assignment
// Professor: Jochen Lang
// Course: CSI2372



#include "GameBoard.h"
using namespace std;
int Tile::staticTileID = 1;
template <const int N>
bool takeTurn(GameBoard<Tile, Player, N, N> &bg, const string &pName);
int main(void) {		
	vector<Player> players;
	vector<string> playerNames;
	GameBoard<Tile, Player, 6, 6>* bg = new GameBoard<Tile, Player, 6, 6>();
	string tempName;		
	int nPlayers;
	bool gamePausedPressed = false;
	bool flag = true;
	bool load = true;
	bool hasWon = false;
	bool validKey = false;
	bool loaded = false;
	string yOrN;
	
	// ask if load previously saved game	
	while (!validKey) {				
		cout << "Load previously saved game? (y/n)";
		cin >> yOrN;
		if (yOrN == "y") {
			validKey = true;

			// load defaults to true
		}
		else if (yOrN == "n") { 
			validKey = true;
			load = false;		
		}		
	}

	// get num of players if not load selected
	if (!load) {

		do {				
			cout << "Enter the number of players: ";						
			cin.clear();			
			cin.ignore(256, '\n');
			cin >> nPlayers;							
		} while (cin.fail());
		cin.clear();
		cin.ignore(256, '\n');
		for (int i = 0; i < nPlayers; i++) {
			cout << "Please enter the name of Player " << i+1 << ": ";
			cin >> tempName;
			players.push_back(Player(tempName));			
			playerNames.push_back(tempName);
		};					
		bg = new GameBoard<Tile, Player, 6, 6>(players);
		TileFactory* tf = TileFactory::get(6*6);
		Tile startTile;
		int startX = 0, startY = 0;
		for (int i = 0; i < 6; i++) {
			for (int  j = 0; j < 6; j++) {
				bg->add(*tf->next(), i, j);
				startTile = bg->getTile(i, j);
				if (startTile.getTileType() == 1) {
					startX = i;
					startY = j;
				}

			}
		}						
		vector<Player> tempPlayers = bg->getPlayers();		
		for (int i = 0; i < tempPlayers.size(); i++) {
			tempPlayers[i].setX(startX);
			tempPlayers[i].setY(startY);
			bg->setPlayer(tempPlayers[i]);
		}
		cout << endl;		
	}
	else {
		// load game
		ifstream infile;
		infile.open("data.txt");
		if (!infile.good()) {
			cout << "No previous save exists. Exiting..." << endl;
			system("pause");
			return 0;
		}
		GameBoard<Tile, Player, 6, 6> temp;
		infile >> *bg;					
		infile.close();	
	}

	// game loop	
	while (!hasWon){
		if (gamePausedPressed) {
			cout << string( 100, '\n' );
			cout << "Pausing.." << endl;
			cout << "Saving game..." << endl;
			ofstream outfile;
			outfile.open("data.txt");
			outfile << *bg;	
			outfile.close();
			cout << "Saved!" << endl;
			cout << "You may now close the game, or press any key to resume your game." << endl;
			std::system("pause");
			gamePausedPressed = false;
			loaded = false;
		}
		players = bg->getPlayers();		

		int p = 0;
		if (!loaded && load) {
			p = bg->getCurrentPlayer();
			loaded = true;
		}
		for (p; p < players.size(); p++){			
			bg->setCurrentPlayer(p);
			cout <<"********************************CURRENT STATS***********************************";
			players[p].display();									
			bg->print(players[p].getName());			
			gamePausedPressed = takeTurn<6>(*bg, players[p].getName());						
			cout <<"********************************UPDATED STATS***********************************";						
			players = bg->getPlayers();
			players[p].display();									
			bg->print(players[p].getName());
			if (gamePausedPressed) break;
			players[p] = bg->getPlayer(players[p].getName());
			if (players[p].getRuby() >= 5){
				hasWon = true;
				cout << players[p].getName() << " has won the game!" << endl;					
				break;
			}			
			system("pause");
		}
	}	
	system("pause");
}

template <const int N>
bool takeTurn(GameBoard<Tile, Player, N, N> &bg, const string &pName){
	string move;
	Move selectedMove = Move::NONE; // default	
	bool validMove = false;
	bool doAction;
	string action;

	do{

		cout << "Please enter a move. (Up (U) / Down (D) / Right (R) / Left (L) / Pause (P)) " << endl;
		cin >> move;		
		move = move.at(0);
		if (move == "U" || move == "u"){
			selectedMove = Move::UP;
			validMove = true;
		}
		else if (move == "D" || move == "d"){
			selectedMove = Move::DOWN;
			validMove = true;
		}
		else if (move == "L" || move == "l"){
			selectedMove = Move::LEFT;
			validMove = true;
		}
		else if (move == "R" || move == "r"){
			selectedMove = Move::RIGHT;			
			validMove = true;	
		}
		else if (move == "P" || move == "p") {
			return true;
		}	
		try{ 
			bg.move(selectedMove, pName); }
		catch (exception e){
			cout << "Invalid move" << endl;
			validMove = false;
		}
	} while (!validMove);


	Tile* playerTile = bg.getTile(pName).clone();		
	Player player = bg.getPlayer(pName);	
	// action automatically performed on desert or restaurant
	if (playerTile->getTileType() <= 1) {
		cout << "You have landed on a ";
		playerTile->display();
		cout << endl << endl;		
		playerTile->displayAction();
		cout << endl << endl;		
		playerTile->action(player);			
		bg.setPlayer(player);
		return false;
	}

	if (player.canAct()){		
		cout << endl;
		cout << "You have landed on a ";
		playerTile->display();
		cout << " tile. You can do the following action: " << endl;
		playerTile->displayAction();
		cout << endl << endl;		
		cout << "Would you like to do the action? (Y or N)" << endl;
		cin >> action;
		action = action.at(0);
		if (action == "n" || action == "N" ) // Do the action if and only if player wants to do the action
			doAction = false;
		else
			doAction = true;
	}	

	if (doAction){
		vector<Player> opL = bg.getPlayers(*playerTile);			
		if (player.getGold() >= opL.size()) {
			player.eat();				
			for (int i = 0; i < opL.size(); i++) {
				if (player.getName() != opL[i].getName()) {															
					player.pay(opL[i]);
					bg.setPlayer(opL[i]);
				}
			}				
			if (playerTile->action(player))
				cout << "Action performed!" << endl;
			else
				cout << "Can not do action!" << endl;				
		}
		bg.setPlayer(player);
	}					
	bg.add(*playerTile, player.getX(), player.getY()); // update tile in game board
	return false;
}