#include "Chess.h"
#include "GameManager.h"

namespace ProjectChineseChess
{
	Chess::Chess(Color color, int id)
	{
		this->color = color;  //設定玩家
		this->id = id;  //設定id
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
		//若棋子是紅色
		if (piece->Name[piece->Name->Length - 2] == 'R')
			return Color::RED;
		//若棋子是黑色
		else
			return Color::BLACK;
	}

	Color Chess::OpponentColor(PictureBox^ piece)
	{
		//若棋子是紅色
		if (piece->Name[piece->Name->Length - 2] == 'R')
			return Color::BLACK;
		//若棋子是黑色
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
					return true;  //不會出現王見王的情況
			}
			return false;  //會出現王見王的情況(piece不能做x軸的移動)
		}
		else
			return true;  //不會出現王見王的情況
	}
	void Chess::SetCrossRiver()
	{
		crossedRiver = true;
	}
	void Chess::pushGreenAndRed(Board^ board, int X, int Y)
	{
		if (board->board[X, Y] == nullptr)
		{
			PictureBox^ greenDot = gcnew PictureBox();  //建立一個綠點
			Point^ formPoint = Board::ToFormCoord(Point(X, Y));  //綠點在視窗上的位置
			greenDot->Location = *formPoint;  //設定綠點的位置
			greenDot->Name = "green";
			GameManager::green->push_back(greenDot);  //將綠點存起來
		}
		else if (PieceColor(board->board[X, Y]) != color)
			GameManager::red->push_back(board->board[X, Y]);
	}
}
