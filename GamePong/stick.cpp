#include "stick.h"

Stick::Stick()
{
	this->speed = 1;
	this->length = 0;
	this->score = 0;
	Position position = { 0,0 };
}

Stick::Stick(int speed, int length, Position position) 
{
	this->speed = speed;
	this->length = length;
	this->position = position;
	this->score = 0;
}

Stick::~Stick()
{
}
