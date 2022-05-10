#pragma once
#include "Chess.h"
namespace ProjectChineseChess
{
	//±N
	ref class General : public Chess
	{
	public:
		General(Color color, int id) : Chess(color, id) {}
		void CanMove(Board^ board, PictureBox^ piece) override {}
		void Move() override {}
	};

}