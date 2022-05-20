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
			GameManager::green[i]->Click += gcnew System::EventHandler(GameForm::gameform, &GameForm::Piece_Click);
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

	void Viewer::ShowMessage(String^ m)
	{
		System::Windows::Forms::MessageBox::Show(m);
	}

	System::Windows::Forms::DialogResult Viewer::ShowMessage(String^ message, String^ caption)
	{
		return System::Windows::Forms::MessageBox::Show(GameForm::gameform,message,caption, System::Windows::Forms::MessageBoxButtons::YesNo);
	}

	void Viewer::Label1Show(String^ str)
	{
		if (str->Substring(0, 1) == "紅")
			GameForm::gameform->label1->ForeColor = System::Drawing::Color::Firebrick;
		else
			GameForm::gameform->label1->ForeColor = System::Drawing::Color::Black;
		GameForm::gameform->label1->Text = str;
	}

	void Viewer::Label1Hide()
	{
		GameForm::gameform->label1->Text = "";
	}

	void Viewer::GameOver()
	{
		GameForm::gameform->giveupButton->Visible = false;
		GameForm::gameform->restartButton->Visible = true;
		GameForm::gameform->menuButton->Visible = true;
		GameForm::gameform->End();
	}

	void Viewer::Refresh()
	{
		GameForm::gameform->Refresh();
	}
	void Viewer::Loading(bool enable)
	{
		GameForm::gameform->giveupButton->Enabled = !enable;
		GameForm::gameform->bar1->Visible = !enable;
	}
	void Viewer::BarColor(Color color)
	{
		if (color == Color::RED)
			GameForm::gameform->bar1->BackColor = System::Drawing::Color::Firebrick;
		else
			GameForm::gameform->bar1->BackColor = System::Drawing::Color::Black;
	}
}