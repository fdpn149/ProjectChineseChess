#pragma once
namespace ProjectChineseChess
{
	//���A
	enum class State
	{
		MOVE_PIECE, PIECE_CLICKED, NONE
	};

	//�C��
	enum class Color
	{
		RED = 1, BLACK = 2
	};

	enum class Direction
	{
		UP, DOWN, LEFT, RIGHT,
		LEFTUP, RIGHTUP, LEFTDOWN, RIGHTDOWN  //for advisor and elephant
	};
}