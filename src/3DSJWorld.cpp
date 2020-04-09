#include "3DSJWorld.h"

void World::setGravity(Vec2 v) // Le daremos valor a la gravedad de la funcion setGravity().
{
	gravity = v; 
}

void World::addBody(Body* b)
{
	bodies.push_back(b); //Va agregando elementos al vector bodies. 
}

void World::Step(float dt) //Step sera usado para calcular los pasos (como su nombre lo dice) que haran los bodies segun los frames. ES LA PARTE M�S IMPORTANTE DE TODO. 
{

	if ((int)bodies.size() == 0) { std::cout << "NO BODIES FOUND IN THIS WORLD." << std::endl; system("pause"); }

	float ax = gravity.getX(); //Por ahora, la �nica aceleraci�n que existe es debido a la gravedad. 
	float ay = gravity.getY();

	//Integrador de Fuerzas (Calcular la aceleraci�n)
	for (int i = 0; i < (int)bodies.size(); i++)
	{
		float ax = gravity.getX() + bodies[i]->getInvMass() * bodies[i]->getForce().getX();
		float ay = gravity.getY() + bodies[i]->getInvMass() * bodies[i]->getForce().getY();
	}

	for (int i = 0; i < (int)bodies.size(); i++) //Iterando sobre el vector "bodies". 
	{
		float sx = bodies[i]->getPos().getX(); //Posici�n en x del cuerpo en bodies[i]
		float sy = bodies[i]->getPos().getY(); //Posici�n en y del cuerpo en bodies[i]

		float vx = bodies[i]->getVel().getX(); //Velocidad en x del cuerpo en bodies[i]
		float vy = bodies[i]->getVel().getY(); //Velocidad en y del cuerpo en bodies[i]

		bodies[i]->setPos(Vec2(sx + vx * dt, sy + vy * dt)); //Modificando la posici�n del cuerpo usando la aproximaci�n de Euler.
		bodies[i]->setVel(Vec2(ax * dt + vx, ay * dt + vy)); //Modificando la velocidad del cuerpo usando la aproximaci�n de Euler.
	
		bodies[i]->addForce(Vec2(0.0f, 0.0f));
	}

}