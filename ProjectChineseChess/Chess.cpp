#include "Chess.h"

namespace ProjectChineseChess
{
	Chess::Chess(Color color, int id)
	{
		this->color = color;  //設定玩家
		this->id = id;  //設定id
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
}
