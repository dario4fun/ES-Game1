#include "Core.h"

static const float VIEW_WIDTH = 800.0f;		// Ancho de la ventana que se va a crear
static const float VIEW_HEIGHT = 600.0f;    // Alto de la ventana que se va a crear

/// <summary>
/// Con esta funcion reescalamos el view segun el tamaño de la ventana del motor y de la camara
/// </summary>
/// <param name="window"> Ventana del motor </param>
/// <param name="view"> Camara principal </param>
void ResizeView(const sf::RenderWindow& window, sf::View& view) {

	float aspectRatio = float(window.getSize().x) / float(window.getSize().y);

	view.setSize(VIEW_HEIGHT * aspectRatio, VIEW_WIDTH * aspectRatio);
}

/// <summary>
/// Constructor donde se inizializa la ventana y camara principal
/// </summary>
Core::Core() :
	_CoreWindow(sf::VideoMode(VIEW_WIDTH, VIEW_HEIGHT), "Dario Core Template - Juego 1", sf::Style::Close | sf::Style::Resize),
	_Renderer(_CoreWindow),
	_CoreCamera(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(VIEW_WIDTH, VIEW_HEIGHT)
	) {

	InitGame();
}


/// <summary>
/// Controlador de todo el motor
/// </summary>
void Core::Run()
{
	sf::Clock _CoreClock;
	float _DeltaTime;

	while (_CoreWindow.isOpen()) {

		// Guardamos el tiempo entre frames para que todo el juego mantenga la misma velocidad en todos los ordenadores
		_DeltaTime = _CoreClock.restart().asSeconds();

		ProcessInput();				// Control de interacciones del usuario

		CoreUpdate(_DeltaTime);		// Controlador de recursos del motor

		CoreRender();				// Controlador del renderizado del motor

	}

}

void Core::InitGame()
{
	_CoreWindow.setFramerateLimit(60);
	_Game.InitGameWindow(&_CoreWindow);
}

/// <summary>
/// Aqui se controlan tanto los eventos como las entradas del usuario
/// </summary>
void Core::ProcessInput()
{
	sf::Event _Event;

	while (_CoreWindow.pollEvent(_Event)) {

		_InputManager.ProcessEvent(_Event);

		switch (_Event.type) {

		case sf::Event::Closed: // Evento de control para cerrar la ventana

			_CoreWindow.close();
			break;

		case sf::Event::Resized: // Eventro para reescalar la ventana

			ResizeView(_CoreWindow, _CoreCamera);
			break;
		}
	}
}

/// <summary>
/// Controlador de todos los recursos del motor
/// </summary>
/// <param name="deltaTime"></param>
void Core::CoreUpdate(float deltaTime)
{
	_Game.Update(deltaTime);
}

/// <summary>
/// Controlador de todo el renderizado del motor
/// </summary>
void Core::CoreRender()
{
	_CoreWindow.clear();
	//_CoreWindow.setView(_CoreCamera);


	_Game.Draw(_Renderer);


	_CoreWindow.display();
}

