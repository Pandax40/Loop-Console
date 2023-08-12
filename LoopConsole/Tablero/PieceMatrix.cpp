#include "PieceMatrix.h"
#include <iostream>

void PieceMatrix::FixUnions(int x, int y)
{
	if (matrix[y][x].CheckFace(Piece::Top))
	{
		if (y == 0 or !matrix[y - 1][x].CheckFace(Piece::Bottom))
			printf("\x1b[%d;%dH_", (y * GLOBALS::FIGURE_SIZE_Y + GLOBALS::MATRIX_BASE_Y), (x * GLOBALS::FIGURE_SIZE_X + GLOBALS::MATRIX_BASE_X) + 5);
		else if (matrix[y - 1][x].CheckFace(Piece::Bottom))
			printf("\x1b[%d;%dH ", (y * GLOBALS::FIGURE_SIZE_Y + GLOBALS::MATRIX_BASE_Y), (x * GLOBALS::FIGURE_SIZE_X + GLOBALS::MATRIX_BASE_X) + 5);
	}
	else if (y != 0)
	{
		if(matrix[y - 1][x].CheckFace(Piece::Bottom))
			printf("\x1b[%d;%dH_", (y * GLOBALS::FIGURE_SIZE_Y + GLOBALS::MATRIX_BASE_Y), (x * GLOBALS::FIGURE_SIZE_X + GLOBALS::MATRIX_BASE_X) + 5);
		else
			printf("\x1b[%d;%dH ", (y * GLOBALS::FIGURE_SIZE_Y + GLOBALS::MATRIX_BASE_Y), (x * GLOBALS::FIGURE_SIZE_X + GLOBALS::MATRIX_BASE_X) + 5);
	}
	else
		printf("\x1b[%d;%dH ", (y * GLOBALS::FIGURE_SIZE_Y + GLOBALS::MATRIX_BASE_Y), (x * GLOBALS::FIGURE_SIZE_X + GLOBALS::MATRIX_BASE_X) + 5);

	if (matrix[y][x].CheckFace(Piece::Right))
	{
		if (x == GLOBALS::COLUMN_MATRIX - 1 or !matrix[y][x + 1].CheckFace(Piece::Left))
		{
			printf("\x1b[%d;%dH  ", (y * GLOBALS::FIGURE_SIZE_Y + GLOBALS::MATRIX_BASE_Y) + 2, (x * GLOBALS::FIGURE_SIZE_X + GLOBALS::MATRIX_BASE_X) + 9);
			printf("\x1b[%d;%dH│ ", (y * GLOBALS::FIGURE_SIZE_Y + GLOBALS::MATRIX_BASE_Y) + 3, (x * GLOBALS::FIGURE_SIZE_X + GLOBALS::MATRIX_BASE_X) + 9);
		}
		else if (matrix[y][x + 1].CheckFace(Piece::Left))
		{
			printf("\x1b[%d;%dH__", (y * GLOBALS::FIGURE_SIZE_Y + GLOBALS::MATRIX_BASE_Y) + 2, (x * GLOBALS::FIGURE_SIZE_X + GLOBALS::MATRIX_BASE_X) + 9);
			printf("\x1b[%d;%dH__", (y * GLOBALS::FIGURE_SIZE_Y + GLOBALS::MATRIX_BASE_Y) + 3, (x * GLOBALS::FIGURE_SIZE_X + GLOBALS::MATRIX_BASE_X) + 9);
		}
			
	}
	else if (x != GLOBALS::COLUMN_MATRIX - 1)
	{
		if (matrix[y][x + 1].CheckFace(Piece::Left))
		{
			printf("\x1b[%d;%dH  ", (y * GLOBALS::FIGURE_SIZE_Y + GLOBALS::MATRIX_BASE_Y) + 2, (x * GLOBALS::FIGURE_SIZE_X + GLOBALS::MATRIX_BASE_X) + 9);
			printf("\x1b[%d;%dH │", (y * GLOBALS::FIGURE_SIZE_Y + GLOBALS::MATRIX_BASE_Y) + 3, (x * GLOBALS::FIGURE_SIZE_X + GLOBALS::MATRIX_BASE_X) + 9);
		}
		else
		{
			printf("\x1b[%d;%dH  ", (y * GLOBALS::FIGURE_SIZE_Y + GLOBALS::MATRIX_BASE_Y) + 2, (x * GLOBALS::FIGURE_SIZE_X + GLOBALS::MATRIX_BASE_X) + 9);
			printf("\x1b[%d;%dH  ", (y * GLOBALS::FIGURE_SIZE_Y + GLOBALS::MATRIX_BASE_Y) + 3, (x * GLOBALS::FIGURE_SIZE_X + GLOBALS::MATRIX_BASE_X) + 9);
		}
	}

	if (matrix[y][x].CheckFace(Piece::Bottom))
	{
		if (y == GLOBALS::ROW_MATRIX - 1 or !matrix[y + 1][x].CheckFace(Piece::Top))
			printf("\x1b[%d;%dH_", (y * GLOBALS::FIGURE_SIZE_Y + GLOBALS::MATRIX_BASE_Y) + 5, (x * GLOBALS::FIGURE_SIZE_X + GLOBALS::MATRIX_BASE_X) + 5);
		else if (matrix[y + 1][x].CheckFace(Piece::Top))
			printf("\x1b[%d;%dH ", (y * GLOBALS::FIGURE_SIZE_Y + GLOBALS::MATRIX_BASE_Y) + 5, (x * GLOBALS::FIGURE_SIZE_X + GLOBALS::MATRIX_BASE_X) + 5);
	}
	else if (y != GLOBALS::ROW_MATRIX - 1)
	{
		if (matrix[y + 1][x].CheckFace(Piece::Top))
			printf("\x1b[%d;%dH_", (y * GLOBALS::FIGURE_SIZE_Y + GLOBALS::MATRIX_BASE_Y) + 5, (x * GLOBALS::FIGURE_SIZE_X + GLOBALS::MATRIX_BASE_X) + 5);
		else
			printf("\x1b[%d;%dH ", (y * GLOBALS::FIGURE_SIZE_Y + GLOBALS::MATRIX_BASE_Y) + 5, (x * GLOBALS::FIGURE_SIZE_X + GLOBALS::MATRIX_BASE_X) + 5);
	}

	if (matrix[y][x].CheckFace(Piece::Left))
	{
		if (x == 0 or !matrix[y][x - 1].CheckFace(Piece::Right))
		{
			printf("\x1b[%d;%dH  ", (y * GLOBALS::FIGURE_SIZE_Y + GLOBALS::MATRIX_BASE_Y) + 2, (x * GLOBALS::FIGURE_SIZE_X + GLOBALS::MATRIX_BASE_X));
			printf("\x1b[%d;%dH │", (y * GLOBALS::FIGURE_SIZE_Y + GLOBALS::MATRIX_BASE_Y) + 3, (x * GLOBALS::FIGURE_SIZE_X + GLOBALS::MATRIX_BASE_X));
		}
		else if (matrix[y][x - 1].CheckFace(Piece::Right))
		{
			printf("\x1b[%d;%dH__", (y * GLOBALS::FIGURE_SIZE_Y + GLOBALS::MATRIX_BASE_Y) + 2, (x * GLOBALS::FIGURE_SIZE_X + GLOBALS::MATRIX_BASE_X));
			printf("\x1b[%d;%dH__", (y * GLOBALS::FIGURE_SIZE_Y + GLOBALS::MATRIX_BASE_Y) + 3, (x * GLOBALS::FIGURE_SIZE_X + GLOBALS::MATRIX_BASE_X));
		}

	}
	else if (x != 0)
	{
		if (matrix[y][x - 1].CheckFace(Piece::Right))
		{
			printf("\x1b[%d;%dH  ", (y * GLOBALS::FIGURE_SIZE_Y + GLOBALS::MATRIX_BASE_Y) + 2, (x * GLOBALS::FIGURE_SIZE_X + GLOBALS::MATRIX_BASE_X));
			printf("\x1b[%d;%dH│ ", (y * GLOBALS::FIGURE_SIZE_Y + GLOBALS::MATRIX_BASE_Y) + 3, (x * GLOBALS::FIGURE_SIZE_X + GLOBALS::MATRIX_BASE_X));
		}
		else
		{
			printf("\x1b[%d;%dH  ", (y * GLOBALS::FIGURE_SIZE_Y + GLOBALS::MATRIX_BASE_Y) + 2, (x * GLOBALS::FIGURE_SIZE_X + GLOBALS::MATRIX_BASE_X));
			printf("\x1b[%d;%dH  ", (y * GLOBALS::FIGURE_SIZE_Y + GLOBALS::MATRIX_BASE_Y) + 3, (x * GLOBALS::FIGURE_SIZE_X + GLOBALS::MATRIX_BASE_X));
		}
	}
}

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
	printf("\x1b[?25l");

	for (int i = 0; i < GLOBALS::ROW_MATRIX; ++i)
		for (int j = 0; j < GLOBALS::COLUMN_MATRIX; ++j)
			FixUnions(j, i);
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
	FixUnions(posX, posY);
	Selected(true);
	//if (level.CheckLevel()) 
	//	level.NextLevel();
}
