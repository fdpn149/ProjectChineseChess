#pragma once
#include "Chess.h"
namespace ProjectChineseChess
{

	ref class Soldier : public Chess
	{
	public:
		Soldier(Player player, int id) : Chess(player, id) {}
		void Move() override {}
	};

}