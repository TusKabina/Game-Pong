#pragma once
#include "ball.h"
#include "stick.h"

class Board
{
	private:

		int rows=0;
		int columns=0;
		Ball ball;
		std::vector<Stick> players;
		std::vector<std::vector<char>> boardState;

	public:

		Board();
		~Board();
		void setPlayers(std::vector<Stick> players);
		void changeStickPosition(int index, int direction);
		int getRows() { return this->rows; }
		void setRows(int rows) { this->rows = rows; }
		int getColumns() { return this->columns; }
		void setColumns(int columns) { this->columns = columns; }
		int checkScore(int index) { return players[index].getScore(); }
		Ball getBall() { return this->ball; }
		void initBoard();
		void setSticks();
		void setBall();
		void display();
		bool isWall();
		bool isCollision();
		void changeBallPosition();
		void ballRandMovement();
		bool isPoint();

};