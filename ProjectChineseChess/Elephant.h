#pragma once
#include "Chess.h"
namespace ProjectChineseChess
{
	//¶H
	ref class Elephant : public Chess
	{
	public:
		Elephant(Player player, int id) : Chess(player, id) {}
		void CanMove(Board^ board, PictureBox^ piece) override {}
		void Move() override {}
	};

}