#include "Advisor.h"
#include "GameManager.h"

namespace ProjectChineseChess
{
	bool Advisor::inRange(Direction direct, Point^ pos)
	{
		switch (direct)
		{
		case ProjectChineseChess::Direction::LEFTUP:
			if (color == Color::RED)  //����
			{
				if (pos->X - 1 >= 3 && pos->Y - 1 >= 7)
					return true;
				else
					return false;
			}
			else  //�¤�
			{
				if (pos->X - 1 >= 3 && pos->Y - 1 >= 0)
					return true;
				else
					return false;
			}
			break;
		case ProjectChineseChess::Direction::RIGHTUP:
			if (color == Color::RED)  //����
			{
				if (pos->X + 1 <= 5 && pos->Y - 1 >= 7)
					return true;
				else
					return false;
			}
			else  //�¤�
			{
				if (pos->X + 1 <= 5 && pos->Y - 1 >= 0)
					return true;
				else
					return false;
			}
			break;
		case ProjectChineseChess::Direction::LEFTDOWN:
			if (color == Color::RED)  //����
			{
				if (pos->X - 1 >= 3 && pos->Y + 1 <= 9)
					return true;
				else
					return false;
			}
			else  //�¤�
			{
				if (pos->X - 1 >= 3 && pos->Y + 1 <= 2)
					return true;
				else
					return false;
			}
			break;
		case ProjectChineseChess::Direction::RIGHTDOWN:
			if (color == Color::RED)  //����
			{
				if (pos->X + 1 <= 5 && pos->Y + 1 <= 9)
					return true;
				else
					return false;
			}
			else  //�¤�
			{
				if (pos->X + 1 <= 5 && pos->Y + 1 <= 2)
					return true;
				else
					return false;
			}
			break;
		}
		return false;
	}
	void Advisor::pushGreenAndRed(Board^ board, int X, int Y)
	{
		if (board->board[X, Y] == nullptr)
		{
			PictureBox^ greenDot = gcnew PictureBox();  //�إߤ@�Ӻ��I
			Point^ formPoint = Board::ToFormCoord(Point(X, Y));  //���I�b�����W����m
			greenDot->Location = *formPoint;  //�]�w���I����m
			GameManager::green->push_back(greenDot);  //�N���I�s�_��
		}
		else if (PieceColor(board->board[X, Y]) != color)
			GameManager::red->push_back(board->board[X, Y]);
	}


	void Advisor::Move(Board^ board, PictureBox^ piece)
	{
		Point^ pos = Board::ToBoardCoord(piece->Location);
		
		//���W
		int X = pos->X - 1; int Y = pos->Y - 1;
		if (inRange(Direction::LEFTUP, pos))
		{
			pushGreenAndRed(board, X, Y);
		}

		//�k�W
		X = pos->X + 1; Y = pos->Y - 1;
		if (inRange(Direction::RIGHTUP, pos))
		{
			pushGreenAndRed(board, X, Y);
		}

		//���U
		X = pos->X - 1; Y = pos->Y + 1;
		if (inRange(Direction::LEFTDOWN, pos))
		{
			pushGreenAndRed(board, X, Y);
		}

		//�k�U
		X = pos->X + 1; Y = pos->Y + 1;
		if (inRange(Direction::RIGHTDOWN, pos))
		{
			pushGreenAndRed(board, X, Y);
		}


		////�p�G�O�¤�A���ಾ�ʨ�¤�Ѥl�W
		//if (this->color == Color::BLACK)
		//{
		//	for (int X = pos->X - 1; X <= pos->X + 1; X += 2)		//----------------------
		//	{														//���W�B�k�W�B���U�B�k�U
		//		for (int Y = pos->Y - 1; Y <= pos->Y + 1; Y += 2)	//----------------------
		//		{
		//			if (X >= 3 && X <= 5 && Y >= 0 && Y <= 2)	//�O�_�W�X�d��
		//			{
		//				if (board->board[X, Y] == nullptr)
		//				{
		//					PictureBox^ greenDot = gcnew PictureBox();  //�إߤ@�Ӻ��I
		//					Point^ formPoint = board->ToFormCoord(Point(X, Y));  //���I�b�����W����m
		//					greenDot->Location = *formPoint;  //�]�w���I����m
		//					GameManager::green->push_back(greenDot);  //�N���I�s�_��
		//				}
		//				else if(PieceColor(board->board[X, Y]) == Color::RED)
		//					GameManager::red->push_back(board->board[X, Y]);
		//			}
		//		}
		//	}
		//}
		//else
		//{
		//	for (int X = pos->X - 1; X <= pos->X + 1; X += 2)		//----------------------
		//	{														//���W�B�k�W�B���U�B�k�U
		//		for (int Y = pos->Y - 1; Y <= pos->Y + 1; Y += 2)	//----------------------
		//		{
		//			if (X >= 3 && X <= 5 && Y >= 7 && Y <= 9)	//�O�_�W�X�d��
		//			{
		//				if (board->board[X, Y] == nullptr)
		//				{
		//					PictureBox^ greenDot = gcnew PictureBox();  //�إߤ@�Ӻ��I
		//					Point^ formPoint = board->ToFormCoord(Point(X, Y));  //���I�b�����W����m
		//					greenDot->Location = *formPoint;  //�]�w���I����m
		//					GameManager::green->push_back(greenDot);  //�N���I�s�_��
		//				}
		//				else if (PieceColor(board->board[X, Y]) == Color::RED)
		//					GameManager::red->push_back(board->board[X, Y]);
		//			}
		//		}
		//	}
		//}
	}
}