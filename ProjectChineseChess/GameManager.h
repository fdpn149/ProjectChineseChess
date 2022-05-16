#pragma once
#include <cliext/vector>
#include <cliext/map>
#include "Chess.h"
#include "Board.h"
#include "Enums.h"
#include "FileManager.h"
using cliext::map;
using cliext::vector;
using Microsoft::VisualC::StlClr::GenericPair;
using System::Windows::Forms::PictureBox;
using System::String;
namespace ProjectChineseChess
{
	ref class Viewer;
	ref class GameManager
	{
		map<String^,Chess^> on_board;
		int current_player;
		Board^ board;
		Viewer^ viewer;
		FileManager^ fmanager;
		State state = State::NONE;  //現在的狀態
		PictureBox^ lastPiece;  //上一個被點擊的棋子
		bool loading = false;  //讀取中
		bool check = false;  //將軍
		void pieceInit();  //建立棋子物件，並加到on_board中
		void changeState(PictureBox^ nowPiece);  //更改狀態
	public:
		static vector<PictureBox^>^ green = gcnew vector<PictureBox^>;  //存可走的路徑
		static vector<PictureBox^>^ red = gcnew vector<PictureBox^>;  //存可被吃掉的棋子
		GameManager();
		void PieceClick(PictureBox^ piece);  //棋子被點擊
		void FormClick();  //視窗被點擊
		void LoadFile();
	};
}