#include "Vector3D.h"
#include <math.h>

Vector3D::Vector3D(float vx, float vy, float vz)
{
	x = vx;
	y = vy;
	z = vz;
}

Vector3D::~Vector3D()
{
}

float Vector3D::modulo()
{
	return (float)sqrt(x*x + y * y + z * z);
}

float Vector3D::argumento()
{
	return (float)atan2(y, x);
}

Vector3D Vector3D::Unitario()
{
	Vector3D retorno(x, y, z);
	float mod = modulo();
	if (mod>0.00001)
	{
		retorno.x /= mod;
		retorno.y /= mod;
		retorno.z /= mod;
	}
	return retorno;
}

Vector3D Vector3D::operator - (Vector3D &v)
{
	Vector3D res;
	res.x = x - v.x;
	res.y = y - v.y;
	res.z = z - v.z;
	return res;
}

Vector3D Vector3D::operator + (Vector3D &v)
{
	Vector3D res;
	res.x = x + v.x;
	res.y = y + v.y;
	res.z = z + v.z;
	return res;
}

float Vector3D::operator * (Vector3D &v)//producto escalar
{
	float p_esc;
	p_esc = x * v.x + y * v.y + z * v.z;
	return p_esc;
}

Vector3D Vector3D::operator * (float esc) //producto por un escalar
{
	Vector3D w;
	w.x = esc * x;
	w.y = esc * y;
	w.z = esc * z;
	return w;
}
