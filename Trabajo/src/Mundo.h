#include "Caja.h"
#include "Coche.h"
#include "Vector3D.h"
#include "Bonus.h"
#include "Interaccion.h"
class Mundo
{
private: 
	Vector3D ojo;
	Vector3D v_ojo;
	Vector3D a_ojo;
	Coche coche;
	Caja caja;
	Bonus positivo, negativo;
public:
	void Tecla(unsigned char key);
	void Inicializa();
	void RotarOjo();
	void Mueve(float t);
	void Dibuja();
	void teclaEspecial(unsigned char key);
	friend class Interaccion;
};
