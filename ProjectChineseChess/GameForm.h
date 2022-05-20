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
	/// GameForm 的摘要
	/// </summary>
	public ref class GameForm : public System::Windows::Forms::Form
	{
		GameManager^ game;
		bool keepRun = false;
	public: System::Windows::Forms::Label^ label1;
	public: System::Windows::Forms::Button^ menuButton;
	private: System::Windows::Forms::Panel^ panel1;
	public:



	public:

	public: System::Windows::Forms::Button^ giveupButton;
	private:
	public: System::Windows::Forms::Button^ restartButton;
	public: System::Windows::Forms::Panel^ bar1;

	public:

	public:
	public:
		static GameForm^ gameform;
		GameForm(void);
		GameForm(char);
		void Load();
		void End();




	protected:
		/// <summary>
		/// 清除任何使用中的資源。
		/// </summary>
		~GameForm();
	public: System::Windows::Forms::PictureBox^ chariotB1;
	protected:
	public: System::Windows::Forms::PictureBox^ horseB1;
	public: System::Windows::Forms::PictureBox^ elephantB1;
	public: System::Windows::Forms::PictureBox^ advisorB1;
	public: System::Windows::Forms::PictureBox^ generalB1;
	public: System::Windows::Forms::PictureBox^ advisorB2;
	public: System::Windows::Forms::PictureBox^ elephantB2;
	public: System::Windows::Forms::PictureBox^ horseB2;
	public: System::Windows::Forms::PictureBox^ chariotB2;
	public: System::Windows::Forms::PictureBox^ cannonB1;
	public: System::Windows::Forms::PictureBox^ cannonB2;
	public: System::Windows::Forms::PictureBox^ soldierB1;
	public: System::Windows::Forms::PictureBox^ soldierB2;
	public: System::Windows::Forms::PictureBox^ soldierB3;
	public: System::Windows::Forms::PictureBox^ soldierB4;
	public: System::Windows::Forms::PictureBox^ soldierB5;
	public: System::Windows::Forms::PictureBox^ soldierR1;
	public: System::Windows::Forms::PictureBox^ soldierR2;
	public: System::Windows::Forms::PictureBox^ soldierR3;
	public: System::Windows::Forms::PictureBox^ soldierR4;
	public: System::Windows::Forms::PictureBox^ soldierR5;
	public: System::Windows::Forms::PictureBox^ cannonR1;
	public: System::Windows::Forms::PictureBox^ cannonR2;
	public: System::Windows::Forms::PictureBox^ chariotR1;
	public: System::Windows::Forms::PictureBox^ horseR1;
	public: System::Windows::Forms::PictureBox^ elephantR1;
	public: System::Windows::Forms::PictureBox^ advisorR1;
	public: System::Windows::Forms::PictureBox^ generalR1;
	public: System::Windows::Forms::PictureBox^ chariotR2;
	public: System::Windows::Forms::PictureBox^ horseR2;
	public: System::Windows::Forms::PictureBox^ elephantR2;
	public: System::Windows::Forms::PictureBox^ advisorR2;
	private:
		/// <summary>
		/// 設計工具所需的變數。
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// 此為設計工具支援所需的方法 - 請勿使用程式碼編輯器修改
		/// 這個方法的內容。
		/// </summary>
		void InitializeComponent(void);
#pragma endregion
	private: System::Void GameForm_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e);
	public: System::Void Piece_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void GameForm_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void menuButton_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void restartButton_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void giveupButton_Click(System::Object^ sender, System::EventArgs^ e);
	};
}
