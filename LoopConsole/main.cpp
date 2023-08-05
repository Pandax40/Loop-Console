// LoopConsole.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include "Tablero/Piece.h" 

int main()
{
    Piece piece(Piece::Type::Recta);
    while (true)
    {
        piece.Rotate();
        std::cout << std::boolalpha << piece.CheckFace(Piece::Top) << ' ';
        std::cout << std::boolalpha << piece.CheckFace(Piece::Right) << ' ';
        std::cout << std::boolalpha << piece.CheckFace(Piece::Bottom) << ' ';
        std::cout << std::boolalpha << piece.CheckFace(Piece::Left) << '\n';
    }
}