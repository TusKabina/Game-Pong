#pragma once
#include "defs.h"

class Ball
{
	private:

		const char ballChar = 'o';
		Position direction = { 0,0 };
		Position position = { 0,0 };
	public:

		Ball();
		~Ball();
		Position getDirection() { return this->direction; }
		void setDirection(Position direction) { this->direction = direction; }
		Position getPosition() { return this->position; }
		void setPosition(Position position) { this->position = position; }
		const char getChar() { return this->ballChar; }

};