#include "3DSJWorld.h"

void World::setGravity(const Vec2& v) // Le daremos valor a la gravedad de la funcion setGravity().
{
	gravity = v;
}

void World::addBody(Body* b)
{
	bodies.push_back(b); //Va agregando elementos al vector bodies. 
}

void World::Step(float dt) //Step sera usado para calcular los pasos (como su nombre lo dice) que haran los bodies segun los frames. ES LA PARTE MÁS IMPORTANTE DE TODO. 
{

	if ((int)bodies.size() == 0) { std::cout << "NO BODIES FOUND IN THIS WORLD." << std::endl; system("pause"); }

	//Definicion temporal de variables (luego lo haremos mas limpio)
	float ax;
	float ay;
	float sx;
	float sy;
	float vx;
	float vy;

	//Integrador de Fuerzas (Calcular la aceleración)
	for (int i = 0; i < (int)bodies.size(); i++)
	{
		bodies[i]->velocity += dt * (gravity + bodies[i]->invMass * bodies[i]->force);
	}

	for (int i = 0; i < (int)bodies.size(); i++) //Iterando sobre el vector "bodies". 
	{
		bodies[i]->position += dt * bodies[i]->velocity;
		bodies[i]->force = Vec2(0.0f, 0.0f);
	}
}