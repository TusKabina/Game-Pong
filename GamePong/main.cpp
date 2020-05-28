#include "pong.h"
#include <ctime>
int main()
{
	srand(time(0));
	Pong pong;
	pong.play();
	return 0;
}