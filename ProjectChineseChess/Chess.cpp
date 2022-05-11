#include "Chess.h"

namespace ProjectChineseChess
{
	Chess::Chess(Color color, int id)
	{
		this->color = color;  //�]�w���a
		this->id = id;  //�]�wid
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
