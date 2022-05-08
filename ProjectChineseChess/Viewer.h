#pragma once

using System::Windows::Forms::PictureBox;

namespace ProjectChineseChess {

	ref class Viewer
	{
		//�]�w�}Resources�Ϥ����F��
		System::Reflection::Assembly^ resourceAssembly = System::Reflection::Assembly::GetExecutingAssembly();
		System::String^ resourceName = resourceAssembly->GetName()->Name + ".Resources";
		System::Resources::ResourceManager^ resourceManager = gcnew System::Resources::ResourceManager(resourceName, resourceAssembly);
	public:
		Viewer();
		void PieceClick(PictureBox^ piece);  //�Ѥl�Q�I��
		void PieceUnclick(PictureBox^ piece);  //�����Q�I��
		//void test(System::Windows::Forms::PictureBox^ p);  //���ե�
	};

}