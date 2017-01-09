#include "Public.h"

bool CompareColor(Color a, Color b)
{
	if (a.b == b.b && a.g == b.g && a.r == b.r)
	{
		return true;
	}
	return false;
}

void WaitForSeconds(Uint32 second)
{
	SDL_Delay(second * 1000);
}