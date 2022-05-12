#include "StartForm.h"
#include "FileManager.h"

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
		//TODO:  �b���[�J�غc�禡�{���X
		//
	}

	/// <summary>
	/// �M������ϥΤ����귽�C
	/// </summary>

	inline StartForm::~StartForm()
	{
		if (components)
		{
			delete components;
		}
	}

	/// <summary>
	/// �����]�p�u��䴩�һݪ���k - �ФŨϥε{���X�s�边�ק�
	/// �o�Ӥ�k�����e�C
	/// </summary>

	inline void StartForm::InitializeComponent(void)
	{
		this->startButton = (gcnew System::Windows::Forms::Button());
		this->exitButton = (gcnew System::Windows::Forms::Button());
		this->loadButton = (gcnew System::Windows::Forms::Button());
		this->SuspendLayout();
		// 
		// startButton
		// 
		this->startButton->Font = (gcnew System::Drawing::Font(L"Microsoft JhengHei", 27.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(136)));
		this->startButton->Location = System::Drawing::Point(268, 447);
		this->startButton->Name = L"startButton";
		this->startButton->Size = System::Drawing::Size(245, 90);
		this->startButton->TabIndex = 0;
		this->startButton->Text = L"�}�l�C��";
		this->startButton->UseVisualStyleBackColor = true;
		this->startButton->Click += gcnew System::EventHandler(this, &StartForm::startButton_Click);
		// 
		// exitButton
		// 
		this->exitButton->Font = (gcnew System::Drawing::Font(L"Microsoft JhengHei", 27.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(136)));
		this->exitButton->Location = System::Drawing::Point(268, 687);
		this->exitButton->Name = L"exitButton";
		this->exitButton->Size = System::Drawing::Size(245, 88);
		this->exitButton->TabIndex = 1;
		this->exitButton->Text = L"���}�C��";
		this->exitButton->UseVisualStyleBackColor = true;
		this->exitButton->Click += gcnew System::EventHandler(this, &StartForm::exitButton_Click);
		// 
		// loadButton
		// 
		this->loadButton->Font = (gcnew System::Drawing::Font(L"Microsoft JhengHei", 27.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(136)));
		this->loadButton->Location = System::Drawing::Point(268, 568);
		this->loadButton->Name = L"loadButton";
		this->loadButton->Size = System::Drawing::Size(245, 88);
		this->loadButton->TabIndex = 1;
		this->loadButton->Text = L"Ū���C��";
		this->loadButton->UseVisualStyleBackColor = true;
		this->loadButton->Click += gcnew System::EventHandler(this, &StartForm::loadButton_Click);
		// 
		// StartForm
		// 
		this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
		this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
		this->ClientSize = System::Drawing::Size(752, 825);
		this->Controls->Add(this->loadButton);
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
	//�}�l�C�����s�Q���U
	inline System::Void StartForm::startButton_Click(System::Object^ sender, System::EventArgs^ e)
	{
		GameForm^ form = gcnew GameForm();  //�إ߹C������
		form->Show();  //��ܹC������
		this->Hide();  //���ö}�l����
	}
	//�����C�����s�Q���U
	inline System::Void StartForm::exitButton_Click(System::Object^ sender, System::EventArgs^ e)
	{
		Application::Exit();  //�����{��
	}
	System::Void StartForm::loadButton_Click(System::Object^ sender, System::EventArgs^ e)
	{
		try 
		{
			GameForm^ form = gcnew GameForm('L');  //�إ߹C������
			form->Show();  //��ܹC������
			this->Hide();  //���ö}�l����
		}
		//�S���}�ɮ�
		catch (int){}
	}
}