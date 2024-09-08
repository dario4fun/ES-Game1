#pragma once

#ifndef RENDERER_H
#define RENDERER_H

#include <SFML/Graphics.hpp>

/// <summary>
/// Esta clase se encarga de dibujar los distintos elementos en pantalla
/// </summary>
class Renderer
{

public:

	Renderer(sf::RenderWindow& window);				// Contrusctor

	void Draw(const sf::Drawable& drawable);		// Funcion que dibuja en pantalla

private:

	sf::RenderWindow& _MainWindow;					// Ventana sobre la que se va a dibujar los elementos
};

#endif 



