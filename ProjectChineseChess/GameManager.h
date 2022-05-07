#pragma once
#include <cliext/vector>
#include "Chess.h"
#include "Board.h"
#include "Viewer.h"
using cliext::vector;
namespace ProjectChineseChess {

	ref class GameManager
	{
		vector<Chess^> on_board;
		int current_player;
		Board board;
		Viewer^ viewer = gcnew Viewer();
	public:
		GameManager()
		{
			
		}
		void clicked(System::Windows::Forms::PictureBox^ p)
		{
			viewer->change(p);
		}
	};

}