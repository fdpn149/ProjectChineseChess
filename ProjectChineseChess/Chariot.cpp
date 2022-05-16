#include "Chariot.h"
#include "GameManager.h"

namespace ProjectChineseChess
{
	void Chariot::findOpponent(Board^ board, Direction direct, Point^ pos)
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

		int i = pos->X + dir_x, j = pos->Y + dir_y;
		while (i >= 0 && i < 9 && j >= 0 && j < 10)
		{
			//碰到棋子
			if (board->board[i, j] != nullptr)
			{
				//判斷紅方黑方的棋子
				if (this->color == PieceColor(board->board[i, j])) //己方棋子
					return;
				else
				{
					GameManager::red->push_back(board->board[i, j]); //對方棋子
					return;
				}
			}
			//沒找到棋子
			else
			{
				PictureBox^ greenDot = gcnew PictureBox();  //建立一個綠點
				Point^ formPoint = Board::ToFormCoord(Point(i, j));  //綠點在視窗上的位置
				greenDot->Location = *formPoint;  //設定綠點的位置
				GameManager::green->push_back(greenDot);  //將綠點存起來
			}

			i += dir_x;
			j += dir_y;
		}
	}
	void Chariot::Move(Board^ board, PictureBox^ piece)
	{
		Point^ pos = Board::ToBoardCoord(piece->Location);

		findOpponent(board, Direction::UP, pos);
		findOpponent(board, Direction::DOWN, pos);
		if (!KingsFaceToFace(board, piece))  //王見王判斷
			return;
		findOpponent(board, Direction::LEFT, pos);
		findOpponent(board, Direction::RIGHT, pos);
	}
}