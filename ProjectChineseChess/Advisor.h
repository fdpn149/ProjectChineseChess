#pragma once
#include "Chess.h"
namespace ProjectChineseChess
{
	//¤h
	ref class Advisor : public Chess
	{
		bool inRange(Direction direct, Point^ pos);
	
	public:
		Advisor(Color color, int id) : Chess(color, id) {}
		void Move(Board^ board, PictureBox^ piece) override;
	};

}