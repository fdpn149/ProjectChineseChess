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

	bool General::KingsFaceToFace(Board^ board, Direction direct, int X, int Y)
	{
		if (Y < 5)  //黑
		{
			Point^ RedGeneral;
			for (int i = 3; i <= 5; i++)
				for (int j = 7; j <= 9; j++)
				{
					if (board->board[i, j] == nullptr)
						continue;
					if (board->board[i, j]->Name == "generalR1")
						RedGeneral = Point(i, j);
				}
			if (X + 1 == RedGeneral->X)  //紅在右
			{
				for (int i = Y; i < RedGeneral->Y; i++)
				{
					if (board->board[RedGeneral->X, i] != nullptr)
						return true;  //不會出現王見王的情況
					else
						continue;
				}
				return false;  //"將"不能右移
			}
			else if (X - 1 == RedGeneral->X)  //紅在左
			{
				for (int i = Y; i < RedGeneral->Y; i++)
				{
					if (board->board[RedGeneral->X, i] != nullptr)
						return true;  //不會出現王見王的情況
					else
						continue;
				}
				return false;  //"將"不能左移
			}
		}
		else  //紅
		{
			Point^ BlackGeneral;
			for (int i = 3; i <= 5; i++)
				for (int j = 0; j <= 2; j++)
				{
					if (board->board[i, j] == nullptr)
						continue;
					if (board->board[i, j]->Name == "generalB1")
						BlackGeneral = Point(i, j);
				}
			if (BlackGeneral->X == X - 1)  //紅在右
			{
				for (int i = BlackGeneral->Y + 1; i <= Y; i++)
				{
					if (board->board[BlackGeneral->X, i] != nullptr)
						return true;
					else
						continue;
				}
				return false;
			}
			else if (BlackGeneral->X == X + 1)  //紅在左
			{
				for (int i = BlackGeneral->Y + 1; i <= Y; i++)
				{
					if (board->board[BlackGeneral->X, i] != nullptr)
						return true;
					else
						continue;
				}
				return false;
			}
		}
		return true;
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

		//下
		X = pos->X; Y = pos->Y + 1;
		if (inRange(Direction::DOWN, X, Y))
		{
			pushGreenAndRed(board, X, Y);
		}

		//左
		X = pos->X - 1; Y = pos->Y;
		if (inRange(Direction::LEFT, X, Y))
		{
			if (!KingsFaceToFace(board, Direction::LEFT, X + 1, Y))  //王見王判斷
			{
			}
			else
				pushGreenAndRed(board, X, Y);
		}

		//右
		X = pos->X + 1; Y = pos->Y;
		if (inRange(Direction::RIGHT, X, Y))
		{
			if (!KingsFaceToFace(board, Direction::RIGHT, X - 1, Y))  //王見王判斷
			{
			}
			else
				pushGreenAndRed(board, X, Y);
		}
	}
}