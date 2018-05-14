#include "Paisaje.h"

Paisaje::Paisaje()
{
	carretera.SetPos(-10.0f, 0, 10.0f, 10.0f, 0, -50);
	carretera.SetColor(100, 100, 100);
	linea1.SetPos(-9.5f, 0.001f, 10.0f, -8.7f, 0.001f, -50);
	linea1.SetColor(255, 255, 255);
	linea2.SetPos(8.7f, 0.001f, 10.0f, 9.5f, 0.001f, -50);
	linea2.SetColor(255, 255, 255);
	cesped.SetPos(-60.0f, 0, 10, -10.0f, 0, -50);
	cesped2.SetPos(60.0f, 0, 10, 10.0f, 0, -50);
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
	linea1.Dibuja();
	linea2.Dibuja();
}
