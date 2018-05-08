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

