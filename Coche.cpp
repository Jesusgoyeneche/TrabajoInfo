#include "Coche.h"
#include"glut.h"


Coche::Coche()
{
	altura = 1.8f;
}


Coche::~Coche()
{
}

void Coche::Dibuja()
{
	glPushMatrix();
	glTranslatef(posicion.x, posicion.y, posicion.z);
	glColor3f(1.0f, 0.0f, 0.0f);
	glutSolidSphere(altura, 20, 20);
	glPopMatrix();
}

void Coche::Mueve(float t)
{
	posicion = posicion + velocidad * t + aceleracion * (0.5f*t*t);
	velocidad = velocidad + aceleracion * t;
}
void Coche::SetVel(float vx, float vy, float vz)
{
	velocidad.x = vx;
	velocidad.y = vy;
	velocidad.z = vz;
}

void Coche::SetPos(float px, float py, float pz)
{
	posicion.x = px;
	posicion.y = py;
	posicion.z = pz;
}
