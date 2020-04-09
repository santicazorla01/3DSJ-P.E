#include <iostream>
#include <math.h>
#include <vector>

struct Vec2
{
public:
	//Definir los constructores.
	Vec2() : x(0.0f), y(0.0f) {} //Constructor default inicializados con valores en 0.
	Vec2(float x, float y) : x(x), y(y) {}

	//Setear valores a las componentes del vector. 
	void Set(float x_, float y_);
	void setX(float x_);
	void setY(float y_);

	//Propiedades del vector (longitud, longitud al cuadrado y mostrar el vector). 
	float Length();
	float LengthSquared();
	void Display();

	//Obtener componentes del vector. 
	float getX();
	float getY();

	//Operaciones con vectores: suma, resta, producto cruz y punto. 
	void operator += (Vec2 v);
	void operator -= (Vec2 v);
	float Dot(Vec2 a, Vec2 b);
	float Cross(Vec2 a, Vec2 b);

private:
	float x, y;
};
