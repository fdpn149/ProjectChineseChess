#pragma once
#include "Enums.h"
#include "Board.h"
using System::Windows::Forms::PictureBox;
namespace ProjectChineseChess 
{
	//棋子的基底類別
	ref class Chess abstract
	{
	protected:
		Color color;  //玩家(BLACK & RED)
		int id;  //棋子的id
	public:
		Chess(Color player, int id);
		virtual void CanMove(Board^ board, PictureBox^ piece) abstract;  //是否可移動
		virtual void Move() abstract;  //棋子的移動方法
		Color PieceColor(PictureBox^ piece);
		Color OpponentColor(Color color);
	};

}