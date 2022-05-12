#include "General.h"
#include "GameManager.h"

namespace ProjectChineseChess
{
	bool General::inRange(Direction direct, int X, int Y)
	{
		switch (direct)
		{
		case ProjectChineseChess::Direction::UP:
			if (color == Color::RED)  //紅方
			{
				if (Y < 7)
					return false;
				else
					return true;
			}
			else  //黑方
			{
				if (Y < 0)
					return false;
				else
					return true;
			}
			break;
		case ProjectChineseChess::Direction::DOWN:
			if (color == Color::RED)  //紅方
			{
				if (Y > 9)
					return false;
				else
					return true;
			}
			else  //黑方
			{
				if (Y > 2)
					return false;
				else
					return true;
			}
			break;
		case ProjectChineseChess::Direction::LEFT:
			if (X < 3)
				return false;
			else
				return true;
			break;
		case ProjectChineseChess::Direction::RIGHT:
			if (X > 5)
				return false;
			else
				return true;
			break;
		default:
			return false;
			break;
		}
	}
	void General::pushGreenAndRed(Board^ board, int X, int Y)
	{
		if (board->board[X, Y] == nullptr)
		{
			PictureBox^ greenDot = gcnew PictureBox();  //建立一個綠點
			Point^ formPoint = Board::ToFormCoord(Point(X, Y));  //綠點在視窗上的位置
			greenDot->Location = *formPoint;  //設定綠點的位置
			GameManager::green->push_back(greenDot);  //將綠點存起來
		}
		else if (PieceColor(board->board[X, Y]) != color)
			GameManager::red->push_back(board->board[X, Y]);
	}

	void General::Move(Board^ board, PictureBox^ piece)
	{
		Point^ pos = Board::ToBoardCoord(piece->Location);

		//上
		int X = pos->X; int Y = pos->Y - 1;
		if (inRange(Direction::UP, X, Y))
		{
			pushGreenAndRed(board, X, Y);
		}

		//左
		X = pos->X - 1; Y = pos->Y;
		if (inRange(Direction::LEFT, X, Y))
		{
			pushGreenAndRed(board, X, Y);
		}

		//下
		X = pos->X; Y = pos->Y + 1;
		if (inRange(Direction::DOWN, X, Y))
		{
			pushGreenAndRed(board, X, Y);
		}

		//右
		X = pos->X + 1; Y = pos->Y;
		if (inRange(Direction::RIGHT, X, Y))
		{
			pushGreenAndRed(board, X, Y);
		}
	}
}