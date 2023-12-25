#include "pch.h"
#include "CQuancoT.h"

CQuancoT::CQuancoT(int mx, int my)
{
    x = mx;
    y = my;
    oco[0] = CHcnmau(x, y, x + RONG, y + RONG, 255, 0, 0);
    oco[1] = CHcnmau(x + RONG, y, x + 2 * RONG, y + RONG, 255, 0, 0);
    oco[2] = CHcnmau(x + 2 * RONG, y, x + 3 * RONG, y + RONG, 255, 0, 0);
    oco[3] = CHcnmau(x + RONG, y, x + 2 * RONG, y + 2 * RONG, 255, 0, 0);
}
void CQuancoT::thietlap(int x, int y)
{
    this->x = x;
    this->y = y;
    oco[0].thietlap(x, y, x + RONG, y + RONG);
    oco[1].thietlap(x + RONG, y, x + 2 * RONG, y + RONG);
    oco[2].thietlap(x + 2 * RONG, y, x + 3 * RONG, y + RONG);
    oco[3].thietlap(x + RONG, y, x + 2 * RONG, y + 2 * RONG);
}
