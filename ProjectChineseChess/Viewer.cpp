#include "Viewer.h"
#include "GameForm.h"

namespace ProjectChineseChess
{
	Viewer::Viewer()
	{

	}

	void Viewer::PieceClick(PictureBox^ piece)
	{
		//�]�w�Ѥl������
		piece->Image = (cli::safe_cast<System::Drawing::Image^>(resourceManager->GetObject(L"Yellow")));
	}

	void Viewer::PieceUnclick(PictureBox^ piece)
	{
		//�N�Ѥl�C��h��
		piece->Image = nullptr;
	}

	//void Viewer::test(PictureBox^ p)
	//{
	//	//�N�ǤJ���Ѥl�]������
	//	p->Image = (cli::safe_cast<System::Drawing::Image^>(resourceManager->GetObject(L"Red")));
	//	//�إߤ@��PictureBox
	//	System::Windows::Forms::PictureBox^ pi = gcnew PictureBox();
	//	pi->Location = Point(265, 265);  //�]�w��m
	//	pi->BackColor = Color::Transparent;  //�]�w�I�����z��
	//	pi->Size = Size(70, 70);  //�]�w�j�p
	//	//�N�Ϥ��]�����
	//	pi->Image = (cli::safe_cast<System::Drawing::Image^>(resourceManager->GetObject(L"Green")));
	//	//�b�����W�s�W��⪺�F�F
	//	GameForm::gameform->Controls->Add(pi);
	//	//�����ǤJ���Ѥl
	//	//GameForm::gameform->Controls->Remove(p);
	//}
}