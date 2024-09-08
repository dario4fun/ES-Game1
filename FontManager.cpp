#include "FontManager.h"
#include <iostream>

/// <summary>
/// En esta funcion se carga cada una de las fuentes que queramos tener disponibles en nuestro motor
/// </summary>
void FontManager::LoadFonts() {

    LoadFont("Choco", "./Fonts/Choco Shake.ttf");

}

/// <summary>
/// Esta funcion carga la fuente al programa
/// </summary>
/// <param name="name"> Nombre de la fuente </param>
/// <param name="path"> Ruta local de la fuente</param>
void FontManager::LoadFont(const std::string& name, const std::string& path) {

    sf::Font _Font;

    if (!_Font.loadFromFile(path)) { std::cout << "Error al cargar la fuente: " << path << " \n"; }

    fonts[name] = _Font;
}

/// <summary>
/// Es ta funcion devuelve una fuente buscandola a partir de su nombre
/// </summary>
/// <param name="name"> Nombre de la fuente </param>
/// <returns> Font </returns>
const sf::Font& FontManager::GetFont(const std::string& name) const {

    auto _Font = fonts.find(name);

    if (_Font != fonts.end()) return _Font->second;
    else std::cout << "No existe la fuente: " << name << " \n";
}

