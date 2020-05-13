#include <SFML/Graphics.hpp>
#include "3DSJWorld.h"
using namespace std;
using namespace sf;

int main()
{
	RenderWindow window(VideoMode(1280, 1024), "GLIDING!"); //Creamos una ventana con dimensiones 800x600. 
	window.setFramerateLimit(60);

	Event event; //Creamos un objeto tipo evento, llamado event. 
	Clock clock; //Para llevar el tiempo que toma hacer un frame en el ciclo de window. 

	//variables
	bool isGliding = false;
	bool controlVar = false;

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
	w1.setGravity(Vec2(0.0f, 500.0f));

	//Condiciones iniciales de nuestro body
	Body b1;
	b1.force = Vec2(0.0f, 0.0f);
	b1.mass = 2.0f;
	b1.invMass = 1 / b1.mass;
	b1.position = Vec2(1200.0f, 100.0f);
	b1.velocity = Vec2(0.0f, 0.0f); //Velocidad inicial.

	w1.addBody(&b1);
	//Configurando texturas.
	kogSprite1.setTexture(kogTex1);
	background.setTexture(backgroundTex);
	tileSprite1.setTexture(tileTex1);

	//configurando tamaños.
	Rect<float> backSize = background.getGlobalBounds();
	Vector2f targetSize(1280.0f, 1024.0f); 
	background.setScale(targetSize.x/backSize.width, targetSize.y/backSize.height);
	tileSprite1.setScale(Vector2f(6.0f, 4.1f));
	kogSprite1.setScale(Vector2f(0.050f, 0.050f));

	//Configurando el player.
	Rect<float> size = kogSprite1.getGlobalBounds();
	tileSprite1.setOrigin(Vector2f(-70.0f, -40.0f));
	kogSprite1.setOrigin(Vector2f(size.width/2, size.height/2));
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
				if (event.key.code == (Keyboard::P))
				{
					isGliding = true;
					cout << "Glider Open!" << endl;
				}	
			}
			if (event.type == Event::KeyReleased)
			{
				if (event.key.code == (Keyboard::P))
				{
					isGliding = false;
					cout << "Glider closed!" << endl;
				}
			}
			if (Keyboard::isKeyPressed(Keyboard::D))
			{
				if (isGliding)
				{
					b1.addForce(Vec2(200.0f, 0.0f));
				}
				else
				{
					b1.addForce(Vec2(700.0f, 0.0f));
				}
			}
			if (Keyboard::isKeyPressed(Keyboard::A))
			{
				if (isGliding)
				{
					b1.addForce(Vec2(-200.0f, 0.0f));
				}
				else
				{
					b1.addForce(Vec2(-700.0f, 0.0f));
				}
			}
		}
		if (isGliding)
		{
			b1.force.y = -1000.0f;
		}

		//Calculo el tiempo que toma hacer un frame.
		Time elapsed = clock.restart();
		float dt = elapsed.asSeconds();

		//Uso el tiempo calculado para usar la función Step() de World w1.
		w1.Step(dt);
	
		//Posición del sprite.
		kogSprite1.setPosition(Vector2f(b1.position.x, b1.position.y));
		window.clear(Color::Transparent);
		window.draw(background);
		window.draw(tileSprite1);
		window.draw(kogSprite1);
		window.display();
	}
}