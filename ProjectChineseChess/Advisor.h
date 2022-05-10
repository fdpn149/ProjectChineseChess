#pragma once
#include "Chess.h"
namespace ProjectChineseChess
{
	//¤h
	ref class Advisor : public Chess
	{
	public:
		Advisor(Color color, int id) : Chess(color, id) {}
		void CanMove(Board^ board, PictureBox^ piece) override;
		void Move() override{}
	};

}