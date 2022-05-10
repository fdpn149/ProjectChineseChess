#include "Soldier.h"
#include "GameManager.h"
namespace ProjectChineseChess
{
	void Soldier::checkFront(Board^ board, Point^ pos)
	{
		int direction;  //�Ѥl�Ө�����V
		if (color == Color::BLACK)
			direction = 1;
		else
			direction = -1;
			
		if (board->board[pos->X, pos->Y + direction] == nullptr)  //�Y�e���@��S���F��
		{
			PictureBox^ greenDot = gcnew PictureBox();  //�إߤ@�Ӻ��I
			Point^ formPoint = board->ToFormCoord(Point(pos->X, pos->Y + direction));  //���I�b�����W����m
			greenDot->Location = *formPoint;  //�]�w���I����m
			GameManager::green->push_back(greenDot);  //�N���I�s�_��
		}
		else if (PieceColor(board->board[pos->X, pos->Y + direction]) != color)  //�Y�e���@��O��⪺�Ѥl
		{
			GameManager::red->push_back(board->board[pos->X, pos->Y + direction]);  //�N�e�����Ѥl�s�_��
		}
	}

	Soldier::Soldier(Color color, int id) : Chess(color, id)
	{
		crossedRiver = false;
	}

	void Soldier::CanMove(Board^ board, PictureBox^ piece)
	{
		Point^ pos = board->ToBoardCoord(piece->Location);

		//�p�G�O"�L"
		if (this->color == Color::RED)
		{
			if (crossedRiver)  //�p�G�w�g�L�e
			{

			}
			else  //�p�G�|���L�e
			{
				if (pos->Y - 1 > 0)
				{
					checkFront(board, pos);
				}
			}
		}
		//�p�G�O"��"
		else
		{
			if (crossedRiver)  //�p�G�w�g�L�e
			{

			}
			else  //�p�G�|���L�e
			{
				if (pos->Y + 1 < 10)
				{
					checkFront(board, pos);
				}
			}
		}
	}
}