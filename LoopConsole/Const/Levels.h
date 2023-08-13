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
	inline const Piece::Type Level_Two[GLOBALS::ROW_MATRIX][GLOBALS::COLUMN_MATRIX] = {
		Piece::Curve, Piece::Line, Piece::Node, Piece::Curve, Piece::Line, Piece::Curve,
		Piece::Line, Piece::Curve, Piece::Line, Piece::QuadrupleJunction, Piece::TripleJunction, Piece::TripleJunction,
		Piece::TripleJunction, Piece::QuadrupleJunction, Piece::Line, Piece::TripleJunction, Piece::Curve, Piece::Node,
		Piece::Node, Piece::Curve, Piece::TripleJunction, Piece::Line, Piece::Line, Piece::Curve,
		Piece::Curve, Piece::Line, Piece::TripleJunction, Piece::Node, Piece::Curve, Piece::Curve,
		Piece::Curve, Piece::TripleJunction, Piece::Line, Piece::Line, Piece::TripleJunction, Piece::Node,
		Piece::Node, Piece::Curve, Piece::TripleJunction, Piece::Line, Piece::QuadrupleJunction, Piece::Curve,
		Piece::Curve, Piece::Node, Piece::Curve, Piece::Line, Piece::TripleJunction, Piece::Node };
	inline const Piece::Type Level_Three[GLOBALS::ROW_MATRIX][GLOBALS::COLUMN_MATRIX] = {
		Piece::Node, Piece::Curve, Piece::Line, Piece::Node, Piece::Curve, Piece::Curve,
		Piece::Curve, Piece::TripleJunction, Piece::Curve, Piece::TripleJunction, Piece::TripleJunction, Piece::Node,
		Piece::Node, Piece::Node, Piece::Line, Piece::Line, Piece::Curve, Piece::Curve,
		Piece::TripleJunction, Piece::Line, Piece::QuadrupleJunction, Piece::TripleJunction, Piece::Node, Piece::Line,
		Piece::Line, Piece::Node, Piece::Curve, Piece::Curve, Piece::TripleJunction, Piece::TripleJunction,
		Piece::TripleJunction, Piece::Line, Piece::TripleJunction, Piece::Curve, Piece::Line, Piece::Node,
		Piece::Line, Piece::Node, Piece::Line, Piece::Curve, Piece::QuadrupleJunction, Piece::Curve,
		Piece::Node, Piece::Node, Piece::Curve, Piece::Curve, Piece::Node, Piece::Node };
	inline const Piece::Type Level_Four[GLOBALS::ROW_MATRIX][GLOBALS::COLUMN_MATRIX] = {
		Piece::Curve, Piece::Line, Piece::TripleJunction, Piece::Line, Piece::TripleJunction, Piece::Node,
		Piece::Line, Piece::Node, Piece::Node, Piece::Curve, Piece::QuadrupleJunction, Piece::Node,
		Piece::Line, Piece::TripleJunction, Piece::Line, Piece::Curve, Piece::Line, Piece::Node,
		Piece::Line, Piece::Node, Piece::Curve, Piece::Curve, Piece::TripleJunction, Piece::Curve,
		Piece::Node, Piece::Curve, Piece::TripleJunction, Piece::TripleJunction, Piece::QuadrupleJunction, Piece::Curve,
		Piece::Curve, Piece::TripleJunction, Piece::Curve, Piece::Curve, Piece::Line, Piece::Line,
		Piece::Line, Piece::Node, Piece::Curve, Piece::Line, Piece::TripleJunction, Piece::Line,
		Piece::Node, Piece::Node, Piece::TripleJunction, Piece::Node, Piece::Curve, Piece::Curve };
	inline const Piece::Type (*Levels[4])[GLOBALS::ROW_MATRIX][GLOBALS::COLUMN_MATRIX] = { &Level_One, &Level_Two, &Level_Three, &Level_Four };
}

