#pragma once
#include "Chess.h"
namespace ProjectChineseChess
{
	//ио
	ref class Chariot : public Chess
	{
	public:
		Chariot(Color color, int id) : Chess(color, id) {}
		void CanMove(Board^ board, PictureBox^ piece) override {}
		void Move() override {}
	};

}