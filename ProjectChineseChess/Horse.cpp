#include "Horse.h"
#include "GameManager.h"

namespace ProjectChineseChess
{
	bool Horse::horseLeg(Board^ board, Direction direct, Point^ pos)
	{
		switch (direct)
		{
		case ProjectChineseChess::Direction::UP:
			if (board->board[pos->X, pos->Y - 1] != nullptr)
				return false;
			else
				return true;
			break;
		case ProjectChineseChess::Direction::LEFT:
			if (board->board[pos->X - 1, pos->Y] != nullptr)
				return false;
			else
				return true;
			break;
		case ProjectChineseChess::Direction::RIGHT:
			if (board->board[pos->X + 1, pos->Y] != nullptr)
				return false;
			else
				return true;
			break;
		case ProjectChineseChess::Direction::DOWN:
			if (board->board[pos->X, pos->Y + 1] != nullptr)
				return false;
			else
				return true;
			break;
		default:
			return false;
			break;
		}
	}
	bool Horse::inRange(int X, int Y)
	{
		if (X >= 0 && X <= 8 && Y >= 0 && Y <= 9)
			return true;
		else
			return false;
	}

	void Horse::Move(Board^ board, PictureBox^ piece)
	{
		if (!KingsFaceToFace(board, piece))  //д¤игд¤зP┬_
			return;
		Point^ pos = Board::ToBoardCoord(piece->Location);

		//UP_LEFT
		int X = pos->X - 1; int Y = pos->Y - 2;
		if (inRange(X, Y))
		{
			if (horseLeg(board, Direction::UP, pos))
				pushGreenAndRed(board, X, Y);
		}

		//UP_RIGHT
		X = pos->X + 1; Y = pos->Y - 2;
		if (inRange(X, Y))
		{
			if (horseLeg(board, Direction::UP, pos))
				pushGreenAndRed(board, X, Y);
		}

		//LEFT_UP
		X = pos->X - 2; Y = pos->Y - 1;
		if (inRange(X, Y))
		{
			if (horseLeg(board, Direction::LEFT, pos))
				pushGreenAndRed(board, X, Y);
		}

		//LEFT_DOWN
		X = pos->X - 2; Y = pos->Y + 1;
		if (inRange(X, Y))
		{
			if (horseLeg(board, Direction::LEFT, pos))
				pushGreenAndRed(board, X, Y);
		}

		//RIGHT_UP
		X = pos->X + 2; Y = pos->Y - 1;
		if (inRange(X, Y))
		{
			if (horseLeg(board, Direction::RIGHT, pos))
				pushGreenAndRed(board, X, Y);
		}

		//RIGHT_DOWN
		X = pos->X + 2; Y = pos->Y + 1;
		if (inRange(X, Y))
		{
			if (horseLeg(board, Direction::RIGHT, pos))
				pushGreenAndRed(board, X, Y);
		}

		//DOWN_LEFT
		X = pos->X - 1; Y = pos->Y + 2;
		if (inRange(X, Y))
		{
			if (horseLeg(board, Direction::DOWN, pos))
				pushGreenAndRed(board, X, Y);
		}

		//DOWN_RIGHT
		X = pos->X + 1; Y = pos->Y + 2;
		if (inRange(X, Y))
		{
			if (horseLeg(board, Direction::DOWN, pos))
				pushGreenAndRed(board, X, Y);
		}
	}
}