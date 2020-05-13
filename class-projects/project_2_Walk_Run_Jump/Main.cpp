#include <SFML/Graphics.hpp>
#include "3DSJWorld.h"
using namespace std;
using namespace sf;

int main()
{
	RenderWindow window(VideoMode(800, 600), "WALK, RUN, JUMP"); //Creamos una ventana con dimensiones 800x600. 
	window.setFramerateLimit(60);

	Event event; //Creamos un objeto tipo evento, llamado event. 
	Clock clock; //Para llevar el tiempo que toma hacer un frame en el ciclo de window. 

	//variables
	bool boolSpace = false;
	bool boolAir = false;
	bool boolWalkA = false;
	bool boolWalkD = false;
	bool boolRun = false;

	//Cargando backgrounds. 
	Sprite background;
	Texture backgroundTex;
	if (!backgroundTex.loadFromFile("Assets/bg1.png"))
	{
		std::cout << "Could not load texture. . ." << std::endl;
		system("pause");
	}

	Texture tileTex1;
	Sprite tileSprite1;
	if (!tileTex1.loadFromFile("Assets/tile1.png"))
	{
		std::cout << "Could not load texture. . ." << std::endl;
		system("pause");
	}

	//Cargando sprite.
	Texture kogTex1;
	Sprite kogSprite1;
	if (!kogTex1.loadFromFile("Assets/kog1.png"))
	{
		std::cout << "Could not load texture. . ." << std::endl;
		system("pause");
	}

	//Configuramos nuestro mundo. 
	World w1;
	w1.setGravity(Vec2(0.0f, 450.0f));

	Body b1;
	b1.mass = 2.0f;
	b1.invMass = 1 / b1.mass;
	b1.position = Vec2(400.0f, 400.0f);
	b1.velocity = Vec2(0.0f, 0.0f); //Velocidad inicial.

	w1.addBody(&b1);

	//Configurando texturas.
	kogSprite1.setTexture(kogTex1);
	background.setTexture(backgroundTex);
	tileSprite1.setTexture(tileTex1);

	//configurando tamaños.
	background.setScale(Vector2f(2.2f, 2.3f));
	tileSprite1.setScale(Vector2f(6.0f, 4.1f));
	kogSprite1.setScale(Vector2f(0.2f, 0.2f));


	//Configurando el player.
	Rect<float> size = kogSprite1.getGlobalBounds();
	tileSprite1.setOrigin(Vector2f(7.0f, -120.0f));
	kogSprite1.setOrigin(Vector2f(size.width, size.height));
	kogSprite1.setPosition(Vector2f(b1.position.x, b1.position.y));

	//Lo que sucede en la pantalla...
	while (window.isOpen()) //Se mantiene el ciclo while mientras la ventana esté abierta. 
	{
		while (window.pollEvent(event)) //Lee si hubo alguna señal de entrada (mouse, teclado, joystick...) 
		{
			if (event.type == Event::Closed) //Si el usuario presiona X (para salir de la ventana)...
			{
				window.close(); //... Cierra la ventana
			}
			if (event.type == Event::KeyPressed)
			{
				if (event.key.code == (Keyboard::Space))
				{
					boolSpace = true;
					cout << "Space pressed!" << endl;
				}
				if (event.key.code == (Keyboard::D))
				{
					boolWalkD = true;
					cout << "D pressed!" << endl;
				}
				if (event.key.code == (Keyboard::A))
				{
					boolWalkA = true;
					cout << "A pressed!" << endl;
				}
				if (event.key.code == (Keyboard::LShift))
				{
					boolRun = true;
					cout << "LShift pressed!" << endl;
				}
			}
			if (event.type == Event::KeyReleased)
			{
				if (event.key.code == (Keyboard::Space))
				{
					boolSpace = false;
				}
				if (event.key.code == (Keyboard::A))
				{
					boolWalkA= false;
				}
				if (event.key.code == (Keyboard::D))
				{
					boolWalkD= false;
				}
				if (event.key.code == (Keyboard::LShift))
				{
					boolRun = false;
				}
			}
		}

		if (!boolAir)
		{
			if (boolSpace)
			{
				b1.velocity.Set(0.0f, -400.0f);
				boolAir = true;
			}
		}
		if (boolWalkA)
		{
			b1.velocity.x = -150.0f;
		}
		if (boolWalkD) 
		{
			b1.velocity.x = 150.0f;
		}
		if ((boolWalkA)&&(boolRun))
		{
			b1.velocity.x = -300.0f;
		}
		if ((boolWalkD) && (boolRun))
		{
			b1.velocity.x = 300.0f;
		}
		/*if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			b1.addForceY(50.0f);
			std::cout << "S pressed" << std::endl;
		}  NO se usara para este proyecto.*/

		//Calculo el tiempo que toma hacer un frame.
		Time elapsed = clock.restart();
		float dt = elapsed.asSeconds();

		//Uso el tiempo calculado para usar la función Step() de World w1.
		w1.Step(dt);

		//Simulacion de collision.
		if (b1.position.y >= 430.0f)
		{
			b1.position.y = 430.0f;
			boolAir = false;
		}
		b1.velocity.x = 0.0f;
		kogSprite1.setPosition(Vector2f(b1.position.x, b1.position.y));

		window.clear(Color::Transparent);
		window.draw(background);
		window.draw(tileSprite1);
		window.draw(kogSprite1);
		window.display();
	}
}
