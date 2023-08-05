#include "Piece.h"
#include <iostream>
#include "../Utility/Random.h"

Piece::Piece(Type type)
{
	facing = static_cast<Face>(GenRandomNumber(0, 3));
	pieceType = type;
	auto it = conectors.find(facing);
	switch (type)
	{
	case Piece::Nodo:
		it->second = true;
		break;
	case Piece::Recta:
		it->second = true;
		for (int i = 0; i < 2; ++i)
		{
			++it;
			if (it == conectors.end()) 
				it = conectors.begin();
		}
		it->second = true;
		break;
	case Piece::Curva:
		it->second = true;
		++it;
		if (it == conectors.end()) 
			it = conectors.begin();
		it->second = true;
		break;
	case Piece::InterseccionTriple:
		if (it == conectors.begin()) 
			it = conectors.end();
		--it;
		for (int i = 0; i < 3; ++i)
		{
			(it++)->second = true;
			if (it == conectors.end()) 
				it = conectors.begin();
		}
		break;
	case Piece::InterseccionQuadruple:
		for (auto it = conectors.begin(); it != conectors.end(); ++it)
			it->second = true;
		break;
	default:
		break;
	}

	for (auto it = conectors.begin(); it != conectors.end(); ++it)
		std::cout << it->first << ' ' << it->second << '\n';
	std::cout << '\n';
}

void Piece::Rotate()
{
	auto it = conectors.find(facing);
	switch (pieceType)
	{
	case Piece::Nodo:
		it->second = false;
		++it;
		if (it == conectors.end())
			it = conectors.begin();
		it->second = true;
		break;
	case Piece::Recta:
		it = conectors.begin();
		if (facing == Top || facing == Bottom)
		{
			it->second = false;
			(++it)->second = true;
			(++it)->second = false;
			(++it)->second = true;
		}
		else
		{
			it->second = true;
			(++it)->second = false;
			(++it)->second = true;
			(++it)->second = false;
		}
		break;
	case Piece::Curva:
		it->second = false;
		for (int i = 0; i < 2; ++i)
		{
			++it;
			if (it == conectors.end())
				it = conectors.begin();
		}
		it->second = true;
		break;
	case Piece::InterseccionTriple:
		if (it == conectors.begin())
			it = conectors.end();
		--it;
		it->second = false;
		for (int i = 0; i < 3; ++i)
		{
			++it;
			if (it == conectors.end())
				it = conectors.begin();
		}
		it->second = true;
		break;
	default:
		break;
	}

	it = conectors.find(facing);
	++it;
	if (it == conectors.end())
		it = conectors.begin();
	facing = it->first;

	for (auto it = conectors.begin(); it != conectors.end(); ++it)
		std::cout << it->first << ' ' << it->second << '\n';
	std::cout << '\n';
}

bool Piece::CheckFace(Face face)
{
	return conectors.find(face)->second;
}
