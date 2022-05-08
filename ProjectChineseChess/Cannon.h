#pragma once
#include "Chess.h"
namespace ProjectChineseChess
{

	ref class Cannon : public Chess
	{
	public:
		Cannon(Player player, int id) : Chess(player, id) {}
		void Move() override {}
	};

}