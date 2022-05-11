#include "Chess.h"

namespace ProjectChineseChess
{
	Chess::Chess(Color color, int id)
	{
		this->color = color;  //�]�w���a
		this->id = id;  //�]�wid
	}
	void Chess::OnMove(Board^ board, Point^ fromPos, Point^ toPos)
	{
		Point^ fpos = board->ToBoardCoord(fromPos);
		Point^ tpos = board->ToBoardCoord(toPos);
		board->board[tpos->X, tpos->Y] = board->board[fpos->X, fpos->Y];
		board->board[fpos->X, fpos->Y] = nullptr;
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
}
