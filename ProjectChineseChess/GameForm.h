#pragma once
#include "Chess.h"
#include "GameManager.h"
namespace ProjectChineseChess {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace ProjectChineseChess;
	/// <summary>
	/// GameForm ���K�n
	/// </summary>
	public ref class GameForm : public System::Windows::Forms::Form
	{
		GameManager^ gm = gcnew GameManager();
	public:
		static GameForm^ gameform;
		GameForm(void);

	protected:
		/// <summary>
		/// �M������ϥΤ����귽�C
		/// </summary>
		~GameForm();
	private: System::Windows::Forms::PictureBox^ chariotB1;
	private: System::Windows::Forms::PictureBox^ horseB1;
	private: System::Windows::Forms::PictureBox^ elephantB1;
	private: System::Windows::Forms::PictureBox^ advisorB1;
	private: System::Windows::Forms::PictureBox^ generalB;
	private: System::Windows::Forms::PictureBox^ advisorB2;
	private: System::Windows::Forms::PictureBox^ elephantB2;
	private: System::Windows::Forms::PictureBox^ horseB2;
	private: System::Windows::Forms::PictureBox^ chariotB2;
	private: System::Windows::Forms::PictureBox^ cannonB1;
	private: System::Windows::Forms::PictureBox^ cannonB2;
	private: System::Windows::Forms::PictureBox^ soldierB1;
	public: System::Windows::Forms::PictureBox^ soldierB2;
	private:

	private:

	private: System::Windows::Forms::PictureBox^ soldierB3;
	private: System::Windows::Forms::PictureBox^ soldierB4;
	private: System::Windows::Forms::PictureBox^ soldierB5;
	private: System::Windows::Forms::PictureBox^ solderR1;
	private: System::Windows::Forms::PictureBox^ solderR2;
	private: System::Windows::Forms::PictureBox^ solderR3;
	private: System::Windows::Forms::PictureBox^ solderR4;
	private: System::Windows::Forms::PictureBox^ solderR5;
	private: System::Windows::Forms::PictureBox^ cannonR1;
	private: System::Windows::Forms::PictureBox^ cannonR2;
	private: System::Windows::Forms::PictureBox^ chariotR1;
	private: System::Windows::Forms::PictureBox^ horseR1;
	private: System::Windows::Forms::PictureBox^ elephantR1;
	private: System::Windows::Forms::PictureBox^ advisorR1;
	private: System::Windows::Forms::PictureBox^ generalR;
	private: System::Windows::Forms::PictureBox^ chariotR2;
	private: System::Windows::Forms::PictureBox^ horseR2;
	private: System::Windows::Forms::PictureBox^ elephantR2;
	private: System::Windows::Forms::PictureBox^ advisorR2;

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
	private: System::Void GameForm_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e);
	private: System::Void piece_Click(System::Object^ sender, System::EventArgs^ e);
	};
}
