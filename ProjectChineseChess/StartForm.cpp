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
		this->button1 = (gcnew System::Windows::Forms::Button());
		this->button2 = (gcnew System::Windows::Forms::Button());
		this->SuspendLayout();
		// 
		// button1
		// 
		this->button1->Font = (gcnew System::Drawing::Font(L"�L�n������", 27.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(136)));
		this->button1->Location = System::Drawing::Point(268, 518);
		this->button1->Name = L"button1";
		this->button1->Size = System::Drawing::Size(245, 90);
		this->button1->TabIndex = 0;
		this->button1->Text = L"�}�l�C��";
		this->button1->UseVisualStyleBackColor = true;
		this->button1->Click += gcnew System::EventHandler(this, &StartForm::button1_Click);
		// 
		// button2
		// 
		this->button2->Font = (gcnew System::Drawing::Font(L"�L�n������", 27.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(136)));
		this->button2->Location = System::Drawing::Point(268, 636);
		this->button2->Name = L"button2";
		this->button2->Size = System::Drawing::Size(245, 88);
		this->button2->TabIndex = 1;
		this->button2->Text = L"���}�C��";
		this->button2->UseVisualStyleBackColor = true;
		this->button2->Click += gcnew System::EventHandler(this, &StartForm::button2_Click);
		// 
		// StartForm
		// 
		this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
		this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
		this->ClientSize = System::Drawing::Size(752, 825);
		this->Controls->Add(this->button2);
		this->Controls->Add(this->button1);
		this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
		this->MaximizeBox = false;
		this->MaximumSize = System::Drawing::Size(768, 864);
		this->Name = L"StartForm";
		this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
		this->Text = L"StartForm";
		this->ResumeLayout(false);

	}

	inline System::Void StartForm::button1_Click(System::Object^ sender, System::EventArgs^ e)
	{
		GameForm^ form = gcnew GameForm();
		form->Show();
		this->Hide();
	}

	inline System::Void StartForm::button2_Click(System::Object^ sender, System::EventArgs^ e)
	{
		Application::Exit();
	}
}