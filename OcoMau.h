#pragma once
#include "CHcnmau.h"
class OCoMau :
    public CHcnmau
{
public:
    int gt; // 0 hoac 1
    OCoMau();
    OCoMau(int x1, int y1, int x2, int y2, int r, int g, int b, int gt) :CHcnmau(x1, y1, x2, y2, r, g, b)
    {
        this->gt = gt;
    }
    void draw(CClientDC* pDC);
};

