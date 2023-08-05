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
	case Piece::Node:
		return face == facing;
		break;
	case Piece::Line:
		return face == facing || face == (facing + 2) % 4;
		break;
	case Piece::Curve:
		return face == facing || face == (facing + 1) % 4;
		break;
	case Piece::TripleJunction:
		if (facing == Top)
			return face == Left || face == Top || face == Right;	
		return face == (facing - 1) || face == facing || face == (facing + 1) % 4;
		break;
	case Piece::QuadrupleJunction:
		return true;
		break;
	default:
		break;
	}
}
