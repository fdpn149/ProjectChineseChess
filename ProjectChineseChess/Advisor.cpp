#include "Advisor.h"

namespace ProjectChineseChess
{
	Advisor::Advisor(Player player, int id) : Chess(player, id)
	{
	}

	void Advisor::CanMove(Board^ board, PictureBox^ piece)
	{
		Point^ pos = board->ToBoardCoord(piece->Location);
		
		//�p�G�O����A���ಾ�ʨ����Ѥl�W
		if (this->player == Player::RED)
		{
			
		}
	}
	
}