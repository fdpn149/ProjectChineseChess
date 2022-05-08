#include "Viewer.h"
#include "GameForm.h"
using namespace ProjectChineseChess;

ProjectChineseChess::Viewer::Viewer()
{

}

void ProjectChineseChess::Viewer::change(PictureBox^ p)
{
	p->Image = (cli::safe_cast<System::Drawing::Image^>(resourceManager->GetObject(L"Red")));
	System::Windows::Forms::PictureBox^ pi = gcnew PictureBox();
	pi->Location = Point(265, 265);
	pi->BackColor = Color::Transparent;
	pi->Size = Size(70, 70);
	pi->Image = (cli::safe_cast<System::Drawing::Image^>(resourceManager->GetObject(L"Green")));
	GameForm::gameform->Controls->Add(pi);
	//GameForm::gameform->Controls->Remove(p);
	
}
