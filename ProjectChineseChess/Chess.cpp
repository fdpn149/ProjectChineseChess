#include "Chess.h"
#include "GameManager.h"

namespace ProjectChineseChess
{
	Chess::Chess(Color color, int id)
	{
		this->color = color;  //�]�w���a
		this->id = id;  //�]�wid
	}
	void Chess::OnMove(Board^ board, Point^ fromPos, Point^ toPos)
	{
		Point^ fpos = Board::ToBoardCoord(fromPos);
		Point^ tpos = Board::ToBoardCoord(toPos);
		if (*fpos != *tpos)
		{
			board->board[tpos->X, tpos->Y] = board->board[fpos->X, fpos->Y];
			board->board[fpos->X, fpos->Y] = nullptr;
		}
	}
	Color Chess::PieceColor(PictureBox^ piece)
	{
		//�Y�Ѥl�O����
		if (piece->Name[piece->Name->Length - 2] == 'R')
			return Color::RED;
		//�Y�Ѥl�O�¦�
		else
			return Color::BLACK;
	}

	Color Chess::OpponentColor(PictureBox^ piece)
	{
		//�Y�Ѥl�O����
		if (piece->Name[piece->Name->Length - 2] == 'R')
			return Color::BLACK;
		//�Y�Ѥl�O�¦�
		else
			return Color::RED;
	}

	bool Chess::KingsFaceToFace(Board^ board, PictureBox^ piece)
	{
		Point RedGeneral;
		Point BlackGeneral;
		for (int i = 3; i <= 5; i++)
			for (int j = 0; j <= 2; j++)
			{
				if (board->board[i, j] == nullptr)
					continue;
				if (board->board[i, j]->Name == "generalB1")
					BlackGeneral = Point(i, j);
			}

		for (int i = 3; i <= 5; i++)
			for (int j = 7; j <= 9; j++)
			{
				if (board->board[i, j] == nullptr)
					continue;
				if (board->board[i, j]->Name == "generalR1")
					RedGeneral = Point(i, j);
			}

		Point^ currentPiece = board->ToBoardCoord(piece->Location);
		if (BlackGeneral.X == RedGeneral.X && RedGeneral.X == currentPiece->X)
		{
			for (int i = BlackGeneral.Y + 1; i < RedGeneral.Y; i++)
			{
				if (i == currentPiece->Y)
					continue;
				if (board->board[BlackGeneral.X, i] != nullptr)
					return true;  //���|�X�{�����������p
			}
			return false;  //�|�X�{�����������p(piece���వx�b������)
		}
		else
			return true;  //���|�X�{�����������p
	}
	void Chess::SetCrossRiver()
	{
		crossedRiver = true;
	}
	void Chess::pushGreenAndRed(Board^ board, int X, int Y)
	{
		if (board->board[X, Y] == nullptr)
		{
			PictureBox^ greenDot = gcnew PictureBox();  //�إߤ@�Ӻ��I
			Point^ formPoint = Board::ToFormCoord(Point(X, Y));  //���I�b�����W����m
			greenDot->Location = *formPoint;  //�]�w���I����m
			greenDot->Name = "green";
			GameManager::green->push_back(greenDot);  //�N���I�s�_��
		}
		else if (PieceColor(board->board[X, Y]) != color)
			GameManager::red->push_back(board->board[X, Y]);
	}
}
