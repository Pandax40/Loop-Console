#include "Console.h"
#include "../Const/Const.h"

void Console::DrawPiece(Piece piece, int baseX, int baseY)
{	
	switch (piece.GetType())
	{
	case Piece::Node:
		for (int i = 0; i < GLOBALS::FIGURE_SIZE_Y; ++i)
		{
			printf("\x1b[%i;%iH", baseY + i + 1, baseX + 1);
			printf(GLOBALS::NODE_FIGURE[static_cast<int>(piece.GetFace())][i]);
		}
		break;
	case Piece::Line:
		for (int i = 0; i < GLOBALS::FIGURE_SIZE_Y; ++i)
		{
			printf("\x1b[%i;%iH", baseY + i + 1, baseX + 1);
			printf(GLOBALS::LINE_FIGURE[static_cast<int>(piece.GetFace())][i]);
		}
		break;
	case Piece::Curve:
		for (int i = 0; i < GLOBALS::FIGURE_SIZE_Y; ++i)
		{
			printf("\x1b[%i;%iH", baseY + i + 1, baseX + 1);
			printf(GLOBALS::CURVE_FIGURE[static_cast<int>(piece.GetFace())][i]);
		}
		break;
	case Piece::TripleJunction:
		for (int i = 0; i < GLOBALS::FIGURE_SIZE_Y; ++i)
		{
			printf("\x1b[%i;%iH", baseY + i + 1, baseX + 1);
			printf(GLOBALS::TRIPLE_FIGURE[static_cast<int>(piece.GetFace())][i]);
		}
		break;
	case Piece::QuadrupleJunction:
		for (int i = 0; i < GLOBALS::FIGURE_SIZE_Y; ++i)
		{
			printf("\x1b[%i;%iH", baseY + i + 1, baseX + 1);
			printf(GLOBALS::QUADRUPLE_FIGURE[i]);
		}
		break;
	default:
		break;
	}
}

void Console::FixUnions(int x, int y, Piece (*matrix)[GLOBALS::ROW_MATRIX][GLOBALS::COLUMN_MATRIX])
{
	if ((*matrix)[y][x].CheckFace(Piece::Top))
	{
		if (y == 0 or !(*matrix)[y - 1][x].CheckFace(Piece::Bottom))
			printf("\x1b[%d;%dH_", (y * GLOBALS::FIGURE_SIZE_Y + GLOBALS::MATRIX_BASE_Y), (x * GLOBALS::FIGURE_SIZE_X + GLOBALS::MATRIX_BASE_X) + 5);
		else if ((*matrix)[y - 1][x].CheckFace(Piece::Bottom))
			printf("\x1b[%d;%dH ", (y * GLOBALS::FIGURE_SIZE_Y + GLOBALS::MATRIX_BASE_Y), (x * GLOBALS::FIGURE_SIZE_X + GLOBALS::MATRIX_BASE_X) + 5);
	}
	else if (y != 0)
	{
		if ((*matrix)[y - 1][x].CheckFace(Piece::Bottom))
			printf("\x1b[%d;%dH_", (y * GLOBALS::FIGURE_SIZE_Y + GLOBALS::MATRIX_BASE_Y), (x * GLOBALS::FIGURE_SIZE_X + GLOBALS::MATRIX_BASE_X) + 5);
		else
			printf("\x1b[%d;%dH ", (y * GLOBALS::FIGURE_SIZE_Y + GLOBALS::MATRIX_BASE_Y), (x * GLOBALS::FIGURE_SIZE_X + GLOBALS::MATRIX_BASE_X) + 5);
	}
	else
		printf("\x1b[%d;%dH ", (y * GLOBALS::FIGURE_SIZE_Y + GLOBALS::MATRIX_BASE_Y), (x * GLOBALS::FIGURE_SIZE_X + GLOBALS::MATRIX_BASE_X) + 5);

	if ((*matrix)[y][x].CheckFace(Piece::Right))
	{
		if (x == GLOBALS::COLUMN_MATRIX - 1 or !(*matrix)[y][x + 1].CheckFace(Piece::Left))
		{
			printf("\x1b[%d;%dH  ", (y * GLOBALS::FIGURE_SIZE_Y + GLOBALS::MATRIX_BASE_Y) + 2, (x * GLOBALS::FIGURE_SIZE_X + GLOBALS::MATRIX_BASE_X) + 9);
			printf("\x1b[%d;%dH│ ", (y * GLOBALS::FIGURE_SIZE_Y + GLOBALS::MATRIX_BASE_Y) + 3, (x * GLOBALS::FIGURE_SIZE_X + GLOBALS::MATRIX_BASE_X) + 9);
		}
		else if ((*matrix)[y][x + 1].CheckFace(Piece::Left))
		{
			printf("\x1b[%d;%dH__", (y * GLOBALS::FIGURE_SIZE_Y + GLOBALS::MATRIX_BASE_Y) + 2, (x * GLOBALS::FIGURE_SIZE_X + GLOBALS::MATRIX_BASE_X) + 9);
			printf("\x1b[%d;%dH__", (y * GLOBALS::FIGURE_SIZE_Y + GLOBALS::MATRIX_BASE_Y) + 3, (x * GLOBALS::FIGURE_SIZE_X + GLOBALS::MATRIX_BASE_X) + 9);
		}

	}
	else if (x != GLOBALS::COLUMN_MATRIX - 1)
	{
		if ((*matrix)[y][x + 1].CheckFace(Piece::Left))
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

	if ((*matrix)[y][x].CheckFace(Piece::Bottom))
	{
		if (y == GLOBALS::ROW_MATRIX - 1 or !(*matrix)[y + 1][x].CheckFace(Piece::Top))
			printf("\x1b[%d;%dH_", (y * GLOBALS::FIGURE_SIZE_Y + GLOBALS::MATRIX_BASE_Y) + 5, (x * GLOBALS::FIGURE_SIZE_X + GLOBALS::MATRIX_BASE_X) + 5);
		else if ((*matrix)[y + 1][x].CheckFace(Piece::Top))
			printf("\x1b[%d;%dH ", (y * GLOBALS::FIGURE_SIZE_Y + GLOBALS::MATRIX_BASE_Y) + 5, (x * GLOBALS::FIGURE_SIZE_X + GLOBALS::MATRIX_BASE_X) + 5);
	}
	else if (y != GLOBALS::ROW_MATRIX - 1)
	{
		if ((*matrix)[y + 1][x].CheckFace(Piece::Top))
			printf("\x1b[%d;%dH_", (y * GLOBALS::FIGURE_SIZE_Y + GLOBALS::MATRIX_BASE_Y) + 5, (x * GLOBALS::FIGURE_SIZE_X + GLOBALS::MATRIX_BASE_X) + 5);
		else
			printf("\x1b[%d;%dH ", (y * GLOBALS::FIGURE_SIZE_Y + GLOBALS::MATRIX_BASE_Y) + 5, (x * GLOBALS::FIGURE_SIZE_X + GLOBALS::MATRIX_BASE_X) + 5);
	}

	if ((*matrix)[y][x].CheckFace(Piece::Left))
	{
		if (x == 0 or !(*matrix)[y][x - 1].CheckFace(Piece::Right))
		{
			printf("\x1b[%d;%dH  ", (y * GLOBALS::FIGURE_SIZE_Y + GLOBALS::MATRIX_BASE_Y) + 2, (x * GLOBALS::FIGURE_SIZE_X + GLOBALS::MATRIX_BASE_X));
			printf("\x1b[%d;%dH │", (y * GLOBALS::FIGURE_SIZE_Y + GLOBALS::MATRIX_BASE_Y) + 3, (x * GLOBALS::FIGURE_SIZE_X + GLOBALS::MATRIX_BASE_X));
		}
		else if ((*matrix)[y][x - 1].CheckFace(Piece::Right))
		{
			printf("\x1b[%d;%dH__", (y * GLOBALS::FIGURE_SIZE_Y + GLOBALS::MATRIX_BASE_Y) + 2, (x * GLOBALS::FIGURE_SIZE_X + GLOBALS::MATRIX_BASE_X));
			printf("\x1b[%d;%dH__", (y * GLOBALS::FIGURE_SIZE_Y + GLOBALS::MATRIX_BASE_Y) + 3, (x * GLOBALS::FIGURE_SIZE_X + GLOBALS::MATRIX_BASE_X));
		}

	}
	else if (x != 0)
	{
		if ((*matrix)[y][x - 1].CheckFace(Piece::Right))
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

void Console::InitScreen()
{
	printf("\x1b[?25l"); //Cursor Hidding
	printf("\x1b[%d;%dH", GLOBALS::ACTUAL_WINDOWS_SIZE_Y / 45, GLOBALS::WINDOW_SIZE_X / 26); //Initial Screen Position
	printf("\x1b[s  _                      \x1b[u\x1b[1B");
	printf("\x1b[s | |    ___   ___  _ __  \x1b[u\x1b[1B");
	printf("\x1b[s | |   / _ \\ / _ \\| '_ \\ \x1b[u\x1b[1B");
	printf("\x1b[s | |__| (_) | (_) | |_) |\x1b[u\x1b[1B");
	printf("\x1b[s |_____\\___/ \\___/| .__/ \x1b[u\x1b[1B");
	printf("\x1b[s                  |_|    \x1b[u\x1b[1B");
	printf("\x1b[1B\x1b[6D"); //Go down 1 lines and 6 back chars
	printf("\x1b[s   ____                      _      \x1b[u\x1b[1B");
	printf("\x1b[s  / ___|___  _ __  ___  ___ | | ___ \x1b[u\x1b[1B");
	printf("\x1b[s | |   / _ \\| '_ \\/ __|/ _ \\| |/ _ \\\x1b[u\x1b[1B");
	printf("\x1b[s | |__| (_) | | | \\__ \\ (_) | |  __/\x1b[u\x1b[1B");
	printf("\x1b[s  \\____\\___/|_| |_|___/\\___/|_|\\___|\x1b[u\x1b[1B");
	printf("\x1b[3B\x1b[6C");
	printf("PULSA ENTER PARA EMPEZAR");
}

void Console::EndScreen()
{
	printf("\x1b[?25l"); //Cursor Hidding
	printf("\x1b[%d;%dH", GLOBALS::ACTUAL_WINDOWS_SIZE_Y / 45, GLOBALS::WINDOW_SIZE_X / 23); //Initial Screen Position
	printf("\x1b[s  _____ _   _ _____ \x1b[u\x1b[1B");
	printf("\x1b[s |_   _| | | | ____|\x1b[u\x1b[1B");
	printf("\x1b[s   | | | |_| |  _|  \x1b[u\x1b[1B");
	printf("\x1b[s   | | |  _  | |___ \x1b[u\x1b[1B");
	printf("\x1b[s   |_| |_| |_|_____|\x1b[u\x1b[1B");
	printf("\x1b[1B"); //Go down 1 lines and 6 back chars
	printf("\x1b[s  _____ _   _ ____  \x1b[u\x1b[1B");
	printf("\x1b[s | ____| \\ | |  _ \\ \x1b[u\x1b[1B");
	printf("\x1b[s |  _| |  \\| | | | |\x1b[u\x1b[1B");
	printf("\x1b[s | |___| |\\  | |_| |\x1b[u\x1b[1B");
	printf("\x1b[s |_____|_| \\_|____/ \x1b[u\x1b[1B");
	printf("\x1b[2B\x1b[8D");
	printf("HAS COMPLETADO EL JUEGO, FELICIDADES");
}