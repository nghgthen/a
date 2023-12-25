#pragma once
#include "OCoMau.h"
#include "CQuanco.h"
#define RONG 50
#define WIDTH 8
#define HEIGHT 16
struct toado { int i; int j; };
class CBanco
{
public:
	int x, y;
	int control, level, diem;
	OCoMau oco[HEIGHT][WIDTH];
	CQuanco* pnext, * pc;

	CBanco();
	void draw(CClientDC* pdc);
	void start();
	int kiemtra_dixuong();
	int kiemtra_quatrai();
	int kiemtra_quaphai();
	int kiemtra_xoay();
	void play(CClientDC* pdc);
	toado timIJ(CHcnmau oco);
	void transfer_banco();
	void spawn_quanco();
	void goDown(CClientDC* pdc);
	void goLeft(CClientDC* pdc);
	void goRight(CClientDC* pdc);
	void rotate(CClientDC* pdc);

};

