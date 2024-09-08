#include "AudioManager.h"

/// <summary>
/// Es funcion carga un efecto de sonido
/// </summary>
/// <param name="name"> nombre del efecto</param>
/// <param name="filename"> ruta del archivo de sonido </param>
/// <returns> true or false </returns>
bool AudioManager::LoadSound(const std::string & name, const std::string & filename) {

    sf::SoundBuffer _Buffer; // Creamos un nuevo archivo de datos de sonidos

    // Cargamos el sonido en memoria
    if (!_Buffer.loadFromFile(filename)) {

        std::cout << "Error - no se ha posiso cargar el sonido " << filename << " \n";

        return false;
    }

    // Añadimos el buffer al diccionario de buffers de sonidos 
    _SoundBuffers[name] = _Buffer;

    // Por ultimo lo añadimos al diccionario de sonidos con el nombre del efecto el buffer que hemos cargado para despues encontrarlo mas rapido
    _Sounds[name].setBuffer(_SoundBuffers[name]);

    return true;
}

/// <summary>
/// Funcion que reproduce un sonido por su nombre
/// </summary>
/// <param name="name"> Nombre del sonido </param>
void AudioManager::PlaySound(const std::string& name) {

    if (_Sounds.find(name) != _Sounds.end()) _Sounds[name].play();
}

/// <summary>
/// Esta funcion para un sonido por su nombre
/// </summary>
/// <param name="name"> Nombre del sonido </param>
void AudioManager::StopSound(const std::string& name) {

    if (_Sounds.find(name) != _Sounds.end()) _Sounds[name].stop();
}

/// <summary>
/// Esta funcion carga una cancion desde un archivo local
/// </summary>
/// <param name="filename"> Ruta de la cacion </param>
/// <returns> true or false </returns>
bool AudioManager::LoadMusic(const std::string& filename) {
    return _Music.openFromFile(filename);
}

/// <summary>
/// Esta funcion reproduce una cancion
/// </summary>
void AudioManager::PlayMusic() { _Music.play(); }

/// <summary>
/// Esta funcion para una cancion
/// </summary>
void AudioManager::StopMusic() { _Music.stop(); }
