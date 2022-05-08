#include "StartForm.h"

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
		this->startButton = (gcnew System::Windows::Forms::Button());
		this->exitButton = (gcnew System::Windows::Forms::Button());
		this->SuspendLayout();
		// 
		// startButton
		// 
		this->startButton->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 27.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(136)));
		this->startButton->Location = System::Drawing::Point(268, 518);
		this->startButton->Name = L"startButton";
		this->startButton->Size = System::Drawing::Size(245, 90);
		this->startButton->TabIndex = 0;
		this->startButton->Text = L"開始遊戲";
		this->startButton->UseVisualStyleBackColor = true;
		this->startButton->Click += gcnew System::EventHandler(this, &StartForm::startButton_Click);
		// 
		// exitButton
		// 
		this->exitButton->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 27.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(136)));
		this->exitButton->Location = System::Drawing::Point(268, 636);
		this->exitButton->Name = L"exitButton";
		this->exitButton->Size = System::Drawing::Size(245, 88);
		this->exitButton->TabIndex = 1;
		this->exitButton->Text = L"離開遊戲";
		this->exitButton->UseVisualStyleBackColor = true;
		this->exitButton->Click += gcnew System::EventHandler(this, &StartForm::exitButton_Click);
		// 
		// StartForm
		// 
		this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
		this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
		this->ClientSize = System::Drawing::Size(752, 825);
		this->Controls->Add(this->exitButton);
		this->Controls->Add(this->startButton);
		this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
		this->MaximizeBox = false;
		this->MaximumSize = System::Drawing::Size(768, 864);
		this->Name = L"StartForm";
		this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
		this->Text = L"StartForm";
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
}