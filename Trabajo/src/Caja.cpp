#include "Caja.h"

Caja::Caja()
{
	carretera.SetPos(-10.0f, 0, 10.0f, 10.0f,0,-200);
	carretera.SetColor(100, 100, 100);
	cesped.SetPos(-50.0f,0,10,-10.0f,0,-200);
	cesped2.SetPos(50.0f,0,10,10.0f,0,-200);
	cesped.SetColor(0,0,100);
	cesped2.SetColor(0,0,100);
}


Caja::~Caja()
{
}

void Caja::Dibuja()
{
	carretera.Dibuja();
	cesped.Dibuja();
	cesped2.Dibuja();
}