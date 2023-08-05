#pragma once
#include <utility>
#include "Piece.h"
#include "../Const/Const.h"

class PieceMatrix
{
public:
	PieceMatrix();
private:
	Piece matrix[CONST::ROW_MATRIX][CONST::COLUMN_MATIX];
};

