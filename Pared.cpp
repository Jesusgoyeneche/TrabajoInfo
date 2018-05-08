#include "Pared.h"
#include"glut.h"


Pared::Pared()
{
	rojo = verde = azul = 255;
}


Pared::~Pared()
{
}

void Pared::Dibuja()
{
	glDisable(GL_LIGHTING);
	glColor3ub(rojo, verde, azul);
	glBegin(GL_POLYGON);
		glVertex3d(limite1.x, limite1.y, limite1.z);
		glVertex3d(limite2.x, limite2.y, limite1.z);
		glVertex3d(limite2.x, limite2.y, limite2.z);
		glVertex3d(limite1.x, limite1.y, limite2.z);
	glEnd();
	glEnable(GL_LIGHTING);
}

void Pared::SetColor(float a, float r, float v)
{
	azul = a;
	rojo = r;
	verde = v;
}

void Pared::SetPos(float x1, float y1, float z1, float x2,float y2,float z2)
{
	limite1.x = x1;
	limite1.y = y1;
	limite1.z = z1;
	limite2.x = x2;
	limite2.y = y2;
	limite2.z = z2;
}
