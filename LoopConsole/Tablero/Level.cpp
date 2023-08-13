#include "Level.h"
#include "../Const/Levels.h"
#include "../Utility/Random.h"
#include "../Graphics/Console.h"
#include <windows.h>

Level::Level()
{
	currentLevel = -1;
	matrix = nullptr;
}

Level::Level(Piece (*matrix)[GLOBALS::ROW_MATRIX][GLOBALS::COLUMN_MATRIX])
{
	this->matrix = matrix;
	currentLevel = 0;
	LoadLevel();
}

void Level::LoadLevel()
{
	for (int i = 0; i < GLOBALS::ROW_MATRIX; ++i)
	{
		for (int j = 0; j < GLOBALS::COLUMN_MATRIX; ++j)
		{
			int randType = GenRandomNumber(0, 4);
			(*matrix)[i][j] = Piece((*Levels::Levels[currentLevel])[i][j]);
			Console::DrawPiece((*matrix)[i][j], j * GLOBALS::FIGURE_SIZE_X + GLOBALS::MATRIX_BASE_X, i * GLOBALS::FIGURE_SIZE_Y + GLOBALS::MATRIX_BASE_Y);
		}
	}
	for (int i = 0; i < GLOBALS::ROW_MATRIX; ++i)
		for (int j = 0; j < GLOBALS::COLUMN_MATRIX; ++j)
			Console::FixUnions(j, i, matrix);
}


bool Level::CheckLevel()
{
	for (int i = 0; i < GLOBALS::ROW_MATRIX; ++i)
	{
		for (int j = 0; j < GLOBALS::COLUMN_MATRIX; ++j)
		{
			Piece::Type type = (*matrix)[i][j].GetType();
			if ((*matrix)[i][j].CheckFace(Piece::Top) and (i == 0 or !(*matrix)[i - 1][j].CheckFace(Piece::Bottom))) return false;
			else if ((*matrix)[i][j].CheckFace(Piece::Right) and (j == GLOBALS::COLUMN_MATRIX - 1 or !(*matrix)[i][j + 1].CheckFace(Piece::Left))) return false;
			else if ((*matrix)[i][j].CheckFace(Piece::Bottom) and (i == GLOBALS::ROW_MATRIX - 1 or !(*matrix)[i + 1][j].CheckFace(Piece::Top))) return false;
			else if ((*matrix)[i][j].CheckFace(Piece::Left) and (j == 0 or !(*matrix)[i][j - 1].CheckFace(Piece::Right))) return false;
		}
	}
	return true;
}

bool Level::NextLevel()
{
	++currentLevel;
	if (currentLevel < sizeof(Levels::Levels) / sizeof(void*))
	{
		Sleep(1000);
		LoadLevel();
	}	
	else
	{
		LEVELS_FINISHED = true;
		return false;
	}
	return true;
}
