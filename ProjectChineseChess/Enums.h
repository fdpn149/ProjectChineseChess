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
		BLACK, RED
	};

	enum class Direction
	{
		UP, DOWN, LEFT, RIGHT
	};
}