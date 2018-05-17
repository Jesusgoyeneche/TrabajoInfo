#pragma once
#include "Coche.h"
#include "Bonus.h"
#include "Vector3D.h"
class Interaccion
{
public:
	Interaccion(void);
	~Interaccion(void);
	static void choque(Coche &h, Bonus b);
};
