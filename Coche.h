#pragma once
#include"Vector3D.h"
class Coche
{
private:
	float altura;
	Vector3D posicion;
	Vector3D velocidad;
	Vector3D aceleracion;
public:
	Coche();
	~Coche();
	void Dibuja();
	void Mueve(float t);
	void SetVel(float vx, float vy, float vz);
	void SetPos(float px, float py, float pz);
	Vector3D GetPos();
	friend class Interaccion;
	friend class Mundo;
};

