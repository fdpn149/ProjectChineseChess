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
using System::Windows::Forms::DialogResult;
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
		State state = State::NONE;  //�{�b�����A
		PictureBox^ lastPiece;  //�W�@�ӳQ�I�����Ѥl
		bool loading = false;  //Ū����
		bool check = false;  //�N�x
		void pieceInit();  //�إߴѤl����A�å[��on_board��
		void changeState(PictureBox^ nowPiece);  //��窱�A
		bool willCheck(Color color);  //�����O�_�|�N�x
		bool opponentCanMove(Color color);  //�P�_�Ĥ�O�_���
		void findExactlyMove(PictureBox^ piece);
		bool cross_river(PictureBox^ piece);
		void checkJudge();  //�N�x�B�ӧQ�P�_
	public:
		static vector<PictureBox^>^ green = gcnew vector<PictureBox^>;  //�s�i�������|
		static vector<PictureBox^>^ red = gcnew vector<PictureBox^>;  //�s�i�Q�Y�����Ѥl
		GameManager();
		void PieceClick(PictureBox^ piece);  //�Ѥl�Q�I��
		void FormClick();  //�����Q�I��
		void SetFile();
		void LoadFile();
		void GiveUp();
	};
}