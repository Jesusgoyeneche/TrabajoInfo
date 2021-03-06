#include "Mundo.h"
#include "glut.h"
#include <math.h>
#include "Paisaje.h"

void Mundo::RotarOjo()
{
	float d, theta;
	d = ojo.x * ojo.x + ojo.z * ojo.z;
	d = sqrt(d);
	theta = (atan2(ojo.z, ojo.x));
	theta = theta + 0.01F;
	ojo.x = d * cos(theta);
	ojo.z = d * sin(theta);
}
void Mundo::Dibuja()
{
	gluLookAt(ojo.x, ojo.y, ojo.z,  // posicion del ojo
		coche.GetPos().x, ojo.y, coche.GetPos().z,      // hacia que punto mira  (0,0,0) 
			0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y)    
	paisaje.Dibuja();
	cielo.Dibuja();
	coche.Dibuja();
	positivo.Dibuja();
	float r = 40, cx = 0, cz = 0;
	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
	glColor3ub(100, 100, 100);
	for (float i = 0; i < 40; i += 0.01f)
	{
		cx = r * cos(i) +30;
		cz = r * sin(i) -50;
		if (cz <= -50 && cz >= -90 && cx >= -10 && cx <= 30)
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
		cz2 = r2 * sin(j) -50;
		glVertex3f(cx2 + 30, 0.011f, cz2);
	}
	glEnd();
	glEnable(GL_LIGHTING);
}

void Mundo::Mueve(float t)
{
	coche.Mueve(0.025f);
	cielo.Mueve(coche.GetPos().z - 100);
	ojo = ojo + v_ojo * t + a_ojo * (0.5f*t*t);
	v_ojo = v_ojo + a_ojo * t;
	Interaccion::choque(coche, positivo, v_ojo);
}

void Mundo::Inicializa()
{
	ojo.x = 0;
	ojo.y = 7.5;
	ojo.z = 30;
	coche.SetPos(0.0f, 0.0f, 0.0f);
	cielo.SetPos(-1000, 0, -100, 1000, 200, -100);
	cielo.SetColor(255, 0, 255);
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
		v_ojo.x = -5.0f;
		v_ojo.z = 0.0f;
		break;
	case GLUT_KEY_RIGHT:
		coche.SetVel(5.0f, 0.0f, 0.0f);
		v_ojo.x = 5.0f;
		v_ojo.z = 0.0f;
		break;
	case GLUT_KEY_UP:
		coche.SetVel(0.0f, 0.0f, -5.0f);
		v_ojo.z = -5.0f;
		v_ojo.x = 0.0f;
		break;
	case GLUT_KEY_DOWN:
		coche.SetVel(0.0f, 0.0f, 5.0f);
		v_ojo.z = 5.0f;
		v_ojo.x = 0.0f;
		break;
	}
}

