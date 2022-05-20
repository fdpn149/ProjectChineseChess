#pragma once
#include "Enums.h"
using System::Windows::Forms::PictureBox;
using System::Windows::Forms::DialogResult;
using System::Drawing::Point;
using System::String;

namespace ProjectChineseChess {

	ref class Viewer
	{
		//設定開Resources圖片的東西
		System::Reflection::Assembly^ resourceAssembly = System::Reflection::Assembly::GetExecutingAssembly();
		System::String^ resourceName = resourceAssembly->GetName()->Name + ".Resources";
		System::Resources::ResourceManager^ resourceManager = gcnew System::Resources::ResourceManager(resourceName, resourceAssembly);
	public:
		Viewer();
		void PieceClick(PictureBox^ piece);  //棋子被點擊
		void PieceUnclick(PictureBox^ piece);  //視窗被點擊
		void ShowGreens();
		void RemoveGreens();
		void ShowReds();
		void RemoveReds();
		void RemovePiece(PictureBox^ piece);
		void SetPiece(PictureBox^ piece, Point^ toPos);
		void ShowMessage(String^ m);
		DialogResult ShowMessage(String^ message,String^ caption);
		void Label1Show(String^ str);
		void Label1Hide();
		void GameOver();
		void Refresh();
		void Loading(bool enable);
		void BarColor(Color color);
	};

}