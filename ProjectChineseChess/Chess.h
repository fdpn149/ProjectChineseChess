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
		Color color;  //���a(BLACK & RED)
		int id;  //�Ѥl��id
	public:
		Chess(Color player, int id);
		virtual void CanMove(Board^ board, PictureBox^ piece) abstract;  //�O�_�i����
		virtual void Move() abstract;  //�Ѥl�����ʤ�k
		Color PieceColor(PictureBox^ piece);
		Color OpponentColor(Color color);
	};

}