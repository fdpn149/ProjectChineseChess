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
	/// StartForm 的摘要
	/// </summary>
	public ref class StartForm : public System::Windows::Forms::Form
	{
	public:
		static StartForm^ startform;
		StartForm(void);

	protected:
		/// <summary>
		/// 清除任何使用中的資源。
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
	private: System::Void startButton_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void exitButton_Click(System::Object^ sender, System::EventArgs^ e);
	};
}
