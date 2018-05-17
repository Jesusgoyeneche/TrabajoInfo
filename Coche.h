#pragma once
#include"Vector3D.h"
class Coche
{

	float altura;
	protected:
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
	Vector3D GetPos(){return posicion;};
	Vector3D GetVel(){return velocidad;};
	friend class Interaccion;
	friend class Mundo;
};

