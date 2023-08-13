#pragma once
#include "../Tablero/Piece.h"
#include "../Const/Const.h"

namespace Console
{
	void DrawPiece(Piece piece, int baseX, int baseY);
	void FixUnions(int x, int y, Piece (*matrix)[GLOBALS::ROW_MATRIX][GLOBALS::COLUMN_MATRIX]);
	void InitScreen();
	void EndScreen();
}

