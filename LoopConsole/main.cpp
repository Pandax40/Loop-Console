// LoopConsole.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include "Tablero/Piece.h" 

int main()
{
    Piece piece(Piece::Type::InterseccionTriple);
    while (true)
    {
        piece.Rotate();
    }
}