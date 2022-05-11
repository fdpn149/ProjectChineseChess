#pragma once
#include "Enums.h"
#include "Board.h"
using System::Windows::Forms::PictureBox;
using System::Drawing::Point;
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
		virtual void Move(Board^ board, PictureBox^ piece) abstract;  //�O�_�i����
		void OnMove(Board^ board, Point^ fromPos, Point^ toPos);  //�Ѥl�����ʤ�k
		Color PieceColor(PictureBox^ piece);
	};

}