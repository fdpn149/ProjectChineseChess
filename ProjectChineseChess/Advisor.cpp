#include "Advisor.h"

namespace ProjectChineseChess
{
	Advisor::Advisor(Color color, int id) : Chess(color, id)
	{
	}

	void Advisor::CanMove(Board^ board, PictureBox^ piece)
	{
		Point^ pos = board->ToBoardCoord(piece->Location);
		
		//�p�G�O����A���ಾ�ʨ����Ѥl�W
		if (this->color == Color::RED)
		{
			
		}
	}
	
}