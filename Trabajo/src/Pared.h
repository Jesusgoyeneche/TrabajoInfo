#pragma once
#include "Vector3D.h"
class Pared
{
private:
	unsigned char rojo;
	unsigned char verde;
	unsigned char azul;
	Vector3D limite1;
	Vector3D limite2;
public:
	Pared();
	~Pared();
	void Dibuja();
	void SetColor(float a, float r, float v);
	void SetPos(float x1, float y1, float z1, float x2,float y2,float z2);
};

