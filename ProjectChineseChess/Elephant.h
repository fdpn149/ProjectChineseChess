#pragma once
#include "Chess.h"
namespace ProjectChineseChess
{

	ref class Elephant : public Chess
	{
	public:
		Elephant(Player player, int id) : Chess(player, id) {}
		void Move() override {}
	};

}