#pragma once
#include "Chess.h"
namespace ProjectChineseChess
{
	//°¨
	ref class Horse : public Chess
	{
	public:
		Horse(Player player, int id) : Chess(player, id) {}
		void CanMove(Board^ board, PictureBox^ piece) override {}
		void Move() override {}
	};

}
