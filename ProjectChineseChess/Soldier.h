#pragma once
#include "Chess.h"
namespace ProjectChineseChess
{
	//¨ò
	ref class Soldier : public Chess
	{
		void checkFront(Board^ board, Point^ pos);
		void checkSide(Board^ board, Point^ pos, int direct);
	public:
		Soldier(Color color, int id);
		void Move(Board^ board, PictureBox^ piece) override;
	};

}