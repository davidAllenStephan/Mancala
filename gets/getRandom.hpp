#include <cstdlib>
int getRandom(int upperBound)
{
	int randomNumber = (rand() % (upperBound + 1));
	return randomNumber;
}