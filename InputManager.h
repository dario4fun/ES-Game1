#pragma once

#ifndef INPUTMANAGER_H
#define INPUTMANAGER_H

#include <SFML/Window.hpp>
#include <map>

/// <summary>
/// Clase que se encarga de controlar los inputs del usuario por teclado y raton
/// </summary>
class InputManager
{
public:

	void ProcessEvent(const sf::Event& event);				// Controlador de todo los imputs marca que esta pulsando el usuario
	bool IsKeyPressed(sf::Keyboard::Key key);				// Funcion que comprueba si una tecla esta pulsada o no
	bool IsMouseButtonPressed(sf::Mouse::Button button);	// Funcion que comprueba si una tecla del raton esta pulsada o no

private:

	std::map<sf::Keyboard::Key, bool> _KeyMap;				// Lista de booleanos de cada tecla para saber si se esta pulsando o no cada tecla del teclado
	std::map<sf::Mouse::Button, bool> _MouseMap;			// Lista de booleanos de cada tecla para saber si se esta pulsando o no cada tecla del raton
};

#endif
