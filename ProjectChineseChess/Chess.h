#pragma once
#include "Enums.h"
namespace ProjectChineseChess 
{
	//�Ѥl�������O
	ref class Chess abstract
	{
		Player player;  //���a(BLACK & RED)
		int id;  //�Ѥl��id
	public:
		Chess(Player player, int id);
		virtual void Move() abstract;  //�Ѥl�����ʤ�k
	};

}