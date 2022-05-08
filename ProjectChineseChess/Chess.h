#pragma once
#include "Enums.h"
namespace ProjectChineseChess 
{
	//棋子的基底類別
	ref class Chess abstract
	{
		Player player;  //玩家(BLACK & RED)
		int id;  //棋子的id
	public:
		Chess(Player player, int id);
		virtual void Move() abstract;  //棋子的移動方法
	};

}