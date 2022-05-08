#include "GameManager.h"
#include "Viewer.h"

ProjectChineseChess::GameManager::GameManager()
{
	viewer = gcnew Viewer();
}

void ProjectChineseChess::GameManager::PieceClicked(System::Windows::Forms::PictureBox^ piece)
{
	viewer->change(piece);
}
