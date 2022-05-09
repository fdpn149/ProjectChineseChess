#include "Advisor.h"

namespace ProjectChineseChess
{
	Advisor::Advisor(Player player, int id) : Chess(player, id)
	{
	}

	void Advisor::CanMove(Board^ board, PictureBox^ piece)
	{
		Point^ pos = board->ToBoardCoord(piece->Location);
		
		//如果是紅方，不能移動到紅方棋子上
		if (this->player == Player::RED)
		{
			
		}
	}
	
}