#include "Renderer.h"

/// <summary>
/// Contructor que inizializa la ventana para renderizar
/// </summary>
/// <param name="window"> Ventana donde se van a representar los elementos </param>
Renderer::Renderer(sf::RenderWindow& window) : _MainWindow(window) {}


/// <summary>
/// Metodo modular para dibujar los elementos
/// </summary>
/// <param name="drawable"> Elemento a dibujar </param>
void Renderer::Draw(const sf::Drawable& drawable) { _MainWindow.draw(drawable); }
