#include "Viewer.h"
#include "GameForm.h"
#include "GameManager.h"

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

	void Viewer::ShowGreens()
	{
		for (int i = 0; i < GameManager::green->size(); i++)
		{
			GameManager::green[i]->Size = Size(70, 70);
			GameManager::green[i]->Click += gcnew System::EventHandler(GameForm::gameform, &GameForm::Green_Click);
			GameManager::green[i]->BackColor = System::Drawing::Color::Transparent;
			GameManager::green[i]->Image = (cli::safe_cast<System::Drawing::Image^>(resourceManager->GetObject(L"Green")));
			GameForm::gameform->Controls->Add(GameManager::green[i]);
		}
	}

	void Viewer::RemoveGreens()
	{
		for (int i = GameManager::green->size() - 1; i >= 0; i--)
		{
			GameForm::gameform->Controls->Remove(GameManager::green[i]);
			GameManager::green->pop_back();
		}
	}

	void Viewer::ShowReds()
	{
		for (int i = 0; i < GameManager::red->size(); i++)
		{
			GameManager::red[i]->Image = (cli::safe_cast<System::Drawing::Image^>(resourceManager->GetObject(L"Red")));
		}
	}

	void Viewer::RemoveReds()
	{
		for (int i = GameManager::red->size() - 1; i >= 0; i--)
		{
			GameManager::red[i]->Image = nullptr;
			GameManager::red->pop_back();
		}
	}

	void Viewer::RemovePiece(PictureBox^ piece)
	{
		piece->Visible = false;
	}

	void Viewer::SetPiece(PictureBox^ piece, Point^ toPos)
	{
		piece->Location = *toPos;
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