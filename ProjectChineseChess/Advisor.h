#pragma once
#include "Chess.h"
namespace ProjectChineseChess
{
	//¤h
	ref class Advisor : public Chess
	{
	public:
		Advisor(Player player, int id) : Chess(player, id) {}
		void CanMove(Board^ board, PictureBox^ piece) override {}
		void Move() override{}
	};

}