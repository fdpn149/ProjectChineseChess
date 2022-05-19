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
		bool crossedRiver;
		void pushGreenAndRed(Board^ board, int X, int Y);
	public:
		Color color;  //���a(BLACK & RED)
		int id;  //�Ѥl��id
		Chess(Color player, int id);
		virtual void Move(Board^ board, PictureBox^ piece) abstract;  //�O�_�i����
		void OnMove(Board^ board, Point^ fromPos, Point^ toPos);  //�Ѥl�����ʤ�k
		static Color PieceColor(PictureBox^ piece);
		static Color OpponentColor(PictureBox^ piece);
		bool KingsFaceToFace(Board^ board, PictureBox^ piece);  //�P�_�������Afalse�N��|�X�{�����������p
		void SetCrossRiver();
	};

}