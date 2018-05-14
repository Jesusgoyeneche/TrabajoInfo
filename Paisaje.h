#pragma once
#include "Pared.h"
class Paisaje
{
private:
	Pared carretera;
	Pared cesped;
	Pared cesped2;
	Pared linea1;
	Pared linea2;
public:
	Paisaje();
	~Paisaje();
	void Dibuja();
};

