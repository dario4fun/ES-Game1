#pragma once

#ifndef CORE_H
#define CORE_H

#include<iostream>

#include "Renderer.h"
#include "InputManager.h"
#include "Game.h"

class Core
{

public:

	Core();											// Constructor

	void Run();										// Ejecucion del motor


private:

	sf::RenderWindow _CoreWindow;					// Ventana de ejecucion del motor
	sf::View _CoreCamera;							// Camara principal del motor

	Renderer _Renderer;								// Renderizador del motor
	InputManager _InputManager;						// Controlador de entradas del usuario
	Game _Game;										// Controlador del juego

	void InitGame();
	void ProcessInput();							// Controlador de eventos del usuario
	void CoreUpdate(float dt);						// Controlador del motor
	void CoreRender();								// Controlador del renderizado

};

#endif


