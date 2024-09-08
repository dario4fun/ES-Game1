#include "InputManager.h"
#include "iostream"
/// <summary>
/// Metodo que actualiza la lista de los botones que estan pulsado del raton y del teclado
/// </summary>
/// <param name="event"></param>
void InputManager::ProcessEvent(const sf::Event& event) {

	switch (event.type)
	{
	case sf::Event::KeyPressed: _KeyMap[event.key.code] = true; break;
	case sf::Event::KeyReleased: _KeyMap[event.key.code] = false; break;
	case sf::Event::MouseButtonPressed: _KeyMap[event.key.code] = true; break;
	case sf::Event::MouseButtonReleased: _KeyMap[event.key.code] = false; break;
	}
}

/// <summary>
/// Metodo que devuelve si una tecla del teclado esta pulsada
/// </summary>
/// <param name="key"> Tecla pulsada </param>
/// <returns> true or false </returns>
bool InputManager::IsKeyPressed(sf::Keyboard::Key key) { return _KeyMap[key]; }

/// <summary>
/// Metodo que devuelve si una tecla del raton esta pulsada
/// </summary>
/// <param name="button"> Boton pulsado </param>
/// <returns> true or false </returns>
bool InputManager::IsMouseButtonPressed(sf::Mouse::Button button) { 

	return sf::Mouse::isButtonPressed(button);

}

