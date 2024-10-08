#pragma once
#include "Chess.h"
namespace ProjectChineseChess
{
	//�H
	ref class Elephant : public Chess
	{
		bool elephantEye(Board^ board, Direction direct, Point^ pos);
		bool inRange(Direction direct, Point^ pos);
	public:
		Elephant(Color color, int id) : Chess(color, id) {}
		void Move(Board^ board, PictureBox^ piece) override;
	};

}