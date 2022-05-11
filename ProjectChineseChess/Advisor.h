#pragma once
#include "Chess.h"
namespace ProjectChineseChess
{
	//¤h
	ref class Advisor : public Chess
	{
		bool inRange(Direction direct, Point^ pos);
		void pushGreenAndRed(Board^ board, int X, int Y);
	public:
		Advisor(Color color, int id) : Chess(color, id) {}
		void Move(Board^ board, PictureBox^ piece) override;
	};

}