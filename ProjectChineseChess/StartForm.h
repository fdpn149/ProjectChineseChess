#pragma once
#include "GameForm.h"
namespace ProjectChineseChess {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// StartForm ���K�n
	/// </summary>
	public ref class StartForm : public System::Windows::Forms::Form
	{
	public:
		static StartForm^ startform;
		StartForm(void);

	protected:
		/// <summary>
		/// �M������ϥΤ����귽�C
		/// </summary>
		~StartForm();
	public: System::Windows::Forms::Button^ startButton;
	private: System::Windows::Forms::Button^ exitButton;
	public:
	protected:


	public:
	protected:

	protected:

	private:
		/// <summary>
		/// �]�p�u��һݪ��ܼơC
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// �����]�p�u��䴩�һݪ���k - �ФŨϥε{���X�s�边�ק�
		/// �o�Ӥ�k�����e�C
		/// </summary>
		void InitializeComponent(void);
#pragma endregion
	private: System::Void startButton_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void exitButton_Click(System::Object^ sender, System::EventArgs^ e);
	};
}
