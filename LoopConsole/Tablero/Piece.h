#pragma once
#include<map>

class Piece
{
public:
	enum Type
	{
		Node,
		Line,
		Curve,
		TripleJunction,
		QuadrupleJunction
	};
	enum Face
	{
		Top,
		Right,
		Bottom,
		Left
	};
	Piece();
	Piece(const Type type);
	void Rotate();
	const bool CheckFace(Face face);
	const Type GetType();
	const Face GetFace();
private:
	Type pieceType;
	Face facing;
};

