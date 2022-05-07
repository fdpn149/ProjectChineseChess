#include "Viewer.h"
#include "GameForm.h"
using namespace ProjectChineseChess;

ProjectChineseChess::Viewer::Viewer()
{

}

void ProjectChineseChess::Viewer::change(PictureBox^ p)
{
	p->Image = (cli::safe_cast<System::Drawing::Image^>(resourceManager->GetObject(L"Red")));
}
