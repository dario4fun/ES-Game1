#include "Game.h"

void Game::InitGameWindow(sf::RenderWindow* window)
{
    _Window = window;
}

/// <summary>
/// En esta funcion se cargan las variables de inicio del juego
/// </summary>
void Game::InitVariables()
{

    _EndGame = false;
    _Points = 0;
    _Health = 10;
    _EnemySpawnTimerMax = 10.f;
    _EnemySpawnTimer = _EnemySpawnTimerMax;
    _MaxEnemies = 5;
    _MouseHeld = false;
}

/// <summary>
/// Esto es un enemigo base que luego usaremos para generar clones de el y modificarlos
/// </summary>
void Game::InitEnemies()
{
    _Enemy.setPosition(10.f, 10.f);
    _Enemy.setSize(sf::Vector2f(50.f, 50.f));
    _Enemy.setFillColor(sf::Color::Cyan);
}

/// <summary>
/// Cargamos las fuentes del motor
/// </summary>
void Game::InitFonts()
{
    _FontManager.LoadFonts();
}

/// <summary>
/// Asignamos la fuente al texto de la ventat y le damos tamaño y color
/// </summary>
void Game::InitText()
{
    _UiText.setFont(_FontManager.GetFont("Choco"));
    _UiText.setCharacterSize(24);
    _UiText.setFillColor(sf::Color::White);
    _UiText.setString("NONE");
}

/// <summary>
/// Inicializamos las texturas de los monstruos y del background
/// </summary>
void Game::InitTextures()
{
    _MonsterTextures["m1"] = new sf::Texture();
    _MonsterTextures["m1"]->loadFromFile("./Resources/Monsters/Monster1.png");

    _MonsterTextures["m2"] = new sf::Texture();
    _MonsterTextures["m2"]->loadFromFile("./Resources/Monsters/Monster2.png");

    _MonsterTextures["m3"] = new sf::Texture();
    _MonsterTextures["m3"]->loadFromFile("./Resources/Monsters/Monster3.png");

    _MonsterTextures["m4"] = new sf::Texture();
    _MonsterTextures["m4"]->loadFromFile("./Resources/Monsters/Monster4.png");

    if (!_WorldBackGroundTexture.loadFromFile("./Resources/bg.png")) {

        std::cout << "Error al cargar la imagen del background" << " \n";
    }

    
}

/// <summary>
/// Cargamos el sprite del background
/// </summary>
void Game::InitSprites()
{
    _WorldBackGround.setTexture(_WorldBackGroundTexture);
}


// Constructor donde se inizializa el juego
Game::Game()
{
	InitVariables();
	InitFonts();
	InitText();
    InitTextures();
    InitSprites();
	InitEnemies();
}

/// <summary>
/// Invocamos un enemigo aleatorio entre 5 posibilidades
/// </summary>
void Game::SpawnEnemy()
{
    _Enemy.setPosition(
        static_cast<float>(rand() % static_cast<int>(_Window->getSize().x - _Enemy.getSize().x)),
        0.f
    );

    int type = rand() % 5;

    switch (type)
    {
    case 0:
        _Enemy.setFillColor(sf::Color::Magenta);
        _Enemy.setSize(sf::Vector2f(30.f, 30.f));
        _Enemy.setTexture(_MonsterTextures["m1"]);
        break;
    case 1:
        _Enemy.setFillColor(sf::Color::Blue);
        _Enemy.setSize(sf::Vector2f(40.f, 40.f));
        _Enemy.setTexture(_MonsterTextures["m2"]);
        break;
    case 2:
        _Enemy.setFillColor(sf::Color::Cyan);
        _Enemy.setSize(sf::Vector2f(60.f, 60.f));
        _Enemy.setTexture(_MonsterTextures["m3"]);
        break;
    case 3:
        _Enemy.setFillColor(sf::Color::Red);
        _Enemy.setSize(sf::Vector2f(80.f, 80.f));
        _Enemy.setTexture(_MonsterTextures["m4"]);
        break;
    case 4:
        _Enemy.setFillColor(sf::Color::Yellow);
        _Enemy.setSize(sf::Vector2f(110.f, 110.f));
        _Enemy.setTexture(_MonsterTextures["m1"]);
        break;
    }

    _Enemies.push_back(_Enemy);
}

/// <summary>
/// Actualiza la posicion del raton
/// </summary>
void Game::UpdateMousePosition() {
    _MousePosWindow = sf::Mouse::getPosition(*_Window);
    _MousePosView = _Window->mapPixelToCoords(_MousePosWindow);
}

/// <summary>
/// Actualiza los puntos de vida
/// </summary>
void Game::UpdateText()
{
    std::stringstream ss;

    ss << "Points: " << _Points << "\n" << "Health: " << _Health << "\n";

    _UiText.setString(ss.str());
}

/// <summary>
/// Este metodo es el que controla a los enemigos
/// </summary>
void Game::UpdateEnemies()
{
    // Comprobamos si hay el maximo de enemigos y si no, invocamos uno y lo guardamos
    if (_Enemies.size() < _MaxEnemies) {

        if (_EnemySpawnTimer >= _EnemySpawnTimerMax) {

            SpawnEnemy();
            _EnemySpawnTimer = 0.f;
        }
        else _EnemySpawnTimer += 1.f;
    }

    // Por cada enemigo guardado lo movemos hacia abajo
    for (int i = 0; i < _Enemies.size(); i++) {

        _Enemies[i].move(0.f, 1.f);

        if (_Enemies[i].getPosition().y > _Window->getSize().y) {

            _Enemies.erase(_Enemies.begin() + i);
            _Health--;

            if (_Health <= 0) _EndGame = true;
        }

    }

    // Si pulsamos el raton y no lo estamos manteniendo
    if (_InputManager.IsMouseButtonPressed(sf::Mouse::Left)) {

        if (_MouseHeld == false) { 

            _MouseHeld = true;
            bool _Delete = false;

            // Comprobamos si hay algun enemigo en esa posicion y lo destruimos
            for (int i = 0; i < _Enemies.size() && _Delete == false; i++) {


                if (_Enemies[i].getGlobalBounds().contains(_MousePosView)) {

                    if (_Enemies[i].getFillColor() == sf::Color::Magenta)  _Points += 10.f;
                    else if (_Enemies[i].getFillColor() == sf::Color::Blue) _Points += 7.f;
                    else if (_Enemies[i].getFillColor() == sf::Color::Cyan) _Points += 5.f;
                    else if (_Enemies[i].getFillColor() == sf::Color::Red) _Points += 3.f;
                    else if (_Enemies[i].getFillColor() == sf::Color::Yellow) _Points += 1.f;

                    _Delete = true;
                    _Enemies.erase(_Enemies.begin() + i);
                }
            }

        }

    }
    else _MouseHeld = false;
}

/// <summary>
/// Funcion que se encarga de la logica del juego
/// </summary>
/// <param name="dt"> delta time </param>
void Game::Update(float dt)
{
    if (!_EndGame) {
        
        UpdateMousePosition();
        UpdateText();
        UpdateEnemies();
    }
    
}

/// <summary>
/// Funcion para renderizar el fondo del juego
/// </summary>
/// <param name="renderer"></param>
void Game::RenderBackground(Renderer& renderer)
{
    renderer.Draw(_WorldBackGround);
}

/// <summary>
/// Funcion para renderizar el texto de los puntos
/// </summary>
/// <param name="renderer"></param>
void Game::RenderText(Renderer& renderer)
{
    renderer.Draw(_UiText);
}

// Funcion para dibujar cada uno de los enemigos
void Game::RenderEnemies(Renderer& renderer)
{

    // Render the enemies
    for (auto& e : _Enemies) {

        renderer.Draw(e);
    }
}

/// <summary>
/// Funcion que se encarga de dibujar todos los elementos del juego
/// </summary>
/// <param name="renderer"></param>
void Game::Draw(Renderer& renderer) {
    
    RenderBackground(renderer);

    RenderEnemies(renderer);

    RenderText(renderer);
}




