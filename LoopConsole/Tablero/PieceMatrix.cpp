#include "PieceMatrix.h"
#include <iostream>

void PieceMatrix::Selected(bool isSelected)
{
	printf("\x1b[%d;%dH", (posY * GLOBALS::FIGURE_SIZE_Y + GLOBALS::MATRIX_BASE_Y) + 3, (posX * GLOBALS::FIGURE_SIZE_X + GLOBALS::MATRIX_BASE_X) + 5);
	if (isSelected)
		printf("\x1b[46m");
	std::string a;
	Piece::Type type = matrix[posY][posX].GetType();
	if (type == Piece::Line and (matrix[posY][posX].GetFace() == Piece::Face::Right or matrix[posY][posX].GetFace() == Piece::Face::Left))
		std::cout << '_';
	else if (type == Piece::Curve and (matrix[posY][posX].GetFace() == Piece::Face::Left or matrix[posY][posX].GetFace() == Piece::Face::Top))
		std::cout << '_';
	else if (type == Piece::TripleJunction and matrix[posY][posX].GetFace() == Piece::Face::Top)
		std::cout << '_';
	else
		std::cout << ' ';
	printf("\x1b[0m");
}

PieceMatrix::PieceMatrix()
{
	level = Level(&matrix);
	posX = posY = 0;
	Selected(true);
}

void PieceMatrix::MoveUp()
{
	Selected(false);
	if (posY != 0) 
		--posY;
	Selected(true);
}

void PieceMatrix::MoveRight()
{
	Selected(false);
	if (posX != GLOBALS::COLUMN_MATRIX - 1)
		++posX;
	Selected(true);
}

void PieceMatrix::MoveDown()
{
	Selected(false);
	if (posY != GLOBALS::ROW_MATRIX - 1)
		++posY;
	Selected(true);
}

void PieceMatrix::MoveLeft()
{
	Selected(false);
	if (posX != 0) 
		--posX;
	Selected(true);
}

void PieceMatrix::Rotate()
{
	matrix[posY][posX].Rotate();
	Console::DrawPiece(matrix[posY][posX], posX * GLOBALS::FIGURE_SIZE_X + GLOBALS::MATRIX_BASE_X, posY * GLOBALS::FIGURE_SIZE_Y + GLOBALS::MATRIX_BASE_Y);
	Console::FixUnions(posX, posY, &matrix);
	Selected(true);
	if (level.CheckLevel())
		level.NextLevel();
		
}
