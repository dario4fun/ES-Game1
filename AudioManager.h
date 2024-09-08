#pragma once

#ifndef AUDIO_MANAGER_H
#define AUDIO_MANAGER_H

#include <SFML/Audio.hpp>

#include <unordered_map>
#include <string>
#include<iostream>	

/// <summary>
/// Esta clase se encarga de controlar todo lo relevante de los efectos de sonidos y canciones de fondo
/// </summary>
class AudioManager {

public:

    bool LoadSound(const std::string& name, const std::string& filename);   // Esta funcion carga un efecto de sonido
    void PlaySound(const std::string& name);                                // Esta funcion reproduce un efecto de sonido
    void StopSound(const std::string& name);                                // Esta funcion detiene un efecto de sonido

    bool LoadMusic(const std::string& filename);                            // Esta funcion carga una cancion para un background
    void PlayMusic();                                                       // Esta funcion reproduce una cancion para un background
    void StopMusic();                                                       // Esta funcion detiene una cancion para un background

private:

    std::unordered_map<std::string, sf::SoundBuffer> _SoundBuffers;         // Diccionario de buffers de sonido para cada sonido
    std::unordered_map<std::string, sf::Sound> _Sounds;                     // Diccionario de sonidos
    sf::Music _Music;                                                       // Variable para canciones largas como las canciones de background en bucle
};

#endif

