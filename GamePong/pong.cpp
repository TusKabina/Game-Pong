#include "pong.h"

void Pong::moveUp()
{
	if (GetAsyncKeyState(VK_UP))
	{
		this->board.changeStickPosition(1, -1);
	}
	if (GetAsyncKeyState(VK_W))
	{
		this->board.changeStickPosition(0, -1);
	}
}

void Pong::moveDown()
{
	if (GetAsyncKeyState(VK_DOWN))
	{
		this->board.changeStickPosition(1, 1);
	}
	if (GetAsyncKeyState(VK_S))
	{
		this->board.changeStickPosition(0, 1);
	}
}

void Pong::movement()
{
	moveUp();
	moveDown();
}


Pong::Pong()
{
	int rows = 11;
	int columns = 21;
	int stickSize = 4;
	std::vector<Stick> players;
	players.push_back({ 1, stickSize, {4,1}});
	players.push_back({ 1, stickSize, {4, columns - 2}});
	this->board.setRows(rows);
	this->board.setColumns(columns);
	this->board.setPlayers(players);
}

Pong::~Pong()
{
}

void Pong::play()
{
	while (1)
	{
		system("cls");
		this->board.initBoard();
		this->board.setBall();
		this->board.setSticks();
		this->board.display();
		this->movement();
		this->board.changeBallPosition();
		if (board.checkScore(0) == 10)
		{
			std::cout << "Player 1 Wins!" << std::endl;
			break;
		}
		else if (board.checkScore(1) == 10)
		{
			std::cout << "Player 2 Wins!" << std::endl;
			break;
		}
		Sleep(10);
	}
	
}
