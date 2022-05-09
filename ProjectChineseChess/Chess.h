#pragma once
#include "Enums.h"
#include "Board.h"
using System::Windows::Forms::PictureBox;
namespace ProjectChineseChess 
{
	//�Ѥl�������O
	ref class Chess abstract
	{
	protected:
		Player player;  //���a(BLACK & RED)
		int id;  //�Ѥl��id
	public:
		Chess(Player player, int id);
		virtual void CanMove(Board^ board, PictureBox^ piece) abstract;  //�O�_�i����
		virtual void Move() abstract;  //�Ѥl�����ʤ�k
	};

}