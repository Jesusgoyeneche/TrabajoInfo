#include "Paisaje.h"

Paisaje::Paisaje()
{
	carretera.SetPos(-10.0f, 0, 10.0f, 10.0f, 0, -200);
	carretera.SetColor(100, 100, 100);
	//cielo.SetPos(-1000, 0, -100, 1000, 200, -100);
	//cielo.SetColor(255, 0, 255);
	cesped.SetPos(-60.0f, 0, 10, -10.0f, 0, -200);
	cesped2.SetPos(60.0f, 0, 10, 10.0f, 0, -200);
	cesped.SetColor(0, 0, 100);
	cesped2.SetColor(0, 0, 100);
}

Paisaje::~Paisaje()
{
}

void Paisaje::Dibuja()
{
	carretera.Dibuja();
	cesped.Dibuja();
	cesped2.Dibuja();
}
