#pragma once
#include "Piece.h"
#include "..\Const\Const.h"

class Level
{
public:
	Level();
	Level(Piece (*matrix)[GLOBALS::ROW_MATRIX][GLOBALS::COLUMN_MATRIX]);
	bool CheckLevel();
	bool NextLevel();

	static inline bool LEVELS_FINISHED = false;

private:
	int currentLevel;
	void LoadLevel();
	Piece (*matrix)[GLOBALS::ROW_MATRIX][GLOBALS::COLUMN_MATRIX];
};

