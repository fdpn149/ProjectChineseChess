#include "Elephant.h"
#include "GameManager.h"

namespace ProjectChineseChess
{
	bool Elephant::elephantEye(Board^ board, Direction direct, Point^ pos)
	{
		switch (direct)
		{
		case ProjectChineseChess::Direction::LEFTUP:
			if (board->board[pos->X - 1, pos->Y - 1] != nullptr)
				return false;
			else
				return true;
			break;
		case ProjectChineseChess::Direction::RIGHTUP:
			if (board->board[pos->X + 1, pos->Y - 1] != nullptr)
				return false;
			else
				return true;
			break;
		case ProjectChineseChess::Direction::LEFTDOWN:
			if (board->board[pos->X - 1, pos->Y + 1] != nullptr)
				return false;
			else
				return true;
			break;
		case ProjectChineseChess::Direction::RIGHTDOWN:
			if (board->board[pos->X + 1, pos->Y + 1] != nullptr)
				return false;
			else
				return true;
			break;
		}
		return false;
	}
	bool Elephant::inRange(Direction direct, Point^ pos)
	{
		switch (direct)
		{
		case ProjectChineseChess::Direction::LEFTUP:
			if (color == Color::RED)  //紅方
			{
				if (pos->X - 2 >= 0 && pos->Y - 2 >= 5)
					return true;
				else
					return false;
			}
			else  //黑方
			{
				if (pos->X - 2 >= 0 && pos->Y - 2 >= 0)
					return true;
				else 
					return false;
			}
			break;
		case ProjectChineseChess::Direction::RIGHTUP:
			if (color == Color::RED)  //紅方
			{
				if (pos->X + 2 <= 8 && pos->Y - 2 >= 5)
					return true;
				else
					return false;
			}
			else  //黑方
			{
				if (pos->X + 2 <= 8 && pos->Y - 2 >= 0)
					return true;
				else
					return false;
			}
			break;
		case ProjectChineseChess::Direction::LEFTDOWN:
			if (color == Color::RED)  //紅方
			{
				if (pos->X - 2 >= 0 && pos->Y + 2 <= 9)
					return true;
				else
					return false;
			}
			else  //黑方
			{
				if (pos->X - 2 >= 0 && pos->Y + 2 <= 4)
					return true;
				else
					return false;
			}
			break;
		case ProjectChineseChess::Direction::RIGHTDOWN:
			if (color == Color::RED)  //紅方
			{
				if (pos->X + 2 <= 8 && pos->Y + 2 <= 9)
					return true;
				else
					return false;
			}
			else  //黑方
			{
				if (pos->X + 2 <= 8 && pos->Y + 2 <= 4)
					return true;
				else
					return false;
			}
			break;
		}
		return false;
	}
	void Elephant::pushGreenAndRed(Board^ board, int X, int Y)
	{
		if (board->board[X, Y] == nullptr)
		{
			PictureBox^ greenDot = gcnew PictureBox();  //建立一個綠點
			Point^ formPoint = board->ToFormCoord(Point(X, Y));  //綠點在視窗上的位置
			greenDot->Location = *formPoint;  //設定綠點的位置
			GameManager::green->push_back(greenDot);  //將綠點存起來
		}
		else if (PieceColor(board->board[X, Y]) != color)
			GameManager::red->push_back(board->board[X, Y]);
	}

	void Elephant::Move(Board^ board, PictureBox^ piece)
	{
		if (!kingsFaceToFace(board, piece))  //王見王判斷
			return;

		Point^ pos = board->ToBoardCoord(piece->Location);

		//左上
		int X = pos->X - 2; int Y = pos->Y - 2;
		if (inRange(Direction::LEFTUP, pos))
		{
			if (elephantEye(board, Direction::LEFTUP, pos))
			{
				pushGreenAndRed(board, X, Y);
			}
		}

		//右上
		X = pos->X + 2; Y = pos->Y - 2;
		if (inRange(Direction::RIGHTUP, pos))
		{
			if (elephantEye(board, Direction::RIGHTUP, pos))
			{
				pushGreenAndRed(board, X, Y);
			}
		}

		//左下
		X = pos->X - 2; Y = pos->Y + 2;
		if (inRange(Direction::LEFTDOWN, pos))
		{
			if (elephantEye(board, Direction::LEFTDOWN, pos))
			{
				pushGreenAndRed(board, X, Y);
			}
		}

		//右下
		X = pos->X + 2; Y = pos->Y + 2;
		if (inRange(Direction::RIGHTDOWN, pos))
		{
			if (elephantEye(board, Direction::RIGHTDOWN, pos))
			{
				pushGreenAndRed(board, X, Y);
			}
		}
	}
}