#include "PieceMatrix.h"
#include "../Utility/Random.h"

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
		

	if (matrix[y][x].CheckFace(Piece::Right))
	{
		if (x == GLOBALS::COLUMN_MATIX - 1 or !matrix[y][x + 1].CheckFace(Piece::Left))
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
	else if (x != GLOBALS::COLUMN_MATIX - 1)
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
	printf("\x1b[%d;%dH", (y * GLOBALS::FIGURE_SIZE_Y + GLOBALS::MATRIX_BASE_Y) + 3, (x * GLOBALS::FIGURE_SIZE_X + GLOBALS::MATRIX_BASE_X) + 5);
}

PieceMatrix::PieceMatrix()
{
	for (int i = 0; i < GLOBALS::ROW_MATRIX; ++i)
	{
		for (int j = 0; j < GLOBALS::COLUMN_MATIX; ++j)
		{
			int randType = GenRandomNumber(0, 4);
			matrix[i][j] = Piece(static_cast<Piece::Type>(randType));
			Console::DrawPiece(matrix[i][j], j * GLOBALS::FIGURE_SIZE_X + GLOBALS::MATRIX_BASE_X, i * GLOBALS::FIGURE_SIZE_Y + GLOBALS::MATRIX_BASE_Y);
		}
	}
	for (int i = 0; i < GLOBALS::ROW_MATRIX; ++i)
		for (int j = 0; j < GLOBALS::COLUMN_MATIX; ++j)
			FixUnions(j, i);
	posX = posY = 0;
}

void PieceMatrix::MoveUp()
{
	if (posY == 0) return;
	--posY;
}

void PieceMatrix::MoveRight()
{
	if (posX == GLOBALS::COLUMN_MATIX - 1) return;
	++posX;
}

void PieceMatrix::MoveDown()
{
	if (posY == GLOBALS::ROW_MATRIX - 1) return;
	++posY;
}

void PieceMatrix::MoveLeft()
{
	if (posX == 0) return;
	--posX;
}

void PieceMatrix::Rotate()
{
	matrix[posY][posX].Rotate();
	Console::DrawPiece(matrix[posY][posX], posX * GLOBALS::FIGURE_SIZE_X + GLOBALS::MATRIX_BASE_X, posY * GLOBALS::FIGURE_SIZE_Y + GLOBALS::MATRIX_BASE_Y);
	FixUnions(posX, posY);
}
