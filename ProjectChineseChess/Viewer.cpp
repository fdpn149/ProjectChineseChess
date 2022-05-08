#include "Viewer.h"
#include "GameForm.h"

namespace ProjectChineseChess
{
	Viewer::Viewer()
	{

	}

	void Viewer::PieceClick(PictureBox^ piece)
	{
		//設定棋子為黃色
		piece->Image = (cli::safe_cast<System::Drawing::Image^>(resourceManager->GetObject(L"Yellow")));
	}

	void Viewer::PieceUnclick(PictureBox^ piece)
	{
		//將棋子顏色去掉
		piece->Image = nullptr;
	}

	//void Viewer::test(PictureBox^ p)
	//{
	//	//將傳入的棋子設為紅色
	//	p->Image = (cli::safe_cast<System::Drawing::Image^>(resourceManager->GetObject(L"Red")));
	//	//建立一個PictureBox
	//	System::Windows::Forms::PictureBox^ pi = gcnew PictureBox();
	//	pi->Location = Point(265, 265);  //設定位置
	//	pi->BackColor = Color::Transparent;  //設定背景為透明
	//	pi->Size = Size(70, 70);  //設定大小
	//	//將圖片設為綠色
	//	pi->Image = (cli::safe_cast<System::Drawing::Image^>(resourceManager->GetObject(L"Green")));
	//	//在視窗上新增綠色的東東
	//	GameForm::gameform->Controls->Add(pi);
	//	//移除傳入的棋子
	//	//GameForm::gameform->Controls->Remove(p);
	//}
}