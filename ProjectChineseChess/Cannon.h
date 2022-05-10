#pragma once
#include "Chess.h"
namespace ProjectChineseChess
{
	//пе
	ref class Cannon : public Chess
	{
		void findOpponent(Board^ board, Direction direct, Point^ pos);
	public:
		Cannon(Color color, int id) : Chess(color, id) {}
		void CanMove(Board^ board, PictureBox^ piece) override;
		void Move() override {}
	};

}