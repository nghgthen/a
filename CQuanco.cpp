#include "pch.h"
#include "CQuanco.h"


CQuanco::CQuanco()
{
	x = 0;
	y = 0;
	trangthai = 0;
}

void CQuanco::draw(CClientDC* pdc)
{
	for (int i = 0; i < 4; i++)
	{
		oco[i].draw(pdc);
	}
}

void  CQuanco::goDown()
{
	for (int i = 0; i < 4; i++) {
		oco[i].y1 += RONG;
		oco[i].y2 += RONG;
	}
	y += RONG;
}

void CQuanco::goLeft()
{
	for (int i = 0; i < 4; i++) {
		oco[i].x1 -= RONG;
		oco[i].x2 -= RONG;
	}
	x -= RONG;
}

void CQuanco::goRight()
{
	for (int i = 0; i < 4; i++) {
		oco[i].x1 += RONG;
		oco[i].x2 += RONG;
	}
	x += RONG;
}

void CQuanco::goUp()
{
	for (int i = 0; i < 4; i++) {
		oco[i].y1 -= RONG;
		oco[i].y2 -= RONG;
	}
}
