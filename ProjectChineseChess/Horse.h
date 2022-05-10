#pragma once
#include "Chess.h"
namespace ProjectChineseChess
{
	//��
	ref class Horse : public Chess
	{
		bool horseLeg(Board^ board, Direction direct, Point^ pos);
		bool inRange(int X, int Y);
		void pushGreenAndRed(Board^ board, int X, int Y);
	public:
		Horse(Color color, int id) : Chess(color, id) {}
		void CanMove(Board^ board, PictureBox^ piece) override;
		void Move() override {}
	};

}
