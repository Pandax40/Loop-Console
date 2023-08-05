#pragma once
#include<map>

class Piece
{
public:
	enum Type
	{
		Nodo,
		Recta,
		Curva,
		InterseccionTriple,
		InterseccionQuadruple
	};
	enum Face
	{
		Top,
		Right,
		Bottom,
		Left
	};
	Piece(const Type type);
	void Rotate();
	bool CheckFace(Face face);
private:
	Type pieceType;
	Face facing;
};

