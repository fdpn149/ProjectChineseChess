#include "Advisor.h"

namespace ProjectChineseChess
{
	Advisor::Advisor(Color color, int id) : Chess(color, id)
	{
	}

	void Advisor::CanMove(Board^ board, PictureBox^ piece)
	{
		Point^ pos = board->ToBoardCoord(piece->Location);
		
		//如果是紅方，不能移動到紅方棋子上
		if (this->color == Color::RED)
		{
			
		}
	}
	
}