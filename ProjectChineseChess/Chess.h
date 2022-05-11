#pragma once
#include "Enums.h"
#include "Board.h"
using System::Windows::Forms::PictureBox;
using System::Drawing::Point;
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
		virtual void Move(Board^ board, PictureBox^ piece) abstract;  //是否可移動
		void OnMove(Board^ board, Point^ fromPos, Point^ toPos);  //棋子的移動方法
		Color PieceColor(PictureBox^ piece);
	};

}