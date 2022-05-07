#pragma once
//#include "GameForm.h"
namespace ProjectChineseChess {

	ref class Viewer
	{
		System::Reflection::Assembly^ resourceAssembly = System::Reflection::Assembly::GetExecutingAssembly();
		System::String^ resourceName = resourceAssembly->GetName()->Name + ".Resources";
		System::Resources::ResourceManager^ resourceManager = gcnew System::Resources::ResourceManager(resourceName, resourceAssembly);
	public:
		Viewer();
		void change(System::Windows::Forms::PictureBox^ p);
	};

}