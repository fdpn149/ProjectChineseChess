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
		bool crossedRiver;
		void pushGreenAndRed(Board^ board, int X, int Y);
	public:
		Color color;  //玩家(BLACK & RED)
		int id;  //棋子的id
		Chess(Color player, int id);
		virtual void Move(Board^ board, PictureBox^ piece) abstract;  //是否可移動
		void OnMove(Board^ board, Point^ fromPos, Point^ toPos);  //棋子的移動方法
		static Color PieceColor(PictureBox^ piece);
		static Color OpponentColor(PictureBox^ piece);
		bool KingsFaceToFace(Board^ board, PictureBox^ piece);  //判斷王見王，false代表會出現王見王的情況
		void SetCrossRiver();
	};

}