#include "Mundo.h"
#include "glut.h"
#include <math.h>
#include "Paisaje.h"

void Mundo::RotarOjo(float dif)
{
	float d, theta=0;
	Vector3D dis =((coche.GetPos().x-ojo.x,0,coche.GetPos().z-ojo.z));
	ojo.x*=-1; 
	ojo.z = dis.z ;
}
void Mundo::Dibuja()
{
	gluLookAt(camara.posicion.x, camara.posicion.y, camara.posicion.z,  // posicion del ojo
		coche.GetPos().x, camara.posicion.y, coche.GetPos().z,      // hacia que punto mira  (0,0,0) 
			0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y)    
	paisaje.Dibuja();
	cielo.Dibuja();
	coche.Dibuja();
	positivo.Dibuja();
	float r = 40, cx = 0, cz = 0;
	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
	glColor3ub(100, 100, 100);
	for (float i = 30; i < 40; i += 0.01f)
	{
		cx = r * cos(i) + 30;
		cz = r * sin(i) - 50;
		if (cx <= 30 && cx >= -10) //cz <= -50 && cz >= -90)
		{
			glVertex3f(cx, 0.0f, cz);
		}
	}
	glEnd();
	glEnable(GL_LIGHTING);

	float r2 = 20, cx2 = 0, cz2 = 0;
	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
	glColor3ub(0, 100, 0);
	for (float j = 0; j < 20; j += 0.01f)
	{
		cx2 = r2 * cos(j);
		cz2 = r2 * sin(j) - 50;
		glVertex3f(cx2 + 30, 0.01f, cz2);
	}
	glEnd();
	glEnable(GL_LIGHTING);
}

void Mundo::Mueve(float t)
{
	coche.Mueve(0.025f);
	cielo.Mueve(coche.GetPos().z - 100);
	camara.velocidad=coche.GetVel();
    camara.Mueve(0.025f);
	if (girar == 2&&coche.posicion.z<=-50)
	{ 
	RotarOjo(-0.01f);
	}
	if (girar == 1&&coche.posicion.z<=-50)
		RotarOjo(0.01f);
	Interaccion::choque(coche, positivo);
}

void Mundo::Inicializa()
{
	coche.SetPos(0.0f, 0.0f, 0.0f);
	cielo.SetPos(-70, 0, -100, 70, 70, -100);
	positivo.SetPos(0.0f,0.0f,-10.0f);
}

void Mundo::Tecla(unsigned char key)
{
}
void Mundo::teclaEspecial(unsigned char key)
{
	switch (key)
	{
	case GLUT_KEY_LEFT:
		coche.SetVel(-5.0f, 0.0f, 0.0f);
		girar = 1;
		break;
	case GLUT_KEY_RIGHT:
		coche.SetVel(5.0f, 0.0f, 0.0f);
		girar = 2;
		break;
	case GLUT_KEY_UP:
		coche.SetVel(0.0f, 0.0f, -5.0f);
		girar = 0;
		break;
	case GLUT_KEY_DOWN:
		coche.SetVel(0.0f, 0.0f, 5.0f);
		girar = 0;
		break;
	}
}
