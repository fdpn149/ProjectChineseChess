#pragma once
#include "Chess.h"
namespace ProjectChineseChess
{
	//�N
	ref class General : public Chess
	{
		bool inRange(Direction direct, int X, int Y);
	public:
		General(Color color, int id) : Chess(color, id) {}
		void Move(Board^ board, PictureBox^ piece) override;
		bool KingsFaceToFace(Board^ board, Direction direct, int X, int Y);
	};

}