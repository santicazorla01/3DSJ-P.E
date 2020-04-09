#include "3DSJWorld.h"
#include <iostream>
#include <stdlib.h>
using namespace std;

float mass; //Masa definida por el usuario
float s_x, s_y, v_x, v_y; //Valores de la posicion y velocidad que seran definidos por el usuario.

int main() {

	//creamos un mundo
	World w1;

	//Le preguntamos al usuario la posicion y velocidad inicial del cuerpo
	cout << "\t\t 3DSJ P.E. version 2.0" << endl;
	cout << "\n  Bienvenido, introduzca la masa del objeto" << endl;
	cin >> mass;
	cout << "\n Ahora introduzca las posicion inicial en x " << endl;
	cin >> s_x;
	cout << "\n Introduzca las posicion inicial en y" << endl;
	cin >> s_y;
	cout << "\n Ahora introduzca la velocidad inicial en x " << endl;
	cin >> v_x;
	cout << "\n Por ultimo introduzca la velocidad inicial en y" << endl;
	cin >> v_y;
	system("cls");

	//creamos el cuerpo y establecemos sus propiedades de masa posicion y velocidad con los datos del usuario.
	Body b1;
	b1.setMass(mass);
	b1.setPos(Vec2(s_x, s_y));
	b1.setVel(Vec2(v_x, v_y));

	//agregamos el cuerpo creado al mundo
	w1.addBody(&b1);

		for (int i = 0; i < 10; i++) {
			w1.Step(1.0f);

			b1.DisplayInfo();
		}
	return 0;
}