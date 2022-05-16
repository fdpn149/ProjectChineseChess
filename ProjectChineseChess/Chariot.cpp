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
			//�I��Ѥl
			if (board->board[i, j] != nullptr)
			{
				//�P�_����¤誺�Ѥl
				if (this->color == PieceColor(board->board[i, j])) //�v��Ѥl
					return;
				else
				{
					GameManager::red->push_back(board->board[i, j]); //���Ѥl
					return;
				}
			}
			//�S���Ѥl
			else
			{
				PictureBox^ greenDot = gcnew PictureBox();  //�إߤ@�Ӻ��I
				Point^ formPoint = Board::ToFormCoord(Point(i, j));  //���I�b�����W����m
				greenDot->Location = *formPoint;  //�]�w���I����m
				GameManager::green->push_back(greenDot);  //�N���I�s�_��
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
		if (!KingsFaceToFace(board, piece))  //�������P�_
			return;
		findOpponent(board, Direction::LEFT, pos);
		findOpponent(board, Direction::RIGHT, pos);
	}
}