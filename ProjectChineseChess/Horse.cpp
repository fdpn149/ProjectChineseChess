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
	void Horse::pushGreenAndRed(Board^ board, int X, int Y)
	{
		if (board->board[X, Y] == nullptr)
		{
			PictureBox^ greenDot = gcnew PictureBox();  //建立一個綠點
			Point^ formPoint = Board::ToFormCoord(Point(X, Y));  //綠點在視窗上的位置
			greenDot->Location = *formPoint;  //設定綠點的位置
			greenDot->Name = "green";
			GameManager::green->push_back(greenDot);  //將綠點存起來
		}
		else if (PieceColor(board->board[X, Y]) != color)
			GameManager::red->push_back(board->board[X, Y]);
	}

	void Horse::Move(Board^ board, PictureBox^ piece)
	{
		if (!KingsFaceToFace(board, piece))  //王見王判斷
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