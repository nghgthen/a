#include "pch.h"
#include "CQuancoL.h"

CQuancoL::CQuancoL(int mx,int my)
{
	x = mx;
	y = my;
	oco[0] = CHcnmau(x, y, x + RONG, y + RONG, 0, 0, 255);
	oco[1] = CHcnmau(x, y + RONG, x + RONG, y + 2 * RONG, 0, 0, 255);
	oco[2] = CHcnmau(x, y + 2 * RONG, x + RONG, y + 3 * RONG, 0, 0, 255);
	oco[3] = CHcnmau(x + RONG, y + 2 * RONG, x + 2 * RONG, y + 3 * RONG, 0, 0, 255);
}

void CQuancoL::thietlap(int x, int y)
{
	this->x = x;
	this->y = y;
	oco[0].thietlap(x, y, x + RONG, y + RONG);
	oco[1].thietlap(x, y + RONG, x + RONG, y + 2 * RONG);
	oco[2].thietlap(x, y + 2 * RONG, x + RONG, y + 3 * RONG);
	oco[3].thietlap (x, y + 2 * RONG, x + 2 * RONG, y + 3 * RONG);
}
