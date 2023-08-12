#pragma once
#include "PieceMatrix.h"
#include "..\Const\Const.h"

class Level
{
public:
	Level(Piece (*matrix)[GLOBALS::ROW_MATRIX][GLOBALS::COLUMN_MATRIX]);
	bool CheckLevel();
	bool NextLevel();
private:
	int currentLevel;
	void LoadLevel();
	Piece (*matrix)[GLOBALS::ROW_MATRIX][GLOBALS::COLUMN_MATRIX];
};

