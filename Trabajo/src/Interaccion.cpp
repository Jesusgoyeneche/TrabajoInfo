#include "Interaccion.h"



Interaccion::Interaccion(void)
{
}


Interaccion::~Interaccion(void)
{
}
void Interaccion::choque(Coche &c,Bonus  b, Vector3D &o)
{
Vector3D seg = c.posicion - b.posicion;
	float dist = seg.modulo();
	if(dist<=(c.altura + b.radio)){

c.velocidad=c.velocidad*1.25f;
o=c.velocidad;

	}


}