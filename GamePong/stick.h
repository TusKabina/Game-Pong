#pragma once
#include "defs.h"

class Stick
{
	private:

		const char stickChar = '#';
		int score=0;
		int speed=0;
		int length=0;
		Position position = {0,0};

	public:

		Stick();
		Stick(int speed, int length, Position position);
		~Stick();
		int getSpeed() { return this->speed; }
		void setSpeed(int speed) { this->speed = speed; }
		int getLength() { return this->length; }
		void setLength(int length) { this->length = length; }
		Position getPosition() { return this->position; }
		void setPosition(Position position) { this->position = position; }
		const char getChar() { return this->stickChar; }
		int getScore() { return this->score; }
		void setScore() { this->score++; }

		

};