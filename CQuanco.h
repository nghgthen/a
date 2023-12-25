#pragma once
#include"CHcnmau.h"
#define RONG  50
class CQuanco
{
public:
	CQuanco();
	CHcnmau oco[4];
	int x, y;
	int trangthai;
	void draw(CClientDC* pdc);
	void goLeft();
	void goRight();
	void goUp();
	void goDown();
	virtual void thietlap(int x, int y) {}
	virtual void doiTrangthai() {}
	virtual void veTrangthaicu() {}
	virtual void rotate() {}
};