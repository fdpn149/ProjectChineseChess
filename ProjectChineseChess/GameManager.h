#pragma once
#include <cliext/vector>
#include <cliext/map>
#include "Chess.h"
#include "Board.h"
#include "Enums.h"
using cliext::map;
using cliext::vector;
using System::Windows::Forms::PictureBox;
using System::String;
namespace ProjectChineseChess
{
	ref class Viewer;
	ref class GameManager
	{
		map<String^,Chess^> on_board;
		int current_player;
		Board board;
		Viewer^ viewer;
		State state = State::NONE;  //�{�b�����A
		PictureBox^ lastClicked;  //�W�@�ӳQ�I�����Ѥl
		vector<PictureBox^> green;  //�s�i�������|
		vector<PictureBox^> red;  //�s�i�Q�Y�����Ѥl
		void pieceInit();  //�إߴѤl����A�å[��on_board��
		void changeState(PictureBox^ nowPiece);  //��窱�A
	public:
		GameManager();
		void PieceClick(PictureBox^ piece);  //�Ѥl�Q�I��
		void FormClick();  //�����Q�I��
	};
}