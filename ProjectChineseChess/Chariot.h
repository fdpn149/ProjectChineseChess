#pragma once
#include "Chess.h"
namespace ProjectChineseChess
{
	//ио
	ref class Chariot : public Chess
	{
	public:
		Chariot(Player player, int id) : Chess(player, id) {}
		void Move() override {}
	};

}