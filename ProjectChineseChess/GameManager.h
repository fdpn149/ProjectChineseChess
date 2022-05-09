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
		State state = State::NONE;  //現在的狀態
		PictureBox^ lastClicked;  //上一個被點擊的棋子
		vector<PictureBox^> green;  //存可走的路徑
		vector<PictureBox^> red;  //存可被吃掉的棋子
		void pieceInit();  //建立棋子物件，並加到on_board中
		void changeState(PictureBox^ nowPiece);  //更改狀態
	public:
		GameManager();
		void PieceClick(PictureBox^ piece);  //棋子被點擊
		void FormClick();  //視窗被點擊
	};
}