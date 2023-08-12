#pragma once
#include "Piece.h"
#include "Level.h"
#include "../Graphics/Console.h"
#include "../Const/Const.h"

class PieceMatrix
{
public:
	PieceMatrix();
	void MoveUp();
	void MoveRight();
	void MoveDown();
	void MoveLeft();
	void Rotate();
private:
	int posX, posY;
	void FixUnions(int x, int y);
	void Selected(bool isSelected);
	Level level;
	Piece matrix[GLOBALS::ROW_MATRIX][GLOBALS::COLUMN_MATRIX];
};

