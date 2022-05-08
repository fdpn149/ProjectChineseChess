#pragma once

using System::Windows::Forms::PictureBox;

namespace ProjectChineseChess {

	ref class Viewer
	{
		System::Reflection::Assembly^ resourceAssembly = System::Reflection::Assembly::GetExecutingAssembly();
		System::String^ resourceName = resourceAssembly->GetName()->Name + ".Resources";
		System::Resources::ResourceManager^ resourceManager = gcnew System::Resources::ResourceManager(resourceName, resourceAssembly);
	public:
		Viewer();
		void PieceClick(PictureBox^ piece);
		void PieceUnclick(PictureBox^ piece);
		//void test(System::Windows::Forms::PictureBox^ p);
	};

}