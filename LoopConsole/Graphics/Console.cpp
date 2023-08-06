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
