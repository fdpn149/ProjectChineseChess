#pragma once
#include <cliext/vector>
#include "Chess.h"
#include "Board.h"
#include "Enums.h"
using cliext::vector;

namespace ProjectChineseChess
{
	ref class Viewer;
	ref class GameManager
	{
		vector<Chess^> on_board_black;
		vector<Chess^> on_board_red;
		int current_player;
		Board board;
		Viewer^ viewer;
		//array<bool>^ clicked = gcnew array<bool>(32);
		State state = State::NONE;
	public:
		GameManager();
		void PieceClicked(System::Windows::Forms::PictureBox^ piece);
	};
}