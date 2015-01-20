#ifndef GAMEBOARD_H
#define GAMEBOARD_H
#include <vector>
#include <string>
#include <iostream>

// Authors: Sarmad Hashmi (7249729) and Salman Rana (7395721)
// Project Assignment
// Professor: Jochen Lang
// Course: CSI2372


using namespace std;
enum class Move {

	UP,DOWN,LEFT,RIGHT,NONE

};

template <class T,class  J, int row, int col>
class GameBoard;
template <class T,class  J, int row, int col>
ostream& operator<<(ostream& _os, const GameBoard<T,J,row,col>& _gb);
template <class T,class  J, int row, int col>
istream& operator>>(istream& _is, GameBoard<T,J,row,col>& _gb);

template <class T,class  J, int row, int col>
class GameBoard{
	template <class T,class  J, int row, int col> friend ostream& operator<<(ostream& _os, const GameBoard<T,J,row,col>& _gb);
	template <class T,class  J, int row, int col> friend istream& operator>>(istream& _is, GameBoard<T,J,row,col>& _gb);		
	T* board[row][col]; //Holds all the tiles 2D
	vector<J> players; //Holds all the players		
	int currentPlayer;
	public:
		GameBoard();
		GameBoard(vector<J> _noplayers);
		void add(const T& tile, int row, int col);
		const T& getTile(int row, int col) const;
		void getCoordinate(const T &tile, int *row, int *col)const;
		void setPlayer(J player);
		J getPlayer(const string& playerName) const;
		const T& getTile(const string& playerName) const;	
		vector<J> getPlayers(const T& tile) const;
		vector<J> getPlayers() const;
		int getCurrentPlayer() const;
		void setCurrentPlayer(int x);
		const T& move(Move move, const string& playerName);
		void print();
		void print(string _playerName);
};

template <class T,class  J, int row, int col>
ostream& operator<<(ostream& _os, const GameBoard<T,J,row,col>& _gb) {	
	_os << row <<  "\t" << col << "\t" << _gb.players.size() << "\t" << _gb.currentPlayer << endl;	
	for (J p: _gb.players) {
		_os << p << endl;
	}
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < row; j++) {
			_os << i << "\t" << j << "\t" << *_gb.board[i][j] << endl;
		}
	}
	return _os;
};


template <class T,class  J, int row, int col>
istream& operator>>(istream& _is, GameBoard<T,J,row,col>& _gb) {		
	string line;			
	getline(_is, line);
	istringstream ss;
	ss.str(line);
	int nPlayers, nRows, nCols, currentPlayer;
	ss >> nRows >> nCols >> nPlayers >> currentPlayer;
	int  i = 0, x, y, tileType, purchasedRubies;	
	_gb.players.clear();	
	J p;
	while (i < nPlayers) {
		getline(_is, line);
		ss.str(line);	
		ss.clear();
		ss >> p;						
		_gb.players.push_back(p);
		i++;
	};
	_gb.currentPlayer = currentPlayer;
	// tiles
	i = 0;
	T* t;
	while (i < (nRows*nCols)) {
		getline(_is, line);
		ss.str(line);	
		ss.clear();			
		ss >> x >> y >> tileType >> purchasedRubies;
		t = TileFactory::getTileFromInteger(tileType, purchasedRubies);				
		_gb.add(*t, x, y);
		i++;
	}							
	return _is;
};

template <class T, class J, int row, int col>
GameBoard<T, J, row, col>::GameBoard(){	
	currentPlayer = 0;	
	for (int i = 0; i < row; i++){        //creating Deafult 2D Game Board				
		for (int j = 0; j < row; j++) {
			board[i][j] = new T();
		}
	};
};


template <class T, class J, int row, int col>
int GameBoard<T, J, row, col>::getCurrentPlayer() const{	
	return currentPlayer;
};

template <class T, class J, int row, int col>
void GameBoard<T, J, row, col>::setCurrentPlayer(int x){	
	currentPlayer = x;
};

template <class T, class J, int row, int col>
GameBoard<T, J, row, col>::GameBoard(vector<J> _players){
	currentPlayer = 0;
	players = _players;	
	for (int i = 0; i < row; i++){        //creating Deafult 2D Game Board				
		for (int j = 0; j < row; j++) {
			board[i][j] = new T();
		}
	};
};
 
	
template <class T, class J, int row, int col>
void GameBoard<T, J, row, col>::add(const T& tile, int _row, int _col){		
	if (_row < row && _col < col && _row >= 0 && _col >= 0) //If valid position then add the tile
		board[_row][_col] = tile.clone();
	else
			throw out_of_range("Coordinates out of range"); // THROW AN EXCEPTION IF OUT OF RANGE

		
}


template <class T, class J, int row, int col>
const T& GameBoard<T, J, row, col>::getTile(int _row, int _col) const{
	
	if (_row < row && _col < col && _row >= 0 && _col >= 0) 
		return *board[_row][_col];
	else
		throw out_of_range("Coordinates out of range"); // THROW AN EXCEPTION HERE IF OUT OF RANGE
}

template <class T, class J, int row, int col>
void GameBoard<T, J, row, col>::getCoordinate(const T &tile, int* _row, int* _col)const{
	
	bool isFound = false;

	for (int i = 0; i < row; i++){
		for (int j = 0; j < col; j++){
			if (*board[i][j] == tile){ // Defined == Operator to compare two tiles
				*_row = i;
				*_col = j;
				isFound = true;
			}

			if (isFound) break;
		}
		if (isFound) break;
	}
}


template <class T, class J, int row, int col>
void GameBoard<T, J, row, col>::setPlayer(J player){

	string playerName = player.getName();
	for (vector<J>::size_type i = 0; i != players.size(); i++){
		if (players[i].getName() == playerName)
			players[i] = player;
	}
}


template <class T, class J, int row, int col>
J GameBoard<T, J, row, col>::getPlayer(const string& playerName) const{

	for (vector<J>::size_type i = 0; i != players.size(); i++){
		if (players[i].getName() == playerName)
			return players[i];
	}

	throw invalid_argument("No Player with Name: " + playerName);
}


template <class T, class J, int row, int col>
const T& GameBoard<T, J, row, col>::getTile(const string& playerName) const{

	Player player = getPlayer(playerName);		
	return *board[player.getX()][player.getY()];

	throw invalid_argument("No Player with Name: " + playerName);
}

template <class T, class J, int row, int col>
vector<J> GameBoard<T, J, row, col>::getPlayers(const T& tile) const{

	vector<J> getPlayers;
	int r, c;	

	getCoordinate(tile, &r, &c);	
	for (vector<J>::size_type i = 0; i != players.size(); i++){				
		if (players[i].getX() == r && players[i].getY() == c)	{			
			getPlayers.push_back(players[i]);		
		}	
	}
	
	return getPlayers; 

}

template <class T, class J, int row, int col>
vector<J> GameBoard<T, J, row, col>::getPlayers() const{
	return players;
}

template <class T, class J, int row, int col>
const T& GameBoard<T, J, row, col>::move(Move move, const string& playerName){

	Player player= getPlayer(playerName);

	int coordX = player.getX();
	int coordY = player.getY();

	bool moveUp = false;
	bool moveDown = false;
	bool moveLeft = false;
	bool moveRight = false;

	if (coordY > 0) moveUp = true;                     	
	if (coordY < row - 1) moveDown = true;
	if (coordX > 0) moveLeft = true;
	if (coordX < col - 1) moveRight = true;
		if (move == Move::UP && moveUp){
			player.setY(coordY - 1);
			setPlayer(player);
			return *board[coordX][coordY - 1];
		}

	else if (move == Move::DOWN && moveDown){		
		player.setY(coordY + 1);
		setPlayer(player);
		return *board[coordX][coordY + 1];
		}


	else if (move == Move::LEFT && moveLeft){		
		player.setX(coordX - 1);
		setPlayer(player);
		return *board[coordX - 1][coordY];
		}

	else if (move == Move::RIGHT && moveRight){	
		player.setX(coordX + 1);
		setPlayer(player);	
		return *board[coordX + 1][coordY];
		}

	
	else	throw invalid_argument("Invalid Move");
	}



//------------------------FOR TESTING --------------------

template <class T, class J, int row, int col>
void GameBoard<T, J, row, col>::print(){
	cout << "                                 -----Game Board------" << endl;
	for (int i = 0; i < row; i++){
		for (int j = 0; j < col; j++){
			board[i][j]->display();
		}
		cout << endl;		
	}	
}



template <class T, class J, int row, int col>
void GameBoard<T, J, row, col>::print(const string _playerName ){

	Player player = getPlayer(_playerName);
	string name = "";


		name = _playerName;
		for (int i = 0; i < row; i++){
			for (int j = 0; j < col; j++){
				if (j == 0){
					cout << "\t \t \t \t ";
				}
				if (player.getY() == i && player.getX() == j)
					cout << name.at(0);
				else
					cout << "-";
			}
			cout << endl;
		}
		cout << endl;
	

}


#endif