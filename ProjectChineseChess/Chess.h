#pragma once
#include "Enums.h"
namespace ProjectChineseChess 
{

	ref class Chess abstract
	{
		Player player;
		int id;
	public:
		Chess(Player player, int id);
		virtual void Move() abstract;
	};

}