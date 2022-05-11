#pragma once
#include "Chess.h"
namespace ProjectChineseChess
{
	//¨ò
	ref class Soldier : public Chess
	{
		bool crossedRiver;
		void checkFront(Board^ board, Point^ pos);
		void checkSide(Board^ board, Point^ pos, int direct);
		void checkCrossRiver(Point^ pos);
	public:
		Soldier(Color color, int id);
		void Move(Board^ board, PictureBox^ piece) override;
	};

}