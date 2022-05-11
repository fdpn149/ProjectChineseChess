#pragma once
#include "Chess.h"
namespace ProjectChineseChess
{
	//±N
	ref class General : public Chess
	{
		bool inRange(Direction direct, int X, int Y);
		void pushGreenAndRed(Board^ board, int X, int Y);
	public:
		General(Color color, int id) : Chess(color, id) {}
		void Move(Board^ board, PictureBox^ piece) override;
	};

}