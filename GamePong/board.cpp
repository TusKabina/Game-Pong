#include "board.h"

Board::Board()
{
	this->rows = 0;
	this->columns = 0;
	this->boardState.clear();
	this->players.clear();
	this->ball.setPosition({ 5, 10 });
	this->ball.setDirection({ 1,1 });
}

Board::~Board()
{
}

void Board::setPlayers(std::vector<Stick> players)
{
	for (int i = 0; i < 2; i++)
	{
		this->players.push_back(players[i]);
	}
}

void Board::changeStickPosition(int index, int direction)
{
	int spd = this->players[index].getSpeed();
	spd *= direction;
	Position newP = { (players[index].getPosition().x + spd), players[index].getPosition().y };
	if (newP.x >= 0 && newP.x < (this->rows - (players[index].getLength() - 1)))
	{
		this->players[index].setPosition(newP);
	}
}

void Board::initBoard()
{
	boardState.clear();
	for (int i = 0; i < this->rows; i++)
	{
		std::vector<char> row;
		for (int j = 0; j < this->columns; j++)
		{

			row.push_back(emptyChar);
		}
		boardState.push_back(row);
	}
	

}

void Board::setSticks()
{
	int length = players[0].getLength();
	for (int i = 0; i < 2; i++) 
	{
		for (int j = 0; j < length; j++)
		{ 
			boardState[players[i].getPosition().x + j][players[i].getPosition().y] = players[i].getChar();
		}
	}
}

void Board::changeBallPosition()
{
	Position dir = this->ball.getDirection();
	Position pos = this->ball.getPosition();
	Position newPos = { pos.x + dir.x,pos.y + dir.y };
	if (isPoint())
	{
		this->ball.setPosition({ 5, 10 });
		this->players[0].setPosition({ 4, 1 });
		this->players[1].setPosition({ 4, columns-2 });
		ballRandMovement();
		Sleep(300);
		
	}
	else
	{
		this->ball.setPosition(newPos);
	}
	if (isWall())
	{
		this->ball.setDirection({ (dir.x*-1), (dir.y) });
	}
	else if (isCollision())
	{
		this->ball.setDirection({ (dir.x), (dir.y*-1) });
	}
}

void Board::ballRandMovement()
{
	int arr[2] = { 1,-1 };
	this->ball.setDirection({ arr[rand() % 2],arr[rand() % 2] });
	
}



void Board::setBall()
{
	boardState[this->ball.getPosition().x][this->ball.getPosition().y] = this->ball.getChar();
}

void Board::display()
{
	for (int i = 0; i < this->columns + 2; i++)
	{
		std::cout << "-";
	}
	std::cout << std::endl;

	for (int i = 0; i < this->rows; i++)
	{
		std::cout << "|";
		for (int j = 0; j < this->columns; j++)
		{
			std::cout << boardState[i][j];
		}
		std::cout << "|";
		std::cout << std::endl;
	}

	for (int i = 0; i < this->columns + 2; i++)
	{
		std::cout << "-";
	}
	std::cout << std::endl;
	std::cout << "Player 1: " << players[0].getScore() << std::endl;
	std::cout << "Player 2: " << players[1].getScore() << std::endl;
}

bool Board::isWall()
{
	int x = this->ball.getPosition().x;
	if (x == 0  || x==this->rows-1)
	{
		return true;
	}
	return false;
}
bool Board::isCollision()
{
	int length = players[0].getLength();
	for (int i = 0; i < 2; i++)
	{
		
		for (int j = 0; j < length; j++)
		{
			Position player = { (this->players[i].getPosition().x + j),(this->players[i].getPosition().y) };
			Position ball = { (this->ball.getPosition().x),(this->ball.getPosition().y) };

			if (i == 0)
			{
				player.y += 1;
			}
			else if (i == 1)
			{
				player.y -= 1;
			}
			if (player.x == ball.x && player.y == ball.y)
			{
				return true;
			}
			
		}
	}
	return false;
}
bool Board::isPoint()
{
	int p1 = ball.getPosition().y;
	if (p1 == 0 )
	{
		this->players[1].setScore();
		return true;
	}
	int p2 = ball.getPosition().y;
	if (p2 == columns-1)
	{
		this->players[0].setScore();
		return true;
	}
	return false;
}
