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
	std::map<Face, bool> conectors = { {Top, false}, { Right, false }, { Bottom, false }, { Left, false } };
	Face facing;
};

