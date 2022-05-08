#pragma once
#include "Chess.h"
namespace ProjectChineseChess
{

	ref class Advisor : public Chess
	{
	public:
		Advisor(Player player, int id) : Chess(player, id) {}
		void Move() override{}
	};

}