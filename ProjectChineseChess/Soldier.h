#pragma once
#include "Chess.h"
namespace ProjectChineseChess
{
	//¨ò
	ref class Soldier : public Chess
	{
		bool crossedRiver;
		void checkFront(Board^ board, Point^ pos);
	public:
		Soldier(Color color, int id);
		void CanMove(Board^ board, PictureBox^ piece) override;
		void Move() override {}
	};

}