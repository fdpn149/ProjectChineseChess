#include "Viewer.h"
#include "GameForm.h"

namespace ProjectChineseChess
{
	Viewer::Viewer()
	{

	}

	void Viewer::PieceClick(PictureBox^ piece)
	{
		piece->Image = (cli::safe_cast<System::Drawing::Image^>(resourceManager->GetObject(L"Yellow")));
	}

	void Viewer::PieceUnclick(PictureBox^ piece)
	{
		piece->Image = nullptr;
	}

	//void Viewer::test(PictureBox^ p)
	//{
	//	p->Image = (cli::safe_cast<System::Drawing::Image^>(resourceManager->GetObject(L"Red")));
	//	System::Windows::Forms::PictureBox^ pi = gcnew PictureBox();
	//	pi->Location = Point(265, 265);
	//	pi->BackColor = Color::Transparent;
	//	pi->Size = Size(70, 70);
	//	pi->Image = (cli::safe_cast<System::Drawing::Image^>(resourceManager->GetObject(L"Green")));
	//	GameForm::gameform->Controls->Add(pi);
	//	//GameForm::gameform->Controls->Remove(p);

	//}
}