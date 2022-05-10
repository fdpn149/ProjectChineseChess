#pragma once
#include "Chess.h"
namespace ProjectChineseChess
{
	//°¨
	ref class Horse : public Chess
	{
	public:
		Horse(Color color, int id) : Chess(color, id) {}
		void CanMove(Board^ board, PictureBox^ piece) override {}
		void Move() override {}
	};

}
