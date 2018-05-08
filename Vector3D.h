#pragma once
class Vector3D
{
public:
	float x;
	float y;
	float z;
	Vector3D(float vx = 0.0f, float vy = 0.0f, float vz = 0.0f);
	~Vector3D();
	float modulo(); // (2) modulo del vector
	float argumento(); // (3) argumento del vector
	Vector3D Unitario(); // (4) devuelve un vector unitario
	Vector3D operator - (Vector3D &); // (5) resta de vectores
	Vector3D operator + (Vector3D &); // (6) suma de vectores
	float operator *(Vector3D &); // (7) producto escalar
	Vector3D operator *(float); // (8) producto por un escalar
	friend class Interaccion;
};

