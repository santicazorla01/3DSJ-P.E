#ifndef MATH_H
#define MATH_H

#include <iostream>
#include <math.h>
#include <vector>

struct Vec2
{
public:
	//Definir los constructores.
	Vec2() {} //Constructor default inicializados con valores en 0.
	Vec2(float x, float y) : x(x), y(y) {}

	//Setear valores a las componentes del vector. 
	void Set(float x_, float y_);

	//Propiedades del vector (longitud, longitud al cuadrado y mostrar el vector). 
	float Length();
	float LengthSquared();
	void Display();

	//Operaciones con vectores: suma, resta, producto cruz y punto. 
	void operator += (const Vec2& v); //
	void operator -= (const Vec2& v);

	float Dot(const Vec2& a, const Vec2& b);
	float Cross(const Vec2& a, const Vec2& b);

	float x, y;
};

inline Vec2 operator * (float k, const Vec2& v)
{
	return Vec2(k * v.x, k * v.y);
}

inline Vec2 operator + (Vec2 v1, Vec2 v2)
{
	return Vec2(v1.x + v2.x, v1.y + v2.y);
}
#endif
