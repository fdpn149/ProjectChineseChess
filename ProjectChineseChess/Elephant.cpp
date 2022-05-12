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
			if (color == Color::RED)  //����
			{
				if (pos->X - 2 >= 0 && pos->Y - 2 >= 5)
					return true;
				else
					return false;
			}
			else  //�¤�
			{
				if (pos->X - 2 >= 0 && pos->Y - 2 >= 0)
					return true;
				else 
					return false;
			}
			break;
		case ProjectChineseChess::Direction::RIGHTUP:
			if (color == Color::RED)  //����
			{
				if (pos->X + 2 <= 8 && pos->Y - 2 >= 5)
					return true;
				else
					return false;
			}
			else  //�¤�
			{
				if (pos->X + 2 <= 8 && pos->Y - 2 >= 0)
					return true;
				else
					return false;
			}
			break;
		case ProjectChineseChess::Direction::LEFTDOWN:
			if (color == Color::RED)  //����
			{
				if (pos->X - 2 >= 0 && pos->Y + 2 <= 9)
					return true;
				else
					return false;
			}
			else  //�¤�
			{
				if (pos->X - 2 >= 0 && pos->Y + 2 <= 4)
					return true;
				else
					return false;
			}
			break;
		case ProjectChineseChess::Direction::RIGHTDOWN:
			if (color == Color::RED)  //����
			{
				if (pos->X + 2 <= 8 && pos->Y + 2 <= 9)
					return true;
				else
					return false;
			}
			else  //�¤�
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
			PictureBox^ greenDot = gcnew PictureBox();  //�إߤ@�Ӻ��I
			Point^ formPoint = board->ToFormCoord(Point(X, Y));  //���I�b�����W����m
			greenDot->Location = *formPoint;  //�]�w���I����m
			GameManager::green->push_back(greenDot);  //�N���I�s�_��
		}
		else if (PieceColor(board->board[X, Y]) != color)
			GameManager::red->push_back(board->board[X, Y]);
	}

	void Elephant::Move(Board^ board, PictureBox^ piece)
	{
		if (!kingsFaceToFace(board, piece))  //�������P�_
			return;

		Point^ pos = board->ToBoardCoord(piece->Location);

		//���W
		int X = pos->X - 2; int Y = pos->Y - 2;
		if (inRange(Direction::LEFTUP, pos))
		{
			if (elephantEye(board, Direction::LEFTUP, pos))
			{
				pushGreenAndRed(board, X, Y);
			}
		}

		//�k�W
		X = pos->X + 2; Y = pos->Y - 2;
		if (inRange(Direction::RIGHTUP, pos))
		{
			if (elephantEye(board, Direction::RIGHTUP, pos))
			{
				pushGreenAndRed(board, X, Y);
			}
		}

		//���U
		X = pos->X - 2; Y = pos->Y + 2;
		if (inRange(Direction::LEFTDOWN, pos))
		{
			if (elephantEye(board, Direction::LEFTDOWN, pos))
			{
				pushGreenAndRed(board, X, Y);
			}
		}

		//�k�U
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