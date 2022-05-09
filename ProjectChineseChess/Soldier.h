#pragma once
#include "Chess.h"
namespace ProjectChineseChess
{
	//¨ò
	ref class Soldier : public Chess
	{
		bool crossedRiver;
	public:
		Soldier(Player player, int id);
		void CanMove(Board^ board, PictureBox^ piece) override;
		void Move() override {}
	};

}