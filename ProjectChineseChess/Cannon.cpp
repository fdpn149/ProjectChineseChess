#include "Cannon.h"
#include "GameManager.h"

namespace ProjectChineseChess
{
	void Cannon::findOpponent(Board^ board, Direction direct, Point^ pos)
	{
		int dir_x = 0, dir_y = 0;

		switch (direct)
		{
		case Direction::UP:
			dir_y = -1; break;
		case Direction::DOWN:
			dir_y = 1; break;
		case Direction::LEFT:
			dir_x = -1; break;
		default:
			dir_x = 1;
		}

		bool meet = false;
		int i = pos->X + dir_x, j = pos->Y + dir_y;
		while (i >= 0 && i < 9 && j >= 0 && j < 10)
		{
			//若第一次找到棋子
			if (!meet && board->board[i, j] != nullptr)
				meet = true;
			//沒找到棋子
			else if (!meet)
			{
				PictureBox^ greenDot = gcnew PictureBox();  //建立一個綠點
				Point^ formPoint = board->ToFormCoord(Point(i, j));  //綠點在視窗上的位置
				greenDot->Location = *formPoint;  //設定綠點的位置
				GameManager::green->push_back(greenDot);  //將綠點存起來
			}
			//若第二次找到棋子
			else if (board->board[i, j] != nullptr)
			{
				//若是對手的棋子
				if (PieceColor(board->board[i, j]) != color)
				{
					GameManager::red->push_back(board->board[i, j]);  //將前面的棋子存起來
					return;
				}
			}

			i += dir_x;
			j += dir_y;
		}
	}
	void Cannon::CanMove(Board^ board, PictureBox^ piece)
	{
		Point^ pos = board->ToBoardCoord(piece->Location);

		findOpponent(board, Direction::UP, pos);
		findOpponent(board, Direction::DOWN, pos);
		findOpponent(board, Direction::LEFT, pos);
		findOpponent(board, Direction::RIGHT, pos);
	}
}