#pragma once
#include "Chess.h"
namespace ProjectChineseChess
{
	//�N
	ref class General : public Chess
	{
	public:
		General(Player player, int id) : Chess(player, id) {}
		void Move() override {}
	};

}