#pragma once
#include "../Tablero/Piece.h"
#include "../Const/Const.h"

namespace Levels
{
	inline const Piece::Type Level_One[GLOBALS::ROW_MATRIX][GLOBALS::COLUMN_MATRIX] = {
		Piece::Node, Piece::Curve, Piece::Line, Piece::TripleJunction, Piece::Node, Piece::Node,
		Piece::Line, Piece::Line, Piece::Node, Piece::QuadrupleJunction, Piece::Line, Piece::TripleJunction,
		Piece::TripleJunction, Piece::TripleJunction, Piece::Node, Piece::Line, Piece::Node, Piece::TripleJunction,
		Piece::Curve, Piece::TripleJunction, Piece::Line, Piece::TripleJunction, Piece::Curve, Piece::Curve,
		Piece::Node, Piece::TripleJunction, Piece::Curve, Piece::Curve, Piece::QuadrupleJunction, Piece::Node,
		Piece::Curve, Piece::TripleJunction, Piece::TripleJunction, Piece::Line, Piece::TripleJunction, Piece::Curve,
		Piece::TripleJunction, Piece::QuadrupleJunction, Piece::Node, Piece::Curve, Piece::Curve, Piece::Node,
		Piece::Curve, Piece::TripleJunction, Piece::Line, Piece::TripleJunction, Piece::TripleJunction, Piece::Node };
	inline const Piece::Type (*Levels[1])[GLOBALS::ROW_MATRIX][GLOBALS::COLUMN_MATRIX] = { &Level_One };
}

