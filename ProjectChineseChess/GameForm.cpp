#include "GameForm.h"
#include "Board.h"
#include "GameManager.h"
/// <summary>
/// 清除任何使用中的資源。
/// </summary>
namespace ProjectChineseChess
{

	inline GameForm::GameForm(void)
	{
		gameform = this;
		InitializeComponent();
		game = gcnew GameManager();
		//
		//TODO:  在此加入建構函式程式碼
		//
	}

	inline GameForm::~GameForm()
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

	inline void GameForm::InitializeComponent(void)
	{
		System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(GameForm::typeid));
		this->chariotB1 = (gcnew System::Windows::Forms::PictureBox());
		this->horseB1 = (gcnew System::Windows::Forms::PictureBox());
		this->elephantB1 = (gcnew System::Windows::Forms::PictureBox());
		this->advisorB1 = (gcnew System::Windows::Forms::PictureBox());
		this->generalB1 = (gcnew System::Windows::Forms::PictureBox());
		this->advisorB2 = (gcnew System::Windows::Forms::PictureBox());
		this->elephantB2 = (gcnew System::Windows::Forms::PictureBox());
		this->horseB2 = (gcnew System::Windows::Forms::PictureBox());
		this->chariotB2 = (gcnew System::Windows::Forms::PictureBox());
		this->cannonB1 = (gcnew System::Windows::Forms::PictureBox());
		this->cannonB2 = (gcnew System::Windows::Forms::PictureBox());
		this->soldierB1 = (gcnew System::Windows::Forms::PictureBox());
		this->soldierB2 = (gcnew System::Windows::Forms::PictureBox());
		this->soldierB3 = (gcnew System::Windows::Forms::PictureBox());
		this->soldierB4 = (gcnew System::Windows::Forms::PictureBox());
		this->soldierB5 = (gcnew System::Windows::Forms::PictureBox());
		this->soldierR1 = (gcnew System::Windows::Forms::PictureBox());
		this->soldierR2 = (gcnew System::Windows::Forms::PictureBox());
		this->soldierR3 = (gcnew System::Windows::Forms::PictureBox());
		this->soldierR4 = (gcnew System::Windows::Forms::PictureBox());
		this->soldierR5 = (gcnew System::Windows::Forms::PictureBox());
		this->cannonR1 = (gcnew System::Windows::Forms::PictureBox());
		this->cannonR2 = (gcnew System::Windows::Forms::PictureBox());
		this->chariotR1 = (gcnew System::Windows::Forms::PictureBox());
		this->horseR1 = (gcnew System::Windows::Forms::PictureBox());
		this->elephantR1 = (gcnew System::Windows::Forms::PictureBox());
		this->advisorR1 = (gcnew System::Windows::Forms::PictureBox());
		this->generalR1 = (gcnew System::Windows::Forms::PictureBox());
		this->chariotR2 = (gcnew System::Windows::Forms::PictureBox());
		this->horseR2 = (gcnew System::Windows::Forms::PictureBox());
		this->elephantR2 = (gcnew System::Windows::Forms::PictureBox());
		this->advisorR2 = (gcnew System::Windows::Forms::PictureBox());
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chariotB1))->BeginInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->horseB1))->BeginInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->elephantB1))->BeginInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->advisorB1))->BeginInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->generalB1))->BeginInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->advisorB2))->BeginInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->elephantB2))->BeginInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->horseB2))->BeginInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chariotB2))->BeginInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->cannonB1))->BeginInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->cannonB2))->BeginInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->soldierB1))->BeginInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->soldierB2))->BeginInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->soldierB3))->BeginInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->soldierB4))->BeginInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->soldierB5))->BeginInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->soldierR1))->BeginInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->soldierR2))->BeginInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->soldierR3))->BeginInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->soldierR4))->BeginInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->soldierR5))->BeginInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->cannonR1))->BeginInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->cannonR2))->BeginInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chariotR1))->BeginInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->horseR1))->BeginInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->elephantR1))->BeginInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->advisorR1))->BeginInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->generalR1))->BeginInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chariotR2))->BeginInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->horseR2))->BeginInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->elephantR2))->BeginInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->advisorR2))->BeginInit();
		this->SuspendLayout();
		// 
		// chariotB1
		// 
		this->chariotB1->BackColor = System::Drawing::Color::Transparent;
		this->chariotB1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"chariotB1.BackgroundImage")));
		this->chariotB1->Location = System::Drawing::Point(40, 40);
		this->chariotB1->Name = L"chariotB1";
		this->chariotB1->Size = System::Drawing::Size(70, 70);
		this->chariotB1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
		this->chariotB1->TabIndex = 0;
		this->chariotB1->TabStop = false;
		this->chariotB1->Click += gcnew System::EventHandler(this, &GameForm::piece_Click);
		// 
		// horseB1
		// 
		this->horseB1->BackColor = System::Drawing::Color::Transparent;
		this->horseB1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"horseB1.BackgroundImage")));
		this->horseB1->Location = System::Drawing::Point(115, 40);
		this->horseB1->Name = L"horseB1";
		this->horseB1->Size = System::Drawing::Size(70, 70);
		this->horseB1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
		this->horseB1->TabIndex = 1;
		this->horseB1->TabStop = false;
		this->horseB1->Click += gcnew System::EventHandler(this, &GameForm::piece_Click);
		// 
		// elephantB1
		// 
		this->elephantB1->BackColor = System::Drawing::Color::Transparent;
		this->elephantB1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"elephantB1.BackgroundImage")));
		this->elephantB1->Location = System::Drawing::Point(190, 40);
		this->elephantB1->Name = L"elephantB1";
		this->elephantB1->Size = System::Drawing::Size(70, 70);
		this->elephantB1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
		this->elephantB1->TabIndex = 2;
		this->elephantB1->TabStop = false;
		this->elephantB1->Click += gcnew System::EventHandler(this, &GameForm::piece_Click);
		// 
		// advisorB1
		// 
		this->advisorB1->BackColor = System::Drawing::Color::Transparent;
		this->advisorB1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"advisorB1.BackgroundImage")));
		this->advisorB1->Location = System::Drawing::Point(265, 40);
		this->advisorB1->Name = L"advisorB1";
		this->advisorB1->Size = System::Drawing::Size(70, 70);
		this->advisorB1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
		this->advisorB1->TabIndex = 3;
		this->advisorB1->TabStop = false;
		this->advisorB1->Click += gcnew System::EventHandler(this, &GameForm::piece_Click);
		// 
		// generalB1
		// 
		this->generalB1->BackColor = System::Drawing::Color::Transparent;
		this->generalB1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"generalB1.BackgroundImage")));
		this->generalB1->Location = System::Drawing::Point(340, 40);
		this->generalB1->Name = L"generalB1";
		this->generalB1->Size = System::Drawing::Size(70, 70);
		this->generalB1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
		this->generalB1->TabIndex = 4;
		this->generalB1->TabStop = false;
		this->generalB1->Click += gcnew System::EventHandler(this, &GameForm::piece_Click);
		// 
		// advisorB2
		// 
		this->advisorB2->BackColor = System::Drawing::Color::Transparent;
		this->advisorB2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"advisorB2.BackgroundImage")));
		this->advisorB2->Location = System::Drawing::Point(415, 40);
		this->advisorB2->Name = L"advisorB2";
		this->advisorB2->Size = System::Drawing::Size(70, 70);
		this->advisorB2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
		this->advisorB2->TabIndex = 5;
		this->advisorB2->TabStop = false;
		this->advisorB2->Click += gcnew System::EventHandler(this, &GameForm::piece_Click);
		// 
		// elephantB2
		// 
		this->elephantB2->BackColor = System::Drawing::Color::Transparent;
		this->elephantB2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"elephantB2.BackgroundImage")));
		this->elephantB2->Location = System::Drawing::Point(490, 40);
		this->elephantB2->Name = L"elephantB2";
		this->elephantB2->Size = System::Drawing::Size(70, 70);
		this->elephantB2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
		this->elephantB2->TabIndex = 6;
		this->elephantB2->TabStop = false;
		this->elephantB2->Click += gcnew System::EventHandler(this, &GameForm::piece_Click);
		// 
		// horseB2
		// 
		this->horseB2->BackColor = System::Drawing::Color::Transparent;
		this->horseB2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"horseB2.BackgroundImage")));
		this->horseB2->Location = System::Drawing::Point(565, 40);
		this->horseB2->Name = L"horseB2";
		this->horseB2->Size = System::Drawing::Size(70, 70);
		this->horseB2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
		this->horseB2->TabIndex = 7;
		this->horseB2->TabStop = false;
		this->horseB2->Click += gcnew System::EventHandler(this, &GameForm::piece_Click);
		// 
		// chariotB2
		// 
		this->chariotB2->BackColor = System::Drawing::Color::Transparent;
		this->chariotB2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"chariotB2.BackgroundImage")));
		this->chariotB2->Location = System::Drawing::Point(640, 40);
		this->chariotB2->Name = L"chariotB2";
		this->chariotB2->Size = System::Drawing::Size(70, 70);
		this->chariotB2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
		this->chariotB2->TabIndex = 8;
		this->chariotB2->TabStop = false;
		this->chariotB2->Click += gcnew System::EventHandler(this, &GameForm::piece_Click);
		// 
		// cannonB1
		// 
		this->cannonB1->BackColor = System::Drawing::Color::Transparent;
		this->cannonB1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"cannonB1.BackgroundImage")));
		this->cannonB1->Location = System::Drawing::Point(116, 190);
		this->cannonB1->Name = L"cannonB1";
		this->cannonB1->Size = System::Drawing::Size(70, 70);
		this->cannonB1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
		this->cannonB1->TabIndex = 9;
		this->cannonB1->TabStop = false;
		this->cannonB1->Click += gcnew System::EventHandler(this, &GameForm::piece_Click);
		// 
		// cannonB2
		// 
		this->cannonB2->BackColor = System::Drawing::Color::Transparent;
		this->cannonB2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"cannonB2.BackgroundImage")));
		this->cannonB2->Location = System::Drawing::Point(565, 190);
		this->cannonB2->Name = L"cannonB2";
		this->cannonB2->Size = System::Drawing::Size(70, 70);
		this->cannonB2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
		this->cannonB2->TabIndex = 10;
		this->cannonB2->TabStop = false;
		this->cannonB2->Click += gcnew System::EventHandler(this, &GameForm::piece_Click);
		// 
		// soldierB1
		// 
		this->soldierB1->BackColor = System::Drawing::Color::Transparent;
		this->soldierB1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"soldierB1.BackgroundImage")));
		this->soldierB1->Location = System::Drawing::Point(40, 265);
		this->soldierB1->Name = L"soldierB1";
		this->soldierB1->Size = System::Drawing::Size(70, 70);
		this->soldierB1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
		this->soldierB1->TabIndex = 11;
		this->soldierB1->TabStop = false;
		this->soldierB1->Click += gcnew System::EventHandler(this, &GameForm::piece_Click);
		// 
		// soldierB2
		// 
		this->soldierB2->BackColor = System::Drawing::Color::Transparent;
		this->soldierB2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"soldierB2.BackgroundImage")));
		this->soldierB2->Location = System::Drawing::Point(190, 265);
		this->soldierB2->Name = L"soldierB2";
		this->soldierB2->Size = System::Drawing::Size(70, 70);
		this->soldierB2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
		this->soldierB2->TabIndex = 12;
		this->soldierB2->TabStop = false;
		this->soldierB2->Click += gcnew System::EventHandler(this, &GameForm::piece_Click);
		// 
		// soldierB3
		// 
		this->soldierB3->BackColor = System::Drawing::Color::Transparent;
		this->soldierB3->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"soldierB3.BackgroundImage")));
		this->soldierB3->Location = System::Drawing::Point(340, 265);
		this->soldierB3->Name = L"soldierB3";
		this->soldierB3->Size = System::Drawing::Size(70, 70);
		this->soldierB3->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
		this->soldierB3->TabIndex = 13;
		this->soldierB3->TabStop = false;
		this->soldierB3->Click += gcnew System::EventHandler(this, &GameForm::piece_Click);
		// 
		// soldierB4
		// 
		this->soldierB4->BackColor = System::Drawing::Color::Transparent;
		this->soldierB4->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"soldierB4.BackgroundImage")));
		this->soldierB4->Location = System::Drawing::Point(490, 265);
		this->soldierB4->Name = L"soldierB4";
		this->soldierB4->Size = System::Drawing::Size(70, 70);
		this->soldierB4->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
		this->soldierB4->TabIndex = 14;
		this->soldierB4->TabStop = false;
		this->soldierB4->Click += gcnew System::EventHandler(this, &GameForm::piece_Click);
		// 
		// soldierB5
		// 
		this->soldierB5->BackColor = System::Drawing::Color::Transparent;
		this->soldierB5->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"soldierB5.BackgroundImage")));
		this->soldierB5->Location = System::Drawing::Point(640, 265);
		this->soldierB5->Name = L"soldierB5";
		this->soldierB5->Size = System::Drawing::Size(70, 70);
		this->soldierB5->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
		this->soldierB5->TabIndex = 15;
		this->soldierB5->TabStop = false;
		this->soldierB5->Click += gcnew System::EventHandler(this, &GameForm::piece_Click);
		// 
		// soldierR1
		// 
		this->soldierR1->BackColor = System::Drawing::Color::Transparent;
		this->soldierR1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"soldierR1.BackgroundImage")));
		this->soldierR1->Location = System::Drawing::Point(40, 490);
		this->soldierR1->Name = L"soldierR1";
		this->soldierR1->Size = System::Drawing::Size(70, 70);
		this->soldierR1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
		this->soldierR1->TabIndex = 16;
		this->soldierR1->TabStop = false;
		this->soldierR1->Click += gcnew System::EventHandler(this, &GameForm::piece_Click);
		// 
		// soldierR2
		// 
		this->soldierR2->BackColor = System::Drawing::Color::Transparent;
		this->soldierR2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"soldierR2.BackgroundImage")));
		this->soldierR2->Location = System::Drawing::Point(190, 490);
		this->soldierR2->Name = L"soldierR2";
		this->soldierR2->Size = System::Drawing::Size(70, 70);
		this->soldierR2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
		this->soldierR2->TabIndex = 17;
		this->soldierR2->TabStop = false;
		this->soldierR2->Click += gcnew System::EventHandler(this, &GameForm::piece_Click);
		// 
		// soldierR3
		// 
		this->soldierR3->BackColor = System::Drawing::Color::Transparent;
		this->soldierR3->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"soldierR3.BackgroundImage")));
		this->soldierR3->Location = System::Drawing::Point(340, 490);
		this->soldierR3->Name = L"soldierR3";
		this->soldierR3->Size = System::Drawing::Size(70, 70);
		this->soldierR3->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
		this->soldierR3->TabIndex = 18;
		this->soldierR3->TabStop = false;
		this->soldierR3->Click += gcnew System::EventHandler(this, &GameForm::piece_Click);
		// 
		// soldierR4
		// 
		this->soldierR4->BackColor = System::Drawing::Color::Transparent;
		this->soldierR4->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"soldierR4.BackgroundImage")));
		this->soldierR4->Location = System::Drawing::Point(490, 490);
		this->soldierR4->Name = L"soldierR4";
		this->soldierR4->Size = System::Drawing::Size(70, 70);
		this->soldierR4->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
		this->soldierR4->TabIndex = 19;
		this->soldierR4->TabStop = false;
		this->soldierR4->Click += gcnew System::EventHandler(this, &GameForm::piece_Click);
		// 
		// soldierR5
		// 
		this->soldierR5->BackColor = System::Drawing::Color::Transparent;
		this->soldierR5->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"soldierR5.BackgroundImage")));
		this->soldierR5->Location = System::Drawing::Point(640, 490);
		this->soldierR5->Name = L"soldierR5";
		this->soldierR5->Size = System::Drawing::Size(70, 70);
		this->soldierR5->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
		this->soldierR5->TabIndex = 20;
		this->soldierR5->TabStop = false;
		this->soldierR5->Click += gcnew System::EventHandler(this, &GameForm::piece_Click);
		// 
		// cannonR1
		// 
		this->cannonR1->BackColor = System::Drawing::Color::Transparent;
		this->cannonR1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"cannonR1.BackgroundImage")));
		this->cannonR1->Location = System::Drawing::Point(115, 565);
		this->cannonR1->Name = L"cannonR1";
		this->cannonR1->Size = System::Drawing::Size(70, 70);
		this->cannonR1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
		this->cannonR1->TabIndex = 21;
		this->cannonR1->TabStop = false;
		this->cannonR1->Click += gcnew System::EventHandler(this, &GameForm::piece_Click);
		// 
		// cannonR2
		// 
		this->cannonR2->BackColor = System::Drawing::Color::Transparent;
		this->cannonR2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"cannonR2.BackgroundImage")));
		this->cannonR2->Location = System::Drawing::Point(565, 565);
		this->cannonR2->Name = L"cannonR2";
		this->cannonR2->Size = System::Drawing::Size(70, 70);
		this->cannonR2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
		this->cannonR2->TabIndex = 22;
		this->cannonR2->TabStop = false;
		this->cannonR2->Click += gcnew System::EventHandler(this, &GameForm::piece_Click);
		// 
		// chariotR1
		// 
		this->chariotR1->BackColor = System::Drawing::Color::Transparent;
		this->chariotR1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"chariotR1.BackgroundImage")));
		this->chariotR1->Location = System::Drawing::Point(40, 715);
		this->chariotR1->Name = L"chariotR1";
		this->chariotR1->Size = System::Drawing::Size(70, 70);
		this->chariotR1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
		this->chariotR1->TabIndex = 23;
		this->chariotR1->TabStop = false;
		this->chariotR1->Click += gcnew System::EventHandler(this, &GameForm::piece_Click);
		// 
		// horseR1
		// 
		this->horseR1->BackColor = System::Drawing::Color::Transparent;
		this->horseR1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"horseR1.BackgroundImage")));
		this->horseR1->Location = System::Drawing::Point(115, 715);
		this->horseR1->Name = L"horseR1";
		this->horseR1->Size = System::Drawing::Size(70, 70);
		this->horseR1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
		this->horseR1->TabIndex = 24;
		this->horseR1->TabStop = false;
		this->horseR1->Click += gcnew System::EventHandler(this, &GameForm::piece_Click);
		// 
		// elephantR1
		// 
		this->elephantR1->BackColor = System::Drawing::Color::Transparent;
		this->elephantR1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"elephantR1.BackgroundImage")));
		this->elephantR1->Location = System::Drawing::Point(190, 715);
		this->elephantR1->Name = L"elephantR1";
		this->elephantR1->Size = System::Drawing::Size(70, 70);
		this->elephantR1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
		this->elephantR1->TabIndex = 25;
		this->elephantR1->TabStop = false;
		this->elephantR1->Click += gcnew System::EventHandler(this, &GameForm::piece_Click);
		// 
		// advisorR1
		// 
		this->advisorR1->BackColor = System::Drawing::Color::Transparent;
		this->advisorR1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"advisorR1.BackgroundImage")));
		this->advisorR1->Location = System::Drawing::Point(265, 715);
		this->advisorR1->Name = L"advisorR1";
		this->advisorR1->Size = System::Drawing::Size(70, 70);
		this->advisorR1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
		this->advisorR1->TabIndex = 26;
		this->advisorR1->TabStop = false;
		this->advisorR1->Click += gcnew System::EventHandler(this, &GameForm::piece_Click);
		// 
		// generalR1
		// 
		this->generalR1->BackColor = System::Drawing::Color::Transparent;
		this->generalR1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"generalR1.BackgroundImage")));
		this->generalR1->Location = System::Drawing::Point(340, 715);
		this->generalR1->Name = L"generalR1";
		this->generalR1->Size = System::Drawing::Size(70, 70);
		this->generalR1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
		this->generalR1->TabIndex = 27;
		this->generalR1->TabStop = false;
		this->generalR1->Click += gcnew System::EventHandler(this, &GameForm::piece_Click);
		// 
		// chariotR2
		// 
		this->chariotR2->BackColor = System::Drawing::Color::Transparent;
		this->chariotR2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"chariotR2.BackgroundImage")));
		this->chariotR2->Location = System::Drawing::Point(640, 715);
		this->chariotR2->Name = L"chariotR2";
		this->chariotR2->Size = System::Drawing::Size(70, 70);
		this->chariotR2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
		this->chariotR2->TabIndex = 28;
		this->chariotR2->TabStop = false;
		this->chariotR2->Click += gcnew System::EventHandler(this, &GameForm::piece_Click);
		// 
		// horseR2
		// 
		this->horseR2->BackColor = System::Drawing::Color::Transparent;
		this->horseR2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"horseR2.BackgroundImage")));
		this->horseR2->Location = System::Drawing::Point(564, 715);
		this->horseR2->Name = L"horseR2";
		this->horseR2->Size = System::Drawing::Size(70, 70);
		this->horseR2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
		this->horseR2->TabIndex = 29;
		this->horseR2->TabStop = false;
		this->horseR2->Click += gcnew System::EventHandler(this, &GameForm::piece_Click);
		// 
		// elephantR2
		// 
		this->elephantR2->BackColor = System::Drawing::Color::Transparent;
		this->elephantR2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"elephantR2.BackgroundImage")));
		this->elephantR2->Location = System::Drawing::Point(490, 715);
		this->elephantR2->Name = L"elephantR2";
		this->elephantR2->Size = System::Drawing::Size(70, 70);
		this->elephantR2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
		this->elephantR2->TabIndex = 30;
		this->elephantR2->TabStop = false;
		this->elephantR2->Click += gcnew System::EventHandler(this, &GameForm::piece_Click);
		// 
		// advisorR2
		// 
		this->advisorR2->BackColor = System::Drawing::Color::Transparent;
		this->advisorR2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"advisorR2.BackgroundImage")));
		this->advisorR2->Location = System::Drawing::Point(415, 715);
		this->advisorR2->Name = L"advisorR2";
		this->advisorR2->Size = System::Drawing::Size(70, 70);
		this->advisorR2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
		this->advisorR2->TabIndex = 31;
		this->advisorR2->TabStop = false;
		this->advisorR2->Click += gcnew System::EventHandler(this, &GameForm::piece_Click);
		// 
		// GameForm
		// 
		this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
		this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
		this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(200)),
			static_cast<System::Int32>(static_cast<System::Byte>(128)));
		this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
		this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
		this->ClientSize = System::Drawing::Size(752, 825);
		this->Controls->Add(this->advisorR2);
		this->Controls->Add(this->elephantR2);
		this->Controls->Add(this->horseR2);
		this->Controls->Add(this->chariotR2);
		this->Controls->Add(this->generalR1);
		this->Controls->Add(this->advisorR1);
		this->Controls->Add(this->elephantR1);
		this->Controls->Add(this->horseR1);
		this->Controls->Add(this->chariotR1);
		this->Controls->Add(this->cannonR2);
		this->Controls->Add(this->cannonR1);
		this->Controls->Add(this->soldierR5);
		this->Controls->Add(this->soldierR4);
		this->Controls->Add(this->soldierR3);
		this->Controls->Add(this->soldierR2);
		this->Controls->Add(this->soldierR1);
		this->Controls->Add(this->soldierB5);
		this->Controls->Add(this->soldierB4);
		this->Controls->Add(this->soldierB3);
		this->Controls->Add(this->soldierB2);
		this->Controls->Add(this->soldierB1);
		this->Controls->Add(this->cannonB2);
		this->Controls->Add(this->cannonB1);
		this->Controls->Add(this->chariotB2);
		this->Controls->Add(this->horseB2);
		this->Controls->Add(this->elephantB2);
		this->Controls->Add(this->advisorB2);
		this->Controls->Add(this->generalB1);
		this->Controls->Add(this->advisorB1);
		this->Controls->Add(this->elephantB1);
		this->Controls->Add(this->horseB1);
		this->Controls->Add(this->chariotB1);
		this->DoubleBuffered = true;
		this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
		this->MaximizeBox = false;
		this->MaximumSize = System::Drawing::Size(768, 864);
		this->Name = L"GameForm";
		this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
		this->Text = L"GameForm";
		this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &GameForm::GameForm_FormClosing);
		this->Click += gcnew System::EventHandler(this, &GameForm::GameForm_Click);
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chariotB1))->EndInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->horseB1))->EndInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->elephantB1))->EndInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->advisorB1))->EndInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->generalB1))->EndInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->advisorB2))->EndInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->elephantB2))->EndInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->horseB2))->EndInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chariotB2))->EndInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->cannonB1))->EndInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->cannonB2))->EndInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->soldierB1))->EndInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->soldierB2))->EndInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->soldierB3))->EndInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->soldierB4))->EndInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->soldierB5))->EndInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->soldierR1))->EndInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->soldierR2))->EndInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->soldierR3))->EndInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->soldierR4))->EndInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->soldierR5))->EndInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->cannonR1))->EndInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->cannonR2))->EndInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chariotR1))->EndInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->horseR1))->EndInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->elephantR1))->EndInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->advisorR1))->EndInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->generalR1))->EndInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chariotR2))->EndInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->horseR2))->EndInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->elephantR2))->EndInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->advisorR2))->EndInit();
		this->ResumeLayout(false);

	}

	//當視窗被關閉
	inline System::Void GameForm::GameForm_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e)
	{
		Application::Exit();  //結束程式
	}

	//當棋子被按下
	inline System::Void GameForm::piece_Click(System::Object^ sender, System::EventArgs^ e)
	{
		PictureBox^ piece = (PictureBox^)sender;  //將piece設為被點擊的棋子
		game->PieceClick(piece);  //執行棋子被點擊後所需做的事

	}

	//當視窗被按下
	inline System::Void GameForm::GameForm_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		game->FormClick();  //執行視窗被點擊後所需做的事
	}

}