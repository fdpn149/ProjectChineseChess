#include "Advisor.h"
#include "GameManager.h"

namespace ProjectChineseChess
{
	void Advisor::CanMove(Board^ board, PictureBox^ piece)
	{
		Point^ pos = board->ToBoardCoord(piece->Location);
		
		//�p�G�O�¤�A���ಾ�ʨ�¤�Ѥl�W
		if (this->color == Color::BLACK)
		{
			for (int X = pos->X - 1; X <= pos->X + 1; X += 2)		//----------------------
			{														//���W�B�k�W�B���U�B�k�U
				for (int Y = pos->Y - 1; Y <= pos->Y + 1; Y += 2)	//----------------------
				{
					if (X >= 3 && X <= 5 && Y >= 0 && Y <= 2)	//�O�_�W�X�d��
					{
						if (board->board[X, Y] == nullptr)
						{
							PictureBox^ greenDot = gcnew PictureBox();  //�إߤ@�Ӻ��I
							Point^ formPoint = board->ToFormCoord(Point(X, Y));  //���I�b�����W����m
							greenDot->Location = *formPoint;  //�]�w���I����m
							GameManager::green->push_back(greenDot);  //�N���I�s�_��
						}
						else if(PieceColor(board->board[X, Y]) == Color::RED)
							GameManager::red->push_back(board->board[X, Y]);
					}
				}
			}
		}
		else
		{
			for (int X = pos->X - 1; X <= pos->X + 1; X += 2)		//----------------------
			{														//���W�B�k�W�B���U�B�k�U
				for (int Y = pos->Y - 1; Y <= pos->Y + 1; Y += 2)	//----------------------
				{
					if (X >= 3 && X <= 5 && Y >= 7 && Y <= 9)	//�O�_�W�X�d��
					{
						if (board->board[X, Y] == nullptr)
						{
							PictureBox^ greenDot = gcnew PictureBox();  //�إߤ@�Ӻ��I
							Point^ formPoint = board->ToFormCoord(Point(X, Y));  //���I�b�����W����m
							greenDot->Location = *formPoint;  //�]�w���I����m
							GameManager::green->push_back(greenDot);  //�N���I�s�_��
						}
						else if (PieceColor(board->board[X, Y]) == Color::RED)
							GameManager::red->push_back(board->board[X, Y]);
					}
				}
			}
		}
	}
}