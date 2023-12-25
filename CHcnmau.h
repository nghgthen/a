#pragma once
#include "Chcn.h"

class CHcnmau :public CHcn
{
public:
	int r, g, b;
	CHcnmau(int mx1, int my1, int mx2, int my2, int mr, int mg, int mb);
	CHcnmau();
	void draw(CClientDC* pDC);
};

