#include "Bonus.h"
#include "glut.h"
//hola

Bonus::Bonus(void)
{
	radio=1.0f;
}


Bonus::~Bonus(void)
{
}
void Bonus::Dibuja(void){
	glPushMatrix();
	glTranslatef(posicion.x, posicion.y, posicion.z);
	glColor3f(1.0f, 0.0f, 0.0f);
	glutSolidSphere(radio, 20, 20);
	glPopMatrix();


}
void Bonus::SetPos(float ix, float iy,float iz){
posicion.x=ix;
posicion.y=iy;
posicion.z=iz;

}
