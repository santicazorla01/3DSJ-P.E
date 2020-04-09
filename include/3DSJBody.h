#include "3DSJMath.h"

struct Body
{
public:
	//Constructores para el cuerpo
	Body() : mass(1.0f) {}
	Body(float mass) : mass(mass) {}

	//Establecer el valor de la masa
	void setMass(float m);

	//Establecer posición y velocidad
	void setVel(Vec2 v);
	void setPos(Vec2 v);

	//Obtener los valores de masa, masa inversa, posición y velocidad
	float getMass();
	float getInvMass();
	Vec2 getVel();
	Vec2 getPos();

	//Mostrar información del cuerpo
	void DisplayInfo();

	//Aplicación de fuerzas, añadir y obtener fuerza, en X y Y
	void addForce(Vec2 f);
	Vec2 getForce();
	void addForceX(float k);
	void addForceY(float k);

private:
	//Daremos los valores que podran ser accedidos en la clase y sus miembros.
	float mass;
	float invMass = 1 / mass;
	Vec2 position;
	Vec2 velocity;
	Vec2 force;
};
