#pragma once
#include "board.h"
class Pong
{
	private:

		Board board;
		void moveUp();
		void moveDown();
		void movement();

	public:
	
		Pong();
		~Pong();
		void play();

};