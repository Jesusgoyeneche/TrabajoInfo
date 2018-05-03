#pragma once
#include "Vector3D.h"
class Bonus
{
private:
	float radio;
	Vector3D posicion;
	
public:
	Bonus(void);
	~Bonus(void);
	void Dibuja(void);
	void SetPos(float ix, float iy, float iz);
	friend class Interaccion;
};

