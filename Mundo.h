#include "Paisaje.h"
#include "Coche.h"
#include "Vector3D.h"
#include "Bonus.h"
#include "Interaccion.h"
#include "Cielo.h"
class Mundo
{
private: 
	Vector3D ojo;
	Vector3D v_ojo;
	Vector3D a_ojo;
	Coche coche;
	Paisaje paisaje;
	Bonus positivo, negativo;
	Cielo cielo;
	int girar; //variable para saber hacia que lado gira
public:
	void Tecla(unsigned char key);
	void Inicializa();
	void RotarOjo(float dif);
	void Mueve(float t);
	void Dibuja();
	void teclaEspecial(unsigned char key);
	friend class Interaccion;
};
