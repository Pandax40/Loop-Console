#include "Piece.h"
#include <iostream>
#include "../Utility/Random.h"

Piece::Piece(Type type)
{
	facing = static_cast<Face>(GenRandomNumber(0, 3));
	pieceType = type;
}

void Piece::Rotate()
{
	switch (facing)
	{
	case Piece::Top:
		facing = Right;
		break;
	case Piece::Right:
		facing = Bottom;
		break;
	case Piece::Bottom:
		facing = Left;
		break;
	case Piece::Left:
		facing = Top;
		break;
	default:
		break;
	}
}

bool Piece::CheckFace(Face face)
{
	switch (pieceType)
	{
	case Piece::Nodo:
		return face == facing;
		break;
	case Piece::Recta:
		return face == facing || face == (facing + 2) % 4;
		break;
	case Piece::Curva:
		return face == facing || face == (facing + 1) % 4;
		break;
	case Piece::InterseccionTriple:
		if (facing == Top)
			return face == Left || face == Top || face == Right;	
		return face == (facing - 1) || face == facing || face == (facing + 1) % 4;
		break;
	case Piece::InterseccionQuadruple:
		return true;
		break;
	default:
		break;
	}
}
