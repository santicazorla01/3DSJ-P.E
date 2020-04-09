#include "3DSJBody.h"

//Funciones del body, les daremos valor a las funciones para poder añadir masas.
void Body::setMass(float m)
{
	mass = m;
}

//Añadir velocidad.
void Body::setVel(Vec2 v)
{
	velocity = v;
}

//La posicion
void Body::setPos(Vec2 v)
{
	position = v;
}

//Aqui obtendremos mass, inverse, vel y pos, y retornaremos sus valores.
float Body::getMass()
{
	return mass;
}

float Body::getInvMass()
{
	return invMass;
}

Vec2 Body::getVel()
{
	return velocity;
}

Vec2 Body::getPos()
{
	return position;
}

//Mostrar los valores de nuestro body, su masa, posicion y velocidad.
void Body::DisplayInfo()
{
	std::cout << "m: " << mass << std::endl;
	std::cout << "s: ", position.Display();
	std::cout << "v: ", velocity.Display();
}

//Añadir y retornar force, en X y Y
void Body::addForce(Vec2 f)
{
	force = f;
}

Vec2 Body::getForce()
{
	return force;
}

void Body::addForceX(float k)
{
	force.setX(k);
}

void Body::addForceY(float k)
{
	force.setY(k);
}