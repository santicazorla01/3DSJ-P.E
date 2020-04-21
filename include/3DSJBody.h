#ifndef BODY_H
#define BODY_H
#include "3DSJMath.h"

struct Body
{
public:
	//Constructores para el cuerpo
	Body() {}

	//Mostrar información del cuerpo
	void DisplayInfo();

	//Aplicación de fuerzas 
	void addForce(const Vec2& f);

	//Daremos los valores que podran ser accedidos en la clase y sus miembros.
	float mass;
	float invMass;
	Vec2 position;
	Vec2 velocity;
	Vec2 force = Vec2(0.0f, 0.0f);
};
#endif // !BODY_H