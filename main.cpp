#include "Core.h"

/// <summary>
/// Esta clase inicia la ejecucion del programa
/// </summary>
int main()
{
    // Inizializamos una semilla para numeros random dentro del motor
    srand(static_cast<unsigned>(time(NULL)));

    Core _Core;
    _Core.Run();     // Ejecucion del motor

    return 0;       // Fin del programa
}
