#include "PieceMatrix.h"
#include "../Utility/Random.h"

PieceMatrix::PieceMatrix()
{
	for (int i = 0; i < CONST::ROW_MATRIX; ++i)
	{
		for (int j = 0; j < CONST::COLUMN_MATIX; ++j)
		{
			int randType = GenRandomNumber(0, 4);
			matrix[i][j] = Piece(static_cast<Piece::Type>(randType));
		}
	}
}
