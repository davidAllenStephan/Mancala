#include <cstdlib>

int getRandomm(int upperBound)
{
	int randomNumber = (rand() % (upperBound + 1));
	return randomNumber;
}

int addRandomness(int percent)
{
	int r = getRandomm(100);
	if (r -= percent < 0)
	{
		return 1;
	}
	return 0;
}