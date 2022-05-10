#pragma once
#include "Chess.h"
namespace ProjectChineseChess
{
	//¶H
	ref class Elephant : public Chess
	{
	public:
		Elephant(Color color, int id) : Chess(color, id) {}
		void CanMove(Board^ board, PictureBox^ piece) override {}
		void Move() override {}
	};

}