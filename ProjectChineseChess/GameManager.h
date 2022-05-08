#pragma once
//#include <cliext/vector>
#include <cliext/map>
#include "Chess.h"
#include "Board.h"
#include "Enums.h"
using cliext::map;
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
		State state = State::NONE;
		PictureBox^ lastClicked;
		void pieceInit();
		void changeState(PictureBox^ nowPiece);
	public:
		GameManager();
		void PieceClick(PictureBox^ piece);
		void FormClick();
	};
}