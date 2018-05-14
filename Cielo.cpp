#include "Cielo.h"
#include "glut.h"

void Cielo::Dibuja()
{
	glDisable(GL_LIGHTING);
	glColor3ub(rojo, verde, azul);
	glBegin(GL_POLYGON);
		glColor3ub(255, 255, 50);
		glVertex3d(limite1.x, limite1.y, limite1.z);
		glColor3ub(0, 255, 255);
		glVertex3d(limite2.x, limite1.y, limite1.z);
		glColor3ub(0, 255, 255);
		glVertex3d(limite2.x, limite2.y, limite2.z);
		glColor3ub(255, 120, 0);
		glVertex3d(limite1.x, limite2.y, limite2.z);
	glEnd();
	glEnable(GL_LIGHTING);
}

void Cielo::SetColor(float a, float r, float v)
{
	azul = a;
	rojo = r;
	verde = v;
}

void Cielo::SetPos(float x1, float y1, float z1, float x2, float y2, float z2)
{
	limite1.x = x1;
	limite1.y = y1;
	limite1.z = z1;
	limite2.x = x2;
	limite2.y = y2;
	limite2.z = z2;
}

void Cielo::Mueve(float z)
{
	limite1.z = z;
	limite2.z = z;
}

Cielo::Cielo()
{
}


Cielo::~Cielo()
{
}
