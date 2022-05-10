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
			//�Y�Ĥ@�����Ѥl
			if (!meet && board->board[i, j] != nullptr)
				meet = true;
			//�S���Ѥl
			else if (!meet)
			{
				PictureBox^ greenDot = gcnew PictureBox();  //�إߤ@�Ӻ��I
				Point^ formPoint = board->ToFormCoord(Point(i, j));  //���I�b�����W����m
				greenDot->Location = *formPoint;  //�]�w���I����m
				GameManager::green->push_back(greenDot);  //�N���I�s�_��
			}
			//�Y�ĤG�����Ѥl
			else if (board->board[i, j] != nullptr)
			{
				//�Y�O��⪺�Ѥl
				if (PieceColor(board->board[i, j]) != color)
				{
					GameManager::red->push_back(board->board[i, j]);  //�N�e�����Ѥl�s�_��
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