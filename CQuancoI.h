#pragma once
#include "CQuanco.h"
class CQuancoI :
    public CQuanco
{
public:
    CQuancoI(int mx, int my);
    void thietlap(int x, int y);
    void doiTrangthai();
    void veTrangthaicu();
    void rotate();
};

