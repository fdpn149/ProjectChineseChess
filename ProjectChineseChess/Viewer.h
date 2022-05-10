#pragma once

using System::Windows::Forms::PictureBox;

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
		//void test(System::Windows::Forms::PictureBox^ p);  //測試用
	};

}