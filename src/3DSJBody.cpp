#include "3DSJBody.h"

//Mostrar los valores de nuestro body, su masa, posicion y velocidad.
void Body::DisplayInfo()
{
	std::cout << "m: " << mass << std::endl;
	std::cout << "s: ", position.Display();
	std::cout << "v: ", velocity.Display();
}

//Añadir y retornar force
void Body::addForce(const Vec2& f)
{
	force += f;
}