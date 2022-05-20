#include "StartForm.h"
#include "FileManager.h"
#include "GameForm.h"

[System::STAThreadAttribute]

int main()
{
	System::Windows::Forms::Application::EnableVisualStyles();
	System::Windows::Forms::Application::SetCompatibleTextRenderingDefault(false);
	ProjectChineseChess::StartForm form;
	System::Windows::Forms::Application::Run(% form);
}

namespace ProjectChineseChess
{
	inline StartForm::StartForm(void)
	{
		InitializeComponent();
		startform = this;
		//
		//TODO:  在此加入建構函式程式碼
		//
	}

	/// <summary>
	/// 清除任何使用中的資源。
	/// </summary>

	inline StartForm::~StartForm()
	{
		if (components)
		{
			delete components;
		}
	}

	/// <summary>
	/// 此為設計工具支援所需的方法 - 請勿使用程式碼編輯器修改
	/// 這個方法的內容。
	/// </summary>

	inline void StartForm::InitializeComponent(void)
	{
		System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(StartForm::typeid));
		this->startButton = (gcnew System::Windows::Forms::Button());
		this->exitButton = (gcnew System::Windows::Forms::Button());
		this->loadButton = (gcnew System::Windows::Forms::Button());
		this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
		this->SuspendLayout();
		// 
		// startButton
		// 
		this->startButton->BackColor = System::Drawing::Color::LightCoral;
		this->startButton->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
		this->startButton->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 36, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(136)));
		this->startButton->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
		this->startButton->Location = System::Drawing::Point(12, 623);
		this->startButton->Name = L"startButton";
		this->startButton->Size = System::Drawing::Size(640, 190);
		this->startButton->TabIndex = 0;
		this->startButton->Text = L"開 始 遊 戲";
		this->startButton->UseVisualStyleBackColor = false;
		this->startButton->Click += gcnew System::EventHandler(this, &StartForm::startButton_Click);
		// 
		// exitButton
		// 
		this->exitButton->BackColor = System::Drawing::Color::MediumPurple;
		this->exitButton->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
		this->exitButton->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 27.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(136)));
		this->exitButton->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
		this->exitButton->Location = System::Drawing::Point(669, 725);
		this->exitButton->Name = L"exitButton";
		this->exitButton->Size = System::Drawing::Size(263, 88);
		this->exitButton->TabIndex = 1;
		this->exitButton->Text = L"離開遊戲";
		this->exitButton->UseVisualStyleBackColor = false;
		this->exitButton->Click += gcnew System::EventHandler(this, &StartForm::exitButton_Click);
		// 
		// loadButton
		// 
		this->loadButton->BackColor = System::Drawing::Color::DarkSeaGreen;
		this->loadButton->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
		this->loadButton->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 27.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(136)));
		this->loadButton->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
		this->loadButton->Location = System::Drawing::Point(669, 623);
		this->loadButton->Name = L"loadButton";
		this->loadButton->Size = System::Drawing::Size(263, 88);
		this->loadButton->TabIndex = 1;
		this->loadButton->Text = L"讀取遊戲";
		this->loadButton->UseVisualStyleBackColor = false;
		this->loadButton->Click += gcnew System::EventHandler(this, &StartForm::loadButton_Click);
		// 
		// pictureBox1
		// 
		this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
		this->pictureBox1->Location = System::Drawing::Point(70, 197);
		this->pictureBox1->Name = L"pictureBox1";
		this->pictureBox1->Size = System::Drawing::Size(802, 267);
		this->pictureBox1->TabIndex = 2;
		this->pictureBox1->TabStop = false;
		// 
		// StartForm
		// 
		this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
		this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
		this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
			static_cast<System::Int32>(static_cast<System::Byte>(128)));
		this->ClientSize = System::Drawing::Size(944, 825);
		this->Controls->Add(this->pictureBox1);
		this->Controls->Add(this->loadButton);
		this->Controls->Add(this->exitButton);
		this->Controls->Add(this->startButton);
		this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
		this->MaximizeBox = false;
		this->Name = L"StartForm";
		this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
		this->Text = L"中國象棋";
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
		this->ResumeLayout(false);

	}
	//開始遊戲按鈕被按下
	inline System::Void StartForm::startButton_Click(System::Object^ sender, System::EventArgs^ e)
	{
		GameForm^ form = gcnew GameForm();  //建立遊戲視窗
		form->Show();  //顯示遊戲視窗
		this->Hide();  //隱藏開始視窗
	}
	//結束遊戲按鈕被按下
	inline System::Void StartForm::exitButton_Click(System::Object^ sender, System::EventArgs^ e)
	{
		Application::Exit();  //結束程式
	}
	System::Void StartForm::loadButton_Click(System::Object^ sender, System::EventArgs^ e)
	{
		try
		{
			GameForm^ form = gcnew GameForm('L');  //建立遊戲視窗
			form->Show();  //顯示遊戲視窗
			this->Hide();  //隱藏開始視窗
			form->Load();
		}
		//沒有開檔案
		catch (int) {}

	}
}