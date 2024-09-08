#pragma once

#ifndef GAME_H
#define GAME_H

#include<sstream>	// Secuencia de cadenas
#include <SFML/Graphics.hpp>

#include "Renderer.h"
#include "AudioManager.h"
#include "InputMAnager.h"
#include "FontManager.h"

class Game {

public:

	Game();								// Constructor

	void Update(float dt);				// Controlador del juego
	void Draw(Renderer& renderer);		// Renderizado del juego

	void InitGameWindow(sf::RenderWindow* window);	// Metodo para guardar la ventana del motor

private:
	sf::RenderWindow* _Window;

	FontManager _FontManager;			// Font manager del motor
	AudioManager _AudioManager;			// AudioManager del motor
	InputManager _InputManager;

	sf::Vector2i _MousePosWindow;		// Posicion del raton sobre la ventana
	sf::Vector2f _MousePosView;			// Posicion del raton sobre la camara

	sf::Text _UiText;					// Texto de la interfaz

	bool _EndGame;						// Esta variable nos dice si el juego ha terminado o no
	unsigned _Points;					// Aqui almacenamos los puntos conseguidos en el juego
	int _Health;						// Vida del jugador
	float _EnemySpawnTimer;				// Variable para calcular el tiempo hasta invocar un nuevo enemigo
	float _EnemySpawnTimerMax;			// Tiempo para invocar un enemigo
	int _MaxEnemies;					// Cantidad maxima de enemigos
	bool _MouseHeld;					// Con esta variable comprobamos si el jugador esta manetiendo pulsao el boton del raton

	std::map<std::string, sf::Texture*> _MonsterTextures;	// Diccionario donde vamos a guardar las texturas de los monstruos

	sf::Texture _WorldBackGroundTexture;					// Textura del background
	sf::Sprite _WorldBackGround;							// Background

	std::vector<sf::RectangleShape> _Enemies;		// Lista donde guardamos los enemigos que vamos creando
	sf::RectangleShape _Enemy;						// Variable base para generar enemigos

	void InitVariables();							// Metodo para inicializar variables
	void InitFonts();								// Metodo para inicializar el FontManager
	void InitText();								// Metodo para inicializar el texto de la interfaz
	void InitTextures();
	void InitSprites();
	void InitEnemies();								// Metodo para inicializar un enemigo

	void SpawnEnemy();								// Metodo para invocar un nuevo enemigo

	void UpdateMousePosition();						// Metodo para actualizar las posiciones del raton
	void UpdateText();								// Metodo para actualizar el texto en pantalla
	void UpdateEnemies();							// Metodo para actualizar los enemigos

	void RenderBackground(Renderer& renderer);		// MEtodo para renderizar el background
	void RenderText(Renderer& renderer);			// Metodo para renderizar el texto de la interfaz
	void RenderEnemies(Renderer& renderer);			// Metodo para renderizar a los enemigos
};

#endif
